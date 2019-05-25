#include "ex_jumps.h"
#include <string.h>

extern avm_memcell ax, bx, cx, retval;
extern avm_memcell stack[AVM_STACKSIZE];
/*Stack pointers*/
extern unsigned top, topsp;

extern bool executionFinished;
extern unsigned pc;
extern std::string typeStrings[];

/* Type conversion to bool values */
unsigned char number_tobool(avm_memcell *m) { return m->data.numVal != 0; }
unsigned char string_tobool(avm_memcell *m) { return m->data.strVal[0] != 0; }
unsigned char bool_tobool(avm_memcell *m) { return m->data.boolVal; }
unsigned char table_tobool(avm_memcell *m) { return 1; }
unsigned char userfunc_tobool(avm_memcell *m) { return 1; }
unsigned char libfunc_tobool(avm_memcell *m) { return 1; }
unsigned char nil_tobool(avm_memcell *m) { return 0; }
unsigned char undef_tobool(avm_memcell *m)
{
	assert(0);
	return 0;
}

tobool_func_t toboolFuncs[] = {
	number_tobool,
	string_tobool,
	bool_tobool,
	table_tobool,
	userfunc_tobool,
	libfunc_tobool,
	nil_tobool,
	undef_tobool};

unsigned char avm_tobool(avm_memcell *m)
{
	assert(m->type >= 0 && m->type < undef_m);
	return (*toboolFuncs[m->type])(m);
}

/* Logical operations */
void execute_jeq(instruction *i)
{
	unsigned char result = 0;

	assert(i->vm_result.type == label_a);

	avm_memcell *rv1 = avm_translate_operand(&i->vm_arg1, &ax);
	avm_memcell *rv2 = avm_translate_operand(&i->vm_arg2, &bx);

	if (rv1->type == undef_m || rv2->type == undef_m)
	{
		avm_error("'undef' involved in equality");
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
			avm_error("%s== %s is illegal", typeStrings[rv1->type], typeStrings[rv2->type]);
		}
		else
		{
			/*TODO::Equality check with dispatching (rv1)*/
			switch (rv1->type)
			{
			case number_m:
				result = rv1->data.numVal == rv2->data.numVal;
				break;
			case string_m:
				result = !strcmp(rv1->data.strVal, rv2->data.strVal);
				break;
			case table_m:
				result = rv1->data.tableVal == rv2->data.tableVal;
				break;
			case userfunc_m:
				result = rv1->data.funcVal == rv2->data.funcVal;
				break;
			case libfunc_m:
				result = rv1->data.libfuncVal == rv2->data.libfuncVal;
				break;
			default:
				assert(0);
			}
		}
	}

	if (!executionFinished && result)
		pc = i->vm_result.val;
}

void execute_jne(instruction *i)
{
	unsigned char result = 0;

	assert(i->vm_result.type == label_a);

	avm_memcell *rv1 = avm_translate_operand(&i->vm_arg1, &ax);
	avm_memcell *rv2 = avm_translate_operand(&i->vm_arg2, &bx);

	if (rv1->type == undef_m || rv2->type == undef_m)
	{
		avm_error("'undef' involved in non equal");
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
			avm_error("%s== %s is illegal", typeStrings[rv1->type], typeStrings[rv2->type]);
		}
		else
		{
			switch (rv1->type)
			{
			case number_m:
				result = rv1->data.numVal != rv2->data.numVal;
				break;
			case string_m:
				result = strcmp(rv1->data.strVal, rv2->data.strVal);
				break;
			case table_m:
				result = rv1->data.tableVal != rv2->data.tableVal;
				break;
			case userfunc_m:
				result = rv1->data.funcVal != rv2->data.funcVal;
				break;
			case libfunc_m:
				result = rv1->data.libfuncVal != rv2->data.libfuncVal;
				break;
			default:
				assert(0);
			}
		}
	}

	if (!executionFinished && result)
		pc = i->vm_result.val;
}

void execute_jle(instruction *i)
{
	unsigned char result = 0;

	assert(i->vm_result.type == label_a);

	avm_memcell *rv1 = avm_translate_operand(&i->vm_arg1, &ax);
	avm_memcell *rv2 = avm_translate_operand(&i->vm_arg2, &bx);

	if (rv1->type == undef_m || rv2->type == undef_m)
	{
		avm_error("'undef' involved in less equal");
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
			avm_error("%s== %s is illegal", typeStrings[rv1->type], typeStrings[rv2->type]);
		}
		else
		{
			switch (rv1->type)
			{
			case number_m:
				result = rv1->data.numVal <= rv2->data.numVal;
				break;
			case string_m:
				result = (strcmp(rv1->data.strVal, rv2->data.strVal) <= 0);
				break;
			case table_m:
				result = rv1->data.tableVal <= rv2->data.tableVal;
				break;
			case userfunc_m:
				result = rv1->data.funcVal <= rv2->data.funcVal;
				break;
			case libfunc_m:
				result = rv1->data.libfuncVal <= rv2->data.libfuncVal;
				break;
			default:
				assert(0);
			}
		}
	}

	if (!executionFinished && result)
		pc = i->vm_result.val;
}

void execute_jge(instruction *i)
{
	unsigned char result = 0;

	assert(i->vm_result.type == label_a);

	avm_memcell *rv1 = avm_translate_operand(&i->vm_arg1, &ax);
	avm_memcell *rv2 = avm_translate_operand(&i->vm_arg2, &bx);

	if (rv1->type == undef_m || rv2->type == undef_m)
	{
		avm_error("'undef' involved in greater equal");
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
			avm_error("%s== %s is illegal", typeStrings[rv1->type], typeStrings[rv2->type]);
		}
		else
		{
			switch (rv1->type)
			{
			case number_m:
				result = rv1->data.numVal >= rv2->data.numVal;
				break;
			case string_m:
				result = (strcmp(rv1->data.strVal, rv2->data.strVal) >= 0);
				break;
			case table_m:
				result = rv1->data.tableVal >= rv2->data.tableVal;
				break;
			case userfunc_m:
				result = rv1->data.funcVal >= rv2->data.funcVal;
				break;
			case libfunc_m:
				result = rv1->data.libfuncVal >= rv2->data.libfuncVal;
				break;
			default:
				assert(0);
			}
		}
	}

	if (!executionFinished && result)
		pc = i->vm_result.val;
}

void execute_jlt(instruction *i)
{
	unsigned char result = 0;

	assert(i->vm_result.type == label_a);

	avm_memcell *rv1 = avm_translate_operand(&i->vm_arg1, &ax);
	avm_memcell *rv2 = avm_translate_operand(&i->vm_arg2, &bx);

	if (rv1->type == undef_m || rv2->type == undef_m)
	{
		avm_error("'undef' involved in less than equal");
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
			avm_error("%s== %s is illegal", typeStrings[rv1->type], typeStrings[rv2->type]);
		}
		else
		{
			switch (rv1->type)
			{
			case number_m:
				result = rv1->data.numVal < rv2->data.numVal;
				break;
			case string_m:
				result = (strcmp(rv1->data.strVal, rv2->data.strVal) < 0);
				break;
			case table_m:
				result = rv1->data.tableVal < rv2->data.tableVal;
				break;
			case userfunc_m:
				result = rv1->data.funcVal < rv2->data.funcVal;
				break;
			case libfunc_m:
				result = rv1->data.libfuncVal < rv2->data.libfuncVal;
				break;
			default:
				assert(0);
			}
		}
	}

	if (!executionFinished && result)
		pc = i->vm_result.val;
}

void execute_jgt(instruction *i)
{
	unsigned char result = 0;

	assert(i->vm_result.type == label_a);

	avm_memcell *rv1 = avm_translate_operand(&i->vm_arg1, &ax);
	avm_memcell *rv2 = avm_translate_operand(&i->vm_arg2, &bx);

	if (rv1->type == undef_m || rv2->type == undef_m)
	{
		avm_error("'undef' involved in greater than equal");
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
			avm_error("%s== %s is illegal", typeStrings[rv1->type], typeStrings[rv2->type]);
		}
		else
		{
			switch (rv1->type)
			{
			case number_m:
				result = rv1->data.numVal > rv2->data.numVal;
				break;
			case string_m:
				result = (strcmp(rv1->data.strVal, rv2->data.strVal) > 0);
				break;
			case table_m:
				result = rv1->data.tableVal > rv2->data.tableVal;
				break;
			case userfunc_m:
				result = rv1->data.funcVal > rv2->data.funcVal;
				break;
			case libfunc_m:
				result = rv1->data.libfuncVal > rv2->data.libfuncVal;
				break;
			default:
				assert(0);
			}
		}
	}

	if (!executionFinished && result)
		pc = i->vm_result.val;
}

void execute_jump(instruction *i)
{
	pc = i->vm_result.val;
}
