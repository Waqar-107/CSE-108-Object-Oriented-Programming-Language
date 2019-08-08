package staticgame;

import util.ConnectionUtillities;
import util.Data;

public class ReadThread implements Runnable
{    
    public ConnectionUtillities ncCon;
    public Player1 player1;
    public Player2 player2;

    public ReadThread(Player1 p1,Player2 p2, ConnectionUtillities conn)
    {
        player1=p1;
        player2=p2;
        ncCon=conn;
    }
    
    
    @Override
    public void run()
    {
         while(true)
         {
             
             final Data obj=(Data)ncCon.read();
             player1.isMyTurn=true;                          
             //player2.count=obj.count;
             
             player2.x=obj.x;
             player2.y=obj.y;
             
             System.out.println("Received"+obj.x+obj.y);
              
         }   
    }
    
}
