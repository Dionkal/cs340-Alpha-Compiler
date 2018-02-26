#include <stdio.h>
#include "scanner.h"

extern int yylex();
extern int yylineno;
extern char* yytext;


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
