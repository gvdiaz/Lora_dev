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

