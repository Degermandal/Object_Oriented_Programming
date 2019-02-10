#include "LinkedList.h"

namespace _collection {

template<typename E, typename C>
//Inserts the specified element into this queue
bool LinkedList<E,C>::add(E e) throw (Exception)
{
	typename C::Iterator i;
	i = container.insert(i,&e);
	//container.push_back(&e);

	if(container.begin() == nullptr)
	{
		throw Exception("Eklenemedi\n");
		return false;
	}
	else 
		return true;
}


template<typename E, typename C>
//Retrieves, but does not remove, the head of this queue.
//element(): Returns but does not removes the head of this queue. It throws an exception if this queue is empty.
//Syntax: public Object element()
Iterator<E> LinkedList<E,C>::element() throw (Exception) 
{

}


template<typename E, typename C>
//Inserts the specified element into this queue
//offer(Object obj): Inserts the specified element into this queue. Returns true if 
//the element was added to this queue otherwise returns false.
//Syntax: public boolean offer(Object obj)
bool LinkedList<E,C>::offer(E e)
{
	bool res;
	typename C::Iterator i;

	for(i = container.begin(); i= container.end(); i++)
	{
		if(*i == e)
		{
			i = container.insert(i,&e);
			res = true;
		}
		else
		{
			res = false;
		}
	}
	return res;
}


template<typename E, typename C>
//Retrieves and removes the head of this queue, or throws if this queue is empty.
//poll(): Returns and removes the head of this queue. Returns null if this queue is empty.
//Syntax: public Object poll()
Iterator<E> LinkedList<E,C>::poll() throw (Exception) 
{

}


template<typename E, typename C>
//remove(E e) Removes a single instance of the specified element from this collection, if it is present
//It remove the specified object from the calling collection. 
//It returns true if collection changed after this call otherwise returns false.
bool LinkedList<E,C>::remove(const E e) 
{
	bool res;
	typename C::Iterator i;
	for(i = container.begin(); i= container.end(); i++)
	{
		if(*i == e)
		{
			i->remove();
			res =  true;
		}
		else
			res = false;
	}
	return res;
}



}//namespace