#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64 


Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
int count=0;

void setup() {

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("OLED not found"));
    for (;;);
  }

  display.clearDisplay();               
  display.setTextSize(2);               
  display.setTextColor(SSD1306_WHITE);  
  display.setCursor(0, 10);            
  display.println("VECTOR");            
  display.setCursor(0, 35);
  display.println("INDIA");
  display.display();                    
}

void loop()
 {
 count++;
}
