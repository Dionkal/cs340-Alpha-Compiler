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
					token_type_union tokenUnion;

					tokenUnion.enumerator_t = IF; 
					addToken(tokenUnion,string(yytext)); 
					printf("IF token\nLine:%d",yylineno);
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
          			fprintf(stderr,"Keyword value: %s\n", yytext);
				}
break			{ 
          			fprintf(stderr,"Keyword value: %s\n", yytext);
				}
continue		{ 
          			fprintf(stderr,"Keyword value: %s\n", yytext);
				}
and				{ 
          			fprintf(stderr,"Keyword value: %s\n", yytext); 
				}
not				{ 
          			fprintf(stderr,"Keyword value: %s\n", yytext);
				}
or				{ 
          			fprintf(stderr,"Keyword value: %s\n", yytext);
				}
local			{ 
          			fprintf(stderr,"Keyword value: %s\n", yytext); 
				}
true			{ 
          			fprintf(stderr,"Keyword value: %s\n", yytext);
				}
false			{ 
          			fprintf(stderr,"Keyword value: %s\n", yytext); 
				}
nil				{ 
          			fprintf(stderr,"Keyword value: %s\n", string(yytext)); 
				}
{ID}			{
					
				}
				
"="				{ 
          			fprintf(stderr,"Operator value: %s\n", yytext);
				}				
"+"				{ 
          			fprintf(stderr,"Operator value: %s\n", yytext);
				}				
"-"				{ 
          			fprintf(stderr,"Operator value: %s\n", yytext);
				}
"*"				{ 
          			fprintf(stderr,"Operator value: %s\n", yytext);
				}
"/"				{ 
          			fprintf(stderr,"Operator value: %s\n", yytext);
				}
"%"				{ 
          			fprintf(stderr,"Operator value: %s\n", yytext);
				}
"=="			{ 
          			fprintf(stderr,"Operator value: %s\n", yytext);
				}
"!="			{ 
          			fprintf(stderr,"Operator value: %s\n", yytext);
				}
"++"			{	 
          			fprintf(stderr,"Operator value: %s\n", yytext);
				}
"--"			{ 
          			fprintf(stderr,"Operator value: %s\n", yytext);
				}
">"				{ 
          			fprintf(stderr,"Operator value: %s\n", yytext);
				}
"<"				{ 
          			fprintf(stderr,"Operator value: %s\n", yytext);
				}
">="			{ 
          			fprintf(stderr,"Operator value: %s\n", yytext);
				}
"<="			{ 
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
						// unput(c);
					}*/
					printf("Comment Error: comments must end with '*/'\n");
				}

.				printf("Invalid character\n");		
				
%%
//Global token vector
vector  <alpha_token_t>* vctr_ptr;
//Global token number
int token_number = 0;

yyFlexLexer temp;

void addToken(token_type_union token_t, string value){
	alpha_token_t token_struct;
	
	token_number++;

	token_struct.number_of_token = token_number; 	//save token number
	//token_struct.line_number = yyFlexLexer::yylineno;	  		//save line number
	token_struct.token_type = token_t;				//save union of token type
	token_struct.token_value = value;				//save value of token as string

	//add token struct to global vector 
	vctr_ptr->push_back(token_struct); 
}

int alpha_yylex(void* yylval){
	vctr_ptr = (vector <alpha_token_t>*) yylval;
	return  temp.yylex();
}


int main (){
	vector <alpha_token_t> token_vector;
	alpha_yylex( &token_vector);

	for(alpha_token_t token :token_vector){
		//print token info 
		printf("%d: ",token.number_of_token);
		printf("#%d\t", token.line_number);
		printf("\"%s\"\t", token.token_value);
		printf(" placeholder token type\n");

	}

  	return 0;
}