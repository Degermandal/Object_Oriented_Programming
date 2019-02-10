#ifndef POLYGON_H
#define POLYGON_H

#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Shape.h"


#include <iostream>
#include <vector>
#include <cstdlib>
#include <exception>

using std::vector;
using std::ostream;

/*
Polygon is an abstract class that derives from class Shape. PolygonVect and PolygonDyn are 
two concrete classes that derive from Polygon class. One of them uses STL vectors to keep the 2D points, 
the other uses dynamic memory to keep the 2D points.
*/

namespace _shape
{
	class Polygon : public Shape{
	public:

		class Point2D{
		private:
			double x;
			double y;

		public:
			//CONSTRUCTOR
			Point2D() : x(0), y(0){	}
			Point2D(double xx, double yy): x(xx), y(yy){	}
			//GETTER FUNCTION
			double getX() const { return x; }
			double getY()const { return y; }
			//SETTER FUNCTION
			void setX(double xx) { x = xx; }
			void setY(double yy) { y = yy; }

		};


	public:
		//CONSTRUCTOR
		Polygon() : Shape() {	}

		//Pure virtual implementation
		virtual double Area() const = 0;//{ cout<<"Polygon Area\n"; }
		virtual double Perimeter() const = 0;//override { cout<<"Polygon Perimter\n"; }

		//COMPARISON
		bool operator== (const Shape &p) const override;
		bool operator!= (const Shape &p) const override;	

	private:

	};

ostream& operator<< (ostream &out, const Polygon &p);


} 
#endif 