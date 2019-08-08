/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package staticgame;

import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.input.MouseEvent;
import javafx.scene.paint.Color;
import javafx.scene.paint.Paint;
import javafx.scene.shape.Circle;
import util.ConnectionUtillities;
import util.Data;

/**
 *
 * @author user
 */
public class Player1 extends Player{
    boolean isMyTurn;
    
    public Player1(boolean turn,ConnectionUtillities conn){
        super();
        circle=new Circle(30, 30, 30,Color.AQUA);
        ncCon=conn;
        isMyTurn=turn;
        display=new Label("0");
        playerName=new Label("Player 1");
        //design.getChildren().add(playerName);
        design.getChildren().add(circle);
    }
    
     public void setHandler(Scene scene){
        scene.addEventHandler(MouseEvent.MOUSE_DRAGGED,new EventHandler<MouseEvent>(){

            @Override
            public void handle(MouseEvent t) {
                
                //System.out.println(isMyTurn);
                
                /*if(isMyTurn)
                {
                    String text=display.getText();
                    int newCount=Integer.parseInt(text)+1;
                    display.setText(Integer.toString(newCount));                
                    
                    isMyTurn=false;                    
                    Data data=new Data(newCount);
                    ncCon.write(data);                    
                }
                */
                
               // System.out.println("Working");
                
                double x=t.getSceneX();
                double y=t.getSceneY();
                System.out.println(circle.getCenterX()+"\t"+circle.getCenterY());
                
                System.out.println(x+"\t"+y);
                                
                circle.setCenterX(x);
                circle.setCenterY(y);                
                
                Data data=new Data(x,y);
                ncCon.write(data);
                
                
            }
        
        
        });
    }
       
}
