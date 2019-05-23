#include "quad.h"
#include "symbolUtilities.h"
#include "jumplists.h"
#include <vector>
#include <iostream>
#include <stack>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>
#include <assert.h>
#include <sstream>

extern int yylineno;

/*Global vector that contains all the quads*/
std::vector<quad> vctr_quads;

void emit(iopcode opCode, expr *_arg1, expr *_arg2, expr *_res, unsigned _label, int yylineno)
{

	/*Create new quad*/
	quad *newQuad = new quad();

	newQuad->op = opCode;
	newQuad->arg1 = _arg1;
	newQuad->arg2 = _arg2;
	newQuad->result = _res;
	newQuad->label = _label;
	newQuad->line = yylineno;

	vctr_quads.push_back(*newQuad);
}

expr *emit_arithexpr(iopcode opCode, expr *_arg1, expr *_arg2, int yylineno)
{

	if (isValidArithexpr(_arg1) && isValidArithexpr(_arg2))
	{
		expr *result_e = newexpr(arithexpr_e);
		result_e->sym = newtemp();
		emit(opCode, _arg1, _arg2, result_e, 0, yylineno);
		return result_e;
	}
	else
	{
		std::cout << "ERROR: invalid arithexpr";
		printExpr(_arg1);
		std::cout << std::endl;
		printExpr(_arg1);
		std::cout << std::endl;
		return NULL;
	}
}

expr *emit_iftableitem(expr *e)
{

	if (e->type != tableitem_e)
	{
		return e;
	}
	else
	{
		expr *result = newexpr(var_e);
		result->sym = newtemp();
		emit(tablegetelem_iopcode, e, e->index, result, 0, yylineno);
		return result;
	}
}

/*Creates some quads based on relational operators*/
expr *emit_relop(iopcode icode, expr *expr1, expr *expr2)
{

	expr *result = newexpr(boolexpr_e);
	result->sym = newtemp();

	emit(icode, expr1, expr2, NULL, nextquadLabel() + 3, yylineno);
	emit(assign_iopcode, newexpr_constbool(false_t), NULL, result, 0, yylineno);
	emit(jump_iopcode, NULL, NULL, NULL, nextquadLabel() + 2, yylineno);
	emit(assign_iopcode, newexpr_constbool(true_t), NULL, result, 0, yylineno);

	return result;
}

/*Creates some quads based on boolean operators*/
expr *emit_bool(iopcode icode, expr *expr1, expr *expr2)
{
	expr *result = newexpr(boolexpr_e);
	result->sym = newtemp();

	emit(icode, expr1, expr2, result, 0, yylineno);

	return result;
}

std::string iopcodeToString(iopcode op)
{
	switch (op)
	{
	case assign_iopcode:
		return "ASSIGN";
	case add_iopcode:
		return "ADD";
	case sub_iopcode:
		return "SUB";
	case mul_iopcode:
		return "MUL";
	case div_iopcode:
		return "DIV";
	case mod_iopcode:
		return "MOD";
	case uminus_iopcode:
		return "UMINUS";
	case funcstart_iopcode:
		return "FUNCSTART";
	case funcend_iopcode:
		return "FUNCEND";
	case tablegetelem_iopcode:
		return "TABLEGETELEM";
	case tablesetelem_iopcode:
		return "TABLESETELEM";
	case tablecreate_iopcode:
		return "TABLECREATE";
	case call_iopcode:
		return "CALL";
	case param_iopcode:
		return "PARAM";
	case getretval_iopcode:
		return "GETRETVAL";
	case if_eq_iopcode:
		return "IF_EQ";
	case if_noteq_iopcode:
		return "IF_NOTEQ";
	case if_lesseq_iopcode:
		return "IF_LESSEQ";
	case if_greatereq_iopcode:
		return "IF_GREATEREQ";
	case if_less_iopcode:
		return "IF_LESS";
	case if_greater_iopcode:
		return "IF_GREATER";
	case jump_iopcode:
		return "JUMP";
	case and_iopcode:
		return "AND";
	case or_iopcode:
		return "OR";
	case ret_iopcode:
		return "RETURN";
	default:
		return "INVALID";
	}
}

std::string expr_ToString(expr_t e)
{
	switch (e)
	{
	case var_e:
		return "var_e";
	case tableitem_e:
		return "tableitem_e";
	case programfunc_e:
		return "programfunc_e";
	case libraryfunc_e:
		return "libraryfunc_e";
	case arithexpr_e:
		return "arithexpr_e";
	case boolexpr_e:
		return "boolexpr_e";
	case assignexpr_e:
		return "assignexpr_e";
	case newtable_e:
		return "newtable_e";
	case constnum_e:
		return "costnum_e";
	case constbool_e:
		return "constbool_e";
	case conststring_e:
		return "conststring_e";
	case nil_e:
		return "nil_e";
	default:
		return "invalid expression type";
	}
}

void printSymbol(symTableEntry *sym)
{
	std::cout << "\t\t\t"
			  << "name: " << sym->name << std::endl;
	if (sym->symType != USER_FUNC && sym->symType != LIB_FUNC)
		std::cout << "\t\t\t"
				  << "offset: " << sym->offset << std::endl;
	/*WIP: print more members*/
}

/*Prints the given expression*/
void printExpr(expr *e)
{
	std::cout << "\t\tType: " << expr_ToString(e->type) << std::endl;

	if (e->sym)
	{
		std::cout << "\t\tSymbol: " << std::endl;
		printSymbol(e->sym);
	}
	if (e->type == constnum_e)
		std::cout << "\t\tnumConst: " << e->numConst << std::endl;
	if (e->type == conststring_e)
		std::cout << "\t\tstrConst: " << e->strConst << std::endl;
	if (e->type == constbool_e)
		std::cout << "\t\tboolConst: " << e->boolConst << std::endl;
}

/*Prints all the quads in the vector*/
void printQuads_debug()
{
	int count = 0;
	for (std::vector<quad>::const_iterator i = vctr_quads.begin(); i != vctr_quads.end(); ++i)
	{
		std::cout << "#"
				  << "Quad " << count++ << ": " << std::endl;
		std::cout << "\tiopcode: " << iopcodeToString(i->op) << "\n";

		if (i->arg1)
		{
			std::cout << "\targ1: "
					  << "\n";
			printExpr(i->arg1);
		}

		if (i->arg2)
		{
			std::cout << "\targ2: "
					  << "\n";
			printExpr(i->arg2);
		}
		if (i->result)
		{
			std::cout << "\tresult: "
					  << "\n";
			printExpr(i->result);
		}
		if (i->op == jump_iopcode || i->op == if_eq_iopcode || i->op == if_noteq_iopcode || i->op == if_lesseq_iopcode || i->op == if_greatereq_iopcode || i->op == if_less_iopcode || i->op == if_greater_iopcode)
			std::cout << "\tlabel: " << i->label << "\n";

		std::cout << "\tline: " << i->line << "\n";
	}
}

void printQuads()
{
	int count = 0;

	std::cout << std::setw(5) << "Quad" << std::setw(20) << "IOPCODE";
	std::cout << std::setw(13) << "arg1" << std::setw(10) << "arg2";
	std::cout << std::setw(15) << "result/label" << std::endl;

	for (std::vector<quad>::const_iterator i = vctr_quads.begin(); i != vctr_quads.end(); ++i)
	{
		std::cout << std::setw(5) << "<#" << count++ << ">" << std::setw(20) << iopcodeToString(i->op);

		if (i->arg1)
		{
			std::cout << std::setw(10) << exprtoString(i->arg1);
		}
		else
		{
			std::cout << std::setw(10) << "";
		}

		if (i->arg2)
		{
			std::cout << std::setw(10) << exprtoString(i->arg2);
		}
		else
		{
			std::cout << std::setw(10) << "";
		}

		if (i->result)
			std::cout << std::setw(10) << exprtoString(i->result);

		if (i->op == jump_iopcode || i->op == if_eq_iopcode || i->op == if_noteq_iopcode || i->op == if_lesseq_iopcode || i->op == if_greatereq_iopcode || i->op == if_less_iopcode || i->op == if_greater_iopcode)
			std::cout << std::setw(10) << i->label << "\n";

		std::cout << std::endl;
	}
}

std::string exprtoString(expr *e)
{
	assert(e);
	std::ostringstream strs;
	std::string str;

	switch (e->type)
	{
	case constnum_e:
		strs << e->numConst;
		str = strs.str();
		return str;
	case constbool_e:
		strs << e->boolConst;
		str = strs.str();
		return str;
	case conststring_e:
		return e->strConst;
	case nil_e:
		return "NIL";
	default:
		return e->sym->name;
	}
}

expr *newexpr(expr_t e)
{
	expr *ptr = new expr();

	ptr->type = e;

	return ptr;
}

unsigned nextquadLabel(void)
{
	return vctr_quads.size();
}

/*Checks if the given expression is a valid arithmetic one
 returns: true for valid / false for invalid*/
bool isValidArithexpr(expr *e)
{
	if (e->type == programfunc_e || e->type == libraryfunc_e || e->type == boolexpr_e || e->type == newtable_e || e->type == constbool_e || e->type == conststring_e || e->type == nil_e)
	{
		return false;
	}
	return true;
}

expr *member_item(expr *e, std::string id)
{
	expr *item;
	e = emit_iftableitem(e);
	item = newexpr(tableitem_e);
	item->sym = e->sym;
	item->index = newxpr_conststring(id);

	return item;
}

expr *newxpr_conststring(std::string s)
{
	expr *e = newexpr(conststring_e);
	e->strConst = s;
	return e;
}

expr *make_call(expr *lvalue, expr *elist)
{
	std::stack<expr *> callsElist;
	expr *func, *lnext, *result;
	func = emit_iftableitem(lvalue);

	lnext = elist;

	//diatreksi autis tis listas:exei to elist
	while (lnext != NULL)
	{
		callsElist.push(lnext);
		lnext = lnext->next;
	}
	while (!callsElist.empty())
	{
		emit(param_iopcode, NULL, NULL, callsElist.top(), 0, yylineno);
		callsElist.pop();
	}

	emit(call_iopcode, NULL, NULL, func, 0, yylineno);

	result = newexpr(var_e);
	result->sym = newtemp();
	emit(getretval_iopcode, NULL, NULL, result, 0, yylineno);

	return result;
}

/*Creates a new expression with constnum_e type
and fills the numConst field with the given value*/
expr *newexpr_constnum(double i)
{
	expr *e = newexpr(constnum_e);
	e->numConst = i;
	return e;
}

/*Creates a new expression with constbool_e type
and fills the boolConst field with the given value*/
expr *newexpr_constbool(bool_t b)
{
	expr *e = newexpr(constbool_e);
	e->boolConst = b;
	return e;
}

//eriona
/*
	Since we know at compile time a unary minus conflict, we can spot it.
	Returns 1 for legal expressions to uminus, and 0 to ilegal ones.
*/
int checkuminus(expr *e)
{
	if (e->type == constbool_e ||
		e->type == conststring_e ||
		e->type == nil_e ||
		e->type == newtable_e ||
		e->type == programfunc_e ||
		e->type == libraryfunc_e ||
		e->type == boolexpr_e)
		return 0; //error case

	else
		return 1; //legal case
}

void patchLabel(unsigned index, unsigned nextQuad)
{
	vctr_quads[index].label = nextQuad;
}
