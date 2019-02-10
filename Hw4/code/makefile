all: begin

begin: 161044096_main.o Rectangle.o Triangle.o Circle.o ComposedShape.o Polygon.o Polyline.o
	  g++ 161044096_main.o Rectangle.o Triangle.o Circle.o ComposedShape.o Polygon.o Polyline.o -o exe
	 ./exe

161044096_main.o: 161044096_main.cpp
	g++ -std=c++11 -c 161044096_main.cpp

Rectangle.o: Rectangle.cpp
	g++ -std=c++11 -c Rectangle.cpp

Triangle.o: Triangle.cpp
	g++ -std=c++11 -c Triangle.cpp

Circle.o: Circle.cpp
	g++ -std=c++11 -c Circle.cpp

Polygon.o: Polygon.cpp
	g++ -std=c++11 -c Polygon.cpp

Polyline.o: Polyline.cpp
	g++ -std=c++11 -c Polyline.cpp

ComposedShape.o: ComposedShape.cpp
	g++ -std=c++11 -c ComposedShape.cpp


clean:
	rm *.o exe