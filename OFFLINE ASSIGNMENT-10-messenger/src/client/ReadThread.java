package client;

import javafx.scene.control.TextArea;

public class ReadThread implements  Runnable 
{
    Thread readMessage;
    TextArea showMessage;
    Util utl;
    
    ReadThread(Util utl,TextArea msg)
    {
        readMessage=new Thread(this);
        readMessage.start();
        showMessage=msg;
        this.utl=utl;
    }

    @Override
    public void run()
    {
        while(true)
        {
            String ss= (String) utl.read();   //object type casted as string object
            showMessage.appendText(ss+"\n");
        }
    }
    
}
