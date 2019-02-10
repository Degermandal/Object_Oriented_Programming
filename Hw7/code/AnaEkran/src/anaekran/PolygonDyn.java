
package anaekran;

import java.awt.Color;
import java.awt.Graphics;
/**
 * 
 * @author Deger
 */
public class PolygonDyn extends Polygon implements Shape {
  /**
   * 
   * 
   */
  private static final long serialVersionUID =  1L;

  private Polygon.Point2D[] dyn2D;

  private int cap;

  private int use;

  private double _area;

  private double _perimeter;

  /**
   * index degerine gore o elemani return ediyor
   * @param index
   * @return dyn2D[index]
   */
  public Polygon.Point2D getDyn2D(int index) {
        return dyn2D[index];
  }

  /**
   * cap get function
   * @return cap
   */
  public int getCap() {
        return cap;
  }

  /**
   * cap set function
   * @param cap
   */
  public void setCap(int cap) {
        this.cap = cap;
  }

  /**
   * use get function
   * @return use
   */
  public int getUse() {
        return use;
  }

  /**
   * use set function
   * @param use
   */
  public void setUse(int use) {
        this.use = use;
  }

  /**
   * rectangle objesi alir ve objenin nokatlarini dyn2D arrayine atar
   * @param rr
   * @throws Exception
   */
  public PolygonDyn(Rectangle rr) throws Exception {
        Point2D pp = new Point2D(rr.getX(), rr.getY());
        if (use >= cap)
             throw new Exception("yeterli yer yok\n");
        dyn2D[use++] = pp;
        pp = new Point2D(rr.getX()+ rr.getWidth(), rr.getY());
        if (use >= cap)
             throw new Exception("yeterli yer yok\n");
        dyn2D[use++] = pp;
        pp = new Point2D(rr.getX()+ rr.getWidth(), rr.getY()+rr.getHeight());
        if (use >= cap)
             throw new Exception("yeterli yer yok\n");
        dyn2D[use++] = pp;
        pp = new Point2D(rr.getX(), rr.getY()+rr.getHeight());
        if (use >= cap)
             throw new Exception("yeterli yer yok\n");
        dyn2D[use++] = pp;
        
        _perimeter = rr.perimeter();
        _area = rr.area();
  }

  /**
   * triangle objesi alir ve objenin nokatlarini dyn2D arrayine atar
   * @param tt
   * @throws Exception
   */
  public PolygonDyn(Triangle tt) throws Exception {
        Point2D pp = new Point2D(tt.getX(), tt.getY());
        if (use >= cap)
             throw new Exception("yeterli yer yok\n");
        dyn2D[use++] = pp;
        pp = new Point2D(tt.getxArr(0), tt.getyArr(0));
        if (use >= cap)
             throw new Exception("yeterli yer yok\n");
        dyn2D[use++] = pp;
        pp = new Point2D(tt.getxArr(1), tt.getyArr(1));
        if (use >= cap)
             throw new Exception("yeterli yer yok\n");
        dyn2D[use++] = pp;
        pp = new Point2D(tt.getxArr(2), tt.getyArr(2));
        if (use >= cap)
             throw new Exception("yeterli yer yok\n");
        dyn2D[use++] = pp;
        
        _perimeter = tt.perimeter();
        _area = tt.area();
  }

  /**
   * circle objesi alir ve objenin nokatlarini dyn2D arrayine atar
   * @param cc
   * @throws Exception
   */
  public PolygonDyn(Circle cc) throws Exception {
    double angle;
    cap = 100;
    dyn2D = new Point2D[100];

    for(int i = 0; i<100; ++i)
    {
            angle = i*(3.6)* Math.PI / 180;
            Point2D pp = new Point2D(cc.getX() + (int)(cc.getRadius() * Math.cos(angle)), cc.getY() + (int)( cc.getRadius() * Math.sin(angle)));
            if (use >= cap)
             throw new Exception("yeterli yer yok\n");
        dyn2D[use++] = pp;
    }
    _perimeter = cc.perimeter();
    _area = cc.area();
  }

  Polygon.Point2D[] getAr() {
	
    Point2D[] ar = new Point2D[getCap()];
    System.arraycopy(dyn2D, 0, ar, 0, dyn2D.length);
           //ar[i] = dyn2D[i];
    
    return ar;
  }

  /**
   * x ve y alan constructor
   * @param xx
   * @param yy
   */
  public PolygonDyn(int xx, int yy) {
     cap = 50;
     dyn2D = new Point2D[cap];
     dyn2D[use] = new Point2D(xx, yy);
     use++;
  }

  /**
   * point2d objesi alan constructor
   * @param p2d
   */
  public PolygonDyn(Polygon.Point2D p2d) {
     cap = 50;
     dyn2D = new Point2D[cap];
     dyn2D[use] = p2d;
     use++;
  }

  /**
   * triangle icin 3 tane point2d objesi alan constructor
   * @param p2d
   * @param pp2d
   * @param ppp2d
   */
  public PolygonDyn(Polygon.Point2D p2d, Polygon.Point2D pp2d, Polygon.Point2D ppp2d) {
    cap = 50;
    dyn2D = new Point2D[cap];
    dyn2D[use] = p2d;
    use++;
    dyn2D[use] = pp2d;
    use++;
    dyn2D[use] = ppp2d;
    use++;
  }

  /**
   * no parameter constructor
   */
  public PolygonDyn() {
    cap = 100;
    use = 0;
    dyn2D = new Point2D[cap];
    use++;
  }

  /**
   * capacity alan constructor
   * @param cap
   */
  public PolygonDyn(int cap) {
    this.cap = cap;
    use = 0;
    dyn2D = new Point2D[cap];
    use++;
  }

  /**
   * area function
   * @return _area
   */
  @Override
  public double area() {
        System.out.println("PolyDyn area");
       return _area;
  }

  /**
   * perimeter function
   * @return _perimeter
   */
  @Override
  public double perimeter() {
       System.out.println("PolyDyn perimeter");
       return _perimeter;
  }

  /**
   * increment function
   */
  @Override
  public void increment() {
        System.out.println("PolyDyn increment function");
       
  }

  /**
   * decrement function
   */
  @Override
  public void decrement() {
        System.out.println("PolyDyn decrement function");
      
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
   * shape draw function
   * @param g
   */
  @Override
  public void draw(Graphics g) {
           super.paintComponent(g);

           g.setColor(Color.green);
            
            g.drawLine((int)dyn2D[0].getPoint2dX(), (int)dyn2D[0].getPoint2dY(), (int)dyn2D[1].getPoint2dX(), (int)dyn2D[1].getPoint2dY());
  }

}
