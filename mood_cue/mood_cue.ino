#include <Servo.h>

Servo myServo;
int const potPin = A0;
int potVal;
int angle;

void setup() {
  // Tell Arduino which pin the servo motor is attached to.
  myServo.attach(9);
  
  Serial.begin(9600);
}

void loop() {
  potVal = analogRead(potPin);
  Serial.print("Pot Value: ");
  Serial.print(potVal);
  
  angle = map(potVal, 0, 1023, 0, 179);
  Serial.print(" Angle: ");
  Serial.println(angle);
  
  myServo.write(angle);
  delay(15);
}
