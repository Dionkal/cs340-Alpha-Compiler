#include "ex_math.h"

extern bool executionFinished;
extern avm_memcell ax, bx, cx, retval;
extern avm_memcell stack[AVM_STACKSIZE];
/*Stack pointers*/
extern unsigned top, topsp;

typedef double (*arithmetic_func_t)(double x, double y);

double add_impl(double x, double y) { return x + y; }
double sub_impl(double x, double y) { return x - y; }
double mul_impl(double x, double y) { return x * y; }
double div_impl(double x, double y)
{
	assert(y);
	return x / y;
}
double mod_impl(double x, double y) { return (unsigned)x % (unsigned)y; }

/*Dispather for arithmetics*/
arithmetic_func_t arithmeticFuncs[] = {
	add_impl,
	sub_impl,
	mul_impl,
	div_impl,
	mod_impl};

void execute_arithmetic(instruction *i)
{
	avm_memcell *lv = avm_translate_operand(&i->vm_result, (avm_memcell *)0);
	avm_memcell *rv1 = avm_translate_operand(&i->vm_arg1, &ax);
	avm_memcell *rv2 = avm_translate_operand(&i->vm_arg2, &bx);

	assert(((lv && (&stack[AVM_STACKSIZE - 1]) && lv > &stack[top]) || lv == &retval));

	if (rv1->type != number_m || rv2->type != number_m)
	{
		avm_error("Not a number in arithmetic");
		executionFinished = true;
	}
	else
	{
		arithmetic_func_t op = arithmeticFuncs[i->vm_op - add_vmopcode];
		avm_memcellclear(lv);
		lv->type = number_m;
		lv->data.numVal = (*op)(rv1->data.numVal, rv2->data.numVal);
	}
}
