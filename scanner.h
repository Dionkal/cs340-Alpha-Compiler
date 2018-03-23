#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <sstream> 
#include <fstream>
#include <map>

using namespace std;

typedef enum{KEYWORD,IDENTIFIER,INT_CONST,REAL_CONST,STRING_TYPE,OPERATOR,PUNCTUATION,COMMENT} type;

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
	unsigned int 	declLine;		//Contains the line where the current symbol is first declared
	bool 			isVisible;		//Flag for hidden tokens (TRUE = visible, FALSE = hidden)
} symTableEntry;


/*Searches the Symbol table to find the given symbol name
 from current scope to global scope.If there is no such symbol
 found then returns a null pointer */
symTableEntry* lookupSym(string key);

/*/*Searches the Symbol table to find the given symbol name ONLY 
int the given scope*/
symTableEntry* lookupSym(string key, int scope);

/*Creates a new symbol and inserts its reference  to both symTables*/
void insertSym(string key,symTableType type,string* args,int scp,unsigned int line);

/*Sets the visibility flag of all  symbols of the given scope to FALSE*/
void hideSym(int scope);