%{
	
#include "scanner.h"
#include <iomanip>
using namespace std;


	
%}
%option yylineno
%option noyywrap

integer [0-9]+
real	[0-9]+"."[0-9]+

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
doubleColon	[:]{2}
period			\.
doublePeriod[.]{2}

comment1		\/{2}.*

ID				[a-zA-Z][a-zA-Z0-9_]*
Whitespace 		[ \t\n]

%%

if				{
					addToken(KEYWORD,string("IF"),string(yytext),yylineno); 
				}
else 			{ 
					 
					addToken(KEYWORD,string("ELSE"),string(yytext),yylineno);
				}
while			{ 
					 
					addToken(KEYWORD,string("WHILE"),string(yytext),yylineno);
				}
for				{ 
          			
					 
					addToken(KEYWORD,string("FOR"),string(yytext),yylineno);
				}
function		{ 
          			
					 
					addToken(KEYWORD,string("FUNCTION"),string(yytext),yylineno);
				}
return			{ 
          			
					 
					addToken(KEYWORD,string("RETURN"),string(yytext),yylineno);
				}
break			{ 
          			
					 
					addToken(KEYWORD,string("BREAK"),string(yytext),yylineno);
				}
continue		{ 
          			
					 
					addToken(KEYWORD,string("CONTINUE"),string(yytext),yylineno);
				}
and				{ 
          			
					 
					addToken(KEYWORD,string("AND"),string(yytext),yylineno); 
				}
not				{ 
          			
					 
					addToken(KEYWORD,string("NOT"),string(yytext),yylineno);
				}
or				{ 
          			
					 
					addToken(KEYWORD,string("OR"),string(yytext),yylineno);
				}
local			{ 
          			
					 
					addToken(KEYWORD,string("LOCAL"),string(yytext),yylineno); 
				}
true			{ 
          			
					 
					addToken(KEYWORD,string("TRUE"),string(yytext),yylineno);
				}
false			{ 
          			
					 
					addToken(KEYWORD,string("FALSE"),string(yytext),yylineno); 
				}
nil				{ 
          			
					 
					addToken(KEYWORD,string("NIL"),string(yytext),yylineno); 
				}
{ID}			{
					addToken(IDENTIFIER,string(yytext),string(yytext),yylineno);
				}
				
"="				{ 
          			addToken(OPERATOR,string("ASSIGNMENT"),string(yytext),yylineno);
				}				
"+"				{ 
          			addToken(OPERATOR,string("PLUS"),string(yytext),yylineno);
				}				
"-"				{ 
          			addToken(OPERATOR,string("MINUS"),string(yytext),yylineno);
				}
"*"				{ 
          			addToken(OPERATOR,string("MULTIPLICATION"),string(yytext),yylineno);
				}
"/"				{ 
          			addToken(OPERATOR,string("DIVISION"),string(yytext),yylineno);
				}
"%"				{ 
          			addToken(OPERATOR,string("MODULO"),string(yytext),yylineno);
				}
"=="			{ 
          			addToken(OPERATOR,string("EQUALS"),string(yytext),yylineno);
				}
"!="			{ 
          			addToken(OPERATOR,string("NOT_EQUALS"),string(yytext),yylineno);
				}
"++"			{	 
          			addToken(OPERATOR,string("PLUS_PLUS"),string(yytext),yylineno);
				}
"--"			{ 
          			addToken(OPERATOR,string("MINUS_MINUS"),string(yytext),yylineno);
				}
">"				{ 
          			addToken(OPERATOR,string("GREATER"),string(yytext),yylineno);
				}
"<"				{ 
          			addToken(OPERATOR,string("LESS"),string(yytext),yylineno);
				}
">="			{ 
          			addToken(OPERATOR,string("G_EQUAL"),string(yytext),yylineno);
				}
"<="			{ 
          			addToken(OPERATOR,string("L_EQUAL"),string(yytext),yylineno);
				}
{integer}		{
					addToken(INT_CONST,string(yytext),string(yytext),yylineno); 	
				}

{real}			{
					addToken(REAL_CONST,string(yytext),string(yytext),yylineno); 
				}

{Whitespace}	;

{leftBracket1}  { 
          	addToken(PUNCTUATION,string("LEFT_BRACKET"),string(yytext),yylineno); 
        } 
{rightBracket1}  { 
          	addToken(PUNCTUATION,string("RIGHT_BRACKET"),string(yytext),yylineno); 
        } 
{leftBracket2}  { 
          	addToken(PUNCTUATION,string("LEFT_SQR_BRACKET"),string(yytext),yylineno);
        } 
{rightBracket2}  { 
          	addToken(PUNCTUATION,string("RIGHT_SQR_BRACKET"),string(yytext),yylineno); 
        } 
{leftBracket3}  { 
          	addToken(PUNCTUATION,string("LEFT_PARENTHESIS"),string(yytext),yylineno);
        } 
{rightBracket3}  { 
          	addToken(PUNCTUATION,string("RIGHT_PARENTHESIS"),string(yytext),yylineno); 
        } 
{semicolon}    { 
          	addToken(PUNCTUATION,string("SEMICOLON"),string(yytext),yylineno);
        } 
{comma}      { 
          	addToken(PUNCTUATION,string("COMMA"),string(yytext),yylineno);
        } 
{colon}      { 
          	addToken(PUNCTUATION,string("COLON"),string(yytext),yylineno);
        } 
{doubleColon}  { 
        	addToken(PUNCTUATION,string("DOUBLE_COLON"),string(yytext),yylineno);
        } 
{period}    { 
          	addToken(PUNCTUATION,string("PERIOD"),string(yytext),yylineno); 
        } 
{doublePeriod}  { 
        	addToken(PUNCTUATION,string("DOUBLE_PERIOD"),string(yytext),yylineno);
} 


"\""	{

				/*code for strings*/
				char input = *yytext;/*get input*/
				char next;
				int buf_size = 1;
				char * output=(char *)malloc(buf_size*sizeof(char));
				int cnt=0;
				output[cnt]=input;

				while( (input=yyinput()) != '\0' && input != 10){
					if(cnt >( buf_size/2)){
						//cout <<"Reallocating..buffsize is now: " << buf_size <<endl;
						buf_size = buf_size *2;
						output = (char*) realloc((void*)output, buf_size);
						//hope it works...pls <3
					}
					/*Check cases which start with '\'*/
					if(input == '\\'){
						next=yyinput();

						if(next=='n'){
							output[cnt]='\n';
							cnt++;
							continue;							
						}
						if(next=='t'){
							output[cnt]='\t';
							cnt++;
							input = next;
						}
						if(next=='v'){
							output[cnt]='\v';
							cnt++;
							input = next;
						}
						if(next=='\\'){
							output[cnt]='\\';
							cnt++;
							input = next;
						}
						if(next=='b'){
							output[cnt]='\b';
							cnt++;
							input = next;
						}
						if(next=='\"'){
							output[cnt]='\"';
							cnt++;
							input = next;
						}
					}

					/*other cases*/
					if(input=='\n'){
						// output[cnt]='\n';
						break;//not sure
					}
					if(input =='\"'){
						break;//not sure	
					}

					output[cnt]=input;
					cnt++;

				}
				if(input==EOF || input== 10){
						addToken(STRING,string(""),"Error: End-of-file reached while in string\n",yylineno);							
				}else{
					output[cnt] = '\0';
					addToken(STRING,string("STRING"),string(output),yylineno); 
				}	
				free(output);

			}
{comment1}		addToken(COMMENT,string("LINE COMMENT"),"",yylineno);;

"/*"			{	
					int c,lineBegin,lineEnd,nested=0; /*lineBegin and lineEnd for printing where the comment is,and nested checks if the comment is nested*/
					string lines;/*for output*/
					stringstream ss;
					lineBegin=yylineno;					
					ss<<lineBegin;
					lines=ss.str();

					while(1){
						while( (c=yyinput()) != '*' && c!=EOF){

							while( (c=yyinput())=='/'){

								if((c=yyinput())=='*'){//possible nested
											
									//idios kodikas		
									nested++;			
								}	
							}

							while(c == '\\' && (c=yyinput())=='n'){//edo tora thelei den thelei input den ksero ego mperdeutei
								;
							}				

							lineEnd=yylineno;
							ss<<lineEnd;
							lines=lines + "-" + ss.str();
							addToken(COMMENT,string("MULTILINE COMMENT"),lines,yylineno); 
						}

						if(c=='*'){
							while( (c=yyinput())=='*'){//ta lookforward prepei na ta pao piso
								unput(c);/*put it back*/
							}

							if(c=='/')
								//ki an einai nested na to valo edo i guess
								break;/*here is the end of the commnent*/
						}

						if(c==EOF){
							printf("EOF found");
							break;
						}

					}
				}

.			printf("Invalid character\n");		
				
%%
//Global token vector
vector  <alpha_token_t>* vctr_ptr; 
//Global token number
int token_number = 0;
//Global lex object
yyFlexLexer temp;

int alpha_yylex(void* yylval){ 
  vctr_ptr = (vector <alpha_token_t>*) yylval;  
  return  temp.yylex(); 
} 

void addToken(type token_t,string token_sT, string value, int line){
	alpha_token_t token_struct;
	
	token_number++;

	token_struct.number_of_token = token_number; 		//save token number
	token_struct.line_number = line;	  				//save line number
	token_struct.token_type = token_t;					//save token type as string
	token_struct.str_subType = token_sT;				//save token subtype as string
	token_struct.token_value = value;					//save value of token as string

	switch(token_t){
		case KEYWORD: 		
		case OPERATOR: 		
		case PUNCTUATION: 	 
		case COMMENT: 
			token_struct.arrow_type = "<--enumerated";
			break;
		case IDENTIFIER: 	
		case STRING:
			token_struct.arrow_type = "<--char*";
			break;
		case INT_CONST: 	
			token_struct.arrow_type = "<--int";
			break;
		case REAL_CONST: 	
			token_struct.arrow_type ="<--floating point";
		 	break;
		default:	
			token_struct.arrow_type = "<--_UKNOWN_TYPE_";
	}
	//add token struct to global vector 
	vctr_ptr->push_back(token_struct);  
}


string typeToString(type t){
	switch(t){
		case KEYWORD: 		return "KEYWORD";
		case IDENTIFIER: 	return "IDENTIFIER";
		case INT_CONST: 	return "INT_CONST";
		case REAL_CONST: 	return "REAL_CONST";
		case STRING: 		return "STRING";
		case OPERATOR: 		return "OPERATOR";
		case PUNCTUATION: 	return "PUNCTUATION";
		case COMMENT: 		return "COMMENT";
		default:			return "_UKNOWN_TYPE_";
	}
}

int main (int argc, char *argv[]){
	vector <alpha_token_t> token_vector; 

	if (argc < 2 || argc > 3) {
		printf("Invalid parameter\nUsage: <program> <path to input file> <optional "
           "path to output file>\n");
		exit(1);
	}
	
	
	std::filebuf fb_in;
	std::filebuf fb_out;
	if (fb_in.open (argv[1],std::ios::in)){
		std::istream is(&fb_in);
	
	
		if (argc == 3) {
	
			fb_out.open (argv[2],std::ios::out);
			std::ostream os(&fb_out);
			temp.switch_streams(&is,&os);

			alpha_yylex( &token_vector);
  
  
			for (vector<alpha_token_t>::iterator token = token_vector.begin() ; token != token_vector.end(); ++token){
			//print token info 
				os  <<left  <<std::setw(5)<<token->number_of_token <<": #" << token->line_number <<" \"" <<std::setw(6)<<token->token_value <<"\"\t";
				os  <<left << typeToString(token->token_type) <<"\t" <<setw(8) <<token->str_subType  <<setw(18) <<token->arrow_type <<endl;
			}
		}else{
			std::ostream os(NULL);
			os.rdbuf(std::cout.rdbuf());
			temp.switch_streams(&is,&os);
			
			alpha_yylex( &token_vector);
  
  
			for (vector<alpha_token_t>::iterator token = token_vector.begin() ; token != token_vector.end(); ++token){
			//print token info 
				os  <<left  <<std::setw(5)<<token->number_of_token <<": #" << token->line_number <<" \"" <<std::setw(6)<<token->token_value <<"\"\t";
				os  <<left << typeToString(token->token_type) <<"\t" <<setw(8) <<token->str_subType  <<setw(18) <<token->arrow_type <<endl;
			}
		}
	

	}else{
		cout <<"Error opening file: " << string(argv[1]) <<endl;
		exit(-1);
	
	}

  	return 0;
}
