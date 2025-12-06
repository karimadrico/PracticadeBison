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
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern FILE *yyin;
int yylex(void);
void yyerror(const char *s);
char *getNumLbl(void);
typedef enum {
  OP_SUMA,
  OP_RESTA,
  OP_MULTIPLICA,
  OP_DIVIDE
} TipoOperacion;

static void generarOperacionAritmetica(TipoOperacion tipo, int numOperandos, char *target, char *destinoDando);

#line 89 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUM = 3,                        /* NUM  */
  YYSYMBOL_ID = 4,                         /* ID  */
  YYSYMBOL_CAD = 5,                        /* CAD  */
  YYSYMBOL_PROGRAMA = 6,                   /* PROGRAMA  */
  YYSYMBOL_INICIO = 7,                     /* INICIO  */
  YYSYMBOL_FIN = 8,                        /* FIN  */
  YYSYMBOL_LEE = 9,                        /* LEE  */
  YYSYMBOL_MOSTRAR = 10,                   /* MOSTRAR  */
  YYSYMBOL_SI = 11,                        /* SI  */
  YYSYMBOL_ENTONCES = 12,                  /* ENTONCES  */
  YYSYMBOL_SINO = 13,                      /* SINO  */
  YYSYMBOL_MIENTRAS = 14,                  /* MIENTRAS  */
  YYSYMBOL_HACER = 15,                     /* HACER  */
  YYSYMBOL_FINMIENTRAS = 16,               /* FINMIENTRAS  */
  YYSYMBOL_EJECUTA = 17,                   /* EJECUTA  */
  YYSYMBOL_VECES = 18,                     /* VECES  */
  YYSYMBOL_USANDO = 19,                    /* USANDO  */
  YYSYMBOL_FIN_EJECUTA = 20,               /* FIN_EJECUTA  */
  YYSYMBOL_FINSI = 21,                     /* FINSI  */
  YYSYMBOL_HASTAQUE = 22,                  /* HASTAQUE  */
  YYSYMBOL_CALCULA = 23,                   /* CALCULA  */
  YYSYMBOL_FIN_CALCULA = 24,               /* FIN_CALCULA  */
  YYSYMBOL_MUEVE = 25,                     /* MUEVE  */
  YYSYMBOL_A = 26,                         /* A  */
  YYSYMBOL_DE = 27,                        /* DE  */
  YYSYMBOL_COMO = 28,                      /* COMO  */
  YYSYMBOL_POR = 29,                       /* POR  */
  YYSYMBOL_ES = 30,                        /* ES  */
  YYSYMBOL_IGUAL = 31,                     /* IGUAL  */
  YYSYMBOL_MAYOR = 32,                     /* MAYOR  */
  YYSYMBOL_MENOR = 33,                     /* MENOR  */
  YYSYMBOL_QUE = 34,                       /* QUE  */
  YYSYMBOL_SUMA = 35,                      /* SUMA  */
  YYSYMBOL_RESTA = 36,                     /* RESTA  */
  YYSYMBOL_MULTIPLICA = 37,                /* MULTIPLICA  */
  YYSYMBOL_DIVIDE = 38,                    /* DIVIDE  */
  YYSYMBOL_DANDO = 39,                     /* DANDO  */
  YYSYMBOL_40_ = 40,                       /* '+'  */
  YYSYMBOL_41_ = 41,                       /* '-'  */
  YYSYMBOL_42_ = 42,                       /* '*'  */
  YYSYMBOL_43_ = 43,                       /* '/'  */
  YYSYMBOL_44_ = 44,                       /* '.'  */
  YYSYMBOL_45_ = 45,                       /* '='  */
  YYSYMBOL_46_ = 46,                       /* ','  */
  YYSYMBOL_47_ = 47,                       /* '<'  */
  YYSYMBOL_48_ = 48,                       /* '>'  */
  YYSYMBOL_YYACCEPT = 49,                  /* $accept  */
  YYSYMBOL_programa = 50,                  /* programa  */
  YYSYMBOL_sentencias = 51,                /* sentencias  */
  YYSYMBOL_sentencia = 52,                 /* sentencia  */
  YYSYMBOL_bucle = 53,                     /* bucle  */
  YYSYMBOL_comparar = 54,                  /* comparar  */
  YYSYMBOL_asignar = 55,                   /* asignar  */
  YYSYMBOL_arit = 56,                      /* arit  */
  YYSYMBOL_targetOpt = 57,                 /* targetOpt  */
  YYSYMBOL_target = 58,                    /* target  */
  YYSYMBOL_optDando = 59,                  /* optDando  */
  YYSYMBOL_listaValores = 60,              /* listaValores  */
  YYSYMBOL_io = 61,                        /* io  */
  YYSYMBOL_listaExpresiones = 62,          /* listaExpresiones  */
  YYSYMBOL_expresion = 63,                 /* expresion  */
  YYSYMBOL_condicion = 64                  /* condicion  */
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
typedef yytype_int8 yy_state_t;

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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   215

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  16
/* YYNRULES -- Number of rules.  */
#define YYNRULES  48
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  121

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   294


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
       2,     2,    42,    40,    46,    41,    44,    43,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      47,    45,    48,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    52,    52,    56,    57,    61,    62,    63,    64,    65,
      69,    79,   104,   118,   121,   127,   133,   139,   145,   155,
     162,   169,   176,   186,   187,   191,   192,   193,   197,   198,
     202,   203,   207,   208,   214,   215,   220,   221,   222,   223,
     224,   225,   226,   230,   231,   232,   233,   234,   235
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NUM", "ID", "CAD",
  "PROGRAMA", "INICIO", "FIN", "LEE", "MOSTRAR", "SI", "ENTONCES", "SINO",
  "MIENTRAS", "HACER", "FINMIENTRAS", "EJECUTA", "VECES", "USANDO",
  "FIN_EJECUTA", "FINSI", "HASTAQUE", "CALCULA", "FIN_CALCULA", "MUEVE",
  "A", "DE", "COMO", "POR", "ES", "IGUAL", "MAYOR", "MENOR", "QUE", "SUMA",
  "RESTA", "MULTIPLICA", "DIVIDE", "DANDO", "'+'", "'-'", "'*'", "'/'",
  "'.'", "'='", "','", "'<'", "'>'", "$accept", "programa", "sentencias",
  "sentencia", "bucle", "comparar", "asignar", "arit", "targetOpt",
  "target", "optDando", "listaValores", "io", "listaExpresiones",
  "expresion", "condicion", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-41)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       5,     8,    25,   -17,   -41,    26,   -41,    62,    -7,    -4,
      51,    32,    32,    32,    59,    70,    72,    32,    32,    32,
      32,   -41,    33,    34,    42,    44,    50,    32,   -41,   -41,
     -41,   -41,   -41,    49,   -26,   163,    96,    97,    95,   100,
     -24,    89,     2,   -26,     2,     2,     2,   -41,   -41,   -41,
     -41,   -41,   -26,    32,    32,    32,    32,    32,    28,    32,
      32,    32,   -41,   -41,    99,    94,    32,    32,   115,   118,
     120,   125,    91,   -41,   -26,    91,    91,    91,   -26,   -40,
     -40,   -41,   -41,   106,   105,   107,   -26,   -26,   -26,     9,
     117,   139,    32,   -26,    41,   -41,   -41,   -41,   -41,   140,
     -41,   -41,   -41,   -41,    32,    32,    32,   -41,   -41,   -41,
     -41,   -41,   -41,   -41,   -26,   -26,   -26,   147,   177,   -41,
     -41
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     3,     0,     0,     0,
       0,     0,     0,     0,     3,     0,     0,     0,     0,     0,
       0,     4,     0,     0,     0,     0,     0,     0,     2,    32,
      37,    36,    38,    33,    34,     0,     0,     0,     0,     0,
       0,     0,    24,    30,    24,    24,    24,     5,     6,     7,
       9,     8,    15,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     3,     3,     0,     0,     0,     0,     0,     0,
       0,     0,    29,    23,    31,    29,    29,    29,    35,    41,
      42,    39,    40,     0,     0,     0,    48,    46,    47,     0,
       0,     0,     0,    17,     0,    18,    26,    25,    27,     0,
      19,    20,    21,    22,     0,     0,     0,     3,    14,    10,
       3,    12,    16,    28,    43,    44,    45,     0,     0,    13,
      11
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -41,   -41,   -14,   -41,   -41,   -41,   -41,   -41,    23,   -41,
      15,    87,   -41,   -41,    -3,   -12
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     7,    21,    22,    23,    24,    25,    72,    73,
     100,    42,    26,    33,    43,    36
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      39,    37,    56,    57,    66,    30,    31,    32,    34,    35,
      35,     1,     3,     8,    54,    55,    56,    57,    10,    11,
      12,    67,   107,    13,    52,     4,    14,     5,    69,    70,
     108,    71,    15,     6,    16,    30,    31,    32,    27,    74,
      28,    74,    74,    74,    17,    18,    19,    20,    89,    90,
      78,    79,    80,    81,    82,    29,    86,    87,    88,    83,
      84,    85,    38,    93,    94,   112,     8,    75,    76,    77,
       9,    10,    11,    12,    40,    41,    13,    47,    48,    14,
     111,    54,    55,    56,    57,    15,    49,    16,    50,    35,
     101,   102,   103,   117,    51,    53,   118,    17,    18,    19,
      20,   114,   115,   116,     8,    44,    45,    46,    62,    10,
      11,    12,    63,    64,    13,    68,    92,    14,    91,    95,
      65,     8,    96,    15,    97,    16,    10,    11,    12,    98,
      99,    13,   104,   109,    14,    17,    18,    19,    20,   105,
      15,   106,    16,   110,   113,     0,     0,     0,     0,     0,
       0,     8,    17,    18,    19,    20,    10,    11,    12,     0,
       0,    13,     0,     0,    14,     0,     0,     0,   119,     0,
      15,     0,    16,     0,     0,     0,     0,     0,     0,     0,
       0,     8,    17,    18,    19,    20,    10,    11,    12,     0,
       0,    13,     0,    58,    14,     0,     0,   120,     0,     0,
      15,     0,    16,    54,    55,    56,    57,     0,    59,     0,
      60,    61,    17,    18,    19,    20
};

static const yytype_int8 yycheck[] =
{
      14,    13,    42,    43,    28,     3,     4,     5,    11,    12,
      13,     6,     4,     4,    40,    41,    42,    43,     9,    10,
      11,    45,    13,    14,    27,     0,    17,    44,    26,    27,
      21,    29,    23,     7,    25,     3,     4,     5,    45,    42,
      44,    44,    45,    46,    35,    36,    37,    38,    62,    63,
      53,    54,    55,    56,    57,     4,    59,    60,    61,    31,
      32,    33,     3,    66,    67,    24,     4,    44,    45,    46,
       8,     9,    10,    11,     4,     3,    14,    44,    44,    17,
      92,    40,    41,    42,    43,    23,    44,    25,    44,    92,
      75,    76,    77,   107,    44,    46,   110,    35,    36,    37,
      38,   104,   105,   106,     4,    18,    19,    20,    12,     9,
      10,    11,    15,    18,    14,    26,    22,    17,    19,     4,
      20,     4,     4,    23,     4,    25,     9,    10,    11,     4,
      39,    14,    26,    16,    17,    35,    36,    37,    38,    34,
      23,    34,    25,     4,     4,    -1,    -1,    -1,    -1,    -1,
      -1,     4,    35,    36,    37,    38,     9,    10,    11,    -1,
      -1,    14,    -1,    -1,    17,    -1,    -1,    -1,    21,    -1,
      23,    -1,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     4,    35,    36,    37,    38,     9,    10,    11,    -1,
      -1,    14,    -1,    30,    17,    -1,    -1,    20,    -1,    -1,
      23,    -1,    25,    40,    41,    42,    43,    -1,    45,    -1,
      47,    48,    35,    36,    37,    38
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,    50,     4,     0,    44,     7,    51,     4,     8,
       9,    10,    11,    14,    17,    23,    25,    35,    36,    37,
      38,    52,    53,    54,    55,    56,    61,    45,    44,     4,
       3,     4,     5,    62,    63,    63,    64,    64,     3,    51,
       4,     3,    60,    63,    60,    60,    60,    44,    44,    44,
      44,    44,    63,    46,    40,    41,    42,    43,    30,    45,
      47,    48,    12,    15,    18,    20,    28,    45,    26,    26,
      27,    29,    57,    58,    63,    57,    57,    57,    63,    63,
      63,    63,    63,    31,    32,    33,    63,    63,    63,    51,
      51,    19,    22,    63,    63,     4,     4,     4,     4,    39,
      59,    59,    59,    59,    26,    34,    34,    13,    21,    16,
       4,    64,    24,     4,    63,    63,    63,    51,    51,    21,
      20
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    49,    50,    51,    51,    52,    52,    52,    52,    52,
      53,    53,    53,    54,    54,    55,    55,    55,    55,    56,
      56,    56,    56,    57,    57,    58,    58,    58,    59,    59,
      60,    60,    61,    61,    62,    62,    63,    63,    63,    63,
      63,    63,    63,    64,    64,    64,    64,    64,    64
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     7,     0,     2,     2,     2,     2,     2,     2,
       5,     7,     5,     7,     5,     3,     5,     4,     4,     4,
       4,     4,     4,     1,     0,     2,     2,     2,     2,     0,
       1,     2,     2,     2,     1,     3,     1,     1,     1,     3,
       3,     3,     3,     5,     5,     5,     3,     3,     3
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
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
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
  case 10: /* bucle: MIENTRAS condicion HACER sentencias FINMIENTRAS  */
#line 69 "parser.y"
                                                    {
        char* lbl0 = getNumLbl();
        char* lbl1 = getNumLbl();
        printf("%s:\n", lbl0);
        // evalúa la condición (la acción de condicion ya genera el código necesario)
        printf("sifalsovea %s\n", lbl1);
        // cuerpo
        printf("vea %s\n", lbl0);
        printf("%s:\n", lbl1);
    }
#line 1239 "parser.tab.c"
    break;

  case 11: /* bucle: EJECUTA NUM VECES USANDO ID sentencias FIN_EJECUTA  */
#line 79 "parser.y"
                                                       {
        char* lbl0 = getNumLbl();
        char* lbl1 = getNumLbl();
        // Inicializa el contador
        printf("valori %s\n", (yyvsp[-2].id)); // variable contador
        printf("mete 1\n");
        printf("asigna\n");
        printf("%s:\n", lbl0);
        // ...cuerpo del bucle...
        // Incrementa el contador
        printf("valori %s\n", (yyvsp[-2].id));
        printf("valord %s\n", (yyvsp[-2].id));
        printf("mete 1\n");
        printf("add\n");
        printf("asigna\n");
        // Condición de salida
        printf("valord %s\n", (yyvsp[-2].id));
        printf("valord %d\n", (yyvsp[-5].num)); // número de repeticiones
        printf("sub\n");
        printf("siciertovea %s\n", lbl1);
        printf("vea %s\n", lbl0);
        printf("%s:\n", lbl1);
        free((yyvsp[-2].id));
    }
#line 1268 "parser.tab.c"
    break;

  case 12: /* bucle: EJECUTA sentencias FIN_EJECUTA HASTAQUE condicion  */
#line 104 "parser.y"
                                                      {
        char* lbl0 = getNumLbl();
        char* lbl1 = getNumLbl();
        printf("%s:\n", lbl0);
        /* cuerpo ya generado por sentencias */
        printf("valord %s\n", "__dummy__"); /* placeholder no usado */
        /* Evaluar condicion: la acción de condicion genera el código apropiado */
        printf("sifalsovea %s\n", lbl1);
        printf("vea %s\n", lbl0);
        printf("%s:\n", lbl1);
    }
#line 1284 "parser.tab.c"
    break;

  case 13: /* comparar: SI condicion ENTONCES sentencias SINO sentencias FINSI  */
#line 118 "parser.y"
                                                           {
      /* caso SI ... SINO ... FINSI */
    }
#line 1292 "parser.tab.c"
    break;

  case 14: /* comparar: SI condicion ENTONCES sentencias FINSI  */
#line 121 "parser.y"
                                           {
      /* caso SI ... FINSI */
    }
#line 1300 "parser.tab.c"
    break;

  case 15: /* asignar: ID '=' expresion  */
#line 127 "parser.y"
                     {
      printf("valori %s\n", (yyvsp[-2].id));
      printf("swap\n");
      printf("asigna\n");
      free((yyvsp[-2].id));
    }
#line 1311 "parser.tab.c"
    break;

  case 16: /* asignar: CALCULA ID '=' expresion FIN_CALCULA  */
#line 133 "parser.y"
                                         {
      printf("valori %s\n", (yyvsp[-3].id));
      printf("swap\n");
      printf("asigna\n");
      free((yyvsp[-3].id));
    }
#line 1322 "parser.tab.c"
    break;

  case 17: /* asignar: CALCULA ID COMO expresion  */
#line 139 "parser.y"
                              {
      printf("valori %s\n", (yyvsp[-2].id));
      printf("swap\n");
      printf("asigna\n");
      free((yyvsp[-2].id));
    }
#line 1333 "parser.tab.c"
    break;

  case 18: /* asignar: MUEVE NUM A ID  */
#line 145 "parser.y"
                   {
      printf("mete %d\n", (yyvsp[-2].num));
      printf("valori %s\n", (yyvsp[0].id));
      printf("swap\n");
      printf("asigna\n");
      free((yyvsp[0].id));
    }
#line 1345 "parser.tab.c"
    break;

  case 19: /* arit: SUMA listaValores targetOpt optDando  */
#line 155 "parser.y"
                                         {
    if (!(yyvsp[-1].id) && !(yyvsp[0].id)) {
      yyerror("La operación SUMA requiere un destino");
      YYERROR;
    }
    generarOperacionAritmetica(OP_SUMA, (yyvsp[-2].num), (yyvsp[-1].id), (yyvsp[0].id));
  }
#line 1357 "parser.tab.c"
    break;

  case 20: /* arit: RESTA listaValores targetOpt optDando  */
#line 162 "parser.y"
                                          {
    if (!(yyvsp[-1].id) && !(yyvsp[0].id)) {
      yyerror("La operación RESTA requiere un destino");
      YYERROR;
    }
    generarOperacionAritmetica(OP_RESTA, (yyvsp[-2].num), (yyvsp[-1].id), (yyvsp[0].id));
  }
#line 1369 "parser.tab.c"
    break;

  case 21: /* arit: MULTIPLICA listaValores targetOpt optDando  */
#line 169 "parser.y"
                                               {
    if (!(yyvsp[-1].id) && !(yyvsp[0].id)) {
      yyerror("La operación MULTIPLICA requiere un destino");
      YYERROR;
    }
    generarOperacionAritmetica(OP_MULTIPLICA, (yyvsp[-2].num), (yyvsp[-1].id), (yyvsp[0].id));
  }
#line 1381 "parser.tab.c"
    break;

  case 22: /* arit: DIVIDE listaValores targetOpt optDando  */
#line 176 "parser.y"
                                           {
    if (!(yyvsp[-1].id) && !(yyvsp[0].id)) {
      yyerror("La operación DIVIDE requiere un destino");
      YYERROR;
    }
    generarOperacionAritmetica(OP_DIVIDE, (yyvsp[-2].num), (yyvsp[-1].id), (yyvsp[0].id));
  }
#line 1393 "parser.tab.c"
    break;

  case 23: /* targetOpt: target  */
#line 186 "parser.y"
           { (yyval.id) = (yyvsp[0].id); }
#line 1399 "parser.tab.c"
    break;

  case 24: /* targetOpt: %empty  */
#line 187 "parser.y"
                 { (yyval.id) = NULL; }
#line 1405 "parser.tab.c"
    break;

  case 25: /* target: DE ID  */
#line 191 "parser.y"
          { (yyval.id) = (yyvsp[0].id); }
#line 1411 "parser.tab.c"
    break;

  case 26: /* target: A ID  */
#line 192 "parser.y"
         { (yyval.id) = (yyvsp[0].id); }
#line 1417 "parser.tab.c"
    break;

  case 27: /* target: POR ID  */
#line 193 "parser.y"
           { (yyval.id) = (yyvsp[0].id); }
#line 1423 "parser.tab.c"
    break;

  case 28: /* optDando: DANDO ID  */
#line 197 "parser.y"
             { (yyval.id) = (yyvsp[0].id); }
#line 1429 "parser.tab.c"
    break;

  case 29: /* optDando: %empty  */
#line 198 "parser.y"
                 { (yyval.id) = NULL; }
#line 1435 "parser.tab.c"
    break;

  case 30: /* listaValores: expresion  */
#line 202 "parser.y"
              { (yyval.num) = 1; }
#line 1441 "parser.tab.c"
    break;

  case 31: /* listaValores: listaValores expresion  */
#line 203 "parser.y"
                           { (yyval.num) = (yyvsp[-1].num) + 1; }
#line 1447 "parser.tab.c"
    break;

  case 32: /* io: LEE ID  */
#line 207 "parser.y"
           { printf("lee %s\n", (yyvsp[0].id)); free((yyvsp[0].id)); }
#line 1453 "parser.tab.c"
    break;

  case 33: /* io: MOSTRAR listaExpresiones  */
#line 208 "parser.y"
                             { printf("print %d\n", (yyvsp[0].num)); }
#line 1459 "parser.tab.c"
    break;

  case 34: /* listaExpresiones: expresion  */
#line 214 "parser.y"
              { (yyval.num) = 1; }
#line 1465 "parser.tab.c"
    break;

  case 35: /* listaExpresiones: listaExpresiones ',' expresion  */
#line 215 "parser.y"
                                   { (yyval.num) = (yyvsp[-2].num) + 1; }
#line 1471 "parser.tab.c"
    break;

  case 36: /* expresion: ID  */
#line 220 "parser.y"
       { printf("valord %s\n", (yyvsp[0].id)); free((yyvsp[0].id)); }
#line 1477 "parser.tab.c"
    break;

  case 37: /* expresion: NUM  */
#line 221 "parser.y"
        { printf("mete %d\n", (yyvsp[0].num)); }
#line 1483 "parser.tab.c"
    break;

  case 38: /* expresion: CAD  */
#line 222 "parser.y"
        { printf("metecad %s\n", (yyvsp[0].cad)); free((yyvsp[0].cad)); }
#line 1489 "parser.tab.c"
    break;

  case 39: /* expresion: expresion '*' expresion  */
#line 223 "parser.y"
                            { printf("mul\n"); }
#line 1495 "parser.tab.c"
    break;

  case 40: /* expresion: expresion '/' expresion  */
#line 224 "parser.y"
                            { printf("div\n"); }
#line 1501 "parser.tab.c"
    break;

  case 41: /* expresion: expresion '+' expresion  */
#line 225 "parser.y"
                            { printf("add\n"); }
#line 1507 "parser.tab.c"
    break;

  case 42: /* expresion: expresion '-' expresion  */
#line 226 "parser.y"
                            { printf("sub\n"); }
#line 1513 "parser.tab.c"
    break;

  case 43: /* condicion: expresion ES IGUAL A expresion  */
#line 230 "parser.y"
                                   { printf("valord %s\nmete 0\nxor\nnot\n", "__dummy__"); }
#line 1519 "parser.tab.c"
    break;

  case 44: /* condicion: expresion ES MAYOR QUE expresion  */
#line 231 "parser.y"
                                     { printf("sub\n"); }
#line 1525 "parser.tab.c"
    break;

  case 45: /* condicion: expresion ES MENOR QUE expresion  */
#line 232 "parser.y"
                                     { printf("sub\n"); }
#line 1531 "parser.tab.c"
    break;

  case 46: /* condicion: expresion '<' expresion  */
#line 233 "parser.y"
                            { printf("sub\n"); }
#line 1537 "parser.tab.c"
    break;

  case 47: /* condicion: expresion '>' expresion  */
#line 234 "parser.y"
                            { printf("sub\n"); }
#line 1543 "parser.tab.c"
    break;

  case 48: /* condicion: expresion '=' expresion  */
#line 235 "parser.y"
                            { printf("xor\nnot\n"); }
#line 1549 "parser.tab.c"
    break;


#line 1553 "parser.tab.c"

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
      yyerror (YY_("syntax error"));
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


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
  yyerror (YY_("memory exhausted"));
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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 238 "parser.y"

static void generarOperacionAritmetica(TipoOperacion tipo, int numOperandos, char *target, char *destinoDando) {
  const char *opAcumulacion = (tipo == OP_MULTIPLICA || tipo == OP_DIVIDE) ? "mul" : "add";
  for (int i = 1; i < numOperandos; ++i) {
    printf("%s\n", opAcumulacion);
  }

  if (target) {
    printf("valord %s\n", target);
    if (tipo == OP_RESTA || tipo == OP_DIVIDE) {
      printf("swap\n");
    }
    const char *opFinal = (tipo == OP_SUMA) ? "add" :
                          (tipo == OP_RESTA) ? "sub" :
                          (tipo == OP_MULTIPLICA) ? "mul" : "div";
    printf("%s\n", opFinal);
  }

  char *destinoFinal = destinoDando ? destinoDando : target;
  if (!destinoFinal) {
    yyerror("La operación aritmética requiere un destino");
    if (destinoDando) free(destinoDando);
    if (target) free(target);
    return;
  }
  printf("valori %s\n", destinoFinal);
  printf("swap\n");
  printf("asigna\n");

  if (destinoDando) {
    free(destinoDando);
  }
  if (target) {
    free(target);
  }
}

void yyerror(const char *s) {
  fprintf(stderr, "Error de sintaxis: %s\n", s);
}

/* Generador simple de etiquetas */
char *getNumLbl(void) {
  static int cnt = 0;
  char *buf = malloc(16);
  if (!buf) return NULL;
  sprintf(buf, "LBL%d", cnt++);
  return buf;
}

/* Exponer el `main` solo cuando no se compile el ejecutable de prueba del lexer.
   Esto permite compilar `lex.yy.c` con `-DTEST_LEXER` y enlazar con
   `parser.tab.c` sin que haya dos funciones vete al sk`main`. */
#ifndef TEST_LEXER
int main(int argc, char *argv[]) {
  if (argc > 1) {
    FILE *f = fopen(argv[1], "r");
    if (!f) {
      perror("No se pudo abrir el archivo");
      return 1;
    }
    yyin = f;
  }
  yydebug = 1;
  yyparse();
  return 0;
}
#endif
