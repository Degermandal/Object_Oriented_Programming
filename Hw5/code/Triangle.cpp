#include "Triangle.h"

using namespace std;

namespace _shape{

ostream& operator<< (ostream &out, const Triangle &t1)
{
	out<<"<svg version = \"1.1\" baseProfile = \"full\" width = \"1000\" height = \"1000\" "
	<<" xmlns=\"http://www.w3.org/2000/svg\">\n";

	out << "<polygon fill=\"red\" points = \"" << t1.getShapeX() << "," << t1.getShapeY() <<" " << t1.getX2() <<","<< 
	t1.getY2() <<" "<< t1.getX3() << "," << t1.getY3() << "\" stroke = \"black\" stroke-width = \"1\" />\n";

	return out;
}


void Triangle::setEdge(double e)
{
	if(e > 0.0)
		edge = e;
	else
		cout<<"Incorrect edge input\n";
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

double Triangle::Perimeter() const
{
	return 3*edge;
}

double Triangle::Area() const
{
	return (edge*edge*sqrt(3)) / 4;
}



Triangle& Triangle::operator++()
{
	setShapeX(getShapeX()+1.0);
	setShapeY(getShapeY()+1.0);
	setX2(cor_x2 + 1.0);
	setY2(cor_y2 + 1.0);
	setX3(cor_x3 + 1.0);
	setY3(cor_y3 + 1.0);

	return *this;
}

Triangle& Triangle::operator--()
{
	setShapeX(getShapeX()-1.0);
	setShapeY(getShapeY()-1.0);
	setX2(cor_x2 - 1.0);
	setY2(cor_y2 - 1.0);
	setX3(cor_x3 - 1.0);
	setY3(cor_y3 - 1.0);

	return *this;
}

Triangle& Triangle::operator++(int)
{
	Triangle &tt = *this;
	setShapeX(getShapeX()+1.0);
	setShapeY(getShapeY()+1.0);
	setX2(cor_x2 + 1.0);
	setY2(cor_y2 + 1.0);
	setX3(cor_x3 + 1.0);
	setY3(cor_y3 + 1.0);

	return tt;
}

Triangle& Triangle::operator--(int)
{
	Triangle &tt = *this;
	setShapeX(getShapeX()-1.0);
	setShapeY(getShapeY()-1.0);
	setX2(cor_x2 - 1.0);
	setY2(cor_y2 - 1.0);
	setX3(cor_x3 - 1.0);
	setY3(cor_y3 - 1.0);

	return tt;
}

Triangle Triangle::operator+(double plusSize)
{
	return Triangle(edge + plusSize);
}

Triangle Triangle::operator-(double minusSize)
{
	return Triangle(edge - minusSize);
}

bool Triangle::operator==(const Shape &t) const
{
try{//bad_cast exception area icin
	if(const Triangle* ptr = dynamic_cast<const Triangle*> (&t))
		return(this->Area() == ptr->Area());
	
	return false;
}
catch(exception&e )
{
	cout<<e.what()<<endl;
}

}
bool Triangle::operator!=(const Shape &t) const
{
try{
	if(const Triangle* ptr = dynamic_cast<const Triangle*> (&t))
		return(this->Area() != ptr->Area());
	
	return false;
}
catch(exception&e )
{
	cout<<e.what()<<endl;
}

}

bool Triangle::operator>(const Shape &t) const
{
	if(const Triangle* ptr = dynamic_cast<const Triangle*> (&t))
		return(this->Area() > ptr->Area());
	
	return false;
}
bool Triangle::operator<(const Shape &t) const
{
	if(const Triangle* ptr = dynamic_cast<const Triangle*> (&t))
		return(this->Area() < ptr->Area());
	
	return false;
}
bool Triangle::operator>=(const Shape &t) const
{
	if(const Triangle* ptr = dynamic_cast<const Triangle*> (&t))
		return(this->Area() >= ptr->Area());
	
	return false;
}
bool Triangle::operator<=(const Shape &t) const
{
	if(const Triangle* ptr = dynamic_cast<const Triangle*> (&t))
		return(this->Area() <= ptr->Area());
	
	return false;
}

int Triangle::areaCounter = 0;
double Triangle::totalArea = 0.0;

int Triangle::perimeterCounter = 0;
double Triangle::totalPerimeter = 0.0;

double Triangle::staticTriArea(const Triangle &t1)
{
	totalArea += areaCounter * t1.Area();
	return totalArea;
}

double Triangle::staticTriPerimeter(const Triangle &t1)
{
	totalPerimeter += perimeterCounter * t1.Perimeter();
	return totalPerimeter;
}

}