%{
	#include <stdlib.h>
	#include <stdio.h>
	#include <stack>
	#include <string>
	#include "symtable.h"
	#include <stdio.h>
	#include <iostream>

	void yyerror (const char *yaccProvidedMessage);
	extern int yylex(void);

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

program:	stmt1						{printf("Program started\n");}
			|/*empty*/					{printf("Program did not start\n");}
			;

stmt1:		stmt1 stmt
            |stmt
			;

stmt:		expr ';' 																{printf("stmt:Expression with ';' in line:%d\n",yylineno);}
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

expr:		assignexpr 					{printf("expr:assignexpr in line:%d\n",yylineno);}
			|expr '+' expr 				{printf("expr:expr + expr in line:%d\n",yylineno);}
			|expr '-' expr 				{printf("expr:expr - expr in line:%d\n",yylineno);}
			|expr '*' expr 				{printf("expr:expr * expr in line:%d\n",yylineno);}
			|expr '/' expr 				{printf("expr:expr / expr in line:%d\n",yylineno);}
			|expr '%' expr 				{printf("expr:expr mod expr in line:%d\n",yylineno);}
			|expr '>' expr 				{printf("expr:expr > expr in line:%d\n",yylineno);}
			|expr '<' expr 				{printf("expr:expr < expr in line:%d\n",yylineno);}
			|expr GREATEREQUAL expr 	{printf("expr:expr >= expr in line:%d\n",yylineno);}
			|expr LESSEQUAL expr 		{printf("expr:expr <= expr in line:%d\n",yylineno);}
			|expr EQUAL expr 			{printf("expr:expr ==(EQUAL) expr in line:%d\n",yylineno);}
			|expr NOTEQUAL expr 		{printf("expr:expr != expr in line:%d\n",yylineno);}
			|expr AND expr 				{printf("expr:expr AND expr in line:%d\n",yylineno);}
			|expr OR expr 				{printf("expr:expr OR expr in line:%d\n",yylineno);}
			|term						{printf("expr:term in line:%d\n",yylineno);}
			;



term: 		'('expr ')' 				{printf("term:(expr) in line:%d\n",yylineno);}
			| '-' expr %prec UMINUS		{{printf("term:-expr in line:%d\n",yylineno);}}
			| NOT expr 					{printf("term:!expr in line:%d\n",yylineno);}
			|PLUSPLUS lvalue 			{printf("term:++lvalue in line:%d\n",yylineno);}
			|lvalue PLUSPLUS 			{printf("term:lvalue++ in line:%d\n",yylineno);}
			|MINUSMINUS lvalue 			{printf("term:--lvalue in line:%d\n",yylineno);}
			|lvalue MINUSMINUS 			{printf("term:lvalue-- in line:%d\n",yylineno);}
			|primary 					{printf("term:primary in line:%d\n",yylineno);}
			;

assignexpr:	lvalue '=' expr 			{printf("assignexpr:lvalue=expr in line:%d\n",yylineno);}
			;

primary:	lvalue 						{printf("primary: lvalue in line:%d\n",yylineno);}
			|call 						{printf("primary: call in line:%d\n",yylineno);}
			|objectdef 					{printf("primary: objectdef in line:%d\n",yylineno);}
			|'(' funcdef ')'            {printf("primary: (funcdef) in line:%d\n",yylineno);}
			|const 						{printf("primary: const in line:%d\n",yylineno);}
			;

lvalue: 	ID 							{printf("lvalue: ID in line:%d\n",yylineno);
										 
										 symTableEntry* ptr = lookupSym($1);
										 
										 if(lvalueCheckSym(ptr,current_scope,yylineno)){
										 	symTableType type;
										 	if(current_scope == 0){
										 		type = GLOBAL_VAR;
										 	}else{
										 		type = LOCAL_VAR;
										 	}
										 	if( !ptr || (!scopeAccessStack.top() && ptr->symType != LOCAL_VAR && ptr->symType != ARGUMENT_VAR && (ptr->scope == current_scope || ptr->scope == 0))){
										 		insertSym($1,type,NULL,current_scope,yylineno);
										 	}else{
												printf("ERROR cannot access %s in scope %d\n",ptr->name, ptr->scope);
											}
										 }
										}
			|LOCAL ID 					{	printf("lvalue: LOCAL ID in line:%d\n",yylineno);
											symTableEntry* ptr = lookupSym($2,current_scope);
											
											if(lvalueCheckSym(ptr,current_scope, yylineno)){
												symTableType type;
										 		if(current_scope == 0){
										 			type = GLOBAL_VAR;
										 		}else{
										 			type = LOCAL_VAR;
										 		}
												insertSym($2,type,NULL,current_scope,yylineno);			
											}
										}
			|SCOPEOP ID 				{	printf("lvalue: SCOPE ID in line:%d\n",yylineno);
											symTableEntry* ptr = lookupSym($2,0);
											if(lvalueCheckSym(ptr,0,yylineno)){
												printf("ERROR there is no global var %s\n",$2);	
											}else{
												if(ptr->declLine == 0){

												}
												/*TODO: print symbol data*/
											}	
										}
			|member 					{printf("lvalue: member in line:%d\n",yylineno);}
			;

member:		lvalue '.' ID 				{printf("member: lvalue.ID in line:%d\n",yylineno);}
			|lvalue '[' expr ']' 		{printf("member: lvalue [expr] in line:%d\n",yylineno);}
			|call '.' ID 				{printf("member: call.ID in line:%d\n",yylineno);}
			call '[' expr ']' 			{printf("member: call [expr] in line:%d\n",yylineno);}
			;

call: 		call '(' elist ')' 			{printf("call: (elist) in line:%d\n",yylineno);}
			|lvalue callsuffix			{printf("call: lvalue callsuffix in line:%d\n",yylineno);}
			|'(' funcdef ')' '(' elist ')' {printf("call: (func) (elist) in line:%d\n",yylineno);}
			;

callsuffix:	normcall					{printf("callsuffix: normcall in line:%d\n",yylineno);}
			|methodcall 				{printf("callsuffix: methodcall in line:%d\n",yylineno);}
			;

normcall:   '(' elist ')'				{printf("normcall: (elist) in line:%d\n",yylineno);}
			;

methodcall:	DOUPLEDOT ID '(' elist ')'  {printf("methodcall: DOUPLEDOT ID (elist) in line:%d\n",yylineno);}
			;

elist:		/*empty*/					{printf("elist: empty list in line:%d\n",yylineno);}
			|expr elist1 				{printf("elist: expr elist1 list in line:%d\n",yylineno);}
			;

elist1:		/*empty*/							{printf("elist1: empty list in line:%d\n",yylineno);}
			|','expr elist1 					{printf("elist1: ,expr elist1 in line:%d\n",yylineno);}
			;

objectdef:	'[' elist ']' 						{printf("objectdef: [elist] in line:%d\n",yylineno);}
			|'[' indexed ']'					{printf("objectdef: [indexed] in line:%d\n",yylineno);}
			;


indexed:	indexedelem more					{printf("indexed: indexedelem more in line:%d\n",yylineno);}
			;

more:       ',' indexedelem more 			{printf("more: ,indexedelem more in line:%d\n",yylineno);}
            |/*empty*/            			{printf("more: empty in line:%d\n",yylineno);}
            ; 
	

indexedelem:'{' expr ':' expr '}'			{printf("indexedelem: {expr:expr} in line:%d\n",yylineno);}
			;

block:		'{' {current_scope++;} stmt1 '}' {hideSym(current_scope--);}						{printf("block: {stmt1} in line:%d\n",yylineno);}		
             |'{''}' 							{printf("funcdefblock: {} in line:%d\n",yylineno);}
			;	

funcdef:	FUNCTION ID '('{current_scope++;} idlist ')' {current_scope--; scopeAccessStack.push(true);} block {scopeAccessStack.pop();} 	
												{
													printf("funcdef: FUNCTION ID (idlist) block in line:%d\n",yylineno);
													symTableEntry* ptr = lookupSym($2);
													/*TODO:take idlist argument list and pass it to insertSym*/
													if(ptr == NULL){
														insertSym($2,USER_FUNC,NULL,current_scope,yylineno);
													}else{
														printf("ERROR: Symbol %s already defined at line %d\n",$2,yylineno);
													}
												}
			| FUNCTION '('{current_scope++;} idlist ')' {current_scope--; scopeAccessStack.push(true);} block 
												{
													scopeAccessStack.pop();
													printf("funcdef: FUNCTION (idlist) block in line:%d\n",yylineno);
													
													std::string anonFunc = "_anonFunc" + std::to_string(anonymousCounter++);
													insertSym(anonFunc,USER_FUNC,NULL,current_scope,yylineno);
												}
			;

const:		NUMBER | STRING | NIL |TRUE|FALSE 	{printf("const: NUMBER | STRING | NIL |TRUE|FALSE in line:%d\n",yylineno);}
			;

idlist:		/*empty*/							{printf("idlist: empty in line:%d\n",yylineno);}
			|ID idlist1 						{
													printf("idlist: ID idlist1 in line:%d\n",yylineno);
													symTableEntry* ptr = lookupSym($1);
													if(lvalueCheckSym(ptr,current_scope,yylineno)){
										 				if( !ptr || (!scopeAccessStack.top() && ptr->symType != LOCAL_VAR && ptr->symType != ARGUMENT_VAR && (ptr->scope == current_scope || ptr->scope == 0))){
										 					insertSym($1,ARGUMENT_VAR,NULL,current_scope,yylineno);
										 				}else{
															printf("ERROR cannot access %s in scope %d\n",ptr->name, ptr->scope);
														}
										 			}
												}
			;

idlist1:	/*empty*/ 							{printf("idlist1: empty in line:%d\n",yylineno);}
			|',' ID idlist1 					{
													printf("idlist1: ,ID idlist1 in line:%d\n",yylineno);
													symTableEntry* ptr = lookupSym($2);
													if(lvalueCheckSym(ptr,current_scope,yylineno)){
										 				if( !ptr || (!scopeAccessStack.top() && ptr->symType != LOCAL_VAR && ptr->symType != ARGUMENT_VAR && (ptr->scope == current_scope || ptr->scope == 0))){
										 					insertSym($2,ARGUMENT_VAR,NULL,current_scope,yylineno);
										 				}else{
															printf("ERROR cannot access %s in scope %d\n",ptr->name, ptr->scope);
														}
										 			}
												}
			;

ifstmt:		IF '(' expr ')' stmt ifstmt1		{printf("ifstmt: IF (expr) stmt ifstmt1 in line:%d\n",yylineno);}
			;

ifstmt1:	/*empty*/							{printf("ifstmt1: empty in line:%d\n",yylineno);}
			|ELSE stmt 							{printf("ifstmt1: ELSE stmt in line:%d\n",yylineno);}
			;

whilestmt:	WHILE '(' expr ')' stmt 			{printf("whilestmt: WHILE (expr) stmt in line:%d\n",yylineno);}
			;

forstmt:	FOR '(' elist ';' expr ';' elist ')' stmt {printf("forstmt: FOR (elist;expr;elist) stmt in 								;											line:%d\n",yylineno);}

returnstmt:	RETURN ';' 							{printf("returnstmt: RETURN; in line:%d",yylineno);}
			|RETURN expr ';'					{printf("returnstmt: RETURN expr; in line:%d",yylineno);}
			;

%%

void yyerror(const char *yaccProvideMessage){
	fprintf(stdout,"%s: at line %d, before token: %s\n",yaccProvideMessage,yylineno,yytext);
	fprintf(stdout,"INPUT NOT VALID");

}