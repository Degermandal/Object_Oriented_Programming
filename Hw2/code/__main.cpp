#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
#include "ComposedShape.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>


using namespace std;

//#########################################################################################################

//##########################################################################################################



int main()
{
	//9 svg dosyam icin ofstream objesi olusturdum
	ofstream svgFile1;
	ofstream svgFile2;
	ofstream svgFile3;
	ofstream svgFile4;
	ofstream svgFile5;
	ofstream svgFile6;
	ofstream svgFile7;
	ofstream svgFile8;
	ofstream svgFile9;

	//9 tane 9 actim
	svgFile1.open("F1.svg");
	svgFile2.open("F2.svg");
	svgFile3.open("F3.svg");
	svgFile4.open("F4.svg");
	svgFile5.open("F5.svg");
	svgFile6.open("F6.svg");
	svgFile7.open("F7.svg");
	svgFile8.open("F8.svg");
	svgFile9.open("F9.svg");

	//ilk svg dosyasinin caisabilmesi icin gerekli olan ve ekran buyuklugunu yazdirdim
	svgFile1<<"<svg version = \"1.1\" baseProfile = \"full\" width = \"1000\" height = \"1000\" "
	<<" xmlns=\"http://www.w3.org/2000/svg\">\n";
	svgFile2<<"<svg version = \"1.1\" baseProfile = \"full\" width = \"1000\" height = \"1000\" "
	<<" xmlns=\"http://www.w3.org/2000/svg\">\n";
	svgFile3<<"<svg version = \"1.1\" baseProfile = \"full\" width = \"1000\" height = \"1000\" "
	<<" xmlns=\"http://www.w3.org/2000/svg\">\n";	
	svgFile4<<"<svg version = \"1.1\" baseProfile = \"full\" width = \"1000\" height = \"1000\" "
	<<" xmlns=\"http://www.w3.org/2000/svg\">\n";
	svgFile5<<"<svg version = \"1.1\" baseProfile = \"full\" width = \"1000\" height = \"1000\" "
	<<" xmlns=\"http://www.w3.org/2000/svg\">\n";
	svgFile6<<"<svg version = \"1.1\" baseProfile = \"full\" width = \"1000\" height = \"1000\" "
	<<" xmlns=\"http://www.w3.org/2000/svg\">\n";
	svgFile7<<"<svg version = \"1.1\" baseProfile = \"full\" width = \"1000\" height = \"1000\" "
	<<" xmlns=\"http://www.w3.org/2000/svg\">\n";
	svgFile8<<"<svg version = \"1.1\" baseProfile = \"full\" width = \"1000\" height = \"1000\" "
	<<" xmlns=\"http://www.w3.org/2000/svg\">\n";
	svgFile9<<"<svg version = \"1.1\" baseProfile = \"full\" width = \"1000\" height = \"1000\" "
	<<" xmlns=\"http://www.w3.org/2000/svg\">\n";

//########################################################################################################3

//4 ayri classimdan array objeleri olusturdum
Rectangle mRecArray[4];
Circle mCirArray[4];
Triangle mTriArray[4];
ComposedShape CS[9];

//rectangle icin manual deger atadim
Rectangle mobjR1(500.0, 600.0, 0.0, 0.0);
Rectangle mobjR2(200.0, 500.0, 0.0, 0.0);
Rectangle sobjR1(25.0, 40.0);
Rectangle sobjR2(20.0, 40.0);

//circle icin manual deger atadim
Circle mobjC1(350.0, 350.0, 350.0);
Circle mobjC2(500.0, 500.0, 500.0);
Circle sobjC1(20.0);
Circle sobjC2(38.0);

//triangle icin manual deger atadim
Triangle mobjT1(500.0);
Triangle mobjT2;
Triangle sobjT1(35.0);
Triangle sobjT2(19.0);

mRecArray[0] = mobjR1;
mRecArray[1] = mobjR2;
mRecArray[2] = sobjR1;
mRecArray[3] = sobjR2;

mCirArray[0] = mobjC1;
mCirArray[1] = mobjC2;
mCirArray[2] = sobjC1;
mCirArray[3] = sobjC2;

mTriArray[0] = mobjT1;
mTriArray[1] = mobjT2;
mTriArray[2] = sobjT1;
mTriArray[3] = sobjT2;

for(int i = 0; i<4; i++)
{
	cout<<i+1<<". shape Height: "<<mRecArray[i].getHeight()<<" Width: "<<mRecArray[i].getWidth()<<
		" X: "<< mRecArray[i].getX()<<" Y: "<<mRecArray[i].getY()<<endl;
}
cout<<"######################################################################\n";
for(int i = 0; i<4; i++)
{
	cout<<i+1<<". shape Radius: "<<mCirArray[i].getRadius()<<
	" X: "<< mCirArray[i].getX()<<" Y: "<<mCirArray[i].getY()<<endl;

}
cout<<"######################################################################\n";

for(int i = 0; i<4; i++)
{
	cout<<i+1<<". shape Edge: "<<mTriArray[i].getEdge()<< "; COORDINATES x1: "<<mTriArray[i].getX1()<<", y1: "<<mTriArray[i].getY1()<<
		", x2: "<<mTriArray[i].getX2()<<", y2: "<<mTriArray[i].getY2()<< ", x3: "<<mTriArray[i].getX3()<<", y3: "<<mTriArray[i].getY3()<<endl;

}
cout<<"######################################################################\n";

//#################################################################################################

//kendimce objleri doldurdum composedShape e
ComposedShape CSobj1(mobjR1, sobjR1,svgFile1);
ComposedShape CSobj2(mobjR2, sobjT1,svgFile2);
ComposedShape CSobj3(mobjR1, sobjC1,svgFile3);
ComposedShape CSobj4(mobjT1, sobjR1,svgFile4);
ComposedShape CSobj5(mobjT1, sobjT2,svgFile5);
ComposedShape CSobj6(mobjT1, sobjC1,svgFile6);
ComposedShape CSobj7(mobjC1, sobjR1,svgFile7);
ComposedShape CSobj8(mobjC2, sobjT2,svgFile8);
ComposedShape CSobj9(mobjC1, sobjC1,svgFile9);


//arrayimi yukarida olusturdugum objelerle doldurdum
CS[0] = CSobj1;
CS[1] = CSobj2;
CS[2] = CSobj3;
CS[3] = CSobj4;
CS[4] = CSobj5;
CS[5] = CSobj6;
CS[6] = CSobj7;
CS[7] = CSobj8;
CS[8] = CSobj9;

//her bir obje icin optimalFiti denedim
CS[0].optimalFit(svgFile1);
CS[1].optimalFit(svgFile2);
CS[2].optimalFit(svgFile3);
CS[3].optimalFit(svgFile4);
CS[4].optimalFit(svgFile5);
CS[5].optimalFit(svgFile6);
CS[6].optimalFit(svgFile7);
CS[7].optimalFit(svgFile8);
CS[8].optimalFit(svgFile9);

//###############################################################################################

//dosyalarin kapatilmasi
	svgFile1<<"</svg>";
	svgFile1.close();
	svgFile2<<"</svg>";
	svgFile2.close();
	svgFile3<<"</svg>";
	svgFile3.close();
	svgFile4<<"</svg>";
	svgFile4.close();
	svgFile5<<"</svg>";
	svgFile5.close();
	svgFile6<<"</svg>";
	svgFile6.close();
	svgFile7<<"</svg>";
	svgFile7.close();
	svgFile8<<"</svg>";
	svgFile8.close();
	svgFile9<<"</svg>";
	svgFile9.close();

	return 0;

}

