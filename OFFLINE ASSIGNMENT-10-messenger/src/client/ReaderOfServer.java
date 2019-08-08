package client;

import java.util.HashMap;
import java.util.StringTokenizer;

public class ReaderOfServer implements Runnable
{
    Thread t;
    String name;
    static HashMap<String,Util> mp;
    Util utl;

    public ReaderOfServer(Util utl,HashMap<String,Util> mp,String name) 
    {
        t=new Thread(this);
        t.start();
        this.name=name;
        this.utl=utl;
        this.mp=mp;
    }
    
    @Override
    public void run()
    {
        while(true)
        {
            int i= 0;
            String sms = (String) utl.read ();
            String[] split = new String[2];
            
            StringTokenizer ss = new StringTokenizer (sms, ":");
            
            while (ss.hasMoreTokens ())
            {
                split[i++] = ss.nextToken ();
            }
                  
            Util reciver_utl = mp.get (split[0]);
            reciver_utl.write ("From " + name + ": " + split[1]);
            
        }
    }
    
}
