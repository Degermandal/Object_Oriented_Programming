//Queue represents a collection for holding elements prior to processing.

#ifndef QUEUE_H_
#define QUEUE_H_
#include "Collection.h"
#include "Exception.h"
using namespace std;

namespace _collection {

template <typename E, typename C = vector<E> > 
class Queue : public Collection<E,C> {
public:
	Queue(){	}
		
	//Inserts the specified element into this queue
	virtual bool add(E e) override = 0; 

	//Retrieves, but does not remove, the head of this queue.
	//element(): Returns but does not removes the head of this queue. It throws an exception if this queue is empty.
	//Syntax: public Object element()
	virtual Iterator<E> element() throw (Exception) = 0 ;

	//Inserts the specified element into this queue
	//offer(Object obj): Inserts the specified element into this queue. Returns true if 
	//the element was added to this queue otherwise returns false.
	//Syntax: public boolean offer(Object obj)
	virtual bool offer(E e) = 0;

	//Retrieves and removes the head of this queue, or throws if this queue is empty.
	//poll(): Returns and removes the head of this queue. Returns null if this queue is empty.
	//Syntax: public Object poll()
	virtual Iterator<E> poll() throw (Exception) = 0;

};

} /* namespace _collection */
#endif /* QUEUE_H_ */

