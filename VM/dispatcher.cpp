#include "dispatcher.h"

extern std::vector<instruction> vctr_instr;

bool 			executionFinished = false;
unsigned 		pc = 0;
unsigned 		currLine = 0;
unsigned 		codeSize = 0;
instruction* 	code = NULL;

#define AVM_ENDING_PC 	codeSize

void execute_cycle(){
	if(executionFinished) return;

	if(pc == AVM_ENDING_PC){
		executionFinished = 1;
		return;
	}else{
		assert( pc < AVM_ENDING_PC);
		instruction* instr = &vctr_instr[pc]; //get the next isntruction to execute
		assert(instr->vm_op >= 0 && instr->vm_op <= AVM_MAX_INSTRUCTIONS);

		/*Optimization: change the currline only if the
		source line has changed from previous instruction*/
		if(instr->vm_srcLine){
			currLine = instr->vm_srcLine;
		}

		unsigned oldPC = pc;
		/*TODO uncomment next line when execute function is implemented*/
		// (*executeFuncs[instr->vm_op]) (instr); 

		if(pc== oldPC) ++pc; //execute next instr
	}
}