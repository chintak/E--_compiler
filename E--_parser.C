/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "E--_parser.y++" /* yacc.c:339  */


#include "Ast.h"
#include "ParserUtil.h"
#include "Error.h"

using namespace std;

extern int verbosity;
extern int yylex();
extern void yyerror(const char *s);
int offSet;
extern const OpNode::OpInfo opInfo[];


#line 82 "E--_parser.C" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "E--_parser.H".  */
#ifndef YY_YY_E_PARSER_H_INCLUDED
# define YY_YY_E_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TOK_LEX_ERROR = 258,
    TOK_PAT_STAR = 259,
    TOK_PAT_OR = 260,
    TOK_PAT_NOT = 261,
    TOK_PLUS = 262,
    TOK_MINUS = 263,
    TOK_UMINUS = 264,
    TOK_MULT = 265,
    TOK_DIV = 266,
    TOK_MOD = 267,
    TOK_BITAND = 268,
    TOK_BITOR = 269,
    TOK_BITNOT = 270,
    TOK_BITXOR = 271,
    TOK_SHL = 272,
    TOK_SHR = 273,
    TOK_GT = 274,
    TOK_LT = 275,
    TOK_GE = 276,
    TOK_LE = 277,
    TOK_EQ = 278,
    TOK_NE = 279,
    TOK_AND = 280,
    TOK_OR = 281,
    TOK_NOT = 282,
    TOK_COMMA = 283,
    TOK_ASSIGN = 284,
    TOK_SEMICOLON = 285,
    TOK_COLON = 286,
    TOK_ARROW = 287,
    TOK_LBRACE = 288,
    TOK_RBRACE = 289,
    TOK_LPAREN = 290,
    TOK_RPAREN = 291,
    TOK_LBRACK = 292,
    TOK_RBRACK = 293,
    TOK_QMARK = 294,
    TOK_IF = 295,
    TOK_ELSE = 296,
    TOK_CLASS = 297,
    TOK_RETURN = 298,
    TOK_EVENT = 299,
    TOK_ANY = 300,
    TOK_PRINT = 301,
    TOK_WHILE = 302,
    TOK_BREAK = 303,
    TOK_CONTINUE = 304,
    TOK_UINTNUM = 305,
    TOK_DOUBLENUM = 306,
    TOK_VOID = 307,
    TOK_STRING = 308,
    TOK_STRCONST = 309,
    TOK_BIT = 310,
    TOK_ENUM = 311,
    TOK_LONG = 312,
    TOK_INT = 313,
    TOK_UNSIGNED = 314,
    TOK_BOOL = 315,
    TOK_BYTE = 316,
    TOK_DOUBLE = 317,
    TOK_SHORT = 318,
    TOK_TRUE = 319,
    TOK_FALSE = 320,
    TOK_IDENT = 321,
    TOK_DOUBLE_COLON = 322,
    TOK_DOT = 323
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 17 "E--_parser.y++" /* yacc.c:355  */

  unsigned int 		 uVal;
  double             dVal;
  char*              cVal;
  vector<string>*    strVector;
  Value*             valVal;

  ExprNode*          exprVal;
  vector<ExprNode*>* exprList;
  RefExprNode*       refexpVal;

  ClassEntry*        classEntry;
  Type*              typeVal;
  vector<Type*>*     typeList; 

  EventEntry*        eventEntry;                        
  VariableEntry*     variableEntry;
  FunctionEntry*     functionEntry;

  BasePatNode*       patVal;
  PrimitivePatNode*  primPatVal;
  StmtNode*          stmtVal;
  list<StmtNode*>*   stmtList;
  IfNode*            ifVal;
  CompoundStmtNode*  compoundStmtVal;
  RuleNode*          ruleNode;

  vector<RuleNode*>* transList;
  
  vector<Type*>*     formalTypeVal;
  const OpNode::OpInfo*    funIval;

  vector<VariableEntry*>* paramList;

#line 226 "E--_parser.C" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_E_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 243 "E--_parser.C" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   371

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  118
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  193

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   323

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      65,    66,    67,    68
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   132,   132,   135,   137,   138,   143,   144,   145,   146,
     147,   150,   162,   192,   205,   208,   213,   214,   218,   227,
     236,   245,   256,   276,   288,   291,   296,   301,   307,   319,
     322,   336,   339,   342,   345,   348,   351,   354,   357,   361,
     365,   369,   375,   380,   390,   400,   410,   422,   433,   441,
     444,   447,   450,   453,   457,   460,   463,   466,   469,   472,
     475,   478,   481,   484,   487,   490,   493,   496,   499,   502,
     505,   508,   511,   514,   517,   520,   523,   526,   529,   532,
     537,   540,   544,   549,   583,   586,   591,   595,   600,   631,
     634,   637,   642,   645,   648,   653,   658,   662,   667,   670,
     673,   674,   677,   690,   691,   694,   697,   706,   712,   724,
     736,   744,   747,   754,   768,   784,   803,   806,   820
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_LEX_ERROR", "TOK_PAT_STAR",
  "TOK_PAT_OR", "TOK_PAT_NOT", "TOK_PLUS", "TOK_MINUS", "TOK_UMINUS",
  "TOK_MULT", "TOK_DIV", "TOK_MOD", "TOK_BITAND", "TOK_BITOR",
  "TOK_BITNOT", "TOK_BITXOR", "TOK_SHL", "TOK_SHR", "TOK_GT", "TOK_LT",
  "TOK_GE", "TOK_LE", "TOK_EQ", "TOK_NE", "TOK_AND", "TOK_OR", "TOK_NOT",
  "TOK_COMMA", "TOK_ASSIGN", "TOK_SEMICOLON", "TOK_COLON", "TOK_ARROW",
  "TOK_LBRACE", "TOK_RBRACE", "TOK_LPAREN", "TOK_RPAREN", "TOK_LBRACK",
  "TOK_RBRACK", "TOK_QMARK", "TOK_IF", "TOK_ELSE", "TOK_CLASS",
  "TOK_RETURN", "TOK_EVENT", "TOK_ANY", "TOK_PRINT", "TOK_WHILE",
  "TOK_BREAK", "TOK_CONTINUE", "TOK_UINTNUM", "TOK_DOUBLENUM", "TOK_VOID",
  "TOK_STRING", "TOK_STRCONST", "TOK_BIT", "TOK_ENUM", "TOK_LONG",
  "TOK_INT", "TOK_UNSIGNED", "TOK_BOOL", "TOK_BYTE", "TOK_DOUBLE",
  "TOK_SHORT", "TOK_TRUE", "TOK_FALSE", "TOK_IDENT", "TOK_DOUBLE_COLON",
  "TOK_DOT", "$accept", "specification", "ifc_decl_star", "ifc_decl",
  "class_decl", "function_decl", "function_header", "fun_rest",
  "variable_decls", "variable_decl2", "event_decl", "event_decl_hdr",
  "formal_param_list", "formal_param_plus", "formal_param", "type",
  "baseType", "variable_decl", "variable_decl1", "ref_expr", "assignment",
  "literal", "expr", "if_then_else_stmt", "asg_stmt",
  "function_invocation", "expr_list", "expr_plus", "simple_stmt", "stmt",
  "compoundStmt", "stmt_plus", "rule_star", "rule_list", "rule",
  "rule_end", "event_pattern", "primitive_pat", "event", "event_name",
  "event_formal_params", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323
};
# endif

#define YYPACT_NINF -55

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-55)))

#define YYTABLE_NINF -116

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-116)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -55,    28,   110,   -55,   -20,   -19,   -55,   -19,   -37,   -32,
     -55,   -55,   -55,   -55,   -38,   -55,   -55,   -55,    13,   -55,
     -55,   -55,   -55,    30,     0,   -55,   -55,   -17,   -55,   -19,
     -55,   200,   -55,    56,    60,   -55,   -55,   -55,   113,    67,
     -55,   -55,   -55,   -55,   -55,   -55,    98,     3,    63,    35,
     -55,   -55,   -55,   -19,   -19,    72,    10,    37,   -55,   -55,
     -55,    68,    79,   -55,    42,    10,    98,    84,     2,   112,
     -55,    72,    10,    10,    86,    85,    89,   -55,   -55,   100,
     -55,   106,   -55,    10,    10,    10,    10,   -55,   -55,   -55,
     -55,   -55,    85,   -55,   -55,   272,   -55,   -55,    -1,   109,
      98,   -55,   272,    92,    10,   -55,     6,   170,   251,    10,
      10,   -55,   -55,   -55,   -55,   -55,   207,   311,   230,    10,
      10,    10,    10,    10,    10,    10,    10,    10,    10,    10,
      10,    10,    10,    10,    10,    10,    10,    80,   -55,   -55,
     -55,   -21,   272,   -55,   -55,   120,   -55,   272,   117,   137,
     272,   -55,   131,   131,   -55,   -55,   -55,   207,   347,   347,
     359,   359,   329,   329,   329,   329,   329,   329,   311,   292,
     -55,   -55,   -55,   -55,    72,   -55,    10,   168,   -55,   272,
      34,    43,   101,    66,   107,   -55,   145,   -55,   150,    10,
      10,   272,   272
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     1,     0,     0,     6,     0,     0,     0,
     113,    31,    33,    36,     0,    32,    34,    37,    30,     4,
       7,     8,     9,     0,     0,    29,    10,     0,     2,    99,
     100,     0,   105,   111,     0,     5,   115,   106,     0,     0,
      23,    38,    40,    35,    39,    41,    24,    43,     0,     0,
      42,   101,   110,     0,     0,     0,     0,   116,   107,    11,
      30,     0,    25,    26,     0,     0,    24,    45,   109,   108,
      89,     0,     0,     0,    47,     0,     0,    94,    90,     0,
      92,   103,    93,     0,     0,     0,     0,    50,    51,    49,
      52,    53,    55,    56,    54,   112,    57,   117,     0,     0,
       0,    28,    44,     0,     0,    96,     0,     0,     0,    84,
       0,    82,    91,   104,   102,    59,    58,    60,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   114,    22,
      27,     0,    46,    95,    97,    80,    88,    86,     0,    85,
      48,    61,    79,    72,    75,    74,    78,    76,    71,    62,
      63,    68,    69,    65,    67,    64,    66,    73,    77,    70,
     118,    14,    16,    12,     0,    83,     0,     0,    81,    87,
      30,     0,     0,     0,     0,    17,    18,    15,    20,     0,
       0,    19,    21
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,
     -55,   -55,   119,   -55,    97,    -2,   -55,   -55,   -55,   -54,
     -52,   -55,   -42,   -55,   -55,   -50,   -55,   -55,   -55,   -48,
     -55,   -11,   -55,   -55,   173,   -55,    -3,   -55,   -55,   -55,
     -55
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    19,    20,    21,    48,   173,   177,   181,
      22,    23,    61,    62,    63,    64,    25,    26,    27,    92,
      93,    94,    95,    77,    78,    96,   148,   149,    80,   105,
      82,   106,    28,    29,    30,   114,    31,    32,    33,    34,
      98
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      24,    75,    37,    76,    38,    79,    52,    81,     5,   171,
      35,    49,   172,    50,    41,    42,     7,    75,    83,    76,
      43,    79,    44,   102,    45,    84,    10,   137,     3,    39,
     107,   108,    65,    54,    40,   138,    70,    85,   -13,    71,
     143,   115,   116,   117,   118,    86,    72,    36,  -115,    73,
      68,    69,    75,    75,    76,    76,    79,    79,   144,   145,
      87,    88,   142,   -47,    89,    46,    47,   147,   150,   109,
      56,   184,    74,   185,    90,    91,    74,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,    57,    70,    59,    66,    71,
     187,    67,    70,    97,    99,    71,    72,   100,   101,    73,
     -98,     4,    72,   104,   110,    73,    52,    52,    53,   111,
      75,   109,    76,    75,    79,    76,   178,    79,   141,    75,
     112,    76,    74,    79,   179,   144,   113,     5,    74,   139,
       6,   121,   122,   123,    54,     7,   170,   191,   192,    58,
      11,    12,     8,   175,     9,    10,    13,    14,    15,    16,
      17,   174,    11,    12,    60,   176,   183,   186,    13,    14,
      15,    16,    17,   188,   189,   182,    18,   119,   120,   190,
     121,   122,   123,   124,   125,   103,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   140,    70,     0,
      70,    71,    51,    71,    52,    53,     0,     0,    72,     0,
      72,    73,     0,    73,   119,   120,     0,   121,   122,   123,
      11,    12,     0,     0,   127,   128,    13,    14,    15,    16,
      17,    54,    55,     0,   180,     0,    74,   119,   120,     0,
     121,   122,   123,   124,   125,     0,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,     0,   119,   120,
       0,   121,   122,   123,   124,   125,   151,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,     0,   119,
     120,   146,   121,   122,   123,   124,   125,     0,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   119,
     120,     0,   121,   122,   123,   124,   125,     0,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   119,   120,
       0,   121,   122,   123,   124,   125,     0,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   119,   120,     0,   121,
     122,   123,   124,   125,     0,   126,   127,   128,  -116,  -116,
    -116,  -116,  -116,  -116,   119,   120,     0,   121,   122,   123,
     124,     0,     0,     0,   127,   128,   119,   120,     0,   121,
     122,   123
};

static const yytype_int16 yycheck[] =
{
       2,    55,     5,    55,     7,    55,     4,    55,    27,    30,
      30,    28,    33,    30,    52,    53,    35,    71,     8,    71,
      58,    71,    60,    65,    62,    15,    45,    28,     0,    66,
      72,    73,    29,    31,    66,    36,    30,    27,    35,    33,
      34,    83,    84,    85,    86,    35,    40,    66,    35,    43,
      53,    54,   106,   107,   106,   107,   106,   107,   106,   107,
      50,    51,   104,    29,    54,    35,    66,   109,   110,    35,
      14,    28,    66,    30,    64,    65,    66,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,    35,    30,    30,    35,    33,
      34,    66,    30,    66,    36,    33,    40,    28,    66,    43,
       0,     1,    40,    29,    29,    43,     4,     4,     5,    30,
     174,    35,   174,   177,   174,   177,   174,   177,    36,   183,
      30,   183,    66,   183,   176,   183,    30,    27,    66,    30,
      30,    10,    11,    12,    31,    35,    66,   189,   190,    36,
      52,    53,    42,    36,    44,    45,    58,    59,    60,    61,
      62,    41,    52,    53,    66,    28,   177,    66,    58,    59,
      60,    61,    62,    66,    29,   177,    66,     7,     8,    29,
      10,    11,    12,    13,    14,    66,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,   100,    30,    -1,
      30,    33,    29,    33,     4,     5,    -1,    -1,    40,    -1,
      40,    43,    -1,    43,     7,     8,    -1,    10,    11,    12,
      52,    53,    -1,    -1,    17,    18,    58,    59,    60,    61,
      62,    31,    32,    -1,    66,    -1,    66,     7,     8,    -1,
      10,    11,    12,    13,    14,    -1,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    -1,     7,     8,
      -1,    10,    11,    12,    13,    14,    36,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    -1,     7,
       8,    30,    10,    11,    12,    13,    14,    -1,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,     7,
       8,    -1,    10,    11,    12,    13,    14,    -1,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,     7,     8,
      -1,    10,    11,    12,    13,    14,    -1,    16,    17,    18,
      19,    20,    21,    22,    23,    24,     7,     8,    -1,    10,
      11,    12,    13,    14,    -1,    16,    17,    18,    19,    20,
      21,    22,    23,    24,     7,     8,    -1,    10,    11,    12,
      13,    -1,    -1,    -1,    17,    18,     7,     8,    -1,    10,
      11,    12
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    70,    71,     0,     1,    27,    30,    35,    42,    44,
      45,    52,    53,    58,    59,    60,    61,    62,    66,    72,
      73,    74,    79,    80,    84,    85,    86,    87,   101,   102,
     103,   105,   106,   107,   108,    30,    66,   105,   105,    66,
      66,    52,    53,    58,    60,    62,    35,    66,    75,    28,
      30,   103,     4,     5,    31,    32,    14,    35,    36,    30,
      66,    81,    82,    83,    84,    29,    35,    66,   105,   105,
      30,    33,    40,    43,    66,    88,    89,    92,    93,    94,
      97,    98,    99,     8,    15,    27,    35,    50,    51,    54,
      64,    65,    88,    89,    90,    91,    94,    66,   109,    36,
      28,    66,    91,    81,    29,    98,   100,    91,    91,    35,
      29,    30,    30,    30,   104,    91,    91,    91,    91,     7,
       8,    10,    11,    12,    13,    14,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    28,    36,    30,
      83,    36,    91,    34,    98,    98,    30,    91,    95,    96,
      91,    36,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      66,    30,    33,    76,    41,    36,    28,    77,    98,    91,
      66,    78,    84,   100,    28,    30,    66,    34,    66,    29,
      29,    91,    91
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    69,    70,    71,    71,    71,    72,    72,    72,    72,
      72,    73,    74,    75,    76,    76,    77,    77,    78,    78,
      78,    78,    79,    80,    81,    81,    82,    82,    83,    84,
      84,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    86,    87,    87,    87,    87,    88,    89,    90,
      90,    90,    90,    90,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      92,    92,    93,    94,    95,    95,    96,    96,    97,    97,
      97,    97,    98,    98,    98,    99,   100,   100,   101,   101,
     102,   102,   103,   104,   104,   105,   105,   105,   105,   105,
     105,   106,   106,   107,   107,   108,   109,   109,   109
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     2,     3,     1,     1,     1,     1,
       1,     3,     6,     1,     1,     4,     0,     3,     2,     4,
       3,     5,     5,     2,     0,     1,     1,     3,     2,     1,
       1,     1,     1,     1,     1,     2,     1,     1,     2,     2,
       2,     2,     2,     2,     4,     3,     5,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     5,     2,     4,     0,     1,     1,     3,     3,     1,
       1,     2,     1,     1,     1,     3,     1,     2,     0,     1,
       1,     2,     4,     0,     1,     1,     2,     3,     3,     3,
       2,     1,     3,     1,     4,     1,     0,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
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
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 132 "E--_parser.y++" /* yacc.c:1646  */
    {
}
#line 1515 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 3:
#line 135 "E--_parser.y++" /* yacc.c:1646  */
    {
}
#line 1522 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 4:
#line 137 "E--_parser.y++" /* yacc.c:1646  */
    {}
#line 1528 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 5:
#line 138 "E--_parser.y++" /* yacc.c:1646  */
    {
	errMsg("Syntax error, expecting a declaration");
}
#line 1536 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 11:
#line 150 "E--_parser.y++" /* yacc.c:1646  */
    {
	SymTabEntry *ste = stm.lookUp((yyvsp[-1].cVal));
	if (ste) {
		errMsg(string("Redefinition of name ") + (yyvsp[-1].cVal));
	} else {
		ClassEntry *ce = new ClassEntry((yyvsp[-1].cVal));
		stm.insert(ce);
		ce->type(new Type(ce, Type::CLASS));
	}
}
#line 1551 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 12:
#line 162 "E--_parser.y++" /* yacc.c:1646  */
    {
	if ((yyvsp[-4].functionEntry)) {
		stm.leaveScope();
		FunctionEntry *fe = (yyvsp[-4].functionEntry);
		if ((yyvsp[-5].typeVal))
		{
			// cout << "return type : " << $1->name() << "\n";
		}
		else
		{
			cout << "return type is bad\n";
		}
		fe->type(new Type((yyvsp[-2].typeList), (yyvsp[-5].typeVal)));
		
		fe->body((yyvsp[0].compoundStmtVal));
	} else {
		SymTabEntry *scopeEntry = stm.currentScope();
		SymTabEntry *ste;
		SymTab::iterator it = scopeEntry->symTab()->begin();
		while (it != scopeEntry->symTab()->end()) {
			ste = *it;
			if (ste->kind() == SymTabEntry::Kind::VARIABLE_KIND) {
				((VariableEntry*)ste)->varKind(VariableEntry::GLOBAL_VAR);
			}
			++it;
		}
	}
}
#line 1584 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 13:
#line 192 "E--_parser.y++" /* yacc.c:1646  */
    {
	SymTabEntry *ste = stm.lookUp((yyvsp[0].cVal));
	if (ste) {
		errMsg(string("Redefinition of name ") + (yyvsp[0].cVal));
		(yyval.functionEntry) = NULL;
	} else {
		(yyval.functionEntry) = new FunctionEntry((yyvsp[0].cVal));
		stm.insert((yyval.functionEntry));
		stm.enterScope((yyval.functionEntry));
	}
}
#line 1600 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 14:
#line 205 "E--_parser.y++" /* yacc.c:1646  */
    {
	(yyval.compoundStmtVal) = NULL;
}
#line 1608 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 15:
#line 208 "E--_parser.y++" /* yacc.c:1646  */
    {
	(yyval.compoundStmtVal) = new CompoundStmtNode((yyvsp[-1].stmtList));
}
#line 1616 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 17:
#line 214 "E--_parser.y++" /* yacc.c:1646  */
    {
}
#line 1623 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 18:
#line 218 "E--_parser.y++" /* yacc.c:1646  */
    {
	SymTabEntry *ste = stm.lookUpInScope((yyvsp[0].cVal), stm.currentScope()->kind());
	if (ste) {
		errMsg(string("Redefinition of name ") + (yyvsp[0].cVal));
	} else {
		(yyval.variableEntry) = new VariableEntry((yyvsp[0].cVal), VariableEntry::LOCAL_VAR, (yyvsp[-1].typeVal));
		stm.insert((yyval.variableEntry));
	}
}
#line 1637 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 19:
#line 227 "E--_parser.y++" /* yacc.c:1646  */
    {
	SymTabEntry *ste = stm.lookUpInScope((yyvsp[-2].cVal), stm.currentScope()->kind());
	if (ste) {
		errMsg(string("Redefinition of name ") + (yyvsp[-2].cVal));
	} else {
		(yyval.variableEntry) = new VariableEntry((yyvsp[-2].cVal), VariableEntry::LOCAL_VAR, (yyvsp[-3].typeVal), (yyvsp[0].exprVal));
		stm.insert((yyval.variableEntry));
	}
}
#line 1651 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 20:
#line 236 "E--_parser.y++" /* yacc.c:1646  */
    {
	SymTabEntry *ste = stm.lookUpInScope((yyvsp[0].cVal), stm.currentScope()->kind());
	if (ste) {
		errMsg(string("Redefinition of name ") + (yyvsp[0].cVal));
	} else {
		(yyval.variableEntry) = new VariableEntry((yyvsp[0].cVal), VariableEntry::LOCAL_VAR, (yyvsp[-2].variableEntry)->type());
		stm.insert((yyval.variableEntry));
	}
}
#line 1665 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 21:
#line 245 "E--_parser.y++" /* yacc.c:1646  */
    {
	SymTabEntry *ste = stm.lookUpInScope((yyvsp[-2].cVal), stm.currentScope()->kind());
	if (ste) {
		errMsg(string("Redefinition of name ") + (yyvsp[-2].cVal));
	} else {
		(yyval.variableEntry) = new VariableEntry((yyvsp[-2].cVal), VariableEntry::LOCAL_VAR, (yyvsp[-4].variableEntry)->type(), (yyvsp[0].exprVal));
		stm.insert((yyval.variableEntry));
	}
}
#line 1679 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 22:
#line 256 "E--_parser.y++" /* yacc.c:1646  */
    {
	if ((yyvsp[-4].eventEntry)) {
		stm.leaveScope();
		(yyvsp[-4].eventEntry)->type(new Type((yyvsp[-2].typeList), Type::EVENT));
	} else {
		Type *type = new Type((yyvsp[-2].typeList), Type::VOID);
		delete type;
		SymTabEntry *scopeEntry = stm.currentScope();
		SymTabEntry *ste;
		SymTab::iterator it = scopeEntry->symTab()->begin();
		while (it != scopeEntry->symTab()->end()) {
			ste = *it;
			if (ste->kind() == SymTabEntry::Kind::VARIABLE_KIND) {
				((VariableEntry*)ste)->varKind(VariableEntry::GLOBAL_VAR);
			}
			++it;
		}
	}
}
#line 1703 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 23:
#line 276 "E--_parser.y++" /* yacc.c:1646  */
    {
	SymTabEntry *ste = stm.lookUp((yyvsp[0].cVal));
	if (ste) {
		errMsg(string("Redefinition of name ") + (yyvsp[0].cVal));
		(yyval.eventEntry) = NULL;
	} else {
		(yyval.eventEntry) = new EventEntry((yyvsp[0].cVal));
		stm.insert((yyval.eventEntry));
		stm.enterScope((yyval.eventEntry));
	}
}
#line 1719 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 24:
#line 288 "E--_parser.y++" /* yacc.c:1646  */
    {
	(yyval.typeList) = NULL;
}
#line 1727 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 25:
#line 291 "E--_parser.y++" /* yacc.c:1646  */
    {
	(yyval.typeList) = (yyvsp[0].typeList);
}
#line 1735 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 26:
#line 296 "E--_parser.y++" /* yacc.c:1646  */
    {
	(yyval.typeList) = new vector<Type*>;
	if ((yyvsp[0].variableEntry))
		(yyval.typeList)->push_back((yyvsp[0].variableEntry)->type());
}
#line 1745 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 27:
#line 301 "E--_parser.y++" /* yacc.c:1646  */
    {
	if ((yyvsp[0].variableEntry))
		(yyvsp[-2].typeList)->push_back((yyvsp[0].variableEntry)->type());
}
#line 1754 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 28:
#line 307 "E--_parser.y++" /* yacc.c:1646  */
    {
	SymTabEntry *ste = stm.lookUpInScope((yyvsp[0].cVal), stm.currentScope()->kind());
	if (ste) {
		errMsg(string("Redefinition of name ") + (yyvsp[0].cVal));
		(yyval.variableEntry) = NULL;
	} else {
		(yyval.variableEntry) = new VariableEntry((yyvsp[0].cVal), VariableEntry::PARAM_VAR, (yyvsp[-1].typeVal));
		stm.insert((yyval.variableEntry));
	}
}
#line 1769 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 29:
#line 319 "E--_parser.y++" /* yacc.c:1646  */
    {
	(yyval.typeVal) = (yyvsp[0].typeVal);
}
#line 1777 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 30:
#line 322 "E--_parser.y++" /* yacc.c:1646  */
    {
	SymTabEntry *ste = stm.lookUp((yyvsp[0].cVal));
	if (!ste) {
		errMsg(string("Undeclared type \"") + (yyvsp[0].cVal) + string("\""));
		(yyval.typeVal) = NULL;
	} else if (ste->typeTag() != Type::CLASS) {
		errMsg(string("Unknown type \"") + (yyvsp[0].cVal) + string("\""));
		(yyval.typeVal) = NULL;
	} else {
		(yyval.typeVal) = ste->type();
	}
}
#line 1794 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 31:
#line 336 "E--_parser.y++" /* yacc.c:1646  */
    {
	(yyval.typeVal) = new Type();
}
#line 1802 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 32:
#line 339 "E--_parser.y++" /* yacc.c:1646  */
    {
	(yyval.typeVal) = new Type(Type::BOOL);
}
#line 1810 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 33:
#line 342 "E--_parser.y++" /* yacc.c:1646  */
    {
	(yyval.typeVal) = new Type(Type::STRING);
}
#line 1818 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 34:
#line 345 "E--_parser.y++" /* yacc.c:1646  */
    {
	(yyval.typeVal) = new Type(Type::BYTE);
}
#line 1826 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 35:
#line 348 "E--_parser.y++" /* yacc.c:1646  */
    {
	(yyval.typeVal) = new Type(Type::UINT);
}
#line 1834 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 36:
#line 351 "E--_parser.y++" /* yacc.c:1646  */
    {
	(yyval.typeVal) = new Type(Type::INT);
}
#line 1842 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 37:
#line 354 "E--_parser.y++" /* yacc.c:1646  */
    {
	(yyval.typeVal) = new Type(Type::DOUBLE);
}
#line 1850 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 38:
#line 357 "E--_parser.y++" /* yacc.c:1646  */
    {
	errMsg("Invalid use of keyword \"unsigned\"");
	(yyval.typeVal) = NULL;
}
#line 1859 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 39:
#line 361 "E--_parser.y++" /* yacc.c:1646  */
    {
	errMsg("Invalid use of keyword \"unsigned\"");
	(yyval.typeVal) = NULL;
}
#line 1868 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 40:
#line 365 "E--_parser.y++" /* yacc.c:1646  */
    {
	errMsg("Invalid use of keyword \"unsigned\"");
	(yyval.typeVal) = NULL;
}
#line 1877 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 41:
#line 369 "E--_parser.y++" /* yacc.c:1646  */
    {
	errMsg("Invalid use of keyword \"unsigned\"");
	(yyval.typeVal) = NULL;
}
#line 1886 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 42:
#line 375 "E--_parser.y++" /* yacc.c:1646  */
    {
	(yyval.variableEntry) = (yyvsp[-1].variableEntry);
}
#line 1894 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 43:
#line 380 "E--_parser.y++" /* yacc.c:1646  */
    {
	SymTabEntry *ste = stm.lookUp((yyvsp[0].cVal));
	if (ste) {
		errMsg(string("Redefinition of name ") + (yyvsp[0].cVal));
		(yyval.variableEntry) = NULL;
	} else {
		(yyval.variableEntry) = new VariableEntry((yyvsp[0].cVal), VariableEntry::GLOBAL_VAR, (yyvsp[-1].typeVal));
		stm.insert((yyval.variableEntry));
	}
}
#line 1909 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 44:
#line 390 "E--_parser.y++" /* yacc.c:1646  */
    {
	SymTabEntry *ste = stm.lookUp((yyvsp[-2].cVal));
	if (ste) {
		errMsg(string("Redefinition of name ") + (yyvsp[-2].cVal));
		(yyval.variableEntry) = NULL;
	} else {
		(yyval.variableEntry) = new VariableEntry((yyvsp[-2].cVal), VariableEntry::GLOBAL_VAR, (yyvsp[-3].typeVal), (yyvsp[0].exprVal));
		stm.insert((yyval.variableEntry));
	}
}
#line 1924 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 45:
#line 400 "E--_parser.y++" /* yacc.c:1646  */
    {
	SymTabEntry *ste = stm.lookUp((yyvsp[0].cVal));
	if (ste) {
		errMsg(string("Redefinition of name ") + (yyvsp[0].cVal));
		(yyval.variableEntry) = NULL;
	} else {
		(yyval.variableEntry) = new VariableEntry((yyvsp[0].cVal), VariableEntry::GLOBAL_VAR, (yyvsp[-2].variableEntry)->type());
		stm.insert((yyval.variableEntry));
	}
}
#line 1939 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 46:
#line 410 "E--_parser.y++" /* yacc.c:1646  */
    {
	SymTabEntry *ste = stm.lookUp((yyvsp[-2].cVal));
	if (ste) {
		errMsg(string("Redefinition of name ") + (yyvsp[-2].cVal));
		(yyval.variableEntry) = NULL;
	} else {
		(yyval.variableEntry) = new VariableEntry((yyvsp[-2].cVal), VariableEntry::GLOBAL_VAR, (yyvsp[-4].variableEntry)->type(), (yyvsp[0].exprVal));
		stm.insert((yyval.variableEntry));
	}
}
#line 1954 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 47:
#line 422 "E--_parser.y++" /* yacc.c:1646  */
    {
	SymTabEntry *ste = stm.lookUp((yyvsp[0].cVal));
	if (!ste) {
		errMsg(string("Undeclared identifier \"") + (yyvsp[0].cVal) + string("\""));
		(yyval.refexpVal) = NULL;
	} else {
		(yyval.refexpVal) = new RefExprNode((yyvsp[0].cVal), ste);
	}
}
#line 1968 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 48:
#line 433 "E--_parser.y++" /* yacc.c:1646  */
    {
	if ((yyvsp[-2].refexpVal) && (yyvsp[0].exprVal))
		(yyval.exprVal) = new OpNode(OpNode::OpCode::ASSIGN, (yyvsp[-2].refexpVal), (yyvsp[0].exprVal));
	else
		(yyval.exprVal) = NULL;
}
#line 1979 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 49:
#line 441 "E--_parser.y++" /* yacc.c:1646  */
    {
	(yyval.valVal) = new Value((yyvsp[0].cVal));
}
#line 1987 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 50:
#line 444 "E--_parser.y++" /* yacc.c:1646  */
    {
	(yyval.valVal) = new Value((yyvsp[0].uVal), Type::UINT);
}
#line 1995 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 51:
#line 447 "E--_parser.y++" /* yacc.c:1646  */
    {
	(yyval.valVal) = new Value((yyvsp[0].dVal));
}
#line 2003 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 52:
#line 450 "E--_parser.y++" /* yacc.c:1646  */
    {
	(yyval.valVal) = new Value(true);
}
#line 2011 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 53:
#line 453 "E--_parser.y++" /* yacc.c:1646  */
    {
	(yyval.valVal) = new Value(false);
}
#line 2019 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 54:
#line 457 "E--_parser.y++" /* yacc.c:1646  */
    {
	(yyval.exprVal) = new ValueNode((yyvsp[0].valVal));
}
#line 2027 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 55:
#line 460 "E--_parser.y++" /* yacc.c:1646  */
    {
	(yyval.exprVal) = (yyvsp[0].refexpVal);
}
#line 2035 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 56:
#line 463 "E--_parser.y++" /* yacc.c:1646  */
    {
	(yyval.exprVal) = (yyvsp[0].exprVal);
}
#line 2043 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 57:
#line 466 "E--_parser.y++" /* yacc.c:1646  */
    {
	(yyval.exprVal) = (yyvsp[0].exprVal);
}
#line 2051 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 58:
#line 469 "E--_parser.y++" /* yacc.c:1646  */
    {
	(yyval.exprVal) = new OpNode(OpNode::OpCode::BITNOT, (yyvsp[0].exprVal));
}
#line 2059 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 59:
#line 472 "E--_parser.y++" /* yacc.c:1646  */
    {
	(yyval.exprVal) = new OpNode(OpNode::OpCode::UMINUS, (yyvsp[0].exprVal));
}
#line 2067 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 60:
#line 475 "E--_parser.y++" /* yacc.c:1646  */
    {
	(yyval.exprVal) = new OpNode(OpNode::OpCode::NOT, (yyvsp[0].exprVal));
}
#line 2075 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 61:
#line 478 "E--_parser.y++" /* yacc.c:1646  */
    {
	(yyval.exprVal) = (yyvsp[-1].exprVal);
}
#line 2083 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 62:
#line 481 "E--_parser.y++" /* yacc.c:1646  */
    {
	(yyval.exprVal) = new OpNode(OpNode::OpCode::BITXOR, (yyvsp[-2].exprVal), (yyvsp[0].exprVal));
}
#line 2091 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 63:
#line 484 "E--_parser.y++" /* yacc.c:1646  */
    {
	(yyval.exprVal) = new OpNode(OpNode::OpCode::SHL, (yyvsp[-2].exprVal), (yyvsp[0].exprVal));
}
#line 2099 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 64:
#line 487 "E--_parser.y++" /* yacc.c:1646  */
    {
	(yyval.exprVal) = new OpNode(OpNode::OpCode::LE, (yyvsp[-2].exprVal), (yyvsp[0].exprVal));
}
#line 2107 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 65:
#line 490 "E--_parser.y++" /* yacc.c:1646  */
    {
	(yyval.exprVal) = new OpNode(OpNode::OpCode::LT, (yyvsp[-2].exprVal), (yyvsp[0].exprVal));
}
#line 2115 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 66:
#line 493 "E--_parser.y++" /* yacc.c:1646  */
    {
	(yyval.exprVal) = new OpNode(OpNode::OpCode::EQ, (yyvsp[-2].exprVal), (yyvsp[0].exprVal));
}
#line 2123 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 67:
#line 496 "E--_parser.y++" /* yacc.c:1646  */
    {
	(yyval.exprVal) = new OpNode(OpNode::OpCode::GE, (yyvsp[-2].exprVal), (yyvsp[0].exprVal));
}
#line 2131 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 68:
#line 499 "E--_parser.y++" /* yacc.c:1646  */
    {
	(yyval.exprVal) = new OpNode(OpNode::OpCode::SHR, (yyvsp[-2].exprVal), (yyvsp[0].exprVal));
}
#line 2139 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 69:
#line 502 "E--_parser.y++" /* yacc.c:1646  */
    {
	(yyval.exprVal) = new OpNode(OpNode::OpCode::GT, (yyvsp[-2].exprVal), (yyvsp[0].exprVal));
}
#line 2147 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 70:
#line 505 "E--_parser.y++" /* yacc.c:1646  */
    {
	(yyval.exprVal) = new OpNode(OpNode::OpCode::OR, (yyvsp[-2].exprVal), (yyvsp[0].exprVal));
}
#line 2155 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 71:
#line 508 "E--_parser.y++" /* yacc.c:1646  */
    {
	(yyval.exprVal) = new OpNode(OpNode::OpCode::BITOR, (yyvsp[-2].exprVal), (yyvsp[0].exprVal));
}
#line 2163 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 72:
#line 511 "E--_parser.y++" /* yacc.c:1646  */
    {
	(yyval.exprVal) = new OpNode(OpNode::OpCode::MINUS, (yyvsp[-2].exprVal), (yyvsp[0].exprVal));
}
#line 2171 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 73:
#line 514 "E--_parser.y++" /* yacc.c:1646  */
    {
	(yyval.exprVal) = new OpNode(OpNode::OpCode::NE, (yyvsp[-2].exprVal), (yyvsp[0].exprVal));
}
#line 2179 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 74:
#line 517 "E--_parser.y++" /* yacc.c:1646  */
    {
	(yyval.exprVal) = new OpNode(OpNode::OpCode::DIV, (yyvsp[-2].exprVal), (yyvsp[0].exprVal));
}
#line 2187 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 75:
#line 520 "E--_parser.y++" /* yacc.c:1646  */
    {
	(yyval.exprVal) = new OpNode(OpNode::OpCode::MULT, (yyvsp[-2].exprVal), (yyvsp[0].exprVal));
}
#line 2195 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 76:
#line 523 "E--_parser.y++" /* yacc.c:1646  */
    {
	(yyval.exprVal) = new OpNode(OpNode::OpCode::BITAND, (yyvsp[-2].exprVal), (yyvsp[0].exprVal));
}
#line 2203 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 77:
#line 526 "E--_parser.y++" /* yacc.c:1646  */
    {
	(yyval.exprVal) = new OpNode(OpNode::OpCode::AND, (yyvsp[-2].exprVal), (yyvsp[0].exprVal));
}
#line 2211 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 78:
#line 529 "E--_parser.y++" /* yacc.c:1646  */
    {
	(yyval.exprVal) = new OpNode(OpNode::OpCode::MOD, (yyvsp[-2].exprVal), (yyvsp[0].exprVal));
}
#line 2219 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 79:
#line 532 "E--_parser.y++" /* yacc.c:1646  */
    {
	(yyval.exprVal) = new OpNode(OpNode::OpCode::PLUS, (yyvsp[-2].exprVal), (yyvsp[0].exprVal));
}
#line 2227 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 80:
#line 537 "E--_parser.y++" /* yacc.c:1646  */
    {
	(yyval.ifVal) = new IfNode((yyvsp[-1].exprVal), (yyvsp[0].stmtVal));
}
#line 2235 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 81:
#line 540 "E--_parser.y++" /* yacc.c:1646  */
    {
	(yyval.ifVal) = new IfNode((yyvsp[-3].exprVal), (yyvsp[-2].stmtVal), (yyvsp[0].stmtVal));
}
#line 2243 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 82:
#line 544 "E--_parser.y++" /* yacc.c:1646  */
    {
	(yyval.stmtVal) = new ExprStmtNode((yyvsp[-1].exprVal));
}
#line 2251 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 83:
#line 549 "E--_parser.y++" /* yacc.c:1646  */
    {
	SymTabEntry *ste = stm.lookUp((yyvsp[-3].cVal));
	if (!ste) {
		errMsg(string("\"") + (yyvsp[-3].cVal) + string("\" is not a function or module name"));
		(yyval.exprVal) = NULL;
	} else if (ste->typeTag() != Type::FUNCTION && ste->typeTag() != Type::EVENT) {
		errMsg(string("\"") + (yyvsp[-3].cVal) + string("\" is not a function or module name"));
		(yyval.exprVal) = NULL;
	} else {
		FunctionEntry *fe = (FunctionEntry*) ste;
		vector<Type*>* args = fe->type()->argTypes();
		vector<Type*>::iterator it;
		vector<ExprNode*>::iterator it1 = (yyvsp[-1].exprList)->begin();
		if ((yyvsp[-1].exprList)->size() == args->size())
		{
			for(it = args->begin();it != args->end(); ++it)
			{
				cout << "invoking function \n";
				/*if ((*it)->name() !=  (*it1)->type()->name())
				{
					errMsg("args type mis-match in function");
				}
				++it1;*/
			}
		}
		else
		{
			errMsg("invalid number of arguments");
		}
		(yyval.exprVal) = new InvocationNode(ste, (yyvsp[-1].exprList));
		cout << "done invoking function \n";
	}
}
#line 2289 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 84:
#line 583 "E--_parser.y++" /* yacc.c:1646  */
    {
	(yyval.exprList) = NULL;
}
#line 2297 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 85:
#line 586 "E--_parser.y++" /* yacc.c:1646  */
    {
	(yyval.exprList) = (yyvsp[0].exprList);
}
#line 2305 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 86:
#line 591 "E--_parser.y++" /* yacc.c:1646  */
    {
	(yyval.exprList) = new vector<ExprNode*>;
	(yyval.exprList)->push_back((yyvsp[0].exprVal));
}
#line 2314 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 87:
#line 595 "E--_parser.y++" /* yacc.c:1646  */
    {
	(yyvsp[-2].exprList)->push_back((yyvsp[0].exprVal));
}
#line 2322 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 88:
#line 600 "E--_parser.y++" /* yacc.c:1646  */
    {
	SymTabEntry *ste = stm.currentScope();
	if (ste->kind() != SymTabEntry::Kind::FUNCTION_KIND) {
		errMsg("Return statement is valid only within a function");
	}
	else
	{
		cout << "handling return statement\n";
		FunctionEntry *fe =(FunctionEntry*) ste;
		cout << "return type : " << fe->name() << "\n";

		if (fe)
		{
			cout << "function ptr not null\n";
		}
		if (fe->type())
		{
			cout << "function type ptr not null\n";

		}
		if (fe->type()->argTypes())
		{
			cout << "function ret type ptr not null\n";
		}
		if (fe && fe->type() && fe->type()->retType())
		{
			errMsg("return type mis-match");
		}
	}
	(yyval.stmtVal) = new ReturnStmtNode((yyvsp[-1].exprVal), (FunctionEntry*)ste);
}
#line 2358 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 89:
#line 631 "E--_parser.y++" /* yacc.c:1646  */
    {
	(yyval.stmtVal) = NULL;
}
#line 2366 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 90:
#line 634 "E--_parser.y++" /* yacc.c:1646  */
    {
	(yyval.stmtVal) = (yyvsp[0].stmtVal);
}
#line 2374 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 91:
#line 637 "E--_parser.y++" /* yacc.c:1646  */
    {
	(yyval.stmtVal) = new ExprStmtNode((yyvsp[-1].exprVal));
}
#line 2382 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 92:
#line 642 "E--_parser.y++" /* yacc.c:1646  */
    {
	(yyval.stmtVal) = (yyvsp[0].stmtVal);
}
#line 2390 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 93:
#line 645 "E--_parser.y++" /* yacc.c:1646  */
    {
	(yyval.stmtVal) = (yyvsp[0].compoundStmtVal);
}
#line 2398 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 94:
#line 648 "E--_parser.y++" /* yacc.c:1646  */
    {
	(yyval.stmtVal) = (yyvsp[0].ifVal);
}
#line 2406 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 95:
#line 653 "E--_parser.y++" /* yacc.c:1646  */
    {
	(yyval.compoundStmtVal) = new CompoundStmtNode((yyvsp[-1].stmtList));
}
#line 2414 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 96:
#line 658 "E--_parser.y++" /* yacc.c:1646  */
    {
	(yyval.stmtList) = new list<StmtNode*>;
	(yyval.stmtList)->push_back((yyvsp[0].stmtVal));
}
#line 2423 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 97:
#line 662 "E--_parser.y++" /* yacc.c:1646  */
    {
	(yyvsp[-1].stmtList)->push_back((yyvsp[0].stmtVal));
}
#line 2431 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 98:
#line 667 "E--_parser.y++" /* yacc.c:1646  */
    {
       errMsg("Must contain at least one rule");
}
#line 2439 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 102:
#line 677 "E--_parser.y++" /* yacc.c:1646  */
    {
	if ((yyvsp[-3].patVal)) {
		if ((yyvsp[-1].stmtVal)) {
			SymTabEntry *ste = stm.currentScope();
			(yyval.ruleNode) = new RuleNode((RuleBlockEntry*)ste, (yyvsp[-3].patVal), (yyvsp[-1].stmtVal));
			GlobalEntry *ge = (GlobalEntry*)stm.currentScope(SymTabEntry::Kind::GLOBAL_KIND);
			ge->addRule((yyval.ruleNode));
		}
		stm.leaveScope();
	}
}
#line 2455 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 105:
#line 694 "E--_parser.y++" /* yacc.c:1646  */
    {
	(yyval.patVal) = (yyvsp[0].primPatVal);
}
#line 2463 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 106:
#line 697 "E--_parser.y++" /* yacc.c:1646  */
    {
	if ((yyvsp[0].patVal)) {
		if ((yyvsp[0].patVal)->kind() != BasePatNode::PatNodeKind::PRIMITIVE)
			errMsg("Only simple patterns without `.', `*', and `!' operators can be negated");
		(yyval.patVal) = new PatNode(BasePatNode::PatNodeKind::NEG, (yyvsp[0].patVal));
	} else {
		(yyval.patVal) = NULL;
	}
}
#line 2477 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 107:
#line 706 "E--_parser.y++" /* yacc.c:1646  */
    {
	if ((yyvsp[-1].patVal))
		(yyval.patVal) = (yyvsp[-1].patVal);
	else
		(yyval.patVal) = NULL;
}
#line 2488 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 108:
#line 712 "E--_parser.y++" /* yacc.c:1646  */
    {
	if ((yyvsp[-2].patVal)) {
		if ((yyvsp[0].patVal)) {
			(yyval.patVal) = new PatNode(BasePatNode::PatNodeKind::SEQ, (yyvsp[-2].patVal), (yyvsp[0].patVal));
		} else {
			stm.leaveScope();
			(yyval.patVal) = NULL;
		}
	} else {
		(yyval.patVal) = NULL;
	}
}
#line 2505 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 109:
#line 724 "E--_parser.y++" /* yacc.c:1646  */
    {
	if ((yyvsp[-2].patVal)) {
		if ((yyvsp[0].patVal)) {
			(yyval.patVal) = new PatNode(BasePatNode::PatNodeKind::OR, (yyvsp[-2].patVal), (yyvsp[0].patVal));
		} else {
			stm.leaveScope();
			(yyval.patVal) = NULL;
		}
	} else {
		(yyval.patVal) = NULL;
	}
}
#line 2522 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 110:
#line 736 "E--_parser.y++" /* yacc.c:1646  */
    {
	if ((yyvsp[-1].patVal))
		(yyval.patVal) = new PatNode(BasePatNode::PatNodeKind::STAR, (yyvsp[-1].patVal));
	else
		(yyval.patVal) = NULL;
}
#line 2533 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 111:
#line 744 "E--_parser.y++" /* yacc.c:1646  */
    {
	(yyval.primPatVal) = (yyvsp[0].primPatVal);
}
#line 2541 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 112:
#line 747 "E--_parser.y++" /* yacc.c:1646  */
    {
	if ((yyvsp[-2].primPatVal))
		(yyvsp[-2].primPatVal)->cond((yyvsp[0].exprVal));
	(yyval.primPatVal) = (yyvsp[-2].primPatVal);
}
#line 2551 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 113:
#line 754 "E--_parser.y++" /* yacc.c:1646  */
    {
	SymTabEntry *ste = stm.lookUp("any");
	if (!ste) {
		errMsg("Undeclared symbol any");
		(yyval.primPatVal) = NULL;
	} else {
		(yyval.primPatVal) = new PrimitivePatNode((EventEntry*)ste, NULL);
	}
	ste = stm.currentScope();
	if (ste->kind() == SymTabEntry::Kind::GLOBAL_KIND) {
		RuleBlockEntry *rbe = new RuleBlockEntry();
		stm.enterScope(rbe);
	}
}
#line 2570 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 114:
#line 768 "E--_parser.y++" /* yacc.c:1646  */
    {
	if ((yyvsp[-3].cVal)) {
		SymTabEntry *ste = stm.lookUp((yyvsp[-3].cVal));
		EventEntry *ee = (EventEntry*)ste;
		Type *eeType = ee->type();
		if (eeType->argTypes() && (yyvsp[-1].paramList)) {
			if (eeType->argTypes()->size() < (yyvsp[-1].paramList)->size())
				errMsg((yyvsp[-3].cVal) + string(": mismatch in the number of arguments"));
		}
		(yyval.primPatVal) = new PrimitivePatNode((EventEntry*)ste, (yyvsp[-1].paramList));
	} else {
		(yyval.primPatVal) = NULL;
	}
}
#line 2589 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 115:
#line 784 "E--_parser.y++" /* yacc.c:1646  */
    {
	SymTabEntry *ste = stm.lookUp((yyvsp[0].cVal));
	if (!ste) {
		errMsg(string("Expected an event name, but got \"") + (yyvsp[0].cVal) + string("\""));
		(yyval.cVal) = NULL;
	} else if (ste->typeTag() != Type::EVENT) {
		errMsg(string("Expected an event name, but got \"") + (yyvsp[0].cVal) + string("\""));
		(yyval.cVal) = NULL;
	} else {
		ste = stm.currentScope();
		if (ste->kind() == SymTabEntry::Kind::GLOBAL_KIND) {
			RuleBlockEntry *rbe = new RuleBlockEntry();
			stm.enterScope(rbe);
		}
		(yyval.cVal) = (yyvsp[0].cVal);
	}
}
#line 2611 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 116:
#line 803 "E--_parser.y++" /* yacc.c:1646  */
    {
	(yyval.paramList) = NULL;
}
#line 2619 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 117:
#line 806 "E--_parser.y++" /* yacc.c:1646  */
    {
	SymTabEntry *ste = stm.currentScope();
	if (ste->kind() == SymTabEntry::Kind::RULE_BLOCK_KIND) {
		ste = stm.lookUpInScope((yyvsp[0].cVal), SymTabEntry::Kind::RULE_BLOCK_KIND);
		if (ste)
			errMsg(string("Redefinition of name ") + (yyvsp[0].cVal));
		VariableEntry *ve = new VariableEntry((yyvsp[0].cVal), VariableEntry::PARAM_VAR);
		(yyval.paramList) = new vector<VariableEntry*>;
		(yyval.paramList)->push_back(ve);
		stm.insert(ve);
	} else {
		(yyval.paramList) = NULL;
	}
}
#line 2638 "E--_parser.C" /* yacc.c:1646  */
    break;

  case 118:
#line 820 "E--_parser.y++" /* yacc.c:1646  */
    {
	if ((yyvsp[-2].paramList)) {
		SymTabEntry *ste = stm.lookUpInScope((yyvsp[0].cVal), SymTabEntry::Kind::RULE_BLOCK_KIND);
		if (ste) {
			errMsg(string("Redefinition of name ") + (yyvsp[0].cVal));
		}
		VariableEntry *ve = new VariableEntry((yyvsp[0].cVal), VariableEntry::PARAM_VAR);
		(yyvsp[-2].paramList)->push_back(ve);
		stm.insert(ve);
	} else {
		(yyval.paramList) = NULL;
	}
}
#line 2656 "E--_parser.C" /* yacc.c:1646  */
    break;


#line 2660 "E--_parser.C" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



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
                      yytoken, &yylval);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 834 "E--_parser.y++" /* yacc.c:1906  */

