#include "generateInstrFunc.h"
#include "vmargs.h"
#include <vector>
#include <stack>

#define VM_FALSE 0
#define VM_TRUE	 1


/*Global vector of instructions*/
extern std::vector<instruction> vctr_instr;

void generate_ADD(quad* q){
	generate(add_iopcode,*q);
}


void generate_SUB(quad* q){
	generate(sub_iopcode,*q);	
}

void generate_MUL(quad* q){
	generate(mul_iopcode,*q);
}

void generate_DIV(quad* q){
	generate(div_iopcode, *q);
}

void generate_MOD(quad* q){
	generate(mod_iopcode, *q);
}

void generate_NEWTABLE(quad* q){
	generate(tablecreate_iopcode, *q);
}

void generate_TABLEGETELEM(quad* q){
	generate(tablegetelem_iopcode, *q);
}

void generate_TABLESETELEM(quad* q){
	generate(tablesetelem_iopcode, *q);
}

void generate_ASSIGN(quad* q){
	generate(assign_iopcode, *q);
}

void generate_NOP(quad* q){
	instruction *t = new instruction();
	t->vm_op = invalid_vmopcode;
	vctr_instr.push_back(*t);
}

void generate_JUMP(quad* q){
	generate_relational(jump_iopcode, *q);
}

void generate_IF_EQ(quad* q){
	generate_relational(if_eq_iopcode, *q);
}

void generate_IF_NOTEQ(quad* q){
	generate_relational(if_noteq_iopcode, *q);
}
 	
void generate_IF_GREATER(quad* q){
	generate_relational(if_greater_iopcode, *q);
}
 	
void generate_IF_GREATEREQ(quad* q ){
	generate_relational(if_greatereq_iopcode, *q);
}
 	
void generate_IF_LESS(quad* q){
	generate_relational(if_less_iopcode, *q);
}
 	
void generate_IF_LESSEQ(quad* q){
	generate_relational(if_lesseq_iopcode, *q);
}
 	
void generate_NOT(quad* q){
	q->taddress = next_instruction_label();
	instruction newInst;

	/*Generate 1st instruction*/	
	newInst.vm_op = if_eq_vmopcode;
	make_operand(q->arg1, &(newInst.vm_arg1));
	make_booloperand(&(newInst.vm_arg2), VM_FALSE);
	newInst.vm_result.type = label_a;
	newInst.vm_result.val = next_instruction_label() + 3;
	vctr_instr.push_back(newInst);

	/*Generate 2nd instruction*/
	newInst.vm_op = assign_vmopcode;
	make_booloperand(&(newInst.vm_arg1), VM_FALSE);
	reset_operand(&newInst.vm_arg2);
	make_operand(q->result, &newInst.vm_result);
	vctr_instr.push_back(newInst);

	/*Generate 3rd instruction*/
	newInst.vm_op = jump_vmopcode;
	reset_operand(&newInst.vm_arg1);
	reset_operand(&newInst.vm_arg2);
	newInst.vm_result.type = label_a;
	newInst.vm_result.val = next_instruction_label() + 2;
	vctr_instr.push_back(newInst);

	/*Generate 4th instruction*/
	newInst.vm_op = assign_vmopcode;
	make_booloperand(&newInst.vm_arg1, VM_TRUE);
	reset_operand(&newInst.vm_arg2);
	make_operand(q->result, &newInst.vm_result);
	vctr_instr.push_back(newInst);
}
 	
void generate_OR(quad* q){
	q->taddress = next_instruction_label();
	instruction newInst;

	unsigned bool1,bool2;


	/*Parametrize AND OR*/
	if(q->op == or_iopcode){
		bool1 = VM_TRUE;
		bool2 = VM_FALSE;
	}else if (q->op == and_iopcode){
		bool1 = VM_FALSE;
		bool2 = VM_TRUE;
	}else{
		/*invalid iopcode*/
		assert(false);
	}

	/*Generate 1st instruction*/
	newInst.vm_op = if_eq_vmopcode;
	make_operand(q->arg1, &newInst.vm_arg1);
	make_booloperand(&newInst.vm_arg2, bool1);
	newInst.vm_result.type = label_a;
	newInst.vm_result.val = next_instruction_label() + 4;
	vctr_instr.push_back(newInst);

	/*Generate 2nd instruction*/
	make_operand(q->arg2, &newInst.vm_arg1);
	newInst.vm_result.val= next_instruction_label() + 3;
	vctr_instr.push_back(newInst);

	/*Generate 3rd instruction*/
	newInst.vm_op = assign_vmopcode;
	make_booloperand(&newInst.vm_arg1, bool2);
	reset_operand(&newInst.vm_arg2);
	make_operand(q->result, &newInst.vm_result);
	vctr_instr.push_back(newInst);
 
	/*Generate 4th instruction*/
	newInst.vm_op = jump_vmopcode;
	reset_operand(&newInst.vm_arg1);
	reset_operand(&newInst.vm_arg2);
	newInst.vm_result.type = label_a;
	newInst.vm_result.val = next_instruction_label() + 2;
	vctr_instr.push_back(newInst);

	/*Generate 5th instruction*/
	newInst.vm_op = assign_vmopcode;
	make_booloperand(&newInst.vm_arg1, bool1);
	reset_operand(&newInst.vm_arg2);
	make_operand(q->result, &newInst.vm_result);
	vctr_instr.push_back(newInst);
}
 	
void generate_PARAM(quad* q){
	q->taddress = next_instruction_label();
	instruction newInst;
	newInst.vm_op = param_vmopcode;
	make_operand(q->arg1, &newInst.vm_arg1);
	vctr_instr.push_back(newInst);
}

void generate_CALL(quad *q){
	q->taddress = next_instruction_label();
	instruction newInst;
	newInst.vm_op = call_vmopcode;
	make_operand(q->arg1, &newInst.vm_arg1);
	vctr_instr.push_back(newInst);
}

void generate_GETRETVAL(quad *q){
	q->taddress = next_instruction_label();
	instruction newInst;
	newInst.vm_op = assign_vmopcode;
	make_operand(q->result, &newInst.vm_result);
	make_retvaloperand( &newInst.vm_arg1);
}

void generate_FUNCSTART(quad *q){
	q->taddress = next_instruction_label();

	instruction newInst;
	newInst.vm_op = funcstart_vmopcode;
	make_operand(q->result, &newInst.vm_result);
	vctr_instr.push_back(newInst);
}

void generate_RETURN(quad *q){
	q->taddress = next_instruction_label();
	instruction newInst;

	newInst.vm_op = assign_vmopcode;
	make_retvaloperand(&newInst.vm_result);
	make_operand(q->arg1, &newInst.vm_arg1);
	vctr_instr.push_back(newInst);
}

void generate_FUNCEND(quad *q){
	q->taddress = next_instruction_label();
	instruction newInst;
	newInst.vm_op = funcend_vmopcode;
	make_operand(q->result, &newInst.vm_result);
	vctr_instr.push_back(newInst);
}