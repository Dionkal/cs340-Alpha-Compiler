#ifndef GEN_INSTR_FUNC_LIB
	#define GEN_INSTR_FUNC_LIB
	#include "quad.h"
	

	void generate_ADD(quad* q);

	void generate_SUB(quad* q);
	
	void generate_MUL(quad* q);
 	
 	void generate_DIV(quad* q);
 	
 	void generate_MOD(quad* q);
 	
 	void generate_UMINUS(quad* q);
 	
 	void generate_NEWTABLE(quad* q);
 	
 	void generate_TABLEGETELEM(quad* q);
 	
 	void generate_TABLESETELEM(quad* q);
 	
 	void generate_ASSIGN(quad* q);
 	
 	void generate_NOP(quad* q);
 	
 	void generate_JUMP(quad* q);
 	
 	void generate_IF_EQ(quad* q);
 	
 	void generate_IF_NOTEQ(quad* q);
 	
 	void generate_IF_GREATER(quad* q);
 	
 	void generate_IF_GREATEREQ(quad* q );
 	
 	void generate_IF_LESS(quad* q);
 	
 	void generate_IF_LESSEQ(quad* q);
 	
 	void generate_NOT(quad* q);
 	
 	void generate_OR(quad* q);
 	
 	void generate_PARAM(quad* q);
 	
 	void generate_CALL(quad* q);
 	
 	void generate_GETRETVAL(quad* q);
 	
 	void generate_FUNCSTART(quad* q);
	
	void generate_RETURN(quad* q);
	
	void generate_FUNCEND(quad* q);
#endif