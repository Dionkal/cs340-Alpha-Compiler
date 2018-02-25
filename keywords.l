%{
	
#include <stdio.h>

enum keyword {IF, ELSE, WHILE, FOR, FUNCTION, RETURN, BREAK, CONTINUE, AND, NOT, OR, LOCAL, TRUE, FALSE, NIL};
enum operators {ASSIGNMENT, PLUS, MINUS, PRODUCT, DIVIDE, PERCENT, EQUALS, NOT, D_PLUS, D_MINUS, GREATER, LESS, G_EQUAL, L_EQUAL}
%}

%option yylineno
%option noyywrap

ID				[a-zA-Z][a-zA-Z0-9_]*

%%
"if"			{
					addToken(yytext, keyword, ELSE);
				}
"else" 			{
					addToken(yytext, keyword, ELSE);
					fprintf(stderr,"Keyword value: %s\n", yytext);
				}
"while"			{
					addToken(yytext, keyword, WHILE);
					fprintf(stderr,"Keyword value: %s\n", yytext);
				}
"for"			{
					addToken(yytext, keyword, FOR);
					fprintf(stderr,"Keyword value: %s\n", yytext);
				}
"function"		{
					addToken(yytext, keyword, FUNCTION);
					fprintf(stderr,"Keyword value: %s\n", yytext);
				}
"return"		{
					addToken(yytext, keyword, RETURN);
					fprintf(stderr,"Keyword value: %s\n", yytext);
				}
"break"			{
					addToken(yytext, keyword, BREAK);
					fprintf(stderr,"Keyword value: %s\n", yytext);
				}
"continue"		{
					addToken(yytext, keyword, CONTINUE);
					fprintf(stderr,"Keyword value: %s\n", yytext);
				}
"and"			{
					addToken(yytext, keyword, AND);
					fprintf(stderr,"Keyword value: %s\n", yytext);
				}
"not"			{
					addToken(yytext, keyword, NOT);
					fprintf(stderr,"Keyword value: %s\n", yytext);
				}
"or"			{
					addToken(yytext, keyword, OR);
					fprintf(stderr,"Keyword value: %s\n", yytext);
				}
"local"			{
					addToken(yytext, keyword, LOCAL);
					fprintf(stderr,"Keyword value: %s\n", yytext);
				}
"true"			{
					addToken(yytext, keyword, TRUE);
					fprintf(stderr,"Keyword value: %s\n", yytext);
				}
"false"			{
					addToken(yytext, keyword, FALSE);
					fprintf(stderr,"Keyword value: %s\n", yytext);
				}
"nil"			{
					addToken(yytext, keyword, NIL);
					fprintf(stderr,"Keyword value: %s\n", yytext);
				}
{ID}			{
					fprintf(stderr,"Identifier value: %s\n", yytext);
				}
				
"="				{
					addToken(yytext, operators, ASSIGNMENT);
					fprintf(stderr,"Operator value: %s\n", yytext);
				}				
"+"				{
					addToken(yytext, operators, PLUS);
					fprintf(stderr,"Operator value: %s\n", yytext);
				}				
"-"				{
					addToken(yytext, operators, MINUS);
					fprintf(stderr,"Operator value: %s\n", yytext);
				}
"*"				{
					addToken(yytext, operators, PRODUCT);
					fprintf(stderr,"Operator value: %s\n", yytext);
				}
"/"				{
					addToken(yytext, operators, DIVIDE);
					fprintf(stderr,"Operator value: %s\n", yytext);
				}
"%"				{
					addToken(yytext, operators, PERCENT);
					fprintf(stderr,"Operator value: %s\n", yytext);
				}
"=="			{
					addToken(yytext, operators, EQUALS);
					fprintf(stderr,"Operator value: %s\n", yytext);
				}
"!="			{
					addToken(yytext, operators, NOT);
					fprintf(stderr,"Operator value: %s\n", yytext);
				}
"++"			{
					addToken(yytext, operators, D_PLUS);
					fprintf(stderr,"Operator value: %s\n", yytext);
				}
"--"			{
					addToken(yytext, operators, D_MINUS);
					fprintf(stderr,"Operator value: %s\n", yytext);
				}
">"				{
					addToken(yytext, operators, GREATER);
					fprintf(stderr,"Operator value: %s\n", yytext);
				}
"<"				{
					addToken(yytext, operators, LESS);
					fprintf(stderr,"Operator value: %s\n", yytext);
				}
">="			{
					addToken(yytext, operators, G_EQUAL);
					fprintf(stderr,"Operator value: %s\n", yytext);
				}
"<="			{
					addToken(yytext, operators, L_EQUAL);
					fprintf(stderr,"Operator value: %s\n", yytext);
				}

%%

int main(void) {
	return yylex();
}
