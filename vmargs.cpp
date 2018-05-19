#include "vmargs.h"

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
			arg->val=e->sym->taddress;
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

/*oi seira ston pinaka einai idia me ta icodes*/

typedef void (*generator_func_t)(quad *);//dunno what this does, i mean the typedef

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

void generate (void){
	unsigned i;
	for(i=0; i<total; ++i){
		(*generators[vctr_quads[i].op])(vctr_quads+i);
	}
}
