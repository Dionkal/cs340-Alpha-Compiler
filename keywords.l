%{
#define YY_DECL int yylex(void)	
#include "scanner.h"
#include "parser.h"
#include "symtable.h"
#include <string.h>
#include <iomanip>
#include <stack>

using namespace std;
 extern std::stack<bool> scopeAccessStack;
	
%}
%option yylineno
%option noyywrap

integer [0-9]+
real	[0-9]+"."[0-9]+

/*Punctuation*/
leftBracket1	'\{'
rightBracket1	'\}'	
leftBracket2	'\['
rightBracket2	'\]'
leftBracket3	'\('
rightBracket3	'\)'
comma			'\,'
colon			'\:'
doubleColon	[:]{2}
period			'\.'
doublePeriod[.]{2}

comment1		\/{2}.*

ID_LEX			[a-zA-Z][a-zA-Z0-9_]*
Whitespace 		[ \t\n]
ANY				.
%%

"if"				{
					return IF;
					//addToken(KEYWORD,string("IF"),string(yytext),yylineno); 
				}
"else" 			{ 
					return ELSE; 
					//addToken(KEYWORD,string("ELSE"),string(yytext),yylineno);
				}
"while"			{ 
					return WHILE; 
					//addToken(KEYWORD,string("WHILE"),string(yytext),yylineno);
				}
"for"				{ 
          			
					return FOR;
					//addToken(KEYWORD,string("FOR"),string(yytext),yylineno);
				}
"function"		{ 
					return FUNCTION; 
					//addToken(KEYWORD,string("FUNCTION"),string(yytext),yylineno);
				}
"return"		{ 
          			
					return RETURN; 
					//addToken(KEYWORD,string("RETURN"),string(yytext),yylineno);
				}
"break"			{ 
          			
					return BREAK; 
					//addToken(KEYWORD,string("BREAK"),string(yytext),yylineno);
				}
"continue"		{ 
          			
					return CONTINUE; 
					//addToken(KEYWORD,string("CONTINUE"),string(yytext),yylineno);
				}
"and"			{ 
          			
					return AND; 
					//addToken(KEYWORD,string("AND"),string(yytext),yylineno); 
				}
"not"				{ 
          			
					return NOT; 
					//addToken(KEYWORD,string("NOT"),string(yytext),yylineno);
				}
"or"				{ 
          			
					return OR; 
					//addToken(KEYWORD,string("OR"),string(yytext),yylineno);
				}
"local"			{ 
          			
					return LOCAL; 
					//addToken(KEYWORD,string("LOCAL"),string(yytext),yylineno); 
				}
"true"			{ 
          			
					return TRUE; 
					//addToken(KEYWORD,string("TRUE"),string(yytext),yylineno);
				}
"false"			{ 
          			
					return FALSE; 
					//addToken(KEYWORD,string("FALSE"),string(yytext),yylineno); 
				}
"nil"			{ 
          			
					return NIL; 
					//addToken(KEYWORD,string("NIL"),string(yytext),yylineno); 
				}
{ID_LEX}		{	
					yylval.stringValue = strdup(yytext);
					return ID;
					//addToken(IDENTIFIER,string(yytext),string(yytext),yylineno);
				}
				
"="				{ 
					return '=';
          			//addToken(OPERATOR,string("ASSIGNMENT"),string(yytext),yylineno);
				}				
"+"				{ 
          			return '+';
					//addToken(OPERATOR,string("PLUS"),string(yytext),yylineno);
				}				
"-"				{ 
          			return '-';
					//addToken(OPERATOR,string("MINUS"),string(yytext),yylineno);
				}
"*"				{ 
          			return '*';
					//addToken(OPERATOR,string("MULTIPLICATION"),string(yytext),yylineno);
				}
"/"				{ 
          			return '/';
					//addToken(OPERATOR,string("DIVISION"),string(yytext),yylineno);
				}
"%"				{ 
          			return '%';
					//addToken(OPERATOR,string("MODULO"),string(yytext),yylineno);
				}
"=="			{ 
          			return EQUAL;
					//addToken(OPERATOR,string("EQUALS"),string(yytext),yylineno);
				}
"!="			{ 
          			return NOTEQUAL;
					//addToken(OPERATOR,string("NOT_EQUALS"),string(yytext),yylineno);
				}
"++"			{	 
          			return PLUSPLUS;
					//addToken(OPERATOR,string("PLUS_PLUS"),string(yytext),yylineno);
				}
"--"			{ 
          			return MINUSMINUS;
					//addToken(OPERATOR,string("MINUS_MINUS"),string(yytext),yylineno);
				}
">"				{ 
          			return '>';
					//addToken(OPERATOR,string("GREATER"),string(yytext),yylineno);
				}
"<"				{ 
          			return '<';
					//addToken(OPERATOR,string("LESS"),string(yytext),yylineno);
				}
">="			{ 
          			return GREATEREQUAL;
					//addToken(OPERATOR,string("G_EQUAL"),string(yytext),yylineno);
				}
"<="			{ 
          			return LESSEQUAL;
					//addToken(OPERATOR,string("L_EQUAL"),string(yytext),yylineno);
				}
{integer}		{	
					// printf("Integer\n");
					yylval.floatValue = atof(yytext);
					return NUMBER;
					//addToken(INT_CONST,string(yytext),string(yytext),yylineno); 	
				}

{real}			{
					yylval.floatValue = atof(yytext);
					return NUMBER;
					//addToken(REAL_CONST,string(yytext),string(yytext),yylineno); 
				}

{Whitespace}	{
					//addToken(PUNCTUATION,string("LEFT_BRACKET"),string(yytext),yylineno); 
				}
"{"				{return '{';}

"}"  			{ return '}';} 

"["  			{ 
					return '[';
					//addToken(PUNCTUATION,string("RIGHT_BRACKET"),string(yytext),yylineno); 
				} 
"]"  			{ 
					return ']';
					//addToken(PUNCTUATION,string("RIGHT_BRACKET"),string(yytext),yylineno); 
				}
"("  			{ 
					return '(';
					//addToken(PUNCTUATION,string("RIGHT_BRACKET"),string(yytext),yylineno); 
				}
")"  			{ 
					return ')';
					//addToken(PUNCTUATION,string("RIGHT_BRACKET"),string(yytext),yylineno); 
				}
";"    			{ 
					return ';';
					//addToken(PUNCTUATION,string("RIGHT_BRACKET"),string(yytext),yylineno); 
				}
","     		{ 
					return ',';
					//addToken(PUNCTUATION,string("RIGHT_BRACKET"),string(yytext),yylineno); 
			    }
":"      		{ 
					return ':';
					//addToken(PUNCTUATION,string("RIGHT_BRACKET"),string(yytext),yylineno); 
				} 
{doubleColon}   { 
					return SCOPEOP;
					//addToken(PUNCTUATION,string("RIGHT_BRACKET"),string(yytext),yylineno); 
			    } 
"."    			{ 
					return '.';
					//addToken(PUNCTUATION,string("RIGHT_BRACKET"),string(yytext),yylineno); 
			    } 
{doublePeriod}  { 
					return DOUPLEDOT;
					//addToken(PUNCTUATION,string("RIGHT_BRACKET"),string(yytext),yylineno); 
			    }  


"\""		{ 	
			char input = *yytext; /*get input*/
  			char next;
  			string output;
  			int stringLine = yylineno;
  			int isLegal = 1;

  			while (input != EOF && (input = yyinput()) != '\0' ) {
    		/*Check cases which start with '\'*/
    			if (input == '\\') {
      				//Lookahead
      				next = yyinput();

      				if (next == 'n') {
        				output += '\n';
        				continue;
      				}else if (next == 't') {
        				output += '\t';
        				continue;
        			}else if (next == '\\') {
        				output += '\\';
        				continue;
      				}else if (next == '\"') {
        				output += '\"';
        				continue;
        			}else{
        				printf("Error: Illegal escape character \'%c%c\' in string at line %d\n",input,next,yylineno);
        				isLegal = 0;
        			}
				}


				/*check if string ends legally*/
				if(input== '\"'){
					if(isLegal){
					// addToken(STRING_TYPE, string("STRING_TYPE"), output, stringLine);
						yylval.stringValue = strdup(yytext);
						return STRING;
					}					 
					break;		
				}

    			output += input; 
  			}
  		
  		if (input == '\0') {
    		printf("Error: End-of-file reached while in string: %s at line #%d\n",yytext,stringLine);
    	}
}


{comment1}		; //addToken(COMMENT,string("LINE COMMENT"),"",yylineno);;

"/*"	{	
					char c;
			int start_line;
			string startToEnd;
			ostringstream convert1,convert2;
			std :: vector <int> v;

			v.push_back (yylineno);
	
			while(((c = yyinput()) != '\0') && (c  != EOF) )
			{
				if(c == '*')
				{
					if((c = yyinput()) == '/')
					{
						if(!v.empty())
						{
							start_line=v.back();
							v.pop_back();
							
							convert1<<start_line;
							convert2<<yylineno;
							startToEnd=convert1.str()+"-"+convert2.str();
							//addToken(COMMENT,string("C STYLE COMMENT"),startToEnd,start_line); 
							convert1.str(std::string());
							convert2.str(std::string());
							
						}
						if(v.empty()) break;
						
					}	
					else unput(c);
				}else if(c == '/')
				{
					if((c = yyinput()) == '*')
					v.push_back(yylineno);
					
					else
					unput(c);
				}
				
				
			}
			
			if(!v.empty()) std::cout << "End of file and unclosed comments\n";
		}

{ANY}		{printf("LEX: Invalid token %s at line: #%d \n",yytext,yylineno);}		
				
%%
//Global Hashtables
std::multimap<string,symTableEntry*> SymTableName;
std::multimap< int,symTableEntry*> SymTableScope;


// std::map<string,symTableEntry> SymTableScope; 
int current_scope = 0;
//Global token vector
vector  <alpha_token_t>* vctr_ptr; 
//Global token number
int token_number = 0;
//Global lex object
//yyFlexLexer temp;

int alpha_yylex(void* yylval){ 
  vctr_ptr = (vector <alpha_token_t>*) yylval;  
  return  yylex(); 
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
		case STRING_TYPE:
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
		case STRING_TYPE: 		return "STRING_TYPE";
		case OPERATOR: 		return "OPERATOR";
		case PUNCTUATION: 	return "PUNCTUATION";
		case COMMENT: 		return "COMMENT";
		default:			return "_UKNOWN_TYPE_";
	}
}

int main (int argc, char *argv[]){
	// vector <alpha_token_t> token_vector; 
	if (argc != 2) {
		std::cout <<"Incorrect usage."<<std::endl;
		std::cout <<"Use: ./scanner <input file> <optional output file>" <<std::endl;
    }else{
    	yyin = fopen(argv[1], "r");

   		scopeAccessStack.push(false);
   		insertLibFuncSym();
		yyparse();
   		scopeAccessStack.pop();

    	printSymTable();
    	fclose(yyin);
    }
  	return 0;
}



symTableEntry* lookupSym(string key){
	int max_scope = -1;
	symTableEntry* tempVal = NULL;
	std::pair <std::multimap<string,symTableEntry*>::iterator, std::multimap<string,symTableEntry*>::iterator> retList;
	
	retList = SymTableName.equal_range(key);

		for (std::multimap<string,symTableEntry*>::iterator it=retList.first; it!=retList.second; ++it){
			if(it->second->isVisible && it->second->scope > max_scope){
				max_scope = it->second->scope;
				tempVal = it->second;
			}
		}
	return tempVal;
}



symTableEntry* lookupSym(string key, int scope){
	std::pair <std::multimap<string,symTableEntry*>::iterator, std::multimap<string,symTableEntry*>::iterator> retList;
	retList = SymTableName.equal_range(key);

		for (std::multimap<string,symTableEntry*>::iterator it=retList.first; it!=retList.second; ++it){
			if(it->second->isVisible && it->second->scope == scope ){
				return it->second;
			}
		}
	return NULL;
}


void insertSym(string key,symTableType type,symTableEntry* args,int scp,unsigned int line){

	/*insert new symbol*/
	// symTableEntry* symptr = (symTableEntry*) malloc(sizeof(symTableEntry));
	symTableEntry* symptr = new symTableEntry();
	// std::cout<<"aft4er  malloc" << " key is : "<<key <<std::endl;
	
	symptr->name = key;
	// std::cout<<"symptr->name: " << symptr->name<<std::endl;
	// exit(1);
	// std::cout<<"aft4er  key" <<std::endl;
	symptr->symType = type;
	// std::cout<<"aft4er  type" <<std::endl;
	symptr->arguments = args;
	// std::cout<<"aft4er  args" <<std::endl;
	symptr->scope = scp;
	// std::cout<<"aft4er  scp" <<std::endl;
	symptr->declLine = line;
	// std::cout<<"aft4er  line" <<std::endl;
	symptr->isVisible = true;
	// std::cout<<"Befor insert" <<std::endl;
	SymTableName.insert ( std::pair<string,symTableEntry*>(key,symptr) );
	// std::cout<<"1 insert" <<std::endl;
	SymTableScope.insert( std::pair<int,symTableEntry*>(scp,symptr) );
	// std::cout<<"2 insert" <<std::endl;
}



void hideSym(int scope){
	std::pair <std::multimap<int,symTableEntry*>::iterator, std::multimap<int,symTableEntry*>::iterator> retList;
	retList = SymTableScope.equal_range(scope);

		for (std::multimap< int,symTableEntry*>::iterator it=retList.first; it!=retList.second; ++it){
			it->second->isVisible = false;
		}
}

bool lvalueCheckSym(symTableEntry* sym, int scope,unsigned int line){
	if(sym == NULL) return true;

	if(sym->symType == LIB_FUNC){
		std::cout <<"ERROR: cannot name symbol at line "  <<line <<" as library function "<<sym->name <<std::endl;
		return false;
	}
	return true;
}

void printSymTable(){
	int i = 0;
	int size = SymTableScope.size();

	for(i = 0; i<size; i++){
		std::pair <std::multimap< int,symTableEntry*>::iterator, std::multimap< int,symTableEntry*>::iterator> ret;
    	ret = SymTableScope.equal_range(i);
    	std::cout << "-------------" <<"	Scope #" <<i <<"	" << "-------------------" << endl;
    	for (std::multimap< int,symTableEntry*>::iterator it=ret.first; it!=ret.second; ++it){
      		std::cout << "\"" << it->second->name << "\"   [" <<symTableTypeToString(it->second->symType) <<"]";
      		std::cout <<"(line " <<it->second->declLine << ")" <<"		(scope " <<it->second->scope <<")" <<endl;
    	}
	}
}

string symTableTypeToString(symTableType t){
	switch(t){
		case GLOBAL_VAR:
			return "global variable";
		case LOCAL_VAR:
			return "local variable";
		case ARGUMENT_VAR:
			return "formal argument";
		case USER_FUNC:
			return "user function";
		case LIB_FUNC:
			return "library function";
		default:
			return "ERROR: Invalid symbol type";
	}
}

void insertLibFuncSym(){
	insertSym(std::string("print"),LIB_FUNC,NULL,0,0);
	insertSym(std::string("input"),LIB_FUNC,NULL,0,0);
	insertSym(std::string("objectmemberkeys"),LIB_FUNC,NULL,0,0);
	insertSym(std::string("objecttotalmembers"),LIB_FUNC,NULL,0,0);
	insertSym(std::string("objectcopy"),LIB_FUNC,NULL,0,0);
	insertSym(std::string("totalarguments"),LIB_FUNC,NULL,0,0);
	insertSym(std::string("argument"),LIB_FUNC,NULL,0,0);
	insertSym(std::string("typeof"),LIB_FUNC,NULL,0,0);
	insertSym(std::string("strtonum"),LIB_FUNC,NULL,0,0);
	insertSym(std::string("sqrt"),LIB_FUNC,NULL,0,0);
	insertSym(std::string("cos"),LIB_FUNC,NULL,0,0);
	insertSym(std::string("sin"),LIB_FUNC,NULL,0,0);
}


bool checkCollisionSym(string key){
	if(key =="print" || key == "input" || key == "objectmemberkeys" || key == "objecttotalmembers" || key == "objectcopy" || key == "totalarguments" || key == "argument" || key == "typeof" || key == "strtonum" || key == "sqrt" || key == "cos" || key == "sin"){
		return true;
	}
	return false;
}
