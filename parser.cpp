/* A Bison parser, made by GNU Bison 3.7.5.  */

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
#define YYBISON 30705

/* Bison version string.  */
#define YYBISON_VERSION "3.7.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 3 "parser.y"

    #include <stdio.h>
    #include <iostream>
    #include <vector>
    #include <string>
    using namespace std; 
    
    extern int yylex();
    extern int yylineno;
    extern char *yytext;
    
    extern bool hayError;
    void yyerror (const char *msg) {
        hayError = true;
        printf("line %d: %s\n", yylineno, msg) ;
    }

    #include "Codigo.hpp"
    
    Codigo codigo;

#line 93 "parser.cpp"

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

#include "parser.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TIDENTIFIER = 3,                /* TIDENTIFIER  */
  YYSYMBOL_TINTEGER = 4,                   /* TINTEGER  */
  YYSYMBOL_TDOUBLE = 5,                    /* TDOUBLE  */
  YYSYMBOL_TMUL = 6,                       /* TMUL  */
  YYSYMBOL_TDIV = 7,                       /* TDIV  */
  YYSYMBOL_TPLUS = 8,                      /* TPLUS  */
  YYSYMBOL_TMINUS = 9,                     /* TMINUS  */
  YYSYMBOL_TCGLE = 10,                     /* TCGLE  */
  YYSYMBOL_TCLT = 11,                      /* TCLT  */
  YYSYMBOL_TCLE = 12,                      /* TCLE  */
  YYSYMBOL_TCGT = 13,                      /* TCGT  */
  YYSYMBOL_TCGE = 14,                      /* TCGE  */
  YYSYMBOL_TEQUAL = 15,                    /* TEQUAL  */
  YYSYMBOL_TNEQUAL = 16,                   /* TNEQUAL  */
  YYSYMBOL_TSEMIC = 17,                    /* TSEMIC  */
  YYSYMBOL_TASSIG = 18,                    /* TASSIG  */
  YYSYMBOL_TLBRACE = 19,                   /* TLBRACE  */
  YYSYMBOL_TRBRACE = 20,                   /* TRBRACE  */
  YYSYMBOL_TLPAREN = 21,                   /* TLPAREN  */
  YYSYMBOL_TRPAREN = 22,                   /* TRPAREN  */
  YYSYMBOL_TCOMMA = 23,                    /* TCOMMA  */
  YYSYMBOL_RPROGRAM = 24,                  /* RPROGRAM  */
  YYSYMBOL_RPROCEDURE = 25,                /* RPROCEDURE  */
  YYSYMBOL_RFLOAT = 26,                    /* RFLOAT  */
  YYSYMBOL_RINTEGER = 27,                  /* RINTEGER  */
  YYSYMBOL_RFOR = 28,                      /* RFOR  */
  YYSYMBOL_RWHILE = 29,                    /* RWHILE  */
  YYSYMBOL_RUNTIL = 30,                    /* RUNTIL  */
  YYSYMBOL_RIF = 31,                       /* RIF  */
  YYSYMBOL_RELSE = 32,                     /* RELSE  */
  YYSYMBOL_RFOREVER = 33,                  /* RFOREVER  */
  YYSYMBOL_RDO = 34,                       /* RDO  */
  YYSYMBOL_RSKIP = 35,                     /* RSKIP  */
  YYSYMBOL_REXIT = 36,                     /* REXIT  */
  YYSYMBOL_RAND = 37,                      /* RAND  */
  YYSYMBOL_ROR = 38,                       /* ROR  */
  YYSYMBOL_RNOT = 39,                      /* RNOT  */
  YYSYMBOL_RREAD = 40,                     /* RREAD  */
  YYSYMBOL_RPRINTLN = 41,                  /* RPRINTLN  */
  YYSYMBOL_RPRINT = 42,                    /* RPRINT  */
  YYSYMBOL_YYACCEPT = 43,                  /* $accept  */
  YYSYMBOL_programa = 44,                  /* programa  */
  YYSYMBOL_45_1 = 45,                      /* $@1  */
  YYSYMBOL_declaraciones = 46,             /* declaraciones  */
  YYSYMBOL_47_2 = 47,                      /* $@2  */
  YYSYMBOL_lista_de_ident = 48,            /* lista_de_ident  */
  YYSYMBOL_resto_lista_id = 49,            /* resto_lista_id  */
  YYSYMBOL_tipo = 50,                      /* tipo  */
  YYSYMBOL_decl_de_subprogs = 51,          /* decl_de_subprogs  */
  YYSYMBOL_decl_de_subprograma = 52,       /* decl_de_subprograma  */
  YYSYMBOL_53_3 = 53,                      /* $@3  */
  YYSYMBOL_argumentos = 54,                /* argumentos  */
  YYSYMBOL_lista_de_param = 55,            /* lista_de_param  */
  YYSYMBOL_56_4 = 56,                      /* $@4  */
  YYSYMBOL_clase_par = 57,                 /* clase_par  */
  YYSYMBOL_resto_lis_de_param = 58,        /* resto_lis_de_param  */
  YYSYMBOL_59_5 = 59,                      /* $@5  */
  YYSYMBOL_lista_de_sentencias = 60,       /* lista_de_sentencias  */
  YYSYMBOL_sentencia = 61,                 /* sentencia  */
  YYSYMBOL_62_6 = 62,                      /* $@6  */
  YYSYMBOL_63_7 = 63,                      /* $@7  */
  YYSYMBOL_lista_de_argumentos = 64,       /* lista_de_argumentos  */
  YYSYMBOL_resto_lista_argumentos = 65,    /* resto_lista_argumentos  */
  YYSYMBOL_M = 66,                         /* M  */
  YYSYMBOL_variable = 67,                  /* variable  */
  YYSYMBOL_expr = 68                       /* expr  */
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
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
#define YYLAST   343

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  62
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  178

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   297


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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    79,    79,    78,    89,    88,    91,    94,   103,   110,
     113,   114,   117,   118,   121,   121,   125,   126,   130,   129,
     135,   136,   137,   141,   140,   143,   146,   153,   161,   185,
     199,   208,   220,   228,   235,   243,   251,   261,   283,   260,
     309,   323,   332,   339,   342,   344,   359,   374,   390,   406,
     422,   438,   453,   469,   485,   498,   512,   526,   540,   555,
     564,   572,   580
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
  "\"end of file\"", "error", "\"invalid token\"", "TIDENTIFIER",
  "TINTEGER", "TDOUBLE", "TMUL", "TDIV", "TPLUS", "TMINUS", "TCGLE",
  "TCLT", "TCLE", "TCGT", "TCGE", "TEQUAL", "TNEQUAL", "TSEMIC", "TASSIG",
  "TLBRACE", "TRBRACE", "TLPAREN", "TRPAREN", "TCOMMA", "RPROGRAM",
  "RPROCEDURE", "RFLOAT", "RINTEGER", "RFOR", "RWHILE", "RUNTIL", "RIF",
  "RELSE", "RFOREVER", "RDO", "RSKIP", "REXIT", "RAND", "ROR", "RNOT",
  "RREAD", "RPRINTLN", "RPRINT", "$accept", "programa", "$@1",
  "declaraciones", "$@2", "lista_de_ident", "resto_lista_id", "tipo",
  "decl_de_subprogs", "decl_de_subprograma", "$@3", "argumentos",
  "lista_de_param", "$@4", "clase_par", "resto_lis_de_param", "$@5",
  "lista_de_sentencias", "sentencia", "$@6", "$@7", "lista_de_argumentos",
  "resto_lista_argumentos", "M", "variable", "expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297
};
#endif

#define YYPACT_NINF (-90)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -18,    10,    16,   -90,   -90,    -6,   -90,   -90,    -7,    28,
      29,    14,    -7,    11,   -90,   -90,    56,   -90,    32,   -90,
      31,    30,    34,    35,     4,    73,    33,    22,   -90,    36,
      37,    39,    41,    56,    44,    11,    -6,    -6,    -6,    73,
      -6,    49,   -90,   -90,   -90,    73,    73,   -90,   176,   -90,
      73,    46,    67,    73,    73,   -90,   -90,    73,   -90,   -90,
      -3,    27,    -7,    50,   192,    68,   -90,   159,   119,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,   -90,
     -90,   -90,    56,   305,   -90,    51,   210,   227,   244,   -90,
     -90,   -90,    28,   -90,    55,    58,    73,   -90,    62,    56,
     -90,   -90,   -90,    18,    18,    21,    21,    21,    21,    21,
      21,    56,    73,    73,    82,    71,    87,    90,    91,   -90,
     -90,    56,   -90,   192,    73,    89,    93,   305,   305,    80,
     -90,   -90,   -90,   -90,    94,    95,   -90,   305,   -90,   -90,
     -90,    -6,   -90,   -90,    97,   100,   101,    73,    -3,   -90,
     -90,   -90,   260,    28,    73,   102,   -90,   305,   -90,    94,
     -90,    56,   -90,   103,    99,    67,   -90,   104,   107,    73,
     -90,   293,   117,    56,   -90,   120,   122,   -90
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     1,     6,    11,    10,    13,     0,
       0,     0,    13,     9,     4,    14,    27,    12,     0,     7,
       0,    17,    45,     0,     0,     0,     0,     0,    44,     0,
       0,     0,     0,    27,     0,     9,     6,     0,     6,     0,
       0,     0,    45,    60,    61,     0,     0,    59,     0,    44,
       0,     0,     0,     0,     0,     3,    26,     0,     8,     5,
       0,     0,    13,     0,    43,     0,    44,     0,    54,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    44,
      44,    44,    27,    44,    33,     0,     0,     0,     0,    22,
      21,    20,     0,    16,     0,     0,     0,    41,     0,    27,
      62,    57,    58,    55,    56,    48,    50,    47,    49,    46,
      51,    27,     0,     0,     0,     0,     0,     0,     0,    28,
      18,    27,    40,    43,     0,     0,     0,    52,    53,     0,
      32,    34,    36,    35,    25,     0,    42,    37,    44,    44,
      44,     0,    19,    15,     0,     0,     0,     0,     0,    44,
      30,    29,     0,     0,     0,     0,    23,    38,    44,    25,
      44,    27,    24,     0,     0,     0,    44,     0,     0,     0,
      31,     0,     0,    27,    44,     0,     0,    39
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -90,   -90,   -90,   -26,   -90,   -89,   108,   -35,    -8,   -90,
     -90,   -90,   -90,   -90,   -11,   -17,   -90,   -32,   -90,   -90,
     -90,   -90,    23,    20,   -16,   -31
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     5,     8,    20,    14,    19,     9,    11,    12,
      21,    38,    61,   134,    92,   142,   159,    32,    33,   144,
     160,    63,    97,    51,    47,    48
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      34,    56,    60,   120,    17,    65,     1,    89,    64,    90,
      59,    91,    62,     3,    67,    68,     4,    34,    10,    83,
       6,     7,    86,    87,    69,    70,    88,    69,    70,    71,
      72,    13,    15,    16,    18,    35,    85,    41,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,    36,    93,
     114,    37,    49,    50,    94,    39,    40,    52,    53,    22,
      54,    55,    57,    84,   156,   123,    34,   125,    66,    82,
      42,    98,    95,   116,   121,   122,    42,    43,    44,   126,
     124,   127,   128,    34,    23,    24,    99,    25,   130,   135,
      26,    27,    28,   137,    45,    34,    29,    30,    31,   111,
     112,   113,   129,   115,   131,    34,   148,   132,   133,   138,
     140,   141,    46,   139,   149,   143,   152,   150,   151,   166,
     165,   158,   169,   157,   170,    69,    70,    71,    72,   164,
      73,    74,    75,    76,    77,    78,   173,   153,   171,   177,
     176,   174,   162,    58,     0,    34,   136,     0,     0,   167,
       0,     0,     0,     0,     0,     0,     0,    34,   145,   146,
     147,     0,     0,     0,     0,    69,    70,    71,    72,   154,
      73,    74,    75,    76,    77,    78,     0,     0,   161,     0,
     163,   100,    69,    70,    71,    72,   168,    73,    74,    75,
      76,    77,    78,     0,   175,    79,    80,    81,    69,    70,
      71,    72,     0,    73,    74,    75,    76,    77,    78,     0,
       0,     0,     0,    80,    81,    96,    69,    70,    71,    72,
       0,    73,    74,    75,    76,    77,    78,     0,     0,    80,
      81,     0,   117,    69,    70,    71,    72,     0,    73,    74,
      75,    76,    77,    78,     0,     0,     0,    80,    81,   118,
      69,    70,    71,    72,     0,    73,    74,    75,    76,    77,
      78,   119,     0,     0,    80,    81,    69,    70,    71,    72,
       0,    73,    74,    75,    76,    77,    78,     0,     0,     0,
       0,    80,    81,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   155,     0,     0,     0,     0,    80,    81,    69,
      70,    71,    72,     0,    73,    74,    75,    76,    77,    78,
       0,    69,    70,    71,    72,   172,    73,    74,    75,    76,
      77,    78,     0,     0,     0,     0,     0,     0,     0,     0,
      80,    81,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    80,    81
};

static const yytype_int16 yycheck[] =
{
      16,    33,    37,    92,    12,    40,    24,    10,    39,    12,
      36,    14,    38,     3,    45,    46,     0,    33,    25,    50,
      26,    27,    53,    54,     6,     7,    57,     6,     7,     8,
       9,     3,     3,    19,    23,     3,    52,    33,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    17,    22,
      82,    21,    19,    31,    62,    21,    21,    21,    21,     3,
      21,    20,    18,    17,   153,    96,    82,    99,    19,    49,
       3,     3,    22,    22,    19,    17,     3,     4,     5,   111,
      18,   112,   113,    99,    28,    29,    66,    31,    17,   121,
      34,    35,    36,   124,    21,   111,    40,    41,    42,    79,
      80,    81,    20,    83,    17,   121,   141,    17,    17,    20,
      30,    17,    39,    20,    17,    20,   147,    17,    17,    20,
      17,    19,    18,   154,    17,     6,     7,     8,     9,   161,
      11,    12,    13,    14,    15,    16,    19,   148,   169,    17,
      20,   173,   159,    35,    -1,   161,   123,    -1,    -1,   165,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   173,   138,   139,
     140,    -1,    -1,    -1,    -1,     6,     7,     8,     9,   149,
      11,    12,    13,    14,    15,    16,    -1,    -1,   158,    -1,
     160,    22,     6,     7,     8,     9,   166,    11,    12,    13,
      14,    15,    16,    -1,   174,    19,    37,    38,     6,     7,
       8,     9,    -1,    11,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    -1,    37,    38,    23,     6,     7,     8,     9,
      -1,    11,    12,    13,    14,    15,    16,    -1,    -1,    37,
      38,    -1,    22,     6,     7,     8,     9,    -1,    11,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    37,    38,    22,
       6,     7,     8,     9,    -1,    11,    12,    13,    14,    15,
      16,    17,    -1,    -1,    37,    38,     6,     7,     8,     9,
      -1,    11,    12,    13,    14,    15,    16,    -1,    -1,    -1,
      -1,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    -1,    -1,    -1,    -1,    37,    38,     6,
       7,     8,     9,    -1,    11,    12,    13,    14,    15,    16,
      -1,     6,     7,     8,     9,    22,    11,    12,    13,    14,
      15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    37,    38
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    24,    44,     3,     0,    45,    26,    27,    46,    50,
      25,    51,    52,     3,    48,     3,    19,    51,    23,    49,
      47,    53,     3,    28,    29,    31,    34,    35,    36,    40,
      41,    42,    60,    61,    67,     3,    17,    21,    54,    21,
      21,    33,     3,     4,     5,    21,    39,    67,    68,    19,
      31,    66,    21,    21,    21,    20,    60,    18,    49,    46,
      50,    55,    46,    64,    68,    50,    19,    68,    68,     6,
       7,     8,     9,    11,    12,    13,    14,    15,    16,    19,
      37,    38,    66,    68,    17,    67,    68,    68,    68,    10,
      12,    14,    57,    22,    51,    22,    23,    65,     3,    66,
      22,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    66,    66,    66,    60,    66,    22,    22,    22,    17,
      48,    19,    17,    68,    18,    60,    60,    68,    68,    20,
      17,    17,    17,    17,    56,    60,    65,    68,    20,    20,
      30,    17,    58,    20,    62,    66,    66,    66,    50,    17,
      17,    17,    68,    57,    66,    32,    48,    68,    19,    59,
      63,    66,    58,    66,    60,    17,    20,    67,    66,    18,
      17,    68,    22,    19,    60,    66,    20,    17
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    45,    44,    47,    46,    46,    48,    49,    49,
      50,    50,    51,    51,    53,    52,    54,    54,    56,    55,
      57,    57,    57,    59,    58,    58,    60,    60,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    62,    63,    61,
      61,    64,    65,    65,    66,    67,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     8,     0,     5,     0,     2,     3,     0,
       1,     1,     2,     0,     0,     9,     3,     0,     0,     5,
       1,     1,     1,     0,     6,     0,     2,     0,     4,     8,
       8,    15,     5,     3,     5,     5,     5,     0,     0,    22,
       5,     2,     3,     0,     0,     1,     3,     3,     3,     3,
       3,     3,     4,     4,     2,     3,     3,     3,     3,     1,
       1,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

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

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


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
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
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

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

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
  case 2: /* $@1: %empty  */
#line 79 "parser.y"
    { codigo.anadirInstruccion(*(yyvsp[-1].str) + " " + *(yyvsp[0].str) + ";"); }
#line 1570 "parser.cpp"
    break;

  case 3: /* programa: RPROGRAM TIDENTIFIER $@1 declaraciones decl_de_subprogs TLBRACE lista_de_sentencias TRBRACE  */
#line 81 "parser.y"
    { 
        codigo.anadirInstruccion("halt;"); 
        if (!hayError) codigo.escribir(); 
        codigo.desempilar(); 
    }
#line 1580 "parser.cpp"
    break;

  case 4: /* $@2: %empty  */
#line 89 "parser.y"
    { codigo.anadirDeclaraciones((yyvsp[0].lident)->lnom, (yyvsp[-1].tp)->clase); delete (yyvsp[-1].tp); delete (yyvsp[0].lident); }
#line 1586 "parser.cpp"
    break;

  case 7: /* lista_de_ident: TIDENTIFIER resto_lista_id  */
#line 95 "parser.y"
    { 
        (yyval.lident) = new lista_de_identstruct; 
        (yyval.lident)->lnom = codigo.iniLista(*(yyvsp[-1].str));
        (yyval.lident)->lnom = *codigo.unir((yyval.lident)->lnom, (yyvsp[0].rlident)->lnom);
        delete (yyvsp[0].rlident);
    }
#line 1597 "parser.cpp"
    break;

  case 8: /* resto_lista_id: TCOMMA TIDENTIFIER resto_lista_id  */
#line 104 "parser.y"
    {
        (yyval.rlident) = new resto_lista_idstruct;
        (yyval.rlident)->lnom = codigo.iniLista(*(yyvsp[-1].str));
        (yyval.rlident)->lnom = *codigo.unir((yyval.rlident)->lnom, (yyvsp[0].rlident)->lnom);
        delete (yyvsp[0].rlident);
    }
#line 1608 "parser.cpp"
    break;

  case 9: /* resto_lista_id: %empty  */
#line 110 "parser.y"
                         { (yyval.rlident) = new resto_lista_idstruct; (yyval.rlident)->lnom = codigo.iniLista(""); }
#line 1614 "parser.cpp"
    break;

  case 10: /* tipo: RINTEGER  */
#line 113 "parser.y"
                { (yyval.tp) = new tipostruct; (yyval.tp)->clase = Codigo::NUMERO_INT; }
#line 1620 "parser.cpp"
    break;

  case 11: /* tipo: RFLOAT  */
#line 114 "parser.y"
             { (yyval.tp) = new tipostruct; (yyval.tp)->clase = Codigo::NUMERO_FLOAT; }
#line 1626 "parser.cpp"
    break;

  case 14: /* $@3: %empty  */
#line 121 "parser.y"
                                              { codigo.declararProcedimiento(*(yyvsp[0].str)); }
#line 1632 "parser.cpp"
    break;

  case 15: /* decl_de_subprograma: RPROCEDURE TIDENTIFIER $@3 argumentos declaraciones decl_de_subprogs TLBRACE lista_de_sentencias TRBRACE  */
#line 122 "parser.y"
                                                         { codigo.finProcedimiento(); }
#line 1638 "parser.cpp"
    break;

  case 18: /* $@4: %empty  */
#line 130 "parser.y"
    { codigo.anadirParametros((yyvsp[0].lident)->lnom, (yyvsp[-1].cp)->tipo, (yyvsp[-2].tp)->clase); delete (yyvsp[-2].tp); delete (yyvsp[-1].cp); delete (yyvsp[0].lident); }
#line 1644 "parser.cpp"
    break;

  case 20: /* clase_par: TCGE  */
#line 135 "parser.y"
         { (yyval.cp) = new clase_parstruct; (yyval.cp)->tipo = "ref"; }
#line 1650 "parser.cpp"
    break;

  case 21: /* clase_par: TCLE  */
#line 136 "parser.y"
           { (yyval.cp) = new clase_parstruct; (yyval.cp)->tipo = "val"; }
#line 1656 "parser.cpp"
    break;

  case 22: /* clase_par: TCGLE  */
#line 137 "parser.y"
            { (yyval.cp) = new clase_parstruct; (yyval.cp)->tipo = "ref"; }
#line 1662 "parser.cpp"
    break;

  case 23: /* $@5: %empty  */
#line 141 "parser.y"
    { codigo.anadirParametros((yyvsp[0].lident)->lnom, (yyvsp[-1].cp)->tipo, (yyvsp[-2].tp)->clase); delete (yyvsp[-2].tp); delete (yyvsp[-1].cp); delete (yyvsp[0].lident); }
#line 1668 "parser.cpp"
    break;

  case 26: /* lista_de_sentencias: sentencia lista_de_sentencias  */
#line 147 "parser.y"
    { 
        (yyval.lsent) = new lista_de_sentenciasstruct; 
        (yyval.lsent)->exits = *codigo.unir((yyvsp[-1].sent)->exits, (yyvsp[0].lsent)->exits); 
        (yyval.lsent)->skips = *codigo.unir((yyvsp[-1].sent)->skips, (yyvsp[0].lsent)->skips);
        delete (yyvsp[-1].sent); delete (yyvsp[0].lsent);
    }
#line 1679 "parser.cpp"
    break;

  case 27: /* lista_de_sentencias: %empty  */
#line 154 "parser.y"
    { 
        (yyval.lsent) = new lista_de_sentenciasstruct; 
        (yyval.lsent)->exits = codigo.iniLista(0); 
        (yyval.lsent)->skips = codigo.iniLista(0); 
    }
#line 1689 "parser.cpp"
    break;

  case 28: /* sentencia: variable TASSIG expr TSEMIC  */
#line 162 "parser.y"
    {
        try {
            string tmp;
            string tipoVar = codigo.obtenerTipo((yyvsp[-3].var)->nom);

            if (codigo.esTipo(tipoVar, Codigo::NUMERO_INT) && codigo.esTipo((yyvsp[-1].expr)->tipo, Codigo::NUMERO_FLOAT)){
                tmp = codigo.nuevoId();
                codigo.anadirInstruccion(tmp + " := real2ent " + (yyvsp[-1].expr)->nom + ";");
            } else if (codigo.esTipo(tipoVar, Codigo::NUMERO_FLOAT) && codigo.esTipo((yyvsp[-1].expr)->tipo, Codigo::NUMERO_INT)) {
                tmp = codigo.nuevoId();
                codigo.anadirInstruccion(tmp + " := ent2real " + (yyvsp[-1].expr)->nom + ";");
            } else if (! codigo.esTipo(tipoVar, (yyvsp[-1].expr)->tipo)){
                yyerror(string("Error semántico. No se puede asignara una variable de tipo " + (yyvsp[-1].expr)->tipo + " a otra de tipo " + tipoVar + ".").c_str());
            } else {
                tmp = (yyvsp[-1].expr)->nom;
            }

            codigo.anadirInstruccion((yyvsp[-3].var)->nom + " := " + tmp + ";");
        } catch (string s) {}
        (yyval.sent) = new sentenciastruct;
        (yyval.sent)->exits = codigo.iniLista(0);
        delete (yyvsp[-3].var); delete (yyvsp[-1].expr);
    }
#line 1717 "parser.cpp"
    break;

  case 29: /* sentencia: RIF expr TLBRACE M lista_de_sentencias TRBRACE M TSEMIC  */
#line 186 "parser.y"
    {	
        try {
            codigo.comprobarTipos((yyvsp[-6].expr)->tipo, Codigo::BOOLEANO);
            codigo.completarInstrucciones((yyvsp[-6].expr)->trues, (yyvsp[-4].m)->ref);
            codigo.completarInstrucciones((yyvsp[-6].expr)->falses, (yyvsp[-1].m)->ref);
            (yyval.sent) = new sentenciastruct; 
            (yyval.sent)->exits = (yyvsp[-3].lsent)->exits;
            (yyval.sent)->skips = (yyvsp[-3].lsent)->skips;
            delete (yyvsp[-6].expr); delete (yyvsp[-4].m); delete (yyvsp[-3].lsent); delete (yyvsp[-1].m);
        } catch (string s) {
            yyerror("Error semántico. La condición de la estructura IF debe ser de tipo Codigo::BOOLEANO.");
        }
    }
#line 1735 "parser.cpp"
    break;

  case 30: /* sentencia: RWHILE RFOREVER TLBRACE M lista_de_sentencias TRBRACE M TSEMIC  */
#line 200 "parser.y"
    {
        codigo.anadirInstruccion("goto" + to_string((yyvsp[-4].m)->ref) + ";");
        codigo.completarInstrucciones((yyvsp[-3].lsent)->exits, (yyvsp[-1].m)->ref + 1);
        (yyval.sent) = new sentenciastruct;
        (yyval.sent)->exits = codigo.iniLista(0);
        (yyval.sent)->skips = codigo.iniLista(0);
        delete (yyvsp[-4].m); delete (yyvsp[-3].lsent); delete (yyvsp[-1].m);
    }
#line 1748 "parser.cpp"
    break;

  case 31: /* sentencia: RDO TLBRACE M lista_de_sentencias TRBRACE RUNTIL M expr RELSE TLBRACE M lista_de_sentencias TRBRACE M TSEMIC  */
#line 209 "parser.y"
    {
        codigo.completarInstrucciones((yyvsp[-7].expr)->trues, (yyvsp[-4].m)->ref);
        codigo.completarInstrucciones((yyvsp[-7].expr)->falses, (yyvsp[-12].m)->ref);
        codigo.completarInstrucciones((yyvsp[-11].lsent)->skips, (yyvsp[-8].m)->ref);
        codigo.completarInstrucciones((yyvsp[-11].lsent)->exits, (yyvsp[-1].m)->ref);
        codigo.completarInstrucciones((yyvsp[-3].lsent)->exits, (yyvsp[-1].m)->ref);
        (yyval.sent) = new sentenciastruct;
        (yyval.sent)->exits = codigo.iniLista(0);
        (yyval.sent)->skips = codigo.iniLista(0);
        delete (yyvsp[-12].m); delete (yyvsp[-11].lsent); delete (yyvsp[-8].m); delete (yyvsp[-7].expr); delete (yyvsp[-4].m); delete (yyvsp[-3].lsent); delete (yyvsp[-1].m);
    }
#line 1764 "parser.cpp"
    break;

  case 32: /* sentencia: RSKIP RIF expr M TSEMIC  */
#line 221 "parser.y"
    {
        codigo.completarInstrucciones((yyvsp[-2].expr)->falses, (yyvsp[-1].m)->ref);
        (yyval.sent) = new sentenciastruct;
        (yyval.sent)->exits = codigo.iniLista(0);
        (yyval.sent)->skips = (yyvsp[-2].expr)->trues;
        delete (yyvsp[-2].expr); delete (yyvsp[-1].m);
    }
#line 1776 "parser.cpp"
    break;

  case 33: /* sentencia: REXIT M TSEMIC  */
#line 229 "parser.y"
    {
        (yyval.sent) = new sentenciastruct;
        (yyval.sent)->exits = codigo.iniLista(codigo.obtenRef());
        (yyval.sent)->skips = codigo.iniLista(0);
        codigo.anadirInstruccion("goto");
    }
#line 1787 "parser.cpp"
    break;

  case 34: /* sentencia: RREAD TLPAREN variable TRPAREN TSEMIC  */
#line 236 "parser.y"
    {
        codigo.anadirInstruccion("read " + (yyvsp[-2].var)->nom + ";");
        (yyval.sent) = new sentenciastruct; 
        (yyval.sent)->exits = codigo.iniLista(0);
        (yyval.sent)->skips = codigo.iniLista(0);
        delete (yyvsp[-2].var);
    }
#line 1799 "parser.cpp"
    break;

  case 35: /* sentencia: RPRINT TLPAREN expr TRPAREN TSEMIC  */
#line 244 "parser.y"
        {
		codigo.anadirInstruccion("write " + (yyvsp[-2].expr)->nom + ";");
		(yyval.sent) = new sentenciastruct; 
        (yyval.sent)->exits = codigo.iniLista(0);
        (yyval.sent)->skips = codigo.iniLista(0);
		delete (yyvsp[-2].expr);
	}
#line 1811 "parser.cpp"
    break;

  case 36: /* sentencia: RPRINTLN TLPAREN expr TRPAREN TSEMIC  */
#line 252 "parser.y"
    {
        codigo.anadirInstruccion("write " + (yyvsp[-2].expr)->nom + ";");
        codigo.anadirInstruccion("writeln;");
        (yyval.sent) = new sentenciastruct; 
        (yyval.sent)->exits = codigo.iniLista(0);
        (yyval.sent)->skips = codigo.iniLista(0);
        delete (yyvsp[-2].expr);
    }
#line 1824 "parser.cpp"
    break;

  case 37: /* $@6: %empty  */
#line 261 "parser.y"
    {
        string variableAsignar;
        try {
            codigo.comprobarTipos((yyvsp[0].expr)->tipo, (yyvsp[-3].tp)->clase);
            variableAsignar = (yyvsp[0].expr)->nom;
        } catch (string s) {
            if (codigo.esTipo((yyvsp[-3].tp)->clase, Codigo::NUMERO_INT)) {
                variableAsignar = codigo.nuevoId();
                codigo.anadirInstruccion(variableAsignar + " := real2ent " + (yyvsp[0].expr)->nom + ";");
            } else if (codigo.esTipo((yyvsp[-3].tp)->clase, Codigo::NUMERO_FLOAT)) {
                variableAsignar = codigo.nuevoId();
                codigo.anadirInstruccion(variableAsignar + " := ent2real " + (yyvsp[0].expr)->nom + ";");
            } else {
                yyerror(s.c_str());
            }
        }
        TablaSimbolos ts;
        codigo.empilar(ts);
        codigo.anadirDeclaraciones(codigo.iniLista(*(yyvsp[-2].str)), (yyvsp[-3].tp)->clase);
        codigo.anadirInstruccion(*(yyvsp[-2].str) + " := " + variableAsignar + ";");
    }
#line 1850 "parser.cpp"
    break;

  case 38: /* $@7: %empty  */
#line 283 "parser.y"
    {
        try {
            codigo.comprobarTipos((yyvsp[0].expr)->tipo, Codigo::BOOLEANO);
        } catch (string s) {
            yyerror("Error semántico. La condición de parada debe ser de tipo booleano! ");
        }
    }
#line 1862 "parser.cpp"
    break;

  case 39: /* sentencia: RFOR TLPAREN tipo TIDENTIFIER TASSIG expr $@6 TSEMIC M expr $@7 M TSEMIC variable TASSIG expr TRPAREN TLBRACE lista_de_sentencias M TRBRACE TSEMIC  */
#line 291 "parser.y"
    {
        if (*(yyvsp[-18].str) != (yyvsp[-8].var)->nom) {
			yyerror(string("Error semántico. Se debe actualizar la variable " + string(*(yyvsp[-18].str)) + " no la variable " + (yyvsp[-8].var)->nom + ".").c_str());
		}
		try{
			codigo.comprobarTipos((yyvsp[-8].var)->tipo, (yyvsp[-6].expr)->tipo);
			codigo.anadirInstruccion((yyvsp[-8].var)->nom + " := " + (yyvsp[-6].expr)->nom + ";");
			codigo.anadirInstruccion("goto " + to_string((yyvsp[-13].m)->ref) + ";");
			codigo.completarInstrucciones((yyvsp[-12].expr)->trues, (yyvsp[-10].m)->ref);
			codigo.completarInstrucciones((yyvsp[-12].expr)->falses, (yyvsp[-2].m)->ref + 2);
			codigo.completarInstrucciones((yyvsp[-3].lsent)->exits, (yyvsp[-2].m)->ref + 2);
		} catch (string s){
			yyerror(s.c_str());
		}
		codigo.desempilar();
		(yyval.sent) = new sentenciastruct; (yyval.sent)->exits = codigo.iniLista(0); (yyval.sent)->skips = codigo.iniLista(0);
		delete (yyvsp[-19].tp); delete (yyvsp[-16].expr); delete (yyvsp[-13].m); delete (yyvsp[-12].expr); delete (yyvsp[-10].m); delete (yyvsp[-8].var); delete (yyvsp[-6].expr); delete (yyvsp[-3].lsent); delete (yyvsp[-2].m);
    }
#line 1885 "parser.cpp"
    break;

  case 40: /* sentencia: TIDENTIFIER TLPAREN lista_de_argumentos TRPAREN TSEMIC  */
#line 310 "parser.y"
    {
        try {
            codigo.llamadaProcedimiento(*(yyvsp[-4].str), (yyvsp[-2].arg)->lparam);
        } catch (string s) {
            yyerror(s.c_str());
        }
        (yyval.sent) = new sentenciastruct; 
        (yyval.sent)->exits = codigo.iniLista(0);
        (yyval.sent)->skips = codigo.iniLista(0);
        delete (yyvsp[-2].arg);
    }
#line 1901 "parser.cpp"
    break;

  case 41: /* lista_de_argumentos: expr resto_lista_argumentos  */
#line 324 "parser.y"
    {
        (yyval.arg) = new argumentostruct;
        (yyval.arg)->lparam = codigo.iniLista((yyvsp[-1].expr)->nom, (yyvsp[-1].expr)->tipo);
        (yyval.arg)->lparam = *codigo.unir((yyval.arg)->lparam, (yyvsp[0].arg)->lparam);
        delete (yyvsp[-1].expr); delete (yyvsp[0].arg);
    }
#line 1912 "parser.cpp"
    break;

  case 42: /* resto_lista_argumentos: TCOMMA expr resto_lista_argumentos  */
#line 333 "parser.y"
    {
        (yyval.arg) = new argumentostruct;
        (yyval.arg)->lparam = codigo.iniLista((yyvsp[-1].expr)->nom, (yyvsp[-1].expr)->tipo);
        (yyval.arg)->lparam = *codigo.unir((yyval.arg)->lparam, (yyvsp[0].arg)->lparam);
        delete (yyvsp[-1].expr); delete (yyvsp[0].arg);
    }
#line 1923 "parser.cpp"
    break;

  case 43: /* resto_lista_argumentos: %empty  */
#line 339 "parser.y"
             {(yyval.arg) = new argumentostruct; (yyval.arg)->lparam = codigo.iniLista("", "");}
#line 1929 "parser.cpp"
    break;

  case 44: /* M: %empty  */
#line 342 "parser.y"
          { (yyval.m) = new mstruct; (yyval.m)->ref = codigo.obtenRef(); }
#line 1935 "parser.cpp"
    break;

  case 45: /* variable: TIDENTIFIER  */
#line 345 "parser.y"
    { 
        string tipo;
        try {
            tipo = codigo.obtenerTipo(*(yyvsp[0].str));
        } catch (string s) {
            yyerror(s.c_str());
        }
        (yyval.var) = new variablestruct; 
        (yyval.var)->nom = *(yyvsp[0].str);
        (yyval.var)->tipo = tipo;
    }
#line 1951 "parser.cpp"
    break;

  case 46: /* expr: expr TEQUAL expr  */
#line 360 "parser.y"
    {
        try {
            codigo.comprobarTipos((yyvsp[-2].expr)->tipo, (yyvsp[0].expr)->tipo);
        } catch (string s) {
            yyerror(s.c_str());
        }
        (yyval.expr) = new expresionstruct;
        (yyval.expr)->nom = codigo.iniNom();
        (yyval.expr)->trues = codigo.iniLista(codigo.obtenRef());
        (yyval.expr)->falses = codigo.iniLista(codigo.obtenRef()+1);
        codigo.anadirInstruccion("if " + (yyvsp[-2].expr)->nom + " = " + (yyvsp[0].expr)->nom + " goto");
        codigo.anadirInstruccion("goto");
        delete (yyvsp[-2].expr); delete (yyvsp[0].expr);
    }
#line 1970 "parser.cpp"
    break;

  case 47: /* expr: expr TCGT expr  */
#line 375 "parser.y"
    {
        try {
            codigo.comprobarTipos((yyvsp[-2].expr)->tipo, Codigo::NUMERO);
            codigo.comprobarTipos((yyvsp[0].expr)->tipo, Codigo::NUMERO);
        } catch (string s) {
            yyerror(s.c_str());
        }
        (yyval.expr) = new expresionstruct;
        (yyval.expr)->nom = codigo.iniNom();
        (yyval.expr)->trues = codigo.iniLista(codigo.obtenRef());
        (yyval.expr)->falses = codigo.iniLista(codigo.obtenRef()+1);
        codigo.anadirInstruccion("if " + (yyvsp[-2].expr)->nom + " > " + (yyvsp[0].expr)->nom + " goto");
        codigo.anadirInstruccion("goto");
        delete (yyvsp[-2].expr); delete (yyvsp[0].expr);
    }
#line 1990 "parser.cpp"
    break;

  case 48: /* expr: expr TCLT expr  */
#line 391 "parser.y"
    {
        try {
            codigo.comprobarTipos((yyvsp[-2].expr)->tipo, Codigo::NUMERO);
            codigo.comprobarTipos((yyvsp[0].expr)->tipo, Codigo::NUMERO);
        } catch (string s) {
            yyerror(s.c_str());
        }
        (yyval.expr) = new expresionstruct;
        (yyval.expr)->nom = codigo.iniNom();
        (yyval.expr)->trues = codigo.iniLista(codigo.obtenRef());
        (yyval.expr)->falses = codigo.iniLista(codigo.obtenRef()+1);
        codigo.anadirInstruccion("if " + (yyvsp[-2].expr)->nom + " < " + (yyvsp[0].expr)->nom + " goto");
        codigo.anadirInstruccion("goto");
        delete (yyvsp[-2].expr); delete (yyvsp[0].expr);
    }
#line 2010 "parser.cpp"
    break;

  case 49: /* expr: expr TCGE expr  */
#line 407 "parser.y"
    {
        try {
            codigo.comprobarTipos((yyvsp[-2].expr)->tipo, Codigo::NUMERO);
            codigo.comprobarTipos((yyvsp[0].expr)->tipo, Codigo::NUMERO);
        } catch (string s) {
            yyerror(s.c_str());
        }
        (yyval.expr) = new expresionstruct;
        (yyval.expr)->nom = codigo.iniNom();
        (yyval.expr)->trues = codigo.iniLista(codigo.obtenRef());
        (yyval.expr)->falses = codigo.iniLista(codigo.obtenRef()+1);
        codigo.anadirInstruccion("if " + (yyvsp[-2].expr)->nom + " >= " + (yyvsp[0].expr)->nom + " goto");
        codigo.anadirInstruccion("goto");
        delete (yyvsp[-2].expr); delete (yyvsp[0].expr);
    }
#line 2030 "parser.cpp"
    break;

  case 50: /* expr: expr TCLE expr  */
#line 423 "parser.y"
    {
        try {
            codigo.comprobarTipos((yyvsp[-2].expr)->tipo, Codigo::NUMERO);
            codigo.comprobarTipos((yyvsp[0].expr)->tipo, Codigo::NUMERO);
        } catch (string s) {
            yyerror(s.c_str());
        }
        (yyval.expr) = new expresionstruct;
        (yyval.expr)->nom = codigo.iniNom();
        (yyval.expr)->trues = codigo.iniLista(codigo.obtenRef());
        (yyval.expr)->falses = codigo.iniLista(codigo.obtenRef()+1);
        codigo.anadirInstruccion("if " + (yyvsp[-2].expr)->nom + " <= " + (yyvsp[0].expr)->nom + " goto");
        codigo.anadirInstruccion("goto");
        delete (yyvsp[-2].expr); delete (yyvsp[0].expr);
    }
#line 2050 "parser.cpp"
    break;

  case 51: /* expr: expr TNEQUAL expr  */
#line 439 "parser.y"
    {
        try {
            codigo.comprobarTipos((yyvsp[-2].expr)->tipo, (yyvsp[0].expr)->tipo);
        } catch (string s) {
            yyerror(s.c_str());
        }
        (yyval.expr) = new expresionstruct;
        (yyval.expr)->nom = codigo.iniNom();
        (yyval.expr)->trues = codigo.iniLista(codigo.obtenRef());
        (yyval.expr)->falses = codigo.iniLista(codigo.obtenRef()+1);
        codigo.anadirInstruccion("if " + (yyvsp[-2].expr)->nom + " /= " + (yyvsp[0].expr)->nom + " goto");
        codigo.anadirInstruccion("goto");
        delete (yyvsp[-2].expr); delete (yyvsp[0].expr);
    }
#line 2069 "parser.cpp"
    break;

  case 52: /* expr: expr RAND M expr  */
#line 454 "parser.y"
    {
        try {
            codigo.comprobarTipos((yyvsp[-3].expr)->tipo, Codigo::BOOLEANO);
            codigo.comprobarTipos((yyvsp[0].expr)->tipo, Codigo::BOOLEANO);
        } catch (string s) {
            yyerror(s.c_str());
        }
        (yyval.expr) = new expresionstruct;
        (yyval.expr)->nom = codigo.iniNom();
        (yyval.expr)->tipo = Codigo::BOOLEANO;
        codigo.completarInstrucciones((yyvsp[-3].expr)->trues, (yyvsp[-1].m)->ref);
        (yyval.expr)->trues = (yyvsp[0].expr)->trues;
        (yyval.expr)->falses = *codigo.unir((yyvsp[-3].expr)->falses, (yyvsp[0].expr)->falses);
        delete (yyvsp[-3].expr); delete (yyvsp[-1].m);
    }
#line 2089 "parser.cpp"
    break;

  case 53: /* expr: expr ROR M expr  */
#line 470 "parser.y"
    {
        try {
            codigo.comprobarTipos((yyvsp[-3].expr)->tipo, Codigo::BOOLEANO);
            codigo.comprobarTipos((yyvsp[0].expr)->tipo, Codigo::BOOLEANO);
        } catch (string s) {
            yyerror(s.c_str());
        }
        (yyval.expr) = new expresionstruct;
        (yyval.expr)->nom = codigo.iniNom();
        (yyval.expr)->tipo = Codigo::BOOLEANO;
        codigo.completarInstrucciones((yyvsp[-3].expr)->falses, (yyvsp[-1].m)->ref);
        (yyval.expr)->trues = *codigo.unir((yyvsp[-3].expr)->trues, (yyvsp[0].expr)->trues);
        (yyval.expr)->falses = (yyvsp[0].expr)->falses;
        delete (yyvsp[-3].expr); delete (yyvsp[-1].m);
    }
#line 2109 "parser.cpp"
    break;

  case 54: /* expr: RNOT expr  */
#line 486 "parser.y"
    {
        try {
            codigo.comprobarTipos((yyvsp[0].expr)->tipo, Codigo::BOOLEANO);
        } catch (string s) {
            yyerror(s.c_str());
        }
        (yyval.expr) = new expresionstruct;
        (yyval.expr)->nom = codigo.iniNom();
        (yyval.expr)->tipo = Codigo::BOOLEANO;
        (yyval.expr)->trues = (yyvsp[0].expr)->falses;
        (yyval.expr)->falses = (yyvsp[0].expr)->trues;
    }
#line 2126 "parser.cpp"
    break;

  case 55: /* expr: expr TPLUS expr  */
#line 499 "parser.y"
    {
        (yyval.expr) = new expresionstruct;
        try {
            codigo.operacionAritmetica((yyval.expr), *(yyvsp[-2].expr), *(yyvsp[0].expr), *(yyvsp[-1].str)); // ultimo parametro tambien puede ser *$2
        } catch (string s) {
            yyerror(s.c_str());
            (yyval.expr)->nom = codigo.iniNom();
            (yyval.expr)->tipo = (yyvsp[-2].expr)->tipo;
            (yyval.expr)->trues = codigo.iniLista(0);
            (yyval.expr)->falses = codigo.iniLista(0);
        }
        delete (yyvsp[-2].expr); delete (yyvsp[0].expr);
    }
#line 2144 "parser.cpp"
    break;

  case 56: /* expr: expr TMINUS expr  */
#line 513 "parser.y"
    {
        (yyval.expr) = new expresionstruct;
        try {
            codigo.operacionAritmetica((yyval.expr), *(yyvsp[-2].expr), *(yyvsp[0].expr), "-"); // ultimo parametro tambien puede ser *$2
        } catch (string s) {
            yyerror(s.c_str());
            (yyval.expr)->nom = codigo.iniNom();
            (yyval.expr)->tipo = (yyvsp[-2].expr)->tipo;
            (yyval.expr)->trues = codigo.iniLista(0);
            (yyval.expr)->falses = codigo.iniLista(0);
        }
        delete (yyvsp[-2].expr); delete (yyvsp[0].expr);
    }
#line 2162 "parser.cpp"
    break;

  case 57: /* expr: expr TMUL expr  */
#line 527 "parser.y"
    {
        (yyval.expr) = new expresionstruct;
        try {
            codigo.operacionAritmetica((yyval.expr), *(yyvsp[-2].expr), *(yyvsp[0].expr), "*"); // ultimo parametro tambien puede ser *$2
        } catch (string s) {
            yyerror(s.c_str());
            (yyval.expr)->nom = codigo.iniNom();
            (yyval.expr)->tipo = (yyvsp[-2].expr)->tipo;
            (yyval.expr)->trues = codigo.iniLista(0);
            (yyval.expr)->falses = codigo.iniLista(0);
        }
        delete (yyvsp[-2].expr); delete (yyvsp[0].expr);
    }
#line 2180 "parser.cpp"
    break;

  case 58: /* expr: expr TDIV expr  */
#line 541 "parser.y"
    {
        (yyval.expr) = new expresionstruct;
        codigo.anadirInstruccion("if " + (yyvsp[0].expr)->nom + " = 0 goto ErrorDiv0;");
        try {    
            codigo.operacionAritmetica((yyval.expr), *(yyvsp[-2].expr), *(yyvsp[0].expr), "/"); // ultimo parametro tambien puede ser *$2
        } catch (string s) {
            yyerror(s.c_str());
            (yyval.expr)->nom = codigo.iniNom();
            (yyval.expr)->tipo = (yyvsp[-2].expr)->tipo;
            (yyval.expr)->trues = codigo.iniLista(0);
            (yyval.expr)->falses = codigo.iniLista(0);
        }
        delete (yyvsp[-2].expr); delete (yyvsp[0].expr);
    }
#line 2199 "parser.cpp"
    break;

  case 59: /* expr: variable  */
#line 556 "parser.y"
    {
        (yyval.expr) = new expresionstruct;
        (yyval.expr)->nom = (yyvsp[0].var)->nom;
        (yyval.expr)->tipo = (yyvsp[0].var)->tipo;
        (yyval.expr)->trues = codigo.iniLista(0);
        (yyval.expr)->falses = codigo.iniLista(0);
        delete (yyvsp[0].var);
    }
#line 2212 "parser.cpp"
    break;

  case 60: /* expr: TINTEGER  */
#line 565 "parser.y"
    {
        (yyval.expr) = new expresionstruct;
        (yyval.expr)->nom = *(yyvsp[0].str);
        (yyval.expr)->tipo = Codigo::NUMERO_INT;
        (yyval.expr)->trues = codigo.iniLista(0);
        (yyval.expr)->falses = codigo.iniLista(0);
    }
#line 2224 "parser.cpp"
    break;

  case 61: /* expr: TDOUBLE  */
#line 573 "parser.y"
    {
        (yyval.expr) = new expresionstruct;
        (yyval.expr)->nom = *(yyvsp[0].str);
        (yyval.expr)->tipo = Codigo::NUMERO_FLOAT;
        (yyval.expr)->trues = codigo.iniLista(0);
        (yyval.expr)->falses = codigo.iniLista(0);
    }
#line 2236 "parser.cpp"
    break;

  case 62: /* expr: TLPAREN expr TRPAREN  */
#line 581 "parser.y"
    {
        (yyval.expr) = (yyvsp[-1].expr);
    }
#line 2244 "parser.cpp"
    break;


#line 2248 "parser.cpp"

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
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
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          goto yyexhaustedlab;
      }
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
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if 1
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
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

