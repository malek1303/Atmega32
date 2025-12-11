```markdown
# Atmega32 - Peripheral Drivers and Utilities

A lightweight collection of MCU drivers, utilities and example code for the Atmega32 (AVR) microcontroller.

This repository gathers low-level drivers for common peripherals (DIO/PORT, LEDs, 7-segment, CLCD, keypad, switches and more) so you can quickly prototype embedded projects using avr-gcc / Atmel toolchains or import the drivers into Atmel Studio / PlatformIO projects.

---

## Contents / What I found in this repo

- Language: C
- Default branch: `main`
- Drivers and peripherals implemented (high level):
  - DIO / PORT drivers (pin / port configuration, pull-ups)
  - LED drivers
  - 7-segment (SEG) drivers
  - CLCD (character LCD) drivers, plus support for custom characters (CLCD_ExtraChar)
  - Keypad drivers
  - Switch drivers
  - CPU_Freq.h — central place to specify the MCU frequency
- Folder: `Drivers/` — main driver implementations

Commit history shows progressive additions and documentation improvements (CLCD helpers, keypad driver, port organization, CPU_Freq.h, etc).

---

## Goals

- Provide simple, well-documented drivers for common Atmega32 peripherals
- Make it easy to plug drivers into small AVR projects
- Keep the code minimal and portable between common AVR toolchains

---

## Quick start

Requirements
- avr-gcc toolchain
