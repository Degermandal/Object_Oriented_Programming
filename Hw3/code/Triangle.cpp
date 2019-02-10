#include "Triangle.h"

using namespace std;


void Triangle::setEdge(double e)
{
	if(e > 0.0)
		edge = e;
	else
		cout<<"Incorrect edge input\n";
}


void Triangle::setX1(double x1)
{
	if(x1 >= 0.0)
		cor_x1 = x1;
	else
		cout<<"Incorrect x input\n";
}

void Triangle::setY1(double y1)
{
	if(y1 >= 0.0)
		cor_y1 = y1;
	else
		cout<<"Incorrect y input\n";
}

void Triangle::setX2(double x2)
{
	if(x2 >= 0.0)
		cor_x2 = x2;
	else
		cout<<"Incorrect x input\n";
}

void Triangle::setY2(double y2)
{
	if(y2 >= 0.0)
		cor_y2 = y2;
	else
		cout<<"Incorrect y input\n";
}

void Triangle::setX3(double x3)
{
	if(x3 >= 0.0)
		cor_x3 = x3;
	else
		cout<<"Incorrect x input\n";
}

void Triangle::setY3(double y3)
{
	if(y3 >= 0.0)
		cor_y3 = y3;
	else
		cout<<"Incorrect y input\n";
}
/*
void Triangle::draw(ofstream &svgFile) const	
{
	svgFile << "<polygon fill=\"red\" points = \"" << cor_x1 << "," << cor_y1 <<" " << cor_x2 <<","<< cor_y2 <<
				" "<< cor_x3 << "," << cor_y3 << "\" stroke = \"black\" stroke-width = \"1\" />\n";
}
*/
double Triangle::triPerimeter() const
{
	return 3*edge;
}

double Triangle::triArea() const
{
	return (edge*edge*sqrt(3)) / 4;
}

ostream& operator<< (ostream &out, const Triangle &t1)
{
	out << "<polygon fill=\"red\" points = \"" << t1.cor_x1 << "," << t1.cor_y1 <<" " << t1.cor_x2 <<","<< t1.cor_y2 <<
				" "<< t1.cor_x3 << "," << t1.cor_y3 << "\" stroke = \"black\" stroke-width = \"1\" />\n";

	/*
	out<< "Edge of Shape: "<<t1.edge<<endl;
	out<< "X1 coordinate of Shape : "<<t1.cor_x1<<endl;
	out<< "Y1 coordinate of Shape : "<<t1.cor_y1<<endl;
	out<< "X2 coordinate of Shape : "<<t1.cor_x2<<endl;
	out<< "Y2 coordinate of Shape : "<<t1.cor_y2<<endl;
	out<< "X3 coordinate of Shape : "<<t1.cor_x3<<endl;
	out<< "Y3 coordinate of Shape : "<<t1.cor_y3<<endl;
	*/
	return out;
}

Triangle& Triangle::operator++()//check YAP!!!!!!!!!!!!!!!!
{
	setX1(cor_x1 + 1.0);
	setY1(cor_y1 + 1.0);
	setX2(cor_x2 + 1.0);
	setY2(cor_y2 + 1.0);
	setX3(cor_x3 + 1.0);
	setY3(cor_y3 + 1.0);

	return *this;
}

Triangle& Triangle::operator--()
{
	setX1(cor_x1 - 1.0);
	setY1(cor_y1 - 1.0);
	setX2(cor_x2 - 1.0);
	setY2(cor_y2 - 1.0);
	setX3(cor_x3 - 1.0);
	setY3(cor_y3 - 1.0);

	return *this;
}

Triangle Triangle::operator++(int)
{
	Triangle temp(cor_x1, cor_y1, cor_x2, cor_y2, cor_x3, cor_y3);

	++(*this);

	return temp;
}

Triangle Triangle::operator--(int)
{
	Triangle temp(cor_x1, cor_y1, cor_x2, cor_y2, cor_x3, cor_y3);

	--(*this);

	return temp;
}

Triangle Triangle::operator+(double plusSize)
{
	return Triangle(edge + plusSize);
}

Triangle Triangle::operator-(double minusSize)
{
	return Triangle(edge - minusSize);
}

bool operator==(const Triangle &t1, const Triangle &t2)
{
	return (t1.triArea() == t2.triArea());
}
bool operator!=(const Triangle &t1, const Triangle &t2)
{
	return !(t1 == t2);
}
bool operator>(const Triangle &t1, const Triangle &t2)
{
	return (t1.triArea() > t2.triArea());
}
bool operator<(const Triangle &t1, const Triangle &t2)
{
	return (t1.triArea() < t2.triArea());
}
bool operator>=(const Triangle &t1, const Triangle &t2)
{
	return (t1.triArea() >= t2.triArea());
}
bool operator<=(const Triangle &t1, const Triangle &t2)
{
	return (t1.triArea() <= t2.triArea());
}

int Triangle::areaCounter = 0;
double Triangle::totalArea = 0.0;

int Triangle::perimeterCounter = 0;
double Triangle::totalPerimeter = 0.0;

double Triangle::staticTriArea(const Triangle &t1)
{
	totalArea += areaCounter * t1.triArea();
	return totalArea;
}

double Triangle::staticTriPerimeter(const Triangle &t1)
{
	totalPerimeter += perimeterCounter * t1.triPerimeter();
	return totalPerimeter;
}