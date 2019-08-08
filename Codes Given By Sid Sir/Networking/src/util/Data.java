/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package util;

import java.io.Serializable;

/**
 *
 * @author uesr
 */
public class Data  implements Serializable {
    
     public String info;
     public int count;
     
     public double x,y;
     
     
     
     public Data(int cnt){
         count=cnt;
     }
     public Data(double x1,double y1 ){
         x=x1;
         y=y1;
     }
    
}
