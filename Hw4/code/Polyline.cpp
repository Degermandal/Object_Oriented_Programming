#include <iostream>
#include <cstdlib>


//using std::istream;
using std::ostream;
using std::cout;
//using std::cin;
#include "Polyline.h"

namespace Shape
{

void Polyline::setUsed(int us)
{ 
	if(us >= 0) 
		PlArUsed = us;
	else 
	{
		cout<<"Set used error\n";
		exit(1);
	}
}

void Polyline::setCapacity(int cp)
{
	if(cp >= 0) PlArCap = cp;
	else 
	{
		cout<<"Set capacity error\n";
		exit(1);
	}
}

Polyline::Polyline(Polygon pol) : poly(pol), PlArUsed(0), PlArCap(100)//objemi objeme attim ve kendimce degerler verdim
{
	vector<double> tt = pol.getPolAr();//getpolar in dondurdugu vektoru aldim

	PlAr = new double[tt.size()];//onun buyuklugne gore array olusturdum

	for(int i = 0; i<tt.size(); ++i)
	{
		PlAr[i] = tt[i];//ve privatedaki arrayimi doldurdum
	}

	PlArUsed = tt.size();
}

//Operator<< for producing the SVG code.

ostream& operator<< (ostream &out, const Polyline &p1)
{
	
	out<< "<polyline points = \"";

	for(int i = 2; i< p1.PlArUsed - 2; ++i)
	{
		out<< p1.PlAr[i]<< ",";
		out<< p1.PlAr[i+1]<< " ";
		i++;
	}

	out<<" fill=\"red\" stroke = \"black\" stroke-width = \"1\" />\n";
	return out;
}


Polyline::Polyline(const Polyline& copy): PlArUsed(copy.getUsed( ))
{
    PlAr = new double[PlArUsed];
    for (int i =0; i < PlArUsed; i++)
        PlAr[i] = copy.PlAr[i];
}

Polyline& Polyline::operator =(const Polyline& rightSide)
{
    if (PlArCap != rightSide.PlArCap)
    {
        delete [] PlAr;
        PlAr = new double[rightSide.PlArCap];
    }

    PlArCap = rightSide.PlArCap;
    PlArUsed = rightSide.PlArUsed;

    for (int i = 0; i < PlArUsed; i++)
        PlAr[i] = rightSide.PlAr[i];

    return *this;
}

Polyline::~Polyline( )
{
    delete [] PlAr;
}


}

