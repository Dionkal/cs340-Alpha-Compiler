#include <stdio.h>
#include <string>
#include <map>


typedef enum symTableType {GLOBAL_VAR,LOCAL_VAR,ARGUMENT_VAR,USER_FUNC,LIB_FUNC} symTableType;

typedef struct symTableEntry{
	string 			name;			//Name of the symbol
	symTableType 	symType;		//Type of the symbol see the enum SymTableType
	string*			arguments;		//List of arguments passed in the function (only for functions)
	int 			scope;			//int value representing the scope where the current symbol is declared
	size_t			declLine;		//Contains the line where the current symbol is first declared
} symTableEntry;