#include "vmargs.h"
#include <vector>

/*Global vector of instructions*/
std::vector<instruction> vctr_instr;

extern std::vector  <quad> vctr_quads; 
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

void generate_func (void){

	for(unsigned i=0; i < vctr_quads.size(); ++i){
		(*generators[vctr_quads[i].op])(&(vctr_quads[i]));
	}
}