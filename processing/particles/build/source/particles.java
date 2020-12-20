import processing.core.*; 
import processing.data.*; 
import processing.event.*; 
import processing.opengl.*; 

import java.util.HashMap; 
import java.util.ArrayList; 
import java.io.File; 
import java.io.BufferedReader; 
import java.io.PrintWriter; 
import java.io.InputStream; 
import java.io.OutputStream; 
import java.io.IOException; 

public class particles extends PApplet {

float mass[] = {0};
float positionX[] = {0};
float positionY[] = {0};
float speedX[] = {0};
float speedY[] = {0};

public void setup(){
    
    noStroke();
    fill(64, 255, 255, 192);
}

public void addNewParticle(){
    mass = expand(mass,mass.length+1);
    mass[mass.length-1] = random(0.003f, 0.03f);

    positionX = expand(positionX, positionX.length+1);
    positionX[positionX.length-1] = mouseX;

    positionY = expand(positionY, positionY.length+1);
    positionY[positionY.length-1] = mouseY;

    speedX = expand(speedX, speedX.length+1);
    speedX[speedX.length-1] = 0;

    speedY = expand(speedY, speedY.length+1);
    speedY[speedY.length-1] = 0;
}

int num = 1;

public void draw(){
    background(32);

    if(mousePressed == true){
        addNewParticle();
    }


    for(int i = 1; i<mass.length; i++){
        float accerlationX = 0, accerlationY = 0;
        for(int j = 1; j<mass.length; j++){
            if(i!=j){
                float distanceX = positionX[j] - positionX[i];
                float distanceY = positionY[j] - positionY[i];
                float distance = dist(positionX[i], positionY[i], positionX[j], positionY[j]);
                if(distance < 1)
                    distance = 1;
                float force = (distance - 400) * mass[j] / distance;
                accerlationX += force * distanceX;
                accerlationY += force * distanceY;
            }
        }
        speedX[i] = speedX[i] * 0.99f + accerlationX * mass[i];
        speedY[i] = speedY[i] * 0.99f + accerlationY * mass[i];
    }

    for(int i=1; i<mass.length; i++){
        positionX[i] += speedX[i];
        positionY[i] += speedY[i];
        ellipse(positionX[i],positionY[i],mass[i]*1000,mass[i]*1000);
    }
}
  public void settings() {  size(800,800); }
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "particles" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
