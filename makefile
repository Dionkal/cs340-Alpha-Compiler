all:clean bi fl main 
main: 
	g++ lex.yy.c parser.c  -o scanner 
fl:  
	flex  keywords.l
bi:
	bison --yacc --defines --output=parser.c -v syntax.y 
clean: 
	rm -rf lex.yy.cc scanner 
