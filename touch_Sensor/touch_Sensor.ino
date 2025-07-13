#define TOUCH_PIN 4    // define touch pin
#define LED_PIN 2      // define LED pin

void setup() {
  pinMode(LED_PIN, OUTPUT);  // LED pin as output
}

void loop() {
  int touchValue = touchRead(TOUCH_PIN); // reading the value of touch pin

  if (touchValue < 20) { // if value is less than 20 then touch is detected 
    digitalWrite(LED_PIN, HIGH); //turn on LED
  } 
  else {
    digitalWrite(LED_PIN, LOW);
  }

  delay(50);
}
