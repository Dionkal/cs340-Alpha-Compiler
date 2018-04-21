%{
	#include <stdlib.h>
	#include <stdio.h>
	#include <stack>
	#include <string>
	#include "symtable.h"
	#include <stdio.h>
	#include <iostream>
	#include <sstream>

	void yyerror (const char *yaccProvidedMessage);
	extern int yylex(void);
	unsigned int scope=0;
	int k=0;

	extern int yylineno;
	extern char* yytext;
	extern FILE* yyin;
	extern unsigned int current_scope;
	std::stack<bool> scopeAccessStack;
	unsigned int anonymousCounter = 0;
%}

%expect 1
%start 	program

%union {
	char* stringValue;
	float floatValue;
	void* symValue;
}

%token <stringValue> ID 
%token <floatValue> NUMBER
%token <stringValue> STRING 
%token BREAK CONTINUE AND OR NOT GREATEREQUAL LESSEQUAL EQUAL NOTEQUAL  PLUSPLUS MINUSMINUS LOCAL SCOPEOP DOUPLEDOT FUNCTION NIL TRUE FALSE IF ELSE WHILE FOR RETURN

%type <symValue> lvalue
//%type<ptr> expr

%left '(' ')' 
%left '[' ']'
%left '.' DOUBLEDOT
%right NOT PLUSPLUS MINUSMINUS UMINUS 
%left '*' '/' '%'
%left '+' '-'
%nonassoc '>' GREATEREQUAL '<' LESSEQUAL
%nonassoc EQUAL NOTEQUAL
%left AND
%left OR
%right '='



%%

program:	stmt1						{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("Program accepted\n");}
			|/*empty*/					{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("Program did not start\n");}
			;

stmt1:		stmt1 stmt
            |stmt
			;

stmt:		expr ';'																{printf("stmt:Expression with ';' in line:%d\n",yylineno);}
			|expr error ';'
			|ifstmt 																{printf("stmt:ifstmt starts in line:%d\n",yylineno);}
			|whilestmt 																{printf("stmt:whilestmt starts in line:%d\n",yylineno);}
			|forstmt 																{printf("stmt:forstmt starts in line:%d\n",yylineno);}
			|returnstmt 															{printf("stmt:returnstmt starts in line:%d\n",yylineno);}
			|BREAK ';' 																{printf("stmt:Break with ';' in line:%d\n",yylineno);}
			|CONTINUE ';'															{printf("stmt:Continue with ';' in line:%d\n",yylineno);}
			|{scopeAccessStack.push(false);} block 		{scopeAccessStack.pop();}	{printf("stmt:block starts in line:%d\n",yylineno);}
			|funcdef																{printf("stmt:funcdef starts in line:%d\n",yylineno);}
			|';'																	{printf("stmt:SEMICOLON in line:%d\n",yylineno);}
			;

expr:		assignexpr 					{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("expr:assignexpr in line:%d\n",yylineno);}
			|expr '+' expr 				{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("expr:expr + expr in line:%d\n",yylineno);}
			|expr '-' expr 				{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("lexpr:expr - expr in line:%d\n",yylineno);}
			|expr '*' expr 				{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("expr:expr * expr in line:%d\n",yylineno);}
			|expr '/' expr 				{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("expr:expr / expr in line:%d\n",yylineno);}
			|expr '%' expr 				{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("expr:expr mod expr in line:%d\n",yylineno);}
			|expr '>' expr 				{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("expr:expr > expr in line:%d\n",yylineno);}
			|expr '<' expr 				{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("expr:expr < expr in line:%d\n",yylineno);}
			|expr GREATEREQUAL expr 	{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("expr:expr >= expr in line:%d\n",yylineno);}
			|expr LESSEQUAL expr 		{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("expr:expr <= expr in line:%d\n",yylineno);}
			|expr EQUAL expr 			{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("expr:expr ==(EQUAL) expr in line:%d\n",yylineno);}
			|expr NOTEQUAL expr 		{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("expr:expr != expr in line:%d\n",yylineno);}
			|expr AND expr 				{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("expr:expr AND expr in line:%d\n",yylineno);}
			|expr OR expr 				{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("expr:expr OR expr in line:%d\n",yylineno);}
			|term						{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("expr:term in line:%d\n",yylineno);}
			;



term: 		'('expr ')' 				{printf("term:(expr) in line:%d\n",yylineno);}
			| '-' expr %prec UMINUS		{{printf("term:-expr in line:%d\n",yylineno);}}
			| NOT expr 					{printf("term:!expr in line:%d\n",yylineno);}
			|PLUSPLUS lvalue 			{	printf("term:++lvalue in line:%d\n",yylineno);
											symTableEntry* ptr = (symTableEntry*) $2;
											
											if(ptr != NULL && (ptr->symType == USER_FUNC || ptr->symType == LIB_FUNC)){
												std::cout << "\033[01;31mERROR:Cannot use funtion " <<ptr->name <<" with operator ++ at line " <<yylineno << "\033[00m" << std::endl;
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
			|primary 					{printf("term:primary in line:%d\n",yylineno);}
			;

assignexpr:	lvalue '=' expr 			{printf("assignexpr:lvalue=expr in line:%d\n",yylineno);
											symTableEntry* ptr = (symTableEntry*) $1;
											
											if(ptr != NULL && (ptr->symType == USER_FUNC || ptr->symType == LIB_FUNC)){
												std::cout << "\033[01;31mERROR:Cannot use funtion " <<ptr->name <<" as left value of assignment at line " <<yylineno << "\033[00m" << std::endl;
											}
										}
			;

primary:	lvalue 						{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("primary: lvalue in line:%d\n",yylineno);}
			|call 						{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("primary: call in line:%d\n",yylineno);}
			|objectdef 					{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("primary: objectdef in line:%d\n",yylineno);}
			|'(' funcdef ')'            {k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("primary: (funcdef) in line:%d\n",yylineno);}
			|const 						{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("primary: const in line:%d\n",yylineno);}
			;

lvalue: 	ID 							{printf("lvalue: ID in line:%d\n",yylineno);
										 
										 symTableEntry* ptr = lookupSym($1);

										if(ptr==NULL){
										 	symTableType type;
										 	if(current_scope == 0){
										 		type = GLOBAL_VAR;
										 	}else{
										 		type = LOCAL_VAR;
										 	}
										 	insertSym($1,type,NULL,current_scope,yylineno);
											ptr = lookupSym($1);
										}else{

										 	if( scopeAccessStack.top() && (ptr->symType == LOCAL_VAR || ptr->symType == ARGUMENT_VAR) && (ptr->scope != current_scope && ptr->scope != 0)){
										 		std::cout  <<"\033[01;31mERROR cannot access " <<ptr->name <<" in scope " <<ptr->scope <<" at line " <<yylineno <<"\033[00m" << std::endl;
										 		ptr = NULL;
										 	}
										}
										 $$ =(void*) ptr;
										}
			|LOCAL ID 					{	printf("lvalue: LOCAL ID in line:%d\n",yylineno);
											symTableEntry* ptr = lookupSym($2,current_scope);
											
											if(ptr==NULL){
												if(checkCollisionSym($2)){
													std::cout <<"\033[01;31mERROR: cannot name symbol at line "  <<yylineno <<" as library function "<<$2 << "\033[00m" << std::endl;
												}else{
													symTableType type;
										 			if(current_scope == 0){
										 				type = GLOBAL_VAR;
										 			}else{
										 				type = LOCAL_VAR;
										 			}
										 			insertSym($2,type,NULL,current_scope,yylineno);
										 			ptr = lookupSym($2);
												}
											}
											$$ = (void*) ptr;
										}
			|SCOPEOP ID 				{	printf("lvalue: SCOPE ID in line:%d\n",yylineno);
											symTableEntry* ptr = lookupSym($2,0);
											
											if(ptr == NULL) std::cout << "\033[01;31mERROR there is no global var " << $2 << "\033[00m" <<std::endl;	
											$$= (void*) ptr;	
										}
			|member 					{printf("lvalue: member in line:%d\n",yylineno);}
			;

member:		lvalue '.' ID 				{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("member: lvalue.ID in line:%d\n",yylineno);}
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

funcdef:	FUNCTION ID  	
												{
													symTableEntry* ptr = lookupSym($2,current_scope);
													/*TODO:take idlist argument list and pass it to insertSym*/										
													if(ptr== NULL){
														if(checkCollisionSym($2)){
															std::cout <<"\033[01;31mERROR: cannot define function at line "  <<yylineno <<" as library function "<<$2 << "\033[00m" << std::endl;
														}else{
															insertSym($2,USER_FUNC,NULL,current_scope,yylineno);
															
														}
													}else{
														printf("\033[01;31mERROR: Symbol %s already defined at line %d\033[00m\n",$2,ptr->declLine);
													}
													
												} '('{current_scope++;} idlist ')' {current_scope--; scopeAccessStack.push(true);} block {scopeAccessStack.pop();}
			| FUNCTION 
												{
													std::string StringTemp = static_cast<std::ostringstream*>( &(std::ostringstream() << anonymousCounter) )->str();
													std::string anonFunc = "_anonFunc" + StringTemp;
													anonymousCounter++;
													insertSym(anonFunc,USER_FUNC,NULL,current_scope,yylineno);
												} '('{current_scope++;} idlist ')' {current_scope--; scopeAccessStack.push(true);} block {scopeAccessStack.pop();}
			;		

const:		NUMBER | STRING | NIL |TRUE|FALSE 	{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("const: NUMBER | STRING | NIL |TRUE|FALSE in line:%d\n",yylineno);}
			;

idlist:		/*empty*/							{printf("idlist: empty in line:%d\n",yylineno);}
			|ID idlist1 						{
													printf("idlist: ID idlist1 in line:%d\n",yylineno);
													symTableEntry* ptr = lookupSym($1,current_scope);
													
													if(ptr == NULL){
														if(checkCollisionSym($1)){
															std::cout <<"\033[01;31mERROR: cannot define formal argumnet at line "  <<yylineno <<" as library function "<<$1 << "\033[00m" << std::endl;
														}else{
															insertSym($1,ARGUMENT_VAR,NULL,current_scope,yylineno);
														}
													}else{
														std::cout <<"\033[01;31mERROR: Symbol "  <<$1 <<" at line " <<yylineno <<" already defined at line " <<ptr->declLine << "\033[00m" << std::endl;
													}
												}
			;

idlist1:	/*empty*/ 							{printf("idlist1: empty in line:%d\n",yylineno);}
			|',' ID idlist1 					{
													printf("idlist1: ,ID idlist1 in line:%d\n",yylineno);
													symTableEntry* ptr = lookupSym($2,current_scope);
													
													if(ptr == NULL){
														if(checkCollisionSym($2)){
															std::cout <<"\033[01;31mERROR: cannot define formal argumnet at line "  <<yylineno <<" as library function "<<$2 << "\033[00m" << std::endl;
														}else{
															insertSym($2,ARGUMENT_VAR,NULL,current_scope,yylineno);
														}
													}else{
														std::cout <<"\033[01;31mERROR: Symbol "  <<$2 <<" at line " <<yylineno <<" already defined at line " <<ptr->declLine << "\033[00m" << std::endl;
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
