#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include <fstream>
#include <exception>

using namespace std;
#include "Shape.h"

namespace _shape{

class Rectangle : public Shape{

public:  
	//CONSTRUCTORS
	//rectangle class icin yazdigim constructorlar degisik durumlar icin
	Rectangle(): Shape(), height(200), width(350)
	{ 
		areaCounter++;
	    perimeterCounter++;	
	};

	Rectangle(double h, double w, double x, double y): Shape(x, y), height(h), width(w)
	{ 
		areaCounter++;
	    perimeterCounter++;	
	};

	Rectangle(double h, double w): Shape(), height(h), width(w)
	{ 
		areaCounter++;
	    perimeterCounter++;	
	};
		//height ve width verdigim constructor icin de 2 double alan constructor tanimladigim icin int ignore verdim
	Rectangle(double x, double y, int ignore): Shape(x, y), height(200), width(350) 
	{ 
		areaCounter++;
	    perimeterCounter++;	
	};

	//ACCESSOR FUNCTIONS
	//bunlar da get fonksiyonlarim privatedaki degiskenlerim icin
	inline int getHeight() const {return height; };
	inline int getWidth() const {return width; };
	//inline double getX() const {return cor_x; };
	//inline double getY() const {return cor_y; };

	//MUTATOR FUNCTIONS
	void setHeight(int h);
	void setWidth(int w);
	//void setX(double x);
	//void setY(double y);

	virtual double Perimeter() const override;
	virtual double Area() const override;

	

	virtual Rectangle& operator++() override;
	virtual Rectangle& operator--() override;
	virtual Rectangle& operator++(int) override;
	virtual Rectangle& operator--(int) override;

	Rectangle operator+(double plusSize);
	Rectangle operator-(double minusSize);

	virtual bool operator==(const Shape &r)const ;
	virtual bool operator!=(const Shape &r)const ;

	virtual bool operator>(const Shape &r) const;
	virtual bool operator<(const Shape &r) const;
	virtual bool operator>=(const Shape &r) const;
	virtual bool operator<=(const Shape &r) const;

	static double staticRecArea(const Rectangle &r1);
	static double staticRecPerimeter(const Rectangle &r1);


private:
	double height;
	double width;
	//double cor_x;
	//double cor_y;

	static int areaCounter;
	static double totalArea;

	static int perimeterCounter;
	static double totalPerimeter;
};

ostream& operator<<(ostream &out, const Rectangle &r1);

}
#endif
