/* A Bison parser, made by GNU Bison 3.7.5.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TIDENTIFIER = 258,             /* TIDENTIFIER  */
    TINTEGER = 259,                /* TINTEGER  */
    TDOUBLE = 260,                 /* TDOUBLE  */
    TMUL = 261,                    /* TMUL  */
    TDIV = 262,                    /* TDIV  */
    TPLUS = 263,                   /* TPLUS  */
    TMINUS = 264,                  /* TMINUS  */
    TCGLE = 265,                   /* TCGLE  */
    TCLT = 266,                    /* TCLT  */
    TCLE = 267,                    /* TCLE  */
    TCGT = 268,                    /* TCGT  */
    TCGE = 269,                    /* TCGE  */
    TEQUAL = 270,                  /* TEQUAL  */
    TNEQUAL = 271,                 /* TNEQUAL  */
    TSEMIC = 272,                  /* TSEMIC  */
    TASSIG = 273,                  /* TASSIG  */
    TLBRACE = 274,                 /* TLBRACE  */
    TRBRACE = 275,                 /* TRBRACE  */
    TLPAREN = 276,                 /* TLPAREN  */
    TRPAREN = 277,                 /* TRPAREN  */
    TCOMMA = 278,                  /* TCOMMA  */
    RPROGRAM = 279,                /* RPROGRAM  */
    RPROCEDURE = 280,              /* RPROCEDURE  */
    RFLOAT = 281,                  /* RFLOAT  */
    RINTEGER = 282,                /* RINTEGER  */
    RFOR = 283,                    /* RFOR  */
    RWHILE = 284,                  /* RWHILE  */
    RUNTIL = 285,                  /* RUNTIL  */
    RIF = 286,                     /* RIF  */
    RELSE = 287,                   /* RELSE  */
    RFOREVER = 288,                /* RFOREVER  */
    RDO = 289,                     /* RDO  */
    RSKIP = 290,                   /* RSKIP  */
    REXIT = 291,                   /* REXIT  */
    RAND = 292,                    /* RAND  */
    ROR = 293,                     /* ROR  */
    RNOT = 294,                    /* RNOT  */
    RREAD = 295,                   /* RREAD  */
    RPRINTLN = 296,                /* RPRINTLN  */
    RPRINT = 297                   /* RPRINT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 28 "parser.y"

    std::string *str;
    lista_de_identstruct *lident;
    resto_lista_idstruct *rlident;
    tipostruct *tp;
    clase_parstruct *cp;
    lista_de_sentenciasstruct *lsent;
    sentenciastruct *sent;
    mstruct *m;
    variablestruct *var;
    expresionstruct *expr; 
    argumentostruct *arg;

#line 120 "parser.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */
