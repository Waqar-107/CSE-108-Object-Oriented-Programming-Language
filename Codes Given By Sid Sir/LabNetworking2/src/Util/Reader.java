/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Util;

/**
 *
 * @author user
 */
public class Reader implements Runnable{
    public NetworkConnection netConnection;
    
    public Reader(NetworkConnection nc){
        netConnection=nc;
    }
    
    @Override
    public void run() {
        while(true){
            
            Object obj=netConnection.read();
            Data dataObj=(Data)obj;
            System.out.println("Received : "+dataObj.message);
            
        }
    }
    
}
