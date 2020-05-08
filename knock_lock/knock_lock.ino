#include <Servo.h>

Servo myServo;
const int piezo = A0;
const int switchPin = 2;
const int greenLED = 3;
const int yellowLED = 4;
const int redLED = 5;

int knockVal;
int switchVal;

const int quietKnock = 10;
const int loudKnock = 100;

boolean locked = false;
int numberOfKnocks = 0;

void setup() {
  myServo.attach(9);
  pinMode(switchPin, INPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  Serial.begin(9600);
  
  digitalWrite(greenLED, HIGH);
  Serial.println("The box is unlocked!");
}

void loop() {
  if (locked == false) {
    switchVal = digitalRead(switchPin);
    if (switchVal == HIGH) {
      locked = true;
      digitalWrite(greenLED, LOW);
      digitalWrite(redLED, HIGH);
      myServo.write(90);
      Serial.println("The box is locked!");
      numberOfKnocks = 0;
      delay(1000);
    }
  } else if (locked == true) {
    knockVal = analogRead(piezo);
    if ((numberOfKnocks < 3) && (knockVal > 0)) {
      if (checkForKnocks(knockVal) == true) {
        numberOfKnocks++;
      }
    }
    
    if (numberOfKnocks >= 3) {
      locked = false;
      myServo.write(0);
      delay(20);
      digitalWrite(redLED, LOW);
      digitalWrite(greenLED, HIGH);
      Serial.println("The box is unlocked!");
    }
  }
}

boolean checkForKnocks(int value) {
  if (value >= loudKnock && value <= quietKnock) {
    digitalWrite(yellowLED, HIGH);
    delay(50);
    digitalWrite(yellowLED, LOW);
    return true;
  }
  
  return false;
}
