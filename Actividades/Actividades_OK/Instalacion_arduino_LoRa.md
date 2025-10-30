# Log de limpieza de arduino IDE para comenzar una instalación limpia

## Instrucciones que seguí dadas por deepseek

### Desinstalación de arduino

´´´
sudo apt remove arduino
sudo apt purge arduino
´´´

# Remove user configuration

´´´
rm -rf ~/.arduino15
rm -rf ~/.arduino-ide -> no existía
´´´

# Remove local sketches and libraries (optional - backup if needed)

´´´
rm -rf ~/Arduino
rm -rf ~/Documents/Arduino -> no existía
´´´

# Check for any remaining Arduino files

´´´
sudo find / -name "*arduino*" -type f 2>/dev/null
´´´

# Remove any leftover directories

´´´
sudo rm -rf /opt/arduino-*
sudo rm -rf /usr/share/arduino
´´´

# Log de instalación de arduino IDE que saqué del siguiente [link](https://www.arduino.cc/en/software/)

# Bajé el instalador y tuve que instalar en el sistema el siguiente paquete

´´´
sudo apt install libfuse2
´´´

# Y luego pude ejecutar el archivo que bajé (arduino-ide_2.3.6_Linux_64bit.AppImage)

# Ya tengo Arduino ejecutándose, vuelvo al siguiente link para instalar las dependencias de la placa LoRa 32 de Heltec
# [link](https://docs.heltec.org/en/node/esp32/esp32_general_docs/quick_start.html#via-arduino-ide)
# Decido la instalación de "Heltec ESP32 series development framework and library" a través de arduino IDE.

# Antes de ejecutar la instalación quise verificar la conexión con el board, es decir si la pc lo veía con el comando

´´´
lsusb

# Y no lo encontraba. Probé varias opciones recomendas por deepseek pero no podía verlo de ninguna manera. Hasta que me recomendó revisar el cable y cambiándolo logré poder verlo con el comando

# COntinuo instalando el framework y la biblioteca para utilizar arduino IDE
