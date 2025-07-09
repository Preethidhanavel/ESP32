const int button = 15;        // Button connected to GPIO 15
unsigned int count = 0;       // Counter for button presses
int lastState = HIGH;         // Stores last button state

void setup() {
  Serial.begin(115200);       // Start serial communication
  pinMode(button, INPUT_PULLUP); // Enable internal pull-up for button
  Serial.println("BUTTON_STATE");
}

void loop() {
  int buttonState = digitalRead(button);  // Read current button state

  // If button transition occurs
  if (buttonState == LOW && lastState == HIGH) 
  {
    count++;                               // Increment count
    Serial.print("Count = ");
    Serial.println(count);
    delay(250);                            // Debounce delay
  }

  lastState = buttonState;  // Update lastState
  delay(10);               
}
