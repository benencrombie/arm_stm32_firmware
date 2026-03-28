#include "main.h"
#include "GPIO.h"
#include "SysTick.h"
// #include "stm32f4xx.h"
#include "stm32f446xx.h"

// defines
#define DEBUG 1

// prototypes
static void SystemClock_Config_84MHz(void);

//

int main(void)
{
    // Update system clock with CMSIS function
    SystemClock_Config_84MHz();

    // Initialize ticker for ms flags
    SysTick_Initialize();

    // Initialize all pins
    GPIO_Initialize();

    while (1)
    {
        // Millisecond loop - 1000 Hz
        if (f_ms)
        {
            // Unflip the flag
            f_ms = 0;

            // Toggle test pin
            GPIO_ToggleTestPin();
        }

        // 84 MHz loop
    }
}

/**
 * @brief configure the clock to be 84MHz (stm32f446 is capable), default is 16MHz
 * @param void
 * @return void
 */
static void SystemClock_Config_84MHz(void)
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

    // switch SYSCLK to PLL
    RCC->CFGR &= ~RCC_CFGR_SW;
    RCC->CFGR |= RCC_CFGR_SW_PLL;
    while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL)
        ;

    // update CMSIS clock variable
    SystemCoreClockUpdate();
}
