Lab09: main.o Menu.o MinSkewHeap.o Node.o
	g++ -std=c++11 main.o Menu.o MinSkewHeap.o Node.o -o Lab09
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
Menu.o: Menu.cpp Menu.h
	g++ -std=c++11 -c Menu.cpp
MinSkewHeap.o: MinSkewHeap.cpp MinSkewHeap.h
	g++ -std=c++11 -c MinSkewHeap.cpp
Node.o: Node.cpp Node.h
	g++ -std=c++11 -c Node.cpp
clean:
	rm -f test *.o