// # Título: Web server
// # Autor: Gustavo V. Diaz
// # Fecha: 05/05/2026
// # Referencia: Libro Hands-on ESP32 with Arduino IDE_ Unleash the power of IoT -- Asim Zulfiqar -- 2023 Capítulo 5 sección "ESP32 as an HTTP web server"
// # Referencia 2: https://github.com/PacktPublishing/Programming-ESP32-with-Arduino-IDE/blob/main/Chapter%205/ESP32_webserver/ESP32_webserver.ino


#include <WiFi.h>
#include <WebServer.h>
#include "arduino_secrets.h"

char ssid[] = SECRET_SSID;
char pass[] = SECRET_PASS;

WebServer server(80);
const int ledPin = 13;
const int buttonPin = 12;
bool ledState = false;
void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  digitalWrite(ledPin, ledState);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi…");
  }
  Serial.println("WiFi connected");
  Serial.println("IP addres: ");
  Serial.println(WiFi.localIP());
  server.on("/", HTTP_GET, handleRoot);
  server.on("/toggle", HTTP_GET, handleToggle);
  server.begin();
}

void loop() {
  server.handleClient();
  int buttonState = digitalRead(buttonPin);
  if (buttonState == LOW) {
    ledState = !ledState;
    digitalWrite(ledPin, ledState);
    }
}

void handleRoot() { 

 String html = "<html><body>"; 

 html += "<h1>ESP32 LED Control</h1>"; 

 html += "<p>LED Status: " + String(ledState) + "</p>"; 

 html += "<form method='get' action='/toggle'>"; 

 html += "<button type='submit'>Toggle LED</button>"; 

 html += "</form>"; 

 html += "</body></html>"; 

 server.send(200, "text/html", html); 
}

void handleToggle() {
  ledState = !ledState;
  digitalWrite(ledPin, ledState);
  server.send(200, "text/plain", "LED toggled");
}