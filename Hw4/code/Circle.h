#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include <fstream>
#define PI 3.1415

using namespace std;

class Circle{

public:
	//CONSTRUCTORS
	//Classim icin yazdigim constructorlar degisik durumlar icin
	Circle(): radius(80), cor_x(radius), cor_y(radius) 
	{ areaCounter++;
	  perimeterCounter++;	};
	Circle(double r, double x, double y): radius(r), cor_x(x), cor_y(y) 
	{	areaCounter++;
	 	perimeterCounter++;	};
	Circle(double r): radius(r), cor_x(radius), cor_y(radius)
	{	areaCounter++;
	 	perimeterCounter++;	};
	Circle(double x, double y): radius(80), cor_x(x), cor_y(y)
	{	areaCounter++;
	 	perimeterCounter++;	};

	//ACCESSOR FUNCTIONS
	//bunlar da get fonksiyonlarim privatedaki degiskenlerim icin
	inline double getRadius() const {return radius; };
	inline double getX() const {return cor_x; };
	inline double getY() const {return cor_y; };

	//MUTATOR FUNCTIONS
	void setRadius(double r);
	void setX(double x);
	void setY(double y);

	//circle a ozel yazdigim draw function
	//void draw(ofstream &svgFile);

	double cirPerimeter() const;
	double cirArea() const;

	friend ostream& operator<<(ostream &out, const Circle &C1);

	Circle& operator++();
	Circle& operator--();
	Circle operator++(int);
	Circle operator--(int);

	Circle operator+(double plusSize);
	Circle operator-(double minusSize);

	friend bool operator==(const Circle &c1, const Circle &c2);
	friend bool operator!=(const Circle &c1, const Circle &c2);
	friend bool operator>(const Circle &c1, const Circle &c2);
	friend bool operator<(const Circle &c1, const Circle &c2);
	friend bool operator>=(const Circle &c1, const Circle &c2);
	friend bool operator<=(const Circle &c1, const Circle &c2);

	static double staticCirArea(const Circle &c1);
	static double staticCirPerimeter(const Circle &c1);

private:
	double radius;
	double cor_x;
	double cor_y;

	static int areaCounter;
	static double totalArea;

	static int perimeterCounter;
	static double totalPerimeter;

};

#endif