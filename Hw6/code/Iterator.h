#ifndef ITERATOR_H_
#define ITERATOR_H_
#include <iostream>
using namespace std;
namespace _collection {

template <typename E>

class Iterator {
public:
	//CONSTRUCTOR
	Iterator(){};	
	Iterator(E ptr) : it_pointer((&ptr)) { };

	//BIG TREE
	Iterator(E &ptr) : it_pointer(ptr) { };
	Iterator& operator=(E* val){	it_pointer=val; 	return *this;	};
	~Iterator() { }

	bool hasNext(){
		if(*(it_pointer+1) == nullptr)
		{
			return false;
		}
		return true;
	}
	
	
	E next()
	{
		if(hasNext() == true)
			return it_pointer++;
		else
			cout<<"Next function error\n";
	}

	void remove()
	{
		if(*it_pointer != nullptr)
		{
			delete *it_pointer;
		}
		else 
			cout<<"Remove function -Iterator null-\n";
	}

private:
	E *it_pointer = 0;
};

} /* namespace _collection */



#endif /* ITERATOR_H_ */

