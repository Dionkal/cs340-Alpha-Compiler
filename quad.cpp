#include "quad.h"
#include "symbolUtilities.h"
#include <vector>
#include <iostream>
#include <stack>
#include <stdlib.h>
#include <stdio.h>

extern int yylineno;

/*Global vector that contains all the quads*/
std::vector  <quad> vctr_quads; 



void emit(iopcode opCode,expr *_arg1,expr *_arg2,expr *_res,unsigned _label,int yylineno){
	
	/*Create new quad*/
	quad *newQuad = new quad();
	
	newQuad->op=opCode;
	newQuad->arg1=_arg1;
	newQuad->arg2=_arg2;
	newQuad->result=_res;
	newQuad->label=_label;
	newQuad->line=yylineno;
	
	vctr_quads.push_back(*newQuad);	

}

expr* emit_arithexpr(iopcode opCode,expr *_arg1,expr *_arg2,int yylineno){
	
	if(isValidArithexpr(_arg1) && isValidArithexpr(_arg2)){											
		expr* result_e = newexpr(arithexpr_e);
		result_e->sym = newtemp();
		emit(opCode,_arg1, _arg2,result_e,0,yylineno);
		return result_e;
	}else{
		std::cout <<"ERROR: invalid arithexpr";
		printExpr(_arg1);
		std::cout <<std::endl;
		printExpr(_arg1);
		std::cout <<std::endl;
		return NULL;
	}
}

std::string iopcodeToString(iopcode op){
	/*TODO: add cases for more opcodes*/
	switch(op){
		case assign_iopcode: 			return "ASSIGN_OPCODE";
		case add_iopcode: 				return "ADD_IOPCODE";
		case sub_iopcode:				return "SUB_IOPCODE"; 
		case mul_iopcode:				return "MUL_IOPCODE";
		case div_iopcode:				return "DIV_IOPCODE";
		case mod_iopcode:				return "MOD_IOPCODE";
		case funcstart_iopcode: 		return "FUNCSTART_IOPCODE";
		case funcend_iopcode: 			return "FUNCEND_IOPCODE";
		case tablegetelem_iopcode:		return "TABLEGETELEM_IOPCODE";
		case tablesetelem_iopcode:		return "TABLESETELEM_IOPCODE";
		case call_iopcode:				return "CALL_IOPCODE";
		case param_iopcode:				return "PARAM_IOPCODE";
		case getretval_iopcode:			return "GETRETVAL_IOPCODE";
		default: 						return "INVALID IOPCODE";
	}
}

std::string expr_ToString(expr_t e){
	switch(e){
		case var_e: 			return "var_e";
		case tableitem_e: 		return "tableitem_e";
		case programfunc_e: 	return "programfunc_e";
		case libraryfunc_e:		return "libraryfunc_e";
		case arithexpr_e:		return "arithexpr_e";
		case boolexpr_e:		return "boolexpr_e";
		case assignexpr_e:		return "assignexpr_e";
		case newtable_e:		return "newtable_e";
		case costnum_e:			return "costnum_e";
		case constbool_e:		return "constbool_e";
		case conststring_e:		return "conststring_e";
		case nil_e:				return "nil_e";
		default:				return "invalid expression type";
	}
}

void printSymbol(symTableEntry* sym){
	std::cout <<"\t\t\t" <<"name: " << sym->name <<std::endl;
	if(sym->symType != USER_FUNC && sym->symType != LIB_FUNC) std::cout <<"\t\t\t" <<"offset: " <<sym->offset <<std::endl;
	/*WIP: print more members*/
}


/*Prints the given expression*/
void printExpr(expr* e){
	std::cout <<"\t\tType: " << expr_ToString(e->type) <<std::endl; 
	if (e->sym) {std::cout <<"\t\tSymbol: " <<std::endl; printSymbol(e->sym);}

	/*TODO print index*/
	if (e->numConst)std::cout <<"\t\tnumConst: " << e->numConst <<std::endl;
	if (!e->strConst.empty())std::cout <<"\t\tstrConst: " << e->strConst <<std::endl;
	if (e->boolConst)std::cout <<"\t\tboolConst: " << e->boolConst <<std::endl;
	/*TODO: print next*/

}


/*Prints all the quads in the vector*/
void printQuads(){
	int count = 1;		
	for (std::vector<quad>::const_iterator i = vctr_quads.begin(); i != vctr_quads.end(); ++i){
		std::cout <<"#" <<"Quad " <<count++ <<": " <<std::endl;
		std::cout <<"\tiopcode: " << iopcodeToString(i->op) << "\n";
		
		if(i->arg1){
			std::cout <<"\targ1: " << "\n";
			printExpr( i->arg1);
		}
		
		if(i->arg2) {
			std::cout << "\targ2: " << "\n";
			printExpr( i->arg2);
		}
		if(i->result) {
			std::cout << "\tresult: " << "\n";
			printExpr( i->result);
		}
		if(i->label) std::cout << "\tlabel: " <<i->label << "\n";

		if(i->line) std::cout << "\tline: " <<i->line << "\n";

	}
}

expr *newexpr(expr_t e){
	expr *ptr=new expr();

	ptr->type=e;

	return ptr;
}


unsigned nextquadLabel(void){
	return vctr_quads.size();
}


/*Checks if the given expression is a valid arithmetic one
 returns: true for valid / false for invalid*/
bool isValidArithexpr(expr* e){
	if(e->type == programfunc_e || e->type == libraryfunc_e || e->type == boolexpr_e 
		|| e->type == newtable_e || e->type == constbool_e 
		|| e->type == conststring_e || e->type == nil_e)
	{
		return false;
	} 
	return true;
}



expr *member_item(expr *e,std::string id){
	expr *item;
	e = emit_iftableitem(e);
	item = newexpr(tableitem_e);
	item->sym = e->sym;
	item->index = newxpr_conststring(id);

	return item;
}

expr *newxpr_conststring(std::string s){
	expr *e = newexpr(conststring_e);
	e->strConst = s;
	return e;
}

expr* emit_iftableitem(expr *e){

	if(e->type!=tableitem_e){
		return e;
	}
	else{
		expr* result = newexpr(var_e);
		result->sym = newtemp();
		emit(tablegetelem_iopcode,e,e->index,result,0,yylineno);
		return result;
	}
}

expr *make_call(expr *lvalue,expr* elist){
  std::stack <expr *> callsElist;
  expr *func,*lnext,*result;
  func=emit_iftableitem(lvalue);
 
  lnext=elist;

  //diatreksi autis tis listas:exei to elist 
  while(lnext!=NULL){
    callsElist.push(lnext);
    lnext=lnext->next;
  }
  while(!callsElist.empty()){
  	emit(param_iopcode,NULL,NULL,callsElist.top(),0,yylineno);
  	callsElist.pop();
  }
 
  emit(call_iopcode,NULL,NULL,func,0,yylineno);
 
  result=newexpr(var_e);
  result->sym=newtemp();
  emit(getretval_iopcode,NULL,NULL,result,0,yylineno);
 
 
  return result; 
}