const int sensorPin = A0;
const float baselineTemp = 20.0;

void setup() {
  // Initialize serial port; specify speed to be 9600 bits/s.
  Serial.begin(9600); 
  
  for (int pinNumber = 2; pinNumber <=4; pinNumber++) {
     pinMode(pinNumber, OUTPUT);
     digitalWrite(pinNumber, LOW);
  }
}

void loop() {
  // Get data from the temp. sensor and store it into sensorVal. 
  int sensorVal = analogRead(sensorPin);
  float voltage;
  float temperature;
  
  Serial.print("Sensor value: ");
  Serial.print(sensorVal);
  
  voltage = (sensorVal/1023.0)*5.0;
  Serial.print(", Volts: ");
  Serial.print(voltage);
  
  temperature = (voltage - 0.5)*100;
  Serial.print(", degrees C: ");
  Serial.println(temperature);
  
  if (temperature < baselineTemp) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if ((temperature >= baselineTemp + 2) && (temperature < baselineTemp + 4)) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW); 
  } else if ((temperature >= baselineTemp + 4) && (temperature < baselineTemp + 6)) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  } else if (temperature >= baselineTemp + 6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
  
  delay(1);
}
