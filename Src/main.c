#include "main.h"
#include "FSM.h"
#include "GPIO.h"
#include "MotorDriver.h"
#include "PWM.h"
#include "SysTick.h"
#include "USART.h"
#include "stm32f446xx.h"

// ISRs
void TIM2_IRQHandler(void);               // Motors 0 step
void TIM3_IRQHandler(void);               // Motors 1 step
void TIM4_IRQHandler(void);               // Motor 2 step
void TIM5_IRQHandler(void);               // Motor 3 step
void TIM1_UP_TIM10_IRQHandler(void);      // Motor 4 step
void TIM1_TRG_COM_TIM11_IRQHandler(void); // Motor 5 step
void USART2_IRQHandler(void);             // Debug comms TX

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

    // Enable interrupts.
    __enable_irq();

    // Initialize the FSM
    FSM_Initialize();

#if DEBUG_SYS
    USART2_SendString("Fully Initialized\r\n");
#endif

    while (1)
    {
        // Millisecond loop - 1000 Hz
        if (f_ms)
        {
            // Unflip the flag
            f_ms = 0;

            // Increment ms counter
            ms_counter++;

            // Update overall system logic
            FSM_Tick1000Hz();

            // Every 1 second (1000 ms)
            if (ms_counter == 1000)
            {
                // Reset counter
                ms_counter = 0;

                // Update overall system logic
                FSM_Tick1Hz();
            }
        }
        // Tick the FSM at 84 MHz
        FSM_TickSys();
    }
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
 * @brief TIM10 interrupt handler
 */
void TIM1_UP_TIM10_IRQHandler(void)
{
    Motors_TIM10_IRQHandler();
}

/**
 * @brief TIM11 interrupt handler
 */
void TIM1_TRG_COM_TIM11_IRQHandler(void)
{
    Motors_TIM11_IRQHandler();
}

/**
 * @brief USART2 interrupt handler. FAH
 */
void USART2_IRQHandler(void)
{
    USART2_InterruptHandler();
}