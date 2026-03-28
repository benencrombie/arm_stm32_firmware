/*
filename: SysTick.c
================
Timekeeper module. Flags for milliseconds

TODO: hard to find documentation on the core_cm4.h registers. Got a lot of help from claude with
the init and interrupt, but it either works or it doesn't so it isn't critical to debug just yet.
Presumably, this is what HAL would do, but there isn't a lot of overhead here at all so low
priority.
*/

#include "SysTick.h"
#include "core_cm4.h"
#include "main.h"
#include "stm32f446xx.h"

#define MS_TICKS (SystemCoreClock / 1000) // 84000 Ticks/ms

// flag for ms
volatile uint32_t f_ms = 0;

void SysTick_Initialize(void)
{
    // SysTick is the hardware countdown timer insite Cortex-M4
    // Load is reload value register, countdown from 84k continuously, then a flag is put up
    SysTick->LOAD = MS_TICKS - 1;

    // Current value register, set current val to 0 on init
    SysTick->VAL = 0;

    // Control and status register
    SysTick->CTRL = (1 << 2) | // Bit 2 CLKSOURCE, set to CPU clock (84 MHz)
                    (1 << 1) | // Bit 1 TICKINT, enable interrupt
                    (1 << 0);  // Bit 0 ENABLE, enable counter
}

/**
 * @brief function to be executed on a systick event. Configured in the startup file, so this name
 * is reserved
 * @param void
 * @return void
 */
void SysTick_Handler(void)
{
    // Put ms flag up
    f_ms = 1;
}