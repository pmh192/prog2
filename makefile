all: main

test: test.o union_find.o graph.o
	g++ -std=c++11 test.o union_find.o graph.o -o test_bin && ./test_bin

test.o: test.cpp
	g++ -std=c++11 -c test.cpp

graph.o: graph.cpp
	g++ -std=c++11 -c graph.cpp

union_find.o: union_find.cpp
	g++ -std=c++11 -c union_find.cpp

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

main: main.o graph.o
	g++ -std=c++11 graph.o main.o -o prog2


clean:
	rm -f *.o prog2 test_bin
