all: main

test: test.o
	g++ -std=c++11 test.o -o test_bin && ./test_bin

test.o: test.cpp
	g++ -std=c++11 -c test.cpp

graph.o: graph.cpp
	g++ -std=c++11 -c graph.cpp

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

main: main.o graph.o
	g++ -std=c++11 graph.o main.o -o prog2


clean:
	rm -f *.o prog2 test_bin
