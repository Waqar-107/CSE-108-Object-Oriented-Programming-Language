/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package util;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author user
 */
public class Reader implements Runnable{
    private Socket socket;    
    ObjectOutputStream oos;
    ObjectInputStream ois;
            
    public Reader(Socket sock){
        socket=sock;
        
        try {            
            oos=new ObjectOutputStream(sock.getOutputStream());        
            ois=new ObjectInputStream(sock.getInputStream());
        } catch (IOException ex) {
            System.out.println("Stream creation failed");
        }
    }
    
    @Override
    public void run() {
        
        while(true){
            try {
                Object obj=ois.readObject();
                Data objData=(Data)obj;                
                System.out.println("Received : "+objData.message);
                
            } catch (Exception ex) {
                System.out.println("Failed to read");
                break;
            }
            
            
        
        }
        
    }
    
}
