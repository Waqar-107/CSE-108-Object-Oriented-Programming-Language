package producer.consumer;

public class cubbyHole 
{
    private int content;
    private boolean available=false;
    
    synchronized int get()
    {
        while(!available)
        {
            try{
                wait();
            }catch(InterruptedException e){}
        }
        
        System.out.println("Got "+content);
        available=false;
        notify();
        
        return content;
    }
    
    synchronized void put(int content)
    {
        while(available)
        {
           try{
               wait();
           }catch(InterruptedException e){}
        }
        
        this.content=content;
        available=true;
        
        System.out.println("Put "+content);
        notify();
    }
}
