%{
	#include <stdlib.h>
	#include <stdio.h>
	int yyerror (char *yaccProvidedMessage);
	int yylex(void);

	extern int yylineno;
	extern char* yytext;
	extern FILE* yyin;

%}
%name parser_name

%start 	program
%token  ID BREAK CONTINUE AND OR NOT GREATER GREATEREQUAL LESS LESSEQUAL EQUAL NOTEQUAL UMINUS PLUSPLUS MINUSMINUS LOCAL SCOPEOP DOUPLEDOT FUNCTION NUMBER STRING NIL TRUE FALSE IF ELSE WHILE FOR RETURN

%left '(' ')' 
%left '[' ']'
%left '.' DOUPLEDOT
%right NOT PLUSPLUS MINUSMINUS UMINUS 
%left '*' '/' '%'
%left '+' '-'
%nonassoc GREATER GREATEREQUAL LESS LESSEQUAL
%nonassoc EQUAL NOTEQUAL
%left AND
%left OR
%right '='



%%

program:	stmt1
			;

stmt1:		/*empty*/
			|stmt stmt1
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

expr:		assignexpr
			|expr op expr
			|term
			;

op:   		'+'|'-'|'*'|'/'|'%'|'>'| GREATEREQUAL |'<'| LESSEQUAL | EQUAL | NOTEQUAL| AND|OR ;

term: 		'('expr ')'
			| UMINUS expr
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

methodcall:	DOUPLEDOT ID '(' elist ')' ;

elist:		/*empty*/
			|expr elist1
			;

elist1:		/*empty*/
			|','expr elist1
			;

objectdef:	'[' 
			|objectdef1
			']'
			;

objectdef1:	/*empty*/
			|elist
			|indexed
			;

indexed:	/*empty*/
			|indexedelem indexed1
			;

indexed1:	/*empty*/
			|',' indexedelem indexed1
			;

indexedelem:'{' expr ':' expr '}' ;

block:		'{'
			|stmt1
			'}'
			;	

funcdef:	FUNCTION funcdef1 '(' idlist ')' block ;

funcdef1:	/*empty*/
			|ID
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

returnstmt:	RETURN returnstmt1;

returnstmt1:/*empty*/
			|expr
			;

