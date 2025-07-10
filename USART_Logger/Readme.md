# STM32 USART Command Parser

A lightweight command interpreter over UART for the STM32 Nucleo-L432KC.  
Send serial commands like `LED ON`, `STATUS`, etc., and receive responses in real-time. Ideal for embedded debugging and device control interfaces.

---

## Features

- UART communication using **USART2**
- Supports simple serial commands:
  - `LED ON` – Turns onboard LED on (PA5)
  - `LED OFF` – Turns LED off
  - `STATUS` – Prints LED state
  - `HELP` – Lists available commands
- Uses **HAL drivers** with **interrupt-based UART**
- Clean, modular structure: `usart_cmd.c/.h`

---

## Requirements

- STM32 Nucleo-L432KC board
- STM32CubeIDE (or STM32CubeMX + your IDE)
- Serial terminal (e.g. PuTTY, TeraTerm, Arduino Serial Monitor)
- USB cable

---

## Hardware Setup

- USB connects PC to Nucleo board (no extra hardware needed)
- Serial appears as **COM port** on your system
- Onboard LED on **PA5**

---

## Getting Started

### 1. Clone the repository:
```bash
git clone https://github.com/shehryarkhan95/PracticeProjects/tree/main/stm32-nucleo-uart-cmd-parser.git

2. Open in STM32CubeIDE
Import as "Existing STM32CubeMX Project"

Open .ioc to configure peripherals

3. Flash the board
Build and upload via CubeIDE

4. Open serial terminal
Baud: 115200

Data: 8-N-1

Send commands like:

vbnet
Copy
Edit
LED ON
LED OFF
STATUS