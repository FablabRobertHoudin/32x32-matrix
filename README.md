# Afficheur LED 32x32 disponible au Fablab

Base information: "RGB Panel Hookup Guide"
https://learn.sparkfun.com/tutorials/rgb-panel-hookup-guide

- Arduino sketch

ESP_32x32.ino 
Support affichage, connection internet en Wifi (2 réseau possible: perso / fablab par ex)
Recupère l'heure en NTP
Affiche les messages publiés par les utilisateurs (PubNub), grace à l'appli Android (APK)

- ESP-12e

Schéma disponible PDF
Attention à l'alimentation:
matrice en 5V (prise USB par ex)
ESP en 3.3V avec régulateur + condensateur 100µF.

http://esp8266.ru/esp8266-pin-register-strapping/

GPIO 0,2,4,5, 12-16 + 9-10 + 1,3 (USART)

GPIO9-10: 
http://smarpl.com/content/esp8266-esp-201-module-freeing-gpio9-and-gpio10


http://www.instructables.com/id/ARDUINO-SOLAR-CHARGE-CONTROLLER-Version-30/

- Application Android

Version très basique, APK dispo