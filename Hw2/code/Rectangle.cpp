#include "Rectangle.h"

using namespace std;


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

void Rectangle::draw(ofstream &svgFile)
{
	svgFile<<"<rect x = \"" << 0 << "\" y = \"" << 0 << "\" width=\"" <<getWidth()<< 
					 "\" height=\"" <<getHeight()<< "\" fill=\"red\" stroke = \"black\" stroke-width = \"1\" />\n";
}