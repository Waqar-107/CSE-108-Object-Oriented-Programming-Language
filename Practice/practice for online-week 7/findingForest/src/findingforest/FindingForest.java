/*************Finding The Island**************
 ********@author: Waqar Hassan khan*********
 ***************OFFLINE-5****************/


package findingforest;

import java.util.Scanner;

public class FindingForest 
{
    public static class finder
     {
            private int row;
            private int column;
            private int[][] visited;
            private int[][] mat;
            private int count;
            
            finder(int r,int c,int[][] mat)
            {
                this.mat=mat;
                this.row=r;
                this.column=c;
                
                visited=new int[r][c];
                
                for(int i=0;i<r;i++)
                {
                    for(int j=0;j<c;j++)
                    {
                        visited[i][j]=0;
                    }
                }
                
                count=0;
                
            }
            
            void dfs(int i,int j,int v)
            {
                if(i>=0 && j>=0 && i<row && j<column && visited[i][j]==0 && mat[i][j]==v)
                {
                    visited[i][j]=1;
                    
                    dfs(i+1,j,v);         //down
                    dfs(i-1,j,v);         //up
                    dfs(i,j+1,v);         //right
                    dfs(i,j-1,v);         //left
                    
                    dfs(i+1,j+1,v);      //down-right diagon
                    dfs(i+1,j-1,v);       //down-left diagon
                    dfs(i-1,j+1,v);       //up-right diagon
                    dfs(i-1,j-1,v);       //up-left diagon
                }
            }
            
            public void driver()
            {
                for(int i=0;i<row;i++)
                {
                    for(int j=0;j<column;j++)
                    {
                        if(visited[i][j]==0 && mat[i][j]==1)
                        {
                            count++;
                            dfs(i,j,mat[i][j]);
                        }
                    }
                }
            }
            
          public int passCount()
          {
              return count;
          }
          
          /*public void pf()        //debug
          {
              for(int i=0;i<row;i++)
              {
                  for(int j=0;j<column;j++)
                  {
                      System.out.print(visited[i][j]+" ");
                  }
                  System.out.println();
              }
          }*/
     }

    
    public static void main(String[] args) 
    {
        int r,c,mat[][];
        Scanner in=new Scanner(System.in);
        
        r=in.nextInt();
        c=in.nextInt();
        
        mat=new int[r][c];
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                mat[i][j]=in.nextInt();
            }
        }
        
        finder x=new finder(r,c,mat);   //declare an object of the class finder to find islands
        x.driver();
        
        System.out.println("there are total " + x.passCount() + "islands");
        
        //x.pf();  //debug
    }
    
}
/*
test case
4 4
1 1 0 1
1 0 1 1
0 0 0 0
0 0 1 1

*/