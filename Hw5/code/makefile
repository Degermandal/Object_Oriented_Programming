all: begin

begin: 161044096_main.o Shape.o Rectangle.o Triangle.o Circle.o ComposedShape.o Polygon.o PolygonVect.o PolygonDyn.o 
	  g++ 161044096_main.o Shape.o Rectangle.o Triangle.o Circle.o ComposedShape.o Polygon.o PolygonVect.o PolygonDyn.o  -o exe
	 ./exe

161044096_main.o: 161044096_main.cpp
	g++ -std=c++11 -c 161044096_main.cpp

Shape.o: Shape.cpp
	g++ -std=c++11 -c Shape.cpp

Rectangle.o: Rectangle.cpp
	g++ -std=c++11 -c Rectangle.cpp

Triangle.o: Triangle.cpp
	g++ -std=c++11 -c Triangle.cpp

Circle.o: Circle.cpp
	g++ -std=c++11 -c Circle.cpp

ComposedShape.o: ComposedShape.cpp
	g++ -std=c++11 -c ComposedShape.cpp

Polygon.o: Polygon.cpp
	g++ -std=c++11 -c Polygon.cpp

PolygonVect.o: PolygonVect.cpp
	g++ -std=c++11 -c PolygonVect.cpp

PolygonDyn.o: PolygonDyn.cpp
	g++ -std=c++11 -c PolygonDyn.cpp

clean:
	rm *.o exe