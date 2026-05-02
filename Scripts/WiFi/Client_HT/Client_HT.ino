// Título: Cliente WiFi
// Autor: Gustavo V. Diaz
// Fecha: 01/05/2026
// Referencia: Libro Hands-on ESP32 with Arduino IDE_ Unleash the power of IoT -- Asim Zulfiqar -- 2023 Capítulo 4 sección "ESP32 as a Wi-Fi client"

#include <WiFi.h>
#include "arduino_secrets.h"

char ssid[] = SECRET_SSID;
char pass[] = SECRET_PASS;

// const char* ssid = "Telecentro-049d";
// const char* password = "KM2ZXV2WXHUZ";
void setup() {
Serial.begin(115200);  delay(500);
  Serial.print(".");
WiFi.begin(ssid, pass);
Serial.print("Connecting to WiFi...");
while (WiFi.status() != WL_CONNECTED) {
  delay(500);
  Serial.print(".");
}
Serial.println();
Serial.print("Connected to WiFi network with IP address: ");
Serial.println(WiFi.localIP());
}
void loop() {
//
}