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

void Circle::draw(ofstream &svgFile)
{
	svgFile<<"<circle cx = \"" << radius << "\" cy = \"" << radius << "\" r=\"" << radius << 
				"\" fill=\"red\" stroke = \"black\" stroke-width = \"1\" />\n";
}