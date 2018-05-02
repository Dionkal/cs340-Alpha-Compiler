%{
	#include <stdlib.h>
	#include <stdio.h>
	#include <stack>
	#include <string>
	#include "quad.h"
	#include "symbolUtilities.h"
	#include <iostream>
	#include <sstream>

	void yyerror (const char *yaccProvidedMessage);
	extern int yylex(void);
	int k=0;

	extern int yylineno;
	extern char* yytext;
	extern FILE* yyin;
	extern int current_scope;
	extern unsigned int scopeSpaceCounter;
	std::stack<bool> scopeAccessStack;
	unsigned int anonymousCounter = 0;
%}

%expect 1
%start 	program

%union {
	char* stringValue;
	float floatValue;
	void* exprPtr;
	void* sym;
}

%token <stringValue> ID 
%token <floatValue> NUMBER
%token <stringValue> STRING 
%token BREAK CONTINUE AND OR NOT GREATEREQUAL LESSEQUAL EQUAL NOTEQUAL  PLUSPLUS MINUSMINUS LOCAL SCOPEOP DOUPLEDOT FUNCTION NIL TRUE FALSE IF ELSE WHILE FOR RETURN

%type <exprPtr> lvalue
%type <exprPtr> const
%type <exprPtr> primary
%type <exprPtr> term
%type <exprPtr> expr
%type <exprPtr> assignexpr
%type <sym>		funcname
%type <exprPtr> funcprefix
%type <exprPtr> funcdef



%right '='
%left OR
%left AND
%nonassoc EQUAL NOTEQUAL
%nonassoc '>' GREATEREQUAL '<' LESSEQUAL
%left '+' '-'
%left '*' '/' '%'
%right NOT PLUSPLUS MINUSMINUS UMINUS 
%left '.' DOUBLEDOT
%left '[' ']'
%left '(' ')' 

%%

program:	stmt1						{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("Program accepted\n");}
			|/*empty*/					{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("Program did not start\n");}
			;

stmt1:		stmt1 stmt
            |stmt
			;

stmt:		expr ';'																{printf("stmt:Expression with ';' in line:%d\n",yylineno); resettemp();}
			|expr error ';'
			|ifstmt 																{printf("stmt:ifstmt starts in line:%d\n",yylineno); resettemp();}
			|whilestmt 																{printf("stmt:whilestmt starts in line:%d\n",yylineno); resettemp();}
			|forstmt 																{printf("stmt:forstmt starts in line:%d\n",yylineno); resettemp();}
			|returnstmt 															{printf("stmt:returnstmt starts in line:%d\n",yylineno); resettemp();}
			|BREAK ';' 																{printf("stmt:Break with ';' in line:%d\n",yylineno); resettemp();}
			|CONTINUE ';'															{printf("stmt:Continue with ';' in line:%d\n",yylineno); resettemp();}
			|{scopeAccessStack.push(false);} block 		{scopeAccessStack.pop();}	{printf("stmt:block starts in line:%d\n",yylineno); resettemp();}
			|funcdef																{printf("stmt:funcdef starts in line:%d\n",yylineno); resettemp();}
			|';'																	{printf("stmt:SEMICOLON in line:%d\n",yylineno); resettemp();}
			;

expr:		assignexpr 					{ 
											printf("expr:	` in line:%d\n",yylineno);
											($$) = ($1);
										}
			|expr '+' expr 				{	
											printf("expr:expr + expr in line:%d\n",yylineno);
											
											$$ = (void*) emit_arithexpr(add_iopcode,(expr*)$1,(expr*) $3,yylineno);
										}
			|expr '-' expr 				{
											printf("lexpr:expr - expr in line:%d\n",yylineno);

											$$ = (void*) emit_arithexpr(sub_iopcode,(expr*)$1,(expr*) $3,yylineno);	
										}
			|expr '*' expr 				{
											printf("expr:expr * expr in line:%d\n",yylineno);

											$$ = (void*) emit_arithexpr(mul_iopcode,(expr*)$1,(expr*) $3,yylineno);	
										}
			|expr '/' expr 				{
											printf("expr:expr / expr in line:%d\n",yylineno);										
											
											$$ = (void*) emit_arithexpr(div_iopcode,(expr*)$1,(expr*) $3,yylineno);	
										}
			|expr '%' expr 				{
											printf("expr:expr mod expr in line:%d\n",yylineno);										
											
											$$ = (void*) emit_arithexpr(mod_iopcode,(expr*)$1,(expr*) $3,yylineno);	
										}
			|expr '>' expr 				{	
											printf("expr:expr > expr in line:%d\n",yylineno);										
											// emit(if_greater_iopcode,($1),($3),($$),0,yylineno);
											/*vazo 0 sto label gt den ksero ti prepei na mpei*/
										}
			|expr '<' expr 				{	
											printf("expr:expr < expr in line:%d\n",yylineno);										
											// emit(if_less_iopcode,($1),($3),($$),0,yylineno);
											/*vazo 0 sto label gt den ksero ti prepei na mpei*/
										}
			|expr GREATEREQUAL expr 	{	
											printf("expr:expr >= expr in line:%d\n",yylineno);										
											// emit(if_greatereq_iopcode,($1),($3),($$),0,yylineno);
											/*vazo 0 sto label gt den ksero ti prepei na mpei*/
										}
			|expr LESSEQUAL expr 		{	
											printf("expr:expr <= expr in line:%d\n",yylineno);										
											// emit(if_lesseq_iopcode,($1),($3),($$),0,yylineno);
											/*vazo 0 sto label gt den ksero ti prepei na mpei*/
										}
			|expr EQUAL expr 			{	
											printf("expr:expr ==(EQUAL) expr in line:%d\n",yylineno);										
											// emit(if_eq_iopcode,($1),($3),($$),0,yylineno);
											/*vazo 0 sto label gt den ksero ti prepei na mpei*/
										}
			|expr NOTEQUAL expr 		{
											printf("expr:expr != expr in line:%d\n",yylineno);										
											// emit(if_noteq_iopcode,($1),($3),($$),0,yylineno);
											/*vazo 0 sto label gt den ksero ti prepei na mpei*/
										}
			|expr AND expr 				{	printf("expr:expr AND expr in line:%d\n",yylineno);										
											// emit(and_iopcode,($1),($3),($$),0,yylineno);
											/*vazo 0 sto label gt den ksero ti prepei na mpei*/
										}
			|expr OR expr 				{	printf("expr:expr OR expr in line:%d\n",yylineno);										
											// emit(or_iopcode,($1),($3),($$),0,yylineno);
											/*vazo 0 sto label gt den ksero ti prepei na mpei*/
										}
			|term						{ 
											printf("expr:term in line:%d\n",yylineno);
											($$) = ($1);
										}
			;



term: 		'('expr ')' 				{printf("term:(expr) in line:%d\n",yylineno);
											($$) = ($2);
										}
			| '-' expr %prec UMINUS		{	
											printf("term:-expr in line:%d\n",yylineno);									
											// emit(uminus_iopcode,($1),($2),($$),0,yylineno);
											/*vazo 0 sto label gt den ksero ti prepei na mpei*/

										}
			| NOT expr 					{
											printf("term:!expr in line:%d\n",yylineno);					
											// emit(not_iopcode,($1),($2),($$),0,yylineno);
											/*vazo 0 sto label gt den ksero ti prepei na mpei*/
										}
			|PLUSPLUS lvalue 			{	printf("term:++lvalue in line:%d\n",yylineno);
											symTableEntry* ptr = (symTableEntry*) $2;
											
											if(ptr != NULL && (ptr->symType == USER_FUNC || ptr->symType == LIB_FUNC)){
												std::cout << "\033[01;31mERROR:Cannot use function " <<ptr->name <<" with operator ++ at line " <<yylineno << "\033[00m" << std::endl;
											}
										}
			|lvalue PLUSPLUS 			{	printf("term:lvalue++ in line:%d\n",yylineno);
											symTableEntry* ptr = (symTableEntry*) $1;

											if(ptr != NULL && (ptr->symType == USER_FUNC || ptr->symType == LIB_FUNC)){
												std::cout << "\033[01;31mERROR:Cannot use funtion " <<ptr->name <<" with operator ++ at line " <<yylineno << "\033[00m" << std::endl;
											}
										}
			|MINUSMINUS lvalue 			{	printf("term:--lvalue in line:%d\n",yylineno);
											symTableEntry* ptr = (symTableEntry*) $2;

											if(ptr != NULL && (ptr->symType == USER_FUNC || ptr->symType == LIB_FUNC)){
												std::cout << "\033[01;31mERROR:Cannot use funtion " <<ptr->name <<" with operator -- " <<yylineno << "\033[00m" << std::endl;
											}
										}
			|lvalue MINUSMINUS 			{	printf("term:lvalue-- in line:%d\n",yylineno);
											symTableEntry* ptr = (symTableEntry*) $1;
											
											if(ptr != NULL && (ptr->symType == USER_FUNC || ptr->symType == LIB_FUNC)){
												std::cout << "\033[01;31mERROR:Cannot use funtion " <<ptr->name <<" with operator -- " <<yylineno << "\033[00m" << std::endl;
											}
										}
			|primary 					{
											printf("term:primary in line:%d\n",yylineno);
											($$) = ($1);

										}
			;

assignexpr:	lvalue '=' expr 			{printf("assignexpr:lvalue=expr in line:%d\n",yylineno);
											if( $1 != NULL &&( ((expr*)$1)->sym->symType ==USER_FUNC || ((expr*)$1)->sym->symType ==LIB_FUNC) ){
												std::cout << "\033[01;31mERROR:Cannot use funtion " <<((expr*)$3)->sym->name 
														  <<" as left value of assignment at line " <<yylineno 
														  << "\033[00m" << std::endl;		
											}else{
												emit(assign_iopcode,(expr*) $3,NULL, (expr*) $1,0,yylineno);
												expr* result_e = newexpr(var_e);
												result_e->sym = newtemp();
												emit(assign_iopcode,(expr*) $1,NULL, result_e,0,yylineno);
												($$) = (void*) result_e;
											}
											
										}
			;

primary:	lvalue 						{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("primary: lvalue in line:%d\n",yylineno);}
			|call 						{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("primary: call in line:%d\n",yylineno);}
			|objectdef 					{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("primary: objectdef in line:%d\n",yylineno);}
			|'(' funcdef ')'            {k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("primary: (funcdef) in line:%d\n",yylineno);}
			|const 						{ 
											 printf("primary: const in line:%d\n",yylineno);
											 ($$) = ($1);
										}
			;

lvalue: 	ID 							{printf("lvalue: ID in line:%d\n",yylineno);
											expr* temp_expr = newexpr(var_e);
											temp_expr->sym=actionID($1);  
											($$)= temp_expr;
															
										}
			|LOCAL ID 					{	printf("lvalue: LOCAL ID in line:%d\n",yylineno);
											expr* temp_expr = newexpr(var_e);
											temp_expr->sym = actionLocalID($2);
											($$) = temp_expr;
											
										}
			|SCOPEOP ID 				{	printf("lvalue: SCOPE ID in line:%d\n",yylineno);
											expr* temp_expr = newexpr(var_e);
											temp_expr->sym = actionGlobalID($2);	
											($$) = temp_expr;
										}
			|member 					{printf("lvalue: member in line:%d\n",yylineno);}
			;

member:		lvalue '.' ID 				{printf("member: lvalue.ID in line:%d\n",yylineno);}
			|lvalue '[' expr ']' 		{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("member: lvalue [expr] in line:%d\n",yylineno);}
			|call '.' ID 				{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("member: call.ID in line:%d\n",yylineno);}
			|call '[' expr ']' 			{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("member: call [expr] in line:%d\n",yylineno);}
			;

call: 		call '(' elist ')' 			{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("call: (elist) in line:%d\n",yylineno);}
			|lvalue callsuffix			{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("call: lvalue callsuffix in line:%d\n",yylineno);}
			|'(' funcdef ')' '(' elist ')' {k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("call: (func) (elist) in line:%d\n",yylineno);}
			;

callsuffix:	normcall					{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("callsuffix: normcall in line:%d\n",yylineno);}
			|methodcall 				{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("callsuffix: methodcall in line:%d\n",yylineno);}
			;

normcall:   '(' elist ')'				{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("normcall: (elist) in line:%d\n",yylineno);}
			;

methodcall:	DOUPLEDOT ID '(' elist ')'  {k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("methodcall: DOUPLEDOT ID (elist) in line:%d\n",yylineno);}
			;

elist:		/*empty*/					{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("elist: empty list in line:%d\n",yylineno);}
			|expr elist1 				{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("elist: expr elist1 list in line:%d\n",yylineno);}
			;

elist1:		/*empty*/							{printf("elist1: empty list in line:%d\n",yylineno);}
			|','expr elist1 					{printf("elist1: ,expr elist1 in line:%d\n",yylineno);}
			|error expr elist1
			;

objectdef:	'[' elist ']' 						{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("objectdef: [elist] in line:%d\n",yylineno);}
			|'[' indexed ']'					{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("objectdef: [indexed] in line:%d\n",yylineno);}
			;


indexed:	indexedelem more					{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("indexed: indexedelem more in line:%d\n",yylineno);}
			;

more:       ',' indexedelem more 			{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("more: ,indexedelem more in line:%d\n",yylineno);}
            |/*empty*/            			{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("more: empty in line:%d\n",yylineno);}
            ; 
	

indexedelem:'{' expr ':' expr '}'			{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("indexedelem: {expr:expr} in line:%d\n",yylineno);}
			;

block:		'{' {current_scope++;} stmt1 '}' { hideSym(current_scope--);}							{printf("``: {stmt1} in line:%d\n",yylineno);}		
             |'{'{current_scope++;}'}'       {hideSym(current_scope--);} 							{printf("funcdefblock: {} in line:%d\n",yylineno);}
             |error stmt1 '}'
             |error '}'
			;	

funcdef:	funcprefix funcargs funcbody 		{
													std::cout<<"funcdef___\n";
													scopeSpaceCounter--; 
													scopeAccessStack.pop();
													getFunctionOffset(2);			
													deleteOffset();	
													($$)=($1);				
													emit(funcend_iopcode,NULL,NULL,(expr *)($1),0,yylineno);	
												}
			;



funcname: 	ID 									{
													std::cout<<"funcname___\n";
													($$)=(void *)actionFuncdefID($1);
												}
			|/*empty*/							{
													std::cout<<"anonymus func___\n";
													($$)=(void *)actionFuncdefAnon();
												}
			;

funcprefix:	FUNCTION funcname					{
													std::cout<<"func prefix___\n";
													unsigned label=nextquadLabel();
													/*TODO:check function address*/
													expr* result_e=newexpr(programfunc_e);
													result_e->sym=(symTableEntry *)($2);
													emit(funcstart_iopcode,NULL,NULL,result_e,label,yylineno);
													scopeSpaceCounter++; //this means enterScopeSpace
													newOffset();
													current_scope++; 
													($$)=(void *)result_e;
												}
			;

funcargs:	'(' idlist ')'						{
													std::cout<<"funcargs___\n";
													scopeSpaceCounter++;
													//to reset ginetai apo prin stin newOffset
													current_scope--; 
													scopeAccessStack.push(true); 
												}
			;

funcbody:	block								{
													std::cout<<"funcbody___\n";
													scopeSpaceCounter--; 
												}
			;

const:		NUMBER 								{
													expr* temp_expr = newexpr(costnum_e);
													temp_expr->numConst=($1);  
													($$) = temp_expr;
												}
			| STRING 							{
													expr* temp_expr = newexpr(conststring_e);
													temp_expr->strConst=($1);
													($$) = temp_expr;
												}
			| NIL 								{

													($$)= (void*) newexpr(nil_e);
												}
			|TRUE 								{
													expr* temp_expr =newexpr(boolexpr_e);
													temp_expr->boolConst=true_t;
													($$)=temp_expr;

												}
			|FALSE 								{
													expr* temp_expr = newexpr(boolexpr_e);
													temp_expr->boolConst=false_t;
													($$) = temp_expr; 
												}
			;

idlist:		/*empty*/							{printf("idlist: empty in line:%d\n",yylineno);}
			|ID idlist1 						{
													const char* temp = $1;
													//TODO create expr list
													printf("idlist: ID idlist1 in line:%d\n",yylineno);
													symTableEntry* ptr = lookupSym(std::string(temp),current_scope);
													
													if(ptr == NULL){
														if(checkCollisionSym(std::string(temp))){
															std::cout <<"\033[01;31mERROR: cannot define formal argumnet at line "  <<yylineno <<" as library function "<<std::string(temp) << "\033[00m" << std::endl;
														}else{
															insertSym(std::string(temp),ARGUMENT_VAR,current_scope,yylineno);
														}
													}else{
														std::cout <<"\033[01;31mERROR: Symbol "  <<std::string(temp) <<" at line " <<yylineno <<" already defined at line " <<ptr->declLine << "\033[00m" << std::endl;
													}

												}
			;

idlist1:	/*empty*/ 							{printf("idlist1: empty in line:%d\n",yylineno);}
			|',' ID idlist1 					{	
													const char* temp = $2;
													printf("idlist1: ,ID idlist1 in line:%d\n",yylineno);
													symTableEntry* ptr = lookupSym(std::string(temp),current_scope);
													
													if(ptr == NULL){
														if(checkCollisionSym(std::string(temp))){
															std::cout <<"\033[01;31mERROR: cannot define formal argumnet at line "  <<yylineno <<" as library function "<<$2 << "\033[00m" << std::endl;
														}else{
															insertSym(std::string(temp),ARGUMENT_VAR,current_scope,yylineno);
														}
													}else{
														std::cout <<"\033[01;31mERROR: Symbol "  <<std::string(temp) <<" at line " <<yylineno <<" already defined at line " <<ptr->declLine << "\033[00m" << std::endl;
													}
												}
			;

ifstmt:		IF '(' expr ')' stmt ifstmt1		{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("ifstmt: IF (expr) stmt ifstmt1 in line:%d\n",yylineno);}
			;

ifstmt1:	/*empty*/							{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("ifstmt1: empty in line:%d\n",yylineno);}
			|ELSE stmt 							{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("ifstmt1: ELSE stmt in line:%d\n",yylineno);}
			;

whilestmt:	WHILE '(' expr ')' stmt 			{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("whilestmt: WHILE (expr) stmt in line:%d\n",yylineno);}
			;

forstmt:	FOR '(' elist ';' expr ';' elist ')' stmt {k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("forstmt: FOR (elist;expr;elist) stmt in 								;											line:%d\n",yylineno);}

returnstmt:	RETURN ';' 							{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("returnstmt: RETURN; in line:%d",yylineno);}
			|RETURN expr ';'					{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("returnstmt: RETURN expr; in line:%d",yylineno);}
			;

%%

void yyerror(const char *yaccProvideMessage){
	fprintf(stdout,"%s: at line %d, before token: %s\n",yaccProvideMessage,yylineno,yytext);
	fprintf(stdout,"INPUT NOT VALID\n");

}
