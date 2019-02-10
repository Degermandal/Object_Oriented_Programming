package myCollection;

/**
 *
 * @author Deger
 * @param <E>
 */

public interface Set<E>{
	
	/**
     *Returns an iterator over the collection
     * @return myIterator
     */
	myIterator<E> iterator();

	/**
     *add(E e)      Ensures that this collection contains the specified element
     * @param e
     * @return true-false
     */
	boolean add(E e) throws Exception;

	 /**
     *addAll(Collection c)  Adds all of the elements in the specified collection to this  collection
     * @param c
     * @return true-false
     */
	boolean addAll(Collection<E> c)throws Exception;

	/**
     *clear()   Removes all of the elements from this collection
     */
	void clear();

	 /**
     *contains(E e)   Returns true if this collection contains the specified element.
     * @param e
     * @return true-false
     */
	boolean contains(E e); //contains(Object obj)

	/**
     *containsAll(Collection c)  Returns true if this collection contains all of the elements in the specified collection.
     * @param c
     * @return true-false
     */
	boolean containsAll(Collection<E> c) throws Exception;
	
	/**
     *isEmpty()  Returns true if this collection contains no elements.
     * @return true-false
     */
	boolean isEmpty();

	/**
     *remove(E e) Removes a single instance of the specified element from this collection, 
     * if it is presentIt remove the specified object from the calling collection. 
     * It returns true if collection changed after this call otherwise returns false.
     * @param e
     * @return true-false
     */
	boolean remove(E e) throws Exception;

	/**
     *removeAll(Collection c)  Removes all of this collection's elements that are also contained in the specified collection
     * @param c
     * @return true-false
     */
	boolean removeAll(Collection<E> c) throws Exception;

	/**
     *retainAll(Collection c) Retains-belirtilen koleksiyonda bulunan öðeleri korur-only the elements 
     * in this collection that are contained in the specified collection
     * @param c
     * @return true-false
     */
	boolean retainAll(Collection<E> c) throws Exception;

	/**
     *size()  Returns the number of elements in this collection.
     * @return int
     */
	int size();
    
}

