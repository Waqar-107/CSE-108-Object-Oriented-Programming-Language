package average.marks;

public class AverageMarks
{
    public static void main(String[] args) 
    {
        Numbers x=new Numbers(20);      //total 20 numbers, divided in 4 threads and each of the 4 will be average of 5 
        Average av=new Average(4);
        int s=0,e=s+4;
        double average=0;
        double de=0;
        
        //normally calculated avg
        for(int i=0;i<20;i++)
        {
            de+=x.number[i];
            System.out.println((i+1)+" "+x.number[i]);
        }
        System.out.println("Normal  "+de/20);
        
         sAVG[] t=new sAVG[4]; 
        
        for(int i=0;i<4;i++)
        {
            t[i]=new sAVG(x, av, s, e);
            s+=5;
            e=s+4;
        }
        
        for(int i=0;i<4;i++)
            System.out.println(av.avg[i]);
        
        for(int i=0;i<4;i++)
        {
            try {
                t[i].T.join();
            } catch (InterruptedException ex) {
                System.out.println("interruption");
            }
        }
        
        for(int i=0;i<4;i++)
        {
            average+=av.avg[i];
        }
        
        average=average/4;
        
        System.out.println("Average"+ average);
        
    }
    
}
