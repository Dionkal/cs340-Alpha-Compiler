%{
	#include "parser.h"
%}

%option noyywrap
%option yylineno

id 		[a-zA-Z][a-zA-Z_0-9]*
integer	[0-9]+

%%

"+"	{return '+';}
"-"	{return '-';}
"*"	{return '*';}
"/"	{return '/';}
"("	{return '(';}
")"	{return ')';}
"="	{return '=';}
";"	{return ';';}

(integer) {yylval.intValue= atoi(yytext); return INTEGER;}
(id) 	{yylval.stringValue = strdup(yytext); return ID;}

[ \t\n]+ {}

. {fprintf(stderr,"Cannot match character %s with any rules with any rule\n", yytext);}
