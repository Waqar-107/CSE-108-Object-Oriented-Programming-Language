package client;

import java.util.Scanner;

public class WriteThread implements Runnable
{
    Thread t;
    Util utl;
    
    WriteThread(Util utl)
    {
        this.t=new Thread(this);
        t.start();
        this.utl=utl;
    }

    @Override
    public void run()
    {
       while(true)
       {
           String send;
           Scanner in = new Scanner(System.in);
           send = in.nextLine ();
           utl.write(send);
       }
    }
}
