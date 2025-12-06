/* A Bison parser, made by GNU Bison 3.8.2.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
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
    NUM = 258,                     /* NUM  */
    ID = 259,                      /* ID  */
    CAD = 260,                     /* CAD  */
    PROGRAMA = 261,                /* PROGRAMA  */
    INICIO = 262,                  /* INICIO  */
    FIN = 263,                     /* FIN  */
    LEE = 264,                     /* LEE  */
    MOSTRAR = 265,                 /* MOSTRAR  */
    SI = 266,                      /* SI  */
    ENTONCES = 267,                /* ENTONCES  */
    SINO = 268,                    /* SINO  */
    MIENTRAS = 269,                /* MIENTRAS  */
    HACER = 270,                   /* HACER  */
    FINMIENTRAS = 271,             /* FINMIENTRAS  */
    EJECUTA = 272,                 /* EJECUTA  */
    VECES = 273,                   /* VECES  */
    USANDO = 274,                  /* USANDO  */
    FIN_EJECUTA = 275,             /* FIN_EJECUTA  */
    FINSI = 276,                   /* FINSI  */
    HASTAQUE = 277,                /* HASTAQUE  */
    CALCULA = 278,                 /* CALCULA  */
    FIN_CALCULA = 279,             /* FIN_CALCULA  */
    MUEVE = 280,                   /* MUEVE  */
    A = 281,                       /* A  */
    DE = 282,                      /* DE  */
    COMO = 283,                    /* COMO  */
    POR = 284,                     /* POR  */
    ES = 285,                      /* ES  */
    IGUAL = 286,                   /* IGUAL  */
    MAYOR = 287,                   /* MAYOR  */
    MENOR = 288,                   /* MENOR  */
    QUE = 289,                     /* QUE  */
    SUMA = 290,                    /* SUMA  */
    RESTA = 291,                   /* RESTA  */
    MULTIPLICA = 292,              /* MULTIPLICA  */
    DIVIDE = 293,                  /* DIVIDE  */
    DANDO = 294                    /* DANDO  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 28 "parser.y"

  int num;
  char *id;
  char *cad;
  LoopVecesInfo *loop;

#line 110 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
