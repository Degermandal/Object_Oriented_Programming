#include <iostream>
#include <fstream>
#include <cmath>
#include <string> 
using namespace std;


void rectangleFunc(int &mWidth, int &mHeight);
void circleFunc(int &mRadius);
void triangleFunc(int &mEdge);

void Rec_RecFunc();
void Rec_CircFunc();
void Rec_TriFunc();
void Circ_RecFunc();
void Circ_CircFunc();
void Tri_CircFunc();
void Tri_RecFunc();
void Tri_TriFunc();
void Circ_TriFunc();

int main()
{

	enum class _Shapes {rectangle, circle, triangle};
	_Shapes mainShape;
	_Shapes smallShape;

	int height = 0;
	int width = 0;
	int radius = 0;
	int edge = 0;

	ofstream outfile;
	outfile.open("outfile.txt");

	cout<< "Please enter the main container shape (R, C, T)"<<endl;
	char main_shape;
	cin>>main_shape;


	if(main_shape == 'R' || main_shape == 'r')
	{
		mainShape = _Shapes::rectangle; //enum atamasi bu sayede biliyorum hangi container oldugunu
		rectangleFunc(height, width);
		outfile<<height<<endl;//verileri tutmak icin dosyaya yazdirmayi sectim dosyaya yazip dosyadan okuyorum
		outfile<<width<<endl;
	}

	else if(main_shape == 'C' || main_shape == 'c')
	{
		mainShape = _Shapes::circle;
		circleFunc(radius);
		outfile<<radius<<endl;
	}

	else if(main_shape == 'T' || main_shape == 't')
	{
		mainShape = _Shapes::triangle;
		triangleFunc(edge);
		outfile<<edge<<endl;
	}
	else
		cout<<"You enter incorrect main shape"<<endl;


	cout<< "Please enter the small shape (R, C, T)"<<endl; //yukarida yaptiklarimin aynisini small containerim icin de yaptim
	char small_shape;
	cin>>small_shape;

	if(small_shape == 'R' || small_shape == 'r')
	{
		smallShape = _Shapes::rectangle;
		rectangleFunc(height, width);
		outfile<<height<<endl;
		outfile<<width<<endl;
	}

	else if(small_shape == 'C' || small_shape == 'c')
	{
		smallShape = _Shapes::circle;
		circleFunc(radius);
		outfile<<radius<<endl;
	}

	else if(small_shape == 'T' || small_shape == 't')
	{
		smallShape = _Shapes::triangle;
		triangleFunc(edge);
		outfile<<edge<<endl;
	}

	else
		cout<<"You enter incorrect small shape"<<endl;


//enum classlari kullanarak karsilastirma yaptim
	if(mainShape == _Shapes::rectangle && smallShape == _Shapes::rectangle)
		Rec_RecFunc();

	else if(mainShape == _Shapes::rectangle && smallShape == _Shapes::circle)
		Rec_CircFunc();

	else if(mainShape == _Shapes::rectangle && smallShape == _Shapes::triangle)
		Rec_TriFunc();

	else if(mainShape == _Shapes::circle && smallShape == _Shapes::rectangle)
		Circ_RecFunc();

	else if(mainShape == _Shapes::circle && smallShape == _Shapes::circle)
		Circ_CircFunc();

	else if(mainShape == _Shapes::triangle && smallShape == _Shapes::circle)
		Tri_CircFunc();

	else if(mainShape == _Shapes::triangle && smallShape == _Shapes::rectangle)
		Tri_RecFunc();

	else if(mainShape == _Shapes::triangle && smallShape == _Shapes::triangle)
		Tri_TriFunc();

	else if(mainShape == _Shapes::circle && smallShape == _Shapes::triangle)
		Circ_TriFunc();
	else
		cout<<"ERROR\n";

	outfile.close();

	return 0;
}
void Circ_TriFunc()
{
	cout<<"I don't write this function\n";
}

void Tri_TriFunc()
{
	ofstream svgfile;
	svgfile.open("output.svg");//svg bilgilerini yazmak icin actigim dosya

	ifstream infile;
	infile.open("outfile.txt");//bu dosyayi aldigim bilgileri okumak icin actim

	int mEdge;//main containerin bilgisi
	int sEdge;//small container bilgisi

	infile>>mEdge;//dosyadan okuma
	infile>>sEdge;

	int mainHalfEdge = mEdge/2;
	int smallHalfEdge = sEdge/2;
//ekran buyuklugumu 1000 e 1000 olarak ayarladim
	svgfile<<"<svg version = \"1.1\" baseProfile = \"full\" width = \"1000\" height = \"1000\" "
			<<" xmlns=\"http://www.w3.org/2000/svg\">\n";

//buyuk ucgen koordinat bilgileri svg dosyasi icin
	svgfile<<"<polygon fill=\"red\" points = \""<<mainHalfEdge<<","<<0<<" "<<0<<","<<mainHalfEdge*sqrt(3)<<
				" "<<mEdge<<","<<mainHalfEdge*sqrt(3)<<
				"\" stroke = \"black\" stroke-width = \"1.5\" />\n";

	int newDistance =  mEdge; //newdistance degiskenim benim alt cigimi tutuyor x koordinatinda ne kadar gidecegimi

	int x = 0;
	int y = 0;
	int count = 1;//dongu icin tuttun kac defa dondugunu buluyorum
	while(newDistance >= sEdge)//newdistance kucuk ucgenin bir kenari oluncaya kadar (ne kadar yukari cikacagi)
	{
		int numOfRec = newDistance/sEdge;//kac tane yerlestirebiliyorum x koordinati boyunca

		for(int i = 0; i<numOfRec; i++)
		{
			//duz kucuk ucgenlerimin koordinatlari
			svgfile<<"<polygon fill=\"green\" points = \""<<x + smallHalfEdge<<","<<y +mainHalfEdge*sqrt(3)- smallHalfEdge*sqrt(3) <<
			" "<<x<<","<<y+mainHalfEdge*sqrt(3)<<" "<<x+sEdge<<","<<y+mainHalfEdge*sqrt(3)<< 
			"\" stroke = \"black\" stroke-width = \"1\" />\n";

			//ters olarak cizdigim kucuk ucgenlerin koordinatlari
			svgfile<<"<polygon fill=\"green\" points = \""<<x+ smallHalfEdge<<","<<y +mainHalfEdge*sqrt(3)- smallHalfEdge*sqrt(3)<<
			" "<<x+sEdge<<","<<y+mainHalfEdge*sqrt(3)<<" "<<x+sEdge+smallHalfEdge<<","<<y +mainHalfEdge*sqrt(3)- smallHalfEdge*sqrt(3)<<
			"\" stroke = \"black\" stroke-width = \"1\" />\n";
			
			x += sEdge;//bu arttirma x koordinatinda ilerlememi sagliyor
		}

		x = 0;//x i tekrradan sifirliyorum
		x += count*smallHalfEdge;//her dongu kadar x koordinatinda ilerlemis olmam gerekiyor
		count++;//dongu icin arttirma

		newDistance -= sEdge;//yukari dogru ilerledikce kucuk ucgenin kenari kadar azaliyor
		y -= smallHalfEdge*sqrt(3); //y koordinati her seferinde kucuk ucgenin kenar uzunlugunun yarisinin kok uc kati kadar azaliyor
	}


	svgfile<<"</svg>";//svg dosyasinin kapanisi

	svgfile.close();//actigim iki dosyayi da kapatiyorum
	infile.close();
}


void Tri_RecFunc()
{
	ofstream svgfile;
	svgfile.open("output.svg");

	ifstream infile;
	infile.open("outfile.txt");

	int mEdge;
	int sHeight;
	int sWidth;

	infile>>mEdge;
	infile>>sWidth;
	infile>>sHeight;

	int halfEdge = mEdge/2;

	svgfile<<"<svg version = \"1.1\" baseProfile = \"full\" width = \"1000\" height = \"1000\" "
			<<" xmlns=\"http://www.w3.org/2000/svg\">\n";


	svgfile<<"<polygon fill=\"red\" points = \""<<halfEdge<<","<<0<<" "<<0<<","<<halfEdge*sqrt(3)<<
				" "<<mEdge<<","<<halfEdge*sqrt(3)<<
				"\" stroke = \"black\" stroke-width = \"1.5\" />\n";

	
	double newDistance = mEdge - (2.0/3 * sqrt(3)*sHeight);//yukari cikildikta azalan alt kenar uzunlugu icin newdistance beliledim
	int x = sHeight*sqrt(3) / 3.0;//ucgen ve dikdortgenime gore matematiksel x ve y belirledim
	int y = halfEdge*sqrt(3) - sHeight;
	int count = 1;//dongu icin

	while(newDistance >= sWidth)//en az dikdortgenin genisligi kadar olmali
	{
		int numOfRec = newDistance/sWidth;//en alta kac tane dikdortgen gelecegi

		for(int i = 0; i<numOfRec; i++)
		{
			svgfile<<"<rect x = \"" <<x<< "\" y = \"" <<y<< "\" width=\"" <<sWidth<< 
					 "\" height=\"" <<sHeight<< "\" fill=\"green\" stroke = \"black\" stroke-width = \"1\" />\n";

			x += sWidth;
		}

		x = sHeight*sqrt(3) / 3.0 + (sWidth/3*count);//matematiksel olarak degisen degerler
		newDistance -= (2.0/3*sqrt(3)*sHeight);
		y -= sHeight;
		count++;
	}

	svgfile<<"</svg>";

	svgfile.close();
	infile.close();
	
}



void Tri_CircFunc()
{
	//bu fonsiyonumda da ayni mantikla ilerledim asagidan yukari dogru ilerledim
	// mesafeye gore dongu kurdum matematiksel olarak koordinat belirledim
	ofstream svgfile;
	svgfile.open("output.svg");

	ifstream infile;
	infile.open("outfile.txt");

	int mEdge;
	int sRadius;

	infile>>mEdge;
	infile>>sRadius;

	int halfEdge = mEdge/2;
	int sDiameter = 2*sRadius;

	svgfile<<"<svg version = \"1.1\" baseProfile = \"full\" width = \"1000\" height = \"1000\" "
			<<" xmlns=\"http://www.w3.org/2000/svg\">\n";


	svgfile<<"<polygon fill=\"red\" points = \""<<halfEdge<<","<<0<<" "<<0<<","<<halfEdge*sqrt(3)<<
				" "<<mEdge<<","<<halfEdge*sqrt(3)<<
				"\" stroke = \"black\" stroke-width = \"1.5\" />\n";

	int distance = mEdge / sDiameter;
	double x = sRadius*sqrt(3);
	double y = halfEdge*sqrt(3) - sRadius;	

	int count = 1;
	while(mEdge > sDiameter)
	{
		for(int i = 0; i<distance; i++)
		{
			svgfile<<"<circle cx = \"" << x << "\" cy = \"" << y << "\" r=\"" << sRadius << 
				"\" fill=\"green\" stroke = \"black\" stroke-width = \"1.5\" />\n";

			x += sDiameter;
		}

		mEdge = mEdge*(0.75);
		distance = mEdge / sDiameter;
		x = sRadius*sqrt(3) + sDiameter*count;
		count++;
		y -= sDiameter;
	}

	svgfile<<"</svg>";

	svgfile.close();
	infile.close();
	
}

void Rec_TriFunc()
{
	ofstream svgfile;
	svgfile.open("output.svg");

	ifstream infile;
	infile.open("outfile.txt");

	int mHeight;
	int mWidth;
	int sEdge;

	infile>>mWidth;
	infile>>mHeight;
	infile>>sEdge;

	svgfile<<"<svg version = \"1.1\" baseProfile = \"full\" width = \"1000\" height = \"1000\" "
			<<" xmlns=\"http://www.w3.org/2000/svg\">\n";

	svgfile<<"<rect width=\"" <<mWidth<< "\" height=\"" <<mHeight<< "\" fill=\"red\" />\n";

	int x = 0;
	int y = 0;
	int a = sEdge/2;

	for(int i = a*sqrt(3); i<= mHeight; i+=(a*sqrt(3)))//yukseklik icin ilerlenmesi gereken kadar donuyor
	{
		for(int j = sEdge; j<= mWidth; j+= sEdge)//yana dogru kac tane ucgen cizilecegi
		{
			svgfile<<"<polygon fill=\"green\" points = \""<<x<<","<<y<<" "<<x+a<<","<<y+a*sqrt(3)<<" "<<x+sEdge<<","<<y<<
				"\" stroke = \"black\" stroke-width = \"1.5\" />\n";

			svgfile<<"<polygon fill=\"green\" points = \""<<x+sEdge<<","<<y<<" "<<x+a<<","<<y+a*sqrt(3)<<
				" "<<x+sEdge+a<<","<<y+a*sqrt(3)<<
				"\" stroke = \"black\" stroke-width = \"1.5\" />\n";

			x += sEdge;
		}

		x =0;
		y+=a*sqrt(3);

	}
	

	svgfile<<"</svg>";
	svgfile.close();
	infile.close();

}


void Circ_CircFunc()
{
	ofstream svgfile;
	svgfile.open("output.svg");

	ifstream infile;
	infile.open("outfile.txt");

	int mRadius;
	int sRadius;
	infile>>mRadius;
	infile>>sRadius;	

	svgfile<<"<svg version = \"1.1\" baseProfile = \"full\" width = \"1000\" height = \"1000\" "
			<<" xmlns=\"http://www.w3.org/2000/svg\">\n";

	svgfile<<"<circle cx = \"" << mRadius << "\" cy = \"" << mRadius << "\" r=\"" << mRadius << 
				"\" fill=\"red\" stroke = \"black\" stroke-width = \"1.5\" />\n";

	int sDiameter = 2*sRadius;
	int Rr = mRadius/sDiameter;//kac tane cember sigar

	int x = mRadius - (Rr*sDiameter)+sRadius;//matematiksel koordinatlar
	int y = mRadius - (Rr*sDiameter)+sRadius;


	for(int i = sDiameter; i<= (2*Rr*sDiameter); i+=sDiameter)//ilerleme mikarlari
	{
		for(int j = sDiameter; j<=2*Rr*sDiameter; j+=sDiameter)
		{
			svgfile<<"<circle cx = \"" <<x<< "\" cy = \"" <<y<< "\" r =\"" <<sRadius<< 
					 "\" fill=\"green\" stroke = \"black\" stroke-width = \"1\" />\n";

			x += sDiameter;
		}

		x = mRadius - (Rr*sDiameter)+sRadius;
		y+=sDiameter;
	}

	svgfile<<"</svg>";
	svgfile.close();
	infile.close();
}

void Circ_RecFunc()
{
	ofstream svgfile;
	svgfile.open("output.svg");

	ifstream infile;
	infile.open("outfile.txt");

	int mRadius;
	int sHeight;
	int sWidth;

	infile>>mRadius;
	infile>>sWidth;
	infile>>sHeight;

	svgfile<<"<svg version = \"1.1\" baseProfile = \"full\" width = \"1000\" height = \"1000\" "
			<<" xmlns=\"http://www.w3.org/2000/svg\">\n";

	svgfile<<"<circle cx = \"" << mRadius << "\" cy = \"" << mRadius << "\" r=\"" << mRadius << 
				"\" fill=\"red\" stroke = \"black\" stroke-width = \"1.5\" />\n";

	double diago = sqrt(pow(sWidth,2) + pow(sHeight,2)); //dikdorgenin kosegen uzunlugu
	int Rr = mRadius/diago;//kosegene gore main cemberin yaricapina ne kadar dikdorgen sigacagi

	int x = mRadius - (Rr*sWidth);
	int y = mRadius - (Rr*sHeight);


	for(int i = sHeight; i<= 2*(2*Rr*sHeight); i+=sHeight)
	{
		for(int j = sWidth; j<=2*Rr*sWidth; j+=sWidth)
		{
			svgfile<<"<rect x = \"" <<x<< "\" y = \"" <<y<< "\" width=\"" <<sWidth<< 
					 "\" height=\"" <<sHeight<< "\" fill=\"green\" stroke = \"black\" stroke-width = \"1\" />\n";

			x += sWidth;
		}

		x = mRadius - (Rr*sWidth);
		y+=sHeight;
	}

	svgfile<<"</svg>";
	svgfile.close();
	infile.close();
	
}

void Rec_CircFunc()
{
	ofstream svgfile;
	svgfile.open("output.svg");

	ifstream infile;
	infile.open("outfile.txt");

	int mHeight;
	int mWidth;
	int sRadius;

	infile>>mWidth;
	infile>>mHeight;
	infile>>sRadius;

	svgfile<<"<svg version = \"1.1\" baseProfile = \"full\" width = \"1000\" height = \"1000\" "
			<<" xmlns=\"http://www.w3.org/2000/svg\">\n";

	svgfile<<"<rect width=\"" <<mWidth<< "\" height=\"" <<mHeight<< "\" fill=\"red\" />\n";


	int x = sRadius;
	int y = sRadius;
	int bRadius = 2*sRadius;

	for(int i = bRadius; i<=mHeight; i+=bRadius)//mantigi asagi ve yana dogru ilerleme
	{
		for(int j = bRadius; j<= mWidth; j+= bRadius)
		{
			svgfile<<"<circle cx = \"" << x << "\" cy = \"" << y << "\" r=\"" << sRadius << 
				"\" fill=\"green\" stroke = \"black\" stroke-width = \"1.5\" />\n";

			x += bRadius;
		}

		x = sRadius;
		y+= bRadius;
	}

	svgfile<<"</svg>";
	svgfile.close();
	infile.close();
}

void Rec_RecFunc()
{
	ofstream svgfile;
	svgfile.open("output.svg");

	ifstream infile;
	infile.open("outfile.txt");
	int mHeight;
	int mWidth;
	int sHeight;
	int sWidth;

	infile>>mWidth;
	infile>>mHeight;
	infile>>sWidth;
	infile>>sHeight;

	svgfile<<"<svg version = \"1.1\" baseProfile = \"full\" width = \"1000\" height = \"1000\" "
			<<" xmlns=\"http://www.w3.org/2000/svg\">\n";

	svgfile<<"<rect width=\"" <<mWidth<< "\" height=\"" <<mHeight<< "\" fill=\"red\" />\n";

	int x =0;
	int y =0;
	int countX = 0;
	int countY = 0;

	for(int i = sHeight; i<=mHeight; i+=sHeight)
	{
		for(int j = sWidth; j<= mWidth; j+= sWidth)
		{
			svgfile<<"<rect x = \"" <<x<< "\" y = \"" <<y<< "\" width=\"" <<sWidth<< 
					 "\" height=\"" <<sHeight<< "\" fill=\"green\" stroke = \"black\" stroke-width = \"1\" />\n";

			x += sWidth;
			countX++;
		}

		x = 0;
		y+= sHeight;
		countY++;
	}

	svgfile<<"</svg>";
	svgfile.close();
	infile.close();	

}


void rectangleFunc(int &mWidth, int &mHeight)//dikdortgenin uzunluklarini aliyorum
{
	cout<<"Please enter the width"<<endl;
	cin>>mWidth;
	if(mWidth < 0)
		return;

	cout<<"Please enter the height"<<endl;
	cin>>mHeight;
	if(mHeight < 0)
		return;
}

void circleFunc(int &mRadius)//cemberin yaricap uzunlugu
{
	cout<<"Please enter the radius"<<endl;
	cin>>mRadius;
	if(mRadius < 0)
		return;
}

void triangleFunc(int &mEdge)//ucgenin bir kenar uzunlugu
{
	cout<<"Please enter an edge length of a equilateral triangle"<<endl;
	cin>>mEdge;
	if(mEdge < 0)
		return;
}


