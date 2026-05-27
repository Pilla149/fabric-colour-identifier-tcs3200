# Fabric Colour Identifier using TCS3200 Sensor

## Overview

This project identifies the colour of fabric materials using the TCS3200 colour sensor and Arduino. The system detects RGB colour frequency values and determines the nearest matching colour.

The project can be used in textile industries, automation systems, smart sorting applications, and quality inspection systems.

---

## Features

- Real-time colour detection
- RGB frequency analysis
- Fabric colour identification
- Serial monitor output
- Low-cost embedded solution
- Easy sensor interfacing

---

## Components Used

| Component | Quantity |
|---|---|
| Arduino UNO | 1 |
| TCS3200 Colour Sensor | 1 |
| Jumper Wires | Several |
| Breadboard | 1 |
| Fabric Samples | Multiple |

---

## Working Principle

The TCS3200 sensor detects colour intensity by measuring the frequency of red, green, and blue light reflected from the fabric surface.

The Arduino reads these frequency values and compares them with predefined thresholds to identify the fabric colour.

---

## Pin Connections

| TCS3200 | Arduino UNO |
|---|---|
| VCC | 5V |
| GND | GND |
| S0 | D4 |
| S1 | D5 |
| S2 | D6 |
| S3 | D7 |
| OUT | D8 |

---

## Output Example

Detected Colour: RED

RGB Values:
R = 45
G = 120
B = 135

---

## Applications

- Textile industry automation
- Smart sorting machines
- Industrial quality inspection
- Embedded sensing applications
- Colour-based object classification

---

## Future Improvements

- OLED/LCD display integration
- IoT-based monitoring
- AI-based colour classification
- Mobile application integration
- Database colour matching

---

## Technologies Used

- Embedded C
- Arduino IDE
- Sensor Interfacing
- Serial Communication

---

## Author
Pilla Naga Adinarayana
ECE Graduate | Embedded Systems Enthusiast
