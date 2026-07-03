# Reaction Timer

A simple Arduino-based reaction time tester with a 20×4 I2C LCD, LEDs, buzzer, and a pushbutton. Press the button, wait for the random signal, and see how fast you react.

[![Wokwi Simulation](https://img.shields.io/badge/Wokwi-Simulate-blue?logo=arduino)](https://wokwi.com/projects/468402428102183937)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Platform](https://img.shields.io/badge/Platform-Arduino%20Uno-green)](https://www.arduino.cc/)
[![Made with](https://img.shields.io/badge/Made%20with-C%2B%2B-00599C?logo=cplusplus)](https://en.wikipedia.org/wiki/C%2B%2B)
[![Display](https://img.shields.io/badge/Display-20x4%20I2C%20LCD-orange)]()

---

## Live Simulation

- **[Current version](https://wokwi.com/projects/468402428102183937)** — LEDs, buzzer tune, false start detection, and a result screen that waits for input.
- **[Older version](https://wokwi.com/projects/468503582785589249)** — earlier build kept here for reference.

---

## Features

- **Idle mode** — green LED on, LCD shows "Press to Start."
- **Race-start tune** — a 3-note ascending jingle plays when a round begins.
- **Hidden random countdown** — waits somewhere between 2 and 6 seconds before showing "Click!", so there's nothing to anticipate.
- **False start detection** — pressing early shows "Too Soon!", turns on the red LED, and plays a low penalty tone.
- **Reaction trigger** — LED switches to red, LCD shows "Click!", and a short beep marks the exact moment to react.
- **Millisecond timing** — reaction time is measured with `millis()` for accurate results.
- **Result screen waits for you** — no auto-timeout after showing your time; it sits there until you press the button again.
- **Repeatable** — press again anytime to run another round.

---

## Components Used

- Arduino Uno
- 20×4 I2C LCD
- Pushbutton
- Buzzer
- 2× LEDs (Green & Red)
- 2× Resistors (220Ω for LEDs)
- Breadboard & jumper wires

---

## Quick Start

1. Open the [Wokwi project](https://wokwi.com/projects/468402428102183937) to simulate instantly, or upload `reaction-timer.ino` to your Arduino.
2. Wire up the components as shown in the table below.
3. Power on the board — LCD shows "Press to Start" with the green LED lit.
4. Press the button, watch for "Be Ready...", then react the instant "Click!" appears.
5. Your reaction time is displayed in milliseconds on the LCD.
6. Press the button again to play another round.

---

## Connections

| Arduino Pin | Component      | Connection              |
|-------------|-----------------|--------------------------|
| 5V          | LCD (I2C)       | VCC                      |
| GND         | LCD, Buzzer, Button, LEDs | GND            |
| A4 (SDA)    | LCD             | SDA                      |
| A5 (SCL)    | LCD             | SCL                      |
| 8           | Green LED       | + (through 220Ω resistor)|
| 9           | Red LED         | + (through 220Ω resistor)|
| 10          | Buzzer          | + (Red)                  |
| 6           | Button          | One leg (other to GND)   |

Note: both LEDs' cathodes (negative legs) connect to GND, and the button's other leg also connects to GND. The internal pull-up is used, so no external resistor is needed for the button itself.

---

## How the Game Works

| Stage | LCD Message | LED | Sound |
|---|---|---|---|
| Idle | "Press to Start" | Green | — |
| Round starts | "Be Ready..." | Green | Start tune |
| Hidden wait | (nothing shown) | Green | — |
| Go signal | "Click!" | Red | Beep |
| False start | "Too Soon!" | Red | Low buzz |
| Result | "Time: XXX ms" | Off | — |

---

## Files

- `reaction-timer.ino` – main sketch
- `libraries.txt` – required libraries
- `README.md` – this file

---

## Libraries

Install via Arduino Library Manager:

- `LiquidCrystal_I2C` by Frank de Brabander

---

## License

This project is licensed under the [MIT License](https://opensource.org/licenses/MIT) — free to use, modify, and share.
