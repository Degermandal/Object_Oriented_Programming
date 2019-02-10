#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include "List.h"
#include "Queue.h"
#include "Iterator.h"
#include "Exception.h"

#include <iostream>
#include <vector>

using namespace std;

namespace _collection {

template <typename E, typename C = vector<E> >

class LinkedList : public List<E,C> , Queue<E,C> {
public:
	LinkedList() { }
	explicit LinkedList(const C& cont = C()) : container(cont){     }

	//Inserts the specified element into this queue
	bool add(E e) throw (Exception) override; 

	//Retrieves, but does not remove, the head of this queue.
	//element(): Returns but does not removes the head of this queue. It throws an exception if this queue is empty.
	//Syntax: public Object element()
	Iterator<E> element() throw (Exception) override;

	//Inserts the specified element into this queue
	//offer(Object obj): Inserts the specified element into this queue. Returns true if 
	//the element was added to this queue otherwise returns false.
	//Syntax: public boolean offer(Object obj)
	bool offer(E e) override;

	//Retrieves and removes the head of this queue, or throws if this queue is empty.
	//poll(): Returns and removes the head of this queue. Returns null if this queue is empty.
	//Syntax: public Object poll()
	Iterator<E> poll() throw (Exception) override;

	//remove(E e) Removes a single instance of the specified element from this collection, if it is present
	//It remove the specified object from the calling collection. 
	//It returns true if collection changed after this call otherwise returns false.
	bool remove(const E e) override;


private:
	C container;

};

} /* namespace _collection */
#endif /* LINKEDLIST_H */


