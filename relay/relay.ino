
#define RELAY_PIN 16 


void setup() {
 
  pinMode(RELAY_PIN, OUTPUT);
}


void loop() {
  digitalWrite(RELAY_PIN, HIGH);
  delay(1000);
  digitalWrite(RELAY_PIN, LOW);
  delay(1000);
}
