#ifndef POLYLINE_H
#define POLYLINE_H

#include "Polygon.h"

#include <iostream>
using std::ostream;

namespace Shape
{
	class Polyline{
	public:
		Polyline(Polygon pol);
		Polyline() {	}
		friend ostream& operator<< (ostream &out, const Polyline &p1);

		~Polyline( );
		Polyline& operator =(const Polyline& rightSide);
		Polyline(const Polyline& copy);

		int getUsed() const {return PlArUsed; }
		int getCapacity() const { return PlArCap; }

		void setUsed(int us);
		void setCapacity(int cp);

	private:
		Polygon poly;
		double *PlAr;
		int PlArUsed;
		int PlArCap;

	};

} 
#endif 