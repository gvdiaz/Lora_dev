# Parametros en "Arduino Tools Menu"

### LoRaWAN DevEUI

You can recognize this is the unique ID (Mac address) of a LoRaWAN node device, this option determines where the DevEUI of the device comes from.

* **CUSTOM**
Use the value defined in the devEui array, which is in the .ino file, Can be any value, but it may conflict with other device, not recommend use in a public LoRaWAN NS.

* **Generate by ChipID**
Generated based on the ESP32’s unique Chip ID.

### LoRaWAN Preamble Length
The length of the preamble in LoRaWAN communication. Just keep the default 8-bit, 16 bit is for Heltec’s single/dual channel gateway.

### LoRaWAN Region
LoRaWAN protocol region definition, strictly follow LoRaWAN™ 1.0.2 Regional Parameters rB, the LoRaWAN Frequency Plans and Regulations by Country/Region also make sense to you.

### LoRaWAN Debug Level
LoRaWAN relevant logs print by serial port.

* **None** – Default.

* **Freq** – Sending/receiving frequency.

* **Freq && DIO** – Sending/receiving frequency, and DIO pin interrupt information.

* **Freq && DIO && PW** – Sending/receiving frequency, DIO pin interrupt information, and low power status.

### Slow Clk Type (only for LoRaWAN)
The clock source of LoRaWAN timer.

* **Internal (default)**
Use ESP32’s internal RTC crystal oscillator.

* **External 32K**
Use external 32.768 KHz crystal oscillator as the timer source, it’s more friendly for low power features.

### Parámetros en el código (por ejemplo en el archivo LoRaWAN_arduino.ino de la carpeta Scripts)

### Lectura de chip id para acceso a recurso de Heltec LoRa 32

Llegué a la página [Get Limited Technical Resources](https://docs.heltec.org/general/view_limited_technical_data.html), y encuentro que para tener acceso a todos los recursos del módulo debo ingresar el chip ID en la siguiente página [web ingreso chip id](https://resource.heltec.cn/search).

En la misma me indica que para obtener el "chip id" debo seguir las instrucciones de la siguiente sección en el siguiente [link](https://docs.heltec.org/general/view_limited_technical_data.html#esp32-lora-series)

En el link indicado encuentro un sketch arduino para leer el chip id el cual guardo en la carpeta de "Scripts" de este proyecto como "./Scripts/GetChipID.ino"

Procedo a cargarlo en el IDE de arduino y ejecutar el código para leer dicho chip id,

1. Bajo código del siguiente [link](https://github.com/HelTecAutomation/Heltec_ESP32/tree/master/examples/ESP32/GetChipID)
2. Cargo código en IDE de arduino
3. Compilo código
4. Cargo código a módulo
5. Leo puerto serie con el "serial monitor" en la opción de "Tools" de IDE.
6. Me devuelve la siguiente cadena,
´´´
This chip has 2 cores
ESP32ChipID=...
ESP32 Chip model = ESP32-S3 Rev 2
´´´
7. Logré bajar la información y lo dejo en la pc del laburo disponible, no así en el repositorio.
