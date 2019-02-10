#ifndef POLYGONVECT_H
#define POLYGONVECT_H

#include "Polygon.h"
using namespace std;
#include <vector>
#include <exception>
#include "Exception.h"


namespace _shape{

	class PolygonVect : public Polygon{
	public:
		PolygonVect();
		PolygonVect(Polygon::Point2D& v2d);
		PolygonVect(Shape *s);

		double Area() const override { cout<<"PolygonVect Area\n"; }
		double Perimeter() const override { cout<<"PolygonVect Perimter\n"; }

		bool operator== (const Shape &pd) const override;
		bool operator!= (const Shape &pd) const override;

		vector<Polygon::Point2D*> getVec() const;

	private:
		vector<Polygon::Point2D*> vec2D;

	};

	ostream& operator<< (ostream &out, const PolygonVect &pv);
}
#endif