%{
#include "scanner.h"
 
using namespace std; 
#define YY_DECL int alpha_yylext(void* yyval); 
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
					 addToken("KEYWORD IF",string(yytext),yylineno); 
					return 1;
				}
else			{ 
					addToken("KEYWORD ELSE",string(yytext),yylineno);
					return 2;
				}
while			{ 
					// yylval = addToken(tokenUnion,string(yytext),yylineno);
				}
for				{           			 
					//yylval = addToken(tokenUnion,string(yytext),yylineno);
				}
function		{
					//yylval = addToken(tokenUnion,string(yytext),yylineno);
				}
return			{
					//yylval = addToken(tokenUnion,string(yytext),yylineno);
				}
break			{  
					//yylval = addToken(tokenUnion,string(yytext),yylineno);
				}
continue		{ 
 					//yylval = addToken(tokenUnion,string(yytext),yylineno);
				}
and				{ 
					//yylval = addToken(tokenUnion,string(yytext),yylineno); 
				}
not				{  
					// yylval = addToken(tokenUnion,string(yytext),yylineno);
				}
or				{ 
					// yylval = addToken(tokenUnion,string(yytext),yylineno);
				}
local			{ 
          			// yylval = addToken(tokenUnion,string(yytext),yylineno); 
				}
true			{ 
          			// yylval = addToken(tokenUnion,string(yytext),yylineno);
				}
false			{ 
          			// yylval = addToken(tokenUnion,string(yytext),yylineno); 
				}
nil				{ 
          			// yylval = addToken(tokenUnion,string(yytext),yylineno); 
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

.			printf("Invalid character\n");		
				
%%
//Global token vector
vector  <alpha_token_t> vctr;
//Global token number
int token_number = 0;

//yyFlexLexer temp;

/*const char* KeywordToString(keyword_enum k)
{
    switch (k)
    {
		case IF:		return "KEYWORD IF";
		case ELSE:		return "KEYWORD ELSE";
        case WHILE:		return "KEYWORD WHILE";
		case FOR:		return "KEYWORD FOR";
		case FUNCTION:	return "KEYWORD FUNCTION";
		case RETURN:	return "KEYWORD RETURN";
		case BREAK:		return "KEYWORD BREAK";
		case CONTINUE:	return "KEYWORD CONTINUE";
		case AND:		return "KEYWORD AND";
		case NOT:		return "KEYWORD NOT";
		case OR:		return "KEYWORD OR";
		case LOCAL:		return "KEYWORD LOCAL";
		case TRUE:   	return "KEYWORD TRUE";
		case FALSE:		return "KEYWORD FALSE";
        case NIL:   	return "KEYWORD NIL";
    }
	return "Error in KeywordToString";
}*/


/*const char* OperatorToString(operators_enum o)
{
    switch (o)
    {
		case ASSIGNMENT:	return "OPERATOR ASSIGNMENT";
		case PLUS:			return "OPERATOR PLUS";
        case MINUS:			return "OPERATOR MINUS";
		case PRODUCT:		return "OPERATOR PRODUCT";
		case DIVIDE:		return "OPERATOR DIVIDE";
		case PERCENT:		return "OPERATOR PERCENT";
		case EQUALS:		return "OPERATOR EQUALS";
		case NOT_OP:		return "OPERATOR NOT";
		case D_PLUS:		return "OPERATOR D_PLUS";
		case D_MINUS:		return "OPERATOR D_MINUS";
		case GREATER:		return "OPERATOR GREATER";
		case LESS:			return "OPERATOR LESS";
		case G_EQUAL:   	return "OPERATOR G_EQUAL";
		case L_EQUAL:		return "OPERATOR L_EQUAL";
        
    }
	return "Error in OperatorToString";
}*/

void* addToken(string token_t, string value, int line){
	alpha_token_t token_struct;
	
	token_number++;

	token_struct.number_of_token = token_number; 		//save token number
	token_struct.line_number = line;	  				//save line number
	token_struct.str_type = token_t;					//save union of token type
	token_struct.token_value = value;					//save value of token as string

	//add token struct to global vector 
	vctr.push_back(token_struct);

	return &token_struct;  
}


int main (){
	alpha_token_t token;
	// cout <<"test";
	// while(alpha_yylex( &token)){
	// 	//print token info 
	// 	cout << token.number_of_token <<": #" << token.line_number <<"\t\""<<token.token_value <<"\"\t";

	// }

  	return 0;
}