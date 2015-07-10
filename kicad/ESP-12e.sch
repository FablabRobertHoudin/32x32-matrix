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
LIBS:ESP8266
LIBS:ESP-12e-cache
EELAYER 27 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "ESP-12e LED 32x32 matrix"
Date "20 jun 2015"
Rev "1.0"
Comp "Fablab Robert-Houdin"
Comment1 "Emmanuel GOUDOT"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L ESP-12E U1
U 1 1 5576D27B
P 6650 5250
F 0 "U1" H 7000 5900 50  0000 C CNN
F 1 "ESP-12E" H 6200 5900 50  0000 C CNN
F 2 "~" H 6650 5250 50  0001 C CNN
F 3 "~" H 6650 5250 50  0001 C CNN
	1    6650 5250
	1    0    0    -1  
$EndComp
$Comp
L CONN_8X2 P1
U 1 1 5576CE37
P 10050 5200
F 0 "P1" H 10050 5650 60  0000 C CNN
F 1 "32x32 RGB panel" V 10050 5200 50  0000 C CNN
F 2 "" H 10050 5200 60  0000 C CNN
F 3 "" H 10050 5200 60  0000 C CNN
	1    10050 5200
	1    0    0    -1  
$EndComp
Text GLabel 9650 4850 0    60   Input ~ 0
R0
Text GLabel 10450 4850 2    60   Input ~ 0
G0
Text GLabel 9650 4950 0    60   Input ~ 0
B0
Text GLabel 10450 4950 2    60   Input ~ 0
GND
Text GLabel 9650 5050 0    60   Input ~ 0
R1
Text GLabel 10450 5050 2    60   Input ~ 0
G1
Text GLabel 9650 5150 0    60   Input ~ 0
B1
Text GLabel 10450 5150 2    60   Input ~ 0
GND
Text GLabel 9650 5250 0    60   Input ~ 0
A
Text GLabel 10450 5250 2    60   Input ~ 0
B
Text GLabel 9650 5350 0    60   Input ~ 0
C
Text GLabel 10450 5350 2    60   Input ~ 0
D
Text GLabel 9650 5450 0    60   Input ~ 0
CLK
Text GLabel 10450 5450 2    60   Input ~ 0
STB
Text GLabel 9650 5550 0    60   Input ~ 0
OE
Text GLabel 10450 5550 2    60   Input ~ 0
GND
Text GLabel 7550 5550 2    60   Input ~ 0
R0
Text GLabel 7550 5450 2    60   Input ~ 0
G0
Text GLabel 7550 5350 2    60   Input ~ 0
B0
Text GLabel 7550 5650 2    60   Input ~ 0
GND
Text GLabel 7550 5250 2    60   Input ~ 0
R1
Text GLabel 7550 5150 2    60   Input ~ 0
G1
Text GLabel 7550 5050 2    60   Input ~ 0
B1
Text GLabel 9100 3150 2    60   Input ~ 0
A
Text GLabel 9100 3250 2    60   Input ~ 0
B
Text GLabel 9100 3350 2    60   Input ~ 0
C
Text GLabel 9100 3450 2    60   Input ~ 0
D
Text GLabel 5750 5350 0    60   Input ~ 0
CLK
Text GLabel 5750 5250 0    60   Input ~ 0
STB
Text GLabel 5750 5450 0    60   Input ~ 0
OE
$Comp
L CONN_2 P2
U 1 1 5576D327
P 7650 4250
F 0 "P2" V 7600 4250 40  0000 C CNN
F 1 "RXTX" V 7700 4250 40  0000 C CNN
F 2 "" H 7650 4250 60  0000 C CNN
F 3 "" H 7650 4250 60  0000 C CNN
	1    7650 4250
	0    -1   -1   0   
$EndComp
$Comp
L +3.3V #PWR01
U 1 1 5576D365
P 10000 3250
F 0 "#PWR01" H 10000 3210 30  0001 C CNN
F 1 "+3.3V" H 10000 3360 30  0000 C CNN
F 2 "" H 10000 3250 60  0000 C CNN
F 3 "" H 10000 3250 60  0000 C CNN
	1    10000 3250
	0    -1   -1   0   
$EndComp
$Comp
L +3.3V #PWR02
U 1 1 5576D383
P 5750 5650
F 0 "#PWR02" H 5750 5610 30  0001 C CNN
F 1 "+3.3V" H 5750 5760 30  0000 C CNN
F 2 "" H 5750 5650 60  0000 C CNN
F 3 "" H 5750 5650 60  0000 C CNN
	1    5750 5650
	0    -1   -1   0   
$EndComp
$Comp
L +3.3V #PWR03
U 1 1 5576D4F0
P 5750 5150
F 0 "#PWR03" H 5750 5110 30  0001 C CNN
F 1 "+3.3V" H 5750 5260 30  0000 C CNN
F 2 "" H 5750 5150 60  0000 C CNN
F 3 "" H 5750 5150 60  0000 C CNN
	1    5750 5150
	0    -1   -1   0   
$EndComp
$Comp
L R R1
U 1 1 5576DF19
P 7900 5800
F 0 "R1" V 7980 5800 40  0000 C CNN
F 1 "10k" V 7907 5801 40  0000 C CNN
F 2 "~" V 7830 5800 30  0000 C CNN
F 3 "~" H 7900 5800 30  0000 C CNN
	1    7900 5800
	1    0    0    -1  
$EndComp
Wire Wire Line
	7550 5550 7900 5550
$Comp
L GND #PWR04
U 1 1 5576DF46
P 7900 6050
F 0 "#PWR04" H 7900 6050 30  0001 C CNN
F 1 "GND" H 7900 5980 30  0001 C CNN
F 2 "" H 7900 6050 60  0000 C CNN
F 3 "" H 7900 6050 60  0000 C CNN
	1    7900 6050
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW2
U 1 1 5576DF87
P 8550 5350
F 0 "SW2" H 8700 5460 50  0000 C CNN
F 1 "Reflash" H 8550 5270 50  0000 C CNN
F 2 "~" H 8550 5350 60  0000 C CNN
F 3 "~" H 8550 5350 60  0000 C CNN
	1    8550 5350
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR05
U 1 1 5576DFAA
P 8850 5350
F 0 "#PWR05" H 8850 5350 30  0001 C CNN
F 1 "GND" H 8850 5280 30  0001 C CNN
F 2 "" H 8850 5350 60  0000 C CNN
F 3 "" H 8850 5350 60  0000 C CNN
	1    8850 5350
	1    0    0    -1  
$EndComp
Wire Wire Line
	7550 4950 7550 4600
Wire Wire Line
	7550 5050 7750 5050
Wire Wire Line
	7750 5050 7750 4600
Wire Wire Line
	8250 5350 7550 5350
Text Notes 3750 4400 0    60   ~ 0
18 GPIO0 (f1) reflash si Gnd\n22 GPIO1 (f4) U0TX (f1)\n17 GPIO2 (f1) U1TX (f3) U0TX (f5)\n21 GPIO3 (f4) U0RX (f1)\n19 GPIO4\n20 GPIO5\nGPIO6 ?\nGPIO7 ? \nGPIO8 ?\n11 GPIO9 ? \n12 GPIO10 ?\nGPIO11 ?\n6 GPIO12\n7 GPIO13\n5 GPIO14\n16 GPIO15\n4 GPIO16\n\n2 GPIO17 ADC
$Comp
L 4040 U3
U 1 1 557C867A
P 8450 3700
F 0 "U3" H 8550 4350 60  0000 C CNN
F 1 "4040" H 8700 3050 60  0000 C CNN
F 2 "" H 8450 3700 60  0000 C CNN
F 3 "" H 8450 3700 60  0000 C CNN
	1    8450 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	5750 5550 4850 5550
Wire Wire Line
	4850 5550 4850 3150
Wire Wire Line
	4850 3150 7800 3150
$Comp
L GND #PWR06
U 1 1 55815705
P 8450 4300
F 0 "#PWR06" H 8450 4300 30  0001 C CNN
F 1 "GND" H 8450 4230 30  0001 C CNN
F 2 "" H 8450 4300 60  0000 C CNN
F 3 "" H 8450 4300 60  0000 C CNN
	1    8450 4300
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR07
U 1 1 55815717
P 8450 3100
F 0 "#PWR07" H 8450 3060 30  0001 C CNN
F 1 "+3.3V" H 8450 3210 30  0000 C CNN
F 2 "" H 8450 3100 60  0000 C CNN
F 3 "" H 8450 3100 60  0000 C CNN
	1    8450 3100
	1    0    0    -1  
$EndComp
$Comp
L CONN_2 P3
U 1 1 55840359
P 10350 3350
F 0 "P3" V 10300 3350 40  0000 C CNN
F 1 "Alim 3.3V" V 10400 3350 40  0000 C CNN
F 2 "" H 10350 3350 60  0000 C CNN
F 3 "" H 10350 3350 60  0000 C CNN
	1    10350 3350
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR08
U 1 1 5576D356
P 10000 3450
F 0 "#PWR08" H 10000 3450 30  0001 C CNN
F 1 "GND" H 10000 3380 30  0001 C CNN
F 2 "" H 10000 3450 60  0000 C CNN
F 3 "" H 10000 3450 60  0000 C CNN
	1    10000 3450
	1    0    0    -1  
$EndComp
$Comp
L CONN_3 K1
U 1 1 5584090E
P 5650 4350
F 0 "K1" V 5600 4350 50  0000 C CNN
F 1 "CONN_3" V 5700 4350 40  0000 C CNN
F 2 "" H 5650 4350 60  0000 C CNN
F 3 "" H 5650 4350 60  0000 C CNN
	1    5650 4350
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5650 4700 5650 5050
Wire Wire Line
	5650 5050 5750 5050
Wire Wire Line
	5750 5150 5550 5150
Wire Wire Line
	5550 5150 5550 4700
$Comp
L GND #PWR09
U 1 1 55840931
P 5750 4700
F 0 "#PWR09" H 5750 4700 30  0001 C CNN
F 1 "GND" H 5750 4630 30  0001 C CNN
F 2 "" H 5750 4700 60  0000 C CNN
F 3 "" H 5750 4700 60  0000 C CNN
	1    5750 4700
	1    0    0    -1  
$EndComp
Wire Wire Line
	9100 3550 7800 3550
Wire Wire Line
	7800 3550 7800 3450
$EndSCHEMATC
