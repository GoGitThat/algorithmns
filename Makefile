test: test.o
	g++ -o -fsyntax-only test test.o
test.o: stack.o list.o
	g++ -c test.cpp
list.o: list.cpp structs.h
	g++ -c list.cpp
stack.o: stack.cpp structs.h
	g++ -c stack.cpp