all: begin

begin: 161044096_main.o Collection.o Set.o List.o Queue.o HashSet.o ArrayList.o LinkedList.o
	  g++ 161044096_main.o Collection.o Set.o List.o Queue.o HashSet.o ArrayList.o LinkedList.o -o exe
	 ./exe

161044096_main.o: 161044096_main.cpp
	g++ -std=c++11 -c 161044096_main.cpp

Collection.o: Collection.cpp
	g++ -std=c++11 -c Collection.cpp

Set.o: Set.cpp
	g++ -std=c++11 -c Set.cpp

HashSet.o: HashSet.cpp
	g++ -std=c++11 -c HashSet.cpp

List.o: List.cpp
	g++ -std=c++11 -c List.cpp

ArrayList.o: ArrayList.cpp
	g++ -std=c++11 -c ArrayList.cpp

Queue.o: Queue.cpp
	g++ -std=c++11 -c Queue.cpp

LinkedList.o: LinkedList.cpp
	g++ -std=c++11 -c LinkedList.cpp


clean:
	rm *.o exe