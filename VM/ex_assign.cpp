#include "ex_assign.h"
#include <assert.h>
#include <cstring>
#include "avm_table.h"

extern avm_memcell ax, retval;
extern unsigned top;
extern avm_memcell stack[AVM_STACKSIZE];

void avm_assign(avm_memcell *lv, avm_memcell *rv)
{
	if (lv == rv)
		return;

	if ((lv->type == table_m) && (rv->type == table_m) && (lv->data.tableVal == rv->data.tableVal))
		return;

	if (rv->type == undef_m) //TODO: throw warning
		return;

	// avm_memcellclear(lv);

	memcpy(lv, rv, sizeof(avm_memcell));

	if (lv->type == string_m)
	{
		lv->data.strVal = strdup(rv->data.strVal);
	}
	else if (lv->type == table_m)
	{
		avm_tableincrefcounter(lv->data.tableVal);
	}
}
void execute_assign(instruction *instr)
{
	avm_memcell *lv = avm_translate_operand(&instr->vm_result, (avm_memcell *)0);
	avm_memcell *rv = avm_translate_operand(&instr->vm_arg1, &ax);

	assert(lv && ((&stack[AVM_STACKSIZE - 1] >= lv && lv > &stack[top]) || lv == &retval));
	assert(rv); // TODO: Similar assertion test as above

	avm_assign(lv, rv);
}
