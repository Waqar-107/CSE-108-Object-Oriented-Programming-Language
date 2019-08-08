package staticgame;

import java.net.ServerSocket;
import java.net.Socket;
import static javafx.application.Application.launch;
import util.ConnectionUtillities;

public class Client extends Main{
    
     public void CreateConnection(){
        try{            
            ncCon=new ConnectionUtillities("localhost",12345);        
        }
        catch(Exception e){

        }
        isMyTurn=false;
       // this.launch(args);        
    }     
    
    public static void main(String[] args) {
          //Client server=new Client();
          //server.CreateConnection(args);        
        launch(args);
    }
}
