#include "quad.h"
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

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

std::string iopcodeToString(iopcode op){
	switch(op){
		case assign_iopcode: 	return "ASSIGN_OPCODE";
		case add_iopcode: 		return "ADD_IOPCODE";
		case sub_iopcode:		return "SUB_IOPCODE"; 
		case mul_iopcode:		return "MUL_IOPCODE";
		case div_iopcode:		return "DIV_IOPCODE";
		case mod_iopcode:		return "MOD_IOPCODE";
		case funcstart_iopcode: return "FUNCSTART_IOPCODE";
		case funcend_iopcode: 	return "FUNCEND_IOPCODE";
		default: 				return "INVALID IOPCODE";
	}
}

std::string expr_tToString(expr_t e){
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

void printExpr(expr* e){
	std::cout <<"\t\tType: " << expr_tToString(e->type) <<std::endl; 
	if (e->sym)std::cout <<"\t\tSymbol: " << "name: " <<e->sym->name  <<" offset: " <<e->sym->offset <<std::endl;
	/*TODO print index*/
	if (e->numConst)std::cout <<"\t\tnumConst: " << e->numConst <<std::endl;
	if (e->strConst)std::cout <<"\t\tstrConst: " << e->strConst <<std::endl;
	if (e->boolConst)std::cout <<"\t\tboolConst: " << e->boolConst <<std::endl;
	/*TODO: print next*/

}


/*Prints all the quads in the vector*/
void printQuads(){
	int count = 0;		
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