#define MOISTURE_PIN 34  

void setup() {
  Serial.begin(115200);
}

void loop() {
  int sensorValue = analogRead(MOISTURE_PIN);  


  int moisturePercent = map(sensorValue, 0, 4095, 100, 0);

  Serial.print("Soil Moisture: ");
  Serial.print(moisturePercent);
  Serial.println(" %");

  delay(1000);
}

