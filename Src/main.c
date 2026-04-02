#include "main.h"
#include "GPIO.h"
#include "MotorDriver.h"
#include "PWM.h"
#include "SysTick.h"
#include "stm32f446xx.h"

// Debug flags dictate what is sent through UART. If you turn everything on you will get... a lot
#define DEBUG 1
#ifdef DEBUG
#define DBUG_MOTORS 1
#endif

// prototypes
static void SystemClock_Config_84MHz(void);
// interrupts
void TIM2_IRQHandler(void);
void TIM3_IRQHandler(void);
void TIM4_IRQHandler(void);
void TIM5_IRQHandler(void);

// Initialize ms to the next second, or however frequently we want to do stuff. Highest frequency
// activities as system speed (84 MHz) and milliseconds (1000 Hz)
uint32_t ms_counter = 0;

/**
 * @brief main. does things.
 */
int main(void)
{
    // Update system clock with CMSIS function
    SystemClock_Config_84MHz();

    // Initialize ticker for ms flags
    SysTick_Initialize();

    // Initialize all pins
    GPIO_Initialize();

    // Initialize PWMs on timers
    PWM_Initialize();

    // Allow motors to be used
    Motors_FSM_Initialize(); // TODO maybe this and any other small FSMs should be called within the
                             // big FSM. Haven't architected what that'll look like just yet, but
                             // this is good for bringup

    while (1)
    {
        // Millisecond loop - 1000 Hz
        if (f_ms)
        {
            // Unflip the flag
            f_ms = 0;

            // Increment ms counter
            ms_counter++;

            // Every 1 second (1000 ms)
            if (ms_counter == 1000)
            {
                // Reset counter
                ms_counter = 0;

                // Update motors
                Motors_FSM_Tick1000Hz();

                // Debug testing block, every 1 second
#if DEBUG
                // Toggle test pin - hooked up to LED, easily shows that CPU is not hanging
                GPIO_ToggleTestPin();
#endif
            }
        }

        // 84 MHz loop
    }
}

/**
 * @brief configure the clock to be 84MHz (stm32f446 is capable), default is 16MHz. This is vibe
 * coded for the most part, but it works and is common in STM architectures. Little risk of this
 * failing.
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

/**
 * ISR Operations
 *
 * TIM2 - Motors 0 and 4
 * TIM3 - Motors 1 and 5
 * TIM4 - Motor 2
 * TIM5 - Motor 3
 */

/**
 * @brief TIM2 interrupt handler
 */
void TIM2_IRQHandler(void)
{
    Motors_TIM2_IRQHandler();
}

/**
 * @brief TIM3 interrupt handler
 */
void TIM3_IRQHandler(void)
{
    Motors_TIM3_IRQHandler();
}

/**
 * @brief TIM4 interrupt handler
 */
void TIM4_IRQHandler(void)
{
    Motors_TIM4_IRQHandler();
}

/**
 * @brief TIM5 interrupt handler
 */
void TIM5_IRQHandler(void)
{
    Motors_TIM5_IRQHandler();
}