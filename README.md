# Flammable Gas Safety Prototype

**Embedded monitoring · sensor integration · automated response**

Prototype of an embedded safety system designed to monitor flammable-gas conditions and trigger local responses according to configurable thresholds.

The project combines sensor readings with actuator control to model a simple safety workflow: detect a potentially unsafe condition, classify the state, provide visual/audio feedback and actuate a servo-based shutoff mechanism.

## System behavior

The code implements three operating states:

- **Safe:** green visual indication and normal operation;
- **Alert:** warning state when gas readings cross an intermediate threshold;
- **Danger:** alarm state with visual warning, buzzer activation and servo actuation intended to represent gas shutoff.

Some versions of the prototype also read **temperature and humidity**, extending the sensor layer beyond gas concentration.

## Repository structure

```text
Main/
├── Main.ino          # Main control loop
├── Sensores.hpp      # Sensor abstraction and readings
├── Operacional.hpp   # LEDs, buzzer and servo actions
└── Comunicacao.hpp   # Communication abstraction

Esp/
└── Esp.ino           # Alternative ESP-oriented prototype flow
```

## Engineering concepts

- embedded C/C++ / Arduino-style development;
- sensor acquisition and threshold-based decision logic;
- actuator control with LEDs, buzzer and servo;
- separation of sensing, communication and operational responsibilities;
- event-driven safety behavior;
- iterative hardware prototyping.

## Purpose

This repository is preserved as an **embedded-systems prototype**. It demonstrates how sensor data can be translated into deterministic operational responses in a small hardware system.

It is not a certified safety device and should not be used as a substitute for industrial gas-detection or shutoff equipment.
