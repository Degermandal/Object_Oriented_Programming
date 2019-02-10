#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include <fstream>

using namespace std;

class Circle{

public:
	//CONSTRUCTORS
	//Classim icin yazdigim constructorlar degisik durumlar icin
	Circle(): radius(80), cor_x(radius), cor_y(radius) {	};
	Circle(double r, double x, double y): radius(r), cor_x(x), cor_y(y) {	};
	Circle(double r): radius(r), cor_x(radius), cor_y(radius) {	};
	Circle(double x, double y): radius(80), cor_x(x), cor_y(y) {	};

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
	void draw(ofstream &svgFile);

private:
	double radius;
	double cor_x;
	double cor_y;

};
#endif