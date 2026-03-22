# ⚡ ATmega32 Peripheral Drivers

![C](https://img.shields.io/badge/Language-C-blue.svg?style=flat-square&logo=c)
![Microcontroller](https://img.shields.io/badge/MCU-ATmega32-red.svg?style=flat-square&logo=microchip)
![Toolchain](https://img.shields.io/badge/Toolchain-AVR--GCC-orange.svg?style=flat-square)
![License](https://img.shields.io/badge/License-MIT-green.svg?style=flat-square)

A lightweight, modular, and well-documented collection of bare-metal peripheral drivers and utilities for the **ATmega32 (AVR)** microcontroller. 

This repository provides simple, plug-and-play drivers for common peripherals so you can quickly prototype embedded projects using the `avr-gcc` toolchain.

---

## 🛠️ Supported Peripherals & Drivers

* **Core System:**
  * `DIO / PORT`: Complete GPIO port and pin configuration (Direction, Value, Pull-ups).
  * `EXTI`: External Interrupts handling.
  * `CPU_Freq.h`: Centralized clock configuration for easy portability.
* **Hardware Interfacing:**
  * **LEDs:** Simplified control for LED toggling and state management.
  * **Switches:** Push-button reading.
  * **7-Segment Displays (SEG):** 7-segment driver logic.
  * **Keypad:** Matrix keypad scanning and mapping.
  * **CLCD (Character LCD):** Initialization, string writing, and custom character support (`CLCD_ExtraChar`).

---

## 📂 Repository Structure

# Atmega32 Repository Structure

```text
Atmega32/
├── .gitignore
├── README.md
└── Drivers/
    ├── LIB/                     # Common libraries and macros
    │   ├── BIT_MATH.h
    │   └── STD_TYPES.h
    ├── HAL/                     # Hardware Abstraction Layer
    │   ├── CLCD/                # Character LCD Driver
    │   │   ├── CLCD_config.h
    │   │   ├── CLCD_ExtraChar.h
    │   │   ├── CLCD_int.h
    │   │   ├── CLCD_private.h
    │   │   └── CLCD_prog.c
    │   ├── KPD/                 # Keypad Driver
    │   │   ├── KPD_config.h
    │   │   ├── KPD_int.h
    │   │   ├── KPD_priv.h
    │   │   └── KPD_prog.c
    │   ├── LED/                 # LED Driver
    │   │   ├── LED_config.h
    │   │   ├── LED_int.h
    │   │   ├── LED_private.h
    │   │   └── LED_prog.c
    │   ├── SEG/                 # Seven Segment Display Driver
    │   │   ├── SEG_config.h
    │   │   ├── SEG_interface.h
    │   │   ├── SEG_private.h
    │   │   └── SEG_prog.c
    │   └── SW/                  # Switch/Button Driver
    │       ├── SW_config.h
    │       ├── SW_interface.h
    │       ├── SW_private.h
    │       └── SW_program.c
    └── MCAL/                    # Microcontroller Abstraction Layer
        ├── CONFIG/
        │   └── CPU_Freq.h
        ├── DIO/                 # Digital Input/Output
        │   ├── DIO_config.h
        │   ├── DIO_interface.h
        │   ├── DIO_private.h
        │   └── DIO_program.c
        ├── EXTI/                # External Interrupts
        │   ├── EXTI_config.h
        │   ├── EXTI_interface.h
        │   ├── EXTI_private.h
        │   └── EXTI_prog.c
        └── PORT/                # Port Configuration
            ├── PORT_config.h
            ├── PORT_int.h
            ├── PORT_priv.h
            └── PORT_prog.c
```

---

## 🚀 Getting Started

### Prerequisites
* **Compiler:** `avr-gcc` toolchain.

### Usage
1. Clone the repository:
   ```bash
   git clone [https://github.com/malek1303/Atmega32.git](https://github.com/malek1303/Atmega32.git)
   ```
2. Copy the `Drivers/` folder into your AVR project directory.
3. Include the necessary driver headers in your `main.c`:
   ```c
   #include "Drivers/DIO/DIO_interface.h"
   // Include other necessary drivers...
   ```
4. Configure your MCU frequency in `CPU_Freq.h` to ensure accurate delay calculations.

---

## 👨‍💻 About the Author

Built and maintained by **Malek Mahdy**.

* 🎓 **Role:** Head of the Embedded Systems Committee @ IEEE MUST SB
* 🐧 **OS:** Arch Linux (I use Arch, btw)
* 📫 **Contact:** [malekmahdy@ieee.org](mailto:malekmahdy@ieee.org)

Feel free to fork this repository or submit a pull request if you want to add drivers for Timers, ADC, UART, SPI, or I2C!
