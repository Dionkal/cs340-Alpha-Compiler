#include "quad.h"
#include <vector>
#include <iostream>
#include <assert.h>

std::vector <quad> vctr_quads; 

unsigned programVarOffset=0;
unsigned functionLocalOffset=0;
unsigned formalArgOffset=0;

unsigned scopeSpaceCounter=1;

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

scopespace_t currScopeSpace(void){
	scopespace_t curr;

	if(scopeSpaceCounter==1)
		curr=programvar;
	else if(scopeSpaceCounter%2==0)
		curr=formalarg;
	else
		curr=functionlocal;

	return curr;
}

void enterScopeSpace(void){
	++scopeSpaceCounter;
}

void exitScopeSpace(void){
	assert(scopeSpaceCounter>0);

	scopeSpaceCounter-=2;//stis diafaneies eiani allios alla etsi m fainetai sosto sel 53 dialeksi 9
}

void inCurrScopeOffset(void){
	scopespace_t spc=currScopeSpace();

	switch(spc){
		case programvar	: ++programVarOffset; 		break;
		case functionlocal 		: ++functionLocalOffset;	break;
		case formalarg 			: ++formalArgOffset;		break;
		default					: assert(0);
	}
}

unsigned currScopeOffset(void){
	scopespace_t spc=currScopeSpace();

	switch(spc){
		case programvar	: return programVarOffset;
		case functionlocal 		: return functionLocalOffset;
		case formalarg 			: return formalArgOffset;
		default					: assert(0);
	}
}