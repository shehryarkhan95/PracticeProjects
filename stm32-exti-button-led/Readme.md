# STM32 EXTI Button Interrupt with Debouncing

This project demonstrates the use of an external interrupt (EXTI) on the STM32 Nucleo-L432KC board to toggle an LED when a pushbutton is pressed. The button press is debounced in software to ensure reliable operation.

---

## 🔧 Hardware Used

- **STM32 Nucleo-L432KC**
- **Pushbutton** connected to pin **PA0**
- **Onboard LED** connected to **PA5**

Optional:
- Breadboard and jumper wires
- 10kΩ resistor (if not using internal pull-up)

---

## 🧠 Features

- **GPIO Interrupt (EXTI)** using HAL
- **Software Debouncing** (200ms delay)
- **Interrupt-driven design** — efficient and responsive
- Minimal `main()` loop — real-time event handling

---

## 🛠️ Pin Configuration

| Pin  | Mode           | Description           |
|------|----------------|-----------------------|
| PA5  | GPIO_Output    | Onboard green LED     |
| PA0  | GPIO_EXTI0     | External button input |

Button pulls PA0 **low** on press. Internal pull-up is enabled in the CubeMX `.ioc` file.

---

## 💡 Circuit Diagram

Button
[ ]──────┬────────> PA0 (EXTI0)
|
[GND]

---

## 🧪 How to Run

1. Open the `.ioc` file in **STM32CubeIDE**
2. Connect your Nucleo-L432KC via USB
3. Build and flash the project
4. Press the button — the LED toggles on/off

---

## 🔄 Debounce Logic

Implemented in the `HAL_GPIO_EXTI_Callback()`:

```c
if (now - lastPress > 200)

This ensures that only one valid press is registered every 200ms, filtering out button noise or bouncing.

License
This project is licensed under the MIT License.

Author
Shehryar Khan
Email: mecha.khan95@gmail.com
GitHub: shehryarkhan95