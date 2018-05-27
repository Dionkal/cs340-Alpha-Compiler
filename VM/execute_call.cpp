#include "execute_call.h"


#define AVM_NUMACTUALS_OFFSET 	4
#define AVM_SAVEDTOP_OFFSET 	2
#define AVM_SAVED_PC_OFFSET 	3
#define AVM_SAVEDTOPSP_OFFSET	1

extern unsigned top,topsp;
extern bool 	executionFinished;
extern avm_memcell stack[AVM_STACKSIZE];
extern unsigned pc;
extern avm_memcell eax;
extern unsigned  pc;
extern std::vector<instruction> vctr_instr;
extern user_func_array_entry* avm_getfuncinfo(unsigned address);

unsigned totalActuals = 0;


void avm_dec_top(void){
	if(!top){ //stack overflow (not the site)
/*TODO:call avmerror*/
		// avm_error("stack overflow");
		executionFinished = 1;
	}else{
		--top;
	}
}

void avm_push_envvalue(unsigned val){
	stack[top].type = number_m;
	stack[top].data.numVal = val;
	avm_dec_top();
}

void avm_callsaveenvironment(void){
	avm_push_envvalue(totalActuals);
	avm_push_envvalue(pc +1);
	avm_push_envvalue(top + totalActuals + 2);
	avm_push_envvalue(topsp);
}


void execute_call (instruction* instr){
	avm_memcell* func = avm_translate_operand(&instr->vm_result, &eax);
	assert(func);
	avm_callsaveenvironment();

	switch(func->type){
		case userfunc_m: {
			pc = func->data.funcVal;
			/*TODO: fix AVM_ENDING_PC*/
			// assert(pc<AVM_ENDING_PC);
			assert(vctr_instr[pc].vm_op == funcstart_vmopcode);
			break;
		}
		/*TODO: add avm_calllibfunc*/
		// case string_m: avm_calllibfunc(func->data.strVal); break;
		// case libfunc_m: avm_calllibfunc(func->data.libfuncVal); break;

		default:
			/*TODO avm_to stirng + cll avm_error*/
			// avm_error("call: cannot bind %s to function!", s);
			executionFinished = 1;
	}		
}


void execute_funcenter(instruction* instr){
	avm_memcell* func = avm_translate_operand(&instr->vm_result, &eax);
	assert(func);
	assert(pc == func->data.funcVal);

	/*Callee actions*/
	totalActuals = 0;
	user_func_array_entry* funcInfo = avm_getfuncinfo(pc);
	topsp = top;
	top = top - funcInfo->local_size;
}

unsigned avm_get_envvalue(unsigned i){
	assert(stack[i].type = number_m);
	unsigned val = (unsigned) stack[i].data.numVal;
	assert(stack[i].data.numVal == ((double) val));
	return val;
}

void execue_funcexit(instruction* unused){
	unsigned oldTop = top;
	top 	= avm_get_envvalue(topsp + AVM_SAVEDTOP_OFFSET);
	pc 		= avm_get_envvalue(topsp + AVM_SAVED_PC_OFFSET);
	topsp 	= avm_get_envvalue(topsp + AVM_SAVEDTOPSP_OFFSET); 

	while(++oldTop <= top){
		/*TODO avm_memcellclear*/
		// avm_memcellclear(&stack[oldTop]);
	}
}