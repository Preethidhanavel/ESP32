#include "BluetoothSerial.h"  // Include the Bluetooth Serial library

BluetoothSerial SerialBT;     // Create an object of BluetoothSerial

void setup() {
  Serial.begin(115200);               // Start serial communication with PC at 115200 baud
  SerialBT.begin("ESP32_bluetooth");        // Start Bluetooth with device name "ESP32_bluetooth"
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop() {
  // If data is available from the Serial Monitor (PC -> ESP32)
  if (Serial.available()) {
    SerialBT.write(Serial.read());    // Read one byte from Serial and send it over Bluetooth
  }

  // If data is available from Bluetooth (Phone -> ESP32)
  if (SerialBT.available()) {
    Serial.write(SerialBT.read());    // Read one byte from Bluetooth and send it to Serial Monitor
  }

  delay(20);  // Small delay 
}
