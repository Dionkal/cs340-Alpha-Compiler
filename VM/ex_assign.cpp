#include "ex_assign.h"


void avm_assign(avm_memcell* lv, avm_memcell* rv){
	if(lv==rv) return;

	if((lv->type == table_m) && (rv->type == table_m) && (lv->data.tableVar == rv->data.tableVar)) return;

	if(rv->tpe == undef_m) //throw warning 
		return;

	avm_memsellclear(lv);

	memcpy(lv, rv, sizeof(avm_memsell)); //dispath instead in cpp

	if (lv->type == string_m)
		lv->data.strVal = strdup(rv->data.strVal);
	else if (lv->type == table_m)
		avm_tableincrefcounter(lv->data.tableVar);

}
void execute_assign (instruction * instr){
	avm_memsell* lv = avm_translate_operand(&instr->result, (avm_memsell*)0);
	avm_memsell* rv = avm_translate_operand(&instr->arg1, &ax);

	assert((lv && ((&stack[AVM_STACKSIZE-1] >= lv) && (lv > &stack[top]))) || lv==&retval);
	assert(rv);

	avm_assign(lv,rv); 
}