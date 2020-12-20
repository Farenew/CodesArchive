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
    void draw(){
        posX += speedX;
        posY += speedY;
        ellipse(posX, posY, mass*5, mass*5);
    }
}

Particle ps[];

void setup(){
    size(800,800);
    noStroke();
    fill(64, 255, 255, 192);
    background(32);
    ps = new Particle[1];
    ps[0] = new Particle(0.0, 0.0, 0.0);
}


int num = 1;

void addNewParticle(){
    num++;
    ps = (Particle[])expand(ps, num);
    ps[num-1] = new Particle(random(1,10), mouseX, mouseY);
}

float getSign(float num){
    if(num != 0)
        return num/abs(num);
    else
        return 0;
}

void addForce(){
    ps[0].mass = 5 * num;
    ps[0].posX = mouseX;
    ps[0].posY = mouseY;
}

int time = 1000;
void monitor(int currentTime){
    if(num > 1){
        if(currentTime / time > 1){
            println(ps[1].posX, ps[1].posY);
            time += 1000;
        }
    }
}
void draw(){

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
                float force = 0.001 * (distance - 400) * ps[i].mass * ps[j].mass / distance;
                accX += force / ps[i].mass * getSign(disX);
                accY += force / ps[i].mass * getSign(disY);
            }
        }
        ps[i].speedX = ps[i].speedX * 0.99 + accX;
        ps[i].speedY = ps[i].speedY * 0.99 + accY;
    }

    for(int i=1; i<num; i++){
        ps[i].draw();
    }
}
