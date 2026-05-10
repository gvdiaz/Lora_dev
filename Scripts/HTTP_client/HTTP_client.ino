// # Título: Web server
// # Autor: Gustavo V. Diaz
// # Fecha: 09/05/2026
// # Referencia: Libro Hands-on ESP32 with Arduino IDE_ Unleash the power of IoT -- Asim Zulfiqar -- 2023 Capítulo 5 sección "ESP32 as an HTTP client"
// # Referencia 2: https://github.com/PacktPublishing/Programming-ESP32-with-Arduino-IDE/blob/main/Chapter%205/ESP32_as_HTTP_client/ESP32_as_HTTP_client.ino

// Biblioteca necesarias para acceso a servidor HTTP
#include <WiFi.h> 
#include <HTTPClient.h>
#include <Arduino_JSON.h>

// Biblioteca para escritura en pantalla OLED de dispositivo
#include <Wire.h>
#include "HT_SSD1306Wire.h"

// Biblioteca para conversión de hora a formato humano
#include <Arduino.h>
#include <TimeLib.h>

// Biblioteca para obtener credenciales
#include "arduino_secrets.h"

#define LAT "-34.62528799687441"
#define LON "-58.464051513325735"

#define INTERLINE 10

// Configuración de pantalla
// Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET); 
static SSD1306Wire  display(0x3c, 500000, SDA_OLED, SCL_OLED, GEOMETRY_128_64, RST_OLED); // addr , freq , i2c group , resolution , rst

// const char* wifiSSID = "WIFI SSID"; 
// const char* wifiPassword = "WIFI PASSWORD"; 
char wifiSSID[] = SECRET_SSID;
char wifiPassword[] = SECRET_PASS;

String openWeatherMapApiKey = API_KEY;
// String city = "London"; //change city name 
// Uso latitud y longitud para solicitar el punto del mundo que quiero en vez del nombre de la ciudad
String latitude = LAT;
String longitud = LON;

String jsonBuffer;

void setup() { 
    Serial.begin(115200);
    WiFi.begin(wifiSSID, wifiPassword);
    Serial.println("Connecting to WiFi...");
    
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nConnected to WiFi network. IP Address: " + WiFi.localIP().toString());
        
    //  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    //   Serial.println(F("SSD1306 allocation failed")); 
    //   for (;;); 
    //  } 

    //  display.clearDisplay();
    // Inicialización del display en vez de las líneas anteriores
    VextON();
    delay(100);
    display.setContrast(255);
    display.init();
    display.clear();
    display.display();
    display.drawString(0,0,"Hola mundirigillo");
    display.display();
    delay(1000);

    // display.setFont(ArialMT_Plain_10);
}

void loop() {
    if (WiFi.status() == WL_CONNECTED) {
        String serverPath = "http://api.openweathermap.org/data/2.5/weather?lat=" + latitude + "&lon=" + longitud + "&appid=" + openWeatherMapApiKey + "&units=metric";
        // String serverPath = "http://api.openweathermap.org/data/2.5/weather?q=" + city + "," + countryCode + "&APPID=" + openWeatherMapApiKey + "&units=metric";
        Serial.println(serverPath);
        jsonBuffer = httpGETRequest(serverPath.c_str());
        Serial.println(jsonBuffer);
        JSONVar weatherData = JSON.parse(jsonBuffer); 
        if (JSON.typeof(weatherData) == "undefined") {
            Serial.println("Parsing input failed!");
            return;
        }
        Serial.print("JSON object = ");
        Serial.println(weatherData);
        Serial.print("City: ");
        Serial.println(weatherData["name"]);
        Serial.print("Temperature: ");
        Serial.println(weatherData["main"]["temp"]);
        Serial.print("Pressure: ");
        Serial.println(weatherData["main"]["pressure"]);
        Serial.print("Humidity: ");
        Serial.println(weatherData["main"]["humidity"]);
        Serial.print("Wind Speed: ");
        Serial.println(weatherData["wind"]["speed"]);
        
        // display.clearDisplay();
        display.clear();
        // display.setTextAlignment(TEXT_ALIGN_RIGHT);

        // display.setTextSize(1);

        // display.setFont(ArialMT_Plain_10);

        // display.setTextColor(SSD1306_WHITE);
        
        // display.setColor(WHITE);
        
        // display.setCursor(0, 0);
        // En principio no defino donde comienzo a escribir, veré en la próxima vuelta si puedo definirlo
        // display.print("\nCity: ");
        // display.println(weatherData["sys"]["name"]);
        display.drawString(0,0,"City: " + String(weatherData["name"]));
        long temp = (long) weatherData["main"]["temp"];
        display.drawString(0,INTERLINE*1,"Temperature: " + String(temp));
        int pres = (int) weatherData["main"]["pressure"];
        display.drawString(0,INTERLINE*2,"Pressure: " + String(pres));
        int hum = (int) weatherData["main"]["humidity"];
        display.drawString(0,INTERLINE*3,"Humidity: " + String(hum));
        long wind_s = (long) weatherData["wind"]["speed"];
        display.drawString(0,INTERLINE*4,"Wind Speed: " + String(wind_s));
        int time_var = (int) weatherData["dt"];
        display.drawString(0,INTERLINE*5,"time acq: " + formatUnixToDMYHM(time_var));
        // display.print("\nTemperature: ");
        // display.println(weatherData["main"]["temp"]);
        // display.print("\nPressure: ");
        // display.println(weatherData["main"]["pressure"]);
        // display.print("\nHumidity: ");
        // display.println(weatherData["main"]["humidity"]);
        // display.print("\nWind Speed: ");
        // display.println(weatherData["wind"]["speed"]);
        display.display();
    } else {
        Serial.println("WiFi Disconnected");
    }
    delay(100000);
}

String httpGETRequest(const char* serverName) {
    WiFiClient client;
    HTTPClient http;
    http.begin(client, serverName);
    int httpResponseCode = http.GET();
    String payload = "{}";
    
    if (httpResponseCode > 0) {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
        
        payload = http.getString();
        
    } else {
        Serial.print("HTTP Request failed. Error code: ");
        Serial.println(httpResponseCode);
        
    }
    http.end();
    
    return payload;
}


String formatUnixToDMYHM(uint32_t unixSeconds) {
  tmElements_t tm;
  breakTime((time_t)unixSeconds, tm);

  char buf[20];
  snprintf(buf, sizeof(buf), "%02d/%02d/%04d %02d:%02d",
           tm.Day, tm.Month, tm.Year + 1970,
           tm.Hour, tm.Minute);

  return String(buf);
}


void VextON(void)
{
  pinMode(Vext,OUTPUT);
  digitalWrite(Vext, LOW);
}