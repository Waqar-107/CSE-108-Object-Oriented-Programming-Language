/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Server;

import Util.Information;
import Util.NetworkConnection;
import java.util.HashMap;

/**
 *
 * @author user
 */
public class CreateConnection implements Runnable{
    
    HashMap<String,Information> clientList;
    NetworkConnection nc;
    
    public CreateConnection(HashMap<String,Information> cList, NetworkConnection nConnection){
        clientList=cList;
        nc=nConnection;    
    }
        
    
    @Override
    public void run() {
        Object userObj=nc.read();
        String username=(String)userObj;
        
        
        
        System.out.println("User : "+username+" connected");
        
        clientList.put(username,new Information(username,nc));
        
        new Thread(new ReaderWriterServer(username,nc,clientList)).start();
        
    }
    
}
