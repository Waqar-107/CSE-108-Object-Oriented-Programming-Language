/*Util contains the necessary things to connect, a socket to make way, oos to write something
 and ois to read what someone has sent to the socket*/

package client;

import java.util.*;
import java.io.*;
import java.net.*;

public class Util {

    Socket sock;
    ObjectOutputStream oos;
    ObjectInputStream ois;

    Util(String ip, int portNo) 
    {
        try {
            sock = new Socket(ip, portNo);
            oos = new ObjectOutputStream(sock.getOutputStream());
            ois = new ObjectInputStream(sock.getInputStream());
     
        } catch (IOException ex) {}
        
    }

    Util(Socket s) 
    {
        try{
            sock = s;
            oos = new ObjectOutputStream (sock.getOutputStream ());
            ois = new ObjectInputStream (sock.getInputStream ());
        }catch(IOException e){}

    }
    
    //this will read the stream and return it  
    public Object read()
    {
        Object obj=null;
        try{
            obj=ois.readObject();
    }catch(IOException | ClassNotFoundException ex){}
        
        return obj;
    }
    
    public void write(Object obj)
    {
        try{
            oos.writeObject(obj);
        }catch(IOException e){}
    }
    

}
