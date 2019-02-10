/**
 * 
 */
package myCollection;

/**
 *
 * @author Deger
 * @param <E> (Template Type)
 */
public class LinkedList<E> implements List<E>, Queue<E> {
    
    //LIST
    private Object[] arr ;
    private int _size; 
    private int capacity;
    //QUEUE
    private int front;//FIFOdan dolayi en ustteki
    private int back;//FIFOddan dolayi en alttaki

    //SETTER AND GETTER FUNCTIONS
	/**
     *Size get function
     * @return _size
     */
    public int getSize() {
        return _size;
    }

	/**
     *size set function
     * @param _size (int)
     */
    public void setSize(int _size) {
        this._size = _size;
    }

	/**
     *front get function
     * @return front
     */
    public int getFront() {
        return front;
    }

	/**
     *set front function
     * @param front
     */
    public void setFront(int front) {
        this.front = front;
    }
	
	 /**
     *get back function
     * @return back
     */
    public int getBack() {
        return back;
    }

	/**
     *back set function
     * @param back
     */
    public void setBack(int back) {
        this.back = back;
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
     * @param capacity (int)
     */
    public void setCapacity(int capacity) {
        this.capacity = capacity;
    }
    
    //CONSTRUCTOR
	
	/**
     *no parameter constructor
     */
    public LinkedList(){
        _size=0; 
        capacity=500;
        arr = new Object[capacity];
    }
    
	/**
     *constructor
     * @param cap (int)
     */
    public LinkedList(int cap){
        _size=0; 
        capacity=cap;
        arr = new Object[capacity];
    }
    
    //HELPER FUNCTIONS
	
	 /**
     *(helper) verilen objenin indexini bulan fonksiyon
     * @param obj (Object)
     * @return -1 yada index
     */
    public int findIndex(Object obj){//eleman yoksa -1 return ediyor eger elemani bulursa oldugu indexi
        int flag = -1;
        for (int i=0; i <_size; i++) 
        {
                if(arr[i].equals(obj)==true)
                       flag =  i;
        }
        return flag;
    }

	/**
     *(helper) verilen objenin listede olup olmadigini anlayan fonksiyon
     * @param obj (Object)
     * @return true yada false
     */
    private boolean find_help(Object obj){//eger obje arrayde varsa true yoksa false return ediyor
        boolean find= false;
        for (int i=0; i<_size; i++) {
            if(arr[i].equals(obj)==true){
                    find=true;
                    i=_size;
            }
        }
        return find;
    }
    
	 /**
	 *dolulugu control ediyor
	 * @return true yada false
	 */
    public boolean full(){
        return (getCapacity() == getSize());
    }

     //LIST FUNCTIONS
     
     /**
     *Insert obj at the specified index position into 
     * this list. All pre-existing elements at or beyond 
     * the specified index are shifted up.
     * @param index (int) 
     * @param e (E)
     * @return true yada false
     * @throws Exception
     */
    @Override
    public boolean add(int index, E e) throws Exception {
        boolean flag = false;
            
        Object newObj= (Object) e;
        if(_size ==capacity)
        {
            capacity+=100;
            Object[] newObjArr =new Object[capacity];
            System.arraycopy(arr, 0, newObjArr, 0, arr.length);
                    //newObjArr[i]=arr[i];
            arr=null;
            arr = new Object[capacity];       
            System.arraycopy(newObjArr, 0, arr, 0, newObjArr.length);
                 //  arr[i]=newObjArr[i];               
        }
        
        else if(capacity > _size)
        {            
            arr[index]=newObj;
            setSize(_size+1);
            flag = true;            
        }
        else
        {               
               flag = false;
               throw new Exception("Capacity yeterli degil\n");
        }
        return flag;     
    }

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
    @Override
    public boolean addAll(int index, Collection<E> c) throws Exception {
         if (c == null || c.isEmpty()) 
            throw new NullPointerException("Collection is null");
       
        int i = 0, k= 0;
        //boolean flag = false;
        for (myIterator< E> iter = c.iterator(); iter.hasNext(); ++i) 
        {
            E element = iter.next(); 
            add(index, element);
            k++;
         }
        
        return (k == i);//her zaman if(add(element)) ifadesine girdiyse 1 return eder
    }

    /**
     *remove(E e) Removes a single instance of the specified element from 
     * this collection, if it is presentIt remove the specified object from the 
     * calling collection.  It returns true if collection 
     * changed after this call otherwise returns false.
     * @param e (E)
     * @return E
     * @throws Exception
     */
    @Override
    public E remove(E e) throws Exception {
        int index = findIndex(e);
        
        if(find_help(e) == false)
            throw new Exception("eleman listede degil\n");
        
        else
        {
            if(index < _size)
            {
                arr[index] = null;
                int temp = index;
                while(temp < _size)
                {
                    arr[temp] = arr[temp++];
                    arr[temp++] = null;
                    temp++;
                }
                _size--;
                return (E)e;
            } 
            else 
                throw new ArrayIndexOutOfBoundsException();
        }
    }

    /**
     *get(int index): Returns the object stored at specified index position into this list.
     * @param index (int)
     * @return E
     * @throws Exception
     */
    @SuppressWarnings("unchecked")
	@Override
    public E get(int index) throws Exception {
         if(index>this._size-1)
            throw new Exception("ArrayIndexOutOfBound");
            
            if(index<0)
                    throw new Exception("Negative value");

            Object e = (Object) arr[index];
            return (E)e;
    }

    /**
     *indexOf(Object obj): Returns index of first occurrence of obj in this list.
     * It returns -1 if obj is not exist in this list.
     * @param e (E)
     * @return index (int)
     */
    @Override
    public int indexOf(E e) {
        if (e == null) 
        {
            for (int i = 0; i < _size; i++)
            {
                if (arr[i]==null)
                    return i;
            }
        } 
        else 
        {
            for (int i = 0; i < _size; i++)
            {
                if (e.equals(arr[i]))
                    return i;
            }
        }
        return -1;
    }

     /**
     * set(int index, Object obj): Assigns obj to the specified index location within the this list.
     * @param index
     * @param e
     * @return E
     * @throws Exception
     */
    @SuppressWarnings("unchecked")
	@Override
    public E set(int index, E e) throws Exception {
        if(index>this._size-1)
           throw new Exception("ArrayIndexOutOfBound");
            
            if(index<0)
                    throw new Exception("Negative value");
                        
            arr[index] = e;
            
            return (E)this.arr[index];
    }

     //QUEUE FUNCTIONS
    
    /**
     *add(Object obj): Inserts the specified element into this queue. 
     * Returns true if queue changed after the operation otherwise returns false.
     * @param e
     * @return true yada false
     */
    @Override
    public boolean add(E e) {
       boolean flag;
       if(full())
           flag = false;
       else
       {
           if(find_help(e))
           {
               capacity++;
               arr[back] = e;
               flag = false;
           }
           else
           {
                capacity++;
                arr[back] = e;
                flag = true;
           }
       }
       return flag;
    }

    /**
     *offer(Object obj): Inserts the specified 
     * element into this queue. 
     * Returns true if the element was added to
     * this queue otherwise returns false.
     * @param e
     * @return true yada false
     * @throws Exception
     */
    @Override
    public boolean offer(E e) throws Exception{
       boolean flag;
       if(full())
       {
            flag = false;
            throw new Exception("List dolu\n");
       }
          
       else
       {
           capacity++;
           arr[back] = e;
           flag = true;
       }
       return flag;
    }

    /**
     *remove(): Returns and removes the head of this queue. 
     * It throws an exception if this queue is empty.
     * @return E
     * @throws Exception
     */
    @SuppressWarnings("unchecked")
	@Override
    public E remove() throws Exception{
        if(_size == 0)
        {
            throw new Exception("List bos\n");
        }
        Object e = arr[front];
        capacity--;
        front++;
        
        return (E)e;
    }

    /**
     *poll(): Returns and removes the head of this queue. 
     * Returns null if this queue is empty.
     * @return E
     * @throws Exception
     */
    @SuppressWarnings("unchecked")
	@Override
    public E poll() throws Exception{
        Object flag;
        if(_size == 0)
        {
            flag = null;
            throw new Exception("List bos\n");
        }
        Object e = arr[front];
        capacity--;
        front++;
        flag = e;
        
        return (E)flag;
    }

    /**
     *element(): Returns but does not removes the head of this queue.
     *It throws an exception if this queue is empty.
     * @return E
     * @throws Exception
     */
    @SuppressWarnings("unchecked")
	@Override
    public E element() throws Exception{
        Object flag = null;
      
        if(_size == 0)
        {
            flag = null;
            throw new Exception("List bos\n");
        }
        if(!(remove() instanceof Object))
        {
            flag = arr[front];
        }

        return (E)flag;
    }

    
}

