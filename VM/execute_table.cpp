#include "execute_table.h"
#include "ex_assign.h"
#include "toString.h"

extern avm_memcell stack[AVM_STACKSIZE];
extern unsigned top;
extern avm_memcell eax, bx, retval;
extern std::string typeStrings[];
// extern std::string avm_tostring(avm_memcell* m);

void execute_newtable(instruction* instr){
	avm_memcell* lv = avm_translate_operand(&instr->vm_result, NULL);
	assert(lv &&(&stack[AVM_STACKSIZE] >= lv && lv > &stack[top]));

	avm_memcellclear(lv);

	lv->type = table_m;
	lv->data.tableVal = avm_tablenew();
	avm_tableincrefcounter(lv->data.tableVal);
}

void execute_tablegetelem(instruction* instr){
	avm_memcell* lv = avm_translate_operand(&instr->vm_result, NULL);
	avm_memcell* t = avm_translate_operand(&instr->vm_arg1, NULL);
	avm_memcell* i = avm_translate_operand(&instr->vm_arg2, &eax);

	assert((lv && &stack[AVM_STACKSIZE-1] >= lv && lv > &stack[top]) || lv == &retval);
	assert(t && &stack[AVM_STACKSIZE-1] >= t && lv > &stack[top]);
	assert(i);

	avm_memcellclear(lv);
	lv->type = nil_m;	//Default value

	if(t->type !=  table_m){
		avm_error("illegal use of type %s, as table!", typeStrings[t->type]);
	}else{
		avm_memcell content = avm_tablegetelem(t->data.tableVal, i);
		if(content.type != undef_m){
			avm_assign(lv, &content);
		}else{
			std::string ts = avm_tostring(t);
			std::string is = avm_tostring(i);
			 avm_warning("%s[%s] not found!",ts,is);
		}
	}
}

void execute_tablesetelem(instruction* instr){
	avm_memcell* t = avm_translate_operand(&instr->vm_result, NULL);
	avm_memcell* i = avm_translate_operand(&instr->vm_arg1, &eax);
	avm_memcell* c = avm_translate_operand(&instr->vm_arg2, &bx);

	assert(t && &stack[AVM_STACKSIZE-1]>= t && t> &stack[top]);
	assert(i && c);

	if(t->type != table_m){
		 avm_error("illegal use of type %s as table!",typeStrings[t->type]);
	}else{
		avm_tablesetelem(t->data.tableVal,i ,c);
	}
}