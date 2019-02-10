#include "PolygonDyn.h"

namespace _shape{

PolygonDyn::PolygonDyn(Shape *s)
{
	if(const Circle* ptr = dynamic_cast< const Circle*>(s))
	{
		dyn2D = new Point2D[cap];
		Point2D a2d(ptr->getShapeX(), ptr->getShapeY());	
		PolygonDyn adyn(a2d);	
		use++;
	}
	else if(const Rectangle* ptr = dynamic_cast< const Rectangle*>(s))
	{
		dyn2D = new Point2D[cap];
		Point2D b2d(ptr->getShapeX(), ptr->getShapeY());	
		PolygonDyn bdyn(b2d);
		use++;	
	}
	else if(const Triangle* ptr = dynamic_cast< const Triangle*>(s))
	{
		dyn2D = new Point2D[cap];
		Point2D c2d(ptr->getShapeX(), ptr->getShapeY());	
		Point2D d2d(ptr->getX2(), ptr->getY2());	
		Point2D f2d(ptr->getX3(), ptr->getY3());


		PolygonDyn adyn(c2d,d2d,f2d);	
		use++;
	}
	else
		throw Exception("PolygonDyn Fail -PolygonDyn(Shape *s)-!!\n");
}



void PolygonDyn::setUsed(int us)
{ 
	if(us >= 0) 
		use = us;
	else 
	{
		throw Exception("used degiskeni 0 dan kucuk olamaz\n");
	}
}

void PolygonDyn::setCapacity(int cp)
{
	if(cp >= 0) cap = cp;
	else 
		throw Exception("capacity degeri 0 dan kucuk olamaz\n");
}


PolygonDyn::PolygonDyn(Polygon::Point2D &p2d) :cap(50)
{
	dyn2D = new Point2D[cap];
	dyn2D[use] = p2d;
	use++;
}

PolygonDyn::PolygonDyn(Polygon::Point2D &p2d, Polygon::Point2D &pp2d, Polygon::Point2D &ppp2d):cap(50)
{
	dyn2D = new Point2D[cap];
	dyn2D[use] = p2d;
	use++;
	dyn2D[use] = pp2d;
	use++;
	dyn2D[use] = ppp2d;
	use++;
}

PolygonDyn::PolygonDyn(): cap(100), use(0)
{
	dyn2D = new Point2D[cap];
	use++;
}

PolygonDyn::PolygonDyn(int cap): cap(cap), use(0)
{
	dyn2D = new Point2D[cap];
	use++;
}
//dinamik bir arrayim oldugu icin copy constructor assignment ve destructor fonksiyonlarini yazdim
PolygonDyn::PolygonDyn(const PolygonDyn& copy): cap(copy.getCapacity( )), use(copy.getUsed( ))
{
    dyn2D = new Point2D[cap];
    for (int i =0; i < use; i++)
        dyn2D[i] = copy.dyn2D[i];
}

PolygonDyn& PolygonDyn::operator =(const PolygonDyn& rs)
{
    if (cap != rs.cap)
    {
        delete [] dyn2D;
        dyn2D = new Point2D[rs.cap];
    }

    cap = rs.cap;
    use = rs.use;

    for (int i = 0; i < use; i++)
        dyn2D[i] = rs.dyn2D[i];

    return *this;
}

PolygonDyn::~PolygonDyn( )
{
    delete [] dyn2D;
}



bool PolygonDyn::operator==(const Shape &pd) const
{
	try{
		if(const PolygonDyn* ptr = dynamic_cast<const PolygonDyn*> (&pd))
			return(this->dyn2D == ptr->dyn2D);
		
		return false;
	}
	catch(exception &e )
	{
		cout<<e.what()<<endl;
	}

}
bool PolygonDyn::operator!=(const Shape &pd) const
{
	try{
		if(const PolygonDyn* ptr = dynamic_cast<const PolygonDyn*> (&pd))
			return(this->dyn2D != ptr->dyn2D);
		
		return false;
	}
	catch(exception&e )
	{
		cout<<e.what()<<endl;
	}

}

Polygon::Point2D& PolygonDyn::getAr() const//privetedaki pointer olarak tuttugum arrayi return ediyor
{
	Point2D *ar;
	ar = new Point2D[getCapacity()];
	for(int i = 0; i<getUsed(); i++)
	{
		ar[i] = dyn2D[i];

	}
	return *ar;
}


//Operator<< for producing the SVG code.
ostream& operator<< (ostream &out, const PolygonDyn &pd)
{
	out<<"<svg version = \"1.1\" baseProfile = \"full\" width = \"1000\" height = \"1000\" "
	<<" xmlns=\"http://www.w3.org/2000/svg\">\n";
	out<< "<polygon points = \"";

	Polygon::Point2D *arr = &(pd.getAr());
	for(int i = 0; i<pd.getUsed(); ++i)
	{
		out<< arr[i]<< ",";
		out<< arr[i+1]<< " ";
		i++;
	}

	out<<" fill=\"red\" stroke = \"black\" stroke-width = \"1\" />\n";

	return out;
}

}