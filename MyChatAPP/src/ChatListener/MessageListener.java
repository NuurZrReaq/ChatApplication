/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ChatListener;

import java.io.IOException;
import java.net.*;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Noor
 */
public class MessageListener extends Thread {
    int port ; 
    boolean RUN = true;
    WritableGUI gui ;
    DatagramSocket clientsocket ;
    DatagramPacket recievePacket ;
    InetAddress IPAddress ;
    byte [] recievedData = new byte [1000] ;
    
    public MessageListener (WritableGUI gui , int port , String IpAddress ) {
        this.port = port ; 
        this.gui = gui ;
        try { 
            
            IPAddress = InetAddress.getByName(IpAddress);
            clientsocket = new DatagramSocket (port);
            recievePacket = new DatagramPacket(recievedData , recievedData.length);
        } catch (Exception ex) {
            Logger.getLogger(MessageListener.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        
    }


    @Override
    public void run () { 
            while ( true ) {
                try { 
                    clientsocket.receive(recievePacket);
                    String message = new String (recievePacket.getData()) ;
                    gui.write(message);
                } catch (IOException ex) {
                    Logger.getLogger(MessageListener.class.getName()).log(Level.SEVERE, null, ex);
                    
                }
            }   
    }
    
}
