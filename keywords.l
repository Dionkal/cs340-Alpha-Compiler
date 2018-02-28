%{
	
#include "scanner.h"
using namespace std;
	
%}

%option yylineno
%option noyywrap


/*Punctuation*/
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
comment1	\/{2}.*

ID				[a-zA-Z][a-zA-Z0-9_]*
Whitespace 		[ \t\n]

%%

if				{
					addToken(string("KEYWORD IF"),string(yytext),yylineno); 
				}
else 			{ 
					 
					addToken(string("KEYWORD ELSE"),string(yytext),yylineno);
				}
while			{ 
					 
					addToken(string("KEYWORD WHILE"),string(yytext),yylineno);
				}
for				{ 
          			
					 
					addToken(string("KEYWORD FOR"),string(yytext),yylineno);
				}
function		{ 
          			
					 
					addToken(string("KEYWORD FUNCTION"),string(yytext),yylineno);
				}
return			{ 
          			
					 
					addToken(string("KEYWORD RETURN"),string(yytext),yylineno);
				}
break			{ 
          			
					 
					addToken(string("KEYWORD BREAK"),string(yytext),yylineno);
				}
continue		{ 
          			
					 
					addToken(string("KEYWORD CONTINUE"),string(yytext),yylineno);
				}
and				{ 
          			
					 
					addToken(string("KEYWORD AND"),string(yytext),yylineno); 
				}
not				{ 
          			
					 
					addToken(string("KEYWORD NOT"),string(yytext),yylineno);
				}
or				{ 
          			
					 
					addToken(string("KEYWORD OR"),string(yytext),yylineno);
				}
local			{ 
          			
					 
					addToken(string("KEYWORD LOCAL"),string(yytext),yylineno); 
				}
true			{ 
          			
					 
					addToken(string("KEYWORD TRUE"),string(yytext),yylineno);
				}
false			{ 
          			
					 
					addToken(string("KEYWORD FALSE"),string(yytext),yylineno); 
				}
nil				{ 
          			
					 
					addToken(string("KEYWORD NIL"),string(yytext),yylineno); 
				}
{ID}			{
					addToken(string("IDENTIFIER"),string(yytext),yylineno);
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

void addToken(string token_t, string value, int line){
	alpha_token_t token_struct;
	
	token_number++;

	token_struct.number_of_token = token_number; 		//save token number
	token_struct.line_number = line;	  				//save line number
	token_struct.str_type = token_t;					//save  token type as string
	token_struct.token_value = value;					//save value of token as string

	//add token struct to global vector 
	vctr_ptr->push_back(token_struct); 
}

int alpha_yylex(void* yylval){
	vctr_ptr = (vector <alpha_token_t>*) yylval;
	cout <<"TEST" <<endl;
	return  temp.yylex();
}


int main (){
	vector <alpha_token_t> token_vector;
	alpha_yylex( &token_vector);

	for(alpha_token_t token :token_vector){
		//print token info 
		cout << token.number_of_token <<": #" << token.line_number <<"\t\""<<token.token_value <<"\"\t" << token.str_type <<endl;
	}

  	return 0;
}