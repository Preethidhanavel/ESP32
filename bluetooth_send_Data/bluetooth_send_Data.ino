#include "BluetoothSerial.h"
#include "DHT.h"

#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  dht.begin();
  SerialBT.begin("ESP32_Sensor");
  Serial.println("Bluetooth ready. Pair with 'ESP32_Sensor'");
}

void loop() {
  float temp = dht.readTemperature();
  float hum  = dht.readHumidity();

  if (isnan(temp) || isnan(hum)) {
    delay(2000);
    return;
  }

  String data = "Temp: " + String(temp) + " °C, Humidity: " + String(hum) + " %";

  SerialBT.println(data);
  Serial.println("Sent to phone: " + data);

  delay(5000);
}
