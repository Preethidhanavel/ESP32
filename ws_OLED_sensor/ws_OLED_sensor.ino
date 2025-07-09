#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

const int sensor_pin = 34;  // Analog sensor pin

// Create OLED display object (128x64 pixels, I2C)
Adafruit_SSD1306 lcd(128, 64, &Wire, -1);

int value;

void setup() {
  Serial.begin(115200);
  Serial.println("OLED_SENSOR!");

  lcd.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // Initialize OLED display
  lcd.clearDisplay();
  lcd.setTextSize(1);
  lcd.setTextColor(SSD1306_WHITE);
}

void loop() {
  value = analogRead(sensor_pin);  // Read sensor value

  lcd.clearDisplay();              // Clear previous display
  lcd.setCursor(0, 0);
  lcd.print("**Sensor data**");
  lcd.setCursor(0, 8);
  lcd.print(value);

  Serial.print("VALUE: ");         // Print value to Serial Monitor
  Serial.println(value);

  lcd.display();                   // Update OLED display
  delay(1000);                     // Delay for 1 second
}
