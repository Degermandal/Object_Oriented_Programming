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

#define PI 3.1415

using namespace std;

class ComposedShape{

public:
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

	//Draw fonksiyonumu overload ettim cunku 3 fakli classtan vektor tanimladim
	void draw(ofstream &svgFile, vector <Triangle> vTri);
	void draw(ofstream &svgFile, vector <Rectangle> vRec);
	void draw(ofstream &svgFile, vector <Circle> vCir);

	//vectorler icin accessor functions
	inline vector <Rectangle> getRecVec() const { return vRec; };
	inline vector <Triangle> getTriVec() const { return vTri; };
	inline vector <Circle> getCirVec() const { return vCir; };

private:
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
	
	//small containerlari yerlestirmek icin kullandigim vektorlerim
	vector<Rectangle> vRec; 
	vector<Triangle> vTri;
	vector<Circle> vCir; 

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