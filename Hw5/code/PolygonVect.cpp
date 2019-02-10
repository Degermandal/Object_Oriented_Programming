#include "PolygonVect.h"

namespace _shape{


PolygonVect::PolygonVect(Shape *s)
{
	if(const Circle* ptr = dynamic_cast< const Circle*>(s))
	{
		Point2D a2d(ptr->getShapeX(), ptr->getShapeY());	
		vec2D.push_back(&a2d);
	}
	else if(const Rectangle* ptr = dynamic_cast< const Rectangle*>(s))
	{
		Point2D b2d(ptr->getShapeX(), ptr->getShapeY());	
		vec2D.push_back(&b2d);	
	}
	else if(const Triangle* ptr = dynamic_cast< const Triangle*>(s))
	{
		Point2D c2d(ptr->getShapeX(), ptr->getShapeY());	
		Point2D d2d(ptr->getX2(), ptr->getY2());	
		Point2D f2d(ptr->getX3(), ptr->getY3());	

		vec2D.push_back(&c2d);
		vec2D.push_back(&d2d);
		vec2D.push_back(&f2d);	
	}
	else
		throw Exception("PolygonVect Fail -PolygonVect(Shape *s)-!!\n");
}

PolygonVect::PolygonVect(Polygon::Point2D& v2d)
{
	vec2D.push_back(&v2d);
}

PolygonVect::PolygonVect()
{
	vec2D.push_back(new Polygon::Point2D(0, 0));
	vec2D.push_back(new Polygon::Point2D(100, 50));
	vec2D.push_back(new Polygon::Point2D(50, 100));
}

bool PolygonVect::operator==(const Shape &pv) const
{
try{
	if(const PolygonVect* ptr = dynamic_cast<const PolygonVect*> (&pv))
		return(this->vec2D == ptr->vec2D);
	
	return false;
}
catch(exception  &e )
{
	cout<<e.what()<<endl;
}

}
bool PolygonVect::operator!=(const Shape &pv) const
{
try{
	if(const PolygonVect* ptr = dynamic_cast<const PolygonVect*> (&pv))
		return(this->vec2D != ptr->vec2D);
	
	return false;
}
catch(exception &e )
{
	cout<<e.what()<<endl;
}

}

vector<Polygon::Point2D*> PolygonVect::getVec() const//vectordeki degerlere ulasmak icin kullandim
{
	vector<Point2D *> ar;

	for(int i = 0; i<vec2D.size(); i++)
	{
		ar[i] = vec2D[i];

	}
	return ar;
}

ostream& operator<< (ostream &out, const PolygonVect &pv)
{
	out<<"<svg version = \"1.1\" baseProfile = \"full\" width = \"1000\" height = \"1000\" "
	<<" xmlns=\"http://www.w3.org/2000/svg\">\n";

	out<< "<polygon points = \"";

	vector<Polygon::Point2D *> arr = pv.getVec();

	for(int i = 0; i<arr.size(); ++i)
	{
		out<< arr[i]->getX()<< ",";
		out<< arr[i]->getY()<< " ";
		i++;
	}

	out<<" fill=\"red\" stroke = \"black\" stroke-width = \"1\" />\n";

	return out;
}


	
}