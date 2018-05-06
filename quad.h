#ifndef QUAD_LIB	
	#define QUAD_LIB
	#include "symtable.h"
	#include <string>
	#include <list>

typedef enum bool_t{
	false_t,true_t
}bool_t;

/*Type of the true/false lists*/
typedef std::list <unsigned> * short_list; 

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
	call_iopcode,
	param_iopcode,
	ret_iopcode,
	getretval_iopcode,
	funcstart_iopcode,
	funcend_iopcode,
	tablecreate_iopcode,
	tablegetelem_iopcode,
	tablesetelem_iopcode,
	jump_iopcode,
	invalid_iopcode
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
	constnum_e,
	constbool_e,
	conststring_e,
	nil_e
}expr_t;


typedef struct expr{
	expr_t 			type;
	symTableEntry* 	sym;
	expr* 			index;
	double 			numConst;
	std::string 	strConst;
	bool_t			boolConst;
	expr* 			next;
	short_list		truelist;
	short_list 		falselist;
}expr;

typedef struct quad{
	iopcode 	op;
	expr* 		result;
	expr* 		arg1;
	expr* 		arg2;
	unsigned	label;
	unsigned 	line;
}quad;

typedef struct calls{
	expr* 		elist;//not sure about this type but i guess its expr cos it says 'E'list
	bool_t		method;
	std::string	name;

}calls;

/*Creates a new quad and initializes it with the arguments. Then it stores it in the vector*/
void emit(iopcode opCode,expr *_arg1,expr *_arg2,expr *_res,unsigned _label,int yylineno);

/*Creates a new quad for arithmetic expressions*/
expr* emit_arithexpr(iopcode opCode,expr *_arg1,expr *_arg2,int yylineno);

/*Creats a new quad for tableitems*/
expr *emit_iftableitem(expr *e);

/*Creates some quads based on relational operators*/
expr* emit_relop(iopcode icode, expr* expr1, expr* expr2);

void printSymbol(symTableEntry* sym);

/*Prints the given expression*/
void printExpr(expr* e);

/*Prints all the recognized quads from the vector*/
void printQuads();

/*creates a new expr*/
expr *newexpr(expr_t e);

unsigned nextquadLabel(void);

expr *member_item(expr *,std::string);

/*Checks if the given expression is a valid arithmetic one
 returns: true for valid / false for invalid*/
bool isValidArithexpr(expr* e);

expr *member_item(expr * e,std::string id);

expr *newxpr_conststring(std::string s);

void elist_vctr_add(expr *e);

expr* emit_bool(iopcode icode, expr* expr1, expr* expr2);

expr *member_item(expr * e,std::string id);

expr *newxpr_constrstring(std::string s);

expr *make_call(expr *lvalue,expr* elist);

/*Creates a new expression with constnum_e type 
and fills the numConst field with the given value*/
expr* newexpr_constnum(double i);

/*Creates a new expression with constbool_e type 
and fills the boolConst field with the given value*/
expr* newexpr_constbool(bool_t b);


/*
	Since we know at compile time a unary minus conflict, we can spot it.
	Returns 1 for legal expressions to uminus, and 0 to ilegal ones.
*/
int checkuminus(expr *e);

void patchLabel(unsigned index, unsigned nextQuad);


typedef struct forJump{
	unsigned test;
	unsigned enter;
}forJump;


/*Creates a new short_list and inserts the argument label
 then returns the list*/
short_list makelist(unsigned label);

/*merge the two lists and return the result */
short_list mergelist(short_list l1, short_list l2);

/*Emits quads for relops using short circuit method*/
expr* emit_relop_short(iopcode icode, expr* expr1, expr* expr2);

#endif