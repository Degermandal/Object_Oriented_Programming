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

void Triangle::draw(ofstream &svgFile) const	
{
	svgFile << "<polygon fill=\"red\" points = \"" << cor_x1 << "," << cor_y1 <<" " << cor_x2 <<","<< cor_y2 <<
				" "<< cor_x3 << "," << cor_y3 << "\" stroke = \"black\" stroke-width = \"1\" />\n";
}