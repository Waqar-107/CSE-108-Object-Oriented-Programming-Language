package average.marks;

public class Average 
{
    public double[] avg;
    public int count;
    public int size;
    
    Average(int size)
    {
        this.size=size;
        count=0;
        
        avg=new double[size];
    }
    
    //this is a shared method which will store averages in the main average array, average of which shall be calculated later in the main()
    synchronized void put(double value)
    {
       
        
        avg[count]=value;
        count++;
        
        notifyAll();
    }
}
