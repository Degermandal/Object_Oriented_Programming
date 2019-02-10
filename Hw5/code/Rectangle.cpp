#include "Rectangle.h"

using namespace std;

namespace _shape{

ostream& operator<< (ostream &out, const Rectangle &r1)
{
	out<<"<svg version = \"1.1\" baseProfile = \"full\" width = \"1000\" height = \"1000\" "
	<<" xmlns=\"http://www.w3.org/2000/svg\">\n";

	out<<"<rect x = \"" << 0 << "\" y = \"" << 0 << "\" width=\"" <<r1.getWidth()<< 
					 "\" height=\"" <<r1.getHeight()<< "\" fill=\"red\" stroke = \"black\" stroke-width = \"1\" />\n";

	return out;
}

int Rectangle::areaCounter = 0;
double Rectangle::totalArea = 0.0;

int Rectangle::perimeterCounter = 0;
double Rectangle::totalPerimeter = 0.0;


void Rectangle::setHeight(int h)
{
	if(h > 0.0) 
		height = h;
	else
		cout<<"Incorrect height input\n";
}

void Rectangle::setWidth(int w)
{
	if(w > 0.0)
		width = w;
	else
		cout<<"Incorrect width input\n";
}

double Rectangle::Perimeter() const
{
	return 2*height + 2*width;
}

double Rectangle::Area() const
{
	return height*width;
}



Rectangle& Rectangle::operator++()
{
	setShapeX(getShapeX()+1.0);
	setShapeY(getShapeY()+1.0);

	return *this;
}

Rectangle& Rectangle::operator--()
{
	setShapeX(getShapeX()-1.0);
	setShapeY(getShapeY()-1.0);

	return *this;
}

Rectangle& Rectangle::operator++(int)
{
	Rectangle &rr = *this;
	setShapeX(getShapeX()+1.0);
	setShapeY(getShapeY()+1.0);
	
	return rr;
}

Rectangle& Rectangle::operator--(int)
{
	Rectangle &rr = *this;
	setShapeX(getShapeX()-1.0);
	setShapeY(getShapeY()-1.0);
	return rr;
}

Rectangle Rectangle::operator+(double plusSize)
{
	return Rectangle(height + plusSize, width + plusSize);
}

Rectangle Rectangle::operator-(double minusSize)
{
	return Rectangle(height - minusSize, width - minusSize);
}



bool Rectangle::operator==(const Shape &r)const
{
try{
	if(const Rectangle* ptr = dynamic_cast<const Rectangle*> (&r))
		return(this->Area() == ptr->Area());
	
	return false;
}
catch(exception&e )
{
	cout<<e.what()<<endl;
}

}

bool Rectangle::operator!=(const Shape &r)const
{
try{
	if(const Rectangle* ptr = dynamic_cast<const Rectangle*> (&r))
		return(this->Area() != ptr->Area());
	
	return false;
}
catch(exception&e )
{
	cout<<e.what()<<endl;
}

}

bool Rectangle::operator>(const Shape &r) const
{
	if(const Rectangle* ptr = dynamic_cast<const Rectangle*> (&r))
		return(this->Area() > ptr->Area());
	
	return false;
}
bool Rectangle::operator<(const Shape &r) const
{
	if(const Rectangle* ptr = dynamic_cast<const Rectangle*> (&r))
		return(this->Area() < ptr->Area());
	
	return false;
}
bool Rectangle::operator>=(const Shape &r) const
{
	if(const Rectangle* ptr = dynamic_cast<const Rectangle*> (&r))
		return(this->Area() >= ptr->Area());
	
	return false;
}
bool Rectangle::operator<=(const Shape &r) const
{
	if(const Rectangle* ptr = dynamic_cast<const Rectangle*> (&r))
		return(this->Area() <= ptr->Area());
	
	return false;
}


double Rectangle::staticRecArea(const Rectangle &r1)
{
	totalArea += areaCounter * r1.Area();
	return totalArea;
}

double Rectangle::staticRecPerimeter(const Rectangle &r1)
{
	totalPerimeter += perimeterCounter * r1.Perimeter();
	return totalPerimeter;
}

}