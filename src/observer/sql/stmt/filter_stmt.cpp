/* Copyright (c) 2021 OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

//
// Created by Wangyunlai on 2022/5/22.
//

#include "common/rc.h"
#include "common/log/log.h"
#include "common/lang/string.h"
#include "sql/stmt/filter_stmt.h"
#include "sql/stmt/select_stmt.h"
#include "storage/db/db.h"
#include "storage/table/table.h"


FilterStmt::~FilterStmt()
{
  for (FilterUnit *unit : filter_units_) {
    delete unit;
  }
  filter_units_.clear();
  for (SelectStmt* sub_query: this->sub_querys_){
    if(sub_query !=nullptr) delete sub_query;
  }
}

RC FilterStmt::create(Db *db, Table *default_table, std::unordered_map<std::string, Table *> *tables,
    const ConditionSqlNode *conditions, int condition_num, FilterStmt *&stmt, std::unordered_map<std::string, Table*> *outer_tables)
{
  RC rc = RC::SUCCESS;
  stmt = nullptr;
  bool is_or = false;
  FilterStmt *tmp_stmt = new FilterStmt();
  for (int i = 0; i < condition_num; i++) {
    FilterUnit *filter_unit = nullptr;
    is_or = conditions[i].is_or || is_or;//只要有一个or，就确定该condition是由or连接的。 
    rc = create_filter_unit(db, default_table, tables, conditions[i], filter_unit, outer_tables);
    if (rc != RC::SUCCESS) {
      delete tmp_stmt;
      LOG_WARN("failed to create filter unit. condition index=%d", i);
      return rc;
    }
    if(filter_unit->has_sub_query()) tmp_stmt->set_has_sub_query(true);
    tmp_stmt->filter_units_.push_back(filter_unit);
  }
  
  // connection by and / or
  tmp_stmt->is_or_ = is_or;
  stmt = tmp_stmt;
  return rc;
}

RC get_table_and_field(Db *db, Table *default_table, std::unordered_map<std::string, Table *> *tables,
    const RelAttrSqlNode &attr, Table *&table, const FieldMeta *&field)
{
  if (common::is_blank(attr.relation_name.c_str())) {
    table = default_table;
  } else if (nullptr != tables) {
    auto iter = tables->find(attr.relation_name);
    if (iter != tables->end()) {
      table = iter->second;
    }
  } else {
    table = db->find_table(attr.relation_name.c_str());
  }
  if (nullptr == table) {
    LOG_WARN("No such table: attr.relation_name: %s", attr.relation_name.c_str());
    return RC::SCHEMA_TABLE_NOT_EXIST;
  }

  field = table->table_meta().field(attr.attribute_name.c_str());
  if (nullptr == field) {
    LOG_WARN("no such field in table: table %s, field %s", table->name(), attr.attribute_name.c_str());
    table = nullptr;
    return RC::SCHEMA_FIELD_NOT_EXIST;
  }

  return RC::SUCCESS;
}

RC FilterStmt::create_filter_unit(Db *db, Table *default_table, std::unordered_map<std::string, Table *> *tables,
    const ConditionSqlNode &condition, FilterUnit *&filter_unit, std::unordered_map<std::string, Table*> *outer_tables)
{
  RC rc = RC::SUCCESS;
  std::unordered_map<std::string, Table*> new_outer_tables;
  if(tables != nullptr) new_outer_tables.insert(tables->begin(),tables->end());
  if(outer_tables != nullptr) new_outer_tables.insert(outer_tables->begin(),outer_tables->end());
  CompOp comp = condition.comp;
  if (comp < EQUAL_TO || comp >= NO_OP) {
    LOG_WARN("invalid compare operator : %d", comp);
    return RC::INVALID_ARGUMENT;
  }

  filter_unit = new FilterUnit;

  //构建左边的OBJ
  if (!condition.left_is_sub_query){
    if (condition.left_is_attr) {
      Table *table = nullptr;
      const FieldMeta *field = nullptr;
      rc = get_table_and_field(db, default_table, tables, condition.left_attr, table, field);
      bool is_connect_to_parent = false;
      
      // if failed, try to get field from the outer query.
      if (rc != RC::SUCCESS) {
        LOG_WARN("cannot find attr in this select stmt scope maybe use outer tables");
        if(outer_tables != nullptr)
          rc = get_table_and_field(db, default_table, outer_tables, condition.left_attr, table, field);
        if(rc != RC::SUCCESS){
          LOG_WARN("cannot find attr");
          return rc;
        }
        is_connect_to_parent = true;
      }
      FilterObj filter_obj;
      filter_obj.is_connect_to_parent = is_connect_to_parent;
      filter_obj.init_attr(Field(table, field));
      filter_unit->set_left(filter_obj);
    } else {
      FilterObj filter_obj;
      filter_obj.init_value(condition.left_value);
      filter_unit->set_left(filter_obj);
    }
  }
  else {
    FilterObj filter_obj;
    SelectSqlNode* sub_select_sql_node = condition.left_sub_query.get();
    rc = SelectStmt::create(db, *sub_select_sql_node, filter_obj.sub_query, &new_outer_tables);
    filter_obj.init_values(std::vector<Value>());
    filter_unit->set_left(filter_obj);
    filter_unit->set_has_sub_query(true);
  }

  if(comp == IS_OP || comp == IS_NOT_OP) {
    //following IS or IS_NOT must be null
    if(condition.right_is_attr) {
      rc = RC::SQL_SYNTAX;
      return rc;
    }
    if(condition.right_value.is_null() == false) {
      rc = RC::SQL_SYNTAX;
      return rc;
    }
  }

  // 构建右边的OBJ
  if (!condition.right_is_sub_query){
    if (condition.right_is_attr) {
      Table *table = nullptr;
      const FieldMeta *field = nullptr;
      rc = get_table_and_field(db, default_table, tables, condition.right_attr, table, field);
      bool is_connect_to_parent = false;
      if (rc != RC::SUCCESS) {
        LOG_WARN("cannot find attr in this select stmt scope maybe use outer tables");
        rc = get_table_and_field(db, default_table, outer_tables, condition.right_attr, table, field);
        if(rc != RC::SUCCESS){
          LOG_WARN("cannot find attr");
          return rc;
        }
        is_connect_to_parent = true;
      }
      FilterObj filter_obj;
      filter_obj.is_connect_to_parent = is_connect_to_parent;
      filter_obj.init_attr(Field(table, field));
      filter_unit->set_right(filter_obj);
    } else {
      FilterObj filter_obj;
      filter_obj.init_value(condition.right_value);
      filter_unit->set_right(filter_obj);
    }
  }
  else{
    FilterObj filter_obj;
    // #TODO 这里是不是要特判一下values是不是为空
    if(condition.right_values.empty()){
      SelectSqlNode* sub_select_sql_node = condition.right_sub_query.get();
      rc = SelectStmt::create(db, *sub_select_sql_node, filter_obj.sub_query, &new_outer_tables);
      filter_unit->set_has_sub_query(true);
    }
    filter_obj.init_values(condition.right_values);
    filter_unit->set_right(filter_obj);
  }

  filter_unit->set_comp(comp);
  filter_unit->set_connect_to_parent(filter_unit->left().is_connect_to_parent || filter_unit->right().is_connect_to_parent);
  return rc;
}
