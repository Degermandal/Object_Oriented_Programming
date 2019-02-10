
package anaekran;

import java.awt.Color;
import java.awt.Graphics;
import java.util.Random;
import javax.swing.JPanel;
/**
 * 
 * @author Deger
 */
public class ComposedShape extends JPanel implements Shape {
  /**
   * 
   * 
   */
  private static final long serialVersionUID =  1L;

  /**
   * variable
   */
  private int capacity;

  private int used;

  private double _area =  0;

  private double _perimeter =  0;

  Rectangle small_rec;

  Triangle small_tri;

  Circle small_cir;

  Rectangle main_rec;

  Triangle main_tri;

  Circle main_cir;

  /**
   * bu degiskenler hangi iki objeyi aldigim bulmak icin kullandigim bu classa ozel degiskenler
   * optimalfit fonksiyonum icin kullandim
   */
  char myMainCon;

  char mySmallCon;

  /**
   * array ve arraylist
   */
  Shape[] refShapeArr =  null;

  /**
   * SETTER AND GETTER FUNCTIONS
   * 
   * area get function
   * @return _area
   */
  public double getArea() {
        return _area;
  }

  /**
   * area set function
   * @param _area
   */
  public void setArea(double _area) {
        this._area = _area;
  }

  /**
   * perimeter get function
   * @return _perimeter
   */
  public double getPerimeter() {
        return _perimeter;
  }

  /**
   * perimeter set function
   * @param _perimeter
   */
  public void setPerimeter(double _perimeter) {
        this._perimeter = _perimeter;
  }

  /**
   * capacity set function
   * @param capacity
   */
  public void setCapacity(int capacity) {
        this.capacity = capacity;
  }

  /**
   * used set function
   * @param used
   */
  public void setUsed(int used) {
        this.used = used;
  }

  /**
   * capacity get function
   * @return capacity
   */
  public int getCapacity() {
        return capacity;
  }

  /**
   * used get function
   * @return used
   */
  public int getUsed() {
        return used;
  }

  /**
   * shape tipindeki arrayin get fonksiyonu indexdeki deger return ediyor
   * @param index
   * @return refShapArr[index]
   */
  public Shape getRefShapeArr(int index) {
        return refShapeArr[index];
  }

  /**
   * main_rec get function
   * @return main_rec
   */
  public Rectangle getMain_rec() {
        return main_rec;
  }

  /**
   * small container icin char degeri
   * @return mySmallCon
   */
  public char getMySmallCon() {
        return mySmallCon;
  }

  /**
   * big container icin char degeri
   * @return myMainCon
   */
  public char getMyMainCon() {
        return myMainCon;
  }

  /**
   * CONSTRUCTORS
   * 
   * rec-tri constructor
   * @param rec
   * @param tri
   */
  public ComposedShape(Rectangle rec, Triangle tri) {
        capacity = 1000;
        used = 0;
        refShapeArr = new Shape[capacity];
        main_rec = rec;// alinan parametreye gore privatemdaki objelere atiyorum
        small_tri = tri;

        myMainCon = 'R';//optimalFitte uygun fonksiyou cagirabilmek icin char atamasi yaptim
        mySmallCon = 'T';

  }

  /**
   * rec-tri constructor
   * @param rec
   * @param tri
   */
  ComposedShape(Rectangle rec, Circle cir) {
        capacity = 1000;
         used = 0;
         refShapeArr = new Shape[capacity];
        main_rec = rec;
        small_cir = cir;

        myMainCon = 'R';
        mySmallCon = 'C';
  }

  /**
   * rec-rec constructor
   * @param rec
   * @param rec2
   */
  ComposedShape(Rectangle rec, Rectangle rec2) {
        capacity = 1000;
        used = 0;

        refShapeArr = new Shape[capacity];
        main_rec = rec;
        small_rec = rec2;

        myMainCon = 'R';
        mySmallCon = 'R';

  }

  /**
   * tri-tri constructor
   * @param tri
   * @param tri2
   */
  ComposedShape(Triangle tri, Triangle tri2) {
        capacity = 1000;
        used = 0;
        refShapeArr = new Shape[capacity];
        main_tri = tri;
        small_tri = tri2;

        myMainCon = 'T';
        mySmallCon = 'T';
  }

  /**
   * tri-rec constructor
   * @param tri
   * @param rec
   */
  ComposedShape(Triangle tri, Rectangle rec) {
        capacity = 1000;
        used = 0;
        refShapeArr = new Shape[capacity];
        main_tri = tri;
        small_rec = rec;

        myMainCon = 'T';
        mySmallCon = 'R';
  }

  /**
   * tri-cir constructor
   * @param tri
   * @param cir
   */
  ComposedShape(Triangle tri, Circle cir) {
        capacity = 1000;
        used = 0;
        refShapeArr = new Shape[capacity];
        main_tri = tri;
        small_cir = cir;

        myMainCon = 'T';
        mySmallCon = 'C';

  }

  /**
   * cir-tri constructor
   * @param cir
   * @param tri
   */
  ComposedShape(Circle cir, Triangle tri) {
        capacity = 1000;
        used = 0;
        refShapeArr = new Shape[capacity];
        main_cir = cir;
        small_tri = tri;

        myMainCon = 'C';
        mySmallCon = 'T';

  }

  /**
   * cir-rec constructor
   * @param cir
   * @param rec
   */
  ComposedShape(Circle cir, Rectangle rec) {
        capacity = 1000;
        used = 0;
        refShapeArr = new Shape[capacity];
        main_cir = cir;
        small_rec = rec;

        myMainCon = 'C';
        mySmallCon = 'R';

  }

  /**
   * cir-cir2 constructor
   * @param cir
   * @param cir2
   */
  ComposedShape(Circle cir, Circle cir2) {
        capacity = 1000;
        used = 0;
        refShapeArr = new Shape[capacity];
        main_cir = cir;
        small_cir = cir2;

        myMainCon = 'C';
        mySmallCon = 'C';
  }

  /**
   * composed Shape area, butun sekillerin area toplamini return ediyor
   * @return _area
   */
  @Override
  public double area() {
                       System.out.printf("%s%f%s\n", "ComposedShape area  ", _area, " .");
                       return _area;
  }

  /**
   * composed Shape perimeter, butun sekillerin perimeter toplamini return ediyor
   * @return _perimeter
   */
  @Override
  public double perimeter() {
                       System.out.printf("%s%f%s\n", "ComposedShape perimeter  ", _perimeter, " .");
                       return _perimeter;
  }

  /**
   * Composed shape increment function
   */
  @Override
  public void increment() {
                System.out.println("ComposedShape increment function");
   
  }

  /**
   * ComposedShape decrement function
   */
  @Override
  public void decrement() {
                      System.out.println("ComposedShape decrement function");
  }

  /**
   * shape objesine gore alan karsilastirma yapiyor
   * @param sh (Shape)
   * @return esit ise 0, parametre alani daha buyukse 1, diger durumda -1
   */
  @Override
  public int compareTo(Shape sh) {
                       if(area() == sh.area())
                           return 0;
                       else if(area() < sh.area())
                           return 1;
                       else
                           return -1;
                
  }

  /**
   * Composed shapedeki refShapeArrdaki sekillere gore draw yapiyor
   * @param g
   */
  @Override
  public void draw(Graphics g) {

                for (Shape refShapeArr1 : refShapeArr) 
                {
                            Random rand = new Random();
                            int color = rand.nextInt(9) + 1; //1-11 arasi sayi uretir
                            if(color == 1)      g.setColor(Color.red);
                            if(color == 2)      g.setColor(Color.green);
                            if(color == 3)      g.setColor(Color.yellow);
                            if(color == 4)      g.setColor(Color.black);
                            if(color == 5)      g.setColor(Color.orange);
                            if(color == 6)      g.setColor(Color.pink);
                            if(color == 7)      g.setColor(Color.cyan);
                            if(color == 8)      g.setColor(Color.blue);
                            if(color == 9)      g.setColor(Color.gray);
                            if(color == 10)      g.setColor(Color.magenta);

                            refShapeArr1.draw(g);
                            //System.out.println("vbn    "+ refShapeArr1.getClass());
                }
                        
  }

  /**
   * REC-TRI OPTIMAL
   */
  public void optimalRec_Tri() {
            refShapeArr[used++] = main_rec;//arrayin 0. elemani hep buyuk sekil olsun istiyorum
            
            _area += main_rec.area();
            _perimeter += main_rec.perimeter();
 
            int x = 0;
            int y = 0;           
            int a = small_tri.getEdge()/2;

            for(int i = (int)( a * Math.sqrt(2.0)) ; i<= main_rec.getHeight();  i+= (int) (a * Math.sqrt(3.0)))//yukseklik icin ilerlenmesi gereken kadar donuyor
            {
                        for(int j = (int)(1*small_tri.getEdge()) ; j<= main_rec.getWidth(); j+= small_tri.getEdge())//yana dogru kac tane ucgen cizilecegi
                        {
                                Shape ptr = new Triangle(small_tri.getEdge(),  x ,  y, x+a, y+a*(int)Math.sqrt(3), x+small_tri.getEdge(), y);		
                                refShapeArr[used++] = ptr;
                                //System.out.println("fgh   "+ small_tri.area());
                                //System.out.println("dhj   "+ptr.getClass());
                                _area += ptr.area();
                                _perimeter += ptr.perimeter();
                                //ters  ucgenlerim
                                ptr = new Triangle(small_tri.getEdge(), x+small_tri.getEdge(), y, x+a, y+a*(int)Math.sqrt(3.0), x+small_tri.getEdge()+a, y+a*(int)Math.sqrt(3.0));
                                refShapeArr[used++] = ptr;
                                _area += ptr.area();
                                _perimeter += ptr.perimeter();

                                x += small_tri.getEdge();	
                        }

                        x =0;
                        y+=a*(int)Math.sqrt(3.0);
             }

  }

  /**
   * TRI-TRI OPTIMAL
   */
  public void optimalTri_Tri() {
    refShapeArr[used++] = main_tri; //arrayin 0. elemani hep buyuk sekil olsun istiyorum
    _area += main_tri.area();
     _perimeter += main_tri.perimeter();

    int mainHalfEdge = main_tri.getEdge()/2;

    int smallHalfEdge = small_tri.getEdge()/2;
    int newDistance =  main_tri.getEdge(); //newdistance degiskenim benim alt cigimi tutuyor x koordinatinda ne kadar gidecegimi

    int x = 0;
    int  y = 0;
    int count = 1;//dongu icin tuttun kac defa dondugunu buluyorum

            while(newDistance > small_tri.getEdge())//newdistance kucuk ucgenin bir kenari oluncaya kadar (ne kadar yukari cikacagi)
            {
                    double numOfRec = newDistance/small_tri.getEdge();//kac tane yerlestirebiliyorum x koordinati boyunca

                    for(int i = 1; i<numOfRec; i++)
                    {
                                    //duz kucuk ucgenlerimin koordinatlari
                                    Shape  ptr = new Triangle(small_tri.getEdge(), x + smallHalfEdge, y +mainHalfEdge*(int)Math.sqrt(3.0)- smallHalfEdge*(int)Math.sqrt(3.0), x, y+mainHalfEdge*(int)Math.sqrt(3.0),
                                                            x+small_tri.getEdge(), y+mainHalfEdge*(int)Math.sqrt(3.0));

                                   refShapeArr[used++] = ptr;
                                   _area += ptr.area();
                                   _perimeter += ptr.perimeter();

                                    ptr = new Triangle(small_tri.getEdge(), x+ smallHalfEdge, y +mainHalfEdge*(int)Math.sqrt(3.0)- smallHalfEdge*(int)Math.sqrt(3.0), 
                                                    x+small_tri.getEdge(), y+mainHalfEdge*(int)Math.sqrt(3.0), x+small_tri.getEdge()+smallHalfEdge, y+mainHalfEdge*(int)Math.sqrt(3.0)- smallHalfEdge*(int)Math.sqrt(3.0));
                                    refShapeArr[used++] = ptr;
                                    _area += ptr.area();
                                     _perimeter += ptr.perimeter();
                                    x += small_tri.getEdge();//bu arttirma x koordinatinda ilerlememi sagliyor
                    }

                    x = 0;//x i tekrradan sifirliyorum
                    x += count*smallHalfEdge;//her dongu kadar x koordinatinda ilerlemis olmam gerekiyor
                    count++;//dongu icin arttirma

                    newDistance -= small_tri.getEdge();//yukari dogru ilerledikce kucuk ucgenin kenari kadar azaliyor
                    y -= smallHalfEdge*(int)Math.sqrt(3.0); //y koordinati her seferinde kucuk ucgenin kenar uzunlugunun yarisinin kok uc kati kadar azaliyor
            }

  }

  /**
   * TRI-REC OPTIMAL
   */
  public void optimalTri_Rec() {
    refShapeArr[used++] = main_tri; //arrayin 0. elemani hep buyuk sekil olsun istiyorum
    _area += main_tri.area();
     _perimeter += main_tri.perimeter();

    int halfEdge = main_tri.getEdge()/2;

    double newDistance = main_tri.getEdge() - (2.0/3 * (int)Math.sqrt(3.0)*small_rec.getHeight());//yukari cikildikta azalan alt kenar uzunlugu icin newdistance beliledim
    int x = small_rec.getHeight()* (int)Math.sqrt(3.0) / 3;//ucgen ve dikdortgenime gore matematiksel x ve y belirledim
    int y = halfEdge*(int)Math.sqrt(3.0) - small_rec.getHeight();
    int count = 1;//dongu icin
    
    while(newDistance >= small_rec.getWidth())//en az dikdortgenin genisligi kadar olmali
    {
            double numOfRec = newDistance/small_rec.getWidth();//en alta kac tane dikdortgen gelecegi

            for(int i = 0; i<numOfRec; i++)
            {
                    Shape ptr = new Rectangle(small_rec.getWidth(), small_rec.getHeight(), x, y);
                      refShapeArr[used++] = ptr;
                      _area += ptr.area();
                        _perimeter += ptr.perimeter();

                    x += small_rec.getWidth();
            }

            x = small_rec.getHeight()*(int)Math.sqrt(3.0) / 3 + (small_rec.getWidth()/3*count);//matematiksel olarak degisen degerler
            newDistance -= (2.0/3*(int)Math.sqrt(3.0)*small_rec.getHeight());
            y -= small_rec.getHeight();
            count++;
    }

	
  }

  /**
   * TRI-CIR OPTIMAL
   * @throws Exception
   */
  public void optimalTri_Cir() throws Exception {
                       refShapeArr[used] = main_tri;//arrayin 0. elemani hep buyuk sekil olsun istiyorum
                       used++;
                       _area += main_tri.area();
                        _perimeter += main_tri.perimeter();

	int halfEdge = main_tri.getEdge()/2;
	double sDiameter = 2*small_cir.getRadius();

	double distance = main_tri.getEdge() / sDiameter;
	int x = small_cir.getRadius()*(int)Math.sqrt(3.0);
	int y = halfEdge*(int)Math.sqrt(3.0) - small_cir.getRadius();	

	int count = 1;

	while(main_tri.getEdge() >= sDiameter)
	{
		for(int i = 2; i<distance; i++)
		{
                                                        Shape ptr = new Circle(small_cir.getRadius(), x, y);
                                                        refShapeArr[used] = ptr;
                                                        used++;
                                                        _area += ptr.area();
                                                        _perimeter += ptr.perimeter();

                                                        x += sDiameter;
		}

		int lvalue = main_tri.getEdge()*(8/10);

		main_tri.setEdge(lvalue);
		distance = main_tri.getEdge() / sDiameter;
		x = small_cir.getRadius()*(int)Math.sqrt(3.0) +(int) (sDiameter/1.4)*count;
		count++;
		y -= sDiameter;
	}
  }

  /**
   * CIR-CIR OPTIMAL
   */
  public void optimalCir_Cir() {
            refShapeArr[used] = main_cir;
            used++;
            _area += main_cir.area();
            _perimeter += main_cir.perimeter();

             int sDiameter = 2*small_cir.getRadius();
             int Rr = main_cir.getRadius()/sDiameter;//kac tane cember sigar

             int x = main_cir.getRadius() - (Rr*sDiameter) + small_cir.getRadius();//matematiksel koordinatlar
             int y = main_cir.getRadius() - (Rr*sDiameter) + small_cir.getRadius();

             for(int i = sDiameter; i<= (2*Rr*sDiameter); i+=sDiameter)//ilerleme mikarlari
             {
                     for(int j = sDiameter; j<=2*Rr*sDiameter; j+=sDiameter)
                     {
                             if((Math.pow(x - main_cir.getRadius(), 2) +Math. pow(y - main_cir.getRadius(), 2)) < Math.pow(main_cir.getRadius(), 2) )
                             {
                                     Shape ptr = new Circle(small_cir.getRadius(), x, y);
                                    refShapeArr[used] = ptr;
                                    used++;
                                    _area += ptr.area();
                                     _perimeter += ptr.perimeter();
                             }
                             x += sDiameter;
                     }

                     x = main_cir.getRadius() - (Rr*sDiameter)+small_cir.getRadius();
                     y+=sDiameter;
             }
  }

  /**
   * CIR-REC OPTIMAL
   */
  public void optimalCir_Rec() {
            refShapeArr[used] = main_cir;//arrayin 0. elemani hep buyuk sekil olsun istiyorum
            used++;
            _area += main_cir.area();
           _perimeter += main_cir.perimeter();

            int diago = (int)Math.sqrt(Math.pow(small_rec.getWidth(),2) + Math.pow(small_rec.getHeight(),2)); //dikdorgenin kosegen uzunlugu

            int Rr = main_cir.getRadius()/diago;//kosegene gore main cemberin yaricapina ne kadar dikdorgen sigacagi

            int x = main_cir.getRadius() - (Rr*small_rec.getWidth());
            int y = main_cir.getRadius() - (Rr*small_rec.getHeight());

            for(int i = 0; i<= (2*Rr*small_rec.getHeight()); i+=small_rec.getHeight())
            {
                        for(int j = 0; j<= (2*Rr*small_rec.getWidth()); j+=small_rec.getWidth())
                        {
                                    Shape ptr = new Rectangle(small_rec.getWidth(), small_rec.getHeight(), x, y);
                                    refShapeArr[used] = ptr;
                                    used++;
                                    _area += ptr.area();
                                    _perimeter += ptr.perimeter();

                            x += small_rec.getWidth();
                        }

            x = main_cir.getRadius() - (Rr*small_rec.getWidth());
            y+=small_rec.getHeight();
            }
  }

  /**
   * REC-TRI OPTIMAL
   */
  public void optimalRec_Cir() {
    refShapeArr[used] = main_rec; //arrayin 0. elemani hep buyuk sekil olsun istiyorum
     used++;
     _area += main_rec.area();
    _perimeter += main_rec.perimeter();

    int x = small_cir.getRadius();
    int y = small_cir.getRadius();
    int bRadius = 2*small_cir.getRadius();


    for(int i = bRadius; i<=main_rec.getHeight(); i+=bRadius)//mantigi asagi ve yana dogru ilerleme
    {
            for(int j = bRadius; j<= main_rec.getWidth(); j+= bRadius)
            {
                    Shape ptr = new Circle(small_cir.getRadius(), x, y);
                    refShapeArr[used] = ptr;
                     used++;
                     _area += ptr.area();
                        _perimeter += ptr.perimeter();

                    x += bRadius;
            }

            x = small_cir.getRadius();
            y+= bRadius;
    }

  }

  /**
   * REC-REC OPTIMAL
   */
  public void optimalRec_Rec() {
    refShapeArr[used] = main_rec; //arrayin 0. elemani hep buyuk sekil olsun istiyorum
     used++;
     _area += main_rec.area();
     _perimeter += main_rec.perimeter();

    int x =0;
    int y =0;

    for(int i = small_rec.getHeight(); i<=main_rec.getHeight(); i+=small_rec.getHeight())
    {
            for(int j = small_rec.getWidth(); j<= main_rec.getWidth(); j+= small_rec.getWidth())
            {
                    Shape ptr = new Rectangle(small_rec.getWidth(), small_rec.getHeight(), x, y);

                    refShapeArr[used] = ptr;
                     used++;
                     _area += ptr.area();
                        _perimeter += ptr.perimeter();

                    x += small_rec.getWidth();
            }

            x = 0;
            y+= small_rec.getHeight();
    }
  }

  /**
   * CIR-TRI OPTIMAL
   */
  public void optimalCir_Tri() {
            refShapeArr[used] = main_cir; //arrayin 0. elemani hep buyuk sekil olsun istiyorum
             used++;
             _area += main_cir.area();
            _perimeter += main_cir.perimeter();

    int x = (main_cir) .getRadius()/2;
    int y = (main_cir) .getRadius()/2;

    int a = small_tri.getEdge()/2;

    for(int i = 0; i<= main_cir.getRadius(); i+=(a*(int)Math.sqrt(3.0)))//yukseklik icin ilerlenmesi gereken kadar donuyor
    {
            for(int j = 0; j<= main_cir.getRadius()*2; j+= small_tri.getEdge())//yana dogru kac tane ucgen cizilecegi
            {			
                    Shape ptr = new Triangle(small_tri.getEdge(), x, y, x+a, y+a*(int)Math.sqrt(3.0), x+small_tri.getEdge(), y);

                    refShapeArr[used] = ptr;
                    used++;
                    _area += ptr.area();
                        _perimeter += ptr.perimeter();

                    ptr = new Triangle(small_tri.getEdge(), x+small_tri.getEdge(), y, x+a, y+a*(int)Math.sqrt(3.0), x+small_tri.getEdge()+a, y+a*(int)Math.sqrt(3.0));
                    refShapeArr[used] = ptr;
                    used++;
                    _area += ptr.area();
                        _perimeter += ptr.perimeter();

                    x += small_tri.getEdge();
            }

            x =0;
            y+=a*(int)Math.sqrt(3.0);
    }
  }

  /**
   * OPTIMALFIT
   * @throws Exception
   */
  public void optimalFit() throws Exception {
		    if(myMainCon == 'R' && mySmallCon == 'R')
		            optimalRec_Rec();
		
		    else if(myMainCon == 'R' && mySmallCon == 'C')
		            optimalRec_Cir();
		
		    else if(myMainCon == 'R' && mySmallCon == 'T')
		            optimalRec_Tri();
		
		    else if(myMainCon == 'C' && mySmallCon == 'C')
		            optimalCir_Cir();
		
		    else if(myMainCon == 'C' && mySmallCon == 'R')
		            optimalCir_Rec();
		
		    else if(myMainCon == 'C' && mySmallCon == 'T')
		            optimalCir_Tri();
		
		    else if(myMainCon == 'T' && mySmallCon == 'C')
		            optimalTri_Cir();
		
		    else if(myMainCon == 'T' && mySmallCon == 'R')
		            optimalTri_Rec();
		
		    else if(myMainCon == 'T' && mySmallCon == 'T')
		            optimalTri_Tri();
		
		    else
		            throw new Exception("ComposedShape Fail -optimalFit-!!");

  }

}
