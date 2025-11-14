# Objetivo: Script para lectura de variables meteorológicas y publicación de datos en broker mqtt
# Autor: Gustavo V. Diaz (con ayuda de deepseek)
# Fecha: 14/11/2025

import paho.mqtt.client as mqtt
import requests
import json
import time

# OpenWeatherMap API (get free API key from openweathermap.org)
API_KEY = "your_api_key_here"
CITY = "London"
WEATHER_URL = f"http://api.openweathermap.org/data/2.5/weather?q={CITY}&appid={API_KEY}&units=metric"

def get_weather():
    response = requests.get(WEATHER_URL)
    data = response.json()
    return {
        "city": data["name"],
        "temperature": data["main"]["temp"],
        "humidity": data["main"]["humidity"],
        "pressure": data["main"]["pressure"],
        "description": data["weather"][0]["description"],
        "wind_speed": data["wind"]["speed"],
        "timestamp": time.strftime("%Y-%m-%dT%H:%M:%SZ", time.gmtime())
    }

client = mqtt.Client()
client.connect("broker.hivemq.com", 1883, 60)

while True:
    weather_data = get_weather()
    client.publish("weather/london", json.dumps(weather_data))
    print(f"Published: {weather_data}")
    time.sleep(300)  # Update every 5 minutes