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
public class MessageSender extends Thread {
    DatagramSocket socket ; 
    String message ; 
    WritableGUI gui ; 
    InetAddress IPAddress ;
    int port ; 
    public MessageSender(WritableGUI gui , int port , String IPaddress , String Message) {
        try { 
            this.gui = gui ;
            socket = new DatagramSocket();
            this.port = port; 
            this.IPAddress = InetAddress.getByName(IPaddress);
            this.message = Message;
        } catch (Exception ex) {
            Logger.getLogger(MessageSender.class.getName()).log(Level.SEVERE, null, ex);
        }
        
    }

    @Override
    public void run() {
        try {
            DatagramPacket sendPacket = new DatagramPacket(message.getBytes(),message.length(),IPAddress,port) ;
            socket.send(sendPacket);
            gui.write(message);
        } catch (IOException ex) {
            Logger.getLogger(MessageSender.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
}
