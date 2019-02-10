#include "Circle.h"

using namespace std;


void Circle::setRadius(double r)
{
	if(r > 0.0)
		radius = r;
	else
		cout<<"Incorrect radius input\n";
}


void Circle::setX(double x)
{
	if(x >= 0.0)
		cor_x = x;
	else
		cout<<"Incorrect x input\n";
}

void Circle::setY(double y)
{
	if(y >= 0.0)
		cor_y = y;
	else
		cout<<"Incorrect y input\n";
}
/*
void Circle::draw(ofstream &svgFile)
{
	svgFile<<"<circle cx = \"" << radius << "\" cy = \"" << radius << "\" r=\"" << radius << 
				"\" fill=\"red\" stroke = \"black\" stroke-width = \"1\" />\n";
}
*/

double Circle::cirPerimeter() const
{
	return 2*PI*radius;
}

double Circle::cirArea() const
{
	return PI*radius*radius;
}

ostream& operator<< (ostream &out, const Circle &C1)
{
	out<<"<circle cx = \"" << C1.radius << "\" cy = \"" << C1.radius << "\" r=\"" << C1.radius << 
				"\" fill=\"red\" stroke = \"black\" stroke-width = \"1\" />\n";

	/*
	out<< "Radius of Shape: "<<C1.radius<<endl;
	out<< "X coordinate of Shape : "<<C1.cor_x<<endl;
	out<< "Y coordinate of Shape : "<<C1.cor_y<<endl;
	*/

	return out;
}

Circle& Circle::operator++()//check YAP!!!!!!!!!!!!!!!!
{
	++cor_x;
	++cor_y;

	return *this;
}

Circle& Circle::operator--()
{
	--cor_x;
	--cor_y;

	return *this;
}

Circle Circle::operator++(int)
{
	Circle temp(cor_x, cor_y);

	++(*this);

	return temp;
}

Circle Circle::operator--(int)
{
	Circle temp(cor_x, cor_y);

	--(*this);

	return temp;
}

Circle Circle::operator+(double plusSize)
{
	return Circle(radius + plusSize);
}

Circle Circle::operator-(double minusSize)
{
	return Circle(radius - minusSize);
}

bool operator==(const Circle &c1, const Circle &c2)
{
	return (c1.cirArea() == c2.cirArea());
}
bool operator!=(const Circle &c1, const Circle &c2)
{
	return !(c1 == c2);
}
bool operator>(const Circle &c1, const Circle &c2)
{
	return (c1.cirArea() > c2.cirArea());
}
bool operator<(const Circle &c1, const Circle &c2)
{
	return (c1.cirArea() < c2.cirArea());
}
bool operator>=(const Circle &c1, const Circle &c2)
{
	return (c1.cirArea() >= c2.cirArea());
}
bool operator<=(const Circle &c1, const Circle &c2)
{
	return (c1.cirArea() <= c2.cirArea());
}

int Circle::areaCounter = 0;
double Circle::totalArea = 0.0;

int Circle::perimeterCounter = 0;
double Circle::totalPerimeter = 0.0;

double Circle::staticCirArea(const Circle &c1)
{
	totalArea += areaCounter * c1.cirArea();
	return totalArea;
}

double Circle::staticCirPerimeter(const Circle &c1)
{
	totalPerimeter += perimeterCounter * c1.cirPerimeter();
	return totalPerimeter;
}
