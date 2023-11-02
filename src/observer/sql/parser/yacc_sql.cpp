/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "yacc_sql.y"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#include "common/log/log.h"
#include "common/lang/string.h"
#include "sql/parser/parse_defs.h"
#include "sql/parser/yacc_sql.hpp"
#include "sql/parser/lex_sql.h"
#include "sql/expr/expression.h"

using namespace std;

string token_name(const char *sql_string, YYLTYPE *llocp)
{
  return string(sql_string + llocp->first_column, llocp->last_column - llocp->first_column + 1);
}

int yyerror(YYLTYPE *llocp, const char *sql_string, ParsedSqlResult *sql_result, yyscan_t scanner, const char *msg)
{
  std::unique_ptr<ParsedSqlNode> error_sql_node = std::make_unique<ParsedSqlNode>(SCF_ERROR);
  error_sql_node->error.error_msg = msg;
  error_sql_node->error.line = llocp->first_line;
  error_sql_node->error.column = llocp->first_column;
  sql_result->add_sql_node(std::move(error_sql_node));
  return 0;
}

ArithmeticExpr *create_arithmetic_expression(ArithmeticExpr::Type type,
                                             Expression *left,
                                             Expression *right,
                                             const char *sql_string,
                                             YYLTYPE *llocp)
{
  ArithmeticExpr *expr = new ArithmeticExpr(type, left, right);
  expr->set_name(token_name(sql_string, llocp));
  return expr;
}


#line 115 "yacc_sql.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "yacc_sql.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_SEMICOLON = 3,                  /* SEMICOLON  */
  YYSYMBOL_CREATE = 4,                     /* CREATE  */
  YYSYMBOL_DROP = 5,                       /* DROP  */
  YYSYMBOL_TABLE = 6,                      /* TABLE  */
  YYSYMBOL_TABLES = 7,                     /* TABLES  */
  YYSYMBOL_UNIQUE = 8,                     /* UNIQUE  */
  YYSYMBOL_INDEX = 9,                      /* INDEX  */
  YYSYMBOL_CALC = 10,                      /* CALC  */
  YYSYMBOL_SELECT = 11,                    /* SELECT  */
  YYSYMBOL_DESC = 12,                      /* DESC  */
  YYSYMBOL_SHOW = 13,                      /* SHOW  */
  YYSYMBOL_SYNC = 14,                      /* SYNC  */
  YYSYMBOL_INSERT = 15,                    /* INSERT  */
  YYSYMBOL_DELETE = 16,                    /* DELETE  */
  YYSYMBOL_UPDATE = 17,                    /* UPDATE  */
  YYSYMBOL_LBRACE = 18,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 19,                    /* RBRACE  */
  YYSYMBOL_COMMA = 20,                     /* COMMA  */
  YYSYMBOL_TRX_BEGIN = 21,                 /* TRX_BEGIN  */
  YYSYMBOL_TRX_COMMIT = 22,                /* TRX_COMMIT  */
  YYSYMBOL_TRX_ROLLBACK = 23,              /* TRX_ROLLBACK  */
  YYSYMBOL_INT_T = 24,                     /* INT_T  */
  YYSYMBOL_STRING_T = 25,                  /* STRING_T  */
  YYSYMBOL_FLOAT_T = 26,                   /* FLOAT_T  */
  YYSYMBOL_DATE_T = 27,                    /* DATE_T  */
  YYSYMBOL_HELP = 28,                      /* HELP  */
  YYSYMBOL_EXIT = 29,                      /* EXIT  */
  YYSYMBOL_DOT = 30,                       /* DOT  */
  YYSYMBOL_INTO = 31,                      /* INTO  */
  YYSYMBOL_VALUES = 32,                    /* VALUES  */
  YYSYMBOL_FROM = 33,                      /* FROM  */
  YYSYMBOL_INNER = 34,                     /* INNER  */
  YYSYMBOL_JOIN = 35,                      /* JOIN  */
  YYSYMBOL_WHERE = 36,                     /* WHERE  */
  YYSYMBOL_AND = 37,                       /* AND  */
  YYSYMBOL_OR = 38,                        /* OR  */
  YYSYMBOL_SET = 39,                       /* SET  */
  YYSYMBOL_ON = 40,                        /* ON  */
  YYSYMBOL_LOAD = 41,                      /* LOAD  */
  YYSYMBOL_DATA = 42,                      /* DATA  */
  YYSYMBOL_INFILE = 43,                    /* INFILE  */
  YYSYMBOL_EXPLAIN = 44,                   /* EXPLAIN  */
  YYSYMBOL_NOT = 45,                       /* NOT  */
  YYSYMBOL_IN = 46,                        /* IN  */
  YYSYMBOL_EXISTS = 47,                    /* EXISTS  */
  YYSYMBOL_LIKE = 48,                      /* LIKE  */
  YYSYMBOL_ORDER = 49,                     /* ORDER  */
  YYSYMBOL_BY = 50,                        /* BY  */
  YYSYMBOL_ASC = 51,                       /* ASC  */
  YYSYMBOL_MAX = 52,                       /* MAX  */
  YYSYMBOL_MIN = 53,                       /* MIN  */
  YYSYMBOL_COUNT = 54,                     /* COUNT  */
  YYSYMBOL_AVG = 55,                       /* AVG  */
  YYSYMBOL_SUM = 56,                       /* SUM  */
  YYSYMBOL_NULL_T = 57,                    /* NULL_T  */
  YYSYMBOL_IS = 58,                        /* IS  */
  YYSYMBOL_EQ = 59,                        /* EQ  */
  YYSYMBOL_LT = 60,                        /* LT  */
  YYSYMBOL_GT = 61,                        /* GT  */
  YYSYMBOL_LE = 62,                        /* LE  */
  YYSYMBOL_GE = 63,                        /* GE  */
  YYSYMBOL_NE = 64,                        /* NE  */
  YYSYMBOL_NUMBER = 65,                    /* NUMBER  */
  YYSYMBOL_FLOAT = 66,                     /* FLOAT  */
  YYSYMBOL_DATE_STR = 67,                  /* DATE_STR  */
  YYSYMBOL_ID = 68,                        /* ID  */
  YYSYMBOL_SSS = 69,                       /* SSS  */
  YYSYMBOL_70_ = 70,                       /* '+'  */
  YYSYMBOL_71_ = 71,                       /* '-'  */
  YYSYMBOL_72_ = 72,                       /* '*'  */
  YYSYMBOL_73_ = 73,                       /* '/'  */
  YYSYMBOL_UMINUS = 74,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 75,                  /* $accept  */
  YYSYMBOL_commands = 76,                  /* commands  */
  YYSYMBOL_command_wrapper = 77,           /* command_wrapper  */
  YYSYMBOL_exit_stmt = 78,                 /* exit_stmt  */
  YYSYMBOL_help_stmt = 79,                 /* help_stmt  */
  YYSYMBOL_sync_stmt = 80,                 /* sync_stmt  */
  YYSYMBOL_begin_stmt = 81,                /* begin_stmt  */
  YYSYMBOL_commit_stmt = 82,               /* commit_stmt  */
  YYSYMBOL_rollback_stmt = 83,             /* rollback_stmt  */
  YYSYMBOL_drop_table_stmt = 84,           /* drop_table_stmt  */
  YYSYMBOL_show_tables_stmt = 85,          /* show_tables_stmt  */
  YYSYMBOL_desc_table_stmt = 86,           /* desc_table_stmt  */
  YYSYMBOL_ind_list = 87,                  /* ind_list  */
  YYSYMBOL_unique_token = 88,              /* unique_token  */
  YYSYMBOL_create_index_stmt = 89,         /* create_index_stmt  */
  YYSYMBOL_drop_index_stmt = 90,           /* drop_index_stmt  */
  YYSYMBOL_create_table_stmt = 91,         /* create_table_stmt  */
  YYSYMBOL_attr_def_list = 92,             /* attr_def_list  */
  YYSYMBOL_attr_def = 93,                  /* attr_def  */
  YYSYMBOL_attr_can_null = 94,             /* attr_can_null  */
  YYSYMBOL_number = 95,                    /* number  */
  YYSYMBOL_type = 96,                      /* type  */
  YYSYMBOL_insert_stmt = 97,               /* insert_stmt  */
  YYSYMBOL_value_list = 98,                /* value_list  */
  YYSYMBOL_value = 99,                     /* value  */
  YYSYMBOL_join_expr = 100,                /* join_expr  */
  YYSYMBOL_on_condition_exprs = 101,       /* on_condition_exprs  */
  YYSYMBOL_join_table = 102,               /* join_table  */
  YYSYMBOL_join_tables = 103,              /* join_tables  */
  YYSYMBOL_delete_stmt = 104,              /* delete_stmt  */
  YYSYMBOL_update_expr = 105,              /* update_expr  */
  YYSYMBOL_update_exprs = 106,             /* update_exprs  */
  YYSYMBOL_update_stmt = 107,              /* update_stmt  */
  YYSYMBOL_order_by_attr = 108,            /* order_by_attr  */
  YYSYMBOL_order_by_attrs = 109,           /* order_by_attrs  */
  YYSYMBOL_order_by = 110,                 /* order_by  */
  YYSYMBOL_select_stmt = 111,              /* select_stmt  */
  YYSYMBOL_calc_stmt = 112,                /* calc_stmt  */
  YYSYMBOL_expression_list = 113,          /* expression_list  */
  YYSYMBOL_expression = 114,               /* expression  */
  YYSYMBOL_select_attr = 115,              /* select_attr  */
  YYSYMBOL_aggr_op = 116,                  /* aggr_op  */
  YYSYMBOL_aggr_func = 117,                /* aggr_func  */
  YYSYMBOL_aggr_func_list = 118,           /* aggr_func_list  */
  YYSYMBOL_rel_attr = 119,                 /* rel_attr  */
  YYSYMBOL_attr_list = 120,                /* attr_list  */
  YYSYMBOL_rel_list = 121,                 /* rel_list  */
  YYSYMBOL_where = 122,                    /* where  */
  YYSYMBOL_condition_list = 123,           /* condition_list  */
  YYSYMBOL_condition = 124,                /* condition  */
  YYSYMBOL_comp_op = 125,                  /* comp_op  */
  YYSYMBOL_comp_op_reverse = 126,          /* comp_op_reverse  */
  YYSYMBOL_load_data_stmt = 127,           /* load_data_stmt  */
  YYSYMBOL_explain_stmt = 128,             /* explain_stmt  */
  YYSYMBOL_set_variable_stmt = 129,        /* set_variable_stmt  */
  YYSYMBOL_opt_semicolon = 130             /* opt_semicolon  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  75
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   305

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  75
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  56
/* YYNRULES -- Number of rules.  */
#define YYNRULES  155
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  289

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   325


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    72,    70,     2,    71,     2,    73,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    74
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   218,   218,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   249,   255,   260,   266,   272,   278,   284,
     291,   297,   305,   308,   319,   322,   326,   350,   360,   379,
     382,   395,   404,   416,   419,   422,   428,   431,   432,   433,
     434,   437,   453,   456,   467,   471,   475,   481,   485,   493,
     498,   506,   509,   515,   523,   534,   543,   546,   559,   572,
     584,   598,   601,   614,   636,   642,   649,   659,   662,   668,
     681,   684,   691,   722,   758,   768,   773,   784,   787,   790,
     793,   796,   800,   803,   811,   818,   827,   839,   842,   845,
     848,   851,   857,   863,   869,   881,   884,   896,   901,   911,
     914,   928,   931,   944,   947,   953,   956,   961,   966,   974,
     986,   998,  1010,  1022,  1034,  1046,  1060,  1074,  1088,  1102,
    1116,  1130,  1147,  1164,  1181,  1202,  1203,  1204,  1205,  1206,
    1207,  1208,  1209,  1210,  1211,  1215,  1216,  1217,  1218,  1219,
    1220,  1223,  1236,  1244,  1254,  1255
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "SEMICOLON", "CREATE",
  "DROP", "TABLE", "TABLES", "UNIQUE", "INDEX", "CALC", "SELECT", "DESC",
  "SHOW", "SYNC", "INSERT", "DELETE", "UPDATE", "LBRACE", "RBRACE",
  "COMMA", "TRX_BEGIN", "TRX_COMMIT", "TRX_ROLLBACK", "INT_T", "STRING_T",
  "FLOAT_T", "DATE_T", "HELP", "EXIT", "DOT", "INTO", "VALUES", "FROM",
  "INNER", "JOIN", "WHERE", "AND", "OR", "SET", "ON", "LOAD", "DATA",
  "INFILE", "EXPLAIN", "NOT", "IN", "EXISTS", "LIKE", "ORDER", "BY", "ASC",
  "MAX", "MIN", "COUNT", "AVG", "SUM", "NULL_T", "IS", "EQ", "LT", "GT",
  "LE", "GE", "NE", "NUMBER", "FLOAT", "DATE_STR", "ID", "SSS", "'+'",
  "'-'", "'*'", "'/'", "UMINUS", "$accept", "commands", "command_wrapper",
  "exit_stmt", "help_stmt", "sync_stmt", "begin_stmt", "commit_stmt",
  "rollback_stmt", "drop_table_stmt", "show_tables_stmt",
  "desc_table_stmt", "ind_list", "unique_token", "create_index_stmt",
  "drop_index_stmt", "create_table_stmt", "attr_def_list", "attr_def",
  "attr_can_null", "number", "type", "insert_stmt", "value_list", "value",
  "join_expr", "on_condition_exprs", "join_table", "join_tables",
  "delete_stmt", "update_expr", "update_exprs", "update_stmt",
  "order_by_attr", "order_by_attrs", "order_by", "select_stmt",
  "calc_stmt", "expression_list", "expression", "select_attr", "aggr_op",
  "aggr_func", "aggr_func_list", "rel_attr", "attr_list", "rel_list",
  "where", "condition_list", "condition", "comp_op", "comp_op_reverse",
  "load_data_stmt", "explain_stmt", "set_variable_stmt", "opt_semicolon", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-230)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     180,    29,     6,    36,   -27,   -55,    35,  -230,    -1,    37,
       9,  -230,  -230,  -230,  -230,  -230,    19,    47,   180,    91,
      89,  -230,  -230,  -230,  -230,  -230,  -230,  -230,  -230,  -230,
    -230,  -230,  -230,  -230,  -230,  -230,  -230,  -230,  -230,  -230,
    -230,    30,  -230,    90,    50,    57,    36,  -230,  -230,  -230,
    -230,  -230,    36,  -230,  -230,    24,  -230,  -230,  -230,  -230,
    -230,    74,  -230,    93,   110,   109,   111,  -230,  -230,    62,
      65,   101,    82,   104,  -230,  -230,  -230,  -230,   131,    85,
    -230,   112,    -5,  -230,    36,    36,    36,    36,    36,    86,
      88,   -25,   209,  -230,    92,  -230,   118,   121,    94,    77,
      99,   102,   129,   105,  -230,  -230,   -20,   -20,  -230,  -230,
    -230,    -3,   -10,   139,   109,   111,   143,    70,  -230,   113,
     154,  -230,   145,    84,   157,   119,  -230,   120,   151,  -230,
     130,    40,   121,  -230,   132,  -230,  -230,  -230,    77,   171,
     142,   181,   183,   190,  -230,    42,   114,    94,   121,   199,
    -230,  -230,  -230,  -230,   -11,   102,   187,   189,   191,  -230,
     170,    40,   121,   168,   201,   198,   203,   205,   171,    16,
     207,  -230,   182,  -230,  -230,  -230,  -230,  -230,  -230,    55,
      23,   208,    98,    70,    70,   171,  -230,   154,  -230,   164,
     169,   176,  -230,  -230,   157,  -230,   172,  -230,    70,  -230,
     168,   216,  -230,  -230,    77,   218,   196,   171,   248,   250,
    -230,    77,  -230,   171,  -230,  -230,   251,    -6,   171,  -230,
    -230,  -230,  -230,   252,  -230,  -230,  -230,   253,  -230,  -230,
     254,  -230,   233,  -230,    92,   198,  -230,  -230,  -230,  -230,
    -230,  -230,  -230,   147,   256,  -230,    77,   198,   257,    -6,
     198,   258,   259,  -230,   -34,   211,   261,    70,   262,  -230,
      -2,  -230,  -230,  -230,  -230,   198,   264,  -230,   198,   265,
     266,  -230,  -230,  -230,   254,  -230,  -230,    92,  -230,  -230,
     267,  -230,   268,  -230,  -230,  -230,  -230,  -230,  -230
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    34,     0,     0,     0,     0,     0,    25,     0,     0,
       0,    26,    27,    28,    24,    23,     0,     0,     0,     0,
     154,    22,    21,    14,    15,    16,    17,     9,    10,    11,
      12,    13,     8,     5,     7,     6,     4,     3,    18,    19,
      20,     0,    35,     0,     0,     0,     0,    57,    54,    55,
      56,    58,     0,    93,    84,    85,    97,   100,   101,    98,
      99,   107,    94,     0,     0,   105,   109,    31,    30,     0,
       0,     0,     0,     0,   152,     1,   155,     2,     0,     0,
      29,     0,     0,    92,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    96,     0,    95,     0,   113,     0,     0,
       0,     0,     0,     0,    91,    86,    87,    88,    89,    90,
     108,   111,     0,     0,   105,   109,     0,   115,    68,     0,
      71,   153,     0,     0,    39,     0,    37,     0,     0,    59,
       0,    66,   113,   103,     0,   102,   106,   110,     0,     0,
       0,     0,     0,     0,   114,   116,     0,     0,   113,     0,
      47,    48,    49,    50,    43,     0,     0,     0,   111,    60,
      65,    66,   113,    80,     0,    52,     0,     0,     0,     0,
       0,   142,   143,   135,   136,   137,   138,   139,   140,     0,
       0,     0,     0,   115,   115,     0,    69,    71,    73,     0,
       0,     0,    45,    42,    39,    38,     0,   112,    61,    67,
      80,     0,    82,   104,     0,     0,     0,     0,     0,     0,
     141,     0,   144,     0,   120,   122,     0,     0,     0,   119,
     121,   117,   118,     0,    72,   151,    46,     0,    44,    40,
      32,    64,    62,    83,    77,    52,    51,   145,   146,   147,
     148,   149,   150,     0,     0,   123,     0,    52,     0,     0,
      52,     0,     0,    70,    43,     0,     0,   115,    78,    81,
      74,    53,   129,   130,   124,    52,     0,   128,    52,     0,
       0,   125,   127,    41,    32,    36,    63,    77,    76,    75,
       0,   133,     0,   126,   131,    33,    79,   134,   132
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -230,  -230,   263,  -230,  -230,  -230,  -230,  -230,  -230,  -230,
    -230,  -230,    14,  -230,  -230,  -230,  -230,    95,   135,    38,
    -230,  -230,  -230,  -229,   -98,  -230,  -230,   184,   133,  -230,
     144,   106,  -230,  -230,    20,    96,  -135,  -230,   214,   -30,
    -230,  -230,   210,   185,    -4,   186,   146,  -124,  -181,   107,
     160,  -230,  -230,  -230,  -230,  -230
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,   256,    43,    30,    31,    32,   156,   124,   193,
     227,   154,    33,   205,    53,   130,   231,   161,   162,    34,
     120,   148,    35,   258,   259,   202,    36,    37,    54,    55,
      63,    64,    65,    93,   143,    95,   132,   118,   144,   145,
     179,   243,    38,    39,    40,    77
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      66,   121,   221,   222,   166,     4,   261,   190,   163,   133,
     278,   191,    44,    67,   104,    45,    82,   127,   266,   142,
     134,   270,    83,   192,   188,    56,    57,    58,    59,    60,
      69,   128,   129,   208,   191,    41,   280,    42,   200,   282,
     165,    61,    68,   112,    84,    62,   192,   113,   186,   279,
     223,    47,    87,    88,    46,   106,   107,   108,   109,    48,
      49,    50,   209,    51,   210,    85,    86,    87,    88,   216,
      70,   210,   244,   213,   128,   129,   276,    71,   248,   183,
     184,   214,   251,   252,   219,   142,   142,    72,   139,    73,
     115,    75,    76,    47,    85,    86,    87,    88,    78,    79,
     142,    48,    49,    50,    89,    51,   235,    52,   150,   151,
     152,   153,    47,   247,   269,   140,   218,   141,    80,   250,
      48,    49,    50,    61,    51,    81,    90,    47,    91,    92,
      96,    94,   185,    97,    47,    48,    49,    50,    61,    51,
      98,    99,    48,    49,    50,   262,    51,   100,   265,   101,
     116,   268,   103,   102,   110,    47,   111,   117,   135,   142,
      61,   138,   119,    48,    49,    50,    61,    51,   122,   125,
     123,    47,   146,   126,   147,   215,   149,   155,   220,    48,
      49,    50,     4,    51,     1,     2,   159,   157,   158,   167,
       3,     4,     5,     6,     7,     8,     9,    10,   160,   168,
     164,    11,    12,    13,    47,   189,   195,   196,    14,    15,
     198,   127,    48,    49,    50,    61,    51,   201,   204,    16,
     203,    17,   206,   207,    18,   211,   217,   212,   169,   170,
     260,   171,   225,   228,   226,   180,   181,   236,   171,   263,
     230,   172,   173,   174,   175,   176,   177,   178,   172,   173,
     174,   175,   176,   177,   178,   237,   238,   239,   240,   241,
     242,    56,    57,    58,    59,    60,   234,   245,   246,   249,
     257,   253,   254,   260,   255,   264,   267,   271,   272,   274,
     275,    74,   277,   281,   283,   284,   287,   288,   285,   229,
     194,   187,   273,   224,   199,   131,   233,   286,   105,   136,
       0,   137,   114,   182,   197,   232
};

static const yytype_int16 yycheck[] =
{
       4,    99,   183,   184,   139,    11,   235,    18,   132,    19,
      12,    45,     6,    68,    19,     9,    46,    20,   247,   117,
      30,   250,    52,    57,   148,    52,    53,    54,    55,    56,
      31,    34,    35,   168,    45,     6,   265,     8,   162,   268,
     138,    68,     7,    68,    20,    72,    57,    72,   146,    51,
     185,    57,    72,    73,    18,    85,    86,    87,    88,    65,
      66,    67,    46,    69,    48,    70,    71,    72,    73,    46,
      33,    48,   207,    18,    34,    35,   257,    68,   213,    37,
      38,   179,   217,   218,   182,   183,   184,    68,    18,    42,
      94,     0,     3,    57,    70,    71,    72,    73,    68,     9,
     198,    65,    66,    67,    30,    69,   204,    71,    24,    25,
      26,    27,    57,   211,   249,    45,    18,    47,    68,   217,
      65,    66,    67,    68,    69,    68,    33,    57,    18,    20,
      68,    20,    18,    68,    57,    65,    66,    67,    68,    69,
      39,    59,    65,    66,    67,   243,    69,    43,   246,    18,
      32,   249,    40,    68,    68,    57,    68,    36,    19,   257,
      68,    18,    68,    65,    66,    67,    68,    69,    69,    40,
      68,    57,    59,    68,    20,   179,    31,    20,   182,    65,
      66,    67,    11,    69,     4,     5,    35,    68,    68,    47,
      10,    11,    12,    13,    14,    15,    16,    17,    68,    18,
      68,    21,    22,    23,    57,     6,    19,    18,    28,    29,
      40,    20,    65,    66,    67,    68,    69,    49,    20,    39,
      19,    41,    19,    18,    44,    18,    18,    45,    45,    46,
     234,    48,    68,    57,    65,    45,    46,    19,    48,   243,
      68,    58,    59,    60,    61,    62,    63,    64,    58,    59,
      60,    61,    62,    63,    64,    59,    60,    61,    62,    63,
      64,    52,    53,    54,    55,    56,    50,    19,    18,    18,
      37,    19,    19,   277,    20,    19,    19,    19,    19,    68,
      19,    18,    20,    19,    19,    19,    19,    19,   274,   194,
     155,   147,   254,   187,   161,   111,   200,   277,    84,   114,
      -1,   115,    92,   143,   158,   198
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,    10,    11,    12,    13,    14,    15,    16,
      17,    21,    22,    23,    28,    29,    39,    41,    44,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      89,    90,    91,    97,   104,   107,   111,   112,   127,   128,
     129,     6,     8,    88,     6,     9,    18,    57,    65,    66,
      67,    69,    71,    99,   113,   114,    52,    53,    54,    55,
      56,    68,    72,   115,   116,   117,   119,    68,     7,    31,
      33,    68,    68,    42,    77,     0,     3,   130,    68,     9,
      68,    68,   114,   114,    20,    70,    71,    72,    73,    30,
      33,    18,    20,   118,    20,   120,    68,    68,    39,    59,
      43,    18,    68,    40,    19,   113,   114,   114,   114,   114,
      68,    68,    68,    72,   117,   119,    32,    36,   122,    68,
     105,    99,    69,    68,    93,    40,    68,    20,    34,    35,
     100,   102,   121,    19,    30,    19,   118,   120,    18,    18,
      45,    47,    99,   119,   123,   124,    59,    20,   106,    31,
      24,    25,    26,    27,    96,    20,    92,    68,    68,    35,
      68,   102,   103,   122,    68,    99,   111,    47,    18,    45,
      46,    48,    58,    59,    60,    61,    62,    63,    64,   125,
      45,    46,   125,    37,    38,    18,    99,   105,   122,     6,
      18,    45,    57,    94,    93,    19,    18,   121,    40,   103,
     122,    49,   110,    19,    20,    98,    19,    18,   111,    46,
      48,    18,    45,    18,    99,   119,    46,    18,    18,    99,
     119,   123,   123,   111,   106,    68,    65,    95,    57,    92,
      68,   101,   124,   110,    50,    99,    19,    59,    60,    61,
      62,    63,    64,   126,   111,    19,    18,    99,   111,    18,
      99,   111,   111,    19,    19,    20,    87,    37,   108,   109,
     119,    98,    99,   119,    19,    99,    98,    19,    99,   111,
      98,    19,    19,    94,    68,    19,   123,    20,    12,    51,
      98,    19,    98,    19,    19,    87,   109,    19,    19
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    75,    76,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    87,    88,    88,    89,    90,    91,    92,
      92,    93,    93,    94,    94,    94,    95,    96,    96,    96,
      96,    97,    98,    98,    99,    99,    99,    99,    99,   100,
     100,   101,   101,   101,   102,   102,   103,   103,   104,   105,
     105,   106,   106,   107,   108,   108,   108,   109,   109,   109,
     110,   110,   111,   111,   112,   113,   113,   114,   114,   114,
     114,   114,   114,   114,   115,   115,   115,   116,   116,   116,
     116,   116,   117,   117,   117,   118,   118,   119,   119,   120,
     120,   121,   121,   122,   122,   123,   123,   123,   123,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   126,   126,   126,   126,   126,
     126,   127,   128,   129,   130,   130
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       2,     2,     0,     3,     0,     1,    10,     5,     7,     0,
       3,     6,     3,     0,     2,     1,     1,     1,     1,     1,
       1,     8,     0,     3,     1,     1,     1,     1,     1,     1,
       2,     0,     1,     3,     4,     2,     0,     2,     4,     3,
       5,     0,     3,     6,     1,     2,     2,     0,     1,     3,
       0,     3,     7,     8,     2,     1,     3,     3,     3,     3,
       3,     3,     2,     1,     1,     2,     2,     1,     1,     1,
       1,     1,     4,     4,     6,     0,     3,     1,     3,     0,
       3,     0,     3,     0,     2,     0,     1,     3,     3,     3,
       3,     3,     3,     4,     5,     5,     6,     5,     5,     5,
       5,     6,     7,     6,     7,     1,     1,     1,     1,     1,
       1,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     7,     2,     4,     0,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (&yylloc, sql_string, sql_result, scanner, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location, sql_string, sql_result, scanner); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  YY_USE (sql_string);
  YY_USE (sql_result);
  YY_USE (scanner);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp, sql_string, sql_result, scanner);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]), sql_string, sql_result, scanner);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, sql_string, sql_result, scanner); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
  YYLTYPE *yylloc;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  YY_USE (sql_string);
  YY_USE (sql_result);
  YY_USE (scanner);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex (&yylval, &yylloc, scanner);
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* commands: command_wrapper opt_semicolon  */
#line 219 "yacc_sql.y"
  {
    std::unique_ptr<ParsedSqlNode> sql_node = std::unique_ptr<ParsedSqlNode>((yyvsp[-1].sql_node));
    sql_result->add_sql_node(std::move(sql_node));
  }
#line 1848 "yacc_sql.cpp"
    break;

  case 23: /* exit_stmt: EXIT  */
#line 249 "yacc_sql.y"
         {
      (void)yynerrs;  // 这么写为了消除yynerrs未使用的告警。如果你有更好的方法欢迎提PR
      (yyval.sql_node) = new ParsedSqlNode(SCF_EXIT);
    }
#line 1857 "yacc_sql.cpp"
    break;

  case 24: /* help_stmt: HELP  */
#line 255 "yacc_sql.y"
         {
      (yyval.sql_node) = new ParsedSqlNode(SCF_HELP);
    }
#line 1865 "yacc_sql.cpp"
    break;

  case 25: /* sync_stmt: SYNC  */
#line 260 "yacc_sql.y"
         {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SYNC);
    }
#line 1873 "yacc_sql.cpp"
    break;

  case 26: /* begin_stmt: TRX_BEGIN  */
#line 266 "yacc_sql.y"
               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_BEGIN);
    }
#line 1881 "yacc_sql.cpp"
    break;

  case 27: /* commit_stmt: TRX_COMMIT  */
#line 272 "yacc_sql.y"
               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_COMMIT);
    }
#line 1889 "yacc_sql.cpp"
    break;

  case 28: /* rollback_stmt: TRX_ROLLBACK  */
#line 278 "yacc_sql.y"
                  {
      (yyval.sql_node) = new ParsedSqlNode(SCF_ROLLBACK);
    }
#line 1897 "yacc_sql.cpp"
    break;

  case 29: /* drop_table_stmt: DROP TABLE ID  */
#line 284 "yacc_sql.y"
                  {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DROP_TABLE);
      (yyval.sql_node)->drop_table.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 1907 "yacc_sql.cpp"
    break;

  case 30: /* show_tables_stmt: SHOW TABLES  */
#line 291 "yacc_sql.y"
                {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SHOW_TABLES);
    }
#line 1915 "yacc_sql.cpp"
    break;

  case 31: /* desc_table_stmt: DESC ID  */
#line 297 "yacc_sql.y"
             {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DESC_TABLE);
      (yyval.sql_node)->desc_table.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 1925 "yacc_sql.cpp"
    break;

  case 32: /* ind_list: %empty  */
#line 305 "yacc_sql.y"
    {
      (yyval.index_list) = nullptr;
    }
#line 1933 "yacc_sql.cpp"
    break;

  case 33: /* ind_list: COMMA ID ind_list  */
#line 308 "yacc_sql.y"
                        {
      if((yyvsp[0].index_list) != nullptr){
        (yyval.index_list) = (yyvsp[0].index_list);
      }else{
        (yyval.index_list) = new std::vector<std::string>; 
      }
      (yyval.index_list)->push_back((yyvsp[-1].string));
      free((yyvsp[-1].string));
    }
#line 1947 "yacc_sql.cpp"
    break;

  case 34: /* unique_token: %empty  */
#line 319 "yacc_sql.y"
           {
    (yyval.is_unique) = nullptr;
  }
#line 1955 "yacc_sql.cpp"
    break;

  case 35: /* unique_token: UNIQUE  */
#line 322 "yacc_sql.y"
           {
    (yyval.is_unique) = new std::string("uniqueistrue");
  }
#line 1963 "yacc_sql.cpp"
    break;

  case 36: /* create_index_stmt: CREATE unique_token INDEX ID ON ID LBRACE ID ind_list RBRACE  */
#line 327 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CREATE_INDEX);
      CreateIndexSqlNode &create_index = (yyval.sql_node)->create_index;
      if((yyvsp[-8].is_unique) != nullptr){
        create_index.is_unique = *(yyvsp[-8].is_unique);
        delete (yyvsp[-8].is_unique);
      }
      create_index.index_name = (yyvsp[-6].string);
      create_index.relation_name = (yyvsp[-4].string);
      std::vector<string> * ind_list = (yyvsp[-1].index_list);
      if(ind_list != nullptr) {
        create_index.attribute_name.swap(*ind_list);
      }
      create_index.attribute_name.push_back((yyvsp[-2].string));
      std::reverse(create_index.attribute_name.begin(),create_index.attribute_name.end());
      free((yyvsp[-6].string));
      free((yyvsp[-4].string));
      free((yyvsp[-2].string));
      delete (yyvsp[-1].index_list);
    }
#line 1988 "yacc_sql.cpp"
    break;

  case 37: /* drop_index_stmt: DROP INDEX ID ON ID  */
#line 351 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DROP_INDEX);
      (yyval.sql_node)->drop_index.index_name = (yyvsp[-2].string);
      (yyval.sql_node)->drop_index.relation_name = (yyvsp[0].string);
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 2000 "yacc_sql.cpp"
    break;

  case 38: /* create_table_stmt: CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE  */
#line 361 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CREATE_TABLE);
      CreateTableSqlNode &create_table = (yyval.sql_node)->create_table;
      create_table.relation_name = (yyvsp[-4].string);
      free((yyvsp[-4].string));

      std::vector<AttrInfoSqlNode> *src_attrs = (yyvsp[-1].attr_infos);

      if (src_attrs != nullptr) {
        create_table.attr_infos.swap(*src_attrs);
      }
      create_table.attr_infos.emplace_back(*(yyvsp[-2].attr_info));
      std::reverse(create_table.attr_infos.begin(), create_table.attr_infos.end());
      delete (yyvsp[-2].attr_info);
    }
#line 2020 "yacc_sql.cpp"
    break;

  case 39: /* attr_def_list: %empty  */
#line 379 "yacc_sql.y"
    {
      (yyval.attr_infos) = nullptr;
    }
#line 2028 "yacc_sql.cpp"
    break;

  case 40: /* attr_def_list: COMMA attr_def attr_def_list  */
#line 383 "yacc_sql.y"
    {
      if ((yyvsp[0].attr_infos) != nullptr) {
        (yyval.attr_infos) = (yyvsp[0].attr_infos);
      } else {
        (yyval.attr_infos) = new std::vector<AttrInfoSqlNode>;
      }
      (yyval.attr_infos)->emplace_back(*(yyvsp[-1].attr_info));
      delete (yyvsp[-1].attr_info);
    }
#line 2042 "yacc_sql.cpp"
    break;

  case 41: /* attr_def: ID type LBRACE number RBRACE attr_can_null  */
#line 396 "yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[-4].number);
      (yyval.attr_info)->name = (yyvsp[-5].string);
      (yyval.attr_info)->length = (yyvsp[-2].number);
      (yyval.attr_info)->can_null = (yyvsp[0].bools);
      free((yyvsp[-5].string));
    }
#line 2055 "yacc_sql.cpp"
    break;

  case 42: /* attr_def: ID type attr_can_null  */
#line 405 "yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[-1].number);
      (yyval.attr_info)->name = (yyvsp[-2].string);
      (yyval.attr_info)->length = 4;
      (yyval.attr_info)->can_null = (yyvsp[0].bools);
      free((yyvsp[-2].string));
    }
#line 2068 "yacc_sql.cpp"
    break;

  case 43: /* attr_can_null: %empty  */
#line 416 "yacc_sql.y"
  {
    (yyval.bools) = true;
  }
#line 2076 "yacc_sql.cpp"
    break;

  case 44: /* attr_can_null: NOT NULL_T  */
#line 419 "yacc_sql.y"
               {
    (yyval.bools) = false;
  }
#line 2084 "yacc_sql.cpp"
    break;

  case 45: /* attr_can_null: NULL_T  */
#line 422 "yacc_sql.y"
           {
    (yyval.bools) = true;
  }
#line 2092 "yacc_sql.cpp"
    break;

  case 46: /* number: NUMBER  */
#line 428 "yacc_sql.y"
           {(yyval.number) = (yyvsp[0].number);}
#line 2098 "yacc_sql.cpp"
    break;

  case 47: /* type: INT_T  */
#line 431 "yacc_sql.y"
               { (yyval.number)=INTS; }
#line 2104 "yacc_sql.cpp"
    break;

  case 48: /* type: STRING_T  */
#line 432 "yacc_sql.y"
               { (yyval.number)=CHARS; }
#line 2110 "yacc_sql.cpp"
    break;

  case 49: /* type: FLOAT_T  */
#line 433 "yacc_sql.y"
               { (yyval.number)=FLOATS; }
#line 2116 "yacc_sql.cpp"
    break;

  case 50: /* type: DATE_T  */
#line 434 "yacc_sql.y"
             { (yyval.number)=DATES; }
#line 2122 "yacc_sql.cpp"
    break;

  case 51: /* insert_stmt: INSERT INTO ID VALUES LBRACE value value_list RBRACE  */
#line 438 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_INSERT);
      (yyval.sql_node)->insertion.relation_name = (yyvsp[-5].string);
      if ((yyvsp[-1].value_list) != nullptr) {
        (yyval.sql_node)->insertion.values.swap(*(yyvsp[-1].value_list));
      }
      (yyval.sql_node)->insertion.values.emplace_back(*(yyvsp[-2].value));
      std::reverse((yyval.sql_node)->insertion.values.begin(), (yyval.sql_node)->insertion.values.end());
      delete (yyvsp[-2].value);
      free((yyvsp[-5].string));
    }
#line 2138 "yacc_sql.cpp"
    break;

  case 52: /* value_list: %empty  */
#line 453 "yacc_sql.y"
    {
      (yyval.value_list) = nullptr;
    }
#line 2146 "yacc_sql.cpp"
    break;

  case 53: /* value_list: COMMA value value_list  */
#line 456 "yacc_sql.y"
                              { 
      if ((yyvsp[0].value_list) != nullptr) {
        (yyval.value_list) = (yyvsp[0].value_list);
      } else {
        (yyval.value_list) = new std::vector<Value>;
      }
      (yyval.value_list)->emplace_back(*(yyvsp[-1].value));
      delete (yyvsp[-1].value);
    }
#line 2160 "yacc_sql.cpp"
    break;

  case 54: /* value: NUMBER  */
#line 467 "yacc_sql.y"
           {
      (yyval.value) = new Value((int)(yyvsp[0].number));
      (yyloc) = (yylsp[0]);
    }
#line 2169 "yacc_sql.cpp"
    break;

  case 55: /* value: FLOAT  */
#line 471 "yacc_sql.y"
           {
      (yyval.value) = new Value((float)(yyvsp[0].floats));
      (yyloc) = (yylsp[0]);
    }
#line 2178 "yacc_sql.cpp"
    break;

  case 56: /* value: DATE_STR  */
#line 475 "yacc_sql.y"
              {
      char *tmp = common::substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
      (yyval.value) = new Value();
      (yyval.value)->set_date(tmp);
      free(tmp);
    }
#line 2189 "yacc_sql.cpp"
    break;

  case 57: /* value: NULL_T  */
#line 481 "yacc_sql.y"
            {
      (yyval.value) = new Value();
      (yyval.value)->set_null(true);
    }
#line 2198 "yacc_sql.cpp"
    break;

  case 58: /* value: SSS  */
#line 485 "yacc_sql.y"
         {
      char *tmp = common::substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
      (yyval.value) = new Value(tmp);
      free(tmp);
    }
#line 2208 "yacc_sql.cpp"
    break;

  case 59: /* join_expr: JOIN  */
#line 494 "yacc_sql.y"
  {
    (yyval.join_type) = JOIN_TABLE;

  }
#line 2217 "yacc_sql.cpp"
    break;

  case 60: /* join_expr: INNER JOIN  */
#line 499 "yacc_sql.y"
  {
    (yyval.join_type) = INNER_JOIN_TABLE;
  }
#line 2225 "yacc_sql.cpp"
    break;

  case 61: /* on_condition_exprs: %empty  */
#line 506 "yacc_sql.y"
  {
    (yyval.condition_list) = nullptr;
  }
#line 2233 "yacc_sql.cpp"
    break;

  case 62: /* on_condition_exprs: condition  */
#line 510 "yacc_sql.y"
  {
    (yyval.condition_list) = new std::vector<ConditionSqlNode>;
    (yyval.condition_list)->emplace_back(*(yyvsp[0].condition));
    delete (yyvsp[0].condition);
  }
#line 2243 "yacc_sql.cpp"
    break;

  case 63: /* on_condition_exprs: condition AND condition_list  */
#line 515 "yacc_sql.y"
                                 {
    (yyval.condition_list) = (yyvsp[0].condition_list);
    (yyval.condition_list)->emplace_back(*(yyvsp[-2].condition));
    delete (yyvsp[-2].condition);
  }
#line 2253 "yacc_sql.cpp"
    break;

  case 64: /* join_table: join_expr ID ON on_condition_exprs  */
#line 524 "yacc_sql.y"
  {
    (yyval.join_table) = new JoinTableSqlNode;
    (yyval.join_table)->table_name = (yyvsp[-2].string);
    free((yyvsp[-2].string));

    if ((yyvsp[0].condition_list) != nullptr) {
      (yyval.join_table)->on_conditions = *(yyvsp[0].condition_list);
    }
    delete (yyvsp[0].condition_list);
  }
#line 2268 "yacc_sql.cpp"
    break;

  case 65: /* join_table: join_expr ID  */
#line 535 "yacc_sql.y"
  {
    (yyval.join_table) = new JoinTableSqlNode;
    (yyval.join_table)->table_name = (yyvsp[0].string);
    free((yyvsp[0].string));
  }
#line 2278 "yacc_sql.cpp"
    break;

  case 66: /* join_tables: %empty  */
#line 543 "yacc_sql.y"
    {
      (yyval.join_table_list) = nullptr;
    }
#line 2286 "yacc_sql.cpp"
    break;

  case 67: /* join_tables: join_table join_tables  */
#line 547 "yacc_sql.y"
    { 
      if ((yyvsp[0].join_table_list) == nullptr) {
        (yyval.join_table_list) = new std::vector<JoinTableSqlNode>;
      } else {
        (yyval.join_table_list) = (yyvsp[0].join_table_list);
      }

      (yyval.join_table_list)->push_back(*(yyvsp[-1].join_table));
      delete (yyvsp[-1].join_table);
    }
#line 2301 "yacc_sql.cpp"
    break;

  case 68: /* delete_stmt: DELETE FROM ID where  */
#line 560 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DELETE);
      (yyval.sql_node)->deletion.relation_name = (yyvsp[-1].string);
      if ((yyvsp[0].condition_list) != nullptr) {
        (yyval.sql_node)->deletion.conditions.swap(*(yyvsp[0].condition_list));
        delete (yyvsp[0].condition_list);
      }
      free((yyvsp[-1].string));
    }
#line 2315 "yacc_sql.cpp"
    break;

  case 69: /* update_expr: ID EQ value  */
#line 572 "yacc_sql.y"
             {
    (yyval.condition) = new ConditionSqlNode();
    (yyval.condition)->left_is_attr = 1;
    (yyval.condition)->left_attr.attribute_name = (yyvsp[-2].string);
    (yyval.condition)->right_is_attr = 0;
    (yyval.condition)->right_is_sub_query = 0;
    (yyval.condition)->right_value = *(yyvsp[0].value);
    (yyval.condition)->comp = EQUAL_TO;
    
    free((yyvsp[-2].string));
    delete (yyvsp[0].value);
  }
#line 2332 "yacc_sql.cpp"
    break;

  case 70: /* update_expr: ID EQ LBRACE select_stmt RBRACE  */
#line 584 "yacc_sql.y"
                                   {
    (yyval.condition) = new ConditionSqlNode();
    (yyval.condition)->left_is_attr = 1;
    (yyval.condition)->left_attr.attribute_name = (yyvsp[-4].string);
    (yyval.condition)->right_is_attr = 0;
    (yyval.condition)->right_is_sub_query = 1;
    (yyval.condition)->right_sub_query = make_shared<SelectSqlNode>((*(yyvsp[-1].sql_node)).selection);
    (yyval.condition)->comp = EQUAL_TO;
  
    free((yyvsp[-4].string));
    delete (yyvsp[-1].sql_node);
  }
#line 2349 "yacc_sql.cpp"
    break;

  case 71: /* update_exprs: %empty  */
#line 598 "yacc_sql.y"
           {
    (yyval.condition_list) = nullptr;
  }
#line 2357 "yacc_sql.cpp"
    break;

  case 72: /* update_exprs: COMMA update_expr update_exprs  */
#line 601 "yacc_sql.y"
                                  {
    if((yyvsp[0].condition_list) == nullptr){
      (yyval.condition_list) = new std::vector<ConditionSqlNode>;
    }
    else {
      (yyval.condition_list) = (yyvsp[0].condition_list);
    }
    (yyval.condition_list)->push_back(*(yyvsp[-1].condition));

    delete (yyvsp[-1].condition);
  }
#line 2373 "yacc_sql.cpp"
    break;

  case 73: /* update_stmt: UPDATE ID SET update_expr update_exprs where  */
#line 615 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_UPDATE);
      (yyval.sql_node)->update.relation_name = (yyvsp[-4].string);
      (yyval.sql_node)->update.update_conditions.push_back(*(yyvsp[-2].condition));
      
      free((yyvsp[-4].string));
      delete (yyvsp[-2].condition);
      if ((yyvsp[0].condition_list) != nullptr) {
        (yyval.sql_node)->update.conditions.swap(*(yyvsp[0].condition_list));
        delete (yyvsp[0].condition_list);
      }
      if ((yyvsp[-1].condition_list) != nullptr){
        for(int i = 0; i < (int)(yyvsp[-1].condition_list)->size(); i++){
          (yyval.sql_node)->update.update_conditions.push_back((yyvsp[-1].condition_list)->at(i));
        }
        delete (yyvsp[-1].condition_list);
      }
    }
#line 2396 "yacc_sql.cpp"
    break;

  case 74: /* order_by_attr: rel_attr  */
#line 637 "yacc_sql.y"
  {
    (yyval.order_by) = new OrderBySqlNode();
    (yyval.order_by)->rel_name = *(yyvsp[0].rel_attr);
    delete (yyvsp[0].rel_attr);
  }
#line 2406 "yacc_sql.cpp"
    break;

  case 75: /* order_by_attr: rel_attr ASC  */
#line 643 "yacc_sql.y"
  {
    (yyval.order_by) = new OrderBySqlNode();
    (yyval.order_by)->rel_name = *(yyvsp[-1].rel_attr);
    delete (yyvsp[-1].rel_attr);
    (yyval.order_by)->order_by = ORDER_ASC;
  }
#line 2417 "yacc_sql.cpp"
    break;

  case 76: /* order_by_attr: rel_attr DESC  */
#line 650 "yacc_sql.y"
  {
    (yyval.order_by) = new OrderBySqlNode();
    (yyval.order_by)->rel_name = *(yyvsp[-1].rel_attr);
    delete (yyvsp[-1].rel_attr);
    (yyval.order_by)->order_by = ORDER_DESC;
  }
#line 2428 "yacc_sql.cpp"
    break;

  case 77: /* order_by_attrs: %empty  */
#line 659 "yacc_sql.y"
  {
    (yyval.order_bys) = nullptr;
  }
#line 2436 "yacc_sql.cpp"
    break;

  case 78: /* order_by_attrs: order_by_attr  */
#line 663 "yacc_sql.y"
  {
    (yyval.order_bys) = new vector<OrderBySqlNode>();
    (yyval.order_bys)->emplace_back(*(yyvsp[0].order_by));
    delete (yyvsp[0].order_by);
  }
#line 2446 "yacc_sql.cpp"
    break;

  case 79: /* order_by_attrs: order_by_attr COMMA order_by_attrs  */
#line 668 "yacc_sql.y"
                                       {
    if ((yyval.order_bys) == nullptr) {
      (yyval.order_bys) = new std::vector<OrderBySqlNode>();
    } else {
      (yyval.order_bys) = (yyvsp[0].order_bys);
    }
    (yyval.order_bys)->emplace_back(*(yyvsp[-2].order_by));
    delete (yyvsp[-2].order_by);
  }
#line 2460 "yacc_sql.cpp"
    break;

  case 80: /* order_by: %empty  */
#line 681 "yacc_sql.y"
  {
    (yyval.order_bys) = nullptr;
  }
#line 2468 "yacc_sql.cpp"
    break;

  case 81: /* order_by: ORDER BY order_by_attrs  */
#line 685 "yacc_sql.y"
  {
    (yyval.order_bys) = (yyvsp[0].order_bys);
  }
#line 2476 "yacc_sql.cpp"
    break;

  case 82: /* select_stmt: SELECT select_attr FROM ID rel_list where order_by  */
#line 692 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SELECT);
      if ((yyvsp[-5].rel_attr_list) != nullptr) {
        (yyval.sql_node)->selection.attributes.swap(*(yyvsp[-5].rel_attr_list));
        delete (yyvsp[-5].rel_attr_list);
      }
      if ((yyvsp[-2].relation_list) != nullptr) {
        /* join with COMMA represents empty on condition */
        for (int i = 0;i < (int)(yyvsp[-2].relation_list)->size(); i++) {
          (yyval.sql_node)->selection.on_conditions.push_back(vector<ConditionSqlNode>());
        }

        (yyval.sql_node)->selection.relations.swap(*(yyvsp[-2].relation_list));
        delete (yyvsp[-2].relation_list);
      }
      (yyval.sql_node)->selection.relations.push_back((yyvsp[-3].string));
      std::reverse((yyval.sql_node)->selection.relations.begin(), (yyval.sql_node)->selection.relations.end());

      if ((yyvsp[-1].condition_list) != nullptr) {
        (yyval.sql_node)->selection.conditions.swap(*(yyvsp[-1].condition_list));
        delete (yyvsp[-1].condition_list);
      }
      free((yyvsp[-3].string));

      if ((yyvsp[0].order_bys) != nullptr) {
        (yyval.sql_node)->selection.order_bys.swap(*(yyvsp[0].order_bys));
        std::reverse((yyval.sql_node)->selection.order_bys.begin(), (yyval.sql_node)->selection.order_bys.end());
        delete (yyvsp[0].order_bys);
      } 
    }
#line 2511 "yacc_sql.cpp"
    break;

  case 83: /* select_stmt: SELECT select_attr FROM ID join_table join_tables where order_by  */
#line 723 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SELECT);
      if ((yyvsp[-6].rel_attr_list) != nullptr) {
        (yyval.sql_node)->selection.attributes.swap(*(yyvsp[-6].rel_attr_list));
        delete (yyvsp[-6].rel_attr_list);
      }
      (yyval.sql_node)->selection.relations.push_back((yyvsp[-4].string));
      
      if ((yyvsp[-2].join_table_list) != nullptr) {
        int i = 0;
        for(i = 0; i < (int)(yyvsp[-2].join_table_list)->size(); i++) {
          (yyval.sql_node)->selection.relations.push_back((*(yyvsp[-2].join_table_list))[i].table_name);
          (yyval.sql_node)->selection.on_conditions.push_back((*(yyvsp[-2].join_table_list))[i].on_conditions);
        }
        delete (yyvsp[-2].join_table_list);
      }
      (yyval.sql_node)->selection.relations.push_back((yyvsp[-3].join_table)->table_name);
      (yyval.sql_node)->selection.on_conditions.push_back((yyvsp[-3].join_table)->on_conditions);
      std::reverse((yyval.sql_node)->selection.relations.begin() + 1, (yyval.sql_node)->selection.relations.end());
      std::reverse((yyval.sql_node)->selection.on_conditions.begin(), (yyval.sql_node)->selection.on_conditions.end());
      delete (yyvsp[-3].join_table);

      if ((yyvsp[-1].condition_list) != nullptr) {
        (yyval.sql_node)->selection.conditions.swap(*(yyvsp[-1].condition_list));
        delete (yyvsp[-1].condition_list);
      }
      free((yyvsp[-4].string));
      if ((yyvsp[0].order_bys) != nullptr) {
        (yyval.sql_node)->selection.order_bys.swap(*(yyvsp[0].order_bys));
        std::reverse((yyval.sql_node)->selection.order_bys.begin(), (yyval.sql_node)->selection.order_bys.end());
        delete (yyvsp[0].order_bys);
      }    
    }
#line 2549 "yacc_sql.cpp"
    break;

  case 84: /* calc_stmt: CALC expression_list  */
#line 759 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CALC);
      std::reverse((yyvsp[0].expression_list)->begin(), (yyvsp[0].expression_list)->end());
      (yyval.sql_node)->calc.expressions.swap(*(yyvsp[0].expression_list));
      delete (yyvsp[0].expression_list);
    }
#line 2560 "yacc_sql.cpp"
    break;

  case 85: /* expression_list: expression  */
#line 769 "yacc_sql.y"
    {
      (yyval.expression_list) = new std::vector<Expression*>;
      (yyval.expression_list)->emplace_back((yyvsp[0].expression));
    }
#line 2569 "yacc_sql.cpp"
    break;

  case 86: /* expression_list: expression COMMA expression_list  */
#line 774 "yacc_sql.y"
    {
      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.expression_list) = (yyvsp[0].expression_list);
      } else {
        (yyval.expression_list) = new std::vector<Expression *>;
      }
      (yyval.expression_list)->emplace_back((yyvsp[-2].expression));
    }
#line 2582 "yacc_sql.cpp"
    break;

  case 87: /* expression: expression '+' expression  */
#line 784 "yacc_sql.y"
                              {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::ADD, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2590 "yacc_sql.cpp"
    break;

  case 88: /* expression: expression '-' expression  */
#line 787 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2598 "yacc_sql.cpp"
    break;

  case 89: /* expression: expression '*' expression  */
#line 790 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::MUL, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2606 "yacc_sql.cpp"
    break;

  case 90: /* expression: expression '/' expression  */
#line 793 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::DIV, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2614 "yacc_sql.cpp"
    break;

  case 91: /* expression: LBRACE expression RBRACE  */
#line 796 "yacc_sql.y"
                               {
      (yyval.expression) = (yyvsp[-1].expression);
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
    }
#line 2623 "yacc_sql.cpp"
    break;

  case 92: /* expression: '-' expression  */
#line 800 "yacc_sql.y"
                                  {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::NEGATIVE, (yyvsp[0].expression), nullptr, sql_string, &(yyloc));
    }
#line 2631 "yacc_sql.cpp"
    break;

  case 93: /* expression: value  */
#line 803 "yacc_sql.y"
            {
      (yyval.expression) = new ValueExpr(*(yyvsp[0].value));
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      delete (yyvsp[0].value);
    }
#line 2641 "yacc_sql.cpp"
    break;

  case 94: /* select_attr: '*'  */
#line 811 "yacc_sql.y"
        {
      (yyval.rel_attr_list) = new std::vector<RelAttrSqlNode>;
      RelAttrSqlNode attr;
      attr.relation_name  = "";
      attr.attribute_name = "*";
      (yyval.rel_attr_list)->emplace_back(attr);
    }
#line 2653 "yacc_sql.cpp"
    break;

  case 95: /* select_attr: rel_attr attr_list  */
#line 818 "yacc_sql.y"
                         {
      if ((yyvsp[0].rel_attr_list) != nullptr) {
        (yyval.rel_attr_list) = (yyvsp[0].rel_attr_list);
      } else {
        (yyval.rel_attr_list) = new std::vector<RelAttrSqlNode>;
      }
      (yyval.rel_attr_list)->emplace_back(*(yyvsp[-1].rel_attr));
      delete (yyvsp[-1].rel_attr);
    }
#line 2667 "yacc_sql.cpp"
    break;

  case 96: /* select_attr: aggr_func aggr_func_list  */
#line 827 "yacc_sql.y"
                              {
      if ((yyvsp[0].rel_attr_list) != nullptr){
        (yyval.rel_attr_list) = (yyvsp[0].rel_attr_list);
      } else {
        (yyval.rel_attr_list) = new std::vector<RelAttrSqlNode>;
      }
      (yyval.rel_attr_list)->emplace_back(*(yyvsp[-1].rel_attr));
      delete (yyvsp[-1].rel_attr);
    }
#line 2681 "yacc_sql.cpp"
    break;

  case 97: /* aggr_op: MAX  */
#line 839 "yacc_sql.y"
      {
    (yyval.aggr_op) = AGG_MAX;
  }
#line 2689 "yacc_sql.cpp"
    break;

  case 98: /* aggr_op: AVG  */
#line 842 "yacc_sql.y"
        {
    (yyval.aggr_op) = AGG_AVG;
  }
#line 2697 "yacc_sql.cpp"
    break;

  case 99: /* aggr_op: SUM  */
#line 845 "yacc_sql.y"
        {
    (yyval.aggr_op) = AGG_SUM;
  }
#line 2705 "yacc_sql.cpp"
    break;

  case 100: /* aggr_op: MIN  */
#line 848 "yacc_sql.y"
        {
    (yyval.aggr_op) = AGG_MIN;
  }
#line 2713 "yacc_sql.cpp"
    break;

  case 101: /* aggr_op: COUNT  */
#line 851 "yacc_sql.y"
          {
    (yyval.aggr_op) = AGG_COUNT;
  }
#line 2721 "yacc_sql.cpp"
    break;

  case 102: /* aggr_func: aggr_op LBRACE '*' RBRACE  */
#line 857 "yacc_sql.y"
                            {
    (yyval.rel_attr) = new RelAttrSqlNode;
    (yyval.rel_attr)->relation_name = "";
    (yyval.rel_attr)->attribute_name = '*';
    (yyval.rel_attr)->aggr_op = (yyvsp[-3].aggr_op);
  }
#line 2732 "yacc_sql.cpp"
    break;

  case 103: /* aggr_func: aggr_op LBRACE ID RBRACE  */
#line 863 "yacc_sql.y"
                             {
    (yyval.rel_attr) = new RelAttrSqlNode;
    (yyval.rel_attr)->attribute_name = (yyvsp[-1].string);
    (yyval.rel_attr)->aggr_op = (yyvsp[-3].aggr_op);
    free((yyvsp[-1].string));    
  }
#line 2743 "yacc_sql.cpp"
    break;

  case 104: /* aggr_func: aggr_op LBRACE ID DOT ID RBRACE  */
#line 869 "yacc_sql.y"
                                    {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->relation_name  = (yyvsp[-3].string);
      (yyval.rel_attr)->attribute_name = (yyvsp[-1].string);
      (yyval.rel_attr)->aggr_op = (yyvsp[-5].aggr_op);
      free((yyvsp[-3].string));
      free((yyvsp[-1].string));
  }
#line 2756 "yacc_sql.cpp"
    break;

  case 105: /* aggr_func_list: %empty  */
#line 881 "yacc_sql.y"
    {
      (yyval.rel_attr_list) = nullptr;
    }
#line 2764 "yacc_sql.cpp"
    break;

  case 106: /* aggr_func_list: COMMA aggr_func aggr_func_list  */
#line 884 "yacc_sql.y"
                                     {
      if ((yyvsp[0].rel_attr_list) != nullptr) {
        (yyval.rel_attr_list) = (yyvsp[0].rel_attr_list);
      } else {
        (yyval.rel_attr_list) = new std::vector<RelAttrSqlNode>;
      }
      (yyval.rel_attr_list)->emplace_back(*(yyvsp[-1].rel_attr));
      delete (yyvsp[-1].rel_attr);
    }
#line 2778 "yacc_sql.cpp"
    break;

  case 107: /* rel_attr: ID  */
#line 896 "yacc_sql.y"
       {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->attribute_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 2788 "yacc_sql.cpp"
    break;

  case 108: /* rel_attr: ID DOT ID  */
#line 901 "yacc_sql.y"
                {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->relation_name  = (yyvsp[-2].string);
      (yyval.rel_attr)->attribute_name = (yyvsp[0].string);
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 2800 "yacc_sql.cpp"
    break;

  case 109: /* attr_list: %empty  */
#line 911 "yacc_sql.y"
    {
      (yyval.rel_attr_list) = nullptr;
    }
#line 2808 "yacc_sql.cpp"
    break;

  case 110: /* attr_list: COMMA rel_attr attr_list  */
#line 914 "yacc_sql.y"
                               {
      if ((yyvsp[0].rel_attr_list) != nullptr) {
        (yyval.rel_attr_list) = (yyvsp[0].rel_attr_list);
      } else {
        (yyval.rel_attr_list) = new std::vector<RelAttrSqlNode>;
      }

      (yyval.rel_attr_list)->emplace_back(*(yyvsp[-1].rel_attr));
      delete (yyvsp[-1].rel_attr);
    }
#line 2823 "yacc_sql.cpp"
    break;

  case 111: /* rel_list: %empty  */
#line 928 "yacc_sql.y"
    {
      (yyval.relation_list) = nullptr;
    }
#line 2831 "yacc_sql.cpp"
    break;

  case 112: /* rel_list: COMMA ID rel_list  */
#line 931 "yacc_sql.y"
                        {
      if ((yyvsp[0].relation_list) != nullptr) {
        (yyval.relation_list) = (yyvsp[0].relation_list);
      } else {
        (yyval.relation_list) = new std::vector<std::string>;
      }

      (yyval.relation_list)->push_back((yyvsp[-1].string));
      free((yyvsp[-1].string));
    }
#line 2846 "yacc_sql.cpp"
    break;

  case 113: /* where: %empty  */
#line 944 "yacc_sql.y"
    {
      (yyval.condition_list) = nullptr;
    }
#line 2854 "yacc_sql.cpp"
    break;

  case 114: /* where: WHERE condition_list  */
#line 947 "yacc_sql.y"
                           {
      (yyval.condition_list) = (yyvsp[0].condition_list);  
    }
#line 2862 "yacc_sql.cpp"
    break;

  case 115: /* condition_list: %empty  */
#line 953 "yacc_sql.y"
    {
      (yyval.condition_list) = nullptr;
    }
#line 2870 "yacc_sql.cpp"
    break;

  case 116: /* condition_list: condition  */
#line 956 "yacc_sql.y"
                {
      (yyval.condition_list) = new std::vector<ConditionSqlNode>;
      (yyval.condition_list)->emplace_back(*(yyvsp[0].condition));
      delete (yyvsp[0].condition);
    }
#line 2880 "yacc_sql.cpp"
    break;

  case 117: /* condition_list: condition AND condition_list  */
#line 961 "yacc_sql.y"
                                   {
      (yyval.condition_list) = (yyvsp[0].condition_list);
      (yyval.condition_list)->emplace_back(*(yyvsp[-2].condition));
      delete (yyvsp[-2].condition);
    }
#line 2890 "yacc_sql.cpp"
    break;

  case 118: /* condition_list: condition OR condition_list  */
#line 966 "yacc_sql.y"
                                 {
      (yyval.condition_list) = (yyvsp[0].condition_list);
      (yyval.condition_list)->emplace_back(*(yyvsp[-2].condition));
      delete (yyvsp[-2].condition);
      (yyval.condition_list)->front().is_or = true;
    }
#line 2901 "yacc_sql.cpp"
    break;

  case 119: /* condition: rel_attr comp_op value  */
#line 975 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_attr = 1;
      (yyval.condition)->left_attr = *(yyvsp[-2].rel_attr);
      (yyval.condition)->right_is_attr = 0;
      (yyval.condition)->right_value = *(yyvsp[0].value);
      (yyval.condition)->comp = (yyvsp[-1].comp);

      delete (yyvsp[-2].rel_attr);
      delete (yyvsp[0].value);
    }
#line 2917 "yacc_sql.cpp"
    break;

  case 120: /* condition: value comp_op value  */
#line 987 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_attr = 0;
      (yyval.condition)->left_value = *(yyvsp[-2].value);
      (yyval.condition)->right_is_attr = 0;
      (yyval.condition)->right_value = *(yyvsp[0].value);
      (yyval.condition)->comp = (yyvsp[-1].comp);

      delete (yyvsp[-2].value);
      delete (yyvsp[0].value);
    }
#line 2933 "yacc_sql.cpp"
    break;

  case 121: /* condition: rel_attr comp_op rel_attr  */
#line 999 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_attr = 1;
      (yyval.condition)->left_attr = *(yyvsp[-2].rel_attr);
      (yyval.condition)->right_is_attr = 1;
      (yyval.condition)->right_attr = *(yyvsp[0].rel_attr);
      (yyval.condition)->comp = (yyvsp[-1].comp);

      delete (yyvsp[-2].rel_attr);
      delete (yyvsp[0].rel_attr);
    }
#line 2949 "yacc_sql.cpp"
    break;

  case 122: /* condition: value comp_op rel_attr  */
#line 1011 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_attr = 0;
      (yyval.condition)->left_value = *(yyvsp[-2].value);
      (yyval.condition)->right_is_attr = 1;
      (yyval.condition)->right_attr = *(yyvsp[0].rel_attr);
      (yyval.condition)->comp = (yyvsp[-1].comp);

      delete (yyvsp[-2].value);
      delete (yyvsp[0].rel_attr);
    }
#line 2965 "yacc_sql.cpp"
    break;

  case 123: /* condition: EXISTS LBRACE select_stmt RBRACE  */
#line 1023 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_attr = 0;
      (yyval.condition)->left_value;
      (yyval.condition)->right_is_attr = 0;
      (yyval.condition)->right_is_sub_query = 1;
      (yyval.condition)->right_sub_query = std::make_shared<SelectSqlNode>((yyvsp[-1].sql_node)->selection);
      (yyval.condition)->comp = EXISTS_OP;

      delete (yyvsp[-1].sql_node);
    }
#line 2981 "yacc_sql.cpp"
    break;

  case 124: /* condition: NOT EXISTS LBRACE select_stmt RBRACE  */
#line 1035 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_attr = 0;
      (yyval.condition)->left_value;
      (yyval.condition)->right_is_attr = 0;
      (yyval.condition)->right_is_sub_query = 1;
      (yyval.condition)->right_sub_query = std::make_shared<SelectSqlNode>((yyvsp[-1].sql_node)->selection);
      (yyval.condition)->comp = NOT_EXISTS_OP;

      delete (yyvsp[-1].sql_node);
    }
#line 2997 "yacc_sql.cpp"
    break;

  case 125: /* condition: rel_attr IN LBRACE select_stmt RBRACE  */
#line 1047 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_attr = 1;
      (yyval.condition)->left_attr = *(yyvsp[-4].rel_attr);
      (yyval.condition)->left_value;
      (yyval.condition)->right_is_attr = 0;
      (yyval.condition)->right_is_sub_query = 1;
      (yyval.condition)->right_sub_query = std::make_shared<SelectSqlNode>((yyvsp[-1].sql_node)->selection);
      (yyval.condition)->comp = IN_OP;

      delete (yyvsp[-4].rel_attr);
      delete (yyvsp[-1].sql_node);
    }
#line 3015 "yacc_sql.cpp"
    break;

  case 126: /* condition: rel_attr NOT IN LBRACE select_stmt RBRACE  */
#line 1061 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_attr = 1;
      (yyval.condition)->left_attr = *(yyvsp[-5].rel_attr);
      (yyval.condition)->left_value;
      (yyval.condition)->right_is_attr = 0;
      (yyval.condition)->right_is_sub_query = 1;
      (yyval.condition)->right_sub_query = std::make_shared<SelectSqlNode>((yyvsp[-1].sql_node)->selection);
      (yyval.condition)->comp = NOT_IN_OP;

      delete (yyvsp[-5].rel_attr);
      delete (yyvsp[-1].sql_node);
    }
#line 3033 "yacc_sql.cpp"
    break;

  case 127: /* condition: rel_attr comp_op LBRACE select_stmt RBRACE  */
#line 1075 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_attr = 1;
      (yyval.condition)->left_attr = *(yyvsp[-4].rel_attr);
      (yyval.condition)->left_value;
      (yyval.condition)->right_is_attr = 0;
      (yyval.condition)->right_is_sub_query = 1;
      (yyval.condition)->right_sub_query = std::make_shared<SelectSqlNode>((yyvsp[-1].sql_node)->selection);
      (yyval.condition)->comp = (yyvsp[-3].comp);

      delete (yyvsp[-4].rel_attr);
      delete (yyvsp[-1].sql_node);
    }
#line 3051 "yacc_sql.cpp"
    break;

  case 128: /* condition: value comp_op LBRACE select_stmt RBRACE  */
#line 1089 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_attr = 0;
      (yyval.condition)->left_attr;
      (yyval.condition)->left_value = *(yyvsp[-4].value);
      (yyval.condition)->right_is_attr = 0;
      (yyval.condition)->right_is_sub_query = 1;
      (yyval.condition)->right_sub_query = std::make_shared<SelectSqlNode>((yyvsp[-1].sql_node)->selection);
      (yyval.condition)->comp = (yyvsp[-3].comp);

      delete (yyvsp[-4].value);
      delete (yyvsp[-1].sql_node);
    }
#line 3069 "yacc_sql.cpp"
    break;

  case 129: /* condition: LBRACE select_stmt RBRACE comp_op_reverse value  */
#line 1103 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_attr = 0;
      (yyval.condition)->left_attr;
      (yyval.condition)->left_value = *(yyvsp[0].value);
      (yyval.condition)->right_is_attr = 0;
      (yyval.condition)->right_is_sub_query = 1;
      (yyval.condition)->right_sub_query = std::make_shared<SelectSqlNode>((yyvsp[-3].sql_node)->selection);
      (yyval.condition)->comp = (yyvsp[-1].comp);

      delete (yyvsp[-3].sql_node);
      delete (yyvsp[0].value);
    }
#line 3087 "yacc_sql.cpp"
    break;

  case 130: /* condition: LBRACE select_stmt RBRACE comp_op_reverse rel_attr  */
#line 1117 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_attr = 1;
      (yyval.condition)->left_attr = *(yyvsp[0].rel_attr);
      (yyval.condition)->left_value;
      (yyval.condition)->right_is_attr = 0;
      (yyval.condition)->right_is_sub_query = 1;
      (yyval.condition)->right_sub_query = std::make_shared<SelectSqlNode>((yyvsp[-3].sql_node)->selection);
      (yyval.condition)->comp = (yyvsp[-1].comp);

      delete (yyvsp[-3].sql_node);
      delete (yyvsp[0].rel_attr);
    }
#line 3105 "yacc_sql.cpp"
    break;

  case 131: /* condition: rel_attr IN LBRACE value value_list RBRACE  */
#line 1130 "yacc_sql.y"
                                                {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_attr = 1;
      (yyval.condition)->left_attr = *(yyvsp[-5].rel_attr);
      (yyval.condition)->left_value;
      (yyval.condition)->right_is_attr = 0;
      (yyval.condition)->right_is_sub_query = 1;
      if ((yyvsp[-1].value_list) != nullptr) {
        (yyval.condition)->right_values.swap(*(yyvsp[-1].value_list));
      }
      (yyval.condition)->right_values.emplace_back(*(yyvsp[-2].value));
      (yyval.condition)->right_sub_query;
      (yyval.condition)->comp = IN_OP;

      delete (yyvsp[-5].rel_attr);
      delete (yyvsp[-2].value);
    }
#line 3127 "yacc_sql.cpp"
    break;

  case 132: /* condition: rel_attr NOT IN LBRACE value value_list RBRACE  */
#line 1147 "yacc_sql.y"
                                                    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_attr = 1;
      (yyval.condition)->left_attr = *(yyvsp[-6].rel_attr);
      (yyval.condition)->left_value;
      (yyval.condition)->right_is_attr = 0;
      (yyval.condition)->right_is_sub_query = 1;
      if ((yyvsp[-1].value_list) != nullptr) {
        (yyval.condition)->right_values.swap(*(yyvsp[-1].value_list));
      }
      (yyval.condition)->right_values.emplace_back(*(yyvsp[-2].value));
      (yyval.condition)->right_sub_query;
      (yyval.condition)->comp = NOT_IN_OP;

      delete (yyvsp[-6].rel_attr);
      delete (yyvsp[-2].value);
    }
#line 3149 "yacc_sql.cpp"
    break;

  case 133: /* condition: value IN LBRACE value value_list RBRACE  */
#line 1164 "yacc_sql.y"
                                             {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_attr = 0;
      (yyval.condition)->left_attr;
      (yyval.condition)->left_value = *(yyvsp[-5].value);
      (yyval.condition)->right_is_attr = 0;
      (yyval.condition)->right_is_sub_query = 1;
      (yyval.condition)->right_sub_query;
      if ((yyvsp[-1].value_list) != nullptr) {
        (yyval.condition)->right_values.swap(*(yyvsp[-1].value_list));
      }
      (yyval.condition)->right_values.emplace_back(*(yyvsp[-2].value));
      (yyval.condition)->comp = IN_OP;

      delete (yyvsp[-5].value);
      delete (yyvsp[-2].value);
    }
#line 3171 "yacc_sql.cpp"
    break;

  case 134: /* condition: value NOT IN LBRACE value value_list RBRACE  */
#line 1182 "yacc_sql.y"
    {
      (yyval.condition) = new ConditionSqlNode;
      (yyval.condition)->left_is_attr = 0;
      (yyval.condition)->left_attr;
      (yyval.condition)->left_value = *(yyvsp[-6].value);
      (yyval.condition)->right_is_attr = 0;
      (yyval.condition)->right_is_sub_query = 1;
      (yyval.condition)->right_sub_query;
      if ((yyvsp[-1].value_list) != nullptr) {
        (yyval.condition)->right_values.swap(*(yyvsp[-1].value_list));
      }
      (yyval.condition)->right_values.emplace_back(*(yyvsp[-2].value));
      (yyval.condition)->comp = NOT_IN_OP;

      delete (yyvsp[-6].value);
      delete (yyvsp[-2].value);
    }
#line 3193 "yacc_sql.cpp"
    break;

  case 135: /* comp_op: EQ  */
#line 1202 "yacc_sql.y"
         { (yyval.comp) = EQUAL_TO; }
#line 3199 "yacc_sql.cpp"
    break;

  case 136: /* comp_op: LT  */
#line 1203 "yacc_sql.y"
         { (yyval.comp) = LESS_THAN; }
#line 3205 "yacc_sql.cpp"
    break;

  case 137: /* comp_op: GT  */
#line 1204 "yacc_sql.y"
         { (yyval.comp) = GREAT_THAN; }
#line 3211 "yacc_sql.cpp"
    break;

  case 138: /* comp_op: LE  */
#line 1205 "yacc_sql.y"
         { (yyval.comp) = LESS_EQUAL; }
#line 3217 "yacc_sql.cpp"
    break;

  case 139: /* comp_op: GE  */
#line 1206 "yacc_sql.y"
         { (yyval.comp) = GREAT_EQUAL; }
#line 3223 "yacc_sql.cpp"
    break;

  case 140: /* comp_op: NE  */
#line 1207 "yacc_sql.y"
         { (yyval.comp) = NOT_EQUAL; }
#line 3229 "yacc_sql.cpp"
    break;

  case 141: /* comp_op: NOT LIKE  */
#line 1208 "yacc_sql.y"
               { (yyval.comp) = NOT_LIKE_OP; }
#line 3235 "yacc_sql.cpp"
    break;

  case 142: /* comp_op: LIKE  */
#line 1209 "yacc_sql.y"
           { (yyval.comp) = LIKE_OP; }
#line 3241 "yacc_sql.cpp"
    break;

  case 143: /* comp_op: IS  */
#line 1210 "yacc_sql.y"
         { (yyval.comp) = IS_OP; }
#line 3247 "yacc_sql.cpp"
    break;

  case 144: /* comp_op: IS NOT  */
#line 1211 "yacc_sql.y"
             { (yyval.comp) = IS_NOT_OP; }
#line 3253 "yacc_sql.cpp"
    break;

  case 145: /* comp_op_reverse: EQ  */
#line 1215 "yacc_sql.y"
       { (yyval.comp) = EQUAL_TO; }
#line 3259 "yacc_sql.cpp"
    break;

  case 146: /* comp_op_reverse: LT  */
#line 1216 "yacc_sql.y"
         { (yyval.comp) = GREAT_THAN; }
#line 3265 "yacc_sql.cpp"
    break;

  case 147: /* comp_op_reverse: GT  */
#line 1217 "yacc_sql.y"
         { (yyval.comp) = LESS_THAN; }
#line 3271 "yacc_sql.cpp"
    break;

  case 148: /* comp_op_reverse: LE  */
#line 1218 "yacc_sql.y"
         { (yyval.comp) = GREAT_EQUAL; }
#line 3277 "yacc_sql.cpp"
    break;

  case 149: /* comp_op_reverse: GE  */
#line 1219 "yacc_sql.y"
         { (yyval.comp) = LESS_EQUAL; }
#line 3283 "yacc_sql.cpp"
    break;

  case 150: /* comp_op_reverse: NE  */
#line 1220 "yacc_sql.y"
         { (yyval.comp) = NOT_EQUAL; }
#line 3289 "yacc_sql.cpp"
    break;

  case 151: /* load_data_stmt: LOAD DATA INFILE SSS INTO TABLE ID  */
#line 1224 "yacc_sql.y"
    {
      char *tmp_file_name = common::substr((yyvsp[-3].string), 1, strlen((yyvsp[-3].string)) - 2);
      
      (yyval.sql_node) = new ParsedSqlNode(SCF_LOAD_DATA);
      (yyval.sql_node)->load_data.relation_name = (yyvsp[0].string);
      (yyval.sql_node)->load_data.file_name = tmp_file_name;
      free((yyvsp[0].string));
      free(tmp_file_name);
    }
#line 3303 "yacc_sql.cpp"
    break;

  case 152: /* explain_stmt: EXPLAIN command_wrapper  */
#line 1237 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_EXPLAIN);
      (yyval.sql_node)->explain.sql_node = std::unique_ptr<ParsedSqlNode>((yyvsp[0].sql_node));
    }
#line 3312 "yacc_sql.cpp"
    break;

  case 153: /* set_variable_stmt: SET ID EQ value  */
#line 1245 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SET_VARIABLE);
      (yyval.sql_node)->set_variable.name  = (yyvsp[-2].string);
      (yyval.sql_node)->set_variable.value = *(yyvsp[0].value);
      free((yyvsp[-2].string));
      delete (yyvsp[0].value);
    }
#line 3324 "yacc_sql.cpp"
    break;


#line 3328 "yacc_sql.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken, &yylloc};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (&yylloc, sql_string, sql_result, scanner, yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  yyerror_range[1] = yylloc;
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc, sql_string, sql_result, scanner);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp, sql_string, sql_result, scanner);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, sql_string, sql_result, scanner, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc, sql_string, sql_result, scanner);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp, sql_string, sql_result, scanner);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 1257 "yacc_sql.y"

//_____________________________________________________________________
extern void scan_string(const char *str, yyscan_t scanner);

int sql_parse(const char *s, ParsedSqlResult *sql_result) {
  yyscan_t scanner;
  yylex_init(&scanner);
  scan_string(s, scanner);
  int result = yyparse(s, sql_result, scanner);
  yylex_destroy(scanner);
  return result;
}
