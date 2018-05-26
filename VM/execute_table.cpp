#include "execute_table.h"
#include "ex_assign.h"

extern avm_memcell stack[AVM_STACKSIZE];
extern unsigned top;
extern avm_memcell ax;


void execute_newtable(instruction* instr){
	avm_memcell* lv = avm_translate_operand(&instr->vm_result, NULL);
	assert(lv &&(&stack[AVM_STACKSIZE] >= lv && lv > &stack[top]));

	avm_memcellclear(lv);

	lv->type = table_m;
	lv->data.tableVal = avm_tablenew();
	avm_tableincrefcounter(lv->data.tableVal);
}

void execute_tablegetelem(instruction* instr){
	avm_memcell* lv = avm_translate_operand(&instr->result, NULL);
	avm_memcell* t = avm_translate_operand(&instr->arg1, NULL);
	avm_memcell* i = avm_translate_operand(&instr->arg2, &ax);

	assert(lv && &stack[AVM_STACKSIZE-1] >= lv && lv > &stack[top] || lv == &retval);
	assert(t && &stack[AVM_STACKSIZE-1] >= t && > &stack[top]);
	assert(i);

	avm_memcellclear(lv);
	lv->type = nil_m;	//Default value

	if(t->type !=  table_m){
		avm_error("illegal use of type %s, as table!", typeStrings[t->type]);
	}else{
		avm_memcell* content = avm_tablegetelem(t->data.tableVal, i);
		if(content){
			avm_assign(lv, content);
		}else{
			/*TODO complete the rest*/
		}
	}
}