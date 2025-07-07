//16*2 lcd display 4 bit code//
#include <LiquidCrystal.h>

// RS, E, D4, D5, D6, D7 (4-bit mode)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int count=0;

void setup()
{
  lcd.begin(16, 2);              // Initialize 16x2 LCD
  lcd.print("PREETHI");    // Print on first line
}

void loop() 
{
 count++;
}
