main: avm.o avm_table.o dispatch.o
	g++ -std=c++11 -g -Wall avm.o avm_table.o initVM.o dispatcher.o -o avm
avm.o: avm.cpp avm_table.h
	g++ -std=c++11 -g -Wall -c avm.cpp
avm_table.o: avm_table.cpp avm.h
	g++ -std=c++11 -g -Wall -c avm_table.cpp 
initVM.o: initVM.cpp
	g++ -std=c++11 -g -Wall -c initVM.cpp
dispatch.o: dispatcher.cpp
	g++ -std=c++11 -g -Wall -c dispatcher.cpp
clean:
	rm -rf avm *.o
