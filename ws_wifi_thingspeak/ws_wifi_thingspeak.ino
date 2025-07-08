#include <WiFi.h>
#include "DHT.h"
#include "HTTPClient.h"

#define DHTPIN 4         
#define DHTTYPE DHT11    
DHT dht(DHTPIN, DHTTYPE);


const char* ssid = "Preethi";
const char* password = "preethi@123";

String apiKey = "R5VANS83S3ZTKA8R"; 
const char* server = "http://api.thingspeak.com/update";

void setup() {
  Serial.begin(115200);
  dht.begin();

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi Connected!");
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature(); 

  
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    delay(2000);
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print("°C, Humidity: ");
  Serial.print(h);
  Serial.println("%");

  
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;

    String url = server;
    url += "?api_key=" + apiKey;
    url += "&field1=" + String(t);
    url += "&field2=" + String(h);

    http.begin(url);
    int httpCode = http.GET();
    if (httpCode > 0) {
      Serial.println("Data sent to ThingSpeak.");
    } else {
      Serial.print("Error sending data. Code: ");
      Serial.println(httpCode);
    }
    http.end();
  }

  delay(15000); 
}
