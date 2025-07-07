const int ledPin = 16;        
const int freq = 5000;      
const int resolution = 8;   

void setup() {
  
  if (!ledcAttach(ledPin, freq, resolution))
   {
    
    while (1); 
  }
}

void loop() {
 
  for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++)
   {
    ledcWrite(ledPin, dutyCycle); 
    delay(15);
  }

  for (int dutyCycle = 255; dutyCycle >= 0; dutyCycle--) {
    ledcWrite(ledPin, dutyCycle);
    delay(15);
  }
}
