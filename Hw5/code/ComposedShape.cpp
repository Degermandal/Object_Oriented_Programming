#include "ComposedShape.h"

using namespace std;

namespace _shape{


double ComposedShape::Area() const 
{
	cout<<"ComposedShape Area function\n";
/*	
	double totalArea = 0;

	if(const Circle* ptr = dynamic_cast< const Circle*>(&c))
	{
		for(int i  = 0; i<sVec.size(); i++)
		{
			totalArea += ptr->Area();
		}

		//return totalArea;
	}

	else if(const Rectangle* ptr = dynamic_cast< const Rectangle*>(&c))
	{
		for(int i  = 0; i<sVec.size(); i++)
		{
			totalArea += ptr->Area();
		}

		//return totalArea;
	}
	else if(const Triangle* ptr = dynamic_cast< const Triangle*>(&c))
	{
 		for(int i  = 0; i<sVec.size(); i++)
		{
			totalArea += ptr->Area();
		}

		//return totalArea;
	}

	else
		cout<<"ComposedShape Area error\n";

	return totalArea;
*/
}	

double ComposedShape::Perimeter() const
{
	cout<<"ComposedShape Perimeter function\n";
/*
	//Shape *c;
	double totalPerimeter = 0;

	if(const Circle* ptr = dynamic_cast< const Circle*>(&c))
	{
		for(int i  = 0; i<sVec.size(); i++)
		{
			totalPerimeter += ptr->Perimeter();
		}

		//return totalPerimeter;
	}

	else if(const Rectangle* ptr = dynamic_cast< const Rectangle*>(&c))
	{
		for(int i  = 0; i<sVec.size(); i++)
		{
			totalPerimeter += ptr->Perimeter();
		}

		//return totalPerimeter;
	}
	else if(const Triangle* ptr = dynamic_cast< const Triangle*>(&c))
	{
 		for(int i  = 0; i<sVec.size(); i++)
		{
			totalPerimeter += ptr->Perimeter();
		}

		//return totalPerimeter;
	}

	else
		cout<<"ComposedShape Perimeter error\n";


	return totalPerimeter;
*/
}


//######################################################################################################
//9 kere overload edilmis constructor var bunlar girilen 2 class objesine gore yapilmis constructors
//...........................................................................................................

ComposedShape::ComposedShape(Rectangle rec, Triangle tri, ofstream &svgFile)
{
	main_rec = rec;// alinan parametreye gore privatemdaki objelere atiyorum
	small_tri = tri;

	myMainCon = 'R';//optimalFitte uygun fonksiyou cagirabilmek icin char atamasi yaptim
	mySmallCon = 'T';

}

ComposedShape::ComposedShape(Rectangle rec, Circle cir, ofstream &svgFile)
{
	main_rec = rec;
	small_cir = cir;

	myMainCon = 'R';
	mySmallCon = 'C';
}

ComposedShape::ComposedShape(Rectangle rec, Rectangle rec2, ofstream &svgFile)
{
	main_rec = rec;
	small_rec = rec2;

	myMainCon = 'R';
	mySmallCon = 'R';

}

ComposedShape::ComposedShape(Triangle tri, Triangle tri2, ofstream &svgFile)
{
	main_tri = tri;
	small_tri = tri2;

	myMainCon = 'T';
	mySmallCon = 'T';
}

ComposedShape::ComposedShape(Triangle tri, Rectangle rec, ofstream &svgFile)
{
	main_tri = tri;
	small_rec = rec;

	myMainCon = 'T';
	mySmallCon = 'R';
}

ComposedShape::ComposedShape(Triangle tri, Circle cir, ofstream &svgFile)
{
	main_tri = tri;
	small_cir = cir;

	myMainCon = 'T';
	mySmallCon = 'C';

}

ComposedShape::ComposedShape(Circle cir, Triangle tri, ofstream &svgFile)
{
	main_cir = cir;
	small_tri = tri;

	myMainCon = 'C';
	mySmallCon = 'T';

}

ComposedShape::ComposedShape(Circle cir, Rectangle rec, ofstream &svgFile)
{
	main_cir = cir;
	small_rec = rec;

	myMainCon = 'C';
	mySmallCon = 'R';

}

ComposedShape::ComposedShape(Circle cir, Circle cir2, ofstream &svgFile)
{
	main_cir = cir;
	small_cir = cir2;

	myMainCon = 'C';
	mySmallCon = 'C';
}

//..............................................................................................................
//##############################################################################################################


//########################################################################################
//uc ayri classima ozel ostream fonksiyonlari duruma gore secim yapiyor
//cast yapip svgfile a yazdiriyor
//...................................................................................................

ostream& operator<< (ostream &svgFile, const Shape *c)
{
	if(const Circle* ptr = dynamic_cast< const Circle*>(c))
	{
		svgFile<<"<circle cx = \"" <<ptr->getShapeX()<< "\" cy = \"" << ptr->getShapeY() << "\" r=\"" << ptr->getRadius() << 
			"\" fill=\"green\" stroke = \"black\" stroke-width = \"1\" />\n";
	}

	else if(const Rectangle* ptr = dynamic_cast< const Rectangle*>(c))
	{
		svgFile<<"<rect x = \"" << ptr->getShapeX()<< "\" y = \"" << ptr->getShapeY()<< "\" width=\"" << ptr->getWidth()<< 
			"\" height=\"" << ptr->getHeight()<< "\" fill=\"green\" stroke = \"black\" stroke-width = \"1\" />\n";
	}
	else if(const Triangle* ptr = dynamic_cast< const Triangle*>(c))
	{

		svgFile << "<polygon fill=\"green\" points = \"" << ptr->getShapeX() << "," << ptr->getShapeY() <<" " << ptr->getX2() <<","<< 
			ptr->getY2()<<" "<< ptr->getX3() << "," << ptr->getY3() << "\" stroke = \"black\" stroke-width = \"1\" />\n";
	}

	else//exception dosyam var. Throw ediyorum
		throw Exception("ComposedShape Fail -ComposedShape operator<<-!!\n");
}


//....................................................................................................
//####################################################################################################


//#####################################################################################################
//optimalFit icin 9 tane degisik tipte fonksiyon yazdim
//yukarida atadigim objelere gore kac tane kucuk container sigacagini buluyor
//ilk olarak main objeyi cizdiriyorum
//.....................................................................................................
void ComposedShape::optimalRec_Tri(ofstream &svgFile)
{
	svgFile<<main_rec;//main container

	double x = 0;
	double y = 0;
	decltype (3.55) a;
	a = small_tri.getEdge()/2;

	int num = 0; //kac tane ciziyor

	for(int i = a*sqrt(3); i<= main_rec.getHeight(); i+=(a*sqrt(3)))//yukseklik icin ilerlenmesi gereken kadar donuyor
	{
		for(int j = 1.2*small_tri.getEdge(); j<= main_rec.getWidth(); j+= small_tri.getEdge())//yana dogru kac tane ucgen cizilecegi
		{
			//constructora verileri girip ona gore obje olusmasini sagliyorum
			//olusturdugum objleri push back yapiyorum
			Shape *ptr = new Triangle(small_tri.getEdge(), x, y, x+a, y+a*sqrt(3), x+small_tri.getEdge(), y);		
			sVec.push_back(ptr);
			svgFile<<sVec[num];//vectore attigimi dosyay yaziyorum

			num++;

			//ters  ucgenlerim
			ptr = new Triangle(small_tri.getEdge(), x+small_tri.getEdge(), y, x+a, y+a*sqrt(3), x+small_tri.getEdge()+a, y+a*sqrt(3));
			sVec.push_back(ptr);
			svgFile<<sVec[num];
			num++;

			x += small_tri.getEdge();	
		}

		x =0;
		y+=a*sqrt(3);
	}

	auto bigArea = main_rec.getHeight() * main_rec.getWidth();
	auto smallArea = num * (small_tri.getEdge() * small_tri.getEdge() * sqrt(3)) / 4;
	auto area = bigArea - smallArea; 


	cout<< "I can fit at most "<<num<< " small shapes into the main container."<<
		" The empty area (red) in container is " <<area<<".\n\n";

}


void ComposedShape::optimalTri_Tri(ofstream &svgFile)
{
	svgFile<<main_tri;//buyuk 

	double mainHalfEdge = main_tri.getEdge()/2;

	decltype(mainHalfEdge * 3.5) smallHalfEdge;
	decltype(smallHalfEdge * 3.5) newDistance;

	smallHalfEdge = small_tri.getEdge()/2;
	newDistance =  main_tri.getEdge(); //newdistance degiskenim benim alt cigimi tutuyor x koordinatinda ne kadar gidecegimi

	double x = 0;
	double y = 0;
	int count = 1;//dongu icin tuttun kac defa dondugunu buluyorum

	int num = 0;
	while(newDistance > small_tri.getEdge())//newdistance kucuk ucgenin bir kenari oluncaya kadar (ne kadar yukari cikacagi)
	{
		double numOfRec = newDistance/small_tri.getEdge();//kac tane yerlestirebiliyorum x koordinati boyunca

		for(int i = 1; i<numOfRec; i++)
		{
			//duz kucuk ucgenlerimin koordinatlari
			Shape  *ptr = new Triangle(small_tri.getEdge(), x + smallHalfEdge, y +mainHalfEdge*sqrt(3)- smallHalfEdge*sqrt(3), x, y+mainHalfEdge*sqrt(3),
						x+small_tri.getEdge(), y+mainHalfEdge*sqrt(3));
			sVec.push_back(ptr);
			
			svgFile<<sVec[num];
			num++;

			ptr = new Triangle(small_tri.getEdge(), x+ smallHalfEdge, y +mainHalfEdge*sqrt(3)- smallHalfEdge*sqrt(3), 
					x+small_tri.getEdge(), y+mainHalfEdge*sqrt(3), x+small_tri.getEdge()+smallHalfEdge, y+mainHalfEdge*sqrt(3)- smallHalfEdge*sqrt(3));
			sVec.push_back(ptr);
			
			svgFile<<sVec[num];
			num++;

			x += small_tri.getEdge();//bu arttirma x koordinatinda ilerlememi sagliyor
		}

		x = 0;//x i tekrradan sifirliyorum
		x += count*smallHalfEdge;//her dongu kadar x koordinatinda ilerlemis olmam gerekiyor
		count++;//dongu icin arttirma

		newDistance -= small_tri.getEdge();//yukari dogru ilerledikce kucuk ucgenin kenari kadar azaliyor
		y -= smallHalfEdge*sqrt(3); //y koordinati her seferinde kucuk ucgenin kenar uzunlugunun yarisinin kok uc kati kadar azaliyor
	}

	auto bigArea = (main_tri.getEdge() * main_tri.getEdge() * sqrt(3)) / 4;
	auto smallArea = num * (small_tri.getEdge() * small_tri.getEdge() * sqrt(3)) / 4;
	auto area = bigArea - smallArea; 


	cout<< "I can fit at most "<<num<< " small shapes into the main container."<<
		" The empty area (red) in container is " <<area<<".\n\n";

}

void ComposedShape::optimalTri_Rec(ofstream &svgFile)
{
	svgFile<<main_tri;//buyuk 

	double halfEdge = main_tri.getEdge()/2;

	double newDistance = main_tri.getEdge() - (2.0/3 * sqrt(3)*small_rec.getHeight());//yukari cikildikta azalan alt kenar uzunlugu icin newdistance beliledim
	double x = small_rec.getHeight()*sqrt(3) / 3.0;//ucgen ve dikdortgenime gore matematiksel x ve y belirledim
	double y = halfEdge*sqrt(3) - small_rec.getHeight();
	int count = 1;//dongu icin

	int num = 0;

	while(newDistance >= small_rec.getWidth())//en az dikdortgenin genisligi kadar olmali
	{
		double numOfRec = newDistance/small_rec.getWidth();//en alta kac tane dikdortgen gelecegi

		for(int i = 0; i<numOfRec; i++)
		{
			//Rectangle obj(small_rec.getHeight(), small_rec.getWidth(), x, y);
			Shape *ptr = new Rectangle(small_rec.getHeight(), small_rec.getWidth(), x, y);
			sVec.push_back(ptr);
			
			svgFile << sVec[num];
			num++;

			x += small_rec.getWidth();
		}

		x = small_rec.getHeight()*sqrt(3) / 3.0 + (small_rec.getWidth()/3*count);//matematiksel olarak degisen degerler
		newDistance -= (2.0/3*sqrt(3)*small_rec.getHeight());
		y -= small_rec.getHeight();
		count++;
	}

	auto bigArea = (main_tri.getEdge() * main_tri.getEdge() * sqrt(3)) / 4;
	auto smallArea = num*(small_rec.getHeight() * small_rec.getWidth());
	auto area = bigArea - smallArea; 


	cout<< "I can fit at most "<<num<< " small shapes into the main container."<<
		" The empty area (red) in container is " <<area<<".\n\n";
	
}

void ComposedShape::optimalTri_Cir(ofstream &svgFile)
{
	svgFile << main_tri;//buyuk 

	double halfEdge = main_tri.getEdge()/2;
	double sDiameter = 2*small_cir.getRadius();

	double distance = main_tri.getEdge() / sDiameter;
	double x = small_cir.getRadius()*sqrt(3);
	double y = halfEdge*sqrt(3) - small_cir.getRadius();	

	int count = 1;

	int num = 0;
	while(main_tri.getEdge() >= sDiameter)
	{
		for(int i = 2; i<distance; i++)
		{
			Shape *ptr = new Circle(small_cir.getRadius(), x, y);
			sVec.push_back(ptr);
			
			svgFile << sVec[num];
			num++;

			x += sDiameter;
		}

		auto lvalue = main_tri.getEdge()*(0.8);

		main_tri.setEdge(lvalue);
		distance = main_tri.getEdge() / sDiameter;
		x = small_cir.getRadius()*sqrt(3) + (sDiameter/1.4)*count;
		count++;
		y -= sDiameter;
	}

	auto bigArea = (main_tri.getEdge() * main_tri.getEdge() * sqrt(3)) / 4;
	auto smallArea = num*(PI * pow(small_cir.getRadius(), 2));
	auto area = bigArea - smallArea; 


	cout<< "I can fit at most "<<num<< " small shapes into the main container."<<
		" The empty area (red) in container is " <<area<<".\n\n";

}

void ComposedShape::optimalCir_Cir(ofstream &svgFile)
{
	svgFile << main_cir;//buyuk 

	double sDiameter = 2*small_cir.getRadius();
	double Rr = main_cir.getRadius()/sDiameter;//kac tane cember sigar

	double x = main_cir.getRadius() - (Rr*sDiameter) + small_cir.getRadius();//matematiksel koordinatlar
	double y = main_cir.getRadius() - (Rr*sDiameter) + small_cir.getRadius();

	int num = 0;
	for(int i = sDiameter; i<= (2*Rr*sDiameter); i+=sDiameter)//ilerleme mikarlari
	{
		for(int j = sDiameter; j<=2*Rr*sDiameter; j+=sDiameter)
		{
			if((pow(x - main_cir.getRadius(), 2) + pow(y - main_cir.getRadius(), 2)) < pow(main_cir.getRadius(), 2) )
			{
				Shape *ptr = new Circle(small_cir.getRadius(), x, y);
				sVec.push_back(ptr);
				svgFile << sVec[num];
				num++;
			}
			x += sDiameter;
		}

		x = main_cir.getRadius() - (Rr*sDiameter)+small_cir.getRadius();
		y+=sDiameter;
	}

	auto bigArea = PI * pow(main_cir.getRadius(), 2);
	auto smallArea = num*(PI * pow(small_cir.getRadius(), 2));
	auto area = bigArea - smallArea; 


	cout<< "I can fit at most "<<num<< " small shapes into the main container."<<
		" The empty area (red) in container is " <<area<<".\n\n";

}

void ComposedShape::optimalCir_Rec(ofstream &svgFile)
{
	svgFile << main_cir;//buyuk 

	double diago = sqrt(pow(small_rec.getWidth(),2) + pow(small_rec.getHeight(),2)); //dikdorgenin kosegen uzunlugu
	double Rr = main_cir.getRadius()/diago;//kosegene gore main cemberin yaricapina ne kadar dikdorgen sigacagi

	double x = main_cir.getRadius() - (Rr*small_rec.getWidth());
	double y = main_cir.getRadius() - (Rr*small_rec.getHeight());

	int num = 0;
	for(int i = 0; i<= (2*Rr*small_rec.getHeight()); i+=small_rec.getHeight())
	{
		for(int j = 0; j<= (2*Rr*small_rec.getWidth()); j+=small_rec.getWidth())
		{
			Shape *ptr = new Rectangle(small_rec.getHeight(), small_rec.getWidth(), x, y);
			sVec.push_back(ptr);

			svgFile << sVec[num];

			num++;

			x += small_rec.getWidth();
		}

		x = main_cir.getRadius() - (Rr*small_rec.getWidth());
		y+=small_rec.getHeight();
	}

	auto bigArea = PI * pow(main_cir.getRadius(), 2);
	auto smallArea = num*(small_rec.getHeight() * small_rec.getWidth());
	auto area = bigArea - smallArea; 


	cout<< "I can fit at most "<<num<< " small shapes into the main container."<<
		" The empty area (red) in container is " <<area<<".\n\n";
	
}

void ComposedShape::optimalRec_Cir(ofstream &svgFile)
{
	svgFile << main_rec;//buyuk 

	double x = small_cir.getRadius();
	double y = small_cir.getRadius();
	double bRadius = 2*small_cir.getRadius();

	int num = 0;

	for(int i = bRadius; i<=main_rec.getHeight(); i+=bRadius)//mantigi asagi ve yana dogru ilerleme
	{
		for(int j = bRadius; j<= main_rec.getWidth(); j+= bRadius)
		{
			Shape *ptr = new Circle(small_cir.getRadius(), x, y);
			sVec.push_back(ptr);

			svgFile << sVec[num];
			num++;
			x += bRadius;
		}

		x = small_cir.getRadius();
		y+= bRadius;
	}

	auto bigArea = main_rec.getHeight() * main_rec.getWidth();
	auto smallArea = num*(PI * pow(small_cir.getRadius(), 2));
	auto area = bigArea - smallArea; 


	cout<< "I can fit at most "<<num<< " small shapes into the main container."<<
		" The empty area (red) in container is " <<area<<".\n\n";

}

void ComposedShape::optimalRec_Rec(ofstream &svgFile)
{
	svgFile << main_rec;//buyuk 

	double x =0;
	double y =0;

	int num = 0;
	for(int i = small_rec.getHeight(); i<=main_rec.getHeight(); i+=small_rec.getHeight())
	{
		for(int j = small_rec.getWidth(); j<= main_rec.getWidth(); j+= small_rec.getWidth())
		{
			Shape *ptr = new Rectangle(small_rec.getHeight(), small_rec.getWidth(), x, y);
			Rectangle *rr = dynamic_cast<Rectangle*> (ptr);
			sVec.push_back(rr);

			svgFile << sVec[num];
		
			num++;

			x += small_rec.getWidth();
		}

		x = 0;
		y+= small_rec.getHeight();
	}

	auto bigArea = main_rec.getHeight() * main_rec.getWidth(); 
	auto smallArea = num*(small_rec.getHeight() * small_rec.getWidth());
	auto area = bigArea - smallArea; 

	cout<< "I can fit at most "<<num<< " small shapes into the main container."<<
		" The empty area (red) in container is " <<area<<".\n\n";

}

void ComposedShape::optimalCir_Tri(ofstream &svgFile)
{
	svgFile<<main_cir;//main container

	double x = (main_cir) .getRadius()/2;
	double y = (main_cir) .getRadius()/2;
	decltype (3.55) a;
	a = small_tri.getEdge()/2;

	int num = 0; //kac tane ciziyor

	for(int i = 0; i<= main_cir.getRadius(); i+=(a*sqrt(3)))//yukseklik icin ilerlenmesi gereken kadar donuyor
	{
		for(int j = 0; j<= main_cir.getRadius()*2; j+= small_tri.getEdge())//yana dogru kac tane ucgen cizilecegi
		{			
			Shape *ptr = new Triangle(small_tri.getEdge(), x, y, x+a, y+a*sqrt(3), x+small_tri.getEdge(), y);
			Triangle *tt = dynamic_cast<Triangle*> (ptr);
			sVec.push_back(tt);

			svgFile << sVec[num];
		

			num++;

			ptr = new Triangle(small_tri.getEdge(), x+small_tri.getEdge(), y, x+a, y+a*sqrt(3), x+small_tri.getEdge()+a, y+a*sqrt(3));
			Triangle *tt2 = dynamic_cast<Triangle*> (ptr);
			sVec.push_back(tt2);

			svgFile << sVec[num];
			num++;

			x += small_tri.getEdge();
		}

		x =0;
		y+=a*sqrt(3);
	}

	auto bigArea = PI * pow(main_cir.getRadius(), 2);
	auto smallArea = num * (small_tri.getEdge() * small_tri.getEdge() * sqrt(3)) / 4;
	auto area = bigArea - smallArea;


	cout<< "I can fit at most "<<num<< " small shapes into the main container."<<
		" The empty area (red) in container is " <<area<<".\n\n";
}

//...................................................................................................
//####################################################################################################


//############################################################################################################
//..........................................................................................................
//optimalFit fonksiyonum yukari yazdigim asil fonksiyonlarimi bilestirdim.
// buna da constructorda atadigim char degerlerine gore karar verdim

void ComposedShape::optimalFit(ofstream &svgFile)
{
	if(myMainCon == 'R' && mySmallCon == 'R')
	{
		optimalRec_Rec(svgFile);
	}
	else if(myMainCon == 'R' && mySmallCon == 'C')
	{
		optimalRec_Cir(svgFile);
	}
	else if(myMainCon == 'R' && mySmallCon == 'T')
	{
		optimalRec_Tri(svgFile);
	}
	else if(myMainCon == 'C' && mySmallCon == 'C')
	{
		optimalCir_Cir(svgFile);
	}
	else if(myMainCon == 'C' && mySmallCon == 'R')
	{
		optimalCir_Rec(svgFile);
	}
	else if(myMainCon == 'C' && mySmallCon == 'T')
	{
		optimalCir_Tri(svgFile);
	}
	else if(myMainCon == 'T' && mySmallCon == 'C')
	{
		optimalTri_Cir(svgFile);
	}
	else if(myMainCon == 'T' && mySmallCon == 'R')
	{
		optimalTri_Rec(svgFile);
	}
	else if(myMainCon == 'T' && mySmallCon == 'T')
	{
		optimalTri_Tri(svgFile);
	}
	else
		throw Exception("ComposedShape Fail -optimalFit-!!");

}

//...............................................................................................
//###############################################################################################



}
