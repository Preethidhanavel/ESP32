const int button = 15;
unsigned int count = 0;
int lastState = HIGH;

void setup() {
  Serial.begin(115200);
  pinMode(button, INPUT_PULLUP);
  Serial.println("BUTTON_STATE");
}

void loop() {
  int buttonState = digitalRead(button);
 // Serial.println(buttonState);

  if (buttonState == LOW && lastState == HIGH) {
    count++;
    Serial.print("Count = ");
    Serial.println(count);
    delay(250); // Debounce delay
  }

  lastState = buttonState;
  delay(10); 
}
