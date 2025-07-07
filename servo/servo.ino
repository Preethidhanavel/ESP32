#include <ESP32Servo.h>

Servo myservo;
const int servoPin = 13;

void setup() {
  Serial.begin(115200);
  myservo.attach(servoPin);
}

void loop() {
  myservo.write(0);
  delay(2000);      
  myservo.write(90);
  delay(1000);      
}
