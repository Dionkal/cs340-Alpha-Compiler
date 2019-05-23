#ifndef EXECUTE_CALL_LIB
#define EXECUTE_CALL_LIB

#define AVM_NUMACTUALS_OFFSET 4
#define AVM_SAVEDTOP_OFFSET 2
#define AVM_SAVED_PC_OFFSET 3
#define AVM_SAVEDTOPSP_OFFSET 1

#include <algorithm>
#include "vmargs.h"
#include "avm.h"
#include "dispatcher.h"
#include "ex_assign.h"

void execute_call(instruction *instr);

void execute_funcenter(instruction *instr);

void execute_funcexit(instruction *unused);

void avm_calllibfunc(char *id);

void libfunc_print(void);

void execute_pusharg(instruction *instr);

#endif
