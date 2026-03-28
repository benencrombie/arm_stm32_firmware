/*
filename: SysTick.h
================
Header for SysTick.c
*/

#include "main.h"

// milliseconds flag visible to main.c
extern volatile uint32_t f_ms;

void SysTick_Initialize(void);