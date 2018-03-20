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

{integer} {return INTEGER;}
{id} 	{return ID;}

[ \t]+ {}

. {fprintf(stderr,"Cannot match character %s with any rules with any rule\n", yytext);}

