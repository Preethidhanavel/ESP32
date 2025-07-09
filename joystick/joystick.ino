#define VRX_PIN  39  // Define GPIO 39 (ADC) for the X-axis of the joystick
#define VRY_PIN  36  // Define GPIO 36 (ADC) for the Y-axis of the joystick

int valueX = 0;  // Variable to store the analog value from X-axis
int valueY = 0;  // Variable to store the analog value from Y-axis

void setup() {
  Serial.begin(9600);                     // Initialize Serial Monitor communication at 9600 baud
  analogSetAttenuation(ADC_11db);         // Set ADC attenuation to 11dB to read up to 0-3.3V
}

void loop() {
  valueX = analogRead(VRX_PIN);           // Read analog value from X-axis pin (0–4095)
  valueY = analogRead(VRY_PIN);           // Read analog value from Y-axis pin (0–4095)

  Serial.print("x = ");                   
  Serial.print(valueX);                   // Print the X-axis value
  Serial.print("  y = ");                 
  Serial.println(valueY);                 // Print the Y-axis value 

  delay(200);                             // delay 
}
