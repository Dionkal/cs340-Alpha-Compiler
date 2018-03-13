%{
#include <stdio.h>
int yyerror (char *yaccProvidedMessage);
int yylex(void)

extern int yylineno;
extern char* yytext;
extern FILE* yyin;
%}

%start 			program

%token 			ID INTEGER

%right			'='
%left			','
%left			'+' '-'
%left			'*' '/'
%nonassoc		UNIMUS
%left 			'(' ')'

%%

program:		assignments expressions
				| /*empty*/
				;
expression:		INTEGER
				| ID
				| expression '+' expression
				| expression '-' expression
				| expression '*' expression
				| expression '/' expression
				| '(' expression ')'
				| '-' expression %prec UNIMUS
				;
expr:			expression '\n'

expressions:	expressions expr
				| exper
				;
assignment:		ID '=' expression '\n'

assignments:	assignments	assignment
				| /*empty*/
				;

%%

int yyerror (char* yaccProvidedMessage){
	fprintf(stderr,"%s: at line %d,before token: %s\n",yaccPrividedMessage,yylineno,yytext);
	fprintf(stderr, "INPUT NOT VALID\n");
}