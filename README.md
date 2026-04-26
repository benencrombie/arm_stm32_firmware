## Intro

Baremetal (minimal CMSIS/stm32 headers) project for controlling a 6 Degree-of-Freedom robot arm.

STM32F446

Tools: STMCube IDE for building and flashing through ST LINK

### FSM 

This system uses a super fsm architecture, where the main brains of the system resides in FSM.c, and other sub fsms are called within (e.g., Motor Ticks)

The main FSM has the following states: 

IDLE
READY
HOMING
FREEDRIVE
DISABLED
FAULT