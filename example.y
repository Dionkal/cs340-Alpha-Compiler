%{/*prologos*/
#include <stdio.h>
int yyerror (char *yaccProvidedMessage);
int yylex(void);

extern int yylineno;
extern char* yytext;
extern FILE* yyin;

%union{/*den ksero p prepei na mpei auto*/
	char *stringValue;
	int intValue;
}/*this is needed for lex actions*/

%}

/*diloseis yacc*/
%start 			program

%token <stringValue> ID
%token <intValue> INTEGER


%right			'='
%left			'+' '-'
%left			'*' '/'
%nonassoc			UNIMUS
%left 			'(' ')'

%type <intValue> expression
%type	<stringValue> assignment 
%type <stringValue> assignments
%type <intValue> expr
%type <intValue> expressions

/*%destructor (free($$);)	ID*/

%%
/*perigrafi grammatikis*/
program:		assignments expressions {;}
				| /*empty*/ {;}
				;

expression:		INTEGER {$$=$1;}
				| ID {printf("Found ID\n");}/*or: {$$=lookup($1); free($1);}*/
				| expression '+' expression {$$=$1+$3;}
				| expression '-' expression {$$=$1-$3;}
				| expression '*' expression {$$=$1*$3;}
				| expression '/' expression {$$=$1/$3;}
				| '(' expression ')' {$$=$2;}/*dunno y, etsi to xei sto front*/
				| '-' expression %prec UNIMUS {$$=$2;}/*same*/
				;
expr:			expression ';' {fprintf(stdout, "Result is %d\n", $1);}

expressions:	expressions expr {;}
				| expr {;}
				;

assignment:		ID '=' expression ';' {assign ($1,$3);}
				;

assignments:	assignments	assignment {;}
				| /*empty*/ {;}
				;
%%

/*epilogos*/
int yyerror (char* yaccProvidedMessage){
	fprintf(stderr,"%s: at line %d,before token: %s\n",yaccPrividedMessage,yylineno,yytext);
	fprintf(stderr, "INPUT NOT VALID\n");
}

int main(int argc,char**argv){
	if(argc>1){
		if(!(yyin=fopen(argv[1],"r"))){
			fprintf(stderr, "Cannot read file: %s\n",argv[1] );
	
			return 1;
		}else{
			yyin=stdin;
		}
		yyparse();
		return 0;
	}

}