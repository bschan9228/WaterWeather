# WaterTopper
WaterTopper is a device that can automatically pump liquids. Using non-contact liquid level sensors, it can pump water accordingly.

It features:
- ESP32-S3-MINI-1 microcontroller
- Barrel jack to power power two motors through two terminals
- Dual motor driver to control motors
- USB-C for programming and powering the device
- Four JST connectors to connect liquid sensors
- 240x320 TFT display
- External temperature sensor
- One user-programmable button
- Six user-programmable LEDs


![IMG_0241](https://user-images.githubusercontent.com/72418944/205477068-9439e28f-1158-4867-ad9a-fe9de69605c1.jpg)
![IMG_0235](https://user-images.githubusercontent.com/72418944/205477069-3d43ea35-3700-4f9d-aafb-d7724ca3b044.jpg)

## PCB Design
![WaterTopper_PCB](https://user-images.githubusercontent.com/72418944/205479946-f8833daf-5e31-4c20-9de8-8b1ced99e3dd.png)

## Current Hardware Bugs
- Display's MOSFET has the wrong pinout/footprint
- Display's connectors has the wrong size/footprint
- JST connectors have the wrong footprint
