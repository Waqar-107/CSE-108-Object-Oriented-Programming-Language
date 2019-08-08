package client;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.scene.text.Text;
import javafx.stage.Stage;


public class Client extends Application 
{
    Scene scene;
    String ipAddress;
    HashMap<String,Util> mp;
    Util clientConnection;
    
    @Override
    public void start(Stage primaryStage) 
    {   
        Pane root = new Pane();
        Image opening_screen=new Image("/opening screen.png",500,550,true,true,true);
        ImageView opscreen=new ImageView(opening_screen);
        root.getChildren().add(opscreen);
        
        TextField name=new TextField();
        name.setLayoutX(200);
        name.setLayoutY(600);
        name.setMinSize(100,25);
        root.getChildren().add(name);
        
        TextField ip=new TextField();
        ip.setLayoutX(200);
        ip.setLayoutY(630);
        ip.setMinSize(100,25);
        root.getChildren().add(ip);
        
        Text name_nao=new Text("Enter your name");
        name_nao.setFont(new Font("calibri",14));
        name_nao.setLayoutX(100);
        name_nao.setLayoutY(617);
        root.getChildren().add(name_nao);
        
        Text ip_nao=new Text("Enter your IP adress");
        ip_nao.setFont(new Font("calibri",14));
        ip_nao.setLayoutX(80);
        ip_nao.setLayoutY(645);
        root.getChildren().add(ip_nao);
        
        Button connectWithServer=new Button("Connect");
        connectWithServer.setLayoutX(360);
        connectWithServer.setLayoutY(615);
        root.getChildren().add(connectWithServer);
        scene = new Scene(root, 500, 650);
        
        connectWithServer.setOnAction(e->
        {
            
            clientConnection=new Util("127.0.0.1",3640);
            String clientName=name.getText();
            clientConnection.write(clientName);                //sending  client name to server
            OriginalChatScreen(primaryStage,clientName);
        });
          
       
        primaryStage.setScene(scene);
        primaryStage.setResizable(false);
        primaryStage.show();
    }

   
    public static void main(String[] args) 
    {
        launch(args);
    }
    
    public void OriginalChatScreen(Stage s,String nam)
    {   
        Pane chat=new Pane();
        Image top=new Image("/top.png",500,30,true,true,true);
        ImageView topp=new ImageView(top);
        
        Image cbg=new Image("/bg2.png",1500,1650,true,true,true);
        ImageView chatBackground=new ImageView(cbg);
        chat.getChildren().add(chatBackground);
        
        Text titleName=new Text(nam);
        titleName.setFont(Font.font("comic sans", 14));
        titleName.setLayoutX(5);
        titleName.setLayoutY(15);
        titleName.setFill(Color.ANTIQUEWHITE);
        chat.getChildren().add(topp);
        chat.getChildren().add(titleName);
        
        Text in=new Text("Inbox");
        in.setFill(Color.AZURE);
        in.setLayoutX(0);
        in.setLayoutY(45);
        chat.getChildren().add(in);
        
        TextArea inbox=new TextArea();
        inbox.setLayoutX(0);
        inbox.setLayoutY(50);
        inbox.setEditable(false);
        inbox.setPrefSize(300,400);
        chat.getChildren().add(inbox);
        
        Text out=new Text(0,500, "Write");
        out.setFill(Color.AZURE);
        chat.getChildren().add(out);
        
        TextField outbox=new TextField();
        outbox.setLayoutX(0);
        outbox.setLayoutY(550);
        outbox.setPrefSize(300, 50);
        chat.getChildren().add(outbox);
        
        Text peeps_online=new Text(330, 50,"people onine:\n");
        peeps_online.setFill(Color.AZURE);
        chat.getChildren().add(peeps_online);
        
        TextArea online=new TextArea();
        online.setLayoutX(330);
        online.setEditable(false);
        online.setLayoutY(55);
        online.setPrefSize(160,350);
        chat.getChildren().add(online);
        
        Button refresh=new Button("Refresh");
        refresh.setLayoutX(330);
        refresh.setLayoutY(500);
        chat.getChildren().add(refresh);
              
        new WriteThread (clientConnection);
        new ReadThread (clientConnection,inbox);
        
        Button send=new Button("send");
        send.setLayoutX(360);
        send.setLayoutY(615);
        chat.getChildren().add(send);
           
        send.setOnAction(e->
        {
            String sent=outbox.getText();
            clientConnection.write(sent);
            outbox.setText("");
            System.out.println(sent);
        });
        
        refresh.setOnAction(e->
        {
            //mp=ReaderOfServer.mp;
            String listOfPeople=" ";
            
            /*for(Map.Entry me: mp.entrySet())
            {
                listOfPeople.concat((String)me.getKey());
                listOfPeople.concat("\n");
            }
            System.out.println(listOfPeople);
            online.appendText(listOfPeople);*/
        });
  
        scene=new Scene(chat,500,650);
        s.setResizable(false);
        s.setScene(scene);
        s.show();
    }
    
}
