# GIF制作

使用gifAnimation实现processing对于GIF格式图像的使用

## 1. 读取gif图像

```c++
import gifAnimation.*;

Gif myAnimation;

void setup() {
    size(400,400);
    myAnimation = new Gif(this, "export.gif");
    myAnimation.play();
}

void draw() {
    image(myAnimation, 10, 10);
}
```

## 2. 制作gif图像

示例的绘制一个圆环的程序

```c++
import gifAnimation.*;

GifMaker gifExport;
int frames = 0;
int totalFrames = 120;

public void setup() {
  smooth();
  size(400, 400);

  gifExport = new GifMaker(this, "export.gif", 100);
  gifExport.setRepeat(0); // make it an "endless" animation

  noFill();
  stroke(0);
  strokeWeight(20);
}

void draw() {
  background(255);
  float size = 100.0 * sin(TWO_PI * frames / float(totalFrames)) + 200.0;
  ellipse(width/ 2.0, height / 2.0, size, size);
  export();
}

void export() {
  if(frames < totalFrames) {
    gifExport.setDelay(20);
    gifExport.addFrame();
    frames++;
  } else {
    gifExport.finish();
    frames++;
    println("gif saved");
    exit();
  }
}
```
