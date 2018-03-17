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
#define	GREATEREQUAL	264
#define	LESSEQUAL	265
#define	EQUAL	266
#define	NOTEQUAL	267
#define	UMINUS	268
#define	PLUSPLUS	269
#define	MINUSMINUS	270
#define	LOCAL	271
#define	SCOPEOP	272
#define	DOUPLEDOT	273
#define	FUNCTION	274
#define	NUMBER	275
#define	STRING	276
#define	NIL	277
#define	TRUE	278
#define	FALSE	279
#define	IF	280
#define	ELSE	281
#define	WHILE	282
#define	FOR	283
#define	RETURN	284


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
static const int GREATEREQUAL;
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
	,GREATEREQUAL=264
	,LESSEQUAL=265
	,EQUAL=266
	,NOTEQUAL=267
	,UMINUS=268
	,PLUSPLUS=269
	,MINUSMINUS=270
	,LOCAL=271
	,SCOPEOP=272
	,DOUPLEDOT=273
	,FUNCTION=274
	,NUMBER=275
	,STRING=276
	,NIL=277
	,TRUE=278
	,FALSE=279
	,IF=280
	,ELSE=281
	,WHILE=282
	,FOR=283
	,RETURN=284


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
