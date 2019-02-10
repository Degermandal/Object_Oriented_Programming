
package anaekran;

import java.awt.Graphics;
import javax.swing.JPanel;
/**
 * 
 * @author Deger
 */
public class Circle extends JPanel implements Shape {
  /**
   * 
   * 
   */
  private static final long serialVersionUID =  1L;

  private int radius;

  private int x;

  private int y;

  /**
   * CONSTRUCTORS
   * 
   * butun degiskenleri alan constructor
   * @param radius
   * @param x
   * @param y
   */
  public Circle(int radius, int x, int y) {
                this.radius = radius;
                this.x = x;
                this.y = y;
  }

  /**
   * yaricap alan constructor
   * @param radius
   */
  public Circle(int radius) {
               // this.radius = radius;
                this(radius, 0, 0);
  }

  /**
   * x ve y degerleri alan constructor
   * @param x
   * @param y
   */
  public Circle(int x, int y) {
                this.x = x;
                this.y = y;
  }

  /**
   * no parameter constructor
   */
  public Circle() {
                this(80, 0, 0);
  }

  /**
   * GETTER AND SETTER FUNCTIONS
   * 
   * radius get function
   * @return radius
   */
  public int getRadius() {
                return radius;
  }

  /**
   * x get function
   * @return x
   */
  @Override
  public int getX() {
                return x;
  }

  /**
   * y get function
   * @return y
   */
  @Override
  public int getY() {
                return y;
  }

  /**
   * set radius function
   * @param r (int)
   * @throws java.lang.Exception
   */
  public void setRadius(int r) throws Exception {
                if(r <= 0)
                    throw new Exception("Yanlis radius input\n");
                else
                        this.radius = r;
  }

  /**
   * set x function
   * @param x
   */
  public void setX(int x) {
                this.x = x;
  }

  /**
   * set y function
   * @param y
   */
  public void setY(int y) {
                this.y = y;
  }

  /**
   * NECESSARY FUNCTIONS
   * 
   * circle alan bulan fonksiyon
   * @return circle area
   */
  @Override
  public double area() {
                       return Math.PI*radius*radius;
  }

  /**
   * circle cevre bulan fonksiyon
   * @return circle cevre
   */
  @Override
  public double perimeter() {
                       return 2*Math.PI*radius;
  }

  /**
   * x ve y degerlerini +1 arttiriyor
   */
  @Override
  public void increment() {
                       this.x = x + 1;
                       this.y = y + 1;

  }

  /**
   * x ve y degerlerini -1 azaltiyor
   */
  @Override
  public void decrement() {
                       this.x = x - 1;
                       this.y = y - 1;
  }

  /**
   * shape objesine gore alan karsilastirma yapiyor
   * @param sh
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
   * radius ve x, y degerlerine gore circle ciziyor 
   * @param g
   */
  @Override
  public void draw(Graphics g) {
        /*
            setBackground(Color.white);
            super.paintComponent(g);

             if(smallOrBig == 'b')
                g.setColor(Color.green);
            else if(smallOrBig == 's')
                g.setColor(Color.red);
            else// 's' degilken 
                System.out.println("smallOrBig seciminde hata");
          */  
            g.fillOval(x, y, radius, radius);

  }

}
