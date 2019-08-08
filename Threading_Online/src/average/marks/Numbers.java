package average.marks;

public class Numbers 
{
    public  double[]  number;
    public int capacity;
    
    Numbers(int capacity)
    {
         this.capacity=capacity;
        number=new double[capacity];
        
        for(int i=0;i<capacity;i++)
        {
            number[i]=Math.random()*1000;
        }
    }
    
    /*debug
    public  void print()
    {
        for(int i=0;i<number.length;i++)
            System.out.println(number[i]);
    }*/
}
