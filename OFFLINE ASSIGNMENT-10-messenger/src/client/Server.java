package client;

import java.io.*;
import java.net.*;
import java.util.*;

public class Server 
{
    static HashMap<String,Util> info=new HashMap<>();
    //static ArrayList<String> names=new ArrayList<>();
    
    public static void main(String[] args)
    {
       
         try{ 
                ServerSocket servsocket=new ServerSocket(3640);
                while(true)
                {
                        Socket socket = servsocket.accept ();
                        Util utl = new Util (socket);                        
                        new ClientThreadForServer(info, utl);
                }
         }catch(IOException e){System.out.println("not connected successfully");}
    }
}
