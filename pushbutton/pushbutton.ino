void setup() {
  // put your setup code here, to run once:
      Serial.begin(9600);
      pinMode(0,INPUT);
      pinMode(2,OUTPUT);
      
}

void loop() {
  // put your main code here, to run repeatedly:
    if (digitalRead(0)==HIGH)
    {
      digitalWrite(2,HIGH);
      delay(1000);
    }
     // delay(500);
      else
      {
      digitalWrite(2,LOW);
    }
}
