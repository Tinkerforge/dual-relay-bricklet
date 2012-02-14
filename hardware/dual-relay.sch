EESchema Schematic File Version 2  date Fr 30 Dez 2011 10:01:38 CET
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
LIBS:tinkerforge
LIBS:dual-relay-cache
EELAYER 25  0
EELAYER END
$Descr A4 11700 8267
encoding utf-8
Sheet 1 1
Title "Dual Relay Bricklet"
Date "28 dec 2011"
Rev "1.1"
Comp "Tinkerforge GmbH"
Comment1 "Licensed under CERN OHL v.1.1"
Comment2 "Copyright (©) 2011, B.Nordmeyer <bastian@tinkerforge.com>"
Comment3 ""
Comment4 ""
$EndDescr
Text Notes 550  7200 0    40   ~ 0
Copyright Tinkerforge GmbH 2011.\nThis documentation describes Open Hardware and is licensed under the\nCERN OHL v. 1.1.\nYou may redistribute and modify this documentation under the terms of the\nCERN OHL v.1.1. (http://ohwr.org/cernohl). This documentation is distributed\nWITHOUT ANY EXPRESS OR IMPLIED WARRANTY, INCLUDING OF\nMERCHANTABILITY, SATISFACTORY QUALITY AND FITNESS FOR A\nPARTICULAR PURPOSE. Please see the CERN OHL v.1.1 for applicable\nconditions\n
NoConn ~ 7700 5600
NoConn ~ 8100 5600
Wire Wire Line
	8100 5700 8350 5700
Wire Wire Line
	7700 5400 7700 5500
Wire Wire Line
	8100 5500 8800 5500
Wire Wire Line
	7700 3500 7600 3500
Wire Wire Line
	8100 3300 8800 3300
Wire Wire Line
	3400 2250 3400 2650
Wire Wire Line
	3400 2650 3250 2650
Wire Wire Line
	3500 2700 3500 2550
Wire Wire Line
	3500 2550 3250 2550
Wire Wire Line
	10550 4150 10200 4150
Wire Wire Line
	10200 4150 10200 4100
Wire Wire Line
	10200 4100 8350 4100
Wire Wire Line
	8350 4100 8350 4400
Wire Wire Line
	10550 3800 9850 3800
Wire Wire Line
	9850 3800 9850 2750
Wire Wire Line
	10550 3550 10100 3550
Wire Wire Line
	10100 3550 10100 1850
Wire Wire Line
	10100 1850 8350 1850
Wire Wire Line
	8350 1850 8350 2200
Wire Wire Line
	8800 2050 8800 2250
Connection ~ 8800 2150
Wire Wire Line
	8950 2150 8550 2150
Wire Wire Line
	8550 2150 8550 2250
Wire Wire Line
	3250 3150 3550 3150
Wire Wire Line
	3400 2950 3400 4200
Connection ~ 4400 3900
Wire Wire Line
	4450 3900 4400 3900
Wire Wire Line
	4850 4050 4850 3900
Wire Wire Line
	4400 4300 4850 4300
Wire Wire Line
	3250 2750 3600 2750
Connection ~ 3500 4100
Wire Wire Line
	3600 4000 3500 4000
Wire Wire Line
	3500 4000 3500 4400
Wire Wire Line
	3500 4300 3600 4300
Wire Wire Line
	2800 3600 2800 3500
Wire Wire Line
	3400 2950 3250 2950
Wire Wire Line
	3400 4200 3600 4200
Wire Wire Line
	3500 4100 3600 4100
Connection ~ 3500 4300
Wire Wire Line
	3250 2850 3600 2850
Wire Wire Line
	4400 4200 4850 4200
Wire Wire Line
	4400 3900 4400 4000
Wire Wire Line
	3250 3050 3550 3050
Wire Wire Line
	8800 2750 8950 2750
Wire Wire Line
	8950 2450 8950 2200
Wire Wire Line
	8950 2200 8350 2200
Wire Wire Line
	8800 3300 8800 2650
Connection ~ 8650 3300
Connection ~ 8800 2750
Wire Wire Line
	8650 3950 8650 3700
Wire Wire Line
	8650 6150 8650 5900
Connection ~ 8800 4950
Connection ~ 8650 5500
Wire Wire Line
	8800 5500 8800 4850
Wire Wire Line
	8350 4400 8950 4400
Wire Wire Line
	8950 4400 8950 4650
Wire Wire Line
	8800 4950 8950 4950
Wire Wire Line
	8550 4450 8550 4350
Wire Wire Line
	8550 4350 8950 4350
Connection ~ 8800 4350
Wire Wire Line
	8800 4250 8800 4450
Wire Wire Line
	9850 2150 10400 2150
Wire Wire Line
	10400 2150 10400 3450
Wire Wire Line
	10400 3450 10550 3450
Wire Wire Line
	9850 4350 9850 3900
Wire Wire Line
	9850 3900 10550 3900
Wire Wire Line
	9850 4950 10200 4950
Wire Wire Line
	10200 4950 10200 4250
Wire Wire Line
	10200 4250 10550 4250
Wire Wire Line
	4250 2450 4350 2450
Wire Wire Line
	3250 2450 3550 2450
Wire Wire Line
	7700 3300 7700 3200
Wire Wire Line
	8550 2650 8550 3200
Wire Wire Line
	8550 3200 8100 3200
Wire Wire Line
	8100 3500 8350 3500
Wire Wire Line
	8100 5400 8550 5400
Wire Wire Line
	8550 5400 8550 4850
Wire Wire Line
	7700 5700 7600 5700
$Comp
L R_PACK4 RP2
U 1 1 4DBA1863
P 7900 5750
F 0 "RP2" H 7900 6200 40  0000 C CNN
F 1 "1k" H 7900 5700 40  0000 C CNN
F 2 "741X083" H 7900 5750 60  0001 C CNN
	1    7900 5750
	1    0    0    -1  
$EndComp
NoConn ~ 7700 3400
NoConn ~ 8100 3400
$Comp
L R_PACK4 RP1
U 1 1 4DBA17D6
P 7900 3550
F 0 "RP1" H 7900 4000 40  0000 C CNN
F 1 "1k" H 7900 3500 40  0000 C CNN
F 2 "741X083" H 7900 3550 60  0001 C CNN
	1    7900 3550
	-1   0    0    -1  
$EndComp
$Comp
L FILTER FB1
U 1 1 4CEA6DB6
P 3900 2450
F 0 "FB1" H 3900 2600 60  0000 C CNN
F 1 "FB" H 3900 2350 60  0000 C CNN
F 2 "0603" H 3900 2450 60  0001 C CNN
	1    3900 2450
	1    0    0    -1  
$EndComp
$Comp
L AKL_5_2 J3
U 1 1 4CEA6B97
P 10750 4200
F 0 "J3" H 10850 4200 60  0000 C CNN
F 1 "AKL_5_2" H 10350 4200 60  0000 C CNN
F 2 "AKL_5_2" H 10750 4200 60  0001 C CNN
	1    10750 4200
	1    0    0    -1  
$EndComp
$Comp
L AKL_5_2 J2
U 1 1 4CEA6B95
P 10750 3850
F 0 "J2" H 10850 3850 60  0000 C CNN
F 1 "AKL_5_2" H 10350 3850 60  0000 C CNN
F 2 "AKL_5_2" H 10750 3850 60  0001 C CNN
	1    10750 3850
	1    0    0    -1  
$EndComp
$Comp
L AKL_5_2 J1
U 1 1 4CEA6B91
P 10750 3500
F 0 "J1" H 10850 3500 60  0000 C CNN
F 1 "AKL_5_2" H 10350 3500 60  0000 C CNN
F 2 "AKL_5_2" H 10750 3500 60  0001 C CNN
	1    10750 3500
	1    0    0    -1  
$EndComp
$Comp
L NPN Q2
U 1 1 4CEA6B6F
P 8550 5700
F 0 "Q2" H 8550 5550 50  0000 R CNN
F 1 "BC817" H 8550 5850 50  0000 R CNN
F 2 "SOT23EBC" H 8550 5700 60  0001 C CNN
	1    8550 5700
	1    0    0    -1  
$EndComp
$Comp
L ORWH-SX U3
U 1 1 4CEA6B6E
P 9400 4650
F 0 "U3" H 9000 5100 60  0000 C CNN
F 1 "ORWH-SX" H 9400 4250 60  0000 C CNN
F 2 "ORWH-SX" H 9400 4650 60  0001 C CNN
	1    9400 4650
	1    0    0    -1  
$EndComp
$Comp
L B0520LW-7-F D4
U 1 1 4CEA6B6D
P 8800 4650
F 0 "D4" H 8800 4650 40  0000 C CNN
F 1 "B0520LW-7-F" H 8800 4750 40  0000 C CNN
F 2 "SOD-123" H 8800 4550 60  0001 C CNN
	1    8800 4650
	0    -1   -1   0   
$EndComp
$Comp
L LED D2
U 1 1 4CEA6B6C
P 8550 4650
F 0 "D2" H 8550 4750 50  0000 C CNN
F 1 "LED blue" H 8550 4550 50  0000 C CNN
F 2 "D0603" H 8550 4650 60  0001 C CNN
	1    8550 4650
	0    1    1    0   
$EndComp
$Comp
L +5V #PWR11
U 1 1 4CEA6B6A
P 8800 4250
F 0 "#PWR11" H 8800 4340 20  0001 C CNN
F 1 "+5V" H 8800 4340 30  0000 C CNN
	1    8800 4250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR9
U 1 1 4CEA6B69
P 8650 6150
F 0 "#PWR9" H 8650 6150 30  0001 C CNN
F 1 "GND" H 8650 6080 30  0001 C CNN
	1    8650 6150
	1    0    0    -1  
$EndComp
Text GLabel 7600 3500 0    60   Input ~ 0
OUT2
Text GLabel 7600 5700 0    60   Input ~ 0
OUT1
$Comp
L GND #PWR8
U 1 1 4CEA6AE2
P 8650 3950
F 0 "#PWR8" H 8650 3950 30  0001 C CNN
F 1 "GND" H 8650 3880 30  0001 C CNN
	1    8650 3950
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR5
U 1 1 4CEA6AD6
P 4350 2450
F 0 "#PWR5" H 4350 2540 20  0001 C CNN
F 1 "+5V" H 4350 2540 30  0000 C CNN
	1    4350 2450
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR10
U 1 1 4CEA6AD2
P 8800 2050
F 0 "#PWR10" H 8800 2140 20  0001 C CNN
F 1 "+5V" H 8800 2140 30  0000 C CNN
	1    8800 2050
	1    0    0    -1  
$EndComp
$Comp
L LED D1
U 1 1 4CEA6A3A
P 8550 2450
F 0 "D1" H 8550 2550 50  0000 C CNN
F 1 "LED blue" H 8550 2350 50  0000 C CNN
F 2 "D0603" H 8550 2450 60  0001 C CNN
	1    8550 2450
	0    1    1    0   
$EndComp
$Comp
L B0520LW-7-F D3
U 1 1 4CEA6A34
P 8800 2450
F 0 "D3" H 8800 2450 40  0000 C CNN
F 1 "B0520LW-7-F" H 8800 2550 40  0000 C CNN
F 2 "SOD-123" H 8800 2350 60  0001 C CNN
	1    8800 2450
	0    -1   -1   0   
$EndComp
$Comp
L ORWH-SX U2
U 1 1 4CEA5A1D
P 9400 2450
F 0 "U2" H 9000 2900 60  0000 C CNN
F 1 "ORWH-SX" H 9400 2050 60  0000 C CNN
F 2 "ORWH-SX" H 9400 2450 60  0001 C CNN
	1    9400 2450
	1    0    0    -1  
$EndComp
NoConn ~ 3250 3250
$Comp
L NPN Q1
U 1 1 4CEA4A22
P 8550 3500
F 0 "Q1" H 8550 3350 50  0000 R CNN
F 1 "BC817" H 8550 3650 50  0000 R CNN
F 2 "SOT23EBC" H 8550 3500 60  0001 C CNN
	1    8550 3500
	1    0    0    -1  
$EndComp
Text GLabel 3550 3150 2    60   Output ~ 0
OUT2
Text GLabel 3550 3050 2    60   Output ~ 0
OUT1
$Comp
L GND #PWR7
U 1 1 4CE29748
P 4850 4050
F 0 "#PWR7" H 4850 4050 30  0001 C CNN
F 1 "GND" H 4850 3980 30  0001 C CNN
	1    4850 4050
	1    0    0    -1  
$EndComp
NoConn ~ 4400 4100
$Comp
L DRILL U4
U 1 1 4C6050A5
P 10700 6500
F 0 "U4" H 10750 6550 60  0001 C CNN
F 1 "DRILL" H 10700 6500 60  0000 C CNN
F 2 "Drill" H 10700 6500 60  0001 C CNN
	1    10700 6500
	1    0    0    -1  
$EndComp
$Comp
L DRILL U5
U 1 1 4C6050A2
P 10700 6700
F 0 "U5" H 10750 6750 60  0001 C CNN
F 1 "DRILL" H 10700 6700 60  0000 C CNN
F 2 "Drill" H 10700 6700 60  0001 C CNN
	1    10700 6700
	1    0    0    -1  
$EndComp
$Comp
L DRILL U7
U 1 1 4C60509F
P 11050 6700
F 0 "U7" H 11100 6750 60  0001 C CNN
F 1 "DRILL" H 11050 6700 60  0000 C CNN
F 2 "Drill" H 11050 6700 60  0001 C CNN
	1    11050 6700
	1    0    0    -1  
$EndComp
$Comp
L DRILL U6
U 1 1 4C605099
P 11050 6500
F 0 "U6" H 11100 6550 60  0001 C CNN
F 1 "DRILL" H 11050 6500 60  0000 C CNN
F 2 "Drill" H 11050 6500 60  0001 C CNN
	1    11050 6500
	1    0    0    -1  
$EndComp
NoConn ~ 3250 3350
$Comp
L C C1
U 1 1 4C5FD6ED
P 4650 3900
F 0 "C1" V 4750 3900 50  0000 L CNN
F 1 "100nF" V 4500 3900 50  0000 L CNN
F 2 "0603" H 4650 3900 60  0001 C CNN
	1    4650 3900
	0    -1   -1   0   
$EndComp
Text GLabel 4850 4300 2    60   Input ~ 0
SDA
Text GLabel 4850 4200 2    60   Input ~ 0
SCL
Text GLabel 3600 2850 2    60   Output ~ 0
SDA
Text GLabel 3600 2750 2    60   Output ~ 0
SCL
$Comp
L VCC #PWR6
U 1 1 4C5FD35E
P 4400 3900
F 0 "#PWR6" H 4400 4000 30  0001 C CNN
F 1 "VCC" H 4400 4000 30  0000 C CNN
	1    4400 3900
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR4
U 1 1 4C5FD34E
P 3500 4400
F 0 "#PWR4" H 3500 4400 30  0001 C CNN
F 1 "GND" H 3500 4330 30  0001 C CNN
	1    3500 4400
	1    0    0    -1  
$EndComp
$Comp
L CAT24C U1
U 1 1 4C5FD337
P 4000 4400
F 0 "U1" H 3850 4900 60  0000 C CNN
F 1 "M24C64" H 4000 4400 60  0000 C CNN
F 2 "TSSOP8" H 4000 4400 60  0001 C CNN
	1    4000 4400
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR2
U 1 1 4C5FCFB4
P 3400 2250
F 0 "#PWR2" H 3400 2350 30  0001 C CNN
F 1 "VCC" H 3400 2350 30  0000 C CNN
	1    3400 2250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR3
U 1 1 4C5FCF5E
P 3500 2700
F 0 "#PWR3" H 3500 2700 30  0001 C CNN
F 1 "GND" H 3500 2630 30  0001 C CNN
	1    3500 2700
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR1
U 1 1 4C5FCF4F
P 2800 3600
F 0 "#PWR1" H 2800 3600 30  0001 C CNN
F 1 "GND" H 2800 3530 30  0001 C CNN
	1    2800 3600
	1    0    0    -1  
$EndComp
$Comp
L CON-SENSOR P1
U 1 1 4C5FCF27
P 2800 2900
F 0 "P1" H 2550 3450 60  0000 C CNN
F 1 "CON-SENSOR" V 2950 2900 60  0000 C CNN
F 2 "CON-SENSOR" H 2800 2900 60  0001 C CNN
	1    2800 2900
	-1   0    0    -1  
$EndComp
$EndSCHEMATC
