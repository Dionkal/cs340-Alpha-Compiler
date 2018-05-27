#ifndef EXECUTE_TABLE_NEW
	#define EXECUTE_TABLE_NEW
	#include "avm.h"
	#include "avm_table.h"
	#include "execute_call.h"

	void execute_newtable(instruction* instr);

	void execute_tablegetelem(instruction* instr);
#endif