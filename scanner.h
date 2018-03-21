#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <sstream> 
#include <fstream>
#include <map>

using namespace std;

typedef enum{KEYWORD,IDENTIFIER,INT_CONST,REAL_CONST,STRING,OPERATOR,PUNCTUATION,COMMENT} type;

typedef struct{
	int number_of_token;
	int line_number;
	type token_type; 
	string str_subType;
	string token_value;
	string arrow_type;

}alpha_token_t;

/*Adds the given token to the global vector*/
void addToken(type token_t,string token_sT, string value, int line);


/*code for strings*/
void stringAction();


/*********************Sym Table Utilities*********************/
typedef enum symTableType {GLOBAL_VAR,LOCAL_VAR,ARGUMENT_VAR,USER_FUNC,LIB_FUNC} symTableType;

typedef struct symTableEntry{
	string 			name;			//Name of the symbol
	symTableType 	symType;		//Type of the symbol see the enum SymTableType
	string*			arguments;		//List of arguments passed in the function (only for functions)
	int 			scope;			//int value representing the scope where the current symbol is declared
	size_t			declLine;		//Contains the line where the current symbol is first declared
} symTableEntry;