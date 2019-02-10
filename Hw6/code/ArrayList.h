#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_
#include "List.h"
#include "Iterator.h"
#include "Exception.h"
#include <vector>

#include <iostream>
using namespace std;

namespace _collection {

template <typename E, typename C = vector<E> >

class ArrayList : public List<E,C> {
public:
	ArrayList() { }

	//iterator()    Returns an iterator over the collection
	Iterator<E> iterator() const  { return Iterator<E>(container.get()); }  //.....

	//add(E e)      Ensures that this collection contains the specified element
	bool add(const E e)const throw (Exception) override; 

	//addAll(Collection c)  Adds all of the elements in the specified collection to this  collection
	bool addAll(const Collection<E,C> &c) const override;

	//clear()   Removes all of the elements from this collection
	void clear()override;

	//contains(E e)   Returns true if this collection contains the specified element.
	bool contains(E e) override; //contains(Object obj)


	//containsAll(Collection c)  Returns true if this collection contains all of the elements 
	//in the specified collection.
	bool containsAll(const Collection<E,C> &c) throw (Exception) override;

	//isEmpty()  Returns true if this collection contains no elements.
	bool isEmpty()  ; //.....

	//remove(E e) Removes a single instance of the specified element from this collection, if it is present
	//It remove the specified object from the calling collection. 
	//It returns true if collection changed after this call otherwise returns false.
	bool remove(const E e) override; 

	//removeAll(Collection c)  Removes all of this collection's elements that are also contained in the 
	//specified collection
	bool removeAll(Collection<E,C> &c) const throw (Exception) override;

	//retainAll(Collection c) Retains-belirtilen koleksiyonda bulunan öğeleri korur-only the elements 
	//in this collection that are contained in the specified collection
	//It remove all elements except those of the specified collection from the calling collection. It 
	//returns true if collection changed after this call otherwise returns false.
	bool retainAll(Collection<E,C> &c) override;

	//size()  Returns the number of elements in this collection.
	int size() const override;
	

private:
	C container;

};

} /* namespace _collection */
#endif /* ARRAYLIST_H */