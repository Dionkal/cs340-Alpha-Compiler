%{
	#include <stdlib.h>
	#include <stdio.h>
	int yyerror (char *yaccProvidedMessage);
	int yylex(void);

	extern int yylineno;
	extern char* yytext;
	extern FILE* yyin;

%}

%start 	program

%union {
	char* stringValue;
	float floatValue;
	//symbol_t entry* ptr pointer se struct tou symbol_t
}

%token <stringValue> ID 
%token <floatValue> NUMBER
%token <stringValue> STRING 
%token BREAK CONTINUE AND OR NOT GREATEREQUAL LESSEQUAL EQUAL NOTEQUAL  PLUSPLUS MINUSMINUS LOCAL SCOPEOP DOUBLEDOT FUNCTION NIL TRUE FALSE IF ELSE WHILE FOR RETURN

//%type<ptr> expr

%left '(' ')' 
%left '[' ']'
%left '.' DOUBLEDOT
%right NOT PLUSPLUS MINUSMINUS UMINUS 
%left '*' '/' '%'
%left '+' '-'
%nonassoc '>' GREATEREQUAL '<' LESSEQUAL
%nonassoc EQUAL NOTEQUAL
%left AND
%left OR
%right '='



%%

program:	stmt1
			|/*empty*/
			;

stmt1:		stmt1 stmt
            |stmt
			;

stmt:		expr ';'
			|ifstmt
			|whilestmt
			|forstmt
			|returnstmt
			|BREAK ';'
			|CONTINUE ';'
			|block
			|funcdef
			|';'
			;

expr:		 assignexpr 
			|expr '+' expr 
			|expr '-' expr 
			|expr '*' expr 
			|expr '/' expr 
			|expr '%' expr 
			|expr '>' expr 
			|expr '<' expr 
			|expr GREATEREQUAL expr 
			|expr LESSEQUAL expr 
			|expr EQUAL expr 
			|expr NOTEQUAL expr 
			|expr AND expr 
			|expr OR expr 
			|term 
			;



term: 		'('expr ')' 
			| '-' expr %prec UMINUS
			| NOT expr
			|PLUSPLUS lvalue
			|lvalue PLUSPLUS
			|MINUSMINUS lvalue
			|lvalue MINUSMINUS
			|primary
			;

assignexpr:	lvalue '=' expr ; 

primary:	lvalue 
			|call
			|objectdef
			|'(' funcdef ')'
			|const
			;

lvalue: 	ID
			|LOCAL ID
			|SCOPEOP ID
			|member
			;

member:		lvalue '.' ID
			|lvalue '[' expr ']'
			|call '.' ID
			call '[' expr ']'
			;

call: 		call '(' elist ')'
			|lvalue callsuffix
			|'(' funcdef ')' '(' elist ')'
			;

callsuffix:	normcall
			|methodcall
			;

normcall:   '(' elist ')';

methodcall:	DOUBLEDOT ID '(' elist ')' ;

elist:		/*empty*/
			|expr elist1
			;

elist1:		/*empty*/
			|','expr elist1
			;

objectdef:	'[' elist ']'
			|'[' indexed ']'
			;


indexed:	indexedelem more;

more:           ',' indexedelem more
                 |/*empty*/
                  ; 
	

indexedelem:'{' expr ':' expr '}' ;

block:		'{' stmt1'}'
             |'{''}'
			;	

funcdef:	FUNCTION ID '(' idlist ')' block 
			| FUNCTION '(' idlist ')' block 
			;

const:		NUMBER | STRING | NIL |TRUE|FALSE;

idlist:		/*empty*/
			|ID idlist1
			;

idlist1:	/*empty*/
			|',' ID idlist1
			;

ifstmt:		IF '(' expr ')' stmt ifstmt1;

ifstmt1:	/*empty*/
			|ELSE stmt
			;

whilestmt:	WHILE '(' expr ')' stmt ;

forstmt:	FOR '(' elist ';' expr ';' elist ')' stmt ;

returnstmt:	RETURN ';'
			|RETURN expr ';'
			;

