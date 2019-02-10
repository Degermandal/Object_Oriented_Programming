#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
#include "ComposedShape.h"
#include "Shape.h"
#include "Polygon.h"
#include "PolygonDyn.h"
#include "PolygonVect.h"
#include "Exception.h"

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <vector>

#include <fstream>


using namespace std;
using namespace _shape;

namespace
{
	void FunCout()
	{
		cout<<"#######################################################################################\n";
	}

//- Function printAll takes a vector of Shape pointers and prints all shapes to an SVG file
void printAll(vector<Shape*> ss, ofstream &svg)
{
	 for(int i = 0; i<ss.size(); i++)
	 {
	 	svg<<ss[i];
	 }
}

//- Function printPoly takes a vector of Shape pointers and prints all Polygon shapes to an SVG file
void printPoly(vector<Shape*> ss, ofstream &svg)
{
	for(int i = 0; i<ss.size(); ++i)
	{
		const Polygon* ptr = dynamic_cast< const Polygon*>(ss[i]);
		svg<<ss[i];
	}
}

//- Function convertAll takes a vector of Shape pointers, converts all shapes to 
//Polygons and returns a new vector with the new shapes..

vector<Polygon*> convertAll(vector<Shape*> ss)
{
	vector<Polygon*> pp;
	for(int i = 0; i<ss.size(); ++i)
	{
		Polygon* ptr = dynamic_cast<Polygon*>(ss[i]);
		pp.push_back(ptr);
	}
	return pp;
}

//- Function sortShapes takes a vector of Shape pointers and increasingly sorts them with respect to their areas.

void sortShapes(vector<Shape*> ss)
{
	int i , j,min;
	int n = ss.size();
	for(i = 0; i<n-1; ++i)
	{
		min = i;
		for(j = i+1; j<n; j++)
			if(ss[j]->Area() < ss[min]->Area())
				min = j;

		Shape* temp = ss[min];
		ss[min] = ss[i];
		ss[i] = ss[min];
	}
}

}

int main()
{
	ofstream svgFile1;
	ofstream svgFile2;
	ofstream svgFile3;
	ofstream svgFile4;
	ofstream svgFile5;
	ofstream svgFile6;
	ofstream svgFile7;
	ofstream svgFile8;
	ofstream svgFile9;

	ofstream svgFile10;
	ofstream svgFile11;
	ofstream svgFile12;
	ofstream svgFile13;
	ofstream svgFile14;
	ofstream svgFile15;


	svgFile1.open("F1.svg");
	svgFile2.open("F2.svg");
	svgFile3.open("F3.svg");
	svgFile4.open("F4.svg");
	svgFile5.open("F5.svg");
	svgFile6.open("F6.svg");
	svgFile7.open("F7.svg");
	svgFile8.open("F8.svg");
	svgFile9.open("F9.svg");

	svgFile10.open("F10.svg");
	svgFile11.open("F11.svg");
	svgFile12.open("F12.svg");
	svgFile13.open("F13.svg");
	svgFile14.open("F14.svg");
	svgFile15.open("F15.svg");
	

//########################################################################################################3

//rectangle icin manual deger atadim
Rectangle mobjR1(500.0, 600.0, 0.0, 0.0);
Rectangle mobjR2(200.0, 500.0, 0.0, 0.0);
Rectangle sobjR1(25.0, 40.0);
Rectangle sobjR2(20.0, 40.0);

//circle icin manual deger atadim
Circle mobjC1(350.0, 350.0, 350.0);
Circle mobjC2(500.0, 500.0, 500.0);
Circle sobjC1(20.0);
Circle sobjC2(38.0);

//triangle icin manual deger atadim
Triangle mobjT1(500.0);
Triangle mobjT2;
Triangle sobjT1(35.0);
Triangle sobjT2(19.0);

//#################################################################################################

//kendimce objleri doldurdum composedShape e
ComposedShape CSobj1(mobjR1, sobjR1,svgFile1);
ComposedShape CSobj2(mobjR2, sobjT1,svgFile2);
ComposedShape CSobj3(mobjR1, sobjC1,svgFile3);
ComposedShape CSobj4(mobjT1, sobjR1,svgFile4);
ComposedShape CSobj5(mobjT1, sobjT2,svgFile5);
ComposedShape CSobj6(mobjT1, sobjC1,svgFile6);
ComposedShape CSobj7(mobjC1, sobjR1,svgFile7);
ComposedShape CSobj8(mobjC2, sobjT2,svgFile8);
ComposedShape CSobj9(mobjC1, sobjC1,svgFile9);

//her bir obje icin optimalFiti denedim
CSobj1.optimalFit(svgFile1);
CSobj2.optimalFit(svgFile2);
CSobj3.optimalFit(svgFile3);
CSobj4.optimalFit(svgFile4);
CSobj5.optimalFit(svgFile5);
CSobj6.optimalFit(svgFile6);
CSobj7.optimalFit(svgFile7);
CSobj8.optimalFit(svgFile8);
CSobj9.optimalFit(svgFile9);

//###############################################################################################


Polygon::Point2D a(100,100);
Polygon::Point2D b(100,50);
Polygon::Point2D c(50,100);


PolygonDyn dyn1(a);
PolygonDyn dyn2(a, b, c);
PolygonVect vec1(a);
PolygonVect vec2(b);

//PolygonDyn dyn3(&mobjT2);

vector<Shape*> shapeVec;



svgFile10<<"<svg version = \"1.1\" baseProfile = \"full\" width = \"1000\" height = \"1000\" "
	<<" xmlns=\"http://www.w3.org/2000/svg\">\n";
svgFile11<<"<svg version = \"1.1\" baseProfile = \"full\" width = \"1000\" height = \"1000\" "
	<<" xmlns=\"http://www.w3.org/2000/svg\">\n";
svgFile12<<"<svg version = \"1.1\" baseProfile = \"full\" width = \"1000\" height = \"1000\" "
	<<" xmlns=\"http://www.w3.org/2000/svg\">\n";

svgFile13<<"<svg version = \"1.1\" baseProfile = \"full\" width = \"1000\" height = \"1000\" "
	<<" xmlns=\"http://www.w3.org/2000/svg\">\n";
svgFile14<<"<svg version = \"1.1\" baseProfile = \"full\" width = \"1000\" height = \"1000\" "
	<<" xmlns=\"http://www.w3.org/2000/svg\">\n";
svgFile15<<"<svg version = \"1.1\" baseProfile = \"full\" width = \"1000\" height = \"1000\" "
	<<" xmlns=\"http://www.w3.org/2000/svg\">\n";



shapeVec.push_back(&mobjR1);
shapeVec.push_back(&sobjC1);
shapeVec.push_back(&mobjT1);
//shapeVec.push_back(&dyn1);
//shapeVec.push_back(&vec1);

printAll(shapeVec, svgFile10);
printPoly(shapeVec, svgFile11);
convertAll(shapeVec);
sortShapes(shapeVec);

svgFile13<< shapeVec[0];
svgFile14<<shapeVec[1];
svgFile15<<shapeVec[2];




//dosyalarin kapatilmasi
	svgFile1<<"</svg>";
	svgFile1.close();
	svgFile2<<"</svg>";
	svgFile2.close();
	svgFile3<<"</svg>";
	svgFile3.close();
	svgFile4<<"</svg>";
	svgFile4.close();
	svgFile5<<"</svg>";
	svgFile5.close();
	svgFile6<<"</svg>";
	svgFile6.close();
	svgFile7<<"</svg>";
	svgFile7.close();
	svgFile8<<"</svg>";
	svgFile8.close();
	svgFile9<<"</svg>";
	svgFile9.close();
	svgFile10<<"</svg>";
	svgFile10.close();
	svgFile11<<"</svg>";
	svgFile11.close();
	svgFile12<<"</svg>";
	svgFile12.close();
	svgFile13<<"</svg>";
	svgFile13.close();
	svgFile14<<"</svg>";
	svgFile14.close();
	svgFile15<<"</svg>";
	svgFile15.close();

	return 0;

}

