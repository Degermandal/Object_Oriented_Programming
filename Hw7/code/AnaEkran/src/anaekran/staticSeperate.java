
package anaekran;

import java.awt.Graphics;
/**
 * 
 * @author Deger
 */
public class staticSeperate {
  /**
   * - Method drawAll takes an array of Shape references and draws all shapes to an JPanel
   */
  public static void drawAll(Shape[] ss, Graphics g)
  {
    for (Shape s : ss) 
    {
        s.draw(g);
    }
  }

  /**
   * - Method convertAll takes an array of Shape references, converts all shapes to Polygons and returns a new array with the new shapes.
   */
  public static Shape[] convertAll(Shape[] arr)
  {
    Polygon[] temp = new Polygon[arr.length];
    for(int i = 0; i<arr.length; i++)
    {
       temp[i] =  (Polygon)arr[i] ;
    }
    
    return temp;
  }

  /**
   * - Method sortShapes takes an array of Shapes and increasingly sorts them with respect to their areas.
   */
  public static void sortShapes(Shape[] arr)
  {
    int i , j,min;
    int n = arr.length;
    for(i = 0; i<n-1; ++i)
    {
            min = i;
            for(j = i+1; j<n; j++)
                    if(arr[j].area() < arr[min].area())
                            min = j;

            Shape temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
    }
  }

}
