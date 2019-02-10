/**
 * 
 */
package myCollection;



/**
 *
 * @author Deger
 * @param <E>
 */
public class HashSet<E> implements Set<E>{

    private myIterator<E> it;
    
    private Object[] arr ;
    private int _size; 
    private int capacity;
    
    //CONSTRUCTOR
	/**
     *no parameter constructor
     */
    public HashSet(){
        _size=0; 
        capacity=500;
        arr = new Object[capacity];
    }
    
	/**
     *constructor
     * @param cap (int)
     */
    public HashSet(int cap){
        _size=0; 
        capacity=cap;
        arr = new Object[capacity];
    }
    
  //SETTER AND GETTER FUNCTIONS
  
	/**
     *get size function
     * @return _size
     */
    public int getSize() {
        return _size;
    }

	/**
     *set size function
     * @param _size
     */
    public void setSize(int _size) {
        this._size = _size;
    }

	 /**
     *get capacity function
     * @return capacity
     */
    public int getCapacity() {
        return capacity;
    }

	 /**
     *set capacity function
     * @param capacity
     */
    public void setCapacity(int capacity) {
        this.capacity = capacity;
    }
    
// HELPER FUNCTIONS 
    
/*    
    public boolean full()
    {
        return (getCapacity() == getSize());
    }
*/			

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
        for (int i=0; i<_size; i++)
        {
            if(arr[i].equals(obj)==true)
            {
                find=true;
                i=_size;
            }
        }
        return find;
    }
   
    //SET INTERFACE FUNCTIONS
    
    @SuppressWarnings({ "unchecked", "rawtypes" })
	/**
     *Returns an iterator over the collection
     * @return myIterator
     */
    @Override
    public myIterator<E> iterator() {   
       it = new myIterator(arr);
       return it;
    }

    /**
     *Ensures that this collection contains the specified element
     * @param e
     * @return true yada false
     * @throws Exception
     */
    @Override
    public boolean add(E e) throws Exception{
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
            if(find_help(e) == false)
            {
                arr[_size]=newObj;
                setSize(_size+1);
                flag = true;
            }
            else
            {
                flag = false;
                throw new Exception("Bu elemani 2. kez ekleyemezsiniz\n");
            }
        }
        else
        {               
           flag = false;
           throw new Exception("Capacity yeterli degil\n");
        }
        return flag;     
    }

    /**
     *Adds all of the elements in the specified collection to this collection
     * @param c (Collection)
     * @return true yada false
     */
    @Override
    public boolean addAll(Collection<E> c) throws Exception {
 
         if (c == null || c.isEmpty()) 
            throw new NullPointerException("Collection is null");
       
        int i = 0, k= 0;
        //boolean flag = false;
        for (myIterator< E> iter = c.iterator(); iter.hasNext(); ++i) 
        { 
            E element = iter.next(); 
            add(element);
            k++;              
         }        
        return (k == i);//her zaman if(add(element)) ifadesine girdiyse 1 return eder        
    }

     /**
     *Removes all of the elements from this collection
     */
    @Override
    public void clear() {
        arr=null;
        arr=new Object[capacity];
        setSize(0);
    }

     /**
     *Returns true if this collection contains the specified element.
     * @param e 
     * @return true yada false
     */
    @Override
    public boolean contains(E e) {
        return (find_help(e) == true);
    }

    /**
     *Returns true if this collection contains all of the elements in the specified collection.
     * @param c
     * @return true yada false
     * @throws Exception
     */
    @Override
    public boolean containsAll(Collection<E> c) throws Exception{
         if (c == null || c.isEmpty()) 
            throw new NullPointerException("Collection is null");
       
        int i = 0, k=0;
    //    boolean flag = false;
        for (myIterator<E> iter = c.iterator(); iter.hasNext();  ++i) 
        {
            E element = iter.next();
            if(contains(element))
                k++;       
        }
        return (k == i); //her zaman if(contains(element)) ifadesine girdiyse 1 return eder
    }

    
    /**
     *Returns true if this collection contains no elements.
     * @return true yada false
     */
    @Override
    public boolean isEmpty() {
        return (_size == 0);
    }
   
    /**
     *Removes a single instance of the specified element from this collection, if it is present
     * @param e
     * @return true yada false
     * @throws Exception
     */
    @Override
    public boolean remove(E e) throws Exception{
        int index = findIndex(e);
        boolean flag;
        
        if(find_help(e) == false)
        {
            flag = false;
            throw new Exception("eleman listede degil\n");
        }
        
        else
        {
            if(index < _size)//arrayde o elemani sildikten sonra ilerletmemiz gerkiyor o indexten sonra
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
               flag = true;
            } 
            else 
            {
                flag = false;
                throw new ArrayIndexOutOfBoundsException();
            }
        }
        
           return flag;
    }

    /**
     *Removes all of this collection's elements that are also contained in the specified collection
     * @param c
     * @return true yada false
     * @throws Exception
     */
    @Override
    public boolean removeAll(Collection<E> c) throws Exception{
         if (c == null || c.isEmpty()) 
            throw new NullPointerException("Collection is null");
               
        int i = 0, k=0;
    //    boolean flag = false;
        for (myIterator< E> iter = c.iterator(); iter.hasNext();  ++i) 
        {           
             E element = iter.next();
             if(remove(element))       
                 k++;           
        }
        return (k == i); //her zaman if(remove(element)) ifadesine girdiyse 1 return eder
    }

     /**
     *Retains only the elements in this collection that are contained in the specified collection
     * @param c
     * @return true yada false
     * @throws Exception
     */
    @Override
    public boolean retainAll(Collection<E> c) throws Exception {
        boolean flag = false;
        if(c == null)
                throw new NullPointerException("Collection is null");
        
        myIterator<E> iter = iterator();
        while(iter.hasNext())
        {   
            if(!c.contains(iter.next()))
            {
                E element = iter.next();
                remove(element); 
                flag = true; 
            }
        }

        return flag;
    }
    
    /**
     *Returns the number of elements in this collection.
     * @return _size (int)
     */
    @Override
    public int size() {
        return _size;
    }
    
}

