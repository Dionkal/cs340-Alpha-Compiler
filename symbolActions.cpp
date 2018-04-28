#include "symtable.h"
#include <stdlib.h>
#include <stdio.h>
#include <stack>
#include <iostream>

extern int yylineno;
extern char* yytext;
extern FILE* yyin;
extern int current_scope;
extern std::stack<bool> scopeAccessStack;
extern unsigned int anonymousCounter; /*for anonymus functions*/

static unsigned int tempVariableCounter = 0; 



symTableEntry* actionID(std::string id){
 	symTableEntry* ptr = lookupSym(id);

	if(ptr==NULL){
		symTableType type;
		
		if(current_scope == 0){
			type = GLOBAL_VAR;
		}else{
			type = LOCAL_VAR;
		}
		
		insertSym(id,type,NULL,current_scope,yylineno);
		ptr = lookupSym(id);
	}else{

		if( scopeAccessStack.top() && (ptr->symType == LOCAL_VAR || ptr->symType == ARGUMENT_VAR) && (ptr->scope != current_scope && ptr->scope != 0)){
			std::cout  <<"\033[01;31mERROR cannot access " <<ptr->name <<" in scope " <<ptr->scope <<" at line " <<yylineno <<"\033[00m" << std::endl;
			ptr = NULL;
		}
	}
	return ptr;
}



symTableEntry* actionLocalID(std::string id){
	symTableEntry* ptr = lookupSym(id,current_scope);
											
	if(ptr==NULL){
		
		if(checkCollisionSym(id)){
			std::cout <<"\033[01;31mERROR: cannot name symbol at line "  <<yylineno <<" as library function "<<id << "\033[00m" << std::endl;
		}else{
			symTableType type;
			
			if(current_scope == 0){
				type = GLOBAL_VAR;
			}else{
				type = LOCAL_VAR;
			}
			
			insertSym(id,type,NULL,current_scope,yylineno);
				ptr = lookupSym(id);
		}
	}

	return ptr;
}


symTableEntry* actionGlobalID(std::string id){
	symTableEntry* ptr = lookupSym(id,0);
											
	if(ptr == NULL) std::cout << "\033[01;31mERROR there is no global var " << id << "\033[00m" <<std::endl;

	return ptr;
}


/*Returns the name of the next hidden variable */
std::string newtempname(){ return "_t" + std::to_string(tempVariableCounter++); }

/*Returns the entry of the symTable that corresponds to the current variable, if no variable with that
name exists then it creates a new one and inserts it into the symTable*/
symTableEntry* newtemp(){
	std::string name = newtempname(); 
	
	symTableEntry* sym =lookupSym(name,current_scope);
	if(sym == NULL){
		insertSym(name,LOCAL_VAR,NULL,current_scope, yylineno);
		sym =lookupSym(name,current_scope);
	}
	return sym;
}


/*Resets the hidden variable counter to zero*/
void resettemp(){tempVariableCounter = 0; }