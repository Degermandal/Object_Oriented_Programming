#include "Rectangle.h"

using namespace std;


int Rectangle::areaCounter = 0;
double Rectangle::totalArea = 0.0;

int Rectangle::perimeterCounter = 0;
double Rectangle::totalPerimeter = 0.0;


void Rectangle::setHeight(int h)
{
	if(h > 0.0) //check ediyorum dogru deger mi diye
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

void Rectangle::setX(double x)
{
	if(x >= 0.0)
		cor_x = x;
	else
		cout<<"Incorrect x input\n";
}

void Rectangle::setY(double y)
{
	if(y >= 0.0)
		cor_y = y;
	else
		cout<<"Incorrect y input\n";
}
/*
void Rectangle::draw(ofstream &svgFile)
{
	svgFile<<"<rect x = \"" << 0 << "\" y = \"" << 0 << "\" width=\"" <<getWidth()<< 
					 "\" height=\"" <<getHeight()<< "\" fill=\"red\" stroke = \"black\" stroke-width = \"1\" />\n";
}
*/
double Rectangle::recPerimeter() const
{
	return 2*height + 2*width;
}

double Rectangle::recArea() const
{
	return height*width;
}

ostream& operator<< (ostream &out, const Rectangle &r1)
{
	out<<"<rect x = \"" << 0 << "\" y = \"" << 0 << "\" width=\"" <<r1.width<< 
					 "\" height=\"" <<r1.height<< "\" fill=\"red\" stroke = \"black\" stroke-width = \"1\" />\n";

	/*
	out<< "Height of Shape: "<<r1.height<<endl;
	out<< "Width of Shape: "<<r1.width<<endl;
	out<< "X coordinate of Shape : "<<r1.cor_x<<endl;
	out<< "Y coordinate of Shape : "<<r1.cor_y<<endl;
	*/
	return out;
}

Rectangle& Rectangle::operator++()//check YAP!!!!!!!!!!!!!!!!
{
	++cor_x;
	++cor_y;

	return *this;
}

Rectangle& Rectangle::operator--()
{
	--cor_x;
	--cor_y;

	return *this;
}

Rectangle Rectangle::operator++(int)
{
	Rectangle temp(cor_x, cor_y, 1);

	++(*this);

	return temp;
}

Rectangle Rectangle::operator--(int)
{
	Rectangle temp(cor_x, cor_y, 1);

	--(*this);

	return temp;
}

Rectangle Rectangle::operator+(double plusSize)
{
	return Rectangle(height + plusSize, width + plusSize);
}

Rectangle Rectangle::operator-(double minusSize)
{
	return Rectangle(height - minusSize, width - minusSize);
}

bool operator==(const Rectangle &r1, const Rectangle &r2)
{
	return (r1.recArea() == r2.recArea());
}
bool operator!=(const Rectangle &r1, const Rectangle &r2)
{
	return !(r1 == r2);
}
bool operator>(const Rectangle &r1, const Rectangle &r2)
{
	return (r1.recArea() > r2.recArea());
}
bool operator<(const Rectangle &r1, const Rectangle &r2)
{
	return (r1.recArea() < r2.recArea());
}
bool operator>=(const Rectangle &r1, const Rectangle &r2)
{
	return (r1.recArea() >= r2.recArea());
}
bool operator<=(const Rectangle &r1, const Rectangle &r2)
{
	return (r1.recArea() <= r2.recArea());
}


double Rectangle::staticRecArea(const Rectangle &r1)
{
	totalArea += areaCounter * r1.recArea();
	return totalArea;
}

double Rectangle::staticRecPerimeter(const Rectangle &r1)
{
	totalPerimeter += perimeterCounter * r1.recPerimeter();
	return totalPerimeter;
}