### Registro actividades

#### Objetivo
Conectar el dispositivo Wifi LoRa 32 de heltec con el gateway usando protocolo OTAA (over the air activation)

#### Tipos de logs
[BUGFIX], [FEATURE], [REFACTOR], [HOTFIX], [DEPLOY], [DECISION], [TEST]

---

### [2025-10-31] [06:24] - [DECISION] Creación de archivo de referencia para métodos y definiciones de Heltec LoRa 32

**Acción:** DRecopilo en un solo archivo la descripción de variables y funciones que voy a necesitar para generar la lectura de datos por parte del gateway

**Racional:** Todavía no investigué esta documentación para poder controlar el módulo y lograr el objetivo de reportar variables al gateway

**Cambios:**
*   `./Actividades/En_curso/LoRa_32_ref.md` - Archivo que contiene el resumen de lo que entienda en la documentación ofical de Heltec

**Contexto/Notas:** [Link de fuente Heltec](https://docs.heltec.org/general/index.html) <!-- Commit: [a1b2c3d](link-to-commit) --> 

---

---

### [2025-10-30] [06:26] - [DECISION] Lectura de documentación para poder repotar variables en gateway SenseCAP

**Acción:** Lograr enviar y visualizar variables a gateway SenseCAP

**Racional:** Habiendo podido activar el módulo en el gateway con las credenciales devEUI y APPkey continuo leyendo documentación de Heltec para lograr reportar variables cada una hora

**Cambios:**
*   `ningún nombre por el momento` - Descripción de archivo

**Contexto/Notas:**

[Docs generales de módulo Heltec](https://docs.heltec.org/general/index.html) <!-- Commit: [a1b2c3d](link-to-commit) --> 

---

---

### [2025-1030] [06:00] - [TEST] Comunicación entre gateway y nodo HELTEC

**Acción:** Registro de activación de nodo Heltec en gateway SenseCAP

**Racional:** El día de ayer pude activar el nodo HELTEC en el gateway SenseCAP. Por el momento solo se pudo activar. Lo posterior sería reportar alguna variable y visualizarla a través del gateway.

**Cambios:**
*   `./Scripts/LoRaWAN_arduino.ino` - Archivo base para probar activación con gateway -> Probada exitosamente el 29/10/2025

**Contexto/Notas:** 
[Link a sketch base](https://github.com/HelTecAutomation/Heltec_ESP32/blob/master/examples/LoRaWAN/LoRaWanOLED/LoRaWanOLED.ino)

---

---

### [2025-10-25] [15:07] - [DECISION] Instalación de android IDE para pc de casa

**Acción:** Redactar limpieza e instalación de android IDE para programar placa LoRa 32 de Heltec

**Racional:** Poder conectar gateway con un dispositivo controlado

**Cambios:**
*   `./Instalacion_arduino_LoRa.txt` - Archivo de texto que describe las instrucciones que seguí para limpiar e instalar nuevamente android IDE

**Contexto/Notas:**  <!-- Commit: [a1b2c3d](link-to-commit) --> 

---

---

### [2025-10-24] [07:30] - [FEATURE] Links base

**Acción:** Dejo registro de links necesarios o base en los cuales me baso para programar dispositivo wifi lora 32 de heltec

**Racional:** Tener centralizados los recursos utilizados para proyecto

**Cambios:**
*   `./resource_log.md` - Descripción de archivo

**Contexto/Notas:** Recomendado por deepseek como "Categorized Resource Log" <!-- Commit: [a1b2c3d](link-to-commit) --> 

---

---

### [2025-10-24] [07:16] - [DECISION] Uso de log para registrar actividades

**Acción:** Pedido a deepseek que me recomiende tipos de registros

**Racional:** Dejar registro de actividades desde el principio del desarrollo

**Cambios:**
*   `./Activity_log.md` - Creación de archivo para registrar actividades

**Contexto/Notas:** Comienzo a dejar registro de actividades con ayuda de consulta a deepseek. <!-- comentario --> 

---

Registro general

---

### [fecha] [hora] - [Tipo_log] Nombre de log

**Acción:** Descripción de acción

**Racional:** Racional de acción

**Cambios:**
*   `archivo_creado/modificado` - Descripción de archivo

**Contexto/Notas:** Para guardar links necesarios o descripciones no previstas <!-- Commit: [a1b2c3d](link-to-commit) --> 

---