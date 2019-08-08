package producer.consumer.problem;

public class ProducerConsumerProblem 
{
    public static void main(String[] args) 
    {
        CubbyHole c=new CubbyHole();
        Producer p=new Producer(c, 1);
        Consumer cn=new Consumer(c,1);
        
        p.start();
        cn.start();
    }
    
}
