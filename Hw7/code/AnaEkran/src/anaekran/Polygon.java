
package anaekran;

import java.awt.Graphics;
import javax.swing.JPanel;
/**
 * 
 * @author Deger
 */
public abstract class Polygon extends JPanel implements Shape {
  /**
   * 
   * 
   */
  private static final long serialVersionUID =  1L;

  public class Point2D {
    private int x;

    private int y;

    /**
     * CONSTRUCTOR
     * 
     * no parameter constructor
     */
    public Point2D() {
                        this.x = 0;
                        this.y = 0;
    }

    /**
     * x ve y alan constructor
     * @param xx
     * @param yy
     */
    public Point2D(int xx, int yy) {
                        this.x = xx;
                        this.y = yy;
    }

    /**
     * GETTER FUNCTION
     * 
     * x return eden get fonksiyonu
     * @return
     */
    public double getPoint2dX() {
 
                       return x;
    }

    /**
     * y return eden get fonksiyonu
     * @return
     */
    public double getPoint2dY() {
 
                        return y; 
    }

    /**
     * SETTER FUNCTION
     */
    void setPoint2dX(int xx) {
                       this. x = xx;
    }

    void setPoint2dY(int yy) {
                       this. y = yy; 
    }

  }

  /**
   * no parameter constructor
   */
  public Polygon() {
                //......
  }

  /**
   * area function
   * @return
   */
  @Override
  public abstract double area() ;

  /**
   * perimeter function
   * @return
   */
  @Override
  public abstract double perimeter() ;

  /**
   * increment function
   */
  @Override
  public abstract void increment() ;

  /**
   * decrement function
   */
  @Override
  public abstract void decrement() ;

  /**
   * area compare function
   * @param sh
   */
  @Override
  public abstract int compareTo(Shape sh) ;

  /**
   * shape draw function
   * @param g
   */
  @Override
  public abstract void draw(Graphics g) ;

}
