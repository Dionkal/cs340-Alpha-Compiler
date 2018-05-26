all:clean bi fl main 
main: 
	g++  -std=c++11 -g -Wall lex.yy.c generateInstrFunc.cpp vmargs.cpp parser.c quad.cpp symbolActions.cpp symbolUtilities.cpp jumplists.cpp -o scanner 
fl:  
	flex  keywords.l
bi:
	bison --yacc --defines --output=parser.c -v syntax.y 
clean: 
	rm -rf lex.yy.c parser.c parser.output scanner 
