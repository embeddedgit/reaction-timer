Reaction Timer 

A simple Arduino‑based reaction time tester with LCD, buzzer, and button.

[![Wokwi Simulation](https://img.shields.io/badge/Wokwi-Simulate-blue?logo=arduino)](https://wokwi.com/projects/468402428102183937)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Platform](https://img.shields.io/badge/Platform-Arduino%20Uno-green)](https://www.arduino.cc/)

Live Simulation
[Click here to try it on Wokwi](https://wokwi.com/projects/468402428102183937)**

Components Used
- Arduino Uno
- 20×4 I2C LCD
- Pushbutton
- Buzzer
- Breadboard & jumper wires

Quick Start
1. Open the **[Wokwi project](https://wokwi.com/projects/468402428102183937)** to simulate instantly, or upload `reaction-timer.ino` to your Arduino.
2. Connect the components as described below.
3. Press the button, wait for the countdown, and react when **GO!** appears.
4. Your reaction time is displayed on the LCD.

Connections:-
| Arduino Pin | Component     | Connection             |
|-------------|---------------|------------------------|
| 5V          | LCD (I2C)     | VCC                    |
| GND         | LCD, Buzzer, Button | GND              |
| A4 (SDA)    | LCD           | SDA                    |
| A5 (SCL)    | LCD           | SCL                    |
| 7           | Buzzer        | + (Red)                |
| 2           | Button        | One leg (other to GND) |

 Files
- `reaction-timer.ino` – main code
- `libraries.txt` – required libraries

 Libraries
Install via Arduino Library Manager:
- `LiquidCrystal_I2C` by Frank de Brabander
