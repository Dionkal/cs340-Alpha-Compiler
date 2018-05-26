#ifndef DISPATCHER_LIB
	#define DISPATCHER_LIB
	
	// #include "exfunc.h"
	#include "vmargs.h"
	#define AVM_MAX_INSTRUCTIONS nop_vmopcode 	//the max valid opode an isntruction can take

	void execute_cycle();

	// typedef void (*execute_func_t) (isntruction*);
#endif