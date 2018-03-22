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
#line 16 "syntax.y" /* yacc.c:1909  */

	char* stringValue;
	float floatValue;
	//symbol_t entry* ptr pointer se struct tou symbol_t

#line 120 "parser.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */
