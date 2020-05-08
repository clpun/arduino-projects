int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;

const int ledPin = 13;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  // Turn led on to indicate that we will start adjusting sensor limits. 
  digitalWrite(ledPin, HIGH);
  
  // Adjust sensor limits.
  while (millis() < 5000) {
    sensorValue = analogRead(A0);
    if (sensorValue > sensorHigh) {
      sensorHigh = sensorValue;
    }
    if (sensorValue < sensorLow) {
      sensorLow = sensorValue;
    }
  }
  
  // Turn led off after it finishes adjusting sensor limits.
  digitalWrite(ledPin, LOW);
}

void loop() {
  sensorValue = analogRead(A0);
  Serial.print("Sensor value: ");
  Serial.println(sensorValue);
  
  int pitch = map(sensorValue, sensorLow, sensorHigh, 20, 1000);
  tone(8, pitch, 20);
  Serial.print("Pitch value: ");
  Serial.println(pitch);
  
  delay(10);
}
