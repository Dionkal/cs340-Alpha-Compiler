#ifndef EX_MATH_LIB
	#define EX_MATH_LIB
	#include 	"vmargs.h"
	#include 	"avm.h"

	void execute_add(instruction *i);

	void execute_sub(instruction *i);

	void execute_mul(instruction *i);

	void execute_div(instruction *i);

	void execute_mod(instruction *i);
#endif