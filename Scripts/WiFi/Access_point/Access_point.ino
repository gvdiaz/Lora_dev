# Título: Access Point WiFi
# Autor: Gustavo V. Diaz
# Fecha: 01/05/2026
# Referencia: Libro Hands-on ESP32 with Arduino IDE_ Unleash the power of IoT -- Asim Zulfiqar -- 2023 Capítulo 4 sección "ESP32 as Wi-Fi access point"

#include <WiFi.h>
const char* ssid = "MyESP32AP";
const char* password = "password123";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  WiFi.softAP(ssid, password);
  IPAddress apIP(192, 168, 4, 1);
  IPAddress subnet(255, 255, 255, 0);
  WiFi.softAPConfig(apIP, apIP, subnet);
  Serial.print("Access Point IP Address: ");
  Serial.println(WiFi.softAPIP());

}

void loop() {
  // put your main code here, to run repeatedly:

}
