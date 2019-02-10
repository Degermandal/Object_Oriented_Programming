
package myCollection;

/**
 *
 * @author Deger
 * @param <E>
 */
public interface Queue<E> {
    
    /**
     *add(Object obj): Inserts the specified element into this queue. Returns true if queue changed after the operation otherwise returns false.
     * @param e
     * @return true-false
     */
    boolean add(E e);

    /**
     *offer(Object obj): Inserts the specified element into this queue. Returns true if the element was added to this queue otherwise returns false.
     * @param e
     * @return true-false
     * @throws Exception
     */
    boolean offer(E e) throws Exception;

    /**
     *remove(): Returns and removes the head of this queue. It throws an exception if this queue is empty.
     * @return Object
     * @throws Exception
     */
    E remove() throws Exception;

     /**
     *poll(): Returns and removes the head of this queue. Returns null if this queue is empty.
     * @return Object
     * @throws Exception
     */
    E poll() throws Exception;

    /**
     *element(): Returns but does not removes the head of this queue. It throws an exception if this queue is empty.
     * @return Object
     * @throws Exception
     */
    E element() throws Exception;
    
}
