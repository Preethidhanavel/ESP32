const int analog_pin=34;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Sensor example");
}

void loop() {
  // put your main code here, to run repeatedly:
  int value=analogRead(analog_pin);
  Serial.print("Potentiometer value:");
  Serial.println(value);
  delay(1000);
  Serial.println((value*3.3)/4095.00);
}
