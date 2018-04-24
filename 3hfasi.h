#include "symtable.h"

typedef enum iopcode{
	assign_iopcode,add_iopcode,sub_iopcode,
	mul_iopcode,div_iopcode,mod_iopcode,
	uminus_iopcode,and_iopcode,or_iopcode,
	not_iopcode,if_eq_iopcode,if_noteq_iopcode,
	if_lesseq_iopcode,if_greatereq_iopcode,if_less_iopcode,
	if_greater_iopcode,call_iopcode,param_iopcode,
	ret_iopcode,getretval_iopcode,funcstart_iopcode,
	funcend_iopcode,tablecreate_iopcode,tablegetelem_iopcode,
	tablesetelem_iopcode
}iopcode;

typedef enum expr_t{
	var_e, tableitem_e, programfunc_e, libraryfunc_e,
	arithexpr_e,boolexpr_e,assignexpr_e,
	newtable_e,costnum_e,constbool_e,conststring_e,nil_e
}expr_t;


struct expr{
	expr_t 			type;
	symTableEntry* 	sym;
	expr* 			index;
	double 			numConst;
	char* 			strConst;
	unsigned char	boolConst;
	expr* 			next;
};

typedef struct quad{
	iopcode 	op;
	expr* 		result;
	expr* 		arg1;
	expr* 		arg2;
	unsigned	label;
	unsigned 	line;
}quad;

/*Creates the quad*/
quad* createQuad(iopcode opCode,expr *_arg1,expr *_arg2,expr *_res,unsigned _label,int yylineno);

/*Adds the created quad to the quad vector*/
void addQuad(quad created);

/*Adds the created quad to the quad vector*/
void emit(expr *_arg1,expr *_arg2,expr *_res);

/*aporia: offset tha kratame px kai gia to f().a? auto theoreitai metavliti?
*/

/*insert*/
scopespace_t currScopeSpace(void);

/*insert*/
void inCurrScopeOffset(void);

/*decreases the scopeSpaceCounter var*/
void enterScopeSpace();

/*decreases the scopeSpaceCounter var, only if it is called 2 times previously*/
void exitScopeSpace();

/*insert */
unsigned currScopeOffset(void);

