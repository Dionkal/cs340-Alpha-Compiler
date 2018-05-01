#include "symbolUtilities.h"
#include <stack>
#include <iostream>

extern int yylineno;
extern int current_scope;

static unsigned int tempVariableCounter = 0; 
unsigned int scopeSpaceCounter = 1;
unsigned int programVarOffset = 0;

std::stack<offset> offsetStack;

/*Returns the name of the next hidden variable */
std::string newtempname(){ return "_t" + std::to_string(tempVariableCounter++); }

/*Returns the entry of the symTable that corresponds to the current variable, if no variable with that
name exists then it creates a new one and inserts it into the symTable*/
symTableEntry* newtemp(){
	std::string name = newtempname(); 
	
	symTableEntry* sym =lookupSym(name,current_scope);
	if(sym == NULL){
		insertSym(name,LOCAL_VAR,current_scope, yylineno);
		sym =lookupSym(name,current_scope);
	}
	return sym;
}


/*Resets the hidden variable counter to zero*/
void resettemp(){tempVariableCounter = 0; }

/*Returns the corresponding scopespace type*/
scopespace_t current_scopescape(){
	if(scopeSpaceCounter == 1 ) return programvar; /*we haven't been inside a function*/

	if( (scopeSpaceCounter % 2) == 0){
		return formalarg; /*We are in formal arglist*/
	}else{
		return functionlocal; /*Inside function's body*/
	}
}

/*Creates a new offset entry in the stack for formal and local vars
 and initializes them with 0*/
void newOffset(){
	offset* ptr = new offset();
	ptr->functionLocalOffset = 0;
	ptr->formalArgOffset = 0;
	
	offsetStack.push(*ptr);
}

/*Removes one offset entry from the stack*/
void deleteOffset(){
	if(!offsetStack.empty()) offsetStack.pop();
}


/*Returns the corresponding offset depending on the current scopespace*/
unsigned int currScopeOffset(){
	switch(current_scopescape()){
		case programvar: 		return programVarOffset;
		case formalarg: 		return  offsetStack.top().formalArgOffset;
		case functionlocal: 	return offsetStack.top().functionLocalOffset;
		default: 
			std::cout << "ERROR: In currScopeOffset, unknown scopespace" <<std::endl;
			return 0;
	}
}

/*Increments the corresponding offset depending on the current scope*/
void incrementScopeOffset(){
	switch(current_scopescape()){
		case programvar: 		
			programVarOffset++;
			break;
		case formalarg: 		 
			offsetStack.top().formalArgOffset++;
			break;
		case functionlocal:
			offsetStack.top().functionLocalOffset++;
			break;
		default: 
			std::cout << "ERROR: In incrementScopeOffset, unknown scopespace" <<std::endl;
	}	
}