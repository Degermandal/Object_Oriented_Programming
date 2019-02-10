//An ordered collection (also known as a sequence).
//The user of this interface has precise control over where in the list each element is inserted.

#ifndef LIST_H_
#define LIST_H_
#include "Collection.h"
#include "Exception.h"

namespace _collection {

template <typename E, typename C = vector<E> > 

class List : public Collection<E,C> {
public:
	List() 	{	}

	//iterator()    Returns an iterator over the collection
	virtual Iterator<E> iterator() override = 0;

	//add(E e)      Ensures that this collection contains the specified element
	virtual bool add(const E e)const throw (Exception) override = 0;

	//addAll(Collection c)  Adds all of the elements in the specified collection to this  collection
	virtual bool addAll(const Collection<E,C> &c)const override = 0;

	//clear()   Removes all of the elements from this collection
	virtual void clear() override = 0;

	//contains(E e)   Returns true if this collection contains the specified element.
	virtual bool contains(E e) override = 0; //contains(Object obj)

	//containsAll(Collection c)  Returns true if this collection contains all of the elements in the specified collection.
	virtual bool containsAll(const Collection<E,C> &c) throw (Exception) override = 0;

	//isEmpty()  Returns true if this collection contains no elements.
	virtual bool isEmpty() override = 0;

	//remove(E e) Removes a single instance of the specified element from this collection, if it is present
	//It remove the specified object from the calling collection. 
	//It returns true if collection changed after this call otherwise returns false.
	virtual bool remove(const E e) override = 0;

	//removeAll(Collection c)  Removes all of this collection's elements that are also contained in the specified collection
	virtual bool removeAll(Collection<E,C> &c) const override = 0;

	//retainAll(Collection c) Retains-belirtilen koleksiyonda bulunan öğeleri korur-only the elements 
	//in this collection that are contained in the specified collection
	virtual bool retainAll(Collection<E,C> &c) override = 0;

	//size()  Returns the number of elements in this collection.
	virtual int size() const override = 0;

};


} /* namespace _collection */
#endif /* LIST_H_ */

