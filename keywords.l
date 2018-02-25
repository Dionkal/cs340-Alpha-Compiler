%{
	
#include <stdio.h>
#include "scanner.h"

#define YY_DECL int alpha_yylext(void* yyval);
%}

%option yylineno

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

.								
%%

int yywrap(){
	return 1;
}
