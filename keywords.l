%{
#include "keywords.h"

#define YY_DECL int alpha_yylext(void* smthing)  
%}
%option yylineno
%option noyywrap

leftBracket1	\{
rightBracet1	\}	
leftBracket2	\[
rightBracket2	\]
leftBracket3	\(
rightBracket3	\)
semicolon		\;
comma			\,
colon			\:
doubleColon	[:]{2}
period			\.
doublePeriod[.]{2}

string			\"[^\n"]*\" 
comment1		\/{2}.*

ID				[a-zA-Z][a-zA-Z0-9_]*
Whitespace 		[ \t\n]

%%

if				{
					// token_type_union tokenUnion;
					//tokenUnion.enumerator_t = IF; 
					addToken(IF,string(yytext),yylineno); 
				}
else 			{ 
					token_type_union tokenUnion;
					tokenUnion.enumerator_t = ELSE; 
					addToken(tokenUnion,string(yytext),yylineno);
				}
while			{ 
					// yylval = addToken(tokenUnion,string(yytext),yylineno);
					return 999;
				}
for				{           			 
					//yylval = addToken(tokenUnion,string(yytext),yylineno);
					return 999;
				}
function		{
					//yylval = addToken(tokenUnion,string(yytext),yylineno);
					return 999;
				}
return			{
					//yylval = addToken(tokenUnion,string(yytext),yylineno);
					return 999;
				}
break			{  
					//yylval = addToken(tokenUnion,string(yytext),yylineno);
					return 999;
				}
continue		{ 
 					//yylval = addToken(tokenUnion,string(yytext),yylineno);
					return 999;
				}
and				{ 
					//yylval = addToken(tokenUnion,string(yytext),yylineno); 
					return 999;
				}
not				{  
					// yylval = addToken(tokenUnion,string(yytext),yylineno);
					return 999;
				}
or				{ 
					// yylval = addToken(tokenUnion,string(yytext),yylineno);
					return 999;
				}
local			{ 
          			// yylval = addToken(tokenUnion,string(yytext),yylineno); 
					return 999;
				}
true			{ 
          			// yylval = addToken(tokenUnion,string(yytext),yylineno);
					return 999;
				}
false			{ 
          			// yylval = addToken(tokenUnion,string(yytext),yylineno); 
					return 999;
				}
nil				{ 
          			// yylval = addToken(tokenUnion,string(yytext),yylineno); 
					return 999;
				}
{ID}			{
				}
				
"="				{ 
          			fprintf(stderr,"Operator value: %s\n", yytext);
					return 999;
				}				
"+"				{ 
          			fprintf(stderr,"Operator value: %s\n", yytext);
					return 999;
				}				
"-"				{ 
          			fprintf(stderr,"Operator value: %s\n", yytext);
					return 999;
				}
"*"				{ 
          			fprintf(stderr,"Operator value: %s\n", yytext);
					return 999;
				}
"/"				{ 
          			fprintf(stderr,"Operator value: %s\n", yytext);
					return 999;
				}
"%"				{ 
          			fprintf(stderr,"Operator value: %s\n", yytext);
					return 999;
				}
"=="			{ 
          			fprintf(stderr,"Operator value: %s\n", yytext);
					return 999;
				}
"!="			{ 
          			fprintf(stderr,"Operator value: %s\n", yytext);
					return 999;
				}
"++"			{	 
          			fprintf(stderr,"Operator value: %s\n", yytext);
					return 999;
				}
"--"			{ 
          			fprintf(stderr,"Operator value: %s\n", yytext);
					return 999;
				}
">"				{ 
          			fprintf(stderr,"Operator value: %s\n", yytext);
					return 999;
				}
"<"				{ 
          			fprintf(stderr,"Operator value: %s\n", yytext);
					return 999;
				}
">="			{ 
          			fprintf(stderr,"Operator value: %s\n", yytext);
					return 999;
				}
"<="			{ 
          			fprintf(stderr,"Operator value: %s\n", yytext);
					return 999;
				}


{Whitespace}	;

{leftBracket1}	{printf("{");}
{rightBracket1}	{printf"}");}
{leftBracket2}	{printf("[");}
{rightBracket2}	{printf("]");}
{leftBracket3}	{printf("(");}
{rightBracket3}	{printf(")");}
{semicolon}		{printf(";");}
{comma}			{printf(",");}
{colon}			{printf(":");}
{doubleColon}	{printf(::");}
{period}		{printf(".");}
{doublePeriod}	{printf(..");}

{string}		{
				
				}

{comment1}		;

"/*"			{	/*dont know if it works, needs testing*/
	
					/*code for comments of embedded style*/
					int c;
					/*while( (c= input()) != EOF){

						if(c=='*'){
							if( (c==input()) != '/'){paizei na prepei na ginei se 2 vimata
								break;
							}else{
								// unput(c);
							}
						}
						// unput(c);					}*/
					printf("Comment Error: comments must end with '*/'\n");
				}

.				printf("Invalid character\n");		
				
%%
//Global token vector
vector  <alpha_token_t>* vctr_ptr;
//Global token number
int token_number = 0;

yyFlexLexer temp;

void addToken(token_type_union token_t, string value, int line){
	alpha_token_t token_struct;
	
	token_number++;

	token_struct.number_of_token = token_number; 		//save token number
	token_struct.line_number = line;	  				//save line number
	token_struct.token_type = token_t;					//save union of token type
	token_struct.token_value = value;					//save value of token as string

	//add token struct to global vector 
	vctr_ptr->push_back(token_struct); 
}

	return NULL;
	// return &token_struct;  
}


int main (){
	//alpha_token_t token;
	cout <<"test";
	// while(alpha_yylex( &token)){
	// 	//print token info 
	// 	cout << token.number_of_token <<": #" << token.line_number <<"\t\""<<token.token_value <<"\"\t";
	// }

  	return 0;
}