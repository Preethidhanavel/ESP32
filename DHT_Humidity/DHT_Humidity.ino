#include "DHT.h"  // Include the DHT sensor library

#define DHTPIN 4        // Define GPIO pin connected to the DHT sensor
#define DHTTYPE DHT22   // Specify the DHT sensor model (DHT22)

#define LED_TEMP 2      // GPIO pin connected to temperature status LED
#define LED_HUMID 15    // GPIO pin connected to humidity status LED

DHT dht(DHTPIN, DHTTYPE);  // Create a DHT object using specified pin and type

void setup() {
  dht.begin();                 // Initialize the DHT sensor
  pinMode(LED_TEMP, OUTPUT);   // Set temperature LED pin as output
  pinMode(LED_HUMID, OUTPUT);  // Set humidity LED pin as output
}

void loop() {
  float temperature = dht.readTemperature(); // Read temperature in Celsius
  float humidity = dht.readHumidity();       // Read humidity percentage

  
  if (!isnan(temperature)) 
  {
    digitalWrite(LED_TEMP, temperature > 30 ? HIGH : LOW); // Turn on LED if temp > 30°C
  }

  if (!isnan(humidity)) 
  {
    digitalWrite(LED_HUMID, humidity > 70 ? HIGH : LOW);   // Turn on LED if humidity > 70%
  }

  delay(2000);  // delay
}
