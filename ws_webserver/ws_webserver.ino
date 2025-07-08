#include <WiFi.h>

const char* ssid     = "Preethi";
const char* password = "preethi@123";

WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.print("Connected! IP address: ");
  Serial.println(WiFi.localIP());

  server.begin();
}

void loop() {
  WiFiClient client = server.available();

  if (client) {
    String currentRequest = "";

    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        currentRequest += c;

        if (c == '\n') {
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");
          client.println();

          client.println("<!DOCTYPE html>");
          client.println("<html>");
          client.println("<head><title>ESP32 Web Server</title></head>");
          client.println("<body><h1>Hello from ESP32!</h1>");
          client.println("<p>This is a simple web page served by ESP32.</p>");
          client.println("</body></html>");

          break;
        }
      }
    }

    delay(1);
    client.stop();
  }
}
