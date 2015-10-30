# Afficheur LED 32x32 disponible au Fablab

Base information: "RGB Panel Hookup Guide"
https://learn.sparkfun.com/tutorials/rgb-panel-hookup-guide

- Arduino sketch

ESP_32x32.ino 
Support affichage, connection internet en Wifi (2 r�seau possible: perso / fablab par ex)
Recup�re l'heure en NTP
Affiche les messages publi�s par les utilisateurs (PubNub), grace � l'appli Android (APK)

- ESP-12e

Sch�ma disponible PDF
Attention � l'alimentation:
matrice en 5V (prise USB par ex)
ESP en 3.3V avec r�gulateur + condensateur 100�F.

http://esp8266.ru/esp8266-pin-register-strapping/

GPIO 0,2,4,5, 12-16 + 9-10 + 1,3 (USART)

GPIO9-10: 
http://smarpl.com/content/esp8266-esp-201-module-freeing-gpio9-and-gpio10


http://www.instructables.com/id/ARDUINO-SOLAR-CHARGE-CONTROLLER-Version-30/

- Application Android

Version tr�s basique, APK dispo