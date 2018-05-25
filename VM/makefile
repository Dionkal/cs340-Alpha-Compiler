main: avm.o avm_table.o
	g++ -g -Wall avm.cpp avm_table.o initVM.o -o avm
avm.o: avm.cpp avm_table.h
	g++ -g -Wall -c avm.cpp
avm_table.o: avm_table.cpp avm.h
	g++ -g -Wall -c avm_table.cpp 
initVM.o: initVM.cpp
	g++ -g -Wall -c initVM.cpp
clean:
	rm -rf avm *.o
