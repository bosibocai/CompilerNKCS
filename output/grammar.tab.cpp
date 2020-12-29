/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 16 "grammar.y"

    #include <stdlib.h>
    #include <stdio.h>
    #include <string>
    #include <fstream>
    #include <cstring>
    #include <string.h>
    #include <iostream>
    #include "../in.h"
    #include "../common/util/AsmGenerator.h"
    #include "../common/util/InterMediate.h"
    #include "../common/tools.h"
    class ASTNode; // 数据类型定义：定义语义动作使用到的数据类型
    extern int yylex(); 
    int yyerror(char* s);
    extern char* yytext;// 外部变量和全局变量定义
    extern FILE* yyin;
    ASTNode* root;

#line 90 "./output/grammar.tab.cpp"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_OUTPUT_GRAMMAR_TAB_H_INCLUDED
# define YY_YY_OUTPUT_GRAMMAR_TAB_H_INCLUDED
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
    ASSIGN = 258,
    NOT = 259,
    UMINUS = 260,
    ADDR = 261,
    ADD = 262,
    SUBTRACT = 263,
    MULTIPLY = 264,
    DIVIDE = 265,
    MOD = 266,
    POW = 267,
    AND = 268,
    OR = 269,
    RELOP = 270,
    LBRAKET = 271,
    RBRAKET = 272,
    LP = 273,
    RP = 274,
    LBRACE = 275,
    RBRACE = 276,
    SEMICOLON = 277,
    COMMA = 278,
    GETMEMBER = 279,
    RETURN = 280,
    IF = 281,
    ELSE = 282,
    ID = 283,
    INT = 284,
    TYPE = 285,
    MAIN = 286,
    FOR = 287,
    WHILE = 288,
    PRINTF = 289
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 67 "grammar.y"

    ASTNode* astNode;
    char* str;

#line 182 "./output/grammar.tab.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_OUTPUT_GRAMMAR_TAB_H_INCLUDED  */



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
typedef yytype_uint8 yy_state_t;

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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   510

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  16
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  143

#define YYUNDEFTOK  2
#define YYMAXUTOK   289


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   160,   160,   176,   179,   191,   196,   197,   207,   214,
     217,   224,   227,   233,   244,   262,   262,   276,   282,   289,
     295,   298,   304,   309,   314,   317,   322,   332,   346,   349,
     352,   355,   358,   361,   364,   367,   370,   373,   376,   379,
     385,   390,   396,   399,   406,   409,   416,   434,   442,   448,
     454,   461,   468,   475,   481,   487,   493,   499,   502,   507,
     510,   517,   523,   529,   541,   544
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ASSIGN", "NOT", "UMINUS", "ADDR", "ADD",
  "SUBTRACT", "MULTIPLY", "DIVIDE", "MOD", "POW", "AND", "OR", "RELOP",
  "LBRAKET", "RBRAKET", "LP", "RP", "LBRACE", "RBRACE", "SEMICOLON",
  "COMMA", "GETMEMBER", "RETURN", "IF", "ELSE", "ID", "INT", "TYPE",
  "MAIN", "FOR", "WHILE", "PRINTF", "$accept", "prog", "extDefList",
  "extDef", "extDecList", "specifier", "varDec", "compd", "$@1", "stmts",
  "initFor", "stmt", "def", "decList", "dec", "expr", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289
};
# endif

#define YYPACT_NINF (-54)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-42)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       3,   -11,     5,    16,    17,   -54,    -9,   -54,   -54,   -54,
     -54,   -54,     7,     8,    38,   -54,    20,    13,   -54,    23,
      37,     0,   -54,   -54,    47,   -54,   -54,   -54,   -54,    75,
      36,   234,    42,   247,   234,   -54,   141,    55,    62,   -54,
      67,    88,    92,    23,   -54,   -54,    94,   270,   -54,   102,
      95,   486,   -54,    62,    51,   334,   -54,   286,   234,   234,
     111,   234,   234,   125,   -54,   109,   -54,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   -54,   -54,
     -54,   348,   446,   -13,   156,   112,   -54,   476,   362,   376,
     234,    23,   476,   494,   494,    51,    51,    51,    76,   115,
     115,   119,   461,    93,   -54,   -54,     6,   302,   171,    93,
     114,   476,   -54,   -54,   110,    93,   390,   186,   202,   318,
     -54,   -54,    93,   -54,    93,    93,   404,    93,   418,   218,
     -54,   -54,   -54,    93,   -54,    93,    93,   432,   -54,   -54,
     -54,    93,   -54
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    11,     0,     0,     3,     0,     8,    12,     1,
       4,     6,    13,     0,     0,     9,     0,     0,     5,     0,
       0,     0,    10,    14,     0,    15,     7,    17,    19,     0,
       0,     0,     0,     0,     0,    16,     0,     0,    63,    64,
       0,     0,     0,     0,    24,    18,     0,     0,    65,    39,
       0,    58,    61,    62,    56,     0,    26,     0,     0,     0,
       0,     0,     0,    44,    40,    42,    23,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    22,    57,
      27,     0,     0,     0,     0,     0,    20,    21,     0,     0,
       0,     0,    46,    50,    51,    52,    53,    54,    55,    47,
      48,    49,     0,     0,    60,    41,     0,     0,     0,     0,
       0,    45,    43,    59,    28,     0,     0,     0,     0,     0,
      30,    25,     0,    31,     0,     0,     0,     0,     0,     0,
      29,    34,    33,     0,    32,     0,     0,     0,    37,    36,
      35,     0,    38
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -54,   -54,   -54,   134,   -54,    48,     2,   122,   -54,   -54,
     -54,   -53,    84,    57,   -54,   -31
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,    14,    43,    63,    44,    28,    29,
      85,    45,    46,    64,    65,    47
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      51,    24,    54,    55,     1,    57,    48,    50,    15,   105,
      31,     7,    32,    11,     8,    33,     9,    -2,     1,    12,
      25,    22,    13,    16,    34,   115,    17,    81,    82,    87,
      88,    89,    21,     2,    38,    39,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,     2,     6,    20,
     114,    12,     6,   107,    23,    48,   120,    27,    49,   111,
      18,    19,   123,    73,    74,    75,    76,    77,    27,   130,
      52,   131,   132,    58,   134,   116,    30,   119,    59,    31,
     138,    32,   139,   140,    33,    60,   126,   128,   142,    74,
      75,    76,    77,    34,    30,    25,    35,    31,   137,    32,
      36,    37,    33,    38,    39,     2,    61,    40,    41,    42,
      62,    34,    83,    25,    48,    31,    66,    32,    36,    37,
      33,    38,    39,     2,   -41,    40,    41,    42,    90,    34,
      76,    77,    91,    84,   108,    77,   121,   122,    10,    38,
      39,     2,    50,    26,    86,    31,     0,    32,   112,     0,
      33,     0,     0,     0,     0,     0,     0,    50,     0,    34,
      31,     0,    32,    56,     0,    33,     0,     0,     0,    38,
      39,     0,    50,     0,    34,    31,     0,    32,   106,     0,
      33,     0,     0,     0,    38,    39,     0,    50,     0,    34,
      31,     0,    32,   118,     0,    33,     0,     0,     0,    38,
      39,     0,     0,    50,    34,   125,    31,     0,    32,     0,
       0,    33,     0,     0,    38,    39,     0,     0,     0,    50,
      34,   127,    31,     0,    32,     0,     0,    33,     0,     0,
      38,    39,     0,     0,     0,    50,    34,   136,    31,     0,
      32,     0,     0,    33,     0,     0,    38,    39,    50,     0,
       0,    31,    34,    32,     0,     0,    33,     0,     0,     0,
       0,     0,    38,    39,     0,    34,     0,     0,     0,     0,
       0,     0,     0,    67,     0,    53,    39,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,     0,     0,    67,
       0,     0,    78,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,     0,     0,    67,     0,     0,    80,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,     0,
       0,    67,     0,     0,   117,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,     0,     0,    67,     0,     0,
     129,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    67,     0,    79,     0,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    67,     0,   103,     0,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    67,
       0,   109,     0,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    67,     0,   110,     0,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    67,     0,   124,
       0,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    67,     0,   133,     0,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    67,     0,   135,     0,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    67,
       0,   141,     0,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,   104,    67,     0,     0,     0,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,   113,    67,
       0,     0,     0,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    70,    71,    72,    73,    74,    75,    76,
      77
};

static const yytype_int16 yycheck[] =
{
      31,     1,    33,    34,     1,    36,    19,     1,     6,    22,
       4,    22,     6,    22,     9,     9,     0,     0,     1,    28,
      20,    19,    31,    16,    18,    19,    18,    58,    59,    60,
      61,    62,    19,    30,    28,    29,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    30,     0,    29,
     103,    28,     4,    84,    17,    19,   109,    21,    22,    90,
      22,    23,   115,    12,    13,    14,    15,    16,    21,   122,
      28,   124,   125,    18,   127,   106,     1,   108,    16,     4,
     133,     6,   135,   136,     9,    18,   117,   118,   141,    13,
      14,    15,    16,    18,     1,    20,    21,     4,   129,     6,
      25,    26,     9,    28,    29,    30,    18,    32,    33,    34,
      18,    18,     1,    20,    19,     4,    22,     6,    25,    26,
       9,    28,    29,    30,    22,    32,    33,    34,     3,    18,
      15,    16,    23,    22,    22,    16,    22,    27,     4,    28,
      29,    30,     1,    21,    60,     4,    -1,     6,    91,    -1,
       9,    -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,    18,
       4,    -1,     6,    22,    -1,     9,    -1,    -1,    -1,    28,
      29,    -1,     1,    -1,    18,     4,    -1,     6,    22,    -1,
       9,    -1,    -1,    -1,    28,    29,    -1,     1,    -1,    18,
       4,    -1,     6,    22,    -1,     9,    -1,    -1,    -1,    28,
      29,    -1,    -1,     1,    18,    19,     4,    -1,     6,    -1,
      -1,     9,    -1,    -1,    28,    29,    -1,    -1,    -1,     1,
      18,    19,     4,    -1,     6,    -1,    -1,     9,    -1,    -1,
      28,    29,    -1,    -1,    -1,     1,    18,    19,     4,    -1,
       6,    -1,    -1,     9,    -1,    -1,    28,    29,     1,    -1,
      -1,     4,    18,     6,    -1,    -1,     9,    -1,    -1,    -1,
      -1,    -1,    28,    29,    -1,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,    -1,    28,    29,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    -1,     3,
      -1,    -1,    22,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,     3,    -1,    -1,    22,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,     3,    -1,    -1,    22,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,     3,    -1,    -1,
      22,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     3,    -1,    19,    -1,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,     3,    -1,    19,    -1,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,     3,
      -1,    19,    -1,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,     3,    -1,    19,    -1,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,     3,    -1,    19,
      -1,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     3,    -1,    19,    -1,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,     3,    -1,    19,    -1,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,     3,
      -1,    19,    -1,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,     3,    -1,    -1,    -1,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,     3,
      -1,    -1,    -1,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,     9,    10,    11,    12,    13,    14,    15,
      16
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,    30,    36,    37,    38,    40,    22,     9,     0,
      38,    22,    28,    31,    39,    41,    16,    18,    22,    23,
      29,    19,    41,    17,     1,    20,    42,    21,    43,    44,
       1,     4,     6,     9,    18,    21,    25,    26,    28,    29,
      32,    33,    34,    40,    42,    46,    47,    50,    19,    22,
       1,    50,    28,    28,    50,    50,    22,    50,    18,    16,
      18,    18,    18,    41,    48,    49,    22,     3,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    22,    19,
      22,    50,    50,     1,    22,    45,    47,    50,    50,    50,
       3,    23,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    19,    17,    22,    22,    50,    22,    19,
      19,    50,    48,    17,    46,    19,    50,    22,    22,    50,
      46,    22,    27,    46,    19,    19,    50,    19,    50,    22,
      46,    46,    46,    19,    46,    19,    19,    50,    46,    46,
      46,    19,    46
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    35,    36,    37,    37,    38,    38,    38,    38,    39,
      39,    40,    40,    41,    41,    43,    42,    42,    44,    44,
      45,    45,    46,    46,    46,    46,    46,    46,    46,    46,
      46,    46,    46,    46,    46,    46,    46,    46,    46,    46,
      47,    47,    48,    48,    49,    49,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     3,     2,     5,     2,     1,
       3,     1,     2,     1,     4,     0,     4,     2,     2,     0,
       1,     1,     2,     2,     1,     5,     2,     3,     5,     7,
       5,     6,     7,     7,     7,     8,     8,     8,     9,     2,
       2,     2,     1,     3,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     3,     2,     4,
       4,     2,     2,     1,     1,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 160 "grammar.y"
                  {
            root = new RootNode();
            root -> addChildNode((yyvsp[0].astNode));
        }
#line 1522 "./output/grammar.tab.cpp"
    break;

  case 3:
#line 176 "grammar.y"
              {
            (yyval.astNode) = (yyvsp[0].astNode);
        }
#line 1530 "./output/grammar.tab.cpp"
    break;

  case 4:
#line 179 "grammar.y"
                           {
            if((yyvsp[-1].astNode)==NULL)
                (yyval.astNode) = (yyvsp[0].astNode);
            else{
                if((yyvsp[0].astNode)!=NULL)
                    (yyvsp[-1].astNode)->getLastBrother()->addBrother((yyvsp[0].astNode));
                (yyval.astNode) = (yyvsp[-1].astNode);
            }
        }
#line 1544 "./output/grammar.tab.cpp"
    break;

  case 5:
#line 191 "grammar.y"
                                       {
            DefVarASTNode* var = (DefVarASTNode*)(yyvsp[-1].astNode);
            var->setSymbolType((yyvsp[-2].str));
            (yyval.astNode) = var;
        }
#line 1554 "./output/grammar.tab.cpp"
    break;

  case 6:
#line 196 "grammar.y"
                              {}
#line 1560 "./output/grammar.tab.cpp"
    break;

  case 7:
#line 197 "grammar.y"
                                     {
            Symbol* main = tempTable->insertSymbol("MAIN", Type::MAIN);
            if(main!=NULL){
                MainASTNode* var = new MainASTNode("main",(yyvsp[0].astNode));
                (yyval.astNode) = var;
            }
            else{
                yyerror((char*)"multi used MAIN");
            }
        }
#line 1575 "./output/grammar.tab.cpp"
    break;

  case 8:
#line 207 "grammar.y"
                          {
            yyerrok;
            (yyval.astNode) = NULL;
        }
#line 1584 "./output/grammar.tab.cpp"
    break;

  case 9:
#line 214 "grammar.y"
               {
            (yyval.astNode) = (yyvsp[0].astNode);
        }
#line 1592 "./output/grammar.tab.cpp"
    break;

  case 10:
#line 217 "grammar.y"
                                  {
            (yyvsp[-2].astNode)->getLastBrother()->addBrother((yyvsp[0].astNode));
            (yyval.astNode) = (yyvsp[-2].astNode);
        }
#line 1601 "./output/grammar.tab.cpp"
    break;

  case 11:
#line 224 "grammar.y"
            {
            (yyval.str) = (char*)"integer";
        }
#line 1609 "./output/grammar.tab.cpp"
    break;

  case 12:
#line 227 "grammar.y"
                        {
            (yyval.str) = (char*)"pointer";
        }
#line 1617 "./output/grammar.tab.cpp"
    break;

  case 13:
#line 233 "grammar.y"
           {
            Symbol* result = tempTable->insertSymbol((yyvsp[0].str),Type::integer);
            if(result!=NULL){
                DefVarASTNode* var = new DefVarASTNode((yyvsp[0].str));
                var->setTheTable(tempTable);
                (yyval.astNode) = var;
            } 
            else{
                yyerror((char*)"multi defined");
            } 
        }
#line 1633 "./output/grammar.tab.cpp"
    break;

  case 14:
#line 244 "grammar.y"
                                 {
            ASTNode* node = new DefVarASTNode((yyvsp[-3].str));
            Symbol* result = tempTable->insertArraySymbol((yyvsp[-3].str), atoi((yyvsp[-1].str)));
            if(result!=NULL){
                DefVarASTNode* var = (DefVarASTNode*) node;
                var -> setSymbolType((char*)"array",(yyvsp[-1].str));
                var -> setTheTable(tempTable);
                (yyval.astNode) = var;
            } 
            else {
                yyerror((char*)"multi defined");
            }
        }
#line 1651 "./output/grammar.tab.cpp"
    break;

  case 15:
#line 262 "grammar.y"
              {
            // tempTable: 指向当前符号表
            // flagTable: 找a具体在哪个table 
            tempTable = tempTable->createChildTable(false);
            flagTable = tempTable;
        }
#line 1662 "./output/grammar.tab.cpp"
    break;

  case 16:
#line 268 "grammar.y"
                    {
           ASTNode* node = new StmtASTNode(stmtType::compoundStmt);
           node -> addChildNode((yyvsp[-1].astNode));
           (yyval.astNode) = node;
           rootTable->setTotalOffsetFromRoot(tempTable->getTotalOffset());
           tempTable = tempTable->getFather();
           flagTable = tempTable;
        }
#line 1675 "./output/grammar.tab.cpp"
    break;

  case 17:
#line 276 "grammar.y"
                      {
           yyerrok;
       }
#line 1683 "./output/grammar.tab.cpp"
    break;

  case 18:
#line 282 "grammar.y"
                   {
            if((yyvsp[-1].astNode)==NULL)
                (yyval.astNode) = (yyvsp[0].astNode);
            else{
                (yyvsp[-1].astNode) -> getLastBrother() -> addBrother((yyvsp[0].astNode));
            }
        }
#line 1695 "./output/grammar.tab.cpp"
    break;

  case 19:
#line 289 "grammar.y"
          {
            (yyval.astNode) = NULL;
        }
#line 1703 "./output/grammar.tab.cpp"
    break;

  case 20:
#line 295 "grammar.y"
            {
            (yyval.astNode) = (yyvsp[0].astNode);
        }
#line 1711 "./output/grammar.tab.cpp"
    break;

  case 21:
#line 298 "grammar.y"
               {
            (yyval.astNode) = (yyvsp[0].astNode);
        }
#line 1719 "./output/grammar.tab.cpp"
    break;

  case 22:
#line 304 "grammar.y"
                       {
            ASTNode* temp = new StmtASTNode(stmtType::expStmt);
            temp -> addChildNode((yyvsp[-1].astNode));
            (yyval.astNode) = temp;
        }
#line 1729 "./output/grammar.tab.cpp"
    break;

  case 23:
#line 309 "grammar.y"
                        {
            ASTNode* temp = new StmtASTNode(stmtType::defStmt);
            temp -> addChildNode((yyvsp[-1].astNode));
            (yyval.astNode) = temp;
        }
#line 1739 "./output/grammar.tab.cpp"
    break;

  case 24:
#line 314 "grammar.y"
                {
            (yyval.astNode) = (yyvsp[0].astNode);
        }
#line 1747 "./output/grammar.tab.cpp"
    break;

  case 25:
#line 317 "grammar.y"
                                     {
            ASTNode* temp = new StmtASTNode(stmtType::printStmt);
            temp->addChildNode((yyvsp[-2].astNode));
            (yyval.astNode)=temp;
        }
#line 1757 "./output/grammar.tab.cpp"
    break;

  case 26:
#line 322 "grammar.y"
                           {
            // $$ = new StmtASTNode(stmtType::returnStmt);
            Symbol* sr = tempTable -> insertSymbol(std::string("RETURN"), Type::RETURN);
            if(sr!=NULL){
                (yyval.astNode) = new StmtASTNode(stmtType::returnStmt);
            } 
            else{
                yyerror((char*)"multi used RETURN");
            }
        }
#line 1772 "./output/grammar.tab.cpp"
    break;

  case 27:
#line 332 "grammar.y"
                                {
            // ASTNode* temp = new StmtASTNode(stmtType::returnStmt);
            // temp->addChildNode($2);
            // $$ = temp;
            Symbol* sr = tempTable -> insertSymbol("RETURN", Type::RETURN);
            if(sr!=NULL){
                ASTNode* temp = new StmtASTNode(stmtType::returnStmt);
                temp->addChildNode((yyvsp[-1].astNode));
                (yyval.astNode) = temp;
            } 
            else{
                yyerror((char*)"multi used RETURN");
            }
        }
#line 1791 "./output/grammar.tab.cpp"
    break;

  case 28:
#line 346 "grammar.y"
                             {
            (yyval.astNode) = new ConditionalASTNode((char*)"", conditionalType::IF, (yyvsp[-2].astNode), (yyvsp[0].astNode));
        }
#line 1799 "./output/grammar.tab.cpp"
    break;

  case 29:
#line 349 "grammar.y"
                                       {
            (yyval.astNode) = new ConditionalASTNode((char*)"", conditionalType::IF, (yyvsp[-4].astNode), (yyvsp[-2].astNode), (yyvsp[0].astNode));
        }
#line 1807 "./output/grammar.tab.cpp"
    break;

  case 30:
#line 352 "grammar.y"
                                {
            (yyval.astNode) = new LoopASTNode((char*)"", LoopType::WHILE, (yyvsp[0].astNode), (yyvsp[-2].astNode));
        }
#line 1815 "./output/grammar.tab.cpp"
    break;

  case 31:
#line 355 "grammar.y"
                                            {
            (yyval.astNode) = new LoopASTNode((char*)"", LoopType::FOR, (yyvsp[0].astNode), NULL, NULL, NULL);
        }
#line 1823 "./output/grammar.tab.cpp"
    break;

  case 32:
#line 358 "grammar.y"
                                                     {
            (yyval.astNode) = new LoopASTNode((char*)"", LoopType::FOR, (yyvsp[0].astNode), (yyvsp[-4].astNode), NULL, NULL);
        }
#line 1831 "./output/grammar.tab.cpp"
    break;

  case 33:
#line 361 "grammar.y"
                                                  {
            (yyval.astNode) = new LoopASTNode((char*)"", LoopType::FOR, (yyvsp[0].astNode), NULL, (yyvsp[-3].astNode), NULL);
        }
#line 1839 "./output/grammar.tab.cpp"
    break;

  case 34:
#line 364 "grammar.y"
                                                  {
            (yyval.astNode) = new LoopASTNode((char*)"", LoopType::FOR, (yyvsp[0].astNode), NULL, NULL, (yyvsp[-2].astNode));
        }
#line 1847 "./output/grammar.tab.cpp"
    break;

  case 35:
#line 367 "grammar.y"
                                                          {
            (yyval.astNode) = new LoopASTNode((char*)"", LoopType::FOR, (yyvsp[0].astNode), (yyvsp[-5].astNode), (yyvsp[-3].astNode), NULL);
        }
#line 1855 "./output/grammar.tab.cpp"
    break;

  case 36:
#line 370 "grammar.y"
                                                          {
            (yyval.astNode) = new LoopASTNode((char*)"", LoopType::FOR, (yyvsp[0].astNode), (yyvsp[-5].astNode), NULL, (yyvsp[-2].astNode));
        }
#line 1863 "./output/grammar.tab.cpp"
    break;

  case 37:
#line 373 "grammar.y"
                                                       {
            (yyval.astNode) = new LoopASTNode((char*)"", LoopType::FOR, (yyvsp[0].astNode), NULL, (yyvsp[-4].astNode), (yyvsp[-2].astNode));
        }
#line 1871 "./output/grammar.tab.cpp"
    break;

  case 38:
#line 376 "grammar.y"
                                                               {
            (yyval.astNode) = new LoopASTNode((char*)"", LoopType::FOR, (yyvsp[0].astNode), (yyvsp[-6].astNode), (yyvsp[-4].astNode), (yyvsp[-2].astNode));
        }
#line 1879 "./output/grammar.tab.cpp"
    break;

  case 39:
#line 379 "grammar.y"
                         {
            yyerrok;
        }
#line 1887 "./output/grammar.tab.cpp"
    break;

  case 40:
#line 385 "grammar.y"
                         {
            DefVarASTNode* temp = (DefVarASTNode*)(yyvsp[0].astNode);
            temp->setSymbolType((yyvsp[-1].str));
            (yyval.astNode) = temp;
        }
#line 1897 "./output/grammar.tab.cpp"
    break;

  case 41:
#line 390 "grammar.y"
                         {
            yyerrok;
        }
#line 1905 "./output/grammar.tab.cpp"
    break;

  case 42:
#line 396 "grammar.y"
            {
            (yyval.astNode) = (yyvsp[0].astNode);
        }
#line 1913 "./output/grammar.tab.cpp"
    break;

  case 43:
#line 399 "grammar.y"
                            {
            (yyvsp[-2].astNode) -> getLastBrother() -> addBrother((yyvsp[0].astNode));
            (yyval.astNode) = (yyvsp[-2].astNode);
        }
#line 1922 "./output/grammar.tab.cpp"
    break;

  case 44:
#line 406 "grammar.y"
               {
            (yyval.astNode) = (yyvsp[0].astNode);
        }
#line 1930 "./output/grammar.tab.cpp"
    break;

  case 45:
#line 409 "grammar.y"
                             {
            (yyvsp[-2].astNode) -> addChildNode((yyvsp[0].astNode));
            (yyval.astNode) = (yyvsp[-2].astNode);
        }
#line 1939 "./output/grammar.tab.cpp"
    break;

  case 46:
#line 416 "grammar.y"
                        {
            ASTNode* temp=NULL;
            if((yyvsp[-2].astNode)->getNodeType()==ASTNodeType::op){
                OpASTNode* left=(OpASTNode*)(yyvsp[-2].astNode);
                if(left->getType()==opType::getArrayValue){
                    temp = new OpASTNode((char*)"=", opType::assignArrayValue);
                }
                else{
                    temp = new OpASTNode((char*)"=", opType::assign);
                }
            }
            else{
                temp = new OpASTNode((char*)"=", opType::assign);
            }
            temp->addChildNode((yyvsp[-2].astNode));
            (yyvsp[-2].astNode)->addBrother((yyvsp[0].astNode));
            (yyval.astNode)=temp;
        }
#line 1962 "./output/grammar.tab.cpp"
    break;

  case 47:
#line 434 "grammar.y"
                        {
            ASTNode* temp = new OpASTNode((char*)"&&",opType::andop);
            temp->addChildNode((yyvsp[-2].astNode));
            (yyvsp[-2].astNode)->addBrother((yyvsp[0].astNode));
            (yyvsp[0].astNode)->setParent(temp);
            (yyval.astNode)=temp;

        }
#line 1975 "./output/grammar.tab.cpp"
    break;

  case 48:
#line 442 "grammar.y"
                       {
            ASTNode* temp = new OpASTNode((char*)"||",opType::orop);
            temp->addChildNode((yyvsp[-2].astNode));
            (yyvsp[-2].astNode)->addBrother((yyvsp[0].astNode));
            (yyval.astNode)=temp;
        }
#line 1986 "./output/grammar.tab.cpp"
    break;

  case 49:
#line 448 "grammar.y"
                          {
            ASTNode* temp=new OpASTNode((yyvsp[-1].str),opType::relop);
            temp->addChildNode((yyvsp[-2].astNode));
            (yyvsp[-2].astNode)->addBrother((yyvsp[0].astNode));
            (yyval.astNode)=temp;
        }
#line 1997 "./output/grammar.tab.cpp"
    break;

  case 50:
#line 454 "grammar.y"
                        {
            ASTNode* temp = new OpASTNode((char*)"+",opType::add);
            temp->addChildNode((yyvsp[-2].astNode));
            (yyvsp[-2].astNode)->addBrother((yyvsp[0].astNode));
            (yyval.astNode)=temp;

        }
#line 2009 "./output/grammar.tab.cpp"
    break;

  case 51:
#line 461 "grammar.y"
                             {
            ASTNode* temp = new OpASTNode((char*)"-",opType::subtract);
            temp->addChildNode((yyvsp[-2].astNode));
            (yyvsp[-2].astNode)->addBrother((yyvsp[0].astNode));
            (yyval.astNode)=temp;

        }
#line 2021 "./output/grammar.tab.cpp"
    break;

  case 52:
#line 468 "grammar.y"
                             {
            ASTNode* temp = new OpASTNode((char*)"*",opType::multiply);
            temp->addChildNode((yyvsp[-2].astNode));
            (yyvsp[-2].astNode)->addBrother((yyvsp[0].astNode));
            (yyval.astNode)=temp;

        }
#line 2033 "./output/grammar.tab.cpp"
    break;

  case 53:
#line 475 "grammar.y"
                           {
            ASTNode* temp = new OpASTNode((char*)"/",opType::divide);
            temp->addChildNode((yyvsp[-2].astNode));
            (yyvsp[-2].astNode)->addBrother((yyvsp[0].astNode));
            (yyval.astNode)=temp;
        }
#line 2044 "./output/grammar.tab.cpp"
    break;

  case 54:
#line 481 "grammar.y"
                        {
            ASTNode* temp = new OpASTNode((char*)"%",opType::mod);
            temp->addChildNode((yyvsp[-2].astNode));
            (yyvsp[-2].astNode)->addBrother((yyvsp[0].astNode));
            (yyval.astNode)=temp;
        }
#line 2055 "./output/grammar.tab.cpp"
    break;

  case 55:
#line 487 "grammar.y"
                        {
            ASTNode* temp = new OpASTNode((char*)"^",opType::pow);
            temp->addChildNode((yyvsp[-2].astNode));
            (yyvsp[-2].astNode)->addBrother((yyvsp[0].astNode));
            (yyval.astNode)=temp;
        }
#line 2066 "./output/grammar.tab.cpp"
    break;

  case 56:
#line 493 "grammar.y"
                        {
            ASTNode* temp = new OpASTNode((char*)"-",opType::negative);
            temp->addChildNode((yyvsp[0].astNode));
            (yyval.astNode)=temp;

        }
#line 2077 "./output/grammar.tab.cpp"
    break;

  case 57:
#line 499 "grammar.y"
                    {
            (yyval.astNode)=(yyvsp[-1].astNode);
        }
#line 2085 "./output/grammar.tab.cpp"
    break;

  case 58:
#line 502 "grammar.y"
                   {
            ASTNode* temp = new OpASTNode((char*)"!",opType::notop);
            temp->addChildNode((yyvsp[0].astNode));
            (yyval.astNode)=temp;
        }
#line 2095 "./output/grammar.tab.cpp"
    break;

  case 59:
#line 507 "grammar.y"
                                   {
            (yyval.astNode)=NULL;
        }
#line 2103 "./output/grammar.tab.cpp"
    break;

  case 60:
#line 510 "grammar.y"
                                 {
            ASTNode* temp = new OpASTNode((char*)"[]",opType::getArrayValue);
            ASTNode* var = new VarASTNode((char*)(yyvsp[-3].str));
            temp->addChildNode(var);
            var->addBrother((yyvsp[-1].astNode));
            (yyval.astNode)=temp;
        }
#line 2115 "./output/grammar.tab.cpp"
    break;

  case 61:
#line 517 "grammar.y"
                 {
            ASTNode* temp = new OpASTNode((char*)"&", opType::signaland);
            ASTNode* child = new VarASTNode((char*)(yyvsp[0].str));
            temp -> addChildNode(child);
            (yyval.astNode) = temp;
        }
#line 2126 "./output/grammar.tab.cpp"
    break;

  case 62:
#line 523 "grammar.y"
                     {
            ASTNode* temp = new OpASTNode((char*)"*",opType::getvalue);
            ASTNode* var = new VarASTNode((char*)(yyvsp[0].str));
            temp->addChildNode(var);
            (yyval.astNode)=temp;
        }
#line 2137 "./output/grammar.tab.cpp"
    break;

  case 63:
#line 529 "grammar.y"
             {
            flagTable = tempTable->findSymbol((yyvsp[0].str));
            if(flagTable!=NULL){
                VarASTNode* var = new VarASTNode((yyvsp[0].str));
                var -> setTheTable(flagTable);
                (yyval.astNode) = var;
                flagTable = tempTable;
            }
            else{
                yyerror((char*)"use variable undifined");
            }
        }
#line 2154 "./output/grammar.tab.cpp"
    break;

  case 64:
#line 541 "grammar.y"
              {
            (yyval.astNode) = new LiteralASTNode((yyvsp[0].str));
        }
#line 2162 "./output/grammar.tab.cpp"
    break;

  case 65:
#line 544 "grammar.y"
                  {
            yyerrok;
        }
#line 2170 "./output/grammar.tab.cpp"
    break;


#line 2174 "./output/grammar.tab.cpp"

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 549 "grammar.y"


int yyerror(char* s){
    printf("Syntax error: %s\n", s);
    exit(1);
}

std::string replaceExtName(char* fileName) {
    int dotIndex = 0;
    int nameLength = strlen(fileName);
    for (int i = nameLength - 1; i >= 0; i--) {
        if (fileName[i] == '.') {
            dotIndex = i;
            break;
        }
    }
    char* buf = new char[dotIndex];
    strncpy(buf, fileName, dotIndex);
    std::string rev(buf);
    rev += ".asm";
    return rev;
}
/* 
YACC源程序的程序部分包括：
主程序 main()
错误信息执行程序 yyerror(s)
词法分析程序yylex(),可以与LEX进行整合
用户在语义动作中用到的子程序
YACC约定：
传递词法分析程序token属性值的全程变量名：yylval
生成的语法分析程序名为：yyparse();
 */

// 暂时没有那么多可选参数，只能从头开始运行
int main(int argc, char* argv[]){
    char* filename = NULL;
    InterMediate* im;
    /* printf(argv[1]); */
    if(argc>=2){
        printf(argv[1]);
        filename = argv[1];
    }
    printf("%s\n",filename);
    printf("begin1.\n");
    FILE* file = fopen(filename, "r");
    printf("begin2.\n");
    yyin = file;
    printf("begin3.\n");
    while(!feof(yyin))
    {
        yyparse();
    }
    root->printTree();
    std::cout << "root->printTree();" << std::endl;
/* <<<<<<< HEAD
    
======= */
    
    //-----------------------------------------------------
    //从rootTable开始遍历符号表，rootTable定义在tools中
    //-----------------------------------------------------
/* <<<<<<< HEAD
    SymbolTable* t = rootTable;
    while(t->getChild()!=NULL){
        t->getAllSymbol();
        t = t-> getChild();
        printf("1.\n");
    }
======= */
    Symbol* s = rootTable->findSymbolfromRoot("MAIN");
    printf("%ld\n", s);
    SymbolTable* st = rootTable->findSymbolfromRootReturnTable("MAIN");
    printf("%ld\n", st);
    std::cout<<"rootTable offset: "<<rootTable->getTotalOffset()<<std::endl;
    std::cout<<"next offset from rootTable can be used: "<<rootTable->getTotalOffsetFromRoot()<<std::endl;
    
    im = new InterMediate( (RootNode *)root , rootTable );
/* >>>>>>> 7ea1a4613195f3495aec37de734eaa7e34ea93fb */

    /* im = new InterMediate((RootNode *)root); */
/* >>>>>>> 6f2c25dff8bdee9a4a40aad1ac7ed8a286b078c6 */
    std::cout << "new InterMediate((RootNode *)root);" << std::endl;
    im->Generate(im->getRoot(), im->getTable());
    std::cout << " !!!!!!!!!!!!!!!! im->Generate(im->getRoot(), im->getTable());" << std::endl;
    im->printQuads();
    std::cout << "im->printQuads();" << std::endl;
    AsmGenerator * asmgenera ;
    std::cout << " AsmGenerator * asmgenera ;" << std::endl;
    asmgenera =  new AsmGenerator(im->getQuads(), im->getTempVars(), im->getTable());
    std::cout << "new AsmGenerator(im->getQuads(), im->getTempVars(), im->getTable());" << std::endl;
    asmgenera->generate();
    std::cout <<"generate!!!!!!!!!!!!!!" <<std::endl;
    std::cout << asmgenera->getAsmCode();
    std::cout << "asmgenera->getAsmCode();" << std::endl;
    std::string outFileName = replaceExtName(filename);
    std::cout << "replaceExtName(filename);" << std::endl;
    std::ofstream outasm(outFileName);
    std::cout << "std::ofstream outasm(outFileName);" << std::endl;
    outasm << asmgenera->getAsmCode();
    std::cout << " outasm << asmgenera->getAsmCode();" << std::endl;
    return 0;
}
