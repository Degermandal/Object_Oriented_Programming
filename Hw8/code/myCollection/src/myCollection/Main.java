/**
 * 
 */
package myCollection;

/**
 * @author Deger
 *
 */
public class Main {

	/**
	 * @param args
	 * @throws Exception 
	 */
	@SuppressWarnings({ "unchecked", "rawtypes" })
	public static void main(String[] args) throws Exception {
		//DIGER BURDA DENEMEDIGIM FONKSIYONLARIN KODLARI VARDIR
        //ZAMANIM KALMADIGI ICIN DUZENLI BIR SEKILDE YAZAMADIM
            
            System.out.printf("\n\n%s\n\n","...........................HASHSET<String>...............................................................");
            Set hashSet = new HashSet();
            if( hashSet.add("elem1"))
           {
               System.out.println("Hashset Add fonksiyonu calisti");
           }
           if( hashSet.add("elem2"))
           {
               System.out.println("Hashset Add fonksiyonu calisti");
           }
            if( hashSet.add("elem3"))
           {
               System.out.println("Hashset Add fonksiyonu calisti");
           }
            
           if( hashSet.contains("elem3"))
           {
               System.out.println("Hashset Contains fonksiyonu calisti");
           }
           if(hashSet.isEmpty() == true)
                System.out.println("Hashset bos");
           else
                System.out.println("Hashset bos degil");
           
           if(hashSet.remove("elem3"))
           {
               System.out.println("Hashset Remove fonksiyonu calisti");
           }
           
           System.out.println("Hashset size " +hashSet.size() + " dir.");

           hashSet.clear();
           if(hashSet.size() == 0)
              System.out.println("Clear fonksiyonu calistirildi. Hashset size " +hashSet.size() + " dir.");
           
           
        
           System.out.printf("\n\n%s\n\n","...........................ARRAYLIST<String>...............................................................");
            
           ArrayList list  = new ArrayList();
           
            if( list.add(0,"elem1"))
           {
               System.out.println("ArrayList Add fonksiyonu calisti");
           }
           if( list.add(1,"elem2"))
           {
               System.out.println("ArrayList Add fonksiyonu calisti");
           }
            if( list.add(2,"elem3"))
           {
               System.out.println("ArrayList Add fonksiyonu calisti");
           }
           
           if((list.remove("elem3")) != null)
           {
               System.out.println("ArrayList Remove fonksiyonu calisti");
           }

           System.out.println("ArrayList 2. eleman icin get fonksiyonu calisti. "+ " Return degeri "+ list.get(1) + " .");
           System.out.println("ArrayList -elem2- stringi icin indexof fonksiyonu calisti. "+ " Return degeri "+ list.indexOf("elem2") + " .");
           System.out.println("ArrayList set fonksiyonu calisti. "+ " Return degeri "+ list.set(1, "elemSet") + " .");
            
    
            
           System.out.printf("\n\n%s\n\n", "...........................LINKEDLIST<String>...............................................................");

            LinkedList lList = new LinkedList();


            if( lList.add(0,"elem1"))
                System.out.println("LinkedList List Add fonksiyonu calisti");

            if( lList.add(1, "elem2"))
                System.out.println("LinkedList List Add fonksiyonu calisti");

             if( lList.add(2,"elem3"))
                System.out.println("LinkedList List Add fonksiyonu calisti");


            if((lList.remove("elem3")) != null)
                System.out.println("LinkedList List Remove fonksiyonu calisti");


            System.out.println("LinkedList List 2. eleman icin get fonksiyonu calisti. "+ " Return degeri "+ list.get(1) + " .");
            System.out.println("LinkedList List -elem2- stringi icin indexof fonksiyonu calisti. "+ " Return degeri "+ list.indexOf("elem2") + " .");
            System.out.println("LinkedList List set fonksiyonu calisti. "+ " Return degeri "+ list.set(1, "elemSet") + " .");
            
            

            System.out.printf("\n%s\n", "..............................................................................................................");

            if( lList.add("elem4"))
                System.out.println("LinkedList Queue Add fonksiyonu calisti");

            if( lList.add("elem5"))
                System.out.println("LinkedList Queue Add fonksiyonu calisti");

             if( lList.add("elem6"))
                System.out.println("LinkedList Queue Add fonksiyonu calisti");

            if(lList.offer("elem7") == true)
                 System.out.println("LinkedList Queue offer fonksiyonu calisti");


            if(lList.remove() != null)
                 System.out.println("LinkedList Queue Remove fonksiyonu calisti");

            if(lList.poll() != null)
                 System.out.println("LinkedList Queue pool fonksiyonu calisti");
            else
                 System.out.println("LinkedList Queue pool fonksiyonu calisti. Liste bos");

             if(lList.element() != null)
                 System.out.println("LinkedList Queue element fonksiyonu calisti");
             
             

            System.out.printf("\n\n%s\n\n","...........................HASHSET<Int>...............................................................");
            
            Set hashSet2 = new HashSet();
            if( hashSet2.add(1))
           {
               System.out.println("Hashset Add fonksiyonu calisti");
           }
           if( hashSet2.add(2))
           {
               System.out.println("Hashset Add fonksiyonu calisti");
           }
            if( hashSet2.add(3))
           {
               System.out.println("Hashset Add fonksiyonu calisti");
           }
            
           if( hashSet2.contains(3))
           {
               System.out.println("Hashset Contains fonksiyonu calisti");
           }
           if(hashSet2.isEmpty() == true)
                System.out.println("Hashset bos");
           else
                System.out.println("Hashset bos degil");
           
           if(hashSet2.remove(3))
           {
               System.out.println("Hashset Remove fonksiyonu calisti");
           }
           
           System.out.println("Hashset size " +hashSet2.size() + " dir.");


        
           System.out.printf("\n\n%s\n\n","...........................ARRAYLIST<Int>...............................................................");
            
           ArrayList list2  = new ArrayList();
           
            if( list2.add(0,1))
           {
               System.out.println("ArrayList Add fonksiyonu calisti");
           }
           if( list2.add(1,2))
           {
               System.out.println("ArrayList Add fonksiyonu calisti");
           }
            if( list2.add(2,3))
           {
               System.out.println("ArrayList Add fonksiyonu calisti");
           }
           
           if((list2.remove(3)) != null)
           {
               System.out.println("ArrayList Remove fonksiyonu calisti");
           }

           System.out.println("ArrayList 2. eleman icin get fonksiyonu calisti. "+ " Return degeri "+ list2.get(1) + " .");
           System.out.println("ArrayList -2- integeri icin indexof fonksiyonu calisti. "+ " Return degeri "+ list2.indexOf(2) + " .");
           System.out.println("ArrayList set fonksiyonu calisti. "+ " Return degeri "+ list2.set(1, 10) + " .");
            
    
            
           System.out.printf("\n\n%s\n\n","...........................LINKEDLIST<Int>...............................................................");

            LinkedList lList2 = new LinkedList();


            if( lList2.add(0,1))
                System.out.println("LinkedList List Add fonksiyonu calisti");

            if( lList2.add(1, 2))
                System.out.println("LinkedList List Add fonksiyonu calisti");

             if( lList2.add(2,3))
                System.out.println("LinkedList List Add fonksiyonu calisti");


            if((lList2.remove(3)) != null)
                System.out.println("LinkedList List Remove fonksiyonu calisti");


            System.out.println("LinkedList List 2. eleman icin get fonksiyonu calisti. "+ " Return degeri "+ list.get(1) + " .");
            System.out.println("LinkedList List -elem2- stringi icin indexof fonksiyonu calisti. "+ " Return degeri "+ list.indexOf(2) + " .");
            System.out.println("LinkedList List set fonksiyonu calisti. "+ " Return degeri "+ list.set(1, 10) + " .");

            System.out.printf("\n%s\n","..............................................................................................................");

            if( lList2.add(4))
                System.out.println("LinkedList Queue Add fonksiyonu calisti");

            if( lList2.add(5))
                System.out.println("LinkedList Queue Add fonksiyonu calisti");

             if( lList2.add(6))
                System.out.println("LinkedList Queue Add fonksiyonu calisti");

            if(lList2.offer(7) == true)
                 System.out.println("LinkedList Queue offer fonksiyonu calisti");


            if(lList2.remove() != null)
                 System.out.println("LinkedList Queue Remove fonksiyonu calisti");

            try {
				if(lList2.poll() != null)
				     System.out.println("LinkedList Queue pool fonksiyonu calisti");
				else
				     System.out.println("LinkedList Queue pool fonksiyonu calisti. Liste bos");
			} catch (Exception e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}

             try {
				if(lList2.element() != null)
				     System.out.println("LinkedList Queue element fonksiyonu calisti");
			} catch (Exception e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
            
            
  

	}

}
