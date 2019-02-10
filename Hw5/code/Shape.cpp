#include "Shape.h"


namespace _shape{


ostream& operator<<(ostream &svgFile, const Shape &s)
{
	cout<<"Shape ostream operator called\n";
	svgFile<<"#########";
}


Shape::Shape(): x(0), y(0)
{
	//noparameter constructor
}

Shape::Shape(double xx, double yy) : x(xx), y(yy)
{
	if(xx>= 0)
		x = xx;
	else
	{
		throw Exception("Shape Fail -Shape const x degeri-!!");
	}

	if(yy>=0)
		y = yy;
	else
	{
		throw Exception("Shape Fail -Shape const y degeri-!!");
	}
}

void Shape::setShapeX(double xx)
{
	if(xx>= 0)
		x = xx;
	else
	{
		throw Exception("Shape Fail -Shape setX-!!");
	}
}

void Shape::setShapeY(double yy)
{
	if(yy>=0)
		y = yy;
	else
		throw Exception("Shape Fail -Shape setY-!!");
}

Shape& Shape::operator++()
{
	++x;
	++y;
	return *this;
}

Shape& Shape::operator--()
{
	--x;
	--y;
	return *this;
}

Shape& Shape::operator++(int)
{
    Shape &ss = *this;
	x++;
	y++;
	return ss;

	//cout<<"Shape post increment\n";
}

Shape& Shape::operator--(int)
{
	Shape &ss = *this;
	x--;
	y--;
	return ss;
	//cout<<"Shape post decrement\n";
}

bool Shape::operator==(const Shape &s) const
{
	cout<<"shape ==\n";
	return (this->Area() == s.Area());
}

bool Shape::operator!=(const Shape &s) const
{
	return (!(this->Area() == s.Area()));
}

bool Shape::operator>(const Shape &s) const
{
	return (this->Area() > s.Area());
}
bool Shape::operator<(const Shape &s) const
{
	return (this->Area() < s.Area());
}
bool Shape::operator>=(const Shape &s) const
{
	return (this->Area() >= s.Area());
}
bool Shape::operator<=(const Shape &s) const
{
	return (this->Area() <= s.Area());
}


}