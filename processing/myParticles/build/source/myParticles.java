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

public class myParticles extends PApplet {

class Particle{
    float mass;
    float speedX;
    float speedY;
    float posX;
    float posY;
    Particle(float m, float x, float y){
        mass = m;
        posX = x;
        posY = y;
        speedX = 0;
        speedY = 0;
    }
    public void draw(){
        posX += speedX;
        posY += speedY;
        ellipse(posX, posY, mass*5, mass*5);
    }
}

Particle ps[];

public void setup(){
    
    noStroke();
    fill(64, 255, 255, 192);
    background(32);
    ps = new Particle[1];
    ps[0] = new Particle(0.0f, 0.0f, 0.0f);
}


int num = 1;

public void addNewParticle(){
    num++;
    ps = (Particle[])expand(ps, num);
    ps[num-1] = new Particle(random(1,10), mouseX, mouseY);
}

public float getSign(float num){
    if(num != 0)
        return num/abs(num);
    else
        return 0;
}

public void addForce(){
    ps[0].mass = 5 * num;
    ps[0].posX = mouseX;
    ps[0].posY = mouseY;
}

int time = 1000;
public void monitor(int currentTime){
    if(num > 1){
        if(currentTime / time > 1){
            println(ps[1].posX, ps[1].posY);
            time += 1000;
        }
    }
}
public void draw(){

    background(32);

    if(mousePressed == true){
        if(mouseButton == LEFT){
            addForce();
        }
        if(mouseButton == RIGHT){
            addNewParticle();
        }
    }
    else{
        ps[0].mass = 0;
    }

    monitor(millis());

    for(int i=0; i<num; i++){
        float accX = 0, accY = 0;
        for(int j=0; j<num; j++){
            if(i!=j){
                float disX = ps[j].posX - ps[i].posX;
                float disY = ps[j].posY - ps[i].posY;
                float distance = dist(ps[i].posX, ps[i].posY, ps[j].posX, ps[j].posY);
                if(distance < 1)
                    distance = 1;

                //float force = 0.0001 * (distance - 400) * ps[i].mass * ps[j].mass;
                float force = 0.001f * (distance - 400) * ps[i].mass * ps[j].mass / distance;
                accX += force / ps[i].mass * getSign(disX);
                accY += force / ps[i].mass * getSign(disY);
            }
        }
        ps[i].speedX = ps[i].speedX * 0.99f + accX;
        ps[i].speedY = ps[i].speedY * 0.99f + accY;
    }

    for(int i=1; i<num; i++){
        ps[i].draw();
    }
}
  public void settings() {  size(800,800); }
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "myParticles" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
