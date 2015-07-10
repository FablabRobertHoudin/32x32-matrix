EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:special
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:arduino_shieldsNCL
LIBS:ArduinoUno-cache
EELAYER 27 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Arduino Uno LED 32x32 matrix"
Date "12 jun 2015"
Rev "1.0"
Comp "Fablab Robert-Houdin"
Comment1 "Emmanuel GOUDOT"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L ARDUINO_SHIELD U1
U 1 1 5576CDE8
P 7700 5200
F 0 "U1" H 7350 6150 60  0000 C CNN
F 1 "Arduino Uno" H 7750 4250 60  0000 C CNN
F 2 "" H 7700 5200 60  0000 C CNN
F 3 "" H 7700 5200 60  0000 C CNN
	1    7700 5200
	1    0    0    -1  
$EndComp
$Comp
L CONN_8X2 P1
U 1 1 5576CE37
P 9900 5200
F 0 "P1" H 9900 5650 60  0000 C CNN
F 1 "32x32 RGB panel" V 9900 5200 50  0000 C CNN
F 2 "" H 9900 5200 60  0000 C CNN
F 3 "" H 9900 5200 60  0000 C CNN
	1    9900 5200
	1    0    0    -1  
$EndComp
Text GLabel 9500 4850 0    60   Input ~ 0
R0
Text GLabel 10300 4850 2    60   Input ~ 0
G0
Text GLabel 9500 4950 0    60   Input ~ 0
B0
Text GLabel 10300 4950 2    60   Input ~ 0
GND
Text GLabel 9500 5050 0    60   Input ~ 0
R1
Text GLabel 10300 5050 2    60   Input ~ 0
G1
Text GLabel 9500 5150 0    60   Input ~ 0
B1
Text GLabel 10300 5150 2    60   Input ~ 0
GND
Text GLabel 9500 5250 0    60   Input ~ 0
A
Text GLabel 10300 5250 2    60   Input ~ 0
B
Text GLabel 9500 5350 0    60   Input ~ 0
C
Text GLabel 10300 5350 2    60   Input ~ 0
D
Text GLabel 9500 5450 0    60   Input ~ 0
CLK
Text GLabel 10300 5450 2    60   Input ~ 0
STB
Text GLabel 9500 5550 0    60   Input ~ 0
OE
Text GLabel 10300 5550 2    60   Input ~ 0
GND
Text GLabel 8650 5800 2    60   Input ~ 0
R0
Text GLabel 8650 5700 2    60   Input ~ 0
G0
Text GLabel 8650 5600 2    60   Input ~ 0
B0
Text GLabel 6750 5200 0    60   Input ~ 0
GND
Text GLabel 8650 5500 2    60   Input ~ 0
R1
Text GLabel 8650 5400 2    60   Input ~ 0
G1
Text GLabel 8650 5300 2    60   Input ~ 0
B1
Text GLabel 6750 5500 0    60   Input ~ 0
A
Text GLabel 6750 5600 0    60   Input ~ 0
B
Text GLabel 6750 5700 0    60   Input ~ 0
C
Text GLabel 6750 5800 0    60   Input ~ 0
D
Text GLabel 8650 4800 2    60   Input ~ 0
CLK
Text GLabel 8650 4900 2    60   Input ~ 0
STB
Text GLabel 8650 5000 2    60   Input ~ 0
OE
Text Notes 7000 2800 0    60   ~ 0
// For Arduino UNO\n// DATA: R1, G1, B1, R2, G2, B2 hard-wired on PD2~PD7\n// ADDR: A, B, C, D hard-wired on PC0~PC3\n// CTRL: CLK, OE, LAT hard-wired on PB0~PB2 and LED PB5\n#define CTRL_CLK_PIN (1 << 0)\n#define CTRL_OE_PIN (1 << 1)\n#define CTRL_LAT_PIN (1 << 2)\n#define CTRL_LED_PIN (1 << 5)
$EndSCHEMATC
