
package anaekran;

import java.awt.Graphics;
import javax.swing.JPanel;
import static java.lang.Math.sqrt;
/**
 * 
 * @author Deger
 */
public class Triangle extends JPanel implements Shape {
  /**
   * 
   * 
   */
  private static final long serialVersionUID =  1L;

  private int edge;

  private final int[] xArr;

  private final int[] yArr;

  /**
   * CONSTRUCTORS
   * 
   * no parameter constructor
   */
  Triangle() {
 
                        this.edge = 300;
                        xArr = new int[] {edge/2, 0, edge};
                        yArr = new int[] {0, (int)((edge/2)*sqrt(3)), (int) ((edge/2)*Math.sqrt(3.0))};
  }

  /**
   * butun degiskenleri alan constructor x ve y degerlerini bir arrayde topladim
   * @param e
   * @param x1
   * @param y1
   * @param x2
   * @param y2
   * @param x3
   * @param y3
   */
  Triangle(int e, int x1, int y1, int x2, int y2, int x3, int y3) {
 
                    this.edge = e;
                    xArr = new int[] {x1, x2, x3};
                    yArr = new int[] {y1, y2, y3};
  }

  /**
   * edge alan constructor
   * @param e
   */
  Triangle(int e) {
 
                    this.edge = e;
                    xArr = new int[] {edge/2, 0, edge};
                    yArr = new int[] {0, (int)((edge/2)*sqrt(3)), (int)( (edge/2)*sqrt(3))};
  }

  /**
   * SETTER AND GETTER FUNCTIONS
   * 
   * x ve y degerlerini alan constructor x ve y degerlerini bir arrayde topladim
   * @param x1
   * @param y1
   * @param x2
   * @param y2
   * @param x3
   * @param y3
   */
  Triangle(int x1, int y1, int x2, int y2, int x3, int y3) {
 
                    this.edge = 300;
                    xArr = new int[] {x1, x2, x3};
                    yArr = new int[] {y1, y2, y3};
  }

  /**
   * xArr arrayinden indexe gore eleman return ediyor
   * @param index
   * @return xArr[index]
   */
  public int getxArr(int index) {
                return xArr[index];
  }

  /**
   * yArr arrayinden indexe gore eleman return ediyor
   * @param index
   * @return yArr[index]
   */
  public int getyArr(int index) {
                return yArr[index];
  }

  /**
   * edge get function
   * @return edge
   */
  public int getEdge() {
                return edge;
  }

  /**
   * set edge function
   * @param e
   * @throws Exception
   */
  public void setEdge(int e) throws Exception {
                if(e > 0.0) 
                        edge = e;
                else
                        throw new Exception("Yanlis edge parameter\n");
  }

  /**
   * NECESSARY FUNCTIONS
   * 
   * triangle alan bulan fonksiyon
   * @return triangle area
   */
  @Override
  public double area() {
                       return (edge*edge*Math.sqrt(3)) / 4;
  }

  /**
   * triangle cevre bulan fonksiyon
   * @return triangle cevre
   */
  @Override
  public double perimeter() {
                       return 3*edge;
  }

  /**
   * x ve y degerlerini +1 arttiriyor
   */
  @Override
  public void increment() {
                    for(int i = 0; i < xArr.length; i++)
                    {
                            this.xArr[i] = xArr[i] + 1;
                            this.yArr[i] = yArr[i] + 1;
                    }       
           
  }

  /**
   * x ve y degerlerini -1 azaltiyor
   */
  @Override
  public void decrement() {
                    for(int i = 0; i < xArr.length; i++)
                    {
                            this.xArr[i] = xArr[i] - 1;
                            this.yArr[i] = yArr[i] - 1;
                    }     
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
   * xlerin tutuldugu array, ylerin tutuldugu array ve edge gore triangle ciziyor
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
            else 
                System.out.println("smallOrBig seciminde hata");
            */
            g.fillPolygon(xArr, yArr, edge);       
            // System.out.println("gshjd   " + xArr[0] + "    y   "+ yArr[0]);
                        
  }

}
