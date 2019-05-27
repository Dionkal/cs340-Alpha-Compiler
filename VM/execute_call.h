#ifndef EXECUTE_CALL_LIB
#define EXECUTE_CALL_LIB

#define AVM_NUMACTUALS_OFFSET 4
#define AVM_SAVEDTOP_OFFSET 2
#define AVM_SAVED_PC_OFFSET 3
#define AVM_SAVEDTOPSP_OFFSET 1

#include <algorithm>
#include "avm.h"
#include "ex_assign.h"

void execute_call(instruction *instr);

void execute_funcenter(instruction *instr);

void execute_funcexit(instruction *unused);

void avm_calllibfunc(char *id);

void libfunc_print(void);

void execute_pusharg(instruction *instr);

typedef void (*library_func_t)(void);

void avm_dec_top(void);

void avm_push_envvalue(unsigned val);

void avm_callsaveenvironment(void);

unsigned avm_get_envvalue(unsigned i);

void avm_calllibfunc(char *id);

unsigned avm_totalactuals(void);

avm_memcell *avm_getactual(unsigned i);

library_func_t avm_getlibraryfunc(std::string id);

/*
	With the following every library function is manually
	added in the VM library function resolution map.
*/
void avm_registerlibfunc(std::string id, library_func_t addr);

user_func_array_entry *avm_getfuncinfo(unsigned address);
#endif
