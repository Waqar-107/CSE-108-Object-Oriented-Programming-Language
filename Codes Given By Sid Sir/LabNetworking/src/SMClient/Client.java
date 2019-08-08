/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package SMClient;

import java.io.IOException;
import java.net.Socket;
import java.util.logging.Level;
import java.util.logging.Logger;
import util.Reader;
import util.Writer;

/**
 *
 * @author user
 */
public class Client {
    public static void main(String[] args) throws IOException {
        Socket socket=new Socket("localhost",12345);
        
        System.out.println("Server Connected->>>>");
        
        Thread readerThread=new Thread(new Reader(socket));
        Thread writerThread=new Thread(new Writer(socket));
        
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
