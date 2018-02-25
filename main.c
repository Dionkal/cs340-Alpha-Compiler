#include <stdio.h>
#include "scanner.h"

extern int yylex();
extern int yylineno;
extern char* yytext;

char* names[] = {
NULL,
"KEYWORD IF",
"KEYWORD ELSE",
"KEYWORD WHILE",
"KEYWORD FOR",
"KEYWORD FUNCTION",
"KEYWORD RETURN",
"KEYWORD BREAK",
"KEYWORD CONTINUE",
"KEYWORD AND",
"KEYWORD NOT",
"KEYWORD OR",
"KEYWORD LOCAL",
"KEYWORD TRUE",
"KEYWORD FALSE",
"KEYWORD NIL",
"OPERATOR ASSIGNMENT",
"OPERATOR PLUS",
"OPERATOR MINUS",
"OPERATOR PRODUCT",
"OPERATOR DIVIDE",
"OPERATOR PERCENT",
"OPERATOR EQUALS",
"OPERATOR NOT_OP",
"OPERATOR D_PLUS",
"OPERATOR D_MINUS",
"OPERATOR GREATER",
"OPERATOR LESS",
"OPERATOR G_EQUAL",
"OPERATOR L_EQUAL",
"IDENTIFIER"
};

int main(void) {
  int token;
  int token_count = 0;

  while ((token = yylex())) {
    token_count++;
    if (token >= 0) {
      printf("%d: ", yylineno);     /*line number*/
      printf("#%d ", token_count);  /*number of token*/
      printf("\"%s\"\t\t", yytext);   /*token container*/
      printf("%s\n", names[token]); /*type of token*/
    }else{
    	printf("Invalid token \"%s\" on line %d",yytext,yylineno);
    }
  }

  return 0;
}
