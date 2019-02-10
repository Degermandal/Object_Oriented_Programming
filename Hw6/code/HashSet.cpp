#include "HashSet.h"

namespace _collection {

template <typename E, typename C> 
//add(E e)      Ensures that this collection contains the specified element
bool HashSet<E,C>::add(E e) throw (Exception)
{
	bool res;
	typename C::Iterator i;

	for(i = container.begin(); i= container.end(); i++)
	{
		if(*i == e)
		{
			res = false;
			throw Exception("Eklenemedi\n");
		}
		else
		{
			container.push_back(&e);
			res = true;
		}
	}
	return res;
}


template<typename E, typename C>
//addAll(Collection c)  Adds all of the elements in the specified collection to this  collection
bool HashSet<E,C>::addAll(const Collection<E,C> &c)const 
{
	bool res;
	typename C::Iterator i;
	for(i = container.begin(); i= container.end(); i++)
	{
		const HashSet* ptr = dynamic_cast< const HashSet*>(&c);
		if(*i == ptr)
		{
			throw Exception("Eklenemedi\n");
			res = false;
		}
		else
		{
			container.push_back(ptr);
			res = true;
		}
	}
	return res;
}

template<typename E, typename C>
//clear()   Removes all of the elements from this collection
void HashSet<E,C>::clear()
{
	typename C::Iterator i;
	for(i = container.begin(); i= container.end(); i++)
	{
		container.remove();
	}
}

template<typename E, typename C>
//contains(E e)   Returns true if this collection contains the specified element.
bool HashSet<E,C>::contains(E e)//contains(Object obj)
{
	typename C::Iterator i;
	for(i = container.begin(); i= container.end(); i++)
	{
		if(*i == e)
			return true;
		else
			return false;
	}
}

template<typename E, typename C>
//containsAll(Collection c)  Returns true if this collection contains all of the elements 
//in the specified collection.
bool HashSet<E,C>::containsAll(const Collection<E,C> &c) throw (Exception) 
{
	bool res;
	typename C::Iterator i;
	for(i = container.begin(); i= container.end(); i++)
	{
		const HashSet* ptr = dynamic_cast< const HashSet*>(&c);
		if(*i == c)
			res = true;
		else
		{
			throw Exception("Hepsini icermiyor\n");
			res = false;
		}
	}
	return res;
}

template<typename E, typename C>
//isEmpty()  Returns true if this collection contains no elements.
bool HashSet<E,C>::isEmpty()
{
	typename C::Iterator i;
	for(i = container.begin(); i= container.end(); i++)
	{
		if(i->hasNext() == nullptr)
			return true;
		else
			return false;
	}
}

template<typename E, typename C>
//remove(E e) Removes a single instance of the specified element from this collection, if it is present
//It remove the specified object from the calling collection. 
//It returns true if collection changed after this call otherwise returns false.
bool HashSet<E,C>::remove(const E e)
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

template<typename E, typename C>
//removeAll(Collection c)  Removes all of this collection's elements that are also contained 
//in the specified collection
bool HashSet<E,C>::removeAll(Collection<E,C> &c) const throw (Exception)
{
	bool res;
	typename C::Iterator i;
	for(i = container.begin(); i= container.end(); i++)
	{
		const HashSet* ptr = dynamic_cast< const HashSet*>(&c);
		if(*i == ptr)
		{
			i->remove();
			res =  true;
		}
		else
		{
			throw Exception("Butun elemanlar silinemedi\n");
			res = false;
		}
	}
	return res;
}

template<typename E, typename C>
//retainAll(Collection c) Retains-belirtilen koleksiyonda bulunan öğeleri korur-only the elements 
//in this collection that are contained in the specified collection
//It remove all elements except those of the specified collection from the calling collection. It 
//returns true if collection changed after this call otherwise returns false.
bool HashSet<E,C>::retainAll(Collection<E,C> &c) 
{
	bool res;
	typename C::Iterator i;
	for(i = container.begin(); i= container.end(); i++)
	{
		const HashSet* ptr = dynamic_cast< const HashSet*>(&c);
		if(*i == ptr)//o collectionda ise sadece sonuca false ata
		{
			res = false;
		}
		else
		{
			i->remove(); //collectionda olmayanlari sil true ata
			res = true;
		}
	}
	return res;
}

template<typename E, typename C>
//size()  Returns the number of elements in this collection.
int HashSet<E,C>::size() const 
{
	int count = 0;
	typename C::Iterator i;
	for(i = container.begin(); i= container.end(); i++)
	{
		count++;
	}
	return count;
}








} /* namespace _collection */