void setup() {
  Serial.begin(9600);      // Start serial communication
  pinMode(2, OUTPUT);      // Set pin 2 as output
}

void loop() {
  if (analogRead(34) > 2000) 
  {
    digitalWrite(2, HIGH); // Turn ON LED if value > 2000 means dark
  } 
  else 
  {
    digitalWrite(2, LOW);  // Turn OFF LED otherwise
  }

  delay(500);              // delay
}
