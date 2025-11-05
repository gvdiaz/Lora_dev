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
