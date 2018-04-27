#include "scanner.h"


/*Enumerator that contains all the available instructions of alpha*/
typedef enum iopcode{
	assign_iopcode,
	add_iopcode,
	sub_iopcode,
	mul_iopcode,
	div_iopcode,
	mod_iopcode,
	uminus_iopcode,
	and_iopcode,
	or_iopcode,
	not_iopcode,
	if_eq_iopcode,
	if_noteq_iopcode,
	if_lesseq_iopcode,
	if_greatereq_iopcode,
	if_less_iopcode,
	if_greater_iopcode,
	call_iopcode,param_iopcode,
	ret_iopcode,getretval_iopcode,
	funcstart_iopcode,
	funcend_iopcode,
	tablecreate_iopcode,
	tablegetelem_iopcode,
	tablesetelem_iopcode
}iopcode;

/*Enumerator that defines all the differnet types of expressions*/
typedef enum expr_t{
	var_e, 
	tableitem_e,
	programfunc_e,
	libraryfunc_e,
	arithexpr_e,
	boolexpr_e,
	assignexpr_e,
	newtable_e,
	costnum_e,
	constbool_e,
	conststring_e,
	nil_e
}expr_t;


typedef struct expr{
	expr_t 			type;
	symTableEntry* 	sym;
	expr* 			index;
	double 			numConst;
	char* 			strConst;
	unsigned char	boolConst;
	expr* 			next;
}expr;

typedef struct quad{
	iopcode 	op;
	expr* 		result;
	expr* 		arg1;
	expr* 		arg2;
	unsigned	label;
	unsigned 	line;
}quad;

/*Index of the last recognised quad*/
unsigned int currQuad;

/*Creates a new quad and initializes it with the arguments. Then it stores it in the vector*/
void emit(iopcode opCode,expr *_arg1,expr *_arg2,expr *_res,unsigned _label,int yylineno);

/*Prints all the recognized quads from the vector*/
void printQuads();