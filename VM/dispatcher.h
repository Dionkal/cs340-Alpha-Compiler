#ifndef DISPATCHER_LIB
	#define DISPATCHER_LIB

	#include "vmargs.h"
	#include "ex_assign.h"
	#include "ex_math.h"
	#include "execute_call.h"
	#include "execute_table.h"
	#include "ex_jumps.h"
	#include "execute_nop.h"
	#define AVM_MAX_INSTRUCTIONS nop_vmopcode 	//the max valid opode an isntruction can take
	
	typedef void (*execute_func_t) (instruction*);

	void execute_cycle();

	// typedef void (*execute_func_t) (isntruction*);
#endif