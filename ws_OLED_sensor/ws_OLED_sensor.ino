#include <Wire.h>
#include <Adafruit_GFX.h>
#include<Adafruit_SSD1306.h>

const int sensor_pin=34;
Adafruit_SSD1306 lcd(128,64,&Wire,-1);
int value;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("OLED_SENSOR!");
  lcd.begin(SSD1306_SWITCHCAPVCC,0X3C);
  lcd.clearDisplay();
  lcd.setTextSize(1);
  lcd.setTextColor(SSD1306_WHITE);
 
}

void loop() {
  // put your main code here, to run repeatedly:
  value=analogRead(sensor_pin);
  lcd.clearDisplay();
  lcd.setCursor(0,0);
  lcd.print("**Sensor data**");
  lcd.setCursor(0,8);
  lcd.print(value);
  Serial.print("VALUE:");
  Serial.println(value);
  lcd.display();
  delay(1000); // this speeds up the simulation
}
