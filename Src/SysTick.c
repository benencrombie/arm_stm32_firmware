/**
 * filename: SysTick.c
 * author: Benen Crombie
 *
 * This module contains the system clock configuration and 1 ms tick.
 */

#include "SysTick.h"
#include "core_cm4.h"
#include "main.h"
#include "stm32f446xx.h"

#define MS_TICKS (SystemCoreClock / 1000) // 84000 Ticks/ms

// flag for ms
volatile uint32_t f_ms = 0;

/**
 * System Clock Configuration
 *
 * Main tick, peripheral clocks, etc.
 */

/**
 * @brief configure the clock to be 84MHz (stm32f446 is capable), default is 16MHz. Keeping this in
 * main for visibility
 * @param void
 * @return void
 */
void SystemClock_Config_84MHz(void)
{
    // NOTE help from claude with this. Similar to what HAL does but stripped down

    // enable power interface clock
    RCC->APB1ENR |= RCC_APB1ENR_PWREN;

    // voltage scaling (needed for higher clocks)
    PWR->CR |= PWR_CR_VOS;

    // Flash config (2 wait states for 84 MHz)
    FLASH->ACR = FLASH_ACR_PRFTEN | FLASH_ACR_ICEN | FLASH_ACR_DCEN | FLASH_ACR_LATENCY_2WS;

    // enable HSI
    RCC->CR |= RCC_CR_HSION;
    while (!(RCC->CR & RCC_CR_HSIRDY))
        ;

    // Don't touch this
    RCC->PLLCFGR = (16 << 0) |  // PLLM is bits [5:0]
                   (336 << 6) | // PLLN is bits [14:6]
                   (7 << 24) |  // PLLQ is bits [27:24]
                   RCC_PLLCFGR_PLLSRC_HSI;

    // PLLP = 4 (encoded as 01 in bits 17:16 on F4)
    RCC->PLLCFGR &= ~(3 << 16);
    RCC->PLLCFGR |= (1 << 16);

    // enable PLL
    RCC->CR |= RCC_CR_PLLON;
    while (!(RCC->CR & RCC_CR_PLLRDY))
        ;

    /**
     * Peripheral bus clocks
     *
     * HCLK = 84 MHz
     * APB1 (PCLK1) = 5.25 MHz
     * - Motor PWMs (TIM2, TIM3, TIM4, TIM5)
     * APB2 (PCLK2) = 84 MHz
     * SYSCLK = 84 MHz
     */

    // AHB, don't prescale, so HCLK = 84 MHz
    RCC->CFGR &= ~RCC_CFGR_HPRE;
    RCC->CFGR |= RCC_CFGR_HPRE_DIV1;

    // APB1, prescale by /16, so PCLK1 = 5.25 MHz. Using these for motor timers, so not super high
    // speed
    RCC->CFGR &= ~RCC_CFGR_PPRE1;
    RCC->CFGR |= RCC_CFGR_PPRE1_DIV16;

    // APB2, prescale by /1, so PCLK2 = 84 MHz
    RCC->CFGR &= ~RCC_CFGR_PPRE2;
    RCC->CFGR |= RCC_CFGR_PPRE2_DIV1;

    // set SYSCLK source from PLL
    RCC->CFGR &= ~RCC_CFGR_SW;
    RCC->CFGR |= RCC_CFGR_SW_PLL;
    while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL)
        ;

    // update CMSIS clock variable
    SystemCoreClockUpdate();
}

/**
 * @brief this function spins up a millisecond counter from the cpu's 84 MHz. This is vibe
 * coded for the most part, but it works and is common in STM architectures. Little risk of this
 * failing.
 * @param void
 * @returns void
 */
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