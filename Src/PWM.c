/**
 * filename: PWM.c
 * author: Benen Crombie
 *
 * Driver for timers, used for motor control
 */

#include "PWM.h"
#include "MotorDriver.h"
#include "USART.h"
#include "main.h"

// GPIOA/B/C clocks are already enabled
// APB1 clock prescaled by 16, so it is 5.25 MHz

/**
 * @brief init timer 2 for pwm
 * @param void
 * @return void
 */
static void PWM_Init_TIM2(void)
{
    // PWMs used here
    // PA1 on channel 2, for MTR0 step
    // PA2 on channel 3, for MTR4 step

    // Enable TIM2 clock
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

    // Speed is predetermined by PSC and ARR.
    // Frequency of the PWM is 5.25 MHz / [(PSC + 1) * (ARR + 1)]
    // So higher the higher the PSC/ARR values are, the slower it goes
    // Keeping PSC pinned for each timer. Speed will be updated with ARR since they have the same
    // affect

    // Set PSC, prescaling
    TIM2->PSC = TIM2_PRESC;

    // Set ARR, auto reload register
    TIM2->ARR = (uint16_t)MAX_ARR;

    // Configure PWM on ch2. CCMR1 contains ch1 and ch2
    // Ch1 is bits 15:8 of this register
    TIM2->CCMR1 &= ~(0xFF << 8); // clear ch2
    TIM2->CCMR1 |= (0x06 << 12); // PWM mode 1
    TIM2->CCMR1 |= (0x01 << 11); // enable preload

    // Configure PWM on ch3. CCMR2 contains ch3 and ch4
    // Ch3 is its 7:0 of this register
    TIM2->CCMR2 &= ~(0xFF << 0); // clear ch3
    TIM2->CCMR2 |= (0x06 << 4);  // PWM mode 1
    TIM2->CCMR2 |= (0x01 << 3);  // output compare preload

    // Set duty cycle for ch2. Will be reset anyway, dont think i need to initialize?
    TIM2->CCR2 = 500; // Defaulting. this will be changed when starting a pwm

    // Set the duty cycle for ch3
    TIM2->CCR3 = 500; // Defaulting. this will be changed when starting a pwm

    // Enable preload. This allows speed to be adjusted mid cycle smoothly
    // Added this in and speed transitions are a lot cleaner
    TIM2->CR1 |= TIM_CR1_ARPE;

    // Load up new config in the registers
    TIM2->EGR |= TIM_EGR_UG;

    // Clear pending interrupt to ensure there isn't a pending one
    TIM2->SR &= ~TIM_SR_UIF;

    // Enable interrupt
    TIM2->DIER |= TIM_DIER_UIE;

    // Enable NVIC for interrupt
    NVIC_EnableIRQ(TIM2_IRQn);

    // Start the timer
    TIM2->CR1 |= TIM_CR1_CEN;
}

/**
 * @brief init timer 3 for pwm
 * @param void
 * @return void
 */
static void PWM_Init_TIM3(void)
{
    // PWMs used here
    // PA6 on channel 1, for MTR1 step
    // PA7 on channel 2, for MTR5 step

    // Enable TIM3 clock
    RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;

    // Set PSC, prescaling
    TIM3->PSC = TIM3_PRESC;

    // Set ARR, auto reload register
    TIM3->ARR = (uint16_t)MAX_ARR;

    // Configure PWM on ch1. Bits 7:0
    TIM3->CCMR1 &= ~(0xFF << 0); // clear ch1
    TIM3->CCMR1 |= (0x06 << 4);  // PWM mode 1
    TIM3->CCMR1 |= (0x01 << 3);  // output compare preload

    // Configure PWM on ch2. Bits 15:8 of same register
    TIM3->CCMR1 &= ~(0xFF << 8); // clear ch2
    TIM3->CCMR1 |= (0x06 << 12); // PWM mode 1
    TIM3->CCMR1 |= (0x01 << 11); // output compare preload

    // Set duty cycle for ch1
    TIM3->CCR1 = 500;

    // Set duty cycle for ch2
    TIM3->CCR2 = 500;

    // Enable ARR preload
    TIM3->CR1 |= TIM_CR1_ARPE;

    // Load up new config in the registers
    TIM3->EGR |= TIM_EGR_UG;

    // Clear pending interrupt to ensure there isn't a pending one
    TIM3->SR &= ~TIM_SR_UIF;

    // Enable interrupt
    TIM3->DIER |= TIM_DIER_UIE;

    // Enable NVIC for interrupt
    NVIC_EnableIRQ(TIM3_IRQn);

    // Start the timer
    TIM3->CR1 |= TIM_CR1_CEN;
}

/**
 * @brief init timer 4 for pwm
 * @param void
 * @return void
 */
static void PWM_Init_TIM4(void)
{
    // PWMs used here
    // Just PB6 on channel 1, for MTR2 step

    // Enable TIM4 clock
    RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;

    // Set PSC, prescaling
    TIM4->PSC = TIM4_PRESC;

    // Set ARR, auto reload register
    TIM4->ARR = (uint16_t)MAX_ARR;

    // Configure PWM on ch1. Bits 7:0
    TIM4->CCMR1 &= ~(0xFF << 0); // clear ch1
    TIM4->CCMR1 |= (0x06 << 4);  // PWM mode 1
    TIM4->CCMR1 |= (0x01 << 3);  // output compare preload

    // Set duty cycle for ch1
    TIM4->CCR1 = 500;

    // Enable ARR preload
    TIM4->CR1 |= TIM_CR1_ARPE;

    // Load up new config in the registers
    TIM4->EGR |= TIM_EGR_UG;

    // Clear pending interrupt to ensure there isn't a pending one
    TIM4->SR &= ~TIM_SR_UIF;

    // Enable interrupt
    TIM4->DIER |= TIM_DIER_UIE;

    // Enable NVIC for interrupt
    NVIC_EnableIRQ(TIM4_IRQn);

    // Start the timer
    TIM4->CR1 |= TIM_CR1_CEN;
}

/**
 * @brief init timer 5 for pwm
 * @param void
 * @return void
 */
static void PWM_Init_TIM5(void)
{
    // PWMs used here
    // Just PA0 on channel 1, for MTR3 step

    // Enable TIM2 clock
    RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;

    // Set PSC, prescaling
    TIM5->PSC = TIM5_PRESC;

    // Set ARR, auto reload register
    TIM5->ARR = (uint16_t)MAX_ARR;

    // Configure PWM on ch1. Bits 7:0
    TIM5->CCMR1 &= ~(0xFF << 0); // clear ch1
    TIM5->CCMR1 |= (0x06 << 4);  // PWM mode 1
    TIM5->CCMR1 |= (0x01 << 3);  // output compare preload

    // Set duty cycle for ch1
    TIM5->CCR1 = 500;

    // Enable ARR preload
    TIM5->CR1 |= TIM_CR1_ARPE;

    // Load up new config in the registers
    TIM5->EGR |= TIM_EGR_UG;

    // Clear pending interrupt to ensure there isn't a pending one
    TIM5->SR &= ~TIM_SR_UIF;

    // Enable interrupt
    TIM5->DIER |= TIM_DIER_UIE;

    // Enable NVIC for interrupt
    NVIC_EnableIRQ(TIM5_IRQn);

    // Start the timer
    TIM5->CR1 |= TIM_CR1_CEN;
}

/**
 * @brief Initializes all relevant PWM timers (general purpose timers)
 * @param void
 * @return void
 */
void PWM_Initialize(void)
{
    PWM_Init_TIM2();
    PWM_Init_TIM3();
    PWM_Init_TIM4();
    PWM_Init_TIM5();
}

/**
 * @brief enables a channel on a timer
 * @param void
 * @return void
 */
void PWM_EnableChannel(e_MotorNum motor_number)
{
    switch (motor_number)
    {
        case M0:
            TIM2->CCER |= TIM_CCER_CC2E; // enable channel 2
            break;
        case M1:
            TIM3->CCER |= TIM_CCER_CC1E; // enable channel 1
            break;
        case M2:
            TIM4->CCER |= TIM_CCER_CC1E; // enable channel 1
            break;
        case M3:
            TIM5->CCER |= TIM_CCER_CC1E; // enable channel 1
            break;
        case M4:
            TIM2->CCER |= TIM_CCER_CC3E; // enable channel 3
            break;
        case M5:
            TIM3->CCER |= TIM_CCER_CC2E; // enable channel 2
            break;
    }
}

/**
 * @brief disables a channel on a timer
 * @param void
 * @return void
 */
void PWM_DisableChannel(e_MotorNum motor_number)
{
    switch (motor_number)
    {
        case M0:
            TIM2->CCER &= ~TIM_CCER_CC2E; // disable channel 2
            break;
        case M1:
            TIM3->CCER &= ~TIM_CCER_CC1E; // disable channel 1
            break;
        case M2:
            TIM4->CCER &= ~TIM_CCER_CC1E; // disable channel 1
            break;
        case M3:
            TIM5->CCER &= ~TIM_CCER_CC1E; // disable channel 1
            break;
        case M4:
            TIM2->CCER &= ~TIM_CCER_CC3E; // disable channel 3
            break;
        case M5:
            TIM3->CCER &= ~TIM_CCER_CC2E; // disable channel 2
            break;
    }
}

/**
 * @brief sets the speed of a pwm by setting the auto reload register (ARR) value
 * @param motor_number the motor selected to adjust speed for
 * @param arr_val the updated arr value
 * @return void
 */
void PWM_SetArr(e_MotorNum motor_number, uint32_t arr_val)
{
    // This is a little ugly, but I couldn't wrap my head around how to do this in a simple way
    // without just using motor numbers. Makes this file a little less generalized, but it's fine.
    // The alternative is to just use specific timer/channels as inputs but that's probbaly messier

    uint32_t clipped_arr;

    // TIM2 and TIM5 take 32 bits for no good reason. Clip this to 16b to be general across all four
    // timers. Clip upper arr to prevent overflow
    if (arr_val > MAX_ARR)
    {
        clipped_arr = MAX_ARR;
    }
    // Clip lower to prevent motor from going too fast.
    else if (arr_val < MIN_ARR)
    {
        clipped_arr = MIN_ARR;
    }
    else
    {
        clipped_arr = arr_val;
    }

    switch (motor_number)
    {
        case M0:
        {
            TIM2->ARR = clipped_arr;
        }
        case M1:
        {
            TIM3->ARR = clipped_arr;
        }
        case M2:
        {
            TIM4->ARR = clipped_arr;
        }
        case M3:
        {
            TIM5->ARR = clipped_arr;
        }
        case M4:
        {
            TIM2->ARR = clipped_arr;
        }
        case M5:
        {
            TIM3->ARR = clipped_arr;
        }
    }

    // Log the new value
    // USART2_SendInt32(clipped_arr);
    // USART2_SendString("\r\n");
}