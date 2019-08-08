package producer.consumer;

public class PRODUCERCONSUMER 
{
    public static void main(String[] args) 
    {
        cubbyHole c=new cubbyHole();
        producer p=new producer(c);
        consumer q=new consumer(c);
        
        System.out.println("press ctrl-c to stop");
    }
    
}
