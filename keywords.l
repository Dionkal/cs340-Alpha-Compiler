%{
	
#include <stdio.h>
#include "scanner.h"

%}

%option yylineno
<<<<<<< HEAD
=======
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

>>>>>>> Ioanna

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


<<<<<<< HEAD
{Whitespace}	;
=======
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

>>>>>>> Ioanna

.				printf("Invalid character\n");				
%%

int yywrap(){
	return 1;
}
