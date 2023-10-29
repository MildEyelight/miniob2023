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

#include <algorithm>

#include "sql/stmt/update_stmt.h"
#include "sql/stmt/filter_stmt.h"
#include "common/log/log.h"
#include "common/lang/string.h"
#include "storage/db/db.h"
#include "storage/table/table.h"


UpdateStmt::UpdateStmt(Table *table, 
                      std::vector<const Value *> update_values, 
                      int value_amount, 
                      std::vector<const FieldMeta*> update_fields ,
                      FilterStmt* filter_stmt)
    :table_(table), update_values_(update_values), value_amount_(value_amount), update_fields_(update_fields),filter_stmt_(filter_stmt)
{}

RC UpdateStmt::create(Db *db, const UpdateSqlNode &update, Stmt *&stmt)
{
  // #TODO
  //get table
  const char *table_name = update.relation_name.c_str();
  if (nullptr == db || nullptr == table_name ) {
    LOG_WARN("invalid argument. db=%p, table_name=%p",
        db, table_name);
    return RC::INVALID_ARGUMENT;
  }

  Table *table = db->find_table(table_name);
  if (nullptr == table) {
    LOG_WARN("no such table. db=%s, table_name=%s", db->name(), table_name);
    return RC::SCHEMA_TABLE_NOT_EXIST;
  }
  //get update_attribute and check validate
  std::vector<const FieldMeta*> update_fields;
  //std::vector<AttrType> update_value_types;
  std::vector<const Value*> update_values;
  std::vector<std::string> update_attribute = update.attribute_name;
  for(int i = 0; i < update.attribute_name.size(); i++){
    const FieldMeta *meta = table->table_meta().field(update.attribute_name.at(i).c_str());
    bool field_nullable = meta->nullable();

    if(field_nullable && update.value.at(i).is_null()) {
      //TODO num_value_ changes with int
      int attr_len = std::min(meta->len(), (int)sizeof(int));;
      const_cast<UpdateSqlNode&>(update).value[i].set_type(meta->type());
      const_cast<UpdateSqlNode&>(update).value[i].set_length(attr_len);
    }

    if(nullptr == meta){
      return RC::SCHEMA_FIELD_NOT_EXIST;
    }
    if(meta->type() != update.value.at(i).attr_type()){
      return RC::SCHEMA_FIELD_TYPE_MISMATCH;
    }
    update_fields.push_back(meta);
    //update_value_types.push_back(update.value.at(i).attr_type());
    update_values.push_back(&update.value.at(i));

  }
  // AttrType value_type = update.value.attr_type();
  // const TableMeta &table_meta = table->table_meta();
  // const int sys_field_num = table_meta.sys_field_num();
  // const int field_num = table_meta.field_num() - sys_field_num;
  // int update_location = 0;
  // for(update_location; update_location<field_num;update_location++){
  //   const FieldMeta *field_meta = table_meta.field(update_location + sys_field_num);
  //   AttrType field_type = field_meta->type();
  //   const char * field_name = field_meta->name();
  //   //field_name 和 type 都要一致 才算合法的update。
  //   if(strcmp(field_name,update_attribute.c_str())==0 && field_type==value_type){
  //       break;
  //     }
  // }
  // if(update_location==field_num){
  //   LOG_WARN("field name or type mismatch");
  //   return RC::SCHEMA_FIELD_TYPE_MISMATCH;
  // }


  //get values
  // Value* value = const_cast<Value*>(&update.value);
  
  //get filter_stmt
  std::unordered_map<std::string, Table *> table_map;
  table_map.insert(std::pair<std::string, Table *>(std::string(table_name), table));
  FilterStmt *filter_stmt = nullptr;
  RC rc = FilterStmt::create(
      db, table, &table_map, update.conditions.data(), static_cast<int>(update.conditions.size()), filter_stmt);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to create filter statement. rc=%d:%s", rc, strrc(rc));
    return rc;
  }
  stmt = new UpdateStmt(table,update_values,update_values.size(),update_fields,filter_stmt);
  return RC::SUCCESS;
}
