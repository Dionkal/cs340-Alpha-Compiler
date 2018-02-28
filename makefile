all: fl main
main:
	g++ lex.yy.c -o scanner
fl: 
	flex  keywords.l
clean:
	rm -rf lex.yy.c scanner
