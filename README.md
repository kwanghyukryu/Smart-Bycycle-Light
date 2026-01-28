# ESP32 Smart Light System

<img width="420" height="753" alt="bike" src="https://github.com/user-attachments/assets/ed28e916-e449-4762-b7a7-bcac22c2b776" />

## Overview
This project implements a wireless master–slave control system using two ESP32 microcontrollers. The system enables synchronized lighting behavior, such as brake lights and turn signals, through real-time communication between devices.

The architecture separates control logic (master) from output actuation (slave), improving modularity, reliability, and scalability.

## System Architecture
- Master ESP32  
  - Handles user input and system state logic  
  - Transmits control signals wirelessly  

- Slave ESP32  
  - Receives commands from the master  
  - Drives LEDs and output hardware  

Communication is handled over Wi-Fi for low-latency state synchronization.

## Features
- Wireless master–slave communication using ESP32 Wi-Fi
- Modular separation of control and output logic
- Real-time synchronization of light states
- Designed for embedded and IoT-style applications
- Easily extendable for additional signals or sensors


## Hardware Requirements
- Two ESP32 development boards
- LEDs (brake lights / indicators)
- Resistors and jumper wires
- Breadboard or PCB (optional)
- USB or battery power supply

## Software Requirements
- Arduino IDE
- ESP32 board support package
- USB drivers for ESP32

## Setup Instructions
1. Install the ESP32 board package in Arduino IDE
2. Upload `master.ino` to the master ESP32
3. Upload `slave.ino` to the slave ESP32
4. Power both boards
5. Verify communication using the Serial Monitor

## How It Works
1. The master ESP32 detects input or state changes
2. Control data is transmitted wirelessly
3. The slave ESP32 decodes incoming messages
4. LEDs and outputs update in real time

This design mirrors distributed embedded systems commonly used in IoT and automotive applications.

## Applications
- Smart bicycle lighting systems
- Distributed embedded control
- Internet of Things (IoT) devices
- Wireless signal synchronization

## Future Improvements
- Encrypted wireless communication
- Support for multiple slave nodes
- Sensor integration (IMU, light, brake pressure)
- Power optimization for battery operation

## Author
Kwanghyuk Ryu

