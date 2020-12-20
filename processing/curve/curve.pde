float t;
float angle =0;
int NUM_LINES = 380;
float v1 =0.4;
float v2;
boolean increment = false;
float fator =0.00001;
int seq = 1;
int step = 1;
int currentTime;

void setup(){
    background(20);
    size(500,500);
    v1 = random(0.4)+0.2;
    smooth(2);
}

void draw(){
    background(0);
    angle+= 0.01;
    stroke(255,200);

    translate(width/2-40, height/2);
    rotate(sin(angle));

    for(int i=1; i < NUM_LINES; i++){
        strokeWeight(4);
        point(x(t+i), y(t+i));
        point(x2(t+i), y2(t+i));

        strokeWeight(1.2);

        line(x(t+i),y(t+i),x2(t+i),y2(t+i));
    }

    t += 0.005;

    if(increment)    v1+=fator;

    String name = step + "curve";

    currentTime = millis();
    int sec = currentTime / 1000;

    //println(currentTime);
    if(currentTime / 41 >= seq){
        //println("test");
        save(name+seq);
        seq++;
    }

    if(sec / 10 >= step){
        step++;
        name = step + "curve";
        v1 = random(0.4)+0.2;
        seq = 1;
    }

    if(sec==10){
        exit();
    }


}

void mousePressed() {
    v1 = random(0.4)+0.2;
}

void keyReleased(){
    increment = false;
}

void keyPressed() {
    if(key == ' '){
        v1 = random(0.4)+0.2;
    }

    if (keyCode == LEFT) {
        increment = true;
        fator = -0.00001;
        } else if (keyCode == RIGHT) {
            increment = true;
            fator = 0.00001;
        }
    if (keyCode == UP) {
        NUM_LINES+=1;
        println("nlines "+NUM_LINES);
        } else if (keyCode == DOWN) {
            NUM_LINES-=1;
        }

}

float x(float t){
    return sin(t/10)*100 + cos(t/v1)*100;
}
float y(float t){
    return cos(t/10)*100 + sin(t/v1)*100;
}
float x2(float t){
    return sin(t/10)*10 + cos(t/v1)*100;
}
float y2(float t){
    return cos(t/10)*10 + sin(t/v1)*100;
}
