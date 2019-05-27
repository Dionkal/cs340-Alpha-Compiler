#include "execute_call.h"
#include "toString.h"
#include <map>

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
extern std::map<std::string, library_func_t> libFuncHash;

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

	while (oldTop++ <= top)
	{
		avm_memcellclear(&stack[oldTop]);
	}
}

void execute_pusharg(instruction *instr)
{
	avm_memcell *arg = avm_translate_operand(&instr->vm_result, &ax);
	assert(arg);
	/*
		This is actually stack[top] = arg, but we have to
		use avm_assign.
	 */
	avm_assign(&stack[top], arg);
	++totalActuals;
	avm_dec_top();
}

void avm_dec_top(void)
{
	if (!top)
	{ //stack overflow (not the site)
		avm_error("stack overflow");
		executionFinished = 1;
	}
	else
	{
		--top;
	}
}

void avm_push_envvalue(unsigned val)
{
	stack[top].type = number_m;
	stack[top].data.numVal = val;
	avm_dec_top();
}

unsigned totalActuals = 0;

void avm_callsaveenvironment(void)
{
	avm_push_envvalue(totalActuals);
	avm_push_envvalue(pc + 1);
	avm_push_envvalue(top + totalActuals + 2);
	avm_push_envvalue(topsp);
}

unsigned avm_get_envvalue(unsigned i)
{
	assert(stack[i].type == number_m);
	unsigned val = (unsigned)stack[i].data.numVal;
	assert(stack[i].data.numVal == ((double)val));
	return val;
}

void avm_calllibfunc(char *id)
{
	library_func_t f = avm_getlibraryfunc(id);
	if (!f)
	{
		avm_error("unsupported lib func %s called!", id);
		executionFinished = 1;
	}
	else
	{
		topsp = top;
		totalActuals = 0;
		(*f)(); // call the lib function
		if (!executionFinished)
		{ //execute func exit only if there are no errors
			execute_funcexit(NULL);
		}
	}
}

unsigned avm_totalactuals(void)
{
	return avm_get_envvalue(topsp + AVM_NUMACTUALS_OFFSET);
}

avm_memcell *avm_getactual(unsigned i)
{
	assert(i < avm_totalactuals());
	return &stack[topsp + AVM_STACKENV_SIZE + 1 + i];
}

library_func_t avm_getlibraryfunc(std::string id)
{
	std::map<std::string, library_func_t>::iterator it;
	it = libFuncHash.find(id);
	if (it == libFuncHash.end()) //Lib func not found
	{
		return NULL;
	}
	else
	{
		return it->second;
	}
}

/*
	With the following every library function is manually
	added in the VM library function resolution map.
*/
void avm_registerlibfunc(std::string id, library_func_t addr)
{
	libFuncHash[id] = addr;
}

user_func_array_entry *avm_getfuncinfo(unsigned address)
{
	assert(vctr_instr[address].vm_result.type == userfunc_a); //only functions are permited
	return &user_func_array[vctr_instr[address].vm_result.val];
}
