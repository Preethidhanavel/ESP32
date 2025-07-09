#define DO_PIN 21      // Digital output pin from the rain sensor

void setup() {
  Serial.begin(9600);           // Start serial communication
  pinMode(DO_PIN, INPUT);       // Set digital output pin as input
}

void loop() {
 
  int rain_state = digitalRead(DO_PIN); // Read sensor value

  if (rain_state == HIGH)
    Serial.println("The rain is NOT detected"); // No rain
  else
    Serial.println("The rain is detected");     // Rain detected

  delay(1000); //delay
}
