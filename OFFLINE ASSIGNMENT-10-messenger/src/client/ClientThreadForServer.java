package client;

import java.util.ArrayList;
import java.util.HashMap;

public class ClientThreadForServer implements Runnable
{
    Thread t;
    Util utl;
    HashMap<String,Util> mp;
    String clientName;
  
    public ClientThreadForServer(HashMap<String,Util> mp,Util utl)
    {
        t=new Thread(this);
        this.utl = utl;
        this.mp=mp;
        t.start();
    }
    
    @Override
    public void run()
    {
        clientName=(String) utl.read();
        mp.put(clientName, utl);
        System.out.println ("[" + clientName + "] is connected");
        new ReaderOfServer(utl,mp,clientName);
    }
}
