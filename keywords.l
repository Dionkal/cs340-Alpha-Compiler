%{
	
#include <stdio.h>
#include "scanner.h"

%}

%option yylineno

ID				[a-zA-Z][a-zA-Z0-9_]*
Whitespace 		[ \t\n]
%%
"if"			{
					return IF;
				}
"else" 			{
					return ELSE;
				}
"while"			{
					return WHILE;
				}
"for"			{
					return FOR;
				}
"function"		{
					return FUNCTION;
				}
"return"		{
					return RETURN;
				}
"break"			{
					return BREAK;
				}
"continue"		{
					return CONTINUE;
				}
"and"			{
					return AND;
				}
"not"			{
					return NOT;
				}
"or"			{
					return OR;
				}
"local"			{
					return LOCAL;
				}
"true"			{
					return TRUE;
				}
"false"			{
					return FALSE;
				}
"nil"			{
					return NIL;
				}
{ID}			{
					return IDENTIFIER;
				}
				
"="				{
					return ASSIGNMENT;
				}				
"+"				{
					return PLUS;
				}				
"-"				{
					return MINUS;
				}
"*"				{
					return PRODUCT;
				}
"/"				{
					return DIVIDE;
				}
"%"				{
					return PERCENT;
				}
"=="			{
					return EQUALS;
				}
"!="			{
					return NOT_OP;
				}
"++"			{	
					return D_PLUS;
				}
"--"			{
					return D_MINUS;
				}
">"				{
					return GREATER;
				}
"<"				{
					return LESS;
				}
">="			{
					return G_EQUAL;
				}
"<="			{
					return L_EQUAL;
				}


{Whitespace}	;

.				printf("Invalid character\n");				
%%

int yywrap(){
	return 1;
}
