#ifndef EXECUTE_CALL_LIB
	#define EXECUTE_CALL_LIB
	
	#define AVM_NUMACTUALS_OFFSET 	4
	#define AVM_SAVEDTOP_OFFSET 	2
	#define AVM_SAVED_PC_OFFSET 	3
	#define AVM_SAVEDTOPSP_OFFSET	1

	#include <algorithm>
	#include "vmargs.h"
	#include "avm.h"
	#include "dispatcher.h"
	#include "ex_assign.h"
	void avm_dec_top(void);

	void avm_push_envvalue(unsigned val);

	void execute_call (instruction* instr);

	void execute_funcenter(instruction* instr);

	unsigned avm_get_envvalue(unsigned i);

	void execute_funcexit(instruction* unused);

	void avm_calllibfunc(char* id);

	unsigned avm_totalactuals (void);

	avm_memcell* avm_getactual(unsigned i);

	void libfunc_print(void);

	user_func_array_entry* avm_getfuncinfo(unsigned address);

	std::string avm_getlibraryfunc(std::string id);
#endif