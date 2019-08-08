package producer.consumer;

public class producer implements Runnable
{
    cubbyHole c;
    
    producer(cubbyHole c)
    {
        this.c=c;
        new Thread(this,"producer").start();
    }

    public void run()
    {
        int i=0;
        while(true)
            c.put(i++);
      
    }
}
