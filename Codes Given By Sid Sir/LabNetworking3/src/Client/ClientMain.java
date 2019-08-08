/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Client;

import Util.NetworkConnection;
import Util.Reader;
import Util.Writer;
import java.io.IOException;
import java.util.Scanner;

/**
 *
 * @author user
 */
public class ClientMain {
    public static void main(String[] args) throws IOException {
        
        NetworkConnection nc=new NetworkConnection("localhost",12345);
        
        System.out.println("Enter your username");
        Scanner in=new Scanner(System.in);        
        String username=in.next();        
        nc.write(username);
        
        
        
        Thread readerThread=new Thread(new Reader(nc));
        Thread writerThread=new Thread(new Writer(nc));
        
        readerThread.start();
        writerThread.start();
        
        try{
            readerThread.join();
            writerThread.join();
        }
        catch(Exception e){
            System.out.println("Thread exited");
        }
         
       
       
    }
}
