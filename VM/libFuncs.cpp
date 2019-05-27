#include "libFuncs.h"
#include "string.h"
#include <math.h>

extern avm_memcell retval;
extern unsigned top, topsp;
extern std::string typeStrings[];
extern bool executionFinished;

/*
	Implementation of the library function 'print'.
	It displays every argument at the console.
 */
void libfunc_print(void)
{
	unsigned n = avm_totalactuals();
	for (unsigned i = 0; i < n; ++i)
	{
		std::string str = avm_tostring(avm_getactual(i));
		puts(str.c_str());
	}
}

void libfunc_typeof(void)
{
	unsigned n = avm_totalactuals();

	if (n != 1)
		avm_error("Too many a arguments %d in 'typeof' expected 1.", n);
	else
	{
		/*
			That's how a library function returns a result.
			It has to only set the 'retval' register!
		*/

		avm_memcellclear(&retval);
		retval.type = string_m;
		retval.data.strVal = strdup(typeStrings[avm_getactual(0)->type].c_str());
	}
}

void libfunc_totalarguments(void)
{
	// Get topsp of previous activation record.
	unsigned p_topsp = avm_get_envvalue(topsp + AVM_SAVEDTOPSP_OFFSET);
	avm_memcellclear(&retval);

	if (!p_topsp)
	{ // If 0, no previous activation record.
		retval.type = number_m;
		retval.data.numVal = avm_get_envvalue(p_topsp + AVM_NUMACTUALS_OFFSET);
	}
}

void libfunc_argument()
{
	unsigned n = avm_totalactuals();
	if (n != 1)
		avm_error("Too many a arguments %d in 'argument' expected 1.", n);
	else
	{
		avm_memcellclear(&retval);
		retval.type = avm_getactual(0)->type;
		if (typeStrings[retval.type] == "number_m")
			retval.data.numVal = avm_getactual(0)->data.numVal;
		else if (typeStrings[retval.type] == "string_m")
			retval.data.strVal = strdup(avm_getactual(0)->data.strVal);
		else if (typeStrings[retval.type] == "bool_m")
			retval.data.boolVal = avm_getactual(0)->data.boolVal;
		else if (typeStrings[retval.type] == "table_m")
		{
			retval.data.tableVal = avm_getactual(0)->data.tableVal;
			avm_tableincrefcounter(retval.data.tableVal);
		}
		else if (typeStrings[retval.type] == "userfunc_m")
			retval.data.funcVal = avm_getactual(0)->data.funcVal;
		else if (typeStrings[retval.type] == "libfunc_m")
			retval.data.libfuncVal = avm_getactual(0)->data.libfuncVal;
		else if (typeStrings[retval.type] == "libfunc_m")
			retval.data.libfuncVal = avm_getactual(0)->data.libfuncVal;
	}
}

void libfunc_sqrt()
{
	unsigned n = avm_totalactuals();
	if (n != 1)
		avm_error("Too many a arguments %d in 'sqrt' expected 1.", n);
	else
	{
		if (avm_getactual(0)->type != number_m || avm_getactual(0)->data.numVal < 0)
		{
			retval.type = nil_m;
			return;
		}

		retval.type = number_m;
		retval.data.numVal = sqrt(avm_getactual(0)->data.numVal);
	}
}

void libfunc_sin()
{
	unsigned n = avm_totalactuals();
	if (n != 1)
		avm_error("Too many a arguments %d in 'sin' expected 1.", n);
	else
	{
		if (avm_getactual(0)->type != number_m)
		{
			retval.type = nil_m;
			return;
		}

		retval.type = number_m;
		retval.data.numVal = sin(avm_getactual(0)->data.numVal);
	}
}

void libfunc_cos()
{
	unsigned n = avm_totalactuals();
	if (n != 1)
		avm_error("Too many a arguments %d in 'cos' expected 1.", n);
	else
	{
		if (avm_getactual(0)->type != number_m)
		{
			retval.type = nil_m;
			return;
		}

		retval.type = number_m;
		retval.data.numVal = cos(avm_getactual(0)->data.numVal);
	}
}
