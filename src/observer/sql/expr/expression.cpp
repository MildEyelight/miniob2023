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
// Created by Wangyunlai on 2022/07/05.
//

#include "sql/expr/expression.h"
#include "sql/expr/tuple.h"
#include "sql/operator/physical_operator.h"
#include "sql/operator/logical_operator.h"

using namespace std;
SubQueryExpr::SubQueryExpr(const std::vector<Value>& value, int field_num, int tuple_num):
  values_(value), field_num_of_sub_query_(field_num), tuple_num_from_sub_query_(tuple_num){}
SubQueryExpr::~SubQueryExpr(){}

RC FieldExpr::get_value(const Tuple &tuple, Value &value) const
{
  return tuple.find_cell(TupleCellSpec(table_name(), field_name()), value);
}
RC SubQueryExpr::get_values(const Tuple& tuple, std::vector<Value> &result) {
  //init
  if(sub_query_physical_oper_ == nullptr) {
    result = values_;
    return RC::SUCCESS;
  }

  RC rc = RC::SUCCESS;
  values_.clear();
  rc = sub_query_physical_oper_->open(trx_);
  if(rc != RC::SUCCESS){
    return rc;
  }
  int tuple_num_from_sub_query = 0;
  int field_num_from_sub_query = 0;
  while(RC::SUCCESS == (rc = sub_query_physical_oper_->next(const_cast<Tuple*>(&tuple)))){
    Tuple * tuple = sub_query_physical_oper_->current_tuple();
    if(nullptr == tuple){
      rc = RC::INTERNAL;
      LOG_WARN("failed to get tuple from operator");
      return rc;
    }
    Value value;
    field_num_from_sub_query = tuple->cell_num();
    tuple_num_from_sub_query++;
    
    // Not Allowed for multiple return values.
    rc = tuple->cell_at(0,value);
    if (rc != RC::SUCCESS) {
      return rc;
    }
    values_.push_back(value);
  }
  if(rc != RC::SUCCESS && rc != RC::RECORD_EOF){
    sub_query_physical_oper_->close();
    return rc;
  }
  field_num_of_sub_query_ = field_num_from_sub_query;
  tuple_num_from_sub_query_ = tuple_num_from_sub_query;
  rc = sub_query_physical_oper_->close();
  if(rc != RC::SUCCESS){
    return rc;
  }
  //pad with a null value when no return values for sub.
  if(tuple_num_from_sub_query == 0) {
    Value tmp;
    tmp.set_null(true);
    tmp.set_type(AttrType::INTS);
    tmp.set_length((int)sizeof(int));
    values_.push_back(tmp);
  }
  result = values_;
  return rc;
}
RC ValueExpr::get_value(const Tuple &tuple, Value &value) const
{
  value = value_;
  return RC::SUCCESS;
}

/////////////////////////////////////////////////////////////////////////////////
CastExpr::CastExpr(unique_ptr<Expression> child, AttrType cast_type)
    : child_(std::move(child)), cast_type_(cast_type)
{}

CastExpr::~CastExpr()
{}

RC CastExpr::cast(const Value &value, Value &cast_value) const
{
  RC rc = RC::SUCCESS;
  if (this->value_type() == value.attr_type()) {
    cast_value = value;
    return rc;
  }

  switch (cast_type_) {
    case BOOLEANS: {
      bool val = value.get_boolean();
      cast_value.set_boolean(val);
    } break;
    default: {
      rc = RC::INTERNAL;
      LOG_WARN("unsupported convert from type %d to %d", child_->value_type(), cast_type_);
    }
  }
  return rc;
}

RC CastExpr::get_value(const Tuple &tuple, Value &cell) const
{
  RC rc = child_->get_value(tuple, cell);
  if (rc != RC::SUCCESS) {
    return rc;
  }

  return cast(cell, cell);
}

RC CastExpr::try_get_value(Value &value) const
{
  RC rc = child_->try_get_value(value);
  if (rc != RC::SUCCESS) {
    return rc;
  }

  return cast(value, value);
}

////////////////////////////////////////////////////////////////////////////////

ComparisonExpr::ComparisonExpr(CompOp comp, unique_ptr<Expression> left, unique_ptr<Expression> right)
    : comp_(comp), left_(std::move(left)), right_(std::move(right))
{}

ComparisonExpr::~ComparisonExpr()
{}

RC ComparisonExpr::compare_values(const Value &left, const std::vector<Value> & right, bool &result) const{
  RC rc = RC::SUCCESS;
  switch (comp_) {
    case CompOp::IN_OP:{
      auto it = std::find_if(right.begin(),right.end(),
        [&,left](const Value &r){return !left.compare(r);});
      result = (it != right.end());
    }break;
    case CompOp::NOT_IN_OP:{
      auto it = std::find_if(right.begin(),right.end(),
        [&,left](const Value &r){return !left.compare(r);});
      result = (it == right.end());
    }break;
    case CompOp::EXISTS_OP:{
      result = !right.empty();
    }break;
    case CompOp::NOT_EXISTS_OP:{
      result = right.empty();
    }break;
    default: {
      LOG_WARN("unsupported comparison. %d", comp_);
      rc = RC::INTERNAL;
    } break;
  }
  return rc;
}
RC ComparisonExpr::compare_value(const Value &left, const Value &right, Value &result_) const
{
  RC rc = RC::SUCCESS;

  result_.set_type(BOOLEANS);
  if(comp_ != IS_OP && comp_ != IS_NOT_OP) {
    //not null relevant comparison but with null result
    if(left.is_null() || right.is_null()) {
      result_.set_null(true);
      return rc;
    }
  }

  bool result = false;
  switch (comp_) {
    case EQUAL_TO: {
      result = (0 == left.compare(right));
    } break;
    case LESS_EQUAL: {
      result = (left.compare(right) <= 0);
    } break;
    case NOT_EQUAL: {
      result = (left.compare(right) != 0);
    } break;
    case LESS_THAN: {
      result = (left.compare(right) < 0);
    } break;
    case GREAT_EQUAL: {
      result = (left.compare(right) >= 0);
    } break;
    case GREAT_THAN: {
      result = (left.compare(right) > 0);
    } break;
    case LIKE_OP: {
      //right must be template, left must be tuple cell
      result = (left.like(right) == true);
    } break;
    case NOT_LIKE_OP: {
      result = (left.like(right) == false);
    } break;
    case IS_OP: {
      ASSERT(right.is_null(), "is opertor right value must be null");
      result = left.is_null();
    } break;
    case IS_NOT_OP: {
      ASSERT(right.is_null(), "is opertor right value must be null");
      result = left.is_null() == false;
    } break;
    default: {
      LOG_WARN("unsupported comparison. %d", comp_);
      rc = RC::INTERNAL;
    } break;
  }
  result_.set_boolean(result);

  return rc;
}

RC ComparisonExpr::try_get_value(Value &cell) const
{
  if (left_->type() == ExprType::VALUE && right_->type() == ExprType::VALUE) {
    ValueExpr *left_value_expr = static_cast<ValueExpr *>(left_.get());
    ValueExpr *right_value_expr = static_cast<ValueExpr *>(right_.get());
    const Value &left_cell = left_value_expr->get_value();
    const Value &right_cell = right_value_expr->get_value();

    bool value = false;
    RC rc = compare_value(left_cell, right_cell, cell);
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to compare tuple cells. rc=%s", strrc(rc));
    }
    return rc;
  }

  return RC::INVALID_ARGUMENT;
}

RC ComparisonExpr::get_value(const Tuple &tuple, Value &value) const
{
  RC rc = RC::SUCCESS;
  if(comp_ == CompOp::IN_OP     || comp_ == CompOp::NOT_IN_OP     ||
     comp_ == CompOp::EXISTS_OP || comp_ == CompOp::NOT_EXISTS_OP)  {
    
    //get left value.
    Value left_value;
    rc = left_->get_value(tuple, left_value); // only need when in op;
    if (rc != RC::SUCCESS && (comp_ == CompOp::IN_OP || comp_ == CompOp::NOT_IN_OP)) {
      LOG_WARN("failed to get value of left expression. rc=%s", strrc(rc));
      return rc;
    }
    
    // TODO : get right values by execute sub query, return when no sub querys
    std::vector<Value> right_values;
    SubQueryExpr* subquery_handler = static_cast<SubQueryExpr*>(right_.get());
    rc = subquery_handler->get_values(tuple, right_values);
    if(rc != RC::SUCCESS){
      LOG_WARN("Sub Query Failed");
      return rc;
    }
    
    // check whether the comparsion is legal.
    if(subquery_handler->get_field_num() > 1) {
      LOG_WARN("The subquery returns with %d fields", subquery_handler->get_field_num());
      return RC::INTERNAL;
    }
    
    // begin compare 
    bool bool_value = false;
    rc = compare_values(left_value, right_values, bool_value);
    if (rc == RC::SUCCESS) {
      value.set_boolean(bool_value);
    }
  }

  // 
  else{
    Value left_value;
    Value right_value;

    //init value if subquery by executing subquery.
    if(left_->type() == ExprType::SUBQUERY) {
      std::vector<Value> left_values;
      SubQueryExpr* subquery_handler = static_cast<SubQueryExpr*>(left_.get());
      rc = subquery_handler->get_values(tuple, left_values);
      if(rc != RC::SUCCESS){
        LOG_WARN("Sub Query Failed");
        return rc;
      }
      if(subquery_handler->get_field_num() > 1) return RC::INTERNAL;
      if(subquery_handler->get_tuple_num() > 1) return RC::INTERNAL;
    }

    rc = left_->get_value(tuple, left_value);
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to get value of left expression. rc=%s", strrc(rc));
      return rc;
      
    }

    // if subquery
    if(right_->type() == ExprType::SUBQUERY) {
      std::vector<Value> right_values;
      // TODO : get values by execute sub query, return when no sub querys
      SubQueryExpr* subquery_handler = static_cast<SubQueryExpr*>(right_.get());
      rc = subquery_handler->get_values(tuple, right_values);
      if(rc != RC::SUCCESS){
        LOG_WARN("Sub Query Failed");
        return rc;
      }

      // check if legal illgal if get more than one values.
      // #TODO when in compare, the subquery returns null when no values is set.
      if(subquery_handler->get_field_num() > 1) return RC::INTERNAL;
      if(subquery_handler->get_tuple_num() > 1) return RC::INTERNAL;
    }

    rc = right_->get_value(tuple, right_value);
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to get value of right expression. rc=%s", strrc(rc));
      return rc;
    }
    rc = compare_value(left_value, right_value, value);
  }
  return rc;
}

////////////////////////////////////////////////////////////////////////////////
ConjunctionExpr::ConjunctionExpr(Type type, vector<unique_ptr<Expression>> &children)
    : conjunction_type_(type), children_(std::move(children))
{}

RC ConjunctionExpr::get_value(const Tuple &tuple, Value &value) const
{
  RC rc = RC::SUCCESS;
  if (children_.empty()) {
    if(this->conjunction_type() == ConjunctionExpr::Type::AND)
      value.set_boolean(true);
    else value.set_boolean(false);//false if or exists 
    return rc;
  }

  Value tmp_value;
  for (const unique_ptr<Expression> &expr : children_) {
    rc = expr->get_value(tuple, tmp_value);
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to get value by child expression. rc=%s", strrc(rc));
      return rc;
    }
    bool bool_value = tmp_value.get_boolean();
    if ((conjunction_type_ == Type::AND && !bool_value) || (conjunction_type_ == Type::OR && bool_value)) {
      value.set_boolean(bool_value);
      return rc;
    }
  }

  bool default_value = (conjunction_type_ == Type::AND); 
  value.set_boolean(default_value);
  return rc;
}

////////////////////////////////////////////////////////////////////////////////

ArithmeticExpr::ArithmeticExpr(ArithmeticExpr::Type type, Expression *left, Expression *right)
    : arithmetic_type_(type), left_(left), right_(right)
{}
ArithmeticExpr::ArithmeticExpr(ArithmeticExpr::Type type, unique_ptr<Expression> left, unique_ptr<Expression> right)
    : arithmetic_type_(type), left_(std::move(left)), right_(std::move(right))
{}

AttrType ArithmeticExpr::value_type() const
{
  if (!right_) {
    return left_->value_type();
  }

  if (left_->value_type() == AttrType::INTS &&
      right_->value_type() == AttrType::INTS &&
      arithmetic_type_ != Type::DIV) {
    return AttrType::INTS;
  }
  
  return AttrType::FLOATS;
}

RC ArithmeticExpr::calc_value(const Value &left_value, const Value &right_value, Value &value) const
{
  RC rc = RC::SUCCESS;

  const AttrType target_type = value_type();

  switch (arithmetic_type_) {
    case Type::ADD: {
      if (target_type == AttrType::INTS) {
        value.set_int(left_value.get_int() + right_value.get_int());
      } else {
        value.set_float(left_value.get_float() + right_value.get_float());
      }
    } break;

    case Type::SUB: {
      if (target_type == AttrType::INTS) {
        value.set_int(left_value.get_int() - right_value.get_int());
      } else {
        value.set_float(left_value.get_float() - right_value.get_float());
      }
    } break;

    case Type::MUL: {
      if (target_type == AttrType::INTS) {
        value.set_int(left_value.get_int() * right_value.get_int());
      } else {
        value.set_float(left_value.get_float() * right_value.get_float());
      }
    } break;

    case Type::DIV: {
      if (target_type == AttrType::INTS) {
        if (right_value.get_int() == 0) {
          // NOTE: 设置为整数最大值是不正确的。通常的做法是设置为NULL，但是当前的miniob没有NULL概念，所以这里设置为整数最大值。
          value.set_int(numeric_limits<int>::max());
        } else {
          value.set_int(left_value.get_int() / right_value.get_int());
        }
      } else {
        if (right_value.get_float() > -EPSILON && right_value.get_float() < EPSILON) {
          // NOTE: 设置为浮点数最大值是不正确的。通常的做法是设置为NULL，但是当前的miniob没有NULL概念，所以这里设置为浮点数最大值。
          value.set_float(numeric_limits<float>::max());
        } else {
          value.set_float(left_value.get_float() / right_value.get_float());
        }
      }
    } break;

    case Type::NEGATIVE: {
      if (target_type == AttrType::INTS) {
        value.set_int(-left_value.get_int());
      } else {
        value.set_float(-left_value.get_float());
      }
    } break;

    default: {
      rc = RC::INTERNAL;
      LOG_WARN("unsupported arithmetic type. %d", arithmetic_type_);
    } break;
  }
  return rc;
}

RC ArithmeticExpr::get_value(const Tuple &tuple, Value &value) const
{
  RC rc = RC::SUCCESS;

  Value left_value;
  Value right_value;

  rc = left_->get_value(tuple, left_value);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to get value of left expression. rc=%s", strrc(rc));
    return rc;
  }
  rc = right_->get_value(tuple, right_value);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to get value of right expression. rc=%s", strrc(rc));
    return rc;
  }
  return calc_value(left_value, right_value, value);
}

RC ArithmeticExpr::try_get_value(Value &value) const
{
  RC rc = RC::SUCCESS;

  Value left_value;
  Value right_value;

  rc = left_->try_get_value(left_value);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to get value of left expression. rc=%s", strrc(rc));
    return rc;
  }

  if (right_) {
    rc = right_->try_get_value(right_value);
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to get value of right expression. rc=%s", strrc(rc));
      return rc;
    }
  }

  return calc_value(left_value, right_value, value);
}