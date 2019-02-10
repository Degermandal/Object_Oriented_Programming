all: begin

begin: __main.o Rectangle.o Triangle.o Circle.o ComposedShape.o
	  g++ __main.o Rectangle.o Triangle.o Circle.o ComposedShape.o -o exe
	 ./exe

__main.o: __main.cpp
	g++ -std=c++11 -c __main.cpp

Rectangle.o: Rectangle.cpp
	g++ -std=c++11 -c Rectangle.cpp

Triangle.o: Triangle.cpp
	g++ -std=c++11 -c Triangle.cpp

Circle.o: Circle.cpp
	g++ -std=c++11 -c Circle.cpp

ComposedShape.o: ComposedShape.cpp
	g++ -std=c++11 -c ComposedShape.cpp


clean:
	rm *.o exe