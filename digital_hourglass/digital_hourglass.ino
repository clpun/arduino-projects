const int switchPin = 8;
unsigned long previousTime = 0;
int switchState = 0;
int prevSwitchState = 0;
int ledCount = 2;
long interval = 30000; // 30 seconds

void setup() {
  for (int i = 2; i <= 7; i++) {
    pinMode(i, OUTPUT);
  }
  
  pinMode(switchPin, INPUT);
}

void loop() {
  unsigned long currentTime = millis();
  
  if ((currentTime - previousTime) > interval) {
    digitalWrite(ledCount, HIGH);
    ledCount++;
    previousTime = currentTime;
    
    if (ledCount == 7) {
      // TODO
    }
  }
  
  switchState = digitalRead(switchPin);
  
  if (switchState != prevSwitchState) {
    for (int i = 2; i <= 7; i++) {
      digitalWrite(i, LOW);
    }
    
    previousTime = currentTime;
    ledCount = 2;
  }
  
  prevSwitchState = switchState;
}
