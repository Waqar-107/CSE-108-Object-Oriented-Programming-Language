package producer.consumer.problem;

public class Consumer extends Thread
{
    private CubbyHole c;
    private int number;
    
    public Consumer(CubbyHole c,int number)
    {
        this.c=c;
        this.number=number;
    }
    
    public void run()
    {
        int value=0;
        for(int i=0;i<10;i++)
        {
            value=c.get();
            System.out.println("Consumer #"+this.number+" got: "+value);
        }
    }
}
