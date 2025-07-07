#define VRX_PIN  39
#define VRY_PIN  36

int valueX = 0;
int valueY = 0;

void setup() {
  Serial.begin(9600);
  analogSetAttenuation(ADC_11db);
}

void loop() {
  valueX = analogRead(VRX_PIN);
  valueY = analogRead(VRY_PIN);

  Serial.print("x = ");
  Serial.print(valueX);
  Serial.print("y = ");
  Serial.println(valueY);

  delay(200);
}
