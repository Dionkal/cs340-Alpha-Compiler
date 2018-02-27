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
					addToken(tokenUnion,string(yytext),yylineno); 
					// printf("IF token\nLine:\n");
				}
else 			{ 
					token_type_union tokenUnion;
					tokenUnion.enumerator_t = ELSE; 
					addToken(tokenUnion,string(yytext),yylineno);
				}
while			{ 
					token_type_union tokenUnion;
					tokenUnion.enumerator_t = WHILE; 
					addToken(tokenUnion,string(yytext),yylineno);
				}
for				{ 
          			
					token_type_union tokenUnion;
					tokenUnion.enumerator_t = FOR; 
					addToken(tokenUnion,string(yytext),yylineno);
				}
function		{ 
          			
					token_type_union tokenUnion;
					tokenUnion.enumerator_t = FUNCTION; 
					addToken(tokenUnion,string(yytext),yylineno);
				}
return			{ 
          			
					token_type_union tokenUnion;
					tokenUnion.enumerator_t = RETURN; 
					addToken(tokenUnion,string(yytext),yylineno);
				}
break			{ 
          			
					token_type_union tokenUnion;
					tokenUnion.enumerator_t = BREAK; 
					addToken(tokenUnion,string(yytext),yylineno);
				}
continue		{ 
          			
					token_type_union tokenUnion;
					tokenUnion.enumerator_t = CONTINUE; 
					addToken(tokenUnion,string(yytext),yylineno);
				}
and				{ 
          			
					token_type_union tokenUnion;
					tokenUnion.enumerator_t = AND; 
					addToken(tokenUnion,string(yytext),yylineno); 
				}
not				{ 
          			
					token_type_union tokenUnion;
					tokenUnion.enumerator_t = NOT; 
					addToken(tokenUnion,string(yytext),yylineno);
				}
or				{ 
          			
					token_type_union tokenUnion;
					tokenUnion.enumerator_t = OR; 
					addToken(tokenUnion,string(yytext),yylineno);
				}
local			{ 
          			
					token_type_union tokenUnion;
					tokenUnion.enumerator_t = LOCAL; 
					addToken(tokenUnion,string(yytext),yylineno); 
				}
true			{ 
          			
					token_type_union tokenUnion;
					tokenUnion.enumerator_t = TRUE; 
					addToken(tokenUnion,string(yytext),yylineno);
				}
false			{ 
          			
					token_type_union tokenUnion;
					tokenUnion.enumerator_t = FALSE; 
					addToken(tokenUnion,string(yytext),yylineno); 
				}
nil				{ 
          			
					token_type_union tokenUnion;
					tokenUnion.enumerator_t = NIL; 
					addToken(tokenUnion,string(yytext),yylineno); 
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

int alpha_yylex(void* yylval){
	vctr_ptr = (vector <alpha_token_t>*) yylval;
	return  temp.yylex();
}


int main (){
	vector <alpha_token_t> token_vector;
	alpha_yylex( &token_vector);

	for(alpha_token_t token :token_vector){
		//print token info 
		cout << token.number_of_token <<": #" << token.line_number <<"\t\""<<token.token_value <<"\"\t  placeholder token type\n" <<endl;
	}

  	return 0;
}