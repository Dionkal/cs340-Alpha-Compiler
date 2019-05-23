CC = gcc
CFLAGS =  -Wall -pedantic -std=c++11 -g

main: avm.o avm_table.o  ex_assign.o  execute_call.o execute_table.o toString.o initVM.o execute_nop.o ex_math.o ex_jumps.o libFuncs.o
	g++ -std=c++11 -g -Wall avm.o avm_table.o ex_assign.o execute_table.o execute_call.o initVM.o  execute_nop.o ex_math.o ex_jumps.o toString.o libFuncs.o -o avm
avm.o: avm.cpp avm_table.h
	g++ -std=c++11 -g -Wall -c avm.cpp
avm_table.o: avm_table.cpp avm.h
	g++ -std=c++11 -g -Wall -c avm_table.cpp
initVM.o: initVM.cpp
	g++ -std=c++11 -g -Wall -c initVM.cpp
ex_assign.o: ex_assign.cpp
	g++ -std=c++11 -g -Wall -c ex_assign.cpp
execute_call.o:	execute_call.cpp
	g++ -std=c++11 -g -Wall -c execute_call.cpp
execute_table.o: execute_table.cpp
	g++ -std=c++11 -g -Wall -c execute_table.cpp
toString.o: toString.cpp
	g++ -std=c++11 -g -Wall -c toString.cpp
ex_math.o: ex_math.cpp
	g++ -std=c++11 -g -Wall -c ex_math.cpp
ex_jumps.o: ex_jumps.cpp
	g++ -std=c++11 -g -Wall -c ex_jumps.cpp
execute_nop.o: execute_nop.cpp
	g++ -std=c++11 -g -Wall -c execute_nop.cpp
libFuncs.o: libFuncs.cpp
	g++ -std=c++11 -g -Wall -c libFuncs.cpp
clean:
	rm -rf avm *.o
