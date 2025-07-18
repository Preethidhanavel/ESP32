#include "BluetoothSerial.h"  // Library for Bluetooth communication
#include "DHT.h"              // Library for DHT sensor

#define DHTPIN 4              // GPIO pin where DHT11 is connected
#define DHTTYPE DHT11         // type of DHT sensor used

DHT dht(DHTPIN, DHTTYPE);     // Create a DHT object with specified pin and type
BluetoothSerial SerialBT;     // Create a BluetoothSerial object

void setup() {
  Serial.begin(115200);               // Start serial communication with the computer
  dht.begin();                        // Initialize the DHT sensor
  SerialBT.begin("ESP32_Sensor");     // Start Bluetooth with the device name "ESP32_Sensor"
  Serial.println("Bluetooth ready. Pair with 'ESP32_Sensor'"); // Confirmation message 
}

void loop() {
  float temp = dht.readTemperature(); // Read temperature from DHT sensor
  float hum  = dht.readHumidity();    // Read humidity from DHT sensor

  // Check if reading failed (returns NaN), skip this cycle if so
  if (isnan(temp) || isnan(hum)) {
    delay(2000);                      // Wait before retrying
    return;
  }

  // Combine temperature and humidity data into a formatted string
  String data = "Temp: " + String(temp) + " °C, Humidity: " + String(hum) + " %";

  SerialBT.println(data);             // Send data over Bluetooth to the paired device
  Serial.println("Sent to phone: " + data);  // Also print data on Serial Monitor

  delay(5000);                        // Wait 5 seconds before next reading
}
