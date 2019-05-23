#include "execute_call.h"
#include "toString.h"

#define AVM_ENDING_PC codeSize

extern unsigned top, topsp;
extern bool executionFinished;
extern avm_memcell stack[AVM_STACKSIZE];
extern unsigned pc;
extern avm_memcell ax;
extern unsigned pc;
extern std::vector<instruction> vctr_instr;
extern std::vector<user_func_array_entry> user_func_array;
extern std::vector<std::string> lib_func_used_array;
extern unsigned codeSize;
extern unsigned totalActuals;

typedef std::string (*tostring_func_t)(avm_memcell *);

extern std::string number_tostring(avm_memcell *);
extern std::string string_tostring(avm_memcell *);
extern std::string bool_tostring(avm_memcell *);
extern std::string table_tostring(avm_memcell *);
extern std::string userfunc_tostring(avm_memcell *);
extern std::string libfunc_tostring(avm_memcell *);
extern std::string nil_tostring(avm_memcell *);
extern std::string undef_tostring(avm_memcell *);

void execute_call(instruction *instr)
{
	avm_memcell *func = avm_translate_operand(&instr->vm_result, &ax);
	assert(func);
	avm_callsaveenvironment();

	switch (func->type)
	{
	case userfunc_m:
	{
		pc = func->data.funcVal;
		assert(pc < AVM_ENDING_PC);
		assert(vctr_instr[pc].vm_op == funcstart_vmopcode);
		break;
	}
	case string_m:
		avm_calllibfunc(func->data.strVal);
		break;
	case libfunc_m:
		avm_calllibfunc(func->data.libfuncVal);
		break;

	default:
		std::string str = avm_tostring(func);
		avm_error("call: cannot bind %s to function!", str);
		executionFinished = 1;
	}
}

void execute_funcenter(instruction *instr)
{
	avm_memcell *func = avm_translate_operand(&instr->vm_result, &ax);
	assert(func);
	assert(pc == func->data.funcVal);

	/*Callee actions*/
	totalActuals = 0;
	user_func_array_entry *funcInfo = avm_getfuncinfo(pc);
	topsp = top;
	top = top - funcInfo->local_size;
}

void execute_funcexit(instruction *unused)
{
	unsigned oldTop = top;
	top = avm_get_envvalue(topsp + AVM_SAVEDTOP_OFFSET);
	pc = avm_get_envvalue(topsp + AVM_SAVED_PC_OFFSET);
	topsp = avm_get_envvalue(topsp + AVM_SAVEDTOPSP_OFFSET);

	while (++oldTop <= top)
	{
		avm_memcellclear(&stack[oldTop]);
	}
}

void execute_pusharg(instruction *instr)
{
	avm_memcell *arg = avm_translate_operand(&instr->vm_arg1, &ax);
	assert(arg);
	/*
		This is actually stack[top] = arg, but we have to
		use avm_assign.
	 */
	avm_assign(&stack[top], arg);
	++totalActuals;
	avm_dec_top();
}
