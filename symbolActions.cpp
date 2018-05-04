#include "symtable.h"
#include <stdlib.h>
#include <stdio.h>
#include <stack>
#include <iostream>
#include <sstream>

extern int yylineno;
extern char* yytext;
extern FILE* yyin;
extern int current_scope;
extern std::stack<bool> scopeAccessStack;
extern unsigned int anonymousCounter; /*for anonymus functions*/




symTableEntry* actionID(std::string id){
 	symTableEntry* ptr = lookupSym(id);

	if(ptr==NULL){
		symTableType type;
		
		if(current_scope == 0){
			type = GLOBAL_VAR;
		}else{
			type = LOCAL_VAR;
		}
		
		insertSym(id,type,current_scope,yylineno);
		
		ptr = lookupSym(id,current_scope);
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
			
			insertSym(id,type,current_scope,yylineno);
			ptr = lookupSym(id,current_scope);
		}
	}

	return ptr;
}


symTableEntry* actionGlobalID(std::string id){
	symTableEntry* ptr = lookupSym(id,0);
											
	if(ptr == NULL) std::cout << "\033[01;31mERROR there is no global var " << id << "\033[00m" <<std::endl;

	return ptr;
}

symTableEntry* actionFuncdefID(std::string id) {
  symTableEntry* ptr = lookupSym(id, current_scope);
  
  if (ptr == NULL) {
    if (checkCollisionSym(id)) {
      std::cout << "\033[01;31mERROR: cannot define function at line "
                << yylineno << " as library function " << id << "\033[00m"
                << std::endl;
    } else {
    	insertSym(id, USER_FUNC, current_scope, yylineno);
     	ptr = lookupSym(id,current_scope);
    }
  } else {
  	std::cout << "\033[01;31mERROR: Symbol" << id 
  			  << " already defined at line" << ptr->declLine 
  			  << "\033[00m" <<std::endl;
  }
  return ptr;
}

symTableEntry* actionFuncdefAnon(){
	std::string StringTemp = static_cast<std::ostringstream*>( &(std::ostringstream() << anonymousCounter) )->str();
	std::string anonFunc = "_anonFunc" + StringTemp;
	anonymousCounter++;
	insertSym(anonFunc,USER_FUNC,current_scope,yylineno);
	return lookupSym(anonFunc, current_scope);
}
