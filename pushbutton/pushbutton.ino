void setup() {
  pinMode(0, INPUT);      // Set pin 0 as input - button
  pinMode(2, OUTPUT);     // Set pin 2 as output - LED
}

void loop() {
  if (digitalRead(0) == HIGH)      // If input on pin 0 is HIGH
  { 
    digitalWrite(2, HIGH);        // Turn ON LED
    delay(1000);                  // Wait for 1 second
  } 
  else 
  {
    digitalWrite(2, LOW);         // Turn OFF LED
  }
}
