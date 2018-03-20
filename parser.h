/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
    BREAK = 259,
    CONTINUE = 260,
    AND = 261,
    OR = 262,
    NOT = 263,
    GREATEREQUAL = 264,
    LESSEQUAL = 265,
    EQUAL = 266,
    NOTEQUAL = 267,
    UMINUS = 268,
    PLUSPLUS = 269,
    MINUSMINUS = 270,
    LOCAL = 271,
    SCOPEOP = 272,
    DOUPLEDOT = 273,
    FUNCTION = 274,
    NUMBER = 275,
    STRING = 276,
    NIL = 277,
    TRUE = 278,
    FALSE = 279,
    IF = 280,
    ELSE = 281,
    WHILE = 282,
    FOR = 283,
    RETURN = 284
  };
#endif
/* Tokens.  */
#define ID 258
#define BREAK 259
#define CONTINUE 260
#define AND 261
#define OR 262
#define NOT 263
#define GREATEREQUAL 264
#define LESSEQUAL 265
#define EQUAL 266
#define NOTEQUAL 267
#define UMINUS 268
#define PLUSPLUS 269
#define MINUSMINUS 270
#define LOCAL 271
#define SCOPEOP 272
#define DOUPLEDOT 273
#define FUNCTION 274
#define NUMBER 275
#define STRING 276
#define NIL 277
#define TRUE 278
#define FALSE 279
#define IF 280
#define ELSE 281
#define WHILE 282
#define FOR 283
#define RETURN 284

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */
