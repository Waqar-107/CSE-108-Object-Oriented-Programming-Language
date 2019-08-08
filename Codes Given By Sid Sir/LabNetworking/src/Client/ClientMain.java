/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Client;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author user
 */
public class ClientMain {
    public static void main(String[] args) throws IOException {
       
        
        Socket socket=new Socket("127.0.0.1",22222);
        
        ObjectOutputStream oos=new ObjectOutputStream(socket.getOutputStream());
        ObjectInputStream ois=new ObjectInputStream(socket.getInputStream());
        
        
        Scanner in=new Scanner(System.in);
        String message=in.nextLine();
        
        oos.writeObject(message);
        
        try {
            Object captialMessage=ois.readObject();
            System.out.println((String)captialMessage);    
            
            
        } catch (Exception e) {
            System.out.println("Fails in client");
        }
        
        
        
        
        
    }
}
