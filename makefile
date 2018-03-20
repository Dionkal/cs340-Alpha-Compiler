all:clean fl main 
main: 
	g++ lex.yy.cc  -o scanner 
fl:  
	flex --c++ keywords.l
bi:
	bison --yacc --defines --output=parser.c -v syntax.y 
clean: 
	rm -rf lex.yy.cc scanner 
