#include "Circle.h"

using namespace std;

namespace _shape{

void Circle::setRadius(double r)
{
	if(r > 0.0)
		radius = r;
	else
		cout<<"Incorrect radius input\n";
}


double Circle::Perimeter() const
{
	return 2*PI*radius;
}

double Circle::Area() const
{
	return PI*radius*radius;
}

ostream& operator<< (ostream &out, const Circle &C1)
{
	out<<"<svg version = \"1.1\" baseProfile = \"full\" width = \"1000\" height = \"1000\" "
	<<" xmlns=\"http://www.w3.org/2000/svg\">\n";

	out<<"<circle cx = \"" << C1.getRadius() << "\" cy = \"" << C1.getRadius() << "\" r=\"" << C1.getRadius() << 
				"\" fill=\"red\" stroke = \"black\" stroke-width = \"1\" />\n";

	return out;
}

Circle& Circle::operator++()
{
	setShapeX(getShapeX()+1.0);
	setShapeY(getShapeY()+1.0);

	return *this;
}

Circle& Circle::operator--()
{
	setShapeX(getShapeX()-1.0);
	setShapeY(getShapeY()-1.0);

	return *this;
}

Circle& Circle::operator++(int)
{
	cout<<"circle ++\n";
	Circle &cc = *this;
	setShapeX(getShapeX()+1.0);
	setShapeY(getShapeY()+1.0);
	
	return cc;
}

Circle& Circle::operator--(int)
{
	Circle &rr = *this;
	setShapeX(getShapeX()-1.0);
	setShapeY(getShapeY()-1.0);
	
	return rr;
}

Circle Circle::operator+(double plusSize)
{
	return Circle(radius + plusSize);
}

Circle Circle::operator-(double minusSize)
{
	return Circle(radius - minusSize);
}

bool Circle::operator==(const Shape &c) const
{
try{
	if(const Circle* ptr = dynamic_cast< const Circle*>(&c))
		return(this->Area() == ptr->Area());
	return false;
}
catch(exception&e )
{
	cout<<e.what()<<endl;
}

}
bool Circle::operator!=(const Shape &c) const
{
try{ ////BAD_CAST exception durumu

	if(const Circle* ptr = dynamic_cast< const Circle*>(&c))
		return(this->Area() != ptr->Area());

	return false;
}
catch(exception&e )
{
	cout<<e.what()<<endl;
}

}

bool Circle::operator>(const Shape &c) const
{
	if(const Circle* ptr = dynamic_cast< const Circle*>(&c))
		return(this->Area() > ptr->Area());

	return false;
}
bool Circle::operator<(const Shape &c) const
{
	if(const Circle* ptr = dynamic_cast< const Circle*>(&c))
		return(this->Area() < ptr->Area());

	return false;
}
bool Circle::operator>=(const Shape &c) const
{
	if(const Circle* ptr = dynamic_cast< const Circle*>(&c))
		return(this->Area() >= ptr->Area());

	return false;
}
bool Circle::operator<=(const Shape &c) const
{
	if(const Circle* ptr = dynamic_cast< const Circle*>(&c))
		return(this->Area() <= ptr->Area());

	return false;
}

int Circle::areaCounter = 0;
double Circle::totalArea = 0.0;

int Circle::perimeterCounter = 0;
double Circle::totalPerimeter = 0.0;

double Circle::staticCirArea(const Circle &c1)
{
	totalArea += areaCounter * c1.Area();
	return totalArea;
}

double Circle::staticCirPerimeter(const Circle &c1)
{
	totalPerimeter += perimeterCounter * c1.Perimeter();
	return totalPerimeter;
}


}