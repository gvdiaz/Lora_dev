# Apuntes sobre lectura de contenido de carpeta "code"
## Repositorio habilitado por ingreso de código CHIP ID

### Fecha: 2025-11-04
### Autor: Gustavo V. Diaz

### Revisión de contenido de carpeta **WiFi_LoRa_32_V3**

```
Heltec LoRa 32 V3 Documentation Package Analysis
📦 Complete Folder Structure
text

📦 WiFi_LoRa_32_V3/
├── 📄 HTIT-WB32LA(F)_V3.1_Schematic_Diagram.pdf
├── 🖼️ HTIT-WB32LA(F)_V3.png
├── 📄 HTIT-WB32LA(F)_V3_Schematic_Diagram.pdf
├── 📄 HTIT-WB32LA_V3(Rev1.1).pdf
├── 📄 HTIT-WB32LA_V3.2.pdf
├── 📁 OLED_TEST/
│   └── 📦 LORA32_OLED (1).zip
├── 🖼️ Wi-Fi_LoRa32_V3.2_Pinmap.png
├── 🎨 WiFi_LoRa32_V3.dwg (AutoCAD file)
├── 📄 WiFi_LoRa_32_V3.2_Schematic_Diagram.pdf
└── 📁 code/
    ├── 📦 LORA32_OLED.zip
    ├── 📦 Lora32_V3_factest_HF.zip
    └── 📦 meshtastic_wifi_lora_32_V3.zip
```

Technical Documents

    Schematic Diagrams (4 PDFs) - Circuit designs for different board revisions

    Pinout Maps (2 images) - GPIO pin assignments and board layout

    Technical Drawings (.dwg) - Mechanical/PCB layout in AutoCAD format
    
Firmware & Code Packages

    OLED_TEST/ - Display testing utilities and examples

    code/ - Contains 3 main firmware packages for different use cases

#### 💾 Firmware Packages Details
```
Located in /code/ directory:
Package                         Purpose
LORA32_OLED.zip                 Basic OLED display code and examples
Lora32_V3_factest_HF.zip	    Factory test firmware for hardware validation
meshtastic_wifi_lora_32_V3.zip	Meshtastic firmware - Popular LoRa mesh networking platform
```

#### Additional Test Utilities:

```
OLED_TEST/LORA32_OLED (1).zip - Additional display testing tools
```

#### Comando para habilitar pantalla

* Me muevo hacia la carpeta que contiene el sketch habilitador
```bash
cd WiFi_LoRa_32_V3/code/Lora32_V3_factest_HF/Lora32_V3_HF/
```
* Antes necesito instalar esptool
```bash
pip3 install esptool
```
* Comando para habilitar pantalla (graba sketch de fábrica, aparentemente)
```bash
esptool --chip esp32s3 --port "/dev/ttyUSB0" --baud 921600 --before default-reset --after hard-reset write-flash -z --flash-mode keep --flash-freq keep --flash-size keep 0x0 "Lora32_V3_HF.ino.bootloader.bin" 0x8000 "Lora32_V3_HF.ino.partitions.bin" 0xe000 "boot_app0.bin" 0x10000 "Lora32_V3_HF.ino.bin"
```
* Si este código se grabó correctamente la pantalla debería volver a funcionar. En mí caso funcionó correctamente.

---

## Entendimiento y pruebacódigo "Lora32_V3_HF.ino"

Enumeración de tareas,

2. Compilar código
3. Grabar código
1. Comprender código

**Compilar código descripción**
fecha: 06/11/2025
hora: 06:36

Para esta tarea hice lo siguiente,

1. Abrí código "Lora32_V3_HF.ino" en arduino IDE
2. Configuré la red WiFi de casa en el código.
2. La primera vez que intenté compilar me devolvió un error sobre una función del WiFi. En el sketch original dice: `WiFi.setAutoConnect(true);`y me pidió que lo cambie a `WiFi.setAutoReconnect(true);`
2. Intenté compilar nuevamente pero me devolvió lo siguiente:

```
Library Heltec ESP32 Dev-Boards has been declared precompiled:
Using precompiled library in /home/negrete/Arduino/libraries/Heltec_ESP32_Dev-Boards/src/esp32s3
/home/negrete/.arduino15/packages/Heltec-esp32/tools/esp-xs3/2302/bin/../lib/gcc/xtensa-esp32s3-elf/12.2.0/../../../../xtensa-esp32s3-elf/bin/ld: /home/negrete/.cache/arduino/sketches/DEE60EB27A82D11F668D960B34D228A7/sketch/Lora32_V3_HF.ino.cpp.o:(.literal._Z5setupv+0x8): undefined reference to `ex_32k_start_cnt'
collect2: error: ld returned 1 exit status
exit status 1

Compilation error: exit status 1
```
A lo cual le consulté a deepseek cual era el problema y me respondió que faltaba la declaración de una variable para el clock externo 'ex_32k_start_cnt'. Lo cual definí al principio de código,
```
// ADD THIS LINE to fix the error
uint32_t ex_32k_start_cnt = 0;
```
 y logró compilar y grabar el micro.

 **Comprensión de código según deepseek**

```
1. Serial.begin(115200)
   ↓
2. Check 32kHz crystal (if fails → display error & halt)
   ↓
3. Mcu.begin() - Initialize microcontroller
   ↓
4. Get ESP32 Chip ID
   ↓
5. Create User Key monitoring task (checkUserkey)
   ↓
6. Turn on OLED power (VextON)
   ↓
7. Initialize OLED display
   ↓
8. Show frequency info on OLED
   ↓
9. Show logo for 1 second
   ↓
10. lora_init() - Initialize LoRa radio
   ↓
11. WIFISetUp() - Connect to WiFi
   ↓
12. WiFi.disconnect() & set to station mode
   ↓
13. WIFIScan(1) - Scan for WiFi networks
   ↓
14. Show LoRa mode on OLED
   ↓
15. Initialize LED pin
```
*Descripción lógica LoRa*

Indica que tiene dos modos de operación,

* Mode 0 (Default): Ping-Pong test between two devices

```
STATE_TX → Send ChipID → Wait → STATE_RX → Receive → Validate → Repeat
```
* Mode 1: Manual test mode (activated by long button press)

```
STATE_RX → Receive any packet → STATE_TX → Echo back with RSSI
```
* LoRa State Machine:

```
STATE_TX: Send packet → Switch to STATE_RX
STATE_RX: Listen for packet → Process received data  
LOWPOWER: Wait state
```