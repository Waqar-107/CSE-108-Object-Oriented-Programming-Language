/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package staticgame;

import javafx.event.EventHandler;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.input.MouseEvent;
import javafx.scene.shape.Circle;
import util.ConnectionUtillities;
import util.Data;

/**
 *
 * @author user
 */
public class Player {
    public Group design;
    Label display;
    Label playerName;    
    Circle circle;
    ConnectionUtillities ncCon;
    
    Player(){
        design=new Group();        
    }
    
   
}
