void setup() {
  Serial.begin(115200);  // Initialize serial communication at 115200 baud rate
}

void loop() {
  int measurement = 0;           // Variable to store the hall sensor value

  measurement = hallRead();     // Read the built-in Hall effect sensor on the ESP32

  Serial.print("Hall sensor measurement: ");  
  Serial.println(measurement);                // Print the measured value

  delay(1000);  // delay
}
