#ifndef EXECUTE_CALL_LIB
	#define EXECUTE_CALL_LIB
	#include "vmargs.h"
	#include "avm.h"
	#include "dispatcher.h"
	void avm_dec_top(void);

	void avm_push_envvalue(unsigned val);

	void execute_call (instruction* instr);

	void execute_funcenter(instruction* instr);

	unsigned avm_get_envvalue(unsigned i);

	void execue_funcexit(instruction* unused);
#endif