#ifndef YY_parser_name_h_included
#define YY_parser_name_h_included
/*#define YY_USE_CLASS 
*/
#line 1 "/usr/share/bison++/bison.h"
/* before anything */
#ifdef c_plusplus
 #ifndef __cplusplus
  #define __cplusplus
 #endif
#endif


 #line 8 "/usr/share/bison++/bison.h"

#line 21 "/usr/share/bison++/bison.h"
 /* %{ and %header{ and %union, during decl */
#ifndef YY_parser_name_COMPATIBILITY
 #ifndef YY_USE_CLASS
  #define  YY_parser_name_COMPATIBILITY 1
 #else
  #define  YY_parser_name_COMPATIBILITY 0
 #endif
#endif

#if YY_parser_name_COMPATIBILITY != 0
/* backward compatibility */
 #ifdef YYLTYPE
  #ifndef YY_parser_name_LTYPE
   #define YY_parser_name_LTYPE YYLTYPE
/* WARNING obsolete !!! user defined YYLTYPE not reported into generated header */
/* use %define LTYPE */
  #endif
 #endif
/*#ifdef YYSTYPE*/
  #ifndef YY_parser_name_STYPE
   #define YY_parser_name_STYPE YYSTYPE
  /* WARNING obsolete !!! user defined YYSTYPE not reported into generated header */
   /* use %define STYPE */
  #endif
/*#endif*/
 #ifdef YYDEBUG
  #ifndef YY_parser_name_DEBUG
   #define  YY_parser_name_DEBUG YYDEBUG
   /* WARNING obsolete !!! user defined YYDEBUG not reported into generated header */
   /* use %define DEBUG */
  #endif
 #endif 
 /* use goto to be compatible */
 #ifndef YY_parser_name_USE_GOTO
  #define YY_parser_name_USE_GOTO 1
 #endif
#endif

/* use no goto to be clean in C++ */
#ifndef YY_parser_name_USE_GOTO
 #define YY_parser_name_USE_GOTO 0
#endif

#ifndef YY_parser_name_PURE

 #line 65 "/usr/share/bison++/bison.h"

#line 65 "/usr/share/bison++/bison.h"
/* YY_parser_name_PURE */
#endif


 #line 68 "/usr/share/bison++/bison.h"
#ifndef YY_USE_CLASS
# ifndef YYSTYPE
#  define YYSTYPE int
#  define YYSTYPE_IS_TRIVIAL 1
# endif
#endif

#line 68 "/usr/share/bison++/bison.h"
/* prefix */

#ifndef YY_parser_name_DEBUG

 #line 71 "/usr/share/bison++/bison.h"

#line 71 "/usr/share/bison++/bison.h"
/* YY_parser_name_DEBUG */
#endif

#ifndef YY_parser_name_LSP_NEEDED

 #line 75 "/usr/share/bison++/bison.h"

#line 75 "/usr/share/bison++/bison.h"
 /* YY_parser_name_LSP_NEEDED*/
#endif

/* DEFAULT LTYPE*/
#ifdef YY_parser_name_LSP_NEEDED
 #ifndef YY_parser_name_LTYPE
  #ifndef BISON_YYLTYPE_ISDECLARED
   #define BISON_YYLTYPE_ISDECLARED
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;
  #endif

  #define YY_parser_name_LTYPE yyltype
 #endif
#endif

/* DEFAULT STYPE*/
#ifndef YY_parser_name_STYPE
 #define YY_parser_name_STYPE int
#endif

/* DEFAULT MISCELANEOUS */
#ifndef YY_parser_name_PARSE
 #define YY_parser_name_PARSE yyparse
#endif

#ifndef YY_parser_name_LEX
 #define YY_parser_name_LEX yylex
#endif

#ifndef YY_parser_name_LVAL
 #define YY_parser_name_LVAL yylval
#endif

#ifndef YY_parser_name_LLOC
 #define YY_parser_name_LLOC yylloc
#endif

#ifndef YY_parser_name_CHAR
 #define YY_parser_name_CHAR yychar
#endif

#ifndef YY_parser_name_NERRS
 #define YY_parser_name_NERRS yynerrs
#endif

#ifndef YY_parser_name_DEBUG_FLAG
 #define YY_parser_name_DEBUG_FLAG yydebug
#endif

#ifndef YY_parser_name_ERROR
 #define YY_parser_name_ERROR yyerror
#endif

#ifndef YY_parser_name_PARSE_PARAM
 #ifndef __STDC__
  #ifndef __cplusplus
   #ifndef YY_USE_CLASS
    #define YY_parser_name_PARSE_PARAM
    #ifndef YY_parser_name_PARSE_PARAM_DEF
     #define YY_parser_name_PARSE_PARAM_DEF
    #endif
   #endif
  #endif
 #endif
 #ifndef YY_parser_name_PARSE_PARAM
  #define YY_parser_name_PARSE_PARAM void
 #endif
#endif

/* TOKEN C */
#ifndef YY_USE_CLASS

 #ifndef YY_parser_name_PURE
  #ifndef yylval
   extern YY_parser_name_STYPE YY_parser_name_LVAL;
  #else
   #if yylval != YY_parser_name_LVAL
    extern YY_parser_name_STYPE YY_parser_name_LVAL;
   #else
    #warning "Namespace conflict, disabling some functionality (bison++ only)"
   #endif
  #endif
 #endif


 #line 169 "/usr/share/bison++/bison.h"
#define	ID	258
#define	BREAK	259
#define	CONTINUE	260
#define	AND	261
#define	OR	262
#define	NOT	263
#define	GREATER	264
#define	GREATEREQUAL	265
#define	LESS	266
#define	LESSEQUAL	267
#define	EQUAL	268
#define	NOTEQUAL	269
#define	UMINUS	270
#define	PLUSPLUS	271
#define	MINUSMINUS	272
#define	LOCAL	273
#define	SCOPEOP	274
#define	DOUPLEDOT	275
#define	FUNCTION	276
#define	NUMBER	277
#define	STRING	278
#define	NIL	279
#define	TRUE	280
#define	FALSE	281
#define	IF	282
#define	ELSE	283
#define	WHILE	284
#define	FOR	285
#define	RETURN	286


#line 169 "/usr/share/bison++/bison.h"
 /* #defines token */
/* after #define tokens, before const tokens S5*/
#else
 #ifndef YY_parser_name_CLASS
  #define YY_parser_name_CLASS parser_name
 #endif

 #ifndef YY_parser_name_INHERIT
  #define YY_parser_name_INHERIT
 #endif

 #ifndef YY_parser_name_MEMBERS
  #define YY_parser_name_MEMBERS 
 #endif

 #ifndef YY_parser_name_LEX_BODY
  #define YY_parser_name_LEX_BODY  
 #endif

 #ifndef YY_parser_name_ERROR_BODY
  #define YY_parser_name_ERROR_BODY  
 #endif

 #ifndef YY_parser_name_CONSTRUCTOR_PARAM
  #define YY_parser_name_CONSTRUCTOR_PARAM
 #endif
 /* choose between enum and const */
 #ifndef YY_parser_name_USE_CONST_TOKEN
  #define YY_parser_name_USE_CONST_TOKEN 0
  /* yes enum is more compatible with flex,  */
  /* so by default we use it */ 
 #endif
 #if YY_parser_name_USE_CONST_TOKEN != 0
  #ifndef YY_parser_name_ENUM_TOKEN
   #define YY_parser_name_ENUM_TOKEN yy_parser_name_enum_token
  #endif
 #endif

class YY_parser_name_CLASS YY_parser_name_INHERIT
{
public: 
 #if YY_parser_name_USE_CONST_TOKEN != 0
  /* static const int token ... */
  
 #line 212 "/usr/share/bison++/bison.h"
static const int ID;
static const int BREAK;
static const int CONTINUE;
static const int AND;
static const int OR;
static const int NOT;
static const int GREATER;
static const int GREATEREQUAL;
static const int LESS;
static const int LESSEQUAL;
static const int EQUAL;
static const int NOTEQUAL;
static const int UMINUS;
static const int PLUSPLUS;
static const int MINUSMINUS;
static const int LOCAL;
static const int SCOPEOP;
static const int DOUPLEDOT;
static const int FUNCTION;
static const int NUMBER;
static const int STRING;
static const int NIL;
static const int TRUE;
static const int FALSE;
static const int IF;
static const int ELSE;
static const int WHILE;
static const int FOR;
static const int RETURN;


#line 212 "/usr/share/bison++/bison.h"
 /* decl const */
 #else
  enum YY_parser_name_ENUM_TOKEN { YY_parser_name_NULL_TOKEN=0
  
 #line 215 "/usr/share/bison++/bison.h"
	,ID=258
	,BREAK=259
	,CONTINUE=260
	,AND=261
	,OR=262
	,NOT=263
	,GREATER=264
	,GREATEREQUAL=265
	,LESS=266
	,LESSEQUAL=267
	,EQUAL=268
	,NOTEQUAL=269
	,UMINUS=270
	,PLUSPLUS=271
	,MINUSMINUS=272
	,LOCAL=273
	,SCOPEOP=274
	,DOUPLEDOT=275
	,FUNCTION=276
	,NUMBER=277
	,STRING=278
	,NIL=279
	,TRUE=280
	,FALSE=281
	,IF=282
	,ELSE=283
	,WHILE=284
	,FOR=285
	,RETURN=286


#line 215 "/usr/share/bison++/bison.h"
 /* enum token */
     }; /* end of enum declaration */
 #endif
public:
 int YY_parser_name_PARSE(YY_parser_name_PARSE_PARAM);
 virtual void YY_parser_name_ERROR(char *msg) YY_parser_name_ERROR_BODY;
 #ifdef YY_parser_name_PURE
  #ifdef YY_parser_name_LSP_NEEDED
   virtual int  YY_parser_name_LEX(YY_parser_name_STYPE *YY_parser_name_LVAL,YY_parser_name_LTYPE *YY_parser_name_LLOC) YY_parser_name_LEX_BODY;
  #else
   virtual int  YY_parser_name_LEX(YY_parser_name_STYPE *YY_parser_name_LVAL) YY_parser_name_LEX_BODY;
  #endif
 #else
  virtual int YY_parser_name_LEX() YY_parser_name_LEX_BODY;
  YY_parser_name_STYPE YY_parser_name_LVAL;
  #ifdef YY_parser_name_LSP_NEEDED
   YY_parser_name_LTYPE YY_parser_name_LLOC;
  #endif
  int YY_parser_name_NERRS;
  int YY_parser_name_CHAR;
 #endif
 #if YY_parser_name_DEBUG != 0
  public:
   int YY_parser_name_DEBUG_FLAG;	/*  nonzero means print parse trace	*/
 #endif
public:
 YY_parser_name_CLASS(YY_parser_name_CONSTRUCTOR_PARAM);
public:
 YY_parser_name_MEMBERS 
};
/* other declare folow */
#endif


#if YY_parser_name_COMPATIBILITY != 0
 /* backward compatibility */
 /* Removed due to bison problems
 /#ifndef YYSTYPE
 / #define YYSTYPE YY_parser_name_STYPE
 /#endif*/

 #ifndef YYLTYPE
  #define YYLTYPE YY_parser_name_LTYPE
 #endif
 #ifndef YYDEBUG
  #ifdef YY_parser_name_DEBUG 
   #define YYDEBUG YY_parser_name_DEBUG
  #endif
 #endif

#endif
/* END */

 #line 267 "/usr/share/bison++/bison.h"
#endif
