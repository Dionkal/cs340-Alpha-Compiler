#include "vmargs.h"
#include <vector>
#include "generateInstrFunc.h"

extern std::vector  <quad> vctr_quads; 
static  unsigned currprocessedquad = 0;

/*Global vector of instructions*/
std::vector<instruction> vctr_instr;

/*Data storage of all incomplete jump instructions and their respective quads*/
std::vector<incomplete_jump> inc_jump_list;

/*Const values Data storage*/
std::vector <std::string> 				const_string_array;
std::vector <double> 					const_num_array;
std::vector <std::string> 				lib_func_used_array;
std::vector <user_func_array_entry>		user_func_array;

unsigned next_instruction_label(){
	return vctr_instr.size();
}


unsigned consts_newstring(std::string str){
	const_string_array.push_back(str);
	return const_string_array.size() - 1;
}

unsigned consts_newnumber(double numconst){
	const_num_array.push_back(numconst);
	return const_num_array.size() - 1;
}

unsigned libfuncs_newused(std::string str){
	lib_func_used_array.push_back(str);
	return lib_func_used_array.size() - 1;	
}

void make_operand(expr * e, vmarg* arg){
	switch(e->type){
		/*All those below use a variable for storage*/
		case var_e:
		case tableitem_e:
		case arithexpr_e:
		case boolexpr_e:
		case newtable_e: {

			arg->val=e->sym->offset;

			switch(e->sym->space){
				case programvar: 	arg->type=global_a; break;
				case functionlocal: arg->type=local_a; break;
				case formalarg:		arg->type=formal_a; break;
				default:			assert(0);
			}
			break;
		}
		case constbool_e:	{
			arg->val=e->boolConst;
			arg->type=bool_a; break;
		}
		case conststring_e: {
			arg->val=consts_newstring(e->strConst);
			arg->type=string_a; break;
		}

		case constnum_e: {
			arg->val=consts_newnumber(e->numConst);
			arg->type=number_a; break;	
		}

		case nil_e: {
			arg->type=nil_a; break;
		}

		/*Functions*/
		case programfunc_e:{
			arg->type=userfunc_a;
			arg->val=e->sym->address;
			break;
		}

		case libraryfunc_e: {
			arg->type=libfunc_a;
			arg->val=libfuncs_newused(e->sym->name);
			break;
		}

		default: assert(0);
	}
}

void make_numberoperand(vmarg* arg, double val){
	arg->val = consts_newnumber(val);
	arg->type = number_a;
}

void make_booloperand(vmarg* arg, unsigned val){
	arg->val = val;
	arg->type = bool_a;
}

void make_retvaloperand(vmarg* arg){
	arg->type = retval_a;
}

void reset_operand(vmarg* arg){
	arg->val = -1; 
	arg->type = invalid_a;
}

int iopcodeToVmopcode(iopcode op){

	assert(op > 26); /*check out of bounds enum*/

	if( op == 6){
		return 3;
	}else if (op == 7){
		return 8;
	}else{
		return (int) op;
	}
}

void add_incomplete_jump (unsigned instrNo, unsigned iaddress){
	incomplete_jump* ij = new incomplete_jump();
	ij->instrNo = instrNo;
	ij->iaddress = iaddress;

	inc_jump_list.push_back(*ij);	
}


typedef void (*generator_func_t)(quad *);

generator_func_t generators[]={
	generate_ADD,
	generate_SUB,
	generate_MUL,
	generate_DIV,
	generate_MOD,
	generate_NEWTABLE,
	generate_TABLEGETELEM,
	generate_TABLESETELEM,
	generate_ASSIGN,
	generate_NOP,
	generate_JUMP,
	generate_IF_EQ,
	generate_IF_NOTEQ,
	generate_IF_GREATER,
	generate_IF_GREATEREQ,
	generate_IF_LESS,
	generate_IF_LESSEQ,
	generate_NOT,
	generate_OR,
	generate_PARAM,
	generate_CALL,
	generate_GETRETVAL,
	generate_FUNCSTART,
	generate_RETURN,
	generate_FUNCEND
};

void generate(iopcode op, quad q){
	instruction *newInst = new instruction();

	newInst->vm_op = (vmopcode) iopcodeToVmopcode(q.op);

	make_operand(q.arg1 , &(newInst->vm_arg1) );
	make_operand(q.arg2 , &(newInst->vm_arg2) );
	make_operand(q.result , &(newInst->vm_result) );
	newInst->vm_srcLine = q.line;

	vctr_instr.push_back(*newInst);
}


void generate_relational(iopcode op, quad q){
	instruction *newInst = new instruction();
	newInst->vm_op = (vmopcode) iopcodeToVmopcode(op); 

	make_operand(q.arg1, &(newInst->vm_arg1));
	make_operand(q.arg2, &(newInst->vm_arg2));

	newInst->vm_result.type = label_a;

	if(q.label < currprocessedquad){
		newInst->vm_result.val = vctr_quads[q.label].taddress;
	}else{
		add_incomplete_jump (next_instruction_label(),q.label);
	}

	q.taddress = next_instruction_label();
	vctr_instr.push_back(*newInst);
}

void generate_NOT(quad q){
	
}

void generate_func (void){

	for(unsigned currprocessedquad = 0; currprocessedquad < vctr_quads.size(); ++currprocessedquad){
		(*generators[vctr_quads[currprocessedquad].op])(&(vctr_quads[currprocessedquad]));
	}
}