#ifndef EX_MATH_LIB
#define EX_MATH_LIB
#include "vmargs.h"
#include "avm.h"

#define execute_add execute_arithmetic
#define execute_sub execute_arithmetic
#define execute_mul execute_arithmetic
#define execute_div execute_arithmetic
#define execute_mod execute_arithmetic

void execute_add(instruction *i);

void execute_sub(instruction *i);

void execute_mul(instruction *i);

void execute_div(instruction *i);

void execute_mod(instruction *i);
#endif
