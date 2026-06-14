/**
 * filename: SysTick.h
 * author: Benen Crombie
 *
 * Header for SysTick.c, contains public API
 */

#ifndef SYSTICK_H
#define SYSTICK_H

#include "main.h"

// milliseconds flag visible to main.c
extern volatile uint32_t f_ms;

void SystemClock_Config_84MHz(void);
void SysTick_Initialize(void);

#endif