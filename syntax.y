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

program:	stmt1						{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("Program started\n");}
			|/*empty*/					{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("Program did not start\n");}
			;

stmt1:		stmt1 stmt
            |stmt
			;

stmt:		expr ';' 					{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("stmt:Expression with ';' in line:%d\n",yylineno);}
			|ifstmt 					{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("stmt:ifstmt starts in line:%d\n",yylineno);}
			|whilestmt 					{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("stmt:whilestmt starts in line:%d\n",yylineno);}
			|forstmt 					{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("stmt:forstmt starts in line:%d\n",yylineno);}
			|returnstmt 				{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("stmt:returnstmt starts in line:%d\n",yylineno);}
			|BREAK ';' 					{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("stmt:Break with ';' in line:%d\n",yylineno);}
			|CONTINUE ';'				{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("stmt:Continue with ';' in line:%d\n",yylineno);}
			|block 						{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("stmt:block starts in line:%d\n",yylineno);}
			|funcdef					{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("stmt:funcdef starts in line:%d\n",yylineno);}
			|';'						{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("stmt:SEMICOLON in line:%d\n",yylineno);}
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



term: 		'('expr ')' 				{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("term:(expr) in line:%d\n",yylineno);}
			| '-' expr %prec UMINUS		{k++; printf("time:%d___ ,token: %s____>",k,yytext); {printf("term:-expr in line:%d\n",yylineno);}}
			| NOT expr 					{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("term:!expr in line:%d\n",yylineno);}
			|PLUSPLUS lvalue 			{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("term:++lvalue in line:%d\n",yylineno);}
			|lvalue PLUSPLUS 			{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("term:lvalue++ in line:%d\n",yylineno);}
			|MINUSMINUS lvalue 			{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("term:--lvalue in line:%d\n",yylineno);}
			|lvalue MINUSMINUS 			{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("term:lvalue-- in line:%d\n",yylineno);}
			|primary 					{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("term:primary in line:%d\n",yylineno);}
			;

assignexpr:	lvalue '=' expr 			{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("assignexpr:lvalue=expr in line:%d\n",yylineno);}
			;

primary:	lvalue 						{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("primary: lvalue in line:%d\n",yylineno);}
			|call 						{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("primary: call in line:%d\n",yylineno);}
			|objectdef 					{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("primary: objectdef in line:%d\n",yylineno);}
			|'(' funcdef ')'            {k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("primary: (funcdef) in line:%d\n",yylineno);}
			|const 						{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("primary: const in line:%d\n",yylineno);}
			;

lvalue: 	ID 							{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("lvalue: ID in line:%d\n",yylineno);}
			|LOCAL ID 					{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("lvalue: LOCAL ID in line:%d\n",yylineno);}
			|SCOPEOP ID 				{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("lvalue: SCOPE ID in line:%d\n",yylineno);}
			|member 					{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("lvalue: member in line:%d\n",yylineno);}
			;

member:		lvalue '.' ID 				{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("member: lvalue.ID in line:%d\n",yylineno);}
			|lvalue '[' expr ']' 		{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("member: lvalue [expr] in line:%d\n",yylineno);}
			|call '.' ID 				{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("member: call.ID in line:%d\n",yylineno);}
			call '[' expr ']' 			{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("member: call [expr] in line:%d\n",yylineno);}
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

elist1:		/*empty*/							{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("elist1: empty list in line:%d\n",yylineno);}
			|','expr elist1 					{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("elist1: ,expr elist1 in line:%d\n",yylineno);}
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

block:		'{' stmt1'}'					{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("block: {stmt1} in line:%d\n",yylineno);}		
             |'{'  '}' {k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("block: {} in line:%d\n",yylineno);}
			;	

funcdef:	FUNCTION ID '('  idlist ')'  block 	{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("funcdef: FUNCTION ID (idlist) block in line:%d\n",yylineno);}
			| FUNCTION '(' idlist ')' block 	{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("funcdef: FUNCTION (idlist) block in line:%d\n",yylineno);}
			;

const:		NUMBER | STRING | NIL |TRUE|FALSE 	{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("const: NUMBER | STRING | NIL |TRUE|FALSE in line:%d\n",yylineno);}
			;

idlist:		/*empty*/							{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("idlist: empty in line:%d\n",yylineno);}
			|ID idlist1 						{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("idlist: ID idlist1 in line:%d\n",yylineno);}
			;

idlist1:	/*empty*/ 							{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("idlist1: empty in line:%d\n",yylineno);}
			|',' ID idlist1 					{k++; printf("time:%d___ ,token: %s____>",k,yytext); printf("idlist1: ,ID idlist1 in line:%d\n",yylineno);}
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
	fprintf(stdout,"INPUT NOT VALID");

}
