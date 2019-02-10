#include "ComposedShape.h"

using namespace std;

//#######################################################################################################
//asagidaki fonksiyonlari yoruma almamin nedeni hata vermeleri 
//ama yine de gormenizi istedim bu seilde yapmaya calistim cogunlukta inner classta hata aldim
//########################################################################################################

/*
ComposedShape::ShapeElem& ComposedShape::operator[](const int index)
{
    return elemVec[index];
}

 void ComposedShape::operator+=(Triangle &t)
 {
 	// elemVec.push_back(ComposedShape::ShapeElem::triangle);
 }
 

 void ComposedShape::operator+=(const Circle &c)
 {
   // elemVec.push_back(ComposedShape::ShapeElem::rectangle);  
 }
 
 void ComposedShape::operator+=(const Rectangle &r )
 {
   // elemVec.push_back(ComposedShape::ShapeElem::rectangle);  
 }

ostream& operator<<(ostream &out, const ComposedShape::ShapeElem &se)
{
    if(elem.type == ComposedShape::_Shapes::rectangle)
    {      
        out << *static_cast< Rectangle * > (se.ptr);
    }
    else if(elem.type == ComposedShape::_Shapes::::triangle)
    {
        out << *static_cast< Triangle * > (se.ptr);
    }
    else if(elem.type == ComposedShape::_Shapes::circle)
    {
        out << *static_cast< Circle * > (se.ptr);
    }
    
    else
        cout<<"SHAPEELEM operator<< ERROR\n";
    
    return out;

}

double ComposedShape::ShapeElem::innerPerimeter() const
{
    if(ComposedShape.elem.type == ComposedShape::ShapeElem::rectangle)
    {
        return small_rec.recPerimeter();
    }
    else if(ComposedShape::ShapeElem::type == ComposedShape::ShapeElem::triangle)
    {
        return small_tri.triPerimeter();
    }
    else if(ComposedShape::ShapeElem::type == ComposedShape::ShapeElem::circle)
    {
        return small_cir.cirPerimeter();
    }
    else
        cout<<"SHAPEELEM perimeter function ERROR\n";
}

double ComposedShape::ShapeElem::innerArea() const
{
    if(ComposedShape::ShapeElem::type == ComposedShape::ShapeElem::rectangle)
    {
        return small_rec.recArea();
    }
    else if(ComposedShape::ShapeElem::type == ComposedShape::ShapeElem::triangle)
    {
        return small_tri.triArea();
    }
    else if(ComposedShape::ShapeElem::type == ComposedShape::ShapeElem::circle)
    {
        return small_cir.cirArea();
    }
    else
        cout<<"SHAPEELEM area function ERROR\n";
}
//#######################################################################################
//bu fonksiyonu ornek olsun diye koydum yukaridaki fonksiyonlari kullanmaya calistim
//#######################################################################################
void ComposedShape::optimalTri_Rec(ofstream &svgFile)
{
	svgFile<<main_tri;

	double halfEdge = main_tri.getEdge()/2;

	double newDistance = main_tri.getEdge() - (2.0/3 * sqrt(3)*small_rec.getHeight());//yukari cikildikta azalan alt kenar uzunlugu icin newdistance beliledim
	double x = small_rec.getHeight()*sqrt(3) / 3.0;//ucgen ve dikdortgenime gore matematiksel x ve y belirledim
	double y = halfEdge*sqrt(3) - small_rec.getHeight();
	int count = 1;//dongu icin

	int num = 0;
        int k = 0;
	while(newDistance >= small_rec.getWidth())//en az dikdortgenin genisligi kadar olmali
	{
		double numOfRec = newDistance/small_rec.getWidth();//en alta kac tane dikdortgen gelecegi

		for(int i = 0; i<numOfRec; i++)
		{
			Rectangle obj(small_rec.getHeight(), small_rec.getWidth(), x, y);
			//aslinda bizden istedigin overloading fonksiyonu
			main_tri += obj;
			//onun yerine de kullanilabilecek mantik
			///elemVec.push_back(obj);
			num++;                       
            
            //bizden istenilen
            svgFile<<small_rec[k]; 

            //asil mantigi        
			//svgFile<<elemVec[k];
            k++;
                        
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
*/


//########################################################################################
//icindeki vektore gore svgfile dosyasina yazdiriyor
//icindeki degiskenler icin vektordeki degiskenleri kullandim. 
//vektorleri kullanmadan once optimalFit icin yazdigim uygun fonksiyonda dolduruyorum

//...................................................................................................
void ComposedShape::draw(ofstream &svgFile,vector <Triangle> vTri)
{
	for(int i =0; i<vTri.size(); i++)
	{
		svgFile << "<polygon fill=\"green\" points = \"" << vTri[i].getX1() << "," << vTri[i].getY1() <<" " << vTri[i].getX2() <<","<< 
				vTri[i].getY2()<<" "<< vTri[i].getX3() << "," << vTri[i].getY3() << "\" stroke = \"black\" stroke-width = \"1\" />\n";
	}

}

void ComposedShape::draw(ofstream &svgFile, vector <Rectangle> vRec)
{
	for(int i =0; i<vRec.size(); i++)
	{
		svgFile<<"<rect x = \"" <<vRec[i].getX()<< "\" y = \"" <<vRec[i].getY()<< "\" width=\"" <<vRec[i].getWidth()<< 
					 "\" height=\"" <<vRec[i].getHeight()<< "\" fill=\"green\" stroke = \"black\" stroke-width = \"1\" />\n";
	}
}

void ComposedShape::draw(ofstream &svgFile, vector <Circle> vCir)
{
	for(int i =0; i<vCir.size(); i++)
	{
		svgFile<<"<circle cx = \"" <<vCir[i].getX()<< "\" cy = \"" << vCir[i].getY() << "\" r=\"" << vCir[i].getRadius() << 
				"\" fill=\"green\" stroke = \"black\" stroke-width = \"1\" />\n";
	}
}

//.................................................................................................
//###########################################################################################################
//ASAGIDAKI FONKSIYONLAR 2. ODEVDE YAZDIKLARIM


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

//#############################################################################################################
//optimalFit icin 9 tane degisik tipte fonksiyon yazdim
//yukarida atadigim objelere gore kac tane kucuk kontainer sigacagini buluyor
//ilk olarak main objeyi cizdiriyorum

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
			Triangle obj1(small_tri.getEdge(), x, y, x+a, y+a*sqrt(3), x+small_tri.getEdge(), y);			
			vTri.push_back(obj1);

			//composedShapedeki draw fonksiyonunu cagiriyorum 1 tane kucuk container ciziyor
			draw(svgFile, vTri);

			num++;

			//ters  ucgenlerim
			Triangle obj2(small_tri.getEdge(), x+small_tri.getEdge(), y, x+a, y+a*sqrt(3), x+small_tri.getEdge()+a, y+a*sqrt(3));
			vTri.push_back(obj2);

			draw(svgFile, vTri);

			x += small_tri.getEdge();
			num++;
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
			Triangle obj1(small_tri.getEdge(), x + smallHalfEdge, y +mainHalfEdge*sqrt(3)- smallHalfEdge*sqrt(3), x, y+mainHalfEdge*sqrt(3),
						x+small_tri.getEdge(), y+mainHalfEdge*sqrt(3)); 
			vTri.push_back(obj1);
			num++;

			draw(svgFile, vTri);

			Triangle obj2(small_tri.getEdge(), x+ smallHalfEdge, y +mainHalfEdge*sqrt(3)- smallHalfEdge*sqrt(3), 
					x+small_tri.getEdge(), y+mainHalfEdge*sqrt(3), x+small_tri.getEdge()+smallHalfEdge, y+mainHalfEdge*sqrt(3)- smallHalfEdge*sqrt(3));
			vTri.push_back(obj2);
			num++;

			draw(svgFile, vTri);
			
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
			Rectangle obj(small_rec.getHeight(), small_rec.getWidth(), x, y);
			vRec.push_back(obj);
			num++;

			draw(svgFile, vRec);
	
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
	svgFile<<main_tri;//buyuk 

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
			Circle obj(small_cir.getRadius(), x, y);
			vCir.push_back(obj);
			num++;

			draw(svgFile, vCir);

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
	svgFile<<main_cir;//buyuk 

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
				Circle obj(small_cir.getRadius(), x, y);
				vCir.push_back(obj);
				num++;

				draw(svgFile, vCir);
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
	svgFile<<main_cir;//buyuk 

	double diago = sqrt(pow(small_rec.getWidth(),2) + pow(small_rec.getHeight(),2)); //dikdorgenin kosegen uzunlugu
	double Rr = main_cir.getRadius()/diago;//kosegene gore main cemberin yaricapina ne kadar dikdorgen sigacagi

	double x = main_cir.getRadius() - (Rr*small_rec.getWidth());
	double y = main_cir.getRadius() - (Rr*small_rec.getHeight());

	int num = 0;
	for(int i = 0; i<= (2*Rr*small_rec.getHeight()); i+=small_rec.getHeight())
	{
		for(int j = 0; j<= (2*Rr*small_rec.getWidth()); j+=small_rec.getWidth())
		{
			Rectangle obj(small_rec.getHeight(), small_rec.getWidth(), x, y);
			vRec.push_back(obj);
			num++;

			draw(svgFile, vRec);

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
	svgFile<<main_rec;//buyuk 

	double x = small_cir.getRadius();
	double y = small_cir.getRadius();
	double bRadius = 2*small_cir.getRadius();

	int num = 0;

	for(int i = bRadius; i<=main_rec.getHeight(); i+=bRadius)//mantigi asagi ve yana dogru ilerleme
	{
		for(int j = bRadius; j<= main_rec.getWidth(); j+= bRadius)
		{
			Circle obj(small_cir.getRadius(), x, y);
			vCir.push_back(obj);
			num++;

			draw(svgFile, vCir);

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
	svgFile<<main_rec;//buyuk 

	double x =0;
	double y =0;

	int num = 0;
	for(int i = small_rec.getHeight(); i<=main_rec.getHeight(); i+=small_rec.getHeight())
	{
		for(int j = small_rec.getWidth(); j<= main_rec.getWidth(); j+= small_rec.getWidth())
		{
			Rectangle obj(small_rec.getHeight(), small_rec.getWidth(), x, y);
			vRec.push_back(obj);
			num++;

			draw(svgFile, vRec);
		
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
	cout<<"I don't write this function.\n\n";
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
		cout<<"ERROR\n";

}

//...............................................................................................
//###############################################################################################