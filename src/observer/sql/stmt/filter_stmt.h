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

#pragma once

#include <vector>
#include <unordered_map>
#include "sql/parser/parse_defs.h"
#include "sql/stmt/stmt.h"
#include "sql/expr/expression.h"
#include "sql/stmt/select_stmt.h"
class Db;
class Table;
class FieldMeta;
class SelectStmt;

struct FilterObj 
{
  bool is_attr;
  bool is_sub_query;                  // 如果是subquery的话，sub-query 不为空
  bool is_connect_to_parent = false;  // 如果是attr的话，这个attr是不是关联到父查询的Tuple        
  
  Field field;
  Value value;
  Stmt* sub_query;      // #TODO memory management
  std::vector<Value> values;
  void init_attr(const Field &field)
  {
    is_attr = true;
    is_sub_query = false;
    this->field = field;
  }

  void init_value(const Value &value)
  {
    is_attr = false;
    is_sub_query = false;
    this->value = value;
  }
  void init_values(const std::vector<Value> & values){
    is_attr = false;
    is_sub_query = true;
    this->values = values;
  }
  void init_sub_query(Stmt* sub_query_stmt){
    sub_query = sub_query_stmt;
  }
};

class FilterUnit 
{
public:
  FilterUnit() = default;
  ~FilterUnit()
  {}

  void set_comp(CompOp comp)
  {
    comp_ = comp;
  }

  CompOp comp() const
  {
    return comp_;
  }

  void set_left(const FilterObj &obj)
  {
    left_ = obj;
  }
  void set_right(const FilterObj &obj)
  {
    right_ = obj;
  }
  void set_connect_to_parent(const bool a){
    is_connect_to_parent_ = a;
  }
  const FilterObj &left() const
  {
    return left_;
  }
  const FilterObj &right() const
  {
    return right_;
  }
  bool is_connect_to_parent() const {
    return is_connect_to_parent_;
  }
private:
  CompOp comp_ = NO_OP;
  FilterObj left_;
  FilterObj right_;
  bool is_connect_to_parent_ = false;
};

/**
 * @brief Filter/谓词/过滤语句
 * @ingroup Statement
 */
class FilterStmt 
{
public:
  FilterStmt() = default;
  virtual ~FilterStmt();

public:
  const std::vector<FilterUnit *> &filter_units() const
  {
    return filter_units_;
  }

  const std::vector<SelectStmt *> &sub_querys() const
  {
    return sub_querys_;
  }
  const bool is_or() const{
    return is_or_;
  }
public:
  static RC create(Db *db, Table *default_table, std::unordered_map<std::string, Table *> *tables, 
      const ConditionSqlNode *conditions, int condition_num, FilterStmt *&stmt, std::unordered_map<std::string ,Table*> * outer_tables = nullptr);

  static RC create_filter_unit(Db *db, Table *default_table, std::unordered_map<std::string, Table *> *tables, 
      const ConditionSqlNode &condition, FilterUnit *&filter_unit, std::unordered_map<std::string ,Table*> * outer_tables = nullptr);

private:
  std::vector<FilterUnit *> filter_units_;  // 默认当前都是AND关系
  std::vector<SelectStmt *> sub_querys_;
  bool is_or_ = false;                       //是不是or？，在本次比赛中，or和and不会混合出现。
};
