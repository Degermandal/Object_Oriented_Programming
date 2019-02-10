
package anaekran;

import java.awt.Graphics;
import javax.swing.JPanel;
/**
 * 
 * @author Deger
 */
public class Rectangle extends JPanel implements Shape {
  /**
   * 
   * 
   */
  private static final long serialVersionUID =  1L;

  private int width;

  private int height;

  private int x;

  private int y;

  /**
   * CONSTRUCTORS
   * 
   * butun degiskenleri alan constructor
   * @param width
   * @param height
   * @param x
   * @param y
   */
  public Rectangle(int width, int height, int x, int y) {
                this.width = width;
                this.height = height;
                this.x = x;
                this.y = y;
  }

  /**
   * width ve height alan constructor
   * @param width
   * @param height
   */
  public Rectangle(int width, int height) {
                this(width, height, 0, 0);
  }

  /**
   * no parameter constructor
   */
  public Rectangle() {
                this(80, 40, 0, 0);
  }

  /**
   * GETTER AND SETTER FUNCTIONS
   * 
   * width get function
   * @return width
   */
  @Override
  public int getWidth() {
                return width;
  }

  /**
   * height get function
   * @return height
   */
  @Override
  public int getHeight() {
                return height;
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
   * set width function
   * @param w (int)
   * @throws java.lang.Exception
   */
  public void setWidth(int w) throws Exception {
                if(w > 0.0) 
                        width = w;
                else
                        throw new Exception("Yanlis width parameter\n");
  }

  /**
   * set height function
   * @param h
   * @throws java.lang.Exception
   */
  public void setHeight(int h) throws Exception {
                if(h > 0.0) 
                        height = h;
                else
                        throw new Exception("Yanlis height parameter\n");
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
   * rectangle alan bulan fonksiyon
   * @return rectangle area
   */
  @Override
  public double area() {
                       return height*width;
  }

  /**
   * rectangle cevre bulan fonksiyon
   * @return rectangle cevre
   */
  @Override
  public double perimeter() {
                       return 2*height + 2*width;
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
   * width, height ve x, y degerlerine gore rectangle ciziyor 
   * @param g
   */
  public void draw(Graphics g) {
            /*
            System.out.println("welcome3");
            setBackground(Color.white);
            super.paintComponent(g);
            
            if(smallOrBig == 'b')
                g.setColor(Color.green);
            else if(smallOrBig == 's')
                g.setColor(Color.red);
            else// 's' degilken 
                System.out.println("smallOrBig seciminde hata");
            */
            g.fillRect(x, y, width, height);       
                        
  }

}
