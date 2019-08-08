/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Server;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author user
 */
public class ServerMain {

    public static void main(String[] args) throws IOException {

        ServerSocket servsocket = new ServerSocket(22222);

        while (true) {

            Socket socket = servsocket.accept();

            ObjectOutputStream oos = new ObjectOutputStream(socket.getOutputStream());
            ObjectInputStream ois = new ObjectInputStream(socket.getInputStream());

            try {
                Object message = ois.readObject();
                System.out.println("From Client : " + (String) message);

                String cMessage = (String) message;
                cMessage = cMessage.toUpperCase();
                
                oos.writeObject(cMessage);

            } catch (Exception e) {
                System.out.println("Failed to read");
            }
        }
    }

}
