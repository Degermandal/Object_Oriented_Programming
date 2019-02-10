
package myCollection;

/*READ -ME
https://codesjava.com/list-interface-in-java  bu sitedeki aciklama ve fonsiyonlara gore yaptim list oldugu icin index degerleri ekledim
ve kodumu ona gore degistirdim
*/

/**
 *
 * @author Deger
 * @param <E>
 */

public interface List <E>{

    /**
     *Insert obj at the specified index position into 
     * this list. All pre-existing elements at or beyond 
     * the specified index are shifted up.
     * @param index (int) 
     * @param e (E)
     * @return true yada false
     * @throws Exception
     */
    boolean add(int index, E e) throws Exception;

    /**
     *Insert all elements of the specified collection at the specified index 
     * position into this collection. All pre-existing elements 
     *at or beyond the specified index are shifted up. Returns true is this list 
     * changes after the operation otherwise returns false.
     * @param index (int)
     * @param c (Collection)
     * @return true yada false
     * @throws Exception
     */
    boolean addAll(int index, Collection<E> c) throws Exception;

    /**
     *remove(E e) Removes a single instance of the specified element from 
     * this collection, if it is presentIt remove the specified object from the 
     * calling collection.  It returns true if collection 
     * changed after this call otherwise returns false.
     * @param e (E)
     * @return E
     * @throws Exception
     */
    E remove(E e) throws Exception;
    
    /**
     *get(int index): Returns the object stored at specified index position into this list.
     * @param index (int)
     * @return E
     * @throws Exception
     */
    E get(int index) throws Exception;

    /**
     *indexOf(Object obj): Returns index of first occurrence of obj in this list.
     * It returns -1 if obj is not exist in this list.
     * @param e (E)
     * @return index (int)
     */
    int indexOf(E e);
    
    /**
     * set(int index, Object obj): Assigns obj to the specified index location within the this list.
     * @param index
     * @param e
     * @return E
     * @throws Exception
     */
    E set(int index, E e) throws Exception;
    
}
