
package anaekran;

import java.awt.Color;
import java.awt.Graphics;
import java.util.ArrayList;
/**
 * 
 * @author Deger
 */
public class PolygonVect extends Polygon implements Shape {
  /**
   * 
   * 
   */
  private static final long serialVersionUID =  1L;

  private ArrayList<Polygon.Point2D> vec2D;

  private double _area;

  private double _perimeter;

  private ArrayList<Polygon.Point2D > ar;

  /**
   * rectangle objesi alir ve objenin noktalarini vec2D arraylistine atar
   * @param rr
   */
  public PolygonVect(Rectangle rr) {
        Point2D pp = new Point2D(rr.getX(), rr.getY());
        vec2D.add(pp);
        pp = new Point2D(rr.getX()+ rr.getWidth(), rr.getY());
        vec2D.add(pp);
        pp = new Point2D(rr.getX()+ rr.getWidth(), rr.getY()+rr.getHeight());
        vec2D.add(pp);
        pp = new Point2D(rr.getX(), rr.getY()+rr.getHeight());
        vec2D.add(pp);
        
        _perimeter = rr.perimeter();
        _area = rr.area();
  }

  /**
   * triangle objesi alir ve objenin noktalarini vec2D arraylistine atar
   * @param tt
   */
  public PolygonVect(Triangle tt) {
        Point2D pp = new Point2D(tt.getX(), tt.getY());
        vec2D.add(pp);
        pp = new Point2D(tt.getxArr(0), tt.getyArr(0));
        vec2D.add(pp);
        pp = new Point2D(tt.getxArr(1), tt.getyArr(1));
        vec2D.add(pp);
        pp = new Point2D(tt.getxArr(2), tt.getyArr(2));
        vec2D.add(pp);
        
        _perimeter = tt.perimeter();
        _area = tt.area();
  }

  /**
   * circle objesi alir ve objenin noktalarini vec2D arraylistine atar
   * @param cc
   */
  public PolygonVect(Circle cc) {
    double angle;

	    for(int i = 0; i<100; ++i)
	    {
	            angle = i*(3.6)* Math.PI / 180;
	            Point2D pp = new Point2D(cc.getX() + (int)(cc.getRadius() * Math.cos(angle)), cc.getY() + (int)( cc.getRadius() * Math.sin(angle)));
	            
	            vec2D.add(pp);
	    }
	    _perimeter = cc.perimeter();
	    _area = cc.area();
  }

  /**
   * point2D tipinde obje alan constructor
   * @param v2d
   */
  public PolygonVect(Polygon.Point2D v2d) {
            vec2D.add(v2d);
  }

  /**
   * x ve y alan constructor
   * @param xx
   * @param yy
   */
  public PolygonVect(int xx, int yy) {
            Point2D pp = new Point2D(xx, yy);
            vec2D.add(pp);
  }

  /**
   * no parameter constructor
   */
  public PolygonVect() {
            vec2D.add(new Point2D(0, 0));
            vec2D.add(new Point2D(100, 50));
            vec2D.add(new Point2D(50, 100));
  }

  /**
   * vectordeki degerlere ulasir
   * @return ar(temp)
   */
  public ArrayList<Polygon.Point2D> getVec() {
           ar = null;

            for(int i = 0; i<vec2D.size(); i++)
            {
                    ar.add (vec2D.get(i)) ;
            }
            return ar;
  }

  /**
   * area function
   * @return _area
   */
  @Override
  public double area() {
        return _area;
  }

  /**
   * perimeter function
   * @return
   */
  @Override
  public double perimeter() {
        return _perimeter;
  }

  /**
   * increment function
   */
  @Override
  public void increment() {
        System.out.println("PolygonVect increment function");
  }

  /**
   * decrement function
   */
  @Override
  public void decrement() {
        System.out.println("PolygonVect decrement function");
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

            g.setColor(Color.orange);

             g.drawLine((int)vec2D.get(0).getPoint2dX(), (int)vec2D.get(0).getPoint2dY(), (int)vec2D.get(1).getPoint2dX(), (int)vec2D.get(1).getPoint2dY());
  }

}
