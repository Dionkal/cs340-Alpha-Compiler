all:clean bi fl main 
main: 
	g++ -Wall lex.yy.c parser.c quad.cpp symbolActions.cpp  -o scanner 
fl:  
	flex  keywords.l
bi:
	bison --yacc --defines --output=parser.c -v syntax.y 
clean: 
	rm -rf lex.yy.c parser.c parser.output scanner 
