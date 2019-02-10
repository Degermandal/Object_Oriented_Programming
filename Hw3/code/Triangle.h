#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;


class Triangle{

public:
	//CONSTRUCTORS
	//Classim icin yazdigim constructorlar degisik durumlar icin
	Triangle() : 
		edge(300), cor_x1(getEdge()/2), cor_y1(0), cor_x2(0), cor_y2((getEdge()/2)*sqrt(3)), cor_x3(getEdge()), cor_y3((getEdge()/2)*sqrt(3))
		{ 	areaCounter++;
	  		perimeterCounter++;	};

	Triangle(double e, double x1, double y1, double x2, double y2, double x3, double y3): 
		edge(e), cor_x1(x1), cor_y1(y1), cor_x2(x2), cor_y2(y2), cor_x3(x3), cor_y3(y3) 
		{ 	areaCounter++;
	  		perimeterCounter++;	};

	Triangle(double e): 
		edge(e), cor_x1(getEdge()/2), cor_y1(0), cor_x2(0), cor_y2(getEdge()/2*sqrt(3)), cor_x3(getEdge()), cor_y3(getEdge()/2*sqrt(3))
		{ 	areaCounter++;
	  		perimeterCounter++;	};

	Triangle(double x1, double y1, double x2, double y2, double x3, double y3): 
		edge(300), cor_x1(x1), cor_y1(y1), cor_x2(x2), cor_y2(y2), cor_x3(x3), cor_y3(y3)
		{ 	areaCounter++;
	  		perimeterCounter++;	};

	//ACCESSOR FUNCTIONS
	//bunlar da get fonksiyonlarim privatedaki degiskenlerim icin
	inline double getEdge() const {return edge; };
	inline double getX1() const {return cor_x1; };
	inline double getY1() const {return cor_y1; };
	inline double getX2() const {return cor_x2; };
	inline double getY2() const {return cor_y2; };
	inline double getX3() const {return cor_x3; };
	inline double getY3() const {return cor_y3; };

	//MUTATOR FUNCTIONS
	void setEdge(double e);
	void setX1(double x1);
	void setY1(double y1);
	void setX2(double x2);
	void setY2(double y2);
	void setX3(double x3);
	void setY3(double y3);

	//Triangle a ozel yazdigim draw function
	//void draw(ofstream &svgFile) const;

	double triPerimeter() const;
	double triArea() const;

	friend ostream& operator<<(ostream &out, const Triangle &t1);
	Triangle& operator++();
	Triangle& operator--();
	Triangle operator++(int);
	Triangle operator--(int);

	Triangle operator+(double plusSize);
	Triangle operator-(double minusSize);

	friend bool operator==(const Triangle &t1, const Triangle &t2);
	friend bool operator!=(const Triangle &t1, const Triangle &t2);
	friend bool operator>(const Triangle &t1, const Triangle &t2);
	friend bool operator<(const Triangle &t1, const Triangle &t2);
	friend bool operator>=(const Triangle &t1, const Triangle &t2);
	friend bool operator<=(const Triangle &t1, const Triangle &t2);

	static double staticTriArea(const Triangle &t1);
	static double staticTriPerimeter(const Triangle &t1);

private:
	double edge;
	double cor_x1; //her bir nokta icin degisken tuttum
	double cor_y1;
	double cor_x2;
	double cor_y2;
	double cor_x3;
	double cor_y3;

	static int areaCounter;
	static double totalArea;

	static int perimeterCounter;
	static double totalPerimeter;

};
#endif
