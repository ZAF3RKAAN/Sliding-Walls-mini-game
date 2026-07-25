# Sliding-Walls-mini-game
A simple UNO mini-game program you can set up with just a 10K potentiometer and an SSD1306 OLED.
![Arduino](https://img.shields.io/badge/Board-Arduino%20Uno-00979D?style=flat&logo=arduino&logoColor=white)
![C++](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=flat&logo=c%2B%2B&logoColor=white)
![License](https://img.shields.io/badge/License-MIT-blue)

## 🛠️ Bill of Materials (BOM)
* **1x** Arduino Uno R3
* **1x** 0.96" I2C OLED Display (SSD1306, 128x64)
* **1x** Breadboard & Jumper Wires
* **1x** 10K Potentiometer 

| Component | Arduino Pin | Description |
|---|---|---|
| OLED SCL | **A5** | I2C Clock Line |
| OLED SDA | **A4** | I2C Data Line |
| Potentiometer Signal | **A0** | Analog Input (Player Movement) |
| Potentiometer VCC / GND | **5V / GND**
| OLED VCC / GND | **5V / GND**

Before compiling the project, make sure to install the following libraries via the **Arduino IDE Library Manager**:

* **[Adafruit SSD1306](https://github.com/adafruit/Adafruit_SSD1306)** (v2.5.0+) – Display driver for monochrome OLEDs.
* **[Adafruit GFX Library](https://github.com/adafruit/Adafruit-GFX-Library)** (v1.10.0+) – Core graphics primitive library.
