#include <iostream>

using std::cout;
using std::cin;
#include "Polygon.h"

namespace _shape
{

bool Polygon::operator==(const Shape &p) const
{
try{
	if(const Polygon* ptr = dynamic_cast<const Polygon*> (&p))
		return(this->Area() == ptr->Area());
	
	return false;
}
catch(exception &e )
{
	cout<<e.what()<<endl;
}

}
bool Polygon::operator!=(const Shape &p) const
{
try{
	if(const Polygon* ptr = dynamic_cast<const Polygon*> (&p))
		return(this->Area() != ptr->Area());
	
	return false;
}
catch(exception &e )
{
	cout<<e.what()<<endl;
}

}


//Operator<< for producing the SVG code.
ostream& operator<< (ostream &out, const Polygon &p)
{
	cout<<"Polygon ostream\n";
}


}







