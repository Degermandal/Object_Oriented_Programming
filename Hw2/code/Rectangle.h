#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include <fstream>

using namespace std;

class Rectangle{

public:  
	//CONSTRUCTORS
	//rectangle class icin yazdigim constructorlar degisik durumlar icin
	Rectangle(): height(200), width(350), cor_x(0), cor_y(0) {	};
	Rectangle(double h, double w, double x, double y): height(h), width(w), cor_x(x), cor_y(y) {	};
	Rectangle(double h, double w): height(h), width(w), cor_x(0), cor_y(0) {	};
	//Rectangle(double x, double y): height(200), width(350), cor_x(x), cor_y(y) {	};

	//ACCESSOR FUNCTIONS
	//bunlar da get fonksiyonlarim privatedaki degiskenlerim icin
	inline int getHeight() const {return height; };
	inline int getWidth() const {return width; };
	inline double getX() const {return cor_x; };
	inline double getY() const {return cor_y; };

	//MUTATOR FUNCTIONS
	void setHeight(int h);
	void setWidth(int w);
	void setX(double x);
	void setY(double y);

	//rectangle a ozel yazdigim draw function
	void draw(ofstream &outfile);

private:
	double height;
	double width;
	double cor_x;
	double cor_y;
};
#endif
