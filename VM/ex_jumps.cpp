#include "ex_jumps.h"

extern avm_memcell eax, bx, cx, retval;
extern avm_memcell stack[AVM_STACKSIZE];
/*Stack pointers*/
extern unsigned top, topsp;

extern bool executionFinished;
extern unsigned pc;

extern std::string typeStrings[];

void execute_jeq(instruction *i)
{
	unsigned char result = 0;

	assert(i->vm_result.type == label_a);

	avm_memcell *rv1 = avm_translate_operand(&i->vm_arg1, &eax);
	avm_memcell *rv2 = avm_translate_operand(&i->vm_arg2, &bx);

	if (rv1->type == undef_m || rv2->type == undef_m)
	{
		//avm_error("'undef' involved in equality");
	}
	else
	{
		if (rv1->type == nil_m || rv2->type == nil_m)
		{
			result = (unsigned char)nil_m;
		}
		else if (rv1->type == bool_m || rv2->type == bool_m)
		{
			result = (unsigned char)bool_m;
		}
		else if (rv1->type != rv2->type)
		{
			//avm_error("%s== %s is illegal",typeStrings[rv1->type],typeString[rv2->type]);
		}
		else
		{
			/*TODO::Equality check with dispatching (rv1)*/
		}
	}

	if (!executionFinished && result)
		pc = i->vm_result.val;
}

void execute_jne(instruction *i) {}

void execute_jle(instruction *i) {}

void execute_jge(instruction *i) {}

void execute_jlt(instruction *i) {}

void execute_jgt(instruction *i) {}
