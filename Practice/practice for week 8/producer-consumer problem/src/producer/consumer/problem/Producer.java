package producer.consumer.problem;

public class Producer extends Thread
{
    private CubbyHole c;
    private int number;
    
    public Producer(CubbyHole c,int number)
    {
        this.c=c;
        this.number=number;
    }
    
    public void run()
    {
        for(int i=0;i<10;i++)
        {
            c.put(i);
            System.out.println("producer #"+this.number+"put "+i);
            
            try{
                sleep((int)(Math.random()*100));
            }catch(InterruptedException e){};
        }
    }
}
