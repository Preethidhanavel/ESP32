#include "DHT.h"

#define DHTPIN 4
#define DHTTYPE DHT22

#define LED_TEMP 2
#define LED_HUMID 15

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  dht.begin();
  pinMode(LED_TEMP, OUTPUT);
  pinMode(LED_HUMID, OUTPUT);
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (!isnan(temperature)) {
    digitalWrite(LED_TEMP, temperature > 30 ? HIGH : LOW);
  }

  if (!isnan(humidity)) {
    digitalWrite(LED_HUMID, humidity > 70 ? HIGH : LOW);
  }

  delay(2000);
}
