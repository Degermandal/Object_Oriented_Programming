/**
 * 
 */
package myCollection;

import java.util.NoSuchElementException;


/**
 *
 * @author Deger
 * @param <E>
 */
public class myIterator<E>{
	
    private E[] iter;
    private int use;
    private int capacity;
    private int current = 0; //index verip kullanabilmek icin
    
   //SETTER AND GETTER FUNCTIONS
   
   /**
     *iterator get function
     * @return E[]
     */
   public E[] getIter() {
       return iter;
   }

   /**
     *iterator set function
     * @param iter
     */
   public void setIter(E[] iter) {
       this.iter = iter;
   }

   /**
     *use get function
     * @return use
     */
   public int getUse() {
       return use;
   }

   /**
     *use set function
     * @param use
     */
   public void setUse(int use) {
       this.use = use;
   }
   
   /**
    *current get function
    * @return current
    */
  public int getCurrent() {
      return current;
  }

  /**
    *current set function
    * @param current
    */
  public void setCurrent(int current) {
      this.current = current;
  }

   /**
     *capacity get function 
     * @return capacity
     */
   public int getCapacity() {
       return capacity;
   }

   /**
     *capacity set function
     * @param capacity
     */
   public void setCapacity(int capacity) {
       this.capacity = capacity;
   }
           
    //CONSTRUCTORS
	 /**
     *no parameter constructor
     */
    public myIterator(){
        use = 0;
    }
	
    /**
     *E tipinde array alan constructor
     * @param ptr
     */
    public myIterator(E[] ptr){
        use = 0;
        iter = ptr;
    }
    
	 /**
     *E tipinde array alan ve deger alan constructor
     * @param ptr
     * @param value
     */
    public myIterator(E[] ptr, int value){
        use = 0;
        capacity = value;
        iter = ptr;
    }
    
	/**
     *copy constructor
     * @param other
     */
    public myIterator(myIterator<E> other){
        use = other.use;
        capacity = other.capacity;
        iter = (E[]) other.iter;
    }
    
    public myIterator(int a){
    	current = a;
    }
    
    
     //NECESSARY FUNCTIONS
	 
	 /**
     *Returns true if the iteration has more elements.
     * @return true yada false
     */
    public boolean hasNext(){
        return (use < capacity);
    }

	/**
     *Returns the next element in the iteration and advances the iterator.
     * @return E
     */
    public E next(){
        if (! hasNext())
            throw new NoSuchElementException();
       use++;
        return iter[use - 1]; 
    }
    
	/**
     *baslangic degeri
     * @return myIterator
     */
    public myIterator<E> begin(){
            return new myIterator<E>(0);
    }

	/**
     *en son degeri 
     * @return myIterator
     */
    public myIterator<E> end(){
            return new myIterator<E>(use-1);
    }
	
}
