#include "dispatcher.h"

extern std::vector<instruction> vctr_instr;

bool executionFinished = false;
unsigned pc = 0;
unsigned currLine = 0;
unsigned codeSize = 0;
instruction *code = NULL;

#define AVM_ENDING_PC codeSize

execute_func_t executeFuncs[] = {
	execute_assign,
	execute_add,
	execute_sub,
	execute_mul,
	execute_div,
	execute_mod,
	execute_nop, // uminus
	execute_nop, // and
	execute_nop, // or
	execute_nop, // not
	execute_jeq,
	execute_jne,
	execute_jle,
	execute_jge,
	execute_jlt,
	execute_jgt,
	execute_call,
	execute_pusharg,
	execute_nop, // return
	execute_nop, // get return value
	execute_funcenter,
	execute_funcexit,
	execute_newtable,
	execute_tablegetelem,
	execute_tablesetelem,
	execute_nop, //jump
	execute_nop};

void execute_cycle()
{
	if (executionFinished)
		return;

	if (pc == AVM_ENDING_PC)
	{
		executionFinished = 1;
		return;
	}
	else
	{
		assert(pc < AVM_ENDING_PC);
		instruction *instr = &vctr_instr[pc]; //get the next isntruction to execute
		assert(instr->vm_op >= 0 && instr->vm_op <= AVM_MAX_INSTRUCTIONS);

		/*Optimization: change the currline only if the
		source line has changed from previous instruction*/
		if (instr->vm_srcLine)
		{
			currLine = instr->vm_srcLine;
		}

		unsigned oldPC = pc;
		/*TODO uncomment next line when execute function is implemented*/
		(*executeFuncs[instr->vm_op])(instr);

		if (pc == oldPC)
			++pc; //execute next instr
	}
}
