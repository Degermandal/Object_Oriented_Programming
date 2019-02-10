#include <iostream>

using std::cout;
using std::cin;
#include "Polygon.h"

namespace Shape
{


Polygon::Point2D::Point2D(): x(0), y(0)
{	
}

Polygon::Point2D::Point2D(double xx, double yy): x(xx), y(yy) 
{
}

void Polygon::setUsed(int us)
{ 
	if(us >= 0) 
		polArUsed = us;
	else 
	{
		cout<<"Set used error\n";
		exit(1);
	}
}

void Polygon::setCapacity(int cp)
{
	if(cp >= 0) polArCapacity = cp;
	else 
	{
		cout<<"Set capacity error\n";
		exit(1);
	}
}

vector<double> Polygon::getPolAr()//bu fonksiyonu Polyline classim icin yazdim polygondaki verileri arraye attip polyline classimda kullanabiliyorum
{
	vector<double> temp;

	for(int i = 0; i<polArUsed; ++i)
	{
		temp.push_back(polAr[i].getX());
		temp.push_back(polAr[i].getY());
	}

	return temp;
}

Polygon::Polygon(): polArCapacity(1000), polArUsed(0)
{
	polAr = new Point2D[polArCapacity];
}

Polygon::Polygon(int cap): polArCapacity(cap), polArUsed(0)
{
	polAr = new Point2D[polArCapacity];
}
//dinamik bir arrayim oldugu icin copy constructor assignment ve destructor fonksiyonlarini yazdim
Polygon::Polygon(const Polygon& copy): polArCapacity(copy.getCapacity( )), polArUsed(copy.getUsed( ))
{
    polAr = new Point2D[polArCapacity];
    for (int i =0; i < polArUsed; i++)
        polAr[i] = copy.polAr[i];
}

Polygon& Polygon::operator =(const Polygon& rightSide)
{
    if (polArCapacity != rightSide.polArCapacity)
    {
        delete [] polAr;
        polAr = new Point2D[rightSide.polArCapacity];
    }

    polArCapacity = rightSide.polArCapacity;
    polArUsed = rightSide.polArUsed;

    for (int i = 0; i < polArUsed; i++)
        polAr[i] = rightSide.polAr[i];

    return *this;
}

Polygon::~Polygon( )
{
    delete [] polAr;
}

Polygon::Polygon(vector < Point2D > vec) 
{
	polAr = new Point2D[vec.size()];//vectorun sizei kadar yer ayirdim
	for(int i = 0; i<vec.size(); ++i)//dongude verileri arrayime attim
	{
		polAr[i].setX(vec[i].getX());
		polAr[i].setY(vec[i].getY()) ;
	}
	
}

Polygon::Polygon(Point2D p2d)
{
	polAr=new Point2D[polArUsed];

	for(int i = 0; i< polArUsed; ++i)
	{
		polAr[i].setX(p2d.getX());
		polAr[i].setY(p2d.getY()) ;
	}

	
}

Polygon::Polygon(Circle &c)
{
//	X=x+cos(Q)
//	Y=y+sin(Q) formulu bu sekilde hangi aralikta ve koordinatta koyacagimi bulmak icin kullandim
	double angle = 0;
	polArCapacity = 100;
	polAr = new Point2D[100];

	for(int i = 0; i<100; ++i)
	{
		angle = i*(3.6)* PI / 180;
		polAr[i].setX(c.getX() + c.getRadius() * cos(angle));
		polAr[i].setY(c.getY() + c.getRadius() * sin(angle));
	}
}

Polygon::Polygon(Triangle &t)
{
	polAr = new Point2D[polArUsed];//used kadar yer actim
	Point2D a(t.getX1(), t.getY1());
	Point2D b(t.getX2(), t.getY2());
	Point2D c(t.getX3(), t.getY3());

	polAr[0] = a;//tek tek atadim zaten 3 tane olacak
	polAr[1] = b;
	polAr[2] = c;
}

Polygon::Polygon(Rectangle &r)//
{
	polAr = new Point2D[polArUsed];
	Point2D a(r.getX(), r.getY());
	polAr[0] = a;
}



//Operator+ that adds two Polygons by concatenating the points and returns the result as a new object.

Polygon Polygon::operator+(const Polygon& obj) const
{
	Polygon pl;
	int i=0, j;

	for(i = 0; i < polArUsed; ++i)
	{
		pl[i] = polAr[i];
	}


	for(j = 0; j < obj.polArUsed; ++j)
	{
		pl[i+1] = polAr[j];
	}

	return pl;

}

bool operator== (const Polygon &p1, const Polygon &p2)
{
    return (p1.polAr == p2.polAr);
}

bool operator!= (const Polygon &p1, const Polygon &p2)
{
   return !(p1== p2);
}

//Operator<< for producing the SVG code.
ostream& operator<< (ostream &out, const Polygon &p1)
{
	
	out<< "<polygon points = \"";

	for(int i = 0; i<p1.polArUsed; ++i)
	{
		out<< p1.polAr[i]<< ",";
		out<< p1.polAr[i+1]<< " ";
		i++;
	}

	out<<" fill=\"red\" stroke = \"black\" stroke-width = \"1\" />\n";

	return out;
}

}







