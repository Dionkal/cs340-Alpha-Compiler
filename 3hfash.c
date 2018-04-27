#include "quad.h"
#include <vector>
#include <iostream>


std::vector  <quad> vctr_quads; 

void addQuad(quad *created){
	vctr_quads.push_back(created);	
}

quad* createQuad(iopcode opCode,expr *_arg1,expr *_arg2,expr *_res,unsigned _label,int yylineno){
	quad *newQuad= malloc(sizeof(quad));//probably wrong
	
	newQuad->op=opCode;
	newQuad->arg1=_arg1;
	newQuad->arg2=_arg2;
	newQuad->result=_res;
	newQuad->label=_label;
	newQuad->line=yylineno;
	
	return quad;
}

void emit(expr *_arg1,expr *_arg2,expr *_res){
	addQuad(createQuad(_arg1,_arg2,_res);
}

void printQuads(){
		
	for (std::vector<quad>::const_iterator i = vctr_quads.begin(); i != vctr_quads.end(); ++i){
		std::cout << i->op << "\n";
		std::cout << i->arg1 << "\n"
		std::cout << i->arg2 << "\n";
		std::cout << i->result << "\n";
		std::cout << i->label << "\n";
		std::cout << i->line << "\n";
		std::cout <<"_____________"<< "\n"<< "\n";
	}
}