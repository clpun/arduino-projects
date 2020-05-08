const int switchPin = 2;
const int motorPin = 9;
boolean switchOn = false;

void setup() {
  pinMode(switchPin, INPUT);
  pinMode(motorPin, OUTPUT);
}

void loop() {
  if (digitalRead(switchPin) == HIGH) {
    switchOn = true;
  } else {
    switchOn = false;
  }
  
  if (switchOn) {
    digitalWrite(motorPin, HIGH);
  } else {
    digitalWrite(motorPin, LOW);
  }
}
