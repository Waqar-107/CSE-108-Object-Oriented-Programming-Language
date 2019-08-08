/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package SMServer;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import util.Reader;
import util.Writer;

/**
 *
 * @author user
 */
public class Server {
    public static void main(String[] args) throws IOException {
        
        ServerSocket serveSocket=new ServerSocket(12345);
        Socket socket=serveSocket.accept();
        
        System.out.println("Client Connected->>>>");
        
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
