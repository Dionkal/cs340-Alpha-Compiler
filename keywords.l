%{
	
#include <stdio.h>
#include <string.h>
#include <iostream.h>
#include "scanner.h"
using namespace std;

#define YY_DECL int alpha_yylext(void* yyval);

typedef struct alpha_token_t alpha_token_t;

alpha_token_t* List = NULL;	

int node_count = 0;
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
comment2		(\/\*)+(\*\/)+ /*not sure about this yet, that propably is not needed here*/


ID				[a-zA-Z][a-zA-Z0-9_]*
Whitespace 		[ \t\n]

%%

if				{
					addToken(yytext, yyleng, "KEYWORD IF"); 
				}
else 			{
					addToken(yytext, keyword, ELSE); 
          			fprintf(stderr,"Keyword value: %s\n", yytext);
				}
while			{
					addToken(yytext, keyword, WHILE); 
          			fprintf(stderr,"Keyword value: %s\n", yytext);
				}
for				{
					addToken(yytext, keyword, FOR); 
          			fprintf(stderr,"Keyword value: %s\n", yytext);
				}
function		{
					addToken(yytext, keyword, FUNCTION); 
          			fprintf(stderr,"Keyword value: %s\n", yytext);
				}
return			{
					addToken(yytext, keyword, RETURN); 
          			fprintf(stderr,"Keyword value: %s\n", yytext);
				}
break			{
					addToken(yytext, keyword, BREAK); 
          			fprintf(stderr,"Keyword value: %s\n", yytext);
				}
continue		{
					addToken(yytext, keyword, CONTINUE); 
          			fprintf(stderr,"Keyword value: %s\n", yytext);
				}
and				{
					addToken(yytext, keyword, AND); 
          			fprintf(stderr,"Keyword value: %s\n", yytext); 
				}
not				{
					addToken(yytext, keyword, NOT); 
          			fprintf(stderr,"Keyword value: %s\n", yytext);
				}
or				{
					addToken(yytext, keyword, OR); 
          			fprintf(stderr,"Keyword value: %s\n", yytext);
				}
local			{
					addToken(yytext, keyword, LOCAL); 
          			fprintf(stderr,"Keyword value: %s\n", yytext); 
				}
true			{
					addToken(yytext, keyword, TRUE); 
          			fprintf(stderr,"Keyword value: %s\n", yytext);
				}
false			{
					addToken(yytext, keyword, FALSE); 
          			fprintf(stderr,"Keyword value: %s\n", yytext); 
				}
nil				{
					addToken(yytext, keyword, FALSE); 
          			fprintf(stderr,"Keyword value: %s\n", yytext); 
				}
{ID}			{
					
				}
				
"="				{
					addToken(yytext, operators, ASSIGNMENT); 
          			fprintf(stderr,"Operator value: %s\n", yytext);
				}				
"+"				{
					addToken(yytext, operators, ASSIGNMENT); 
          			fprintf(stderr,"Operator value: %s\n", yytext);
				}				
"-"				{
					addToken(yytext, operators, ASSIGNMENT); 
          			fprintf(stderr,"Operator value: %s\n", yytext);
				}
"*"				{
					addToken(yytext, operators, ASSIGNMENT); 
          			fprintf(stderr,"Operator value: %s\n", yytext);
				}
"/"				{
					addToken(yytext, operators, ASSIGNMENT); 
          			fprintf(stderr,"Operator value: %s\n", yytext);
				}
"%"				{
					addToken(yytext, operators, ASSIGNMENT); 
          			fprintf(stderr,"Operator value: %s\n", yytext);
				}
"=="			{
					addToken(yytext, operators, ASSIGNMENT); 
          			fprintf(stderr,"Operator value: %s\n", yytext);
				}
"!="			{
					addToken(yytext, operators, ASSIGNMENT); 
          			fprintf(stderr,"Operator value: %s\n", yytext);
				}
"++"			{	
					addToken(yytext, operators, ASSIGNMENT); 
          			fprintf(stderr,"Operator value: %s\n", yytext);
				}
"--"			{
					addToken(yytext, operators, ASSIGNMENT); 
          			fprintf(stderr,"Operator value: %s\n", yytext);
				}
">"				{
					addToken(yytext, operators, ASSIGNMENT); 
          			fprintf(stderr,"Operator value: %s\n", yytext);
				}
"<"				{
					addToken(yytext, operators, ASSIGNMENT); 
          			fprintf(stderr,"Operator value: %s\n", yytext);
				}
">="			{
					addToken(yytext, operators, ASSIGNMENT); 
          			fprintf(stderr,"Operator value: %s\n", yytext);
				}
"<="			{
					addToken(yytext, operators, ASSIGNMENT); 
          			fprintf(stderr,"Operator value: %s\n", yytext);
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

{string}		{
					/*code for handing strings*/
					int c;
					while( (c==input()) != '\0'){

						/* '\t' and '\n' are thought to be part of the string, they have no special meaning inside the string*/
						if (c=='\'){
							if( ((c==input())=='t') || ((c==input()) == 'n') ){/*paizei na prepei na ginei se 2 vimata, k prepei na perasei ap compilation gt exo sinatiktika lathi nomizo*/
								unput(c);/*pleonasmos isos*/
							}
						}
						if(c==' '){
							unput(c);/*idia logiki me pano*/
						}
					}
					printf("String Error: string must end with '\0'\n");
				}

{comment1}		{}

"/*"			{	/*dont know if it works, needs testing*/
	
					/*code for comments of embedded style*/
					int c;
					while( (c= input()) != EOF){/*paizei na prepei na ginei se 2 vimata*/

						if(c=='*'){
							if( (c==input()) != '/'){/*paizei na prepei na ginei se 2 vimata*/
								break;
							}else{
								unput(c);
							}
						}
						unput(c);
					}
					printf("Comment Error: comments must end with '*/'\n");
				}

.				printf("Invalid character\n");		
				
%%
int addToken(char* value, int value_lenght, char* type){
	alpha_token_t* node = malloc (sizeof(alpha_token_t));
	
	node.token_no = ++node_count;
	node.line_no = yylineno;
	/*TODO add type */
	/*TODO add value*/
}



int yywrap(){
	return 1;
}

