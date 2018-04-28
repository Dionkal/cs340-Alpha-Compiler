#include <string>

typedef enum symTableType {GLOBAL_VAR,LOCAL_VAR,ARGUMENT_VAR,USER_FUNC,LIB_FUNC} symTableType;

typedef enum scopespace_t{
	programvar,functionlocal,formalarg
}scopespace_t;

typedef	enum symbol_t{
	var_s,programfunc_s,libraryfunc_s
}symbol_t;

typedef struct symTableEntry{
	std::string 	name;			//Name of the symbol
	symTableType 	symType;		//Type of the symbol see the enum SymTableType
	symTableEntry*	arguments;		//List of arguments passed in the function (only for functions)
	int 			scope;			//int value representing the scope where the current symbol is declared
	unsigned int 	declLine;		//Contains the line where the current symbol is first declared
	bool 			isVisible;		//Flag for hidden tokens (TRUE = visible, FALSE = hidden)
	int 			offset;
	symbol_t		type;
	scopespace_t	space;
} symTableEntry;


/*Searches the Symbol table to find the given symbol name
 from current scope to global scope.If there is no such symbol
 found then returns a null pointer */
symTableEntry* lookupSym(std::string key);

/*/*Searches the Symbol table to find the given symbol name ONLY 
int the given scope*/
symTableEntry* lookupSym(std::string key,  int scope);

/*Creates a new symbol and inserts its reference  to both symTables*/
void insertSym(std::string key,symTableType type,symTableEntry* args, int scp, unsigned int line);

/*Sets the visibility flag of all  symbols of the given scope to FALSE*/
void hideSym(int  scope);

bool lvalueCheckSym(symTableEntry* sym,  int scope, unsigned int line);

/*Prints the entire symTable by scope order*/
void printSymTable();

/*convert symTableType enum to string values*/
std::string symTableTypeToString(symTableType t);

/*inserts all library functions into the SymTable*/
void insertLibFuncSym();

bool checkCollisionSym(std::string key);