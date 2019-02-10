#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <cstdlib>
#include "Exception.h"

using std::ostream;
using std::cout;
using std::endl;

namespace _shape{

class Shape{
public:
	Shape();
	Shape(double xx, double yy);

	inline double getShapeX() const {return x;}
	inline double getShapeY() const {return y;}
protected:
	void setShapeX(double xx);
	void setShapeY(double yy);

public:
	virtual double Area() const = 0;
	virtual double Perimeter() const = 0;

	virtual Shape& operator++(); //pre
	virtual Shape& operator--();
	virtual Shape& operator++(int); //post
	virtual Shape& operator--(int);

	virtual bool operator==(const Shape &s) const;
	virtual bool operator!=(const Shape &s) const;
	virtual bool operator>(const Shape &s) const;
	virtual bool operator<(const Shape &s) const;
	virtual bool operator>=(const Shape &s) const;
	virtual bool operator<=(const Shape &s) const;

private:
	double x;
	double y; 
};

ostream& operator<<(ostream &svgFile, const Shape &s);

}
#endif