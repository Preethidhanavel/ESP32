#define PIR_PIN 15    
#define LED_PIN 2     

void setup() {
  pinMode(PIR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

}

void loop() {
  int motion = digitalRead(PIR_PIN);

  if (motion == HIGH) 
  {
    digitalWrite(LED_PIN, HIGH);  
  } else
   {
    digitalWrite(LED_PIN, LOW);   
  }

  delay(500);  
}