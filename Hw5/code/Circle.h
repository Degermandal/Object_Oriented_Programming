#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include <fstream>
#include <exception>
#define PI 3.1415

using namespace std;
#include "Shape.h"

namespace _shape{

class Circle : public Shape{

public:
	//CONSTRUCTORS
	//Classim icin yazdigim constructorlar degisik durumlar icin
	Circle(): radius(80), Shape(radius, radius) 
	{ 
		areaCounter++;
	    perimeterCounter++;	
	};
	Circle(double r, double x, double y): radius(r), Shape(x, y)
	{ 
		areaCounter++;
	    perimeterCounter++;	
	};
	Circle(double r): radius(r), Shape(radius, radius)
	{ 
		areaCounter++;
	    perimeterCounter++;	
	};
	Circle(double x, double y): radius(80), Shape(x, y)
	{ 
		areaCounter++;
	    perimeterCounter++;	
	};

	//ACCESSOR FUNCTIONS
	//bunlar da get fonksiyonlarim privatedaki degiskenlerim icin
	inline double getRadius() const {return radius; };
	//inline double getX() const {return cor_x; };
	//inline double getY() const {return cor_y; };

	//MUTATOR FUNCTIONS
	void setRadius(double r);
	//void setX(double x);
	//void setY(double y);

	virtual double Perimeter() const override;
	virtual double Area() const override;


	virtual Circle& operator++() override;
	virtual Circle& operator--() override;
	virtual Circle& operator++(int) override;
	virtual Circle& operator--(int) override;

	Circle operator+(double plusSize);
	Circle operator-(double minusSize);

	virtual bool operator==(const Shape &c) const override;
	virtual bool operator!=(const Shape &c) const override;

	virtual bool operator>(const Shape &c) const override;
	virtual bool operator<(const Shape &c) const override;
	virtual bool operator>=(const Shape &c) const override;
	virtual bool operator<=(const Shape &c) const override;

	static double staticCirArea(const Circle &c1);
	static double staticCirPerimeter(const Circle &c1);

private:
	double radius;
	//double cor_x;
	//double cor_y;

	static int areaCounter;
	static double totalArea;

	static int perimeterCounter;
	static double totalPerimeter;

};

	ostream& operator<<(ostream &out, const Circle &C1);
}
#endif