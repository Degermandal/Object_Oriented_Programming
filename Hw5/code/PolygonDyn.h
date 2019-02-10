#ifndef POLYGONDYN_H
#define POLYGONDYN_H

#include "Polygon.h"
#include "Exception.h"
using namespace std;

namespace _shape{

	class PolygonDyn : public Polygon{
	public:
		//CONSTRUCTOR
		PolygonDyn();
		PolygonDyn(int capacity);
		PolygonDyn(Polygon::Point2D &p2d);
		PolygonDyn(Polygon::Point2D &p2d, Polygon::Point2D &pp2d, Polygon::Point2D &ppp2d);
		PolygonDyn(Shape *s);
		//GETTER FUNCTION
		inline int getUsed() const {return use; }
		inline int getCapacity() const { return cap; }
		//SETTER FUNCTION
		void setUsed(int us);
		void setCapacity(int cp);

		//BIG THREE
		~PolygonDyn( );
		PolygonDyn& operator =(const PolygonDyn& rightSide);
		PolygonDyn(const PolygonDyn& copy);

		//INDEX OPERATOR
		Polygon::Point2D* getIndex() { return dyn2D;}
		Polygon::Point2D& operator[](int index) {  return getIndex()[index]; }

		//Pure virtual implementation
		double Area() const override { cout<<"PolygonDyn Area\n"; }
		double Perimeter() const override { cout<<"PolygonDyn Perimter\n"; }

		//COMPARISON
		bool operator== (const Shape &pd) const override;
		bool operator!= (const Shape &pd) const override;	

		//helper functions
		Polygon::Point2D& getAr() const;

	private:		
		Point2D *dyn2D;
		int cap;
		int use;

	};

	ostream& operator<< (ostream &out, const PolygonDyn &pd);
}
#endif