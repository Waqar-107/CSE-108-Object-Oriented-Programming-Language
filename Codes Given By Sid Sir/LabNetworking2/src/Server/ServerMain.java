/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Server;

import Util.NetworkConnection;
import Util.Reader;
import Util.Writer;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

/**
 *
 * @author user
 */
public class ServerMain {
    public static void main(String[] args) throws IOException {
        
        ServerSocket serverSocket=new ServerSocket(12345);        
        Socket socket=serverSocket.accept();        
        NetworkConnection nc=new NetworkConnection(socket);
        
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
