/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package messenger;

import java.util.HashMap;
import util.ConnectionUtillities;

/**
 *
 * @author uesr
 */
public class ServerReaderWriter implements Runnable{

    public HashMap<String,Information> clientList;
    public ConnectionUtillities connection;
    public String user;
    
    public ServerReaderWriter(String username,ConnectionUtillities con, HashMap<String,Information> list){
        connection=con;
        clientList=list;
        user=username;
    }
    
    @Override
    public void run() {
        while(true){
            
            Object o=connection.read();
            String data=o.toString();
            
            String msg[]=data.split(":",2);
            
            String username=msg[0];
            String msgInfo=msg[1];
            
            if(clientList.containsKey(username)){
                Information info=clientList.get(username);
                info.connection.write(user+" - "+msgInfo);
            }
            else{
               connection.write(username+" not found ");
            }
            
        }
    }
    
    
}
