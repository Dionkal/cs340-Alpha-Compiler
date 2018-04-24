#include "3hfasi.h"
#include <vector>
#include <iostream>

std::vector <quad> vctr_quads; 

void addQuad(quad created){
	vctr_quads.push_back(created);	
}

quad* createQuad(iopcode opCode,expr *_arg1,expr *_arg2,expr *_res,unsigned _label,int yylineno){
	quad *newQuad= new quad();
	
	newQuad->op=opCode;
	newQuad->arg1=_arg1;
	newQuad->arg2=_arg2;
	newQuad->result=_res;
	newQuad->label=_label;
	newQuad->line=yylineno;
	
	return newQuad;
}

void emit(iopcode opCode,expr *_arg1,expr *_arg2,expr *_res,unsigned _label,int yylineno){
	quad *newQ=createQuad(opCode,_arg1,_arg2,_res,_label,yylineno);
	addQuad(*newQ);
}

void printQuads(){
		
	for (std::vector<quad>::const_iterator i = vctr_quads.begin(); i != vctr_quads.end(); ++i){
		std::cout << i->op << "\n";
		std::cout << i->arg1 << "\n";
		std::cout << i->arg2 << "\n";
		std::cout << i->result << "\n";
		std::cout << i->label << "\n";
		std::cout << i->line << "\n";
		std::cout <<"_____________"<< "\n"<< "\n";
	}
}