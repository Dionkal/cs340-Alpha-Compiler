#include "ex_assign.h"
#include <assert.h>
#include <cstring>
#include "avm_table.h"

extern avm_memcell ax,retval;
extern unsigned top;
extern avm_memcell stack[AVM_STACKSIZE];


void avm_assign(avm_memcell* lv, avm_memcell* rv){
	if(lv==rv) return;

	if((lv->type == table_m) && (rv->type == table_m) && (lv->data.tableVal == rv->data.tableVal)) return;

	if(rv->type == undef_m) //throw warning 
		return;


	// avm_memsellclear(lv);

	/*TODO: monitor this for possible segmentations*/
	//memcpy(lv, rv, sizeof(avm_memcell)); //dispath instead in cpp

	if (lv->type == string_m){
		lv->data.strVal = strdup(rv->data.strVal);
	}
	else if (lv->type == table_m){
		avm_tableincrefcounter(lv->data.tableVal);
	}

}
void execute_assign (instruction * instr){
	avm_memcell* lv = avm_translate_operand(&instr->vm_result, (avm_memcell*)0);
	avm_memcell* rv = avm_translate_operand(&instr->vm_arg1, &ax);

	assert((lv && ((&stack[AVM_STACKSIZE-1] >= lv) && (lv > &stack[top]))) || lv==&retval);
	assert(rv);

	avm_assign(lv,rv); 
}