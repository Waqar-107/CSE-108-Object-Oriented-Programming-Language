// average calculator of 5 numbers
package average.marks;

public class sAVG implements Runnable
{
    private Numbers n;
    private Average a;
    private int start;
    private int end;
    private double sum;
    Thread T;
    
    sAVG(Numbers n,Average a,int start,int end)
    {
        this.n=n;
        this.a=a;
        this.start=start;
        this.end=end;
        
        sum=0;
        
        T=new Thread(this,"aaa");
        T.start();
    }
    
    @Override
    public void run() 
    {  
           for(int i=start;i<=end;i++)
           {
               sum+=n.number[i];
           }
           //System.out.println("in "+ T.getName()+" "+start+" "+end+" "+sum/5);
           a.put(sum/5);
    }
    
}
