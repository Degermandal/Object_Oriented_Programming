#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include <fstream>

using namespace std;

class Rectangle{

public:  
	//CONSTRUCTORS
	//rectangle class icin yazdigim constructorlar degisik durumlar icin
	Rectangle(): height(200), width(350), cor_x(0), cor_y(0) 
	{ areaCounter++;
	  perimeterCounter++;	};
	Rectangle(double h, double w, double x, double y): height(h), width(w), cor_x(x), cor_y(y) 
	{ areaCounter++;
	  perimeterCounter++;	};
	Rectangle(double h, double w): height(h), width(w), cor_x(0), cor_y(0)
	{ areaCounter++;
	  perimeterCounter++;	};
		//height ve width verdigim constructor icin de 2 double alan constructor tanimladigim icin int ignore verdim
	Rectangle(double x, double y, int ignore): height(200), width(350), cor_x(x), cor_y(y) 
	{ areaCounter++;
	  perimeterCounter++;	};

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
	//void draw(ofstream &outfile);

	double recPerimeter() const;
	double recArea() const;
	
	friend ostream& operator<<(ostream &out, const Rectangle &r1);

	Rectangle& operator++();
	Rectangle& operator--();
	Rectangle operator++(int);
	Rectangle operator--(int);

	Rectangle operator+(double plusSize);
	Rectangle operator-(double minusSize);

	friend bool operator==(const Rectangle &r1, const Rectangle &r2);
	friend bool operator!=(const Rectangle &r1, const Rectangle &r2);
	friend bool operator>(const Rectangle &r1, const Rectangle &r2);
	friend bool operator<(const Rectangle &r1, const Rectangle &r2);
	friend bool operator>=(const Rectangle &r1, const Rectangle &r2);
	friend bool operator<=(const Rectangle &r1, const Rectangle &r2);

	static double staticRecArea(const Rectangle &r1);
	static double staticRecPerimeter(const Rectangle &r1);


private:
	double height;
	double width;
	double cor_x;
	double cor_y;

	static int areaCounter;
	static double totalArea;

	static int perimeterCounter;
	static double totalPerimeter;
};
#endif
