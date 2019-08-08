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
public class CreateClientConnection implements Runnable{
    public HashMap<String,Information> clientList;
    public ConnectionUtillities connection;

    public CreateClientConnection(HashMap<String,Information> list, ConnectionUtillities con){
        clientList=list;
        connection=con;
    }
    
    @Override
    public void run() {
        Object o=connection.read();
        String username=o.toString();        
        clientList.put(username, new Information(connection, username));
        new Thread(new ServerReaderWriter(username,connection, clientList)).start();
        
    }
    
    
    
}
