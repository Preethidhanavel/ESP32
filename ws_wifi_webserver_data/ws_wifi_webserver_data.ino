#include <WiFi.h>

const char* ssid = "Preethi";         // WiFi SSID
const char* password = "*******"; // WiFi password

WiFiServer server(80);  // Create server on port 80 (HTTP)
String request;
#define LED 21           // LED connected to GPIO 21

int LED_Status;          // To track LED state
WiFiClient client;

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW); // Start with LED off

  // Connect to WiFi
  Serial.print("Connecting to");
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(100);
  }

  Serial.print("\nConnected to Wi-Fi ");
  Serial.println(WiFi.SSID());

  server.begin();  // Start the web server

  // Print the ESP32's IP address
  Serial.print("Connect to IP Address: http://");
  Serial.println(WiFi.localIP());
}

// Function to send HTML page to the browser
void html() {
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("Connection: close");
  client.println();

  client.println("<!DOCTYPE HTML><html>");
  client.println("<head>");
  client.println("<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
  client.println("<style>");
  client.println("html { font-family: Roboto; text-align: center;}");
  client.println(".button { padding: 15px 32px; font-size: 25px; cursor: pointer;}");
  client.println(".button_ON { background-color: white; color: black; border: 2px solid #4CAF50; }");
  client.println(".button_OFF { background-color: white; color: black; border: 2px solid #f44336; }");
  client.println("</style>");
  client.println("</head>");

  client.println("<body>");
  client.println("<h2>ESP32 WiFi Station Mode</h2>");
  client.println("<p>Click to Turn ON and OFF the LED</p>");

  // Show ON or OFF button depending on LED status
  if (LED_Status == LOW) {
    client.print("<p><a href=\"/LED_ON\n\"><button class=\"button button_ON\">ON</button></a></p>");
  } 
  else {
    client.print("<p><a href=\"/LED_OFF\n\"><button class=\"button button_OFF\">OFF</button></a></p>");
  }

  client.println("</body></html>");
}

void loop() {
  client = server.available();  // Wait for client connection
  if (!client) return;

  while (client.connected()) {
    if (client.available()) {
      char c = client.read();   // Read request character by character
      request += c;

      // When end of HTTP request line is reached
      if (c == '\n') {
        // Handle LED ON command
        if (request.indexOf("GET /LED_ON") != -1) {
          Serial.println("LED is ON");
          digitalWrite(LED, HIGH);
          LED_Status = HIGH;
        }

        // Handle LED OFF command
        if (request.indexOf("GET /LED_OFF") != -1) {
          Serial.println("LED is OFF");
          digitalWrite(LED, LOW);
          LED_Status = LOW;
        }

        html();  // Send HTML response
        break;
      }
    }
  }

  delay(1);
  request = "";      // Clear the request buffer
  client.stop();     // Close the connection
}
