all: fl main 
main: 
	g++ lex.yy.cc -o scanner 
fl:  
	flex --c++ keywords.l 
clean: 
	rm -rf lex.yy.cc scanner 
