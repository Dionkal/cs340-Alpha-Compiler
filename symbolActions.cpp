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

//eriona ioanna

expr *member_item(expr *e,std::string id){
	expr *item;
	e=emit_iftableitem(e);
	item=newepxr(tableitem_e);
	item->sym=e->sym;
	item->index=newexpr_conststring(id);

	return item;
}

expr *newxpr_constrstring(std::string s){
	expr *e=newepxr(conststring_e);
	e->strConst=strdup(s);//TODO: replace strdup with c++ func
	return e;
}

expr *emit_iftableitem(expr *e){
	expr *result;

	if(e->type!=tableitem_e){
		return e;
	}
	else{
		result=newepxr(var_e);//needs understanidn before valsamakis
		result->sym=newtemp();
		emit(tablegetelem_iopcode,e,e->index,result,0,yylineno);//label=0 fort he time being
		//e->index needs underastnid:: is it q.a?
		return result;
	}
}

expr *make_call(expr *lvalue,expr* elist){
	expr *func=emit_iftableitem(lvalue);

	//diatreksi autis tis listas:exei to elist
	for(std::vector<expr *>::iterator it = vctr_elist.begin() ; it != vctr_elist.end(); ++it){
		emit(param_iopcode,NULL,NULL,it,0,yylineno);
		//needs filling
	}
	
}