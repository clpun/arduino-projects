import processing.serial.*;

Serial myPort;
PImage logo;
int bgcolour = 0;

void setup() {
  colorMode(HSB, 255);
  logo = loadImage("http://arduino.cc/logo.png");
  size(logo.width, logo.height);
  
  println("Available serial ports: ");
  println(Serial.list());
  
  myPort = new Serial(this, Serial.list()[9], 9600);
}

void draw() {
  if (myPort.available() > 0) {
    bgcolour = myPort.read();
    //println(bgcolour);
  }
  
  background(bgcolour, 255, 255);
  image(logo, 0, 0);
}
