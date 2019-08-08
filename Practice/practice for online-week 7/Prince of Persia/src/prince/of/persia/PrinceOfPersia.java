/*************Prince of Persia**************
 ********@author: Waqar Hassan khan*********
 ***************OFFLINE-5****************/


package prince.of.persia;

import java.util.Scanner;
public class PrinceOfPersia
{
    public static class pathFinder
    {
        private int row;
        private int column;
        private int[][] visited;
        private int[][] mat;
        
        pathFinder(int r,int c,int[][] mat)
        {
            this.row=r;
            this.column=c;
            this.mat=mat;
            
            visited=new int[r][c];
            
            for(int i=0;i<r;i++)
            {
                for(int j=0;j<c;j++)
                {
                    visited[i][j]=0;
                }
            }
        }
        
        public void dfs(int i,int j)
        {
            if(i>=0 && i<row && j>=0 && j<column && visited[i][j]==0 && mat[i][j]==1)
            {
                visited[i][j]=1;
                
                dfs(i+1,j);     //down
                dfs(i-1,j);     //up
                dfs(i,j+1);     //right
                dfs(i,j-1);     //left
            }
 
        }
        
        public boolean checker(int p1,int p2)
        {
            
            if(visited[p1][p2]==1)
                return true;
            else
                return false;
        }
        
        
        public void print()
        {
            for(int i=0;i<row;i++)
            {
                for(int j=0;j<column;j++)
                {
                    System.out.print(visited[i][j]+"  ");
                }
                System.out.println();
            }
        }
        
    }
    
    public static void main(String[] args) 
    {
        int r,c;
        int mat[][];
        
        Scanner in=new Scanner(System.in);
        
        System.out.println("enter the number of rows and columns:");
        r=in.nextInt();
        c=in.nextInt();
        
        mat=new int[r][c];
        System.out.println("enter the path:");
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                mat[i][j]=in.nextInt();
            }
        }
        
        pathFinder x=new pathFinder(r,c,mat);
        
        System.out.println("enter the starting index");
        int si=in.nextInt();
        int sj=in.nextInt();
           
        System.out.println("enter where the princess is:");
        int pi=in.nextInt();
        int pj=in.nextInt();
        
        x.dfs(si, sj);
        
        if(x.checker(pi, pj)==true)
            System.out.println("YES, the prince can reach the princess!! :)");
        else
            System.out.println("No, the prince can't reach to the princess :(");
        
        //x.print();
    }
    
}
