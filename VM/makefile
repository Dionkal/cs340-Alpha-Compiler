main: avm.o avm_table.o dispatch.o assign.o  execute_call.o initVM.o
	g++ -std=c++11 -g -Wall avm.o avm_table.o dispatcher.o ex_assign.o execute_table.o execute_call.o initVM.o  -o avm
avm.o: avm.cpp avm_table.h
	g++ -std=c++11 -g -Wall -c avm.cpp
avm_table.o: avm_table.cpp avm.h
	g++ -std=c++11 -g -Wall -c avm_table.cpp 
initVM.o: initVM.cpp
	g++ -std=c++11 -g -Wall -c initVM.cpp
dispatch.o: dispatcher.cpp
	g++ -std=c++11 -g -Wall -c dispatcher.cpp
assign.o: ex_assign.cpp
	g++ -std=c++11 -g -Wall -c ex_assign.cpp
execute_call.o:	execute_call.cpp
	g++ -std=c++11 -g -Wall -c execute_call.cpp
execute_table.o: execute_table.cpp
	g++ -std=c++11 -g -Wall -c execute_table.cpp
clean:
	rm -rf avm *.o