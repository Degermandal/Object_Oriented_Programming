#ifndef COMPOSEDSHAPE_H
#define COMPOSEDSHAPE_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>

#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
#include "Polygon.h"

using namespace Shape;

#define PI 3.1415


using namespace std;



class ComposedShape{

public:

enum class _Shapes {rectangle, circle, triangle};
		class ShapeElem{
	    public:   
              
	       _Shapes getEnum() const {return type;}
	        void setEnum(_Shapes shape){ type = shape; }
	        ShapeElem(_Shapes shape, void *pp)
	        {
	        	type = shape;
	        	if(type == _Shapes::rectangle)
	        	{
	        		//Rectangle *small_rec = new Rectangle;
	        		//small_rec = pp;
	        		ptr = static_cast<void*>(pp);
	        	}
	        	else if(type == _Shapes::circle)
	        	{
	        		//Circle *small_cir = new Circle;
	        		ptr = static_cast<void*>(pp);
	        	}
	        	else if(type == _Shapes::triangle)
	        	{
	        		//Triangle *small_tri = new Triangle;
	        		ptr = static_cast<void*>(pp);
	        	}
	        	else
	        		cout<<"Shape elem constructor error\n";

	        }
	       
	        friend ostream& operator<<(ostream &out, const ShapeElem &se);  
	        double innerPerimeter() const ;   
	        double innerArea() const ;
	        
	         
	        //Rectangle *elemRec;
	       	//Circle *elemCir;
	       	//Triangle *elemTir;

	    	private:
	        void *ptr;
	        _Shapes type;  
		};



	//CONSTRUCTORS
	ComposedShape(){};
	ComposedShape(Rectangle rec, Triangle tri, ofstream &svgFile);
	ComposedShape(Rectangle rec, Circle cir, ofstream &svgFile);
	ComposedShape(Rectangle rec, Rectangle rec2, ofstream &svgFile);
	ComposedShape(Circle cir, Rectangle rec, ofstream &svgFile);
	ComposedShape(Circle cir, Triangle tri, ofstream &svgFile);
	ComposedShape(Circle cir, Circle cir2, ofstream &svgFile);
	ComposedShape(Triangle tri, Triangle tri2, ofstream &svgFile);
	ComposedShape(Triangle tri, Circle cir, ofstream &svgFile);
	ComposedShape(Triangle tri, Rectangle rec, ofstream &svgFile);

	//en son butun fonksiyonlari birlestirip yerlestirdigim fonksiyon
	void optimalFit(ofstream &svgFile);

	friend ostream& operator<<(ostream &svgFile, const ComposedShape &cs);

	char getSmallCon() const{return mySmallCon; } //
	char getMainCon() const{return myMainCon; }

private:

	vector <ShapeElem> elemVec;
	
	ShapeElem& operator[](const int index);

    void operator+=(Triangle &t);
    void operator+=(const Rectangle &r);
    void operator+=(const Circle &c);
	
	//bu objeleri composition icin kullandim small ve main olmak uzere 3 er taneden 6 tane
	Rectangle small_rec;
	Triangle small_tri;
	Circle small_cir;
	Rectangle main_rec;
	Triangle main_tri;
	Circle main_cir;

	//bu degiskenler hangi iki objeyi aldigim bulmak icin kullandigim bu classa ozel degiskenler
	//optimalfit fonksiyonum icin kullandim
	char myMainCon;
	char mySmallCon;
	
	vector<Polygon> Poly;
	//Polygon polyObje;

	//girilen her objeye gore fonksiyonlar tanimladim
	//bu fonksiyonlari optimalFit de birlestiriyorum
	void optimalRec_Tri(ofstream &svgFile);
	void optimalRec_Cir(ofstream &svgFile);
	void optimalRec_Rec(ofstream &svgFile);
	void optimalTri_Tri(ofstream &svgFile);
	void optimalTri_Rec(ofstream &svgFile);
	void optimalTri_Cir(ofstream &svgFile);
	void optimalCir_Rec(ofstream &svgFile);
	void optimalCir_Tri(ofstream &svgFile);
	void optimalCir_Cir(ofstream &svgFile);

};

#endif