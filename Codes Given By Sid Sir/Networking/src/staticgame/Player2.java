package staticgame;

import javafx.scene.control.Label;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import util.ConnectionUtillities;


public class Player2 extends Player{
    
    public Player2(ConnectionUtillities conn){
        super();
        circle=new Circle(30, 30, 30,Color.BLUE);
        ncCon=conn;        
        display=new Label("0");
        playerName=new Label("Player 2");
        //design.getChildren().add(playerName);
        design.getChildren().add(circle);
    }
    
    public int count;
    public double x;
    public double y;
    
    public void update(){
        //display.setText(Integer.toString(count));
        circle.setCenterX(x);
        circle.setCenterY(y);
    }
    
}
