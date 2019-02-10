
package anaekran;

import java.awt.Graphics;
/**
 * 
 * @author Deger
 */
public interface Shape {
  /**
   * area that returns the area of the shape
   * @return
   */
  double area() ;

  /**
   * perimeter that returns the perimeter
   * @return
   */
  double perimeter() ;

  /**
   * Functions increment and decrement for incrementing and decrementing the shape positions by 1.0.
   */
  void increment() ;

  /**
   * This interface implements the Comparable interface to compare shapes with respect to their areas.
   */
  void decrement() ;

  /**
   * area compare function
   * @param sh
   */
  int compareTo(Shape sh) ;

  /**
   * Draw takes a Graphics object as parameter and draws the shape. This method will be called from the paintComponent method of a JPanel object.
   * @param g
   */
  void draw(Graphics g) ;

}
