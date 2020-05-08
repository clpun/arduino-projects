int switchState = 0; // Stores the state of the switch. 

/* The setup method runs once when the Arduino is first powered on. 
 * This is where the digital pins are configured to be input/output. 
 */
void setup() {
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, INPUT);
}

/* The loop method runs continuously after the setup method has completed.
 */
void loop() {
  switchState = digitalRead(2); // Read signal from pin 2.
  if (switchState == LOW) {
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  } else {
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    
    delay(250); // Wait for 0.25 second.
    
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    
    delay(250);
  }
}
