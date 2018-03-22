%{
	#include <stdlib.h>
	#include <stdio.h>
	int yyerror (char *yaccProvidedMessage);
	int yylex(void);

	extern int yylineno;
	extern char* yytext;
	extern FILE* yyin;

%}

%expect 1
%start 	program

%union {
	char* stringValue;
	float floatValue;
	//symbol_t entry* ptr pointer se struct tou symbol_t
}

%token <stringValue> ID 
%token <floatValue> NUMBER
%token <stringValue> STRING 
%token BREAK CONTINUE AND OR NOT GREATEREQUAL LESSEQUAL EQUAL NOTEQUAL  PLUSPLUS MINUSMINUS LOCAL SCOPEOP DOUPLEDOT FUNCTION NIL TRUE FALSE IF ELSE WHILE FOR RETURN

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

program:	stmt1						{printf("Program started");}
			|/*empty*/					{printf("Program did not start");}
			;

stmt1:		stmt1 stmt
            |stmt
			;

stmt:		expr ';' 					{printf("stmt:Expression with ';' in line:%d",yylineno);}
			|ifstmt 					{printf("stmt:ifstmt starts in line:%d",yylineno);}
			|whilestmt 					{printf("stmt:whilestmt starts in line:%d",yylineno);}
			|forstmt 					{printf("stmt:forstmt starts in line:%d",yylineno);}
			|returnstmt 				{printf("stmt:returnstmt starts in line:%d",yylineno);}
			|BREAK ';' 					{printf("stmt:Break with ';' in line:%d",yylineno);}
			|CONTINUE ';'				{printf("stmt:Continue with ';' in line:%d",yylineno);}
			|block 						{printf("stmt:block starts in line:%d",yylineno);}
			|funcdef					{printf("stmt:funcdef starts in line:%d",yylineno);}
			|';'						{printf("stmt:SEMICOLON in line:%d",yylineno);}
			;

expr:		assignexpr 					{printf("expr:assignexpr in line:%d",yylineno);}
			|expr '+' expr 				{printf("expr:expr + expr in line:%d",yylineno);}
			|expr '-' expr 				{printf("expr:expr - expr in line:%d",yylineno);}
			|expr '*' expr 				{printf("expr:expr * expr in line:%d",yylineno);}
			|expr '/' expr 				{printf("expr:expr / expr in line:%d",yylineno);}
			|expr '%' expr 				{printf("expr:expr % expr in line:%d",yylineno);}
			|expr '>' expr 				{printf("expr:expr > expr in line:%d",yylineno);}
			|expr '<' expr 				{printf("expr:expr < expr in line:%d",yylineno);}
			|expr GREATEREQUAL expr 	{printf("expr:expr >= expr in line:%d",yylineno);}
			|expr LESSEQUAL expr 		{printf("expr:expr <= expr in line:%d",yylineno);}
			|expr EQUAL expr 			{printf("expr:expr ==(EQUAL) expr in line:%d",yylineno);}
			|expr NOTEQUAL expr 		{printf("expr:expr != expr in line:%d",yylineno);}
			|expr AND expr 				{printf("expr:expr AND expr in line:%d",yylineno);}
			|expr OR expr 				{printf("expr:expr OR expr in line:%d",yylineno);}
			|term						{printf("expr:term in line:%d",yylineno);}
			;



term: 		'('expr ')' 				{printf("term:(expr) in line:%d",yylineno);}
			| '-' expr %prec UMINUS		{{printf("term:-expr in line:%d",yylineno);}}
			| NOT expr 					{printf("term:!expr in line:%d",yylineno);}
			|PLUSPLUS lvalue 			{printf("term:++lvalue in line:%d",yylineno);}
			|lvalue PLUSPLUS 			{printf("term:lvalue++ in line:%d",yylineno);}
			|MINUSMINUS lvalue 			{printf("term:--lvalue in line:%d",yylineno);}
			|lvalue MINUSMINUS 			{printf("term:lvalue-- in line:%d",yylineno);}
			|primary 					{printf("term:primary in line:%d",yylineno);}
			;

assignexpr:	lvalue '=' expr 			{printf("assignexpr:lvalue=expr in line:%d",yylineno);}
			;

primary:	lvalue 						{printf("primary: lvalue in line:%d",yylineno);}
			|call 						{printf("primary: call in line:%d",yylineno);}
			|objectdef 					{printf("primary: objectdef in line:%d",yylineno);}
			|'(' funcdef ')'            {printf("primary: (funcdef) in line:%d",yylineno);}
			|const 						{printf("primary: const in line:%d",yylineno);}
			;

lvalue: 	ID 							{printf("lvalue: ID in line:%d",yylineno);}
			|LOCAL ID 					{printf("lvalue: LOCAL ID in line:%d",yylineno);}
			|SCOPEOP ID 				{printf("lvalue: SCOPE ID in line:%d",yylineno);}
			|member 					{printf("lvalue: member in line:%d",yylineno);}
			;

member:		lvalue '.' ID 				{printf("member: lvalue.ID in line:%d",yylineno);}
			|lvalue '[' expr ']' 		{printf("member: lvalue [expr] in line:%d",yylineno);}
			|call '.' ID 				{printf("member: call.ID in line:%d",yylineno);}
			call '[' expr ']' 			{printf("member: call [expr] in line:%d",yylineno);}
			;

call: 		call '(' elist ')' 			{printf("call: (elist) in line:%d",yylineno);}
			|lvalue callsuffix			{printf("call: lvalue callsuffix in line:%d",yylineno);}
			|'(' funcdef ')' '(' elist ')' {printf("call: (func) (elist) in line:%d",yylineno);}
			;

callsuffix:	normcall					{printf("callsuffix: normcall in line:%d",yylineno);}
			|methodcall 				{printf("callsuffix: methodcall in line:%d",yylineno);}
			;

normcall:   '(' elist ')'				{printf("normcall: (elist) in line:%d",yylineno);}
			;

methodcall:	DOUPLEDOT ID '(' elist ')'  {printf("methodcall: DOUPLEDOT ID (elist) in line:%d",yylineno);}
			;

elist:		/*empty*/					{printf("elist: empty list in line:%d",yylineno);}
			|expr elist1 				{printf("elist: expr elist1 list in line:%d",yylineno);}
			;

elist1:		/*empty*/							{printf("elist1: empty list in line:%d",yylineno);}
			|','expr elist1 					{printf("elist1: ,expr elist1 in line:%d",yylineno);}
			;

objectdef:	'[' elist ']' 						{printf("objectdef: [elist] in line:%d",yylineno);}
			|'[' indexed ']'					{printf("objectdef: [indexed] in line:%d",yylineno);}
			;


indexed:	indexedelem more					{printf("indexed: indexedelem more in line:%d",yylineno);}
			;

more:       ',' indexedelem more 			{printf("more: ,indexedelem more in line:%d",yylineno);}
            |/*empty*/            			{printf("more: empty in line:%d",yylineno);}
            ; 
	

indexedelem:'{' expr ':' expr '}'			{printf("indexedelem: {expr:expr} in line:%d",yylineno);}
			;

block:		'{' stmt1'}'						{printf("block: {stmt1} in line:%d",yylineno);}		
             |'{''}' 							{printf("block: {} in line:%d",yylineno);}
			;	

funcdef:	FUNCTION ID '(' idlist ')' block 	{printf("funcdef: FUNCTION ID (idlist) block in line:%d",yylineno);}
			| FUNCTION '(' idlist ')' block 	{printf("funcdef: FUNCTION (idlist) block in line:%d",yylineno);}
			;

const:		NUMBER | STRING | NIL |TRUE|FALSE 	{printf("const: NUMBER | STRING | NIL |TRUE|FALSE in line:%d",yylineno);}
			;

idlist:		/*empty*/							{printf("idlist: empty in line:%d",yylineno);}
			|ID idlist1 						{printf("idlist: ID idlist1 in line:%d",yylineno);}
			;

idlist1:	/*empty*/ 							{printf("idlist1: empty in line:%d",yylineno);}
			|',' ID idlist1 					{printf("idlist1: ,ID idlist1 in line:%d",yylineno);}
			;

ifstmt:		IF '(' expr ')' stmt ifstmt1		{printf("ifstmt: IF (expr) stmt ifstmt1 in line:%d",yylineno);}
			;

ifstmt1:	/*empty*/							{printf("ifstmt1: empty in line:%d",yylineno);}
			|ELSE stmt 							{printf("ifstmt1: ELSE stmt in line:%d",yylineno);}
			;

whilestmt:	WHILE '(' expr ')' stmt 			{printf("whilestmt: WHILE (expr) stmt in line:%d",yylineno);}
			;

forstmt:	FOR '(' elist ';' expr ';' elist ')' stmt {printf("forstmt: FOR (elist;expr;elist) stmt in 								;											line:%d",yylineno);}

returnstmt:	RETURN ';' 							{printf("returnstmt: RETURN; in line:%d",yylineno);}
			|RETURN expr ';'					{printf("returnstmt: RETURN expr; in line:%d",yylineno);}
			;

%%

int yyerror(char *yaccProvideMessage){
	fprintf(stdout,"%s: at line %d, before token: %s\n",yaccProvideMessage,yylineno,yytext);
	fprintf(stdout,"INPUT NOT VALID");

}