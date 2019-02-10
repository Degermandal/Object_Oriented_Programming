#ifndef POLYGON_H
#define POLYGON_H

#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"

//#define PI 3.14

#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
//using std::cout;
//using std::istream;
using std::ostream;

namespace Shape
{
	class Polygon{
	
	public:
		class Point2D{
		private:
			double x;
			double y;

		public:
			//CONSTRUCTOR
			Point2D();
			Point2D(double xx, double yy);
			//GETTER FUNCTION
			double getX() const { return x; }
			double getY()const { return y; }
			//SETTER FUNCTION
			void setX(double xx) { x = xx; }
			void setY(double yy) { y = yy; }

		};


	public:
		//CONSTRUCTOR
		Polygon();
		Polygon(int cap);
		//GETTER FUNCTION
		int getUsed() const {return polArUsed; }
		int getCapacity() const { return polArCapacity; }
		//SETTER FUNCTION
		void setUsed(int us);
		void setCapacity(int cp);

		Polygon(vector < Point2D > vec);
		Polygon(Point2D p2d);
		Polygon(Circle &c);
		Polygon(Triangle &t);
		Polygon(Rectangle &r);
		//BIG THREE
		~Polygon( );
		Polygon& operator =(const Polygon& rightSide);
		Polygon(const Polygon& copy);
		//INDEX OPERATOR
		Point2D* getIndex() { return polAr;}
		Point2D& operator[](int index)
		{
			return getIndex()[index];
		}


		//COMPARISON
		friend bool operator== (const Polygon &p1, const Polygon &p2);
		friend bool operator!= (const Polygon &p1, const Polygon &p2);	
		Polygon operator+(const Polygon& obj) const;

		friend ostream& operator<< (ostream &out, const Polygon &p1);

		vector<double> getPolAr();//PolAr arrayimdeki verileri vektore atmak icin yaptigim fonksiyon

		Point2D objP2d;

	private:
		
		Point2D *polAr;
		int polArCapacity;
		int polArUsed;

	};

} 
#endif 