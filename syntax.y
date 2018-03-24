%{
	#include <stdlib.h>
	#include <stdio.h>
	void yyerror (const char *yaccProvidedMessage);
	extern int yylex(void);
	unsigned int scope=0;
	int k=0;

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

program:	stmt1						{k++; printf("%d___",k); printf("Program started\n");}
			|/*empty*/					{k++; printf("%d___",k); printf("Program did not start\n");}
			;

stmt1:		stmt1 stmt
            |stmt
			;

stmt:		expr ';' 					{k++; printf("%d___",k); printf("stmt:Expression with ';' in line:%d\n",yylineno);}
			|ifstmt 					{k++; printf("%d___",k); printf("stmt:ifstmt starts in line:%d\n",yylineno);}
			|whilestmt 					{k++; printf("%d___",k); printf("stmt:whilestmt starts in line:%d\n",yylineno);}
			|forstmt 					{k++; printf("%d___",k); printf("stmt:forstmt starts in line:%d\n",yylineno);}
			|returnstmt 				{k++; printf("%d___",k); printf("stmt:returnstmt starts in line:%d\n",yylineno);}
			|BREAK ';' 					{k++; printf("%d___",k); printf("stmt:Break with ';' in line:%d\n",yylineno);}
			|CONTINUE ';'				{k++; printf("%d___",k); printf("stmt:Continue with ';' in line:%d\n",yylineno);}
			|block 						{k++; printf("%d___",k); printf("stmt:block starts in line:%d\n",yylineno);}
			|funcdef					{k++; printf("%d___",k); printf("stmt:funcdef starts in line:%d\n",yylineno);}
			|';'						{k++; printf("%d___",k); printf("stmt:SEMICOLON in line:%d\n",yylineno);}
			;

expr:		assignexpr 					{k++; printf("%d___",k); printf("expr:assignexpr in line:%d\n",yylineno);}
			|expr '+' expr 				{k++; printf("%d___",k); printf("expr:expr + expr in line:%d\n",yylineno);}
			|expr '-' expr 				{k++; printf("%d___",k); printf("lexpr:expr - expr in line:%d\n",yylineno);}
			|expr '*' expr 				{k++; printf("%d___",k); printf("expr:expr * expr in line:%d\n",yylineno);}
			|expr '/' expr 				{k++; printf("%d___",k); printf("expr:expr / expr in line:%d\n",yylineno);}
			|expr '%' expr 				{k++; printf("%d___",k); printf("expr:expr mod expr in line:%d\n",yylineno);}
			|expr '>' expr 				{k++; printf("%d___",k); printf("expr:expr > expr in line:%d\n",yylineno);}
			|expr '<' expr 				{k++; printf("%d___",k); printf("expr:expr < expr in line:%d\n",yylineno);}
			|expr GREATEREQUAL expr 	{k++; printf("%d___",k); printf("expr:expr >= expr in line:%d\n",yylineno);}
			|expr LESSEQUAL expr 		{k++; printf("%d___",k); printf("expr:expr <= expr in line:%d\n",yylineno);}
			|expr EQUAL expr 			{k++; printf("%d___",k); printf("expr:expr ==(EQUAL) expr in line:%d\n",yylineno);}
			|expr NOTEQUAL expr 		{k++; printf("%d___",k); printf("expr:expr != expr in line:%d\n",yylineno);}
			|expr AND expr 				{k++; printf("%d___",k); printf("expr:expr AND expr in line:%d\n",yylineno);}
			|expr OR expr 				{k++; printf("%d___",k); printf("expr:expr OR expr in line:%d\n",yylineno);}
			|term						{k++; printf("%d___",k); printf("expr:term in line:%d\n",yylineno);}
			;



term: 		'('expr ')' 				{k++; printf("%d___",k); printf("term:(expr) in line:%d\n",yylineno);}
			| '-' expr %prec UMINUS		{k++; printf("%d___",k); {printf("term:-expr in line:%d\n",yylineno);}}
			| NOT expr 					{k++; printf("%d___",k); printf("term:!expr in line:%d\n",yylineno);}
			|PLUSPLUS lvalue 			{k++; printf("%d___",k); printf("term:++lvalue in line:%d\n",yylineno);}
			|lvalue PLUSPLUS 			{k++; printf("%d___",k); printf("term:lvalue++ in line:%d\n",yylineno);}
			|MINUSMINUS lvalue 			{k++; printf("%d___",k); printf("term:--lvalue in line:%d\n",yylineno);}
			|lvalue MINUSMINUS 			{k++; printf("%d___",k); printf("term:lvalue-- in line:%d\n",yylineno);}
			|primary 					{k++; printf("%d___",k); printf("term:primary in line:%d\n",yylineno);}
			;

assignexpr:	lvalue '=' expr 			{k++; printf("%d___",k); printf("assignexpr:lvalue=expr in line:%d\n",yylineno);}
			;

primary:	lvalue 						{k++; printf("%d___",k); printf("primary: lvalue in line:%d\n",yylineno);}
			|call 						{k++; printf("%d___",k); printf("primary: call in line:%d\n",yylineno);}
			|objectdef 					{k++; printf("%d___",k); printf("primary: objectdef in line:%d\n",yylineno);}
			|'(' funcdef ')'            {k++; printf("%d___",k); printf("primary: (funcdef) in line:%d\n",yylineno);}
			|const 						{k++; printf("%d___",k); printf("primary: const in line:%d\n",yylineno);}
			;

lvalue: 	ID 							{k++; printf("%d___",k); printf("lvalue: ID in line:%d\n",yylineno);}
			|LOCAL ID 					{k++; printf("%d___",k); printf("lvalue: LOCAL ID in line:%d\n",yylineno);}
			|SCOPEOP ID 				{k++; printf("%d___",k); printf("lvalue: SCOPE ID in line:%d\n",yylineno);}
			|member 					{k++; printf("%d___",k); printf("lvalue: member in line:%d\n",yylineno);}
			;

member:		lvalue '.' ID 				{k++; printf("%d___",k); printf("member: lvalue.ID in line:%d\n",yylineno);}
			|lvalue '[' expr ']' 		{k++; printf("%d___",k); printf("member: lvalue [expr] in line:%d\n",yylineno);}
			|call '.' ID 				{k++; printf("%d___",k); printf("member: call.ID in line:%d\n",yylineno);}
			call '[' expr ']' 			{k++; printf("%d___",k); printf("member: call [expr] in line:%d\n",yylineno);}
			;

call: 		call '(' elist ')' 			{k++; printf("%d___",k); printf("call: (elist) in line:%d\n",yylineno);}
			|lvalue callsuffix			{k++; printf("%d___",k); printf("call: lvalue callsuffix in line:%d\n",yylineno);}
			|'(' funcdef ')' '(' elist ')' {k++; printf("%d___",k); printf("call: (func) (elist) in line:%d\n",yylineno);}
			;

callsuffix:	normcall					{k++; printf("%d___",k); printf("callsuffix: normcall in line:%d\n",yylineno);}
			|methodcall 				{k++; printf("%d___",k); printf("callsuffix: methodcall in line:%d\n",yylineno);}
			;

normcall:   '(' elist ')'				{k++; printf("%d___",k); printf("normcall: (elist) in line:%d\n",yylineno);}
			;

methodcall:	DOUPLEDOT ID '(' elist ')'  {k++; printf("%d___",k); printf("methodcall: DOUPLEDOT ID (elist) in line:%d\n",yylineno);}
			;

elist:		/*empty*/					{k++; printf("%d___",k); printf("elist: empty list in line:%d\n",yylineno);}
			|expr elist1 				{k++; printf("%d___",k); printf("elist: expr elist1 list in line:%d\n",yylineno);}
			;

elist1:		/*empty*/							{k++; printf("%d___",k); printf("elist1: empty list in line:%d\n",yylineno);}
			|','expr elist1 					{k++; printf("%d___",k); printf("elist1: ,expr elist1 in line:%d\n",yylineno);}
			;

objectdef:	'[' elist ']' 						{k++; printf("%d___",k); printf("objectdef: [elist] in line:%d\n",yylineno);}
			|'[' indexed ']'					{k++; printf("%d___",k); printf("objectdef: [indexed] in line:%d\n",yylineno);}
			;


indexed:	indexedelem more					{k++; printf("%d___",k); printf("indexed: indexedelem more in line:%d\n",yylineno);}
			;

more:       ',' indexedelem more 			{k++; printf("%d___",k); printf("more: ,indexedelem more in line:%d\n",yylineno);}
            |/*empty*/            			{k++; printf("%d___",k); printf("more: empty in line:%d\n",yylineno);}
            ; 
	

indexedelem:'{' expr ':' expr '}'			{k++; printf("%d___",k); printf("indexedelem: {expr:expr} in line:%d\n",yylineno);}
			;

block:		'{' stmt1'}'					{k++; printf("%d___",k); printf("block: {stmt1} in line:%d\n",yylineno);}		
             |'{'  '}' {k++; printf("%d___",k); printf("block: {} in line:%d\n",yylineno);}
			;	

funcdef:	FUNCTION ID '('  idlist ')'  block 	{k++; printf("%d___",k); printf("funcdef: FUNCTION ID (idlist) block in line:%d\n",yylineno);}
			| FUNCTION '(' idlist ')' block 	{k++; printf("%d___",k); printf("funcdef: FUNCTION (idlist) block in line:%d\n",yylineno);}
			;

const:		NUMBER | STRING | NIL |TRUE|FALSE 	{k++; printf("%d___",k); printf("const: NUMBER | STRING | NIL |TRUE|FALSE in line:%d\n",yylineno);}
			;

idlist:		/*empty*/							{k++; printf("%d___",k); printf("idlist: empty in line:%d\n",yylineno);}
			|ID idlist1 						{k++; printf("%d___",k); printf("idlist: ID idlist1 in line:%d\n",yylineno);}
			;

idlist1:	/*empty*/ 							{k++; printf("%d___",k); printf("idlist1: empty in line:%d\n",yylineno);}
			|',' ID idlist1 					{k++; printf("%d___",k); printf("idlist1: ,ID idlist1 in line:%d\n",yylineno);}
			;

ifstmt:		IF '(' expr ')' stmt ifstmt1		{k++; printf("%d___",k); printf("ifstmt: IF (expr) stmt ifstmt1 in line:%d\n",yylineno);}
			;

ifstmt1:	/*empty*/							{k++; printf("%d___",k); printf("ifstmt1: empty in line:%d\n",yylineno);}
			|ELSE stmt 							{k++; printf("%d___",k); printf("ifstmt1: ELSE stmt in line:%d\n",yylineno);}
			;

whilestmt:	WHILE '(' expr ')' stmt 			{k++; printf("%d___",k); printf("whilestmt: WHILE (expr) stmt in line:%d\n",yylineno);}
			;

forstmt:	FOR '(' elist ';' expr ';' elist ')' stmt {k++; printf("%d___",k); printf("forstmt: FOR (elist;expr;elist) stmt in 								;											line:%d\n",yylineno);}

returnstmt:	RETURN ';' 							{k++; printf("%d___",k); printf("returnstmt: RETURN; in line:%d",yylineno);}
			|RETURN expr ';'					{k++; printf("%d___",k); printf("returnstmt: RETURN expr; in line:%d",yylineno);}
			;

%%

void yyerror(const char *yaccProvideMessage){
	fprintf(stdout,"%s: at line %d, before token: %s\n",yaccProvideMessage,yylineno,yytext);
	fprintf(stdout,"INPUT NOT VALID");

}
