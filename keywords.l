%{
	
#include <stdio.h>
#include "scanner.h"

#define YY_DECL int alpha_yylext(void* yyval);
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


ID				[a-zA-Z][a-zA-Z0-9_]*
Whitespace 		[ \t\n]
%%

if				{
					
				}
else 			{
					
				}
while			{
					
				}
for				{
					
				}
function		{
					
				}
return			{
					
				}
break			{
					
				}
continue		{
					
				}
and				{
					
				}
not				{
					
				}
or				{
					
				}
local			{
					
				}
true			{
					
				}
false			{
					
				}
nil				{
					
				}
{ID}			{
					
				}
				
"="				{
					
				}				
"+"				{
					
				}				
"-"				{
					
				}
"*"				{
					
				}
"/"				{
					
				}
"%"				{
					
				}
"=="			{
					
				}
"!="			{
					
				}
"++"			{	
					
				}
"--"			{
					
				}
">"				{
					
				}
"<"				{
					
				}
">="			{
					
				}
"<="			{
					
				}


{Whitespace}	;
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

.								
%%

int yywrap(){
	return 1;
}
