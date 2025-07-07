#define POWER_PIN 19
#define DO_PIN 21

void setup() {
  Serial.begin(9600);
  pinMode(POWER_PIN, OUTPUT);
  pinMode(DO_PIN, INPUT);
}

void loop() {
  digitalWrite(POWER_PIN, HIGH);
  delay(10);

  int rain_state = digitalRead(DO_PIN);

  digitalWrite(POWER_PIN, LOW);

  if (rain_state == HIGH)
    Serial.println("The rain is NOT detected");
  else
    Serial.println("The rain is detected");

  delay(1000);
}
