#include "main.h"
#include "GPIO.h"
#include "MotorDriver.h"
#include "PWM.h"
#include "SysTick.h"
#include "TheBigFSM.h"
#include "USART.h"
#include "stm32f446xx.h"

// prototypes
static void SystemClock_Config_84MHz(void);
// interrupts
void TIM2_IRQHandler(void);   // Motors 0 and 4 steps
void TIM3_IRQHandler(void);   // Motors 1 and 5 steps
void TIM4_IRQHandler(void);   // Motor 2 steps
void TIM5_IRQHandler(void);   // Motor 3 steps
void USART2_IRQHandler(void); // Debug comms TX

// Initialize ms to the next second, or however frequently we want to do stuff. Highest frequency
// activities as system speed (84 MHz) and milliseconds (1000 Hz)
uint32_t ms_counter = 0;

/**
 * @brief main. does things.
 */
int main(void)
{
    ////////////////////////////
    // Initialize all submodules
    ////////////////////////////

    // Update system clock with CMSIS function
    SystemClock_Config_84MHz();

    // Initialize ticker for ms flags
    SysTick_Initialize();

    // Initialize simple IOs
    GPIO_Initialize();

    // Initialize PWMs on timers
    PWM_Initialize();

    // Initialize UART for debug and comms later
    USART_Initialize();

    // Allow motors to be used
    Motors_FSM_Initialize(); // TODO maybe this and any other small FSMs should be called within the
                             // big FSM. Haven't architected what that'll look like just yet, but
                             // this is good for bringup

    // Enable interrupts
    __enable_irq();

    /////////////////
    // Initialize FSM
    /////////////////

    FSM_Initialize();

#ifdef DEBUG
    USART2_SendString("Fully Initialized\r\n");
#endif

    ////////////////////////
    // PRELOOP TESTING BLOCK
    ////////////////////////

    // Test out motor fsm
    // Set M0 to go at 99 arr speed for 100 steps
    // PWM freq prescaled down to 10 kHz, so this is 100 ticks/second (0.5 rev/s)
    Motors_StartMotor(M0, 999, 100); // NOTE I lowkey cant drive the beefy NEMA17 that fast. Maybe
                                     // cap this in raspberry pi/desktop

    ////////////////////////

    while (1)
    {
        // Millisecond loop - 1000 Hz
        if (f_ms)
        {
            // Unflip the flag
            f_ms = 0;

            // Increment ms counter
            ms_counter++;

            // Update motors
            Motors_FSM_Tick1000Hz();

            // Update overall system logic
            FSM_Tick1000Hz();

            ////////////////////////
            // 1000 HZ TESTING BLOCK
            ////////////////////////

            ////////////////////////

            // Every 1 second (1000 ms)
            if (ms_counter == 1000)
            {
                // Reset counter
                ms_counter = 0;

                // Debug testing block, every 1 second
#ifdef DEBUG
                // Toggle test pin - hooked up to LED, easily shows that CPU is not hanging
                GPIO_ToggleTestPin();
#endif
                ////////////////////////
                // 1 HZ TESTING BLOCK
                ////////////////////////

                ////////////////////////
            }
        }

        ////////////////////////
        // SYSTICK TESTING BLOCK
        ////////////////////////

        ////////////////////////
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

/**
 * @brief USART2 interrupt handler
 */
void USART2_IRQHandler(void)
{
    USART_USART2_IRQHandler();
}