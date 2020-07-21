all: test ;
clean:
    rm -f test test.o
test: test.o
	g++ -o test test.o
test.o: stack.o list.o sorting.o
	g++ -c test.cpp
sorting.o: sorting.cpp
	g++ -c sorting.cpp
list.o: list.cpp structs.h
	g++ -c list.cpp
stack.o: stack.cpp structs.h
	g++ -c stack.cpp