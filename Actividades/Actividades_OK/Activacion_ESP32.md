## Título: Activación de módulo heltec LoRa32
## Autor: Gustavo V. Diaz
## Fecha: 23/04/2026
## Descripción de problemática:

Probando el dispositivo encontré que el monitoreo reportaba el siguiente mensaje,

```
Please provide a correct license! For more information:
http://www.heltec.cn/search/
ESP32ChipID=xxxxxxxxxxxxxxxx
```

Consulté a copilot por este problema y me contestó lo siguiente,

```
I am trying to program a device LoRa 32 from heltec. But every time that I try to program the device the monitor prints this string,
Please provide a correct license! For more information:
http://www.heltec.cn/search/
ESP32ChipID=xxxxxxxxxxxxx
```
Copilot said:
Copilot

Ese mensaje no es un error de “programación” del ESP32 en sí: indica que el firmware/biblioteca de Heltec que estás usando para LoRa/LoRaWAN está comprobando una licencia asociada al Chip ID, y no la encuentra en la flash (o no es válida). Heltec documenta que la licencia se genera a partir del Chip ID y que, aunque suele venir grabada de fábrica, si borras/reescribes la flash puede ser necesario reactivarla.heltec

Tu Chip ID ya lo tienes: ESP32ChipID = xxxxxxxxxxxxxx
Qué hacer (paso a paso, lo más directo)
1. Obtener la licencia (32 caracteres) con tu Chip ID

En la documentación oficial indican que debes ir a https://resource.heltec.cn/search, introducir el Chip ID de 12 dígitos y guardar la licencia de 32 bits que te devuelve.heltecy 1 más

    Nota: el enlace viejo que imprime el ejemplo (http://www.heltec.cn/search/) suele redirigir o estar desactualizado; el portal actual que cita Heltec es resource.heltec.cn/search.heltecy 1 más

2. Grabar la licencia en la placa (**método recomendado: comando AT**)

Heltec explica que una forma de activarla es enviar por el monitor serie el comando:

AT+CDKEY=xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

donde x... es tu licencia en una sola tira de 32 caracteres, sin 0x, sin comas y sin espacios.heltecy 1 más

Ejemplo de formato (tal como lo documentan): si te dieran algo como
0x12345678, 0x12345678, 0x12345678, 0x12345678
entonces enviarías:
AT+CDKEY=12345678123456781234567812345678

Cuando esté bien, la documentación indica que el puerto serie debería mostrar un mensaje tipo “The board is active”.heltec
3. Alternativa: meter la licencia en el código (si tu ejemplo lo soporta)

En algunos ejemplos de LoRa/LoRaWAN de Heltec hay un “hueco” para pegar la licencia en el sketch y subirlo. Heltec menciona que en algunos códigos la interfaz de licencia está reservada y se puede copiar allí.
Aun así, hay reportes de usuarios indicando que, en ciertos casos, la activación por código no funcionó y el AT+CDKEY fue lo que lo resolvió.
Por qué te pasa (causas típicas)

    Se borró la flash (por “Erase flash”, por cambiar firmware, o por flashear otra cosa). Heltec indica que una vez activada no hace falta reactivarla salvo que borres
    Si previamente flasheaste algo como Meshtastic, hay gente que reporta que eso puede sobrescribir la zona donde iba la licencia y reaparece el mensaje.youtube

Si la web NO te devuelve licencia para tu Chip ID

El propio portal de Heltec indica que algunas placas antiguas o algunos ChipID pueden no estar en su base de datos, y en ese caso recomiendan escribir a soporte (support@heltec.cn) aportando prueba de que la placa es original para que te regeneren una.heltec
Consejo rápido para evitar el problema en el futuro

## Conclusioń

Habiendo seguido las instrucciones pude reactivar el dispositivo y volvió a funcionar correctamente.
