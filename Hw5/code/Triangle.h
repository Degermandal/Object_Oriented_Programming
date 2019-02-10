#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include <fstream>
#include <cmath>
#include <exception>

using namespace std;
#include "Shape.h"

namespace _shape{

class Triangle : public Shape{

public:
	//CONSTRUCTORS
	//Classim icin yazdigim constructorlar degisik durumlar icin
	Triangle() : 
		edge(300), Shape(edge/2, 0), cor_x2(0), cor_y2((getEdge()/2)*sqrt(3)), cor_x3(getEdge()), cor_y3((getEdge()/2)*sqrt(3))
	{ 
		areaCounter++;
	    perimeterCounter++;	
	};
	Triangle(double e, double x1, double y1, double x2, double y2, double x3, double y3): 
		edge(e), Shape(x1, y1), cor_x2(x2), cor_y2(y2), cor_x3(x3), cor_y3(y3) 
	{ 
		areaCounter++;
	    perimeterCounter++;	
	};

	Triangle(double e): 
		edge(e), Shape(edge/2, 0), cor_x2(0), cor_y2(getEdge()/2*sqrt(3)), cor_x3(getEdge()), cor_y3(getEdge()/2*sqrt(3))
	{ 
		areaCounter++;
	    perimeterCounter++;	
	};
	Triangle(double x1, double y1, double x2, double y2, double x3, double y3): 
		edge(300), Shape(x1, y1), cor_x2(x2), cor_y2(y2), cor_x3(x3), cor_y3(y3)
	{ 
		areaCounter++;
	    perimeterCounter++;	
	};

	//ACCESSOR FUNCTIONS
	//bunlar da get fonksiyonlarim privatedaki degiskenlerim icin
	inline double getEdge() const {return edge; };
	//inline double getX1() const {return cor_x1; };
	//inline double getY1() const {return cor_y1; };
	inline double getX2() const {return cor_x2; };
	inline double getY2() const {return cor_y2; };
	inline double getX3() const {return cor_x3; };
	inline double getY3() const {return cor_y3; };

	//MUTATOR FUNCTIONS
	void setEdge(double e);
	//void setX1(double x1);
	//void setY1(double y1);
	void setX2(double x2);
	void setY2(double y2);
	void setX3(double x3);
	void setY3(double y3);

	virtual double Perimeter() const override;
	virtual double Area() const override;

	

	virtual Triangle& operator++() override;
	virtual Triangle& operator--() override;
	virtual Triangle& operator++(int) override;
	virtual Triangle& operator--(int) override;

	Triangle operator+(double plusSize);
	Triangle operator-(double minusSize);

	virtual bool operator==(const Shape &t) const;
	virtual bool operator!=(const Shape &t) const;

	virtual bool operator>(const Shape &t) const;
	virtual bool operator<(const Shape &t) const;
	virtual bool operator>=(const Shape &t) const;
	virtual bool operator<=(const Shape &t) const;

	static double staticTriArea(const Triangle &t1);
	static double staticTriPerimeter(const Triangle &t1);

private:
	double edge;
	//double cor_x1; //her bir nokta icin degisken tuttum
	//double cor_y1;
	double cor_x2;
	double cor_y2;
	double cor_x3;
	double cor_y3;

	static int areaCounter;
	static double totalArea;

	static int perimeterCounter;
	static double totalPerimeter;

};

ostream& operator<<(ostream &out, const Triangle &t1);
}
#endif
