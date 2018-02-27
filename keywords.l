%{
	
#include "scanner.h"
using namespace st;
	

#define YY_DECL int alpha_yylext(void* yyval);
alpha_token_t* List = NULL;	

int node_count = 0;

enum keyword {IF, ELSE, WHILE, FOR, FUNCTION, RETURN, BREAK, CONTINUE, AND, NOT, OR, LOCAL, TRUE, FALSE, NIL}; 
 
enum operators {ASSIGNMENT, PLUS, MINUS, PRODUCT, DIVIDE, PERCENT, EQUALS, NOT, D_PLUS, D_MINUS, GREATER, LESS, G_EQUAL, L_EQUAL} 

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

const char* KeywordToString(keyword k)
{
    switch (k)
    {
		case IF:		return "IF";
		case ELSE:		return "ELSE";
        case WHILE:		return "WHILE";
		case FOR:		return "FOR";
		case FUNCTION:	return "FUNCTION";
		case RETURN:	return "RETURN";
		case BREAK:		return "BREAK";
		case CONTINUE:	return "CONTINUE";
		case AND:		return "AND";
		case NOT:		return "NOT";
		case OR:		return "OR";
		case LOCAL:		return "LOCAL";
		case TRUE:   	return "TRUE";
		case FALSE:		return "FALSE";
        case NIL:   	return "NIL";
    }
	return "Error in KeywordToString";
}


const char* OperatorToString(operators o)
{
    switch (o)
    {
		case ASSIGNMENT:	return "ASSIGNMENT";
		case PLUS:			return "PLUS";
        case MINUS:			return "MINUS";
		case PRODUCT:		return "PRODUCT";
		case DIVIDE:		return "DIVIDE";
		case PERCENT:		return "PERCENT";
		case EQUALS:		return "EQUALS";
		case NOT:			return "NOT";
		case D_PLUS:		return "D_PLUS";
		case D_MINUS:		return "D_MINUS";
		case GREATER:		return "GREATER";
		case LESS:			return "LESS";
		case G_EQUAL:   	return "G_EQUAL";
		case L_EQUAL:		return "L_EQUAL";
        
    }
	return "Error in OperatorToString";
}


int addToken(char* value, int value_lenght, char* type){
	alpha_token_t* node = malloc (sizeof(alpha_token_t));
	
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