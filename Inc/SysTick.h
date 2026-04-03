/**
 * filename: SysTick.h
 * author: Benen Crombie
 *
 * Header for SysTick.c
 */

#ifndef SYSTICK_H
#define SYSTICK_H

#include "main.h"

// milliseconds flag visible to main.c
extern volatile uint32_t f_ms;

void SysTick_Initialize(void);

#endif