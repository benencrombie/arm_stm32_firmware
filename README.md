## Intro

Baremetal (minimal CMSIS/stm32 headers) project for controlling a 6 Degree-of-Freedom robot arm.

STM32F446

Build Tools: STMCube IDE for building and flashing through ST LINK

[TODO eventually put a pic of finished robot or something]

### Drivers

This codebase contains baremetal drivers for GPIO, UART, and stepper motor control (through PWM peripherals).

### FSM 

This system uses a finite state machine architecture, where the main brains of the system resides in FSM.c, and other sub-fsms are called within (e.g., Motor Ticks). This architecture ensures that all necessary timing constraints are met.

RTOS not even close to necessary.

### Middleware

This system implements a very scalable middleware communications stack defined in the Comms.c/h module. The module uses UART to receive incoming commands, indicated by pre-determined preamble and postamble byte pattern. These command payloads are decoded and loaded into a queue that's processed by the FSM.  This middleware ensures that the robot can be driven through a variety of means (e.g., UART, BLE, WiFi, etc.).

For now, the only means of controlling the robot in live-time is through a desktop app (https://github.com/benencrombie/arm_sbc_app). Mostly vibe coded this app after constructing the middleware and rounding out firmware features. The concept of the app is straight forward and super easy to debug (PySerial, simple GUI). 

### Hardware

This firmware will work for any robot arm with 6 stepper motors with typical rising edge-driven stepper motor drivers (I use A4988s with some Nema 17s). The only customization that I would recommend is adjusting the base speeds and ramp times of the motors in MotorDriver.h. The motor specific configs would depend on how fast you could reasonably drive the motors and any mechanical gear reductions. 

I'll think about making my STLs open source.

### Spaghetti

Woah you made it this far