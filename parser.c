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
#line 1 "syntax.y" /* yacc.c:339  */

	#include <stdlib.h>
	#include <stdio.h>
	#include <stack>
	#include <string>
	#include "symtable.h"
	#include <stdio.h>
	#include <iostream>

	void yyerror (const char *yaccProvidedMessage);
	extern int yylex(void);

	extern int yylineno;
	extern char* yytext;
	extern FILE* yyin;
	extern unsigned int current_scope;
	std::stack<bool> scopeAccessStack;
	unsigned int anonymousCounter = 0;

#line 86 "parser.c" /* yacc.c:339  */

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
   by #include "parser.h".  */
#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ID = 258,
    NUMBER = 259,
    STRING = 260,
    BREAK = 261,
    CONTINUE = 262,
    AND = 263,
    OR = 264,
    NOT = 265,
    GREATEREQUAL = 266,
    LESSEQUAL = 267,
    EQUAL = 268,
    NOTEQUAL = 269,
    PLUSPLUS = 270,
    MINUSMINUS = 271,
    LOCAL = 272,
    SCOPEOP = 273,
    DOUPLEDOT = 274,
    FUNCTION = 275,
    NIL = 276,
    TRUE = 277,
    FALSE = 278,
    IF = 279,
    ELSE = 280,
    WHILE = 281,
    FOR = 282,
    RETURN = 283,
    DOUBLEDOT = 284,
    UMINUS = 285
  };
#endif
/* Tokens.  */
#define ID 258
#define NUMBER 259
#define STRING 260
#define BREAK 261
#define CONTINUE 262
#define AND 263
#define OR 264
#define NOT 265
#define GREATEREQUAL 266
#define LESSEQUAL 267
#define EQUAL 268
#define NOTEQUAL 269
#define PLUSPLUS 270
#define MINUSMINUS 271
#define LOCAL 272
#define SCOPEOP 273
#define DOUPLEDOT 274
#define FUNCTION 275
#define NIL 276
#define TRUE 277
#define FALSE 278
#define IF 279
#define ELSE 280
#define WHILE 281
#define FOR 282
#define RETURN 283
#define DOUBLEDOT 284
#define UMINUS 285

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 24 "syntax.y" /* yacc.c:355  */

	char* stringValue;
	float floatValue;
	void* symValue;

#line 192 "parser.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 209 "parser.c" /* yacc.c:358  */

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
#define YYFINAL  65
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   600

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  98
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  188

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   285

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    38,     2,     2,
      29,    30,    36,    39,    45,    40,    33,    37,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    47,    44,
      42,    43,    41,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    31,     2,    32,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    46,     2,    48,     2,     2,     2,     2,
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
      25,    26,    27,    28,    34,    35
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    54,    54,    55,    58,    59,    62,    63,    64,    65,
      66,    67,    68,    69,    69,    69,    70,    71,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    93,    94,    95,    96,    97,    98,    99,
     100,   103,   106,   107,   108,   109,   110,   113,   131,   144,
     155,   158,   159,   160,   160,   164,   165,   166,   169,   170,
     173,   176,   179,   180,   183,   184,   187,   188,   192,   195,
     196,   200,   203,   203,   203,   204,   207,   207,   207,   207,
     218,   218,   218,   228,   228,   228,   228,   228,   231,   232,
     235,   236,   239,   242,   243,   246,   249,   251,   252
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "NUMBER", "STRING", "BREAK",
  "CONTINUE", "AND", "OR", "NOT", "GREATEREQUAL", "LESSEQUAL", "EQUAL",
  "NOTEQUAL", "PLUSPLUS", "MINUSMINUS", "LOCAL", "SCOPEOP", "DOUPLEDOT",
  "FUNCTION", "NIL", "TRUE", "FALSE", "IF", "ELSE", "WHILE", "FOR",
  "RETURN", "'('", "')'", "'['", "']'", "'.'", "DOUBLEDOT", "UMINUS",
  "'*'", "'/'", "'%'", "'+'", "'-'", "'>'", "'<'", "'='", "';'", "','",
  "'{'", "':'", "'}'", "$accept", "program", "stmt1", "stmt", "$@1", "$@2",
  "expr", "term", "assignexpr", "primary", "lvalue", "member", "$@3",
  "call", "callsuffix", "normcall", "methodcall", "elist", "elist1",
  "objectdef", "indexed", "more", "indexedelem", "block", "$@4", "$@5",
  "funcdef", "$@6", "$@7", "$@8", "$@9", "$@10", "const", "idlist",
  "idlist1", "ifstmt", "ifstmt1", "whilestmt", "forstmt", "returnstmt", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,    40,
      41,    91,    93,    46,   284,   285,    42,    47,    37,    43,
      45,    62,    60,    61,    59,    44,   123,    58,   125
};
# endif

#define YYPACT_NINF -161

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-161)))

#define YYTABLE_NINF -14

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-14)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     214,  -161,  -161,  -161,   -34,   -33,   370,    83,    83,    25,
      33,     4,  -161,  -161,  -161,    12,    14,    32,   277,   341,
      74,   370,  -161,    76,   214,  -161,    36,    18,  -161,  -161,
    -161,   500,  -161,   -13,  -161,  -161,  -161,  -161,  -161,  -161,
    -161,  -161,  -161,   551,    65,     6,   -13,     6,  -161,  -161,
      59,  -161,   370,   370,   370,  -161,   404,   450,    64,   370,
     394,    70,    72,    61,   551,  -161,  -161,    60,  -161,   370,
     370,   370,   370,   370,   370,   370,   370,   370,   370,   370,
     370,   370,  -161,  -161,  -161,   104,   370,   370,   106,   370,
    -161,  -161,  -161,   370,   107,    81,  -161,   110,   463,   498,
      73,  -161,  -161,    89,   301,   370,  -161,  -161,  -161,    75,
    -161,  -161,   246,  -161,   117,  -161,   311,   311,   124,   124,
      10,    10,    10,   558,   558,   311,   311,    90,   101,   509,
    -161,  -161,   109,  -161,    89,   110,    96,   112,   246,   246,
     370,   370,   370,   394,    61,   168,   370,  -161,  -161,  -161,
      83,   113,   141,  -161,  -161,   123,  -161,   413,   119,   116,
    -161,  -161,  -161,   120,     6,    11,  -161,    96,    36,   246,
    -161,   370,  -161,  -161,  -161,  -161,   370,    36,  -161,  -161,
    -161,   121,   544,  -161,   246,  -161,  -161,  -161
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,    47,    83,    84,     0,     0,     0,     0,     0,     0,
       0,     0,    85,    86,    87,     0,     0,     0,     0,     0,
      62,     0,    17,     0,     2,     5,     0,     0,    32,    18,
      40,    42,    50,    43,    44,    16,    46,     7,     8,     9,
      10,    11,    12,    35,     0,    36,     0,    38,    48,    49,
       0,    80,     0,     0,    62,    97,     0,     0,     0,     0,
      64,     0,     0,    70,    34,     1,     4,    72,    14,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     6,    37,    39,     0,    62,     0,     0,     0,
      56,    58,    59,    62,     0,     0,    76,    88,     0,     0,
       0,    98,    33,    45,     0,     0,    63,    66,    67,     0,
      68,    75,    13,    15,    30,    31,    26,    27,    28,    29,
      21,    22,    23,    19,    20,    24,    25,     0,     0,     0,
      51,    41,     0,    53,     0,    88,    90,     0,    13,    13,
       0,    62,     0,    64,    70,    13,    62,    60,    52,    55,
       0,     0,     0,    89,    81,    93,    95,     0,     0,     0,
      65,    69,    73,     0,     0,     0,    77,    90,     0,    13,
      92,    62,    57,    71,    74,    61,     0,     0,    91,    82,
      94,     0,     0,    78,    13,    54,    79,    96
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -161,  -161,    47,   -23,  -161,  -161,    -6,  -161,  -161,  -161,
      -5,  -161,  -161,    -3,  -161,  -161,  -161,   -48,    17,  -161,
    -161,    19,    53,  -160,  -161,  -161,   -10,  -161,  -161,  -161,
    -161,  -161,  -161,    31,     0,  -161,  -161,  -161,  -161,  -161
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    23,    24,    25,    26,   113,    27,    28,    29,    30,
      31,    32,   150,    33,    90,    91,    92,    61,   106,    34,
      62,   110,    63,    68,   112,   174,    35,   135,   177,   186,
      97,   168,    36,   137,   153,    37,   170,    38,    39,    40
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      43,    66,    45,    47,    46,    46,   100,    50,   179,    58,
      41,    42,    56,    57,    60,    64,    93,   183,    69,    70,
      94,    71,    72,    73,    74,    85,    69,    70,    48,    71,
      72,    73,    74,    51,    95,    86,    49,    87,   128,    88,
      93,    52,   176,    53,    94,   132,    98,    99,    60,    78,
      79,    80,    81,   104,    75,    76,    77,    78,    79,    80,
      81,    54,    82,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,    65,     1,     2,     3,
      60,   129,    67,   131,     6,    11,     1,    60,    96,     7,
       8,     9,    10,   158,   103,    12,    13,    14,   163,   143,
       9,    10,   107,    19,   108,    20,   109,   127,   111,   130,
     133,   134,    44,   136,    21,   155,   156,   140,   141,   146,
      59,    59,    66,   181,    69,    70,    70,    71,    72,    73,
      74,   147,    69,    70,   157,    60,   159,   -14,   -14,   149,
      60,   152,   154,   166,   167,   164,   180,   165,   169,   172,
     175,   184,    75,    76,    77,    78,    79,    80,    81,   145,
     160,   187,   144,   161,   173,    60,   151,   178,     0,     0,
     182,     1,     2,     3,     4,     5,     0,     0,     6,     0,
       0,     0,     0,     7,     8,     9,    10,     0,    11,    12,
      13,    14,    15,     0,    16,    17,    18,    19,     0,    20,
       0,     0,     0,     0,     0,     0,     0,     0,    21,     0,
       0,     0,    22,     0,     0,     0,   162,     1,     2,     3,
       4,     5,     0,     0,     6,     0,     0,     0,     0,     7,
       8,     9,    10,     0,    11,    12,    13,    14,    15,     0,
      16,    17,    18,    19,     0,    20,     0,     0,     0,     1,
       2,     3,     4,     5,    21,     0,     6,     0,    22,     0,
     -13,     7,     8,     9,    10,     0,    11,    12,    13,    14,
      15,     0,    16,    17,    18,    19,     0,    20,     0,     0,
       1,     2,     3,     0,     0,     0,    21,     6,     0,     0,
      22,     0,     7,     8,     9,    10,     0,     0,    12,    13,
      14,     0,     0,     0,     0,     0,    19,     0,    20,    69,
      70,     0,    71,    72,    73,    74,     0,    21,     0,    69,
      70,    55,   -14,   -14,    73,    74,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    75,    76,    77,
      78,    79,    80,    81,     1,     2,     3,     0,   142,     0,
       0,     6,   -14,   -14,     0,     0,     7,     8,     9,    10,
       0,    11,    12,    13,    14,     0,     0,     0,     0,     0,
      19,     0,    20,     1,     2,     3,     0,     0,     0,     0,
       6,    21,     0,     0,     0,     7,     8,     9,    10,     0,
       0,    12,    13,    14,     0,     0,     0,     0,     0,    19,
       0,    20,    69,    70,     0,    71,    72,    73,    74,     0,
      21,     0,    69,    70,     0,    71,    72,    73,    74,     0,
       0,    69,    70,     0,    71,    72,    73,    74,     0,     0,
      75,    76,    77,    78,    79,    80,    81,     0,     0,   105,
      75,    76,    77,    78,    79,    80,    81,     0,   101,    75,
      76,    77,    78,    79,    80,    81,     0,   171,    69,    70,
       0,    71,    72,    73,    74,     0,     0,     0,     0,     0,
       0,    69,    70,     0,    71,    72,    73,    74,     0,     0,
     102,     0,     0,     0,     0,     0,    75,    76,    77,    78,
      79,    80,    81,   138,     0,     0,     0,     0,     0,    75,
      76,    77,    78,    79,    80,    81,    69,    70,     0,    71,
      72,    73,    74,     0,     0,    83,    84,    69,    70,    85,
      71,    72,    73,    74,     0,     0,     0,     0,   139,    86,
       0,    87,     0,    88,    75,    76,    77,    78,    79,    80,
      81,   148,     0,    89,     0,    75,    76,    77,    78,    79,
      80,    81,    69,    70,     0,    71,    72,    73,    74,    69,
      70,     0,    71,    72,    73,    74,    69,    70,     0,    71,
      72,    73,    74,     0,     0,     0,   185,     0,     0,     0,
      75,    76,    77,    78,    79,    80,    81,    75,    76,    77,
      78,    79,    80,    81,     0,     0,     0,     0,     0,    80,
      81
};

static const yytype_int16 yycheck[] =
{
       6,    24,     7,     8,     7,     8,    54,     3,   168,    19,
      44,    44,    18,    19,    20,    21,    29,   177,     8,     9,
      33,    11,    12,    13,    14,    19,     8,     9,     3,    11,
      12,    13,    14,    29,    44,    29,     3,    31,    86,    33,
      29,    29,    31,    29,    33,    93,    52,    53,    54,    39,
      40,    41,    42,    59,    36,    37,    38,    39,    40,    41,
      42,    29,    44,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,     0,     3,     4,     5,
      86,    87,    46,    89,    10,    20,     3,    93,    29,    15,
      16,    17,    18,   141,    30,    21,    22,    23,   146,   105,
      17,    18,    32,    29,    32,    31,    45,     3,    48,     3,
       3,    30,    29,     3,    40,   138,   139,    44,    29,    29,
      46,    46,   145,   171,     8,     9,     9,    11,    12,    13,
      14,    30,     8,     9,   140,   141,   142,    13,    14,    30,
     146,    45,    30,    30,     3,   150,   169,   150,    25,    30,
      30,    30,    36,    37,    38,    39,    40,    41,    42,   112,
     143,   184,   109,   144,    48,   171,   135,   167,    -1,    -1,
     176,     3,     4,     5,     6,     7,    -1,    -1,    10,    -1,
      -1,    -1,    -1,    15,    16,    17,    18,    -1,    20,    21,
      22,    23,    24,    -1,    26,    27,    28,    29,    -1,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,
      -1,    -1,    44,    -1,    -1,    -1,    48,     3,     4,     5,
       6,     7,    -1,    -1,    10,    -1,    -1,    -1,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    24,    -1,
      26,    27,    28,    29,    -1,    31,    -1,    -1,    -1,     3,
       4,     5,     6,     7,    40,    -1,    10,    -1,    44,    -1,
      46,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      24,    -1,    26,    27,    28,    29,    -1,    31,    -1,    -1,
       3,     4,     5,    -1,    -1,    -1,    40,    10,    -1,    -1,
      44,    -1,    15,    16,    17,    18,    -1,    -1,    21,    22,
      23,    -1,    -1,    -1,    -1,    -1,    29,    -1,    31,     8,
       9,    -1,    11,    12,    13,    14,    -1,    40,    -1,     8,
       9,    44,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,
      39,    40,    41,    42,     3,     4,     5,    -1,    47,    -1,
      -1,    10,    41,    42,    -1,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      29,    -1,    31,     3,     4,     5,    -1,    -1,    -1,    -1,
      10,    40,    -1,    -1,    -1,    15,    16,    17,    18,    -1,
      -1,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,    29,
      -1,    31,     8,     9,    -1,    11,    12,    13,    14,    -1,
      40,    -1,     8,     9,    -1,    11,    12,    13,    14,    -1,
      -1,     8,     9,    -1,    11,    12,    13,    14,    -1,    -1,
      36,    37,    38,    39,    40,    41,    42,    -1,    -1,    45,
      36,    37,    38,    39,    40,    41,    42,    -1,    44,    36,
      37,    38,    39,    40,    41,    42,    -1,    44,     8,     9,
      -1,    11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,     8,     9,    -1,    11,    12,    13,    14,    -1,    -1,
      30,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,    39,
      40,    41,    42,    30,    -1,    -1,    -1,    -1,    -1,    36,
      37,    38,    39,    40,    41,    42,     8,     9,    -1,    11,
      12,    13,    14,    -1,    -1,    15,    16,     8,     9,    19,
      11,    12,    13,    14,    -1,    -1,    -1,    -1,    30,    29,
      -1,    31,    -1,    33,    36,    37,    38,    39,    40,    41,
      42,    32,    -1,    43,    -1,    36,    37,    38,    39,    40,
      41,    42,     8,     9,    -1,    11,    12,    13,    14,     8,
       9,    -1,    11,    12,    13,    14,     8,     9,    -1,    11,
      12,    13,    14,    -1,    -1,    -1,    32,    -1,    -1,    -1,
      36,    37,    38,    39,    40,    41,    42,    36,    37,    38,
      39,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,    41,
      42
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,    10,    15,    16,    17,
      18,    20,    21,    22,    23,    24,    26,    27,    28,    29,
      31,    40,    44,    50,    51,    52,    53,    55,    56,    57,
      58,    59,    60,    62,    68,    75,    81,    84,    86,    87,
      88,    44,    44,    55,    29,    59,    62,    59,     3,     3,
       3,    29,    29,    29,    29,    44,    55,    55,    75,    46,
      55,    66,    69,    71,    55,     0,    52,    46,    72,     8,
       9,    11,    12,    13,    14,    36,    37,    38,    39,    40,
      41,    42,    44,    15,    16,    19,    29,    31,    33,    43,
      63,    64,    65,    29,    33,    75,    29,    79,    55,    55,
      66,    44,    30,    30,    55,    45,    67,    32,    32,    45,
      70,    48,    73,    54,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,     3,    66,    55,
       3,    55,    66,     3,    30,    76,     3,    82,    30,    30,
      44,    29,    47,    55,    71,    51,    29,    30,    32,    30,
      61,    82,    45,    83,    30,    52,    52,    55,    66,    55,
      67,    70,    48,    66,    59,    62,    30,     3,    80,    25,
      85,    44,    30,    48,    74,    30,    31,    77,    83,    72,
      52,    66,    55,    72,    30,    32,    78,    52
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    50,    51,    51,    52,    52,    52,    52,
      52,    52,    52,    53,    54,    52,    52,    52,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    56,    56,    56,    56,    56,    56,    56,
      56,    57,    58,    58,    58,    58,    58,    59,    59,    59,
      59,    60,    60,    61,    60,    62,    62,    62,    63,    63,
      64,    65,    66,    66,    67,    67,    68,    68,    69,    70,
      70,    71,    73,    74,    72,    72,    76,    77,    78,    75,
      79,    80,    75,    81,    81,    81,    81,    81,    82,    82,
      83,    83,    84,    85,    85,    86,    87,    88,    88
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     2,     1,     1,     1,
       1,     2,     2,     0,     0,     3,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     3,     2,     2,     2,     2,     2,     2,
       1,     3,     1,     1,     1,     3,     1,     1,     2,     2,
       1,     3,     4,     0,     8,     4,     2,     6,     1,     1,
       3,     5,     0,     2,     0,     3,     3,     3,     2,     3,
       0,     5,     0,     0,     5,     2,     0,     0,     0,     9,
       0,     0,     7,     1,     1,     1,     1,     1,     0,     2,
       0,     3,     6,     0,     2,     5,     9,     2,     3
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
#line 54 "syntax.y" /* yacc.c:1646  */
    {printf("Program started\n");}
#line 1498 "parser.c" /* yacc.c:1646  */
    break;

  case 3:
#line 55 "syntax.y" /* yacc.c:1646  */
    {printf("Program did not start\n");}
#line 1504 "parser.c" /* yacc.c:1646  */
    break;

  case 6:
#line 62 "syntax.y" /* yacc.c:1646  */
    {printf("stmt:Expression with ';' in line:%d\n",yylineno);}
#line 1510 "parser.c" /* yacc.c:1646  */
    break;

  case 7:
#line 63 "syntax.y" /* yacc.c:1646  */
    {printf("stmt:ifstmt starts in line:%d\n",yylineno);}
#line 1516 "parser.c" /* yacc.c:1646  */
    break;

  case 8:
#line 64 "syntax.y" /* yacc.c:1646  */
    {printf("stmt:whilestmt starts in line:%d\n",yylineno);}
#line 1522 "parser.c" /* yacc.c:1646  */
    break;

  case 9:
#line 65 "syntax.y" /* yacc.c:1646  */
    {printf("stmt:forstmt starts in line:%d\n",yylineno);}
#line 1528 "parser.c" /* yacc.c:1646  */
    break;

  case 10:
#line 66 "syntax.y" /* yacc.c:1646  */
    {printf("stmt:returnstmt starts in line:%d\n",yylineno);}
#line 1534 "parser.c" /* yacc.c:1646  */
    break;

  case 11:
#line 67 "syntax.y" /* yacc.c:1646  */
    {printf("stmt:Break with ';' in line:%d\n",yylineno);}
#line 1540 "parser.c" /* yacc.c:1646  */
    break;

  case 12:
#line 68 "syntax.y" /* yacc.c:1646  */
    {printf("stmt:Continue with ';' in line:%d\n",yylineno);}
#line 1546 "parser.c" /* yacc.c:1646  */
    break;

  case 13:
#line 69 "syntax.y" /* yacc.c:1646  */
    {scopeAccessStack.push(false);}
#line 1552 "parser.c" /* yacc.c:1646  */
    break;

  case 14:
#line 69 "syntax.y" /* yacc.c:1646  */
    {scopeAccessStack.pop();}
#line 1558 "parser.c" /* yacc.c:1646  */
    break;

  case 15:
#line 69 "syntax.y" /* yacc.c:1646  */
    {printf("stmt:block starts in line:%d\n",yylineno);}
#line 1564 "parser.c" /* yacc.c:1646  */
    break;

  case 16:
#line 70 "syntax.y" /* yacc.c:1646  */
    {printf("stmt:funcdef starts in line:%d\n",yylineno);}
#line 1570 "parser.c" /* yacc.c:1646  */
    break;

  case 17:
#line 71 "syntax.y" /* yacc.c:1646  */
    {printf("stmt:SEMICOLON in line:%d\n",yylineno);}
#line 1576 "parser.c" /* yacc.c:1646  */
    break;

  case 18:
#line 74 "syntax.y" /* yacc.c:1646  */
    {printf("expr:assignexpr in line:%d\n",yylineno);}
#line 1582 "parser.c" /* yacc.c:1646  */
    break;

  case 19:
#line 75 "syntax.y" /* yacc.c:1646  */
    {printf("expr:expr + expr in line:%d\n",yylineno);}
#line 1588 "parser.c" /* yacc.c:1646  */
    break;

  case 20:
#line 76 "syntax.y" /* yacc.c:1646  */
    {printf("expr:expr - expr in line:%d\n",yylineno);}
#line 1594 "parser.c" /* yacc.c:1646  */
    break;

  case 21:
#line 77 "syntax.y" /* yacc.c:1646  */
    {printf("expr:expr * expr in line:%d\n",yylineno);}
#line 1600 "parser.c" /* yacc.c:1646  */
    break;

  case 22:
#line 78 "syntax.y" /* yacc.c:1646  */
    {printf("expr:expr / expr in line:%d\n",yylineno);}
#line 1606 "parser.c" /* yacc.c:1646  */
    break;

  case 23:
#line 79 "syntax.y" /* yacc.c:1646  */
    {printf("expr:expr mod expr in line:%d\n",yylineno);}
#line 1612 "parser.c" /* yacc.c:1646  */
    break;

  case 24:
#line 80 "syntax.y" /* yacc.c:1646  */
    {printf("expr:expr > expr in line:%d\n",yylineno);}
#line 1618 "parser.c" /* yacc.c:1646  */
    break;

  case 25:
#line 81 "syntax.y" /* yacc.c:1646  */
    {printf("expr:expr < expr in line:%d\n",yylineno);}
#line 1624 "parser.c" /* yacc.c:1646  */
    break;

  case 26:
#line 82 "syntax.y" /* yacc.c:1646  */
    {printf("expr:expr >= expr in line:%d\n",yylineno);}
#line 1630 "parser.c" /* yacc.c:1646  */
    break;

  case 27:
#line 83 "syntax.y" /* yacc.c:1646  */
    {printf("expr:expr <= expr in line:%d\n",yylineno);}
#line 1636 "parser.c" /* yacc.c:1646  */
    break;

  case 28:
#line 84 "syntax.y" /* yacc.c:1646  */
    {printf("expr:expr ==(EQUAL) expr in line:%d\n",yylineno);}
#line 1642 "parser.c" /* yacc.c:1646  */
    break;

  case 29:
#line 85 "syntax.y" /* yacc.c:1646  */
    {printf("expr:expr != expr in line:%d\n",yylineno);}
#line 1648 "parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 86 "syntax.y" /* yacc.c:1646  */
    {printf("expr:expr AND expr in line:%d\n",yylineno);}
#line 1654 "parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 87 "syntax.y" /* yacc.c:1646  */
    {printf("expr:expr OR expr in line:%d\n",yylineno);}
#line 1660 "parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 88 "syntax.y" /* yacc.c:1646  */
    {printf("expr:term in line:%d\n",yylineno);}
#line 1666 "parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 93 "syntax.y" /* yacc.c:1646  */
    {printf("term:(expr) in line:%d\n",yylineno);}
#line 1672 "parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 94 "syntax.y" /* yacc.c:1646  */
    {{printf("term:-expr in line:%d\n",yylineno);}}
#line 1678 "parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 95 "syntax.y" /* yacc.c:1646  */
    {printf("term:!expr in line:%d\n",yylineno);}
#line 1684 "parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 96 "syntax.y" /* yacc.c:1646  */
    {printf("term:++lvalue in line:%d\n",yylineno);}
#line 1690 "parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 97 "syntax.y" /* yacc.c:1646  */
    {printf("term:lvalue++ in line:%d\n",yylineno);}
#line 1696 "parser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 98 "syntax.y" /* yacc.c:1646  */
    {printf("term:--lvalue in line:%d\n",yylineno);}
#line 1702 "parser.c" /* yacc.c:1646  */
    break;

  case 39:
#line 99 "syntax.y" /* yacc.c:1646  */
    {printf("term:lvalue-- in line:%d\n",yylineno);}
#line 1708 "parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 100 "syntax.y" /* yacc.c:1646  */
    {printf("term:primary in line:%d\n",yylineno);}
#line 1714 "parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 103 "syntax.y" /* yacc.c:1646  */
    {printf("assignexpr:lvalue=expr in line:%d\n",yylineno);}
#line 1720 "parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 106 "syntax.y" /* yacc.c:1646  */
    {printf("primary: lvalue in line:%d\n",yylineno);}
#line 1726 "parser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 107 "syntax.y" /* yacc.c:1646  */
    {printf("primary: call in line:%d\n",yylineno);}
#line 1732 "parser.c" /* yacc.c:1646  */
    break;

  case 44:
#line 108 "syntax.y" /* yacc.c:1646  */
    {printf("primary: objectdef in line:%d\n",yylineno);}
#line 1738 "parser.c" /* yacc.c:1646  */
    break;

  case 45:
#line 109 "syntax.y" /* yacc.c:1646  */
    {printf("primary: (funcdef) in line:%d\n",yylineno);}
#line 1744 "parser.c" /* yacc.c:1646  */
    break;

  case 46:
#line 110 "syntax.y" /* yacc.c:1646  */
    {printf("primary: const in line:%d\n",yylineno);}
#line 1750 "parser.c" /* yacc.c:1646  */
    break;

  case 47:
#line 113 "syntax.y" /* yacc.c:1646  */
    {printf("lvalue: ID in line:%d\n",yylineno);
										 
										 symTableEntry* ptr = lookupSym((yyvsp[0].stringValue));
										 // symbol doesn't exist
										 if(lvalueCheckSym(ptr,current_scope,yylineno)){
										 	symTableType type;
										 	if(current_scope == 0){
										 		type = GLOBAL_VAR;
										 	}else{
										 		type = LOCAL_VAR;
										 	}
										 	if( !ptr || (!scopeAccessStack.top() && ptr->symType != LOCAL_VAR && ptr->symType != ARGUMENT_VAR && (ptr->scope == current_scope || ptr->scope == 0))){
										 		insertSym((yyvsp[0].stringValue),type,NULL,current_scope,yylineno);
										 	}else{
												printf("ERROR cannot access %s in scope %d\n",ptr->name, ptr->scope);
											}
										 }
										}
#line 1773 "parser.c" /* yacc.c:1646  */
    break;

  case 48:
#line 131 "syntax.y" /* yacc.c:1646  */
    {	printf("lvalue: LOCAL ID in line:%d\n",yylineno);
											symTableEntry* ptr = lookupSym((yyvsp[0].stringValue),current_scope);
											
											if(lvalueCheckSym(ptr,current_scope, yylineno)){
												symTableType type;
										 		if(current_scope == 0){
										 			type = GLOBAL_VAR;
										 		}else{
										 			type = LOCAL_VAR;
										 		}
												insertSym((yyvsp[0].stringValue),type,NULL,current_scope,yylineno);			
											}
										}
#line 1791 "parser.c" /* yacc.c:1646  */
    break;

  case 49:
#line 144 "syntax.y" /* yacc.c:1646  */
    {	printf("lvalue: SCOPE ID in line:%d\n",yylineno);
											symTableEntry* ptr = lookupSym((yyvsp[0].stringValue),0);
											if(lvalueCheckSym(ptr,0,yylineno)){
												printf("ERROR there is no global var %s\n",(yyvsp[0].stringValue));	
											}else{
												if(ptr->declLine == 0){

												}
												/*TODO: print symbol data*/
											}	
										}
#line 1807 "parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 155 "syntax.y" /* yacc.c:1646  */
    {printf("lvalue: member in line:%d\n",yylineno);}
#line 1813 "parser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 158 "syntax.y" /* yacc.c:1646  */
    {printf("member: lvalue.ID in line:%d\n",yylineno);}
#line 1819 "parser.c" /* yacc.c:1646  */
    break;

  case 52:
#line 159 "syntax.y" /* yacc.c:1646  */
    {printf("member: lvalue [expr] in line:%d\n",yylineno);}
#line 1825 "parser.c" /* yacc.c:1646  */
    break;

  case 53:
#line 160 "syntax.y" /* yacc.c:1646  */
    {printf("member: call.ID in line:%d\n",yylineno);}
#line 1831 "parser.c" /* yacc.c:1646  */
    break;

  case 54:
#line 161 "syntax.y" /* yacc.c:1646  */
    {printf("member: call [expr] in line:%d\n",yylineno);}
#line 1837 "parser.c" /* yacc.c:1646  */
    break;

  case 55:
#line 164 "syntax.y" /* yacc.c:1646  */
    {printf("call: (elist) in line:%d\n",yylineno);}
#line 1843 "parser.c" /* yacc.c:1646  */
    break;

  case 56:
#line 165 "syntax.y" /* yacc.c:1646  */
    {printf("call: lvalue callsuffix in line:%d\n",yylineno);}
#line 1849 "parser.c" /* yacc.c:1646  */
    break;

  case 57:
#line 166 "syntax.y" /* yacc.c:1646  */
    {printf("call: (func) (elist) in line:%d\n",yylineno);}
#line 1855 "parser.c" /* yacc.c:1646  */
    break;

  case 58:
#line 169 "syntax.y" /* yacc.c:1646  */
    {printf("callsuffix: normcall in line:%d\n",yylineno);}
#line 1861 "parser.c" /* yacc.c:1646  */
    break;

  case 59:
#line 170 "syntax.y" /* yacc.c:1646  */
    {printf("callsuffix: methodcall in line:%d\n",yylineno);}
#line 1867 "parser.c" /* yacc.c:1646  */
    break;

  case 60:
#line 173 "syntax.y" /* yacc.c:1646  */
    {printf("normcall: (elist) in line:%d\n",yylineno);}
#line 1873 "parser.c" /* yacc.c:1646  */
    break;

  case 61:
#line 176 "syntax.y" /* yacc.c:1646  */
    {printf("methodcall: DOUPLEDOT ID (elist) in line:%d\n",yylineno);}
#line 1879 "parser.c" /* yacc.c:1646  */
    break;

  case 62:
#line 179 "syntax.y" /* yacc.c:1646  */
    {printf("elist: empty list in line:%d\n",yylineno);}
#line 1885 "parser.c" /* yacc.c:1646  */
    break;

  case 63:
#line 180 "syntax.y" /* yacc.c:1646  */
    {printf("elist: expr elist1 list in line:%d\n",yylineno);}
#line 1891 "parser.c" /* yacc.c:1646  */
    break;

  case 64:
#line 183 "syntax.y" /* yacc.c:1646  */
    {printf("elist1: empty list in line:%d\n",yylineno);}
#line 1897 "parser.c" /* yacc.c:1646  */
    break;

  case 65:
#line 184 "syntax.y" /* yacc.c:1646  */
    {printf("elist1: ,expr elist1 in line:%d\n",yylineno);}
#line 1903 "parser.c" /* yacc.c:1646  */
    break;

  case 66:
#line 187 "syntax.y" /* yacc.c:1646  */
    {printf("objectdef: [elist] in line:%d\n",yylineno);}
#line 1909 "parser.c" /* yacc.c:1646  */
    break;

  case 67:
#line 188 "syntax.y" /* yacc.c:1646  */
    {printf("objectdef: [indexed] in line:%d\n",yylineno);}
#line 1915 "parser.c" /* yacc.c:1646  */
    break;

  case 68:
#line 192 "syntax.y" /* yacc.c:1646  */
    {printf("indexed: indexedelem more in line:%d\n",yylineno);}
#line 1921 "parser.c" /* yacc.c:1646  */
    break;

  case 69:
#line 195 "syntax.y" /* yacc.c:1646  */
    {printf("more: ,indexedelem more in line:%d\n",yylineno);}
#line 1927 "parser.c" /* yacc.c:1646  */
    break;

  case 70:
#line 196 "syntax.y" /* yacc.c:1646  */
    {printf("more: empty in line:%d\n",yylineno);}
#line 1933 "parser.c" /* yacc.c:1646  */
    break;

  case 71:
#line 200 "syntax.y" /* yacc.c:1646  */
    {printf("indexedelem: {expr:expr} in line:%d\n",yylineno);}
#line 1939 "parser.c" /* yacc.c:1646  */
    break;

  case 72:
#line 203 "syntax.y" /* yacc.c:1646  */
    {current_scope++;}
#line 1945 "parser.c" /* yacc.c:1646  */
    break;

  case 73:
#line 203 "syntax.y" /* yacc.c:1646  */
    {hideSym(current_scope--);}
#line 1951 "parser.c" /* yacc.c:1646  */
    break;

  case 74:
#line 203 "syntax.y" /* yacc.c:1646  */
    {printf("block: {stmt1} in line:%d\n",yylineno);}
#line 1957 "parser.c" /* yacc.c:1646  */
    break;

  case 75:
#line 204 "syntax.y" /* yacc.c:1646  */
    {printf("funcdefblock: {} in line:%d\n",yylineno);}
#line 1963 "parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 207 "syntax.y" /* yacc.c:1646  */
    {current_scope++;}
#line 1969 "parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 207 "syntax.y" /* yacc.c:1646  */
    {current_scope--; scopeAccessStack.push(true);}
#line 1975 "parser.c" /* yacc.c:1646  */
    break;

  case 78:
#line 207 "syntax.y" /* yacc.c:1646  */
    {scopeAccessStack.pop();}
#line 1981 "parser.c" /* yacc.c:1646  */
    break;

  case 79:
#line 208 "syntax.y" /* yacc.c:1646  */
    {
													printf("funcdef: FUNCTION ID (idlist) block in line:%d\n",yylineno);
													symTableEntry* ptr = lookupSym((yyvsp[-7].stringValue));
													/*TODO:take idlist argument list and pass it to insertSym*/
													if(ptr == NULL){
														insertSym((yyvsp[-7].stringValue),USER_FUNC,NULL,current_scope,yylineno);
													}else{
														printf("ERROR: Symbol %s already defined at line %d\n",(yyvsp[-7].stringValue),yylineno);
													}
												}
#line 1996 "parser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 218 "syntax.y" /* yacc.c:1646  */
    {current_scope++;}
#line 2002 "parser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 218 "syntax.y" /* yacc.c:1646  */
    {current_scope--; scopeAccessStack.push(true);}
#line 2008 "parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 219 "syntax.y" /* yacc.c:1646  */
    {
													scopeAccessStack.pop();
													printf("funcdef: FUNCTION (idlist) block in line:%d\n",yylineno);
													
													std::string anonFunc = "_anonFunc" + std::to_string(anonymousCounter++);
													insertSym(anonFunc,USER_FUNC,NULL,current_scope,yylineno);
												}
#line 2020 "parser.c" /* yacc.c:1646  */
    break;

  case 87:
#line 228 "syntax.y" /* yacc.c:1646  */
    {printf("const: NUMBER | STRING | NIL |TRUE|FALSE in line:%d\n",yylineno);}
#line 2026 "parser.c" /* yacc.c:1646  */
    break;

  case 88:
#line 231 "syntax.y" /* yacc.c:1646  */
    {printf("idlist: empty in line:%d\n",yylineno);}
#line 2032 "parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 232 "syntax.y" /* yacc.c:1646  */
    {printf("idlist: ID idlist1 in line:%d\n",yylineno);}
#line 2038 "parser.c" /* yacc.c:1646  */
    break;

  case 90:
#line 235 "syntax.y" /* yacc.c:1646  */
    {printf("idlist1: empty in line:%d\n",yylineno);}
#line 2044 "parser.c" /* yacc.c:1646  */
    break;

  case 91:
#line 236 "syntax.y" /* yacc.c:1646  */
    {printf("idlist1: ,ID idlist1 in line:%d\n",yylineno);}
#line 2050 "parser.c" /* yacc.c:1646  */
    break;

  case 92:
#line 239 "syntax.y" /* yacc.c:1646  */
    {printf("ifstmt: IF (expr) stmt ifstmt1 in line:%d\n",yylineno);}
#line 2056 "parser.c" /* yacc.c:1646  */
    break;

  case 93:
#line 242 "syntax.y" /* yacc.c:1646  */
    {printf("ifstmt1: empty in line:%d\n",yylineno);}
#line 2062 "parser.c" /* yacc.c:1646  */
    break;

  case 94:
#line 243 "syntax.y" /* yacc.c:1646  */
    {printf("ifstmt1: ELSE stmt in line:%d\n",yylineno);}
#line 2068 "parser.c" /* yacc.c:1646  */
    break;

  case 95:
#line 246 "syntax.y" /* yacc.c:1646  */
    {printf("whilestmt: WHILE (expr) stmt in line:%d\n",yylineno);}
#line 2074 "parser.c" /* yacc.c:1646  */
    break;

  case 96:
#line 249 "syntax.y" /* yacc.c:1646  */
    {printf("forstmt: FOR (elist;expr;elist) stmt in 								;											line:%d\n",yylineno);}
#line 2080 "parser.c" /* yacc.c:1646  */
    break;

  case 97:
#line 251 "syntax.y" /* yacc.c:1646  */
    {printf("returnstmt: RETURN; in line:%d",yylineno);}
#line 2086 "parser.c" /* yacc.c:1646  */
    break;

  case 98:
#line 252 "syntax.y" /* yacc.c:1646  */
    {printf("returnstmt: RETURN expr; in line:%d",yylineno);}
#line 2092 "parser.c" /* yacc.c:1646  */
    break;


#line 2096 "parser.c" /* yacc.c:1646  */
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
#line 255 "syntax.y" /* yacc.c:1906  */


void yyerror(const char *yaccProvideMessage){
	fprintf(stdout,"%s: at line %d, before token: %s\n",yaccProvideMessage,yylineno,yytext);
	fprintf(stdout,"INPUT NOT VALID");

}
