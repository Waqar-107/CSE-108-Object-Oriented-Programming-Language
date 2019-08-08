package producer.consumer;

public class consumer implements Runnable
{
    cubbyHole c;
    
    consumer(cubbyHole c)
    {
        this.c=c;
        new Thread(this,"consumer").start();
    }
    
    public void run() 
    {
        while(true)
            c.get();
    }
    
}
