# Smart Home Control System using PIC18F4620 Microcontrollers
![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)     ![Embedded systems](https://img.shields.io/badge/Embedded%20systems-gray?style=flat)      ![PIC18f4620](https://img.shields.io/badge/PIC18f4620-Red?style=flat)

![image](https://github.com/user-attachments/assets/c654f969-92be-49f8-a35b-2ab721203352)
![image](https://github.com/user-attachments/assets/fd412120-4a82-4230-b705-927fcf46ec0b)


## Project Overview
This project implements a smart home control system with three PIC18F4620 microcontrollers (MCUs) connected via the I2C protocol, with one MCU serving as the master and two as slaves. Each MCU is dedicated to managing specific functionalities within the system, including a real-time clock, alarm, temperature control, lighting, and gate security.

## System Components and Functionalities

### 1. Master MCU (Central Controller)
- **LCD and Keypad Interface**: The master MCU is connected to an LCD and a keypad. The user can select one of two main functions:
  - **Clock Mode**: By pressing '1' on the keypad, the master MCU retrieves real-time date and time from the DS1307 Real-Time Clock (RTC) sensor via I2C and displays it on the LCD.
  - ![image](https://github.com/user-attachments/assets/e8469c78-7258-4bb1-9649-264e6f0b30bb)

  - **Alarm Mode**: Pressing '2' enters the alarm mode, where a stopwatch interface appears on the LCD. The user can:
    - Move the cursor left (`#` key) or right (`=` key).
    - Set values for seconds, minutes, and hours by pressing the `+` key.
    - Start the countdown timer with the `-` key. When the timer reaches zero, a buzzer sounds, which can be disabled by pressing '1' to return to the main dashboard.
    - ![image](https://github.com/user-attachments/assets/a568c6cc-5e66-4698-9fcf-96911b7eb05f)


- **Temperature Monitoring**: The master MCU constantly reads temperature data from a TC74 temperature sensor and sends it to Slave 1 for temperature regulation.

### 2. Slave 1 MCU (Temperature and Outdoor Illumination Control)
- **Temperature Control**: Based on the temperature data received from the master MCU, Slave 1 performs the following actions:
  - **Cooler & Blue LED Activation**: If the temperature is below 20°C.
  - ![image](https://github.com/user-attachments/assets/3088d82a-882b-4070-9b32-1d943d7c17bd)

  - **No Action**: If the temperature is between 20°C and 30°C.
  - ![image](https://github.com/user-attachments/assets/e426294a-c9eb-45f4-ba81-04382b94fc8a)

  - **Heater & Red LED Activation**: If the temperature is 30°C or higher.
  - ![image](https://github.com/user-attachments/assets/cdaebf27-f136-4d70-acf6-0e9489feda4d)

- **Outdoor Illumination**: An outdoor illumination button enables or disables outdoor lighting when pressed.
- ![image](https://github.com/user-attachments/assets/b7863c12-a34b-4c84-b103-35fbedad7607)


### 3. Slave 2 MCU (Indoor Illumination and Gate Security Control)
- **Indoor Illumination**: Slave 2 receives data from the master MCU regarding the Light Dependent Resistor (LDR) sensor’s ADC reading:
  - **Indoor Lighting ON**: If the LDR reading is below 130.
  - ![image](https://github.com/user-attachments/assets/4487757c-69d1-4378-b395-817b22c48308)

  - **Indoor Lighting OFF**: If the LDR reading is 130 or higher.
  - ![image](https://github.com/user-attachments/assets/2649b9fd-6c15-435b-a812-62c398ad746e)

- **Gate Security System**: This subsystem controls gate access via an LCD and keypad:
- ![image](https://github.com/user-attachments/assets/b7bad58b-653b-48bf-b3c3-09a9b39ac2aa)

  - The user must enter a seven-character password correctly to unlock the gate.
  - When access is granted, a DC motor opens the gate, and a green LED turns on.
  - If access is denied, the gate remains locked, and a red LED is illuminated.

## Key Features
- **Modular Design**: The three MCUs work together, each with a defined role, ensuring efficient system management.
- **User-Friendly Interface**: A keypad and LCD allow easy selection of clock and alarm modes, along with interactive alarm settings.
- **Temperature and Lighting Automation**: Automated actions based on temperature and lighting conditions provide a smart home experience.
- **Secure Gate Access**: A password-protected gate ensures security, with visual LED indicators to reflect the gate’s status.

---
