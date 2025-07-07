void setup() {
  // put your setup code here, to run once:
      Serial.begin(9600);
  
      pinMode(2,OUTPUT);
      
}

void loop() {
  // put your main code here, to run repeatedly:
    if (analogRead(34)<2000)
    {
      digitalWrite(2,HIGH);
     
    }
     // delay(500);
      else
      {
      digitalWrite(2,LOW);
    }
}