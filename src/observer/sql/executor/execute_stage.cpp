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
// Created by Longda on 2021/4/13.
//

#include <string>
#include <sstream>
#include <cstring>

#include "sql/executor/execute_stage.h"

#include "common/log/log.h"
#include "session/session.h"
#include "event/storage_event.h"
#include "event/sql_event.h"
#include "event/session_event.h"
#include "sql/stmt/stmt.h"
#include "sql/stmt/select_stmt.h"
#include "sql/parser/parse_defs.h"
#include "storage/default/default_handler.h"
#include "sql/executor/command_executor.h"
#include "sql/operator/calc_physical_operator.h"

using namespace std;
using namespace common;

RC ExecuteStage::handle_request(SQLStageEvent *sql_event)
{
  RC rc = RC::SUCCESS;
  const unique_ptr<PhysicalOperator> &physical_operator = sql_event->physical_operator();
  if (physical_operator != nullptr) {
    return handle_request_with_physical_operator(sql_event);
  }

  SessionEvent *session_event = sql_event->session_event();

  Stmt *stmt = sql_event->stmt();
  if (stmt != nullptr) {
    CommandExecutor command_executor;
    rc = command_executor.execute(sql_event);
    session_event->sql_result()->set_return_code(rc);
  } else {
    return RC::INTERNAL;
  }
  return rc;
}

RC ExecuteStage::handle_request_with_physical_operator(SQLStageEvent *sql_event)
{
  RC rc = RC::SUCCESS;

  Stmt *stmt = sql_event->stmt();
  ASSERT(stmt != nullptr, "SQL Statement shouldn't be empty!");

  unique_ptr<PhysicalOperator> &physical_operator = sql_event->physical_operator();
  ASSERT(physical_operator != nullptr, "physical operator should not be null");

  // TODO 这里也可以优化一下，是否可以让physical operator自己设置tuple schema
  TupleSchema schema;
  switch (stmt->type()) {
    case StmtType::SELECT: {
      SelectStmt *select_stmt = static_cast<SelectStmt *>(stmt);
      bool with_table_name = select_stmt->tables().size() > 1;
      bool visible = true;
      for (const Field &field : select_stmt->query_fields()) {
        AggrOp aggr_op = field.aggr_op();
        const char* table_name = field.table_name();
        const char* table_name_alias = field.table_name_alias();
        const char* field_name = field.field_name();
        const char* field_name_alias = field.get_name_with_oper();
        LOG_DEBUG("This cell table name %s, field name %s", table_name,field_name);
        //没有聚合操作时的正常情况
        //if(aggr_op == AggrOp::NO_AGGR_OP){
        // #TODO 这里用TUPLE设置显示名称的时候，field_name直接就输出的是SUM+(ID),看看能不能把组装过程放到
        // append_cell 里面
        if (with_table_name) {
          if(strlen(table_name_alias) !=0 && strcmp(table_name,table_name_alias) !=0){
            schema.append_cell(table_name_alias, field_name);
            schema.append_aggr_ops(aggr_op);
          }
          else{
            schema.append_cell(table_name, field_name);
            schema.append_aggr_ops(aggr_op);
          }
        } else {
          schema.append_cell(field_name);
          schema.append_aggr_ops(aggr_op);
        }
      }
    } break;

    case StmtType::CALC: {
      CalcPhysicalOperator *calc_operator = static_cast<CalcPhysicalOperator *>(physical_operator.get());
      for (const unique_ptr<Expression> & expr : calc_operator->expressions()) {
        schema.append_cell(expr->name().c_str());
      }
    } break;

    case StmtType::EXPLAIN: {
      schema.append_cell("Query Plan");
    } break;
    default: {
      // 只有select返回结果
    } break;
  }

  SqlResult *sql_result = sql_event->session_event()->sql_result();
  sql_result->set_tuple_schema(schema);
  sql_result->set_operator(std::move(physical_operator));
  return rc;
}
