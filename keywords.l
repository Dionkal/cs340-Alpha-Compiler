%{
	
#include <stdio.h>

enum keyword {IF, ELSE, WHILE, FOR, FUNCTION, RETURN, BREAK, CONTINUE, AND, NOT, OR, LOCAL, TRUE, FALSE, NIL};

%}

%option yylineno
%option noyywrap

/*Punctuation*/
leftBracket1	\{
rightBracket1	\}	
leftBracket2	\[
rightBracket2	\]
leftBracket3	\(
rightBracket3	\)
semicolon		\;
comma			\,
colon			\:
doubleColon		[:]{2}
period			\.
doublePeriod	[.]{2}

string			\"[^\n"]*\" 
comment1		\/{2}.*
comment2		(\/\*)+(\*\/)+ /*not sure about this yet*/


%%

{if} 			{
					addToken(yytext, keyword, IF);
					fprintf(stderr,"Keyword value: %s\n", yytext);
				}
{else} 			{
					addToken(yytext, keyword, ELSE);
					fprintf(stderr,"Keyword value: %s\n", yytext);
				}
{while}			{
					addToken(yytext, keyword, WHILE);
					fprintf(stderr,"Keyword value: %s\n", yytext);
				}
{for}			{
					addToken(yytext, keyword, FOR);
					fprintf(stderr,"Keyword value: %s\n", yytext);
				}
{function}		{
					addToken(yytext, keyword, FUNCTION);
					fprintf(stderr,"Keyword value: %s\n", yytext);
				}
{return}		{
					addToken(yytext, keyword, RETURN);
					fprintf(stderr,"Keyword value: %s\n", yytext);
				}
{break}			{
					addToken(yytext, keyword, BREAK);
					fprintf(stderr,"Keyword value: %s\n", yytext);
				}
{continue}		{
					addToken(yytext, keyword, CONTINUE);
					fprintf(stderr,"Keyword value: %s\n", yytext);
				}
{and}			{
					addToken(yytext, keyword, AND);
					fprintf(stderr,"Keyword value: %s\n", yytext);
				}
{not}			{
					addToken(yytext, keyword, NOT);
					fprintf(stderr,"Keyword value: %s\n", yytext);
				}
{or}			{
					addToken(yytext, keyword, OR);
					fprintf(stderr,"Keyword value: %s\n", yytext);
				}
{local}			{
					addToken(yytext, keyword, LOCAL);
					fprintf(stderr,"Keyword value: %s\n", yytext);
				}
{true}			{
					addToken(yytext, keyword, TRUE);
					fprintf(stderr,"Keyword value: %s\n", yytext);
				}
{false}			{
					addToken(yytext, keyword, FALSE);
					fprintf(stderr,"Keyword value: %s\n", yytext);
				}
{nil}			{
					addToken(yytext, keyword, NIL);
					fprintf(stderr,"Keyword value: %s\n", yytext);
				}				

{leftBracket1}	{printf("{");}
{rightBracket1}	{printf("}");}
{leftBracket2}	{printf("[");}
{rightBracket2}	{printf("]");}
{leftBracket3}	{printf("(");}
{rightBracket3}	{printf(")");}
{semicolon}		{printf(";");}
{comma}			{printf(",");}
{colon}			{printf(":");}
{doubleColon}	{printf("::");}
{period}		{printf(".");}
{doublePeriod}	{printf("..");}

{string}		{/*needs smthing*/}

{comment2}		{/*prepei n doulepso ta emfoleumena*/}


%%

int main(void) {
	return yylex();
}
