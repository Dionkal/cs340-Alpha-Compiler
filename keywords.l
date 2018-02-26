%{
	
#include "scanner.h"

using namespace std;
	
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
					addToken(,string(yytext)); 
				}
else 			{ 
          			fprintf(stderr,"Keyword value: %s\n", yytext);
				}
while			{ 
          			fprintf(stderr,"Keyword value: %s\n", yytext);
				}
for				{ 
          			fprintf(stderr,"Keyword value: %s\n", yytext);
				}
function		{ 
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
          			fprintf(stderr,"Keyword value: %s\n", string(yytext)); 
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
					yylval = addToken(yytext, operators, ASSIGNMENT); 
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
//Global token vector
vector  <alpha_token_t>* vctr_ptr;
//Global token number
int token_number = 0;

int alpha_yylex(void* yylval){
	vctr_ptr = (vector* <alpha_token_t>) yylval;
	return yylex();
}


void addToken(void* token_t, string value){
	alpha_token_t token_struct;
	
	token_number++;

	token_struct.number_of_token = token_no; 	//save token number
	token_struct.line_number = yylineno;	  	//save line number
	token_struct.token_type = token_t;			//save pointer to token type
	token_struct.token_value = value;			//save value of token as string

	//add token struct to global vector 
	vctr_ptr->push_back(token_struct); 
}


int main (){
	vector <alpha_token_t> token_vector;
	alpha_yylex((void *) (&token_vector));



  	return 0;
}