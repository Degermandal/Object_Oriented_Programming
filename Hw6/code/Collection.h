#ifndef COLLECTION_H_
#define COLLECTION_H_
#include "Iterator.h"
#include "Exception.h"
#include <iostream>
#include <vector>


using namespace std;
namespace _collection {

template <typename E, typename C = vector<E> > //template <typename E, typename C  >
class Collection {
public:
	//typedef typename C::value_type value_type;
	//typedef typename C::size_type size_type;
	//typedef C container_type;

	//iterator()    Returns an iterator over the collection
	virtual Iterator<E> iterator() = 0;

	//add(E e)      Ensures that this collection contains the specified element
	virtual bool add(const E e)const throw (Exception) = 0;

	//addAll(Collection c)  Adds all of the elements in the specified collection to this  collection
	virtual bool addAll(const Collection &c) const = 0;

	//clear()   Removes all of the elements from this collection
	virtual void clear() = 0;

	//contains(E e)   Returns true if this collection contains the specified element.
	virtual bool contains(E e) = 0; //contains(Object obj)

	//containsAll(Collection c)  Returns true if this collection contains all of the elements in the specified collection.
	virtual bool containsAll(const Collection &c) throw (Exception) = 0;

	//isEmpty()  Returns true if this collection contains no elements.
	virtual bool isEmpty() = 0;

	//remove(E e) Removes a single instance of the specified element from this collection, if it is present
	//It remove the specified object from the calling collection. 
	//It returns true if collection changed after this call otherwise returns false.
	virtual bool remove(const E e) = 0;

	//removeAll(Collection c)  Removes all of this collection's elements that are also contained in the specified collection
	virtual bool removeAll(Collection &c)const = 0;

	//retainAll(Collection c) Retains-belirtilen koleksiyonda bulunan öğeleri korur-only the elements 
	//in this collection that are contained in the specified collection
	virtual bool retainAll(Collection &c) = 0;

	//size()  Returns the number of elements in this collection.
	virtual int size() const= 0;

};



} /* namespace _collection */
#endif /* COLLECTION_H_ */

