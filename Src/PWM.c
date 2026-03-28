/*
filename: PWM.c

PWM driver
*/

#include "main.h"

// GPIOA/B/C clocks are already enabled

static void PWM_Init_TIM2(void)
{
    // PWMs used here
    // PA1 on channel 2, for MTR0 step
    // PA2 on channel 3, for MTR4 step

    // Enable TIM2 clock
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

    // Speed is predetermined by PSC and ARR.
    // Frequency of the PWM is proportional to 1 / [(PSC + 1) * (ARR + 1)]
    // So higher the higher the PSC/ARR values are, the slower it goes
    // Keeping PSC pinned for each timer. Speed will be updated with ARR since they have the same
    // affect

    // Set PSC, prescaling
    TIM2->PSC = 16000;

    // Set ARR, auto reload register
    TIM2->ARR = 1000;

    // Configure PWM on applicable channels (CH2)
    TIM2->CCMR1 &= ~(0xFF << 8); // clear CH2
    TIM2->CCMR1 |= (6 << 12);    // PWM mode 1
    TIM2->CCMR1 |= (1 << 11);    // enable preload

    // Set duty cycle
    TIM2->CCR2 = 500;

    // Enable CH2 output
    TIM2->CCER |= TIM_CCER_CC2E;

    // Enable preload. This allows speed to be adjusted mid cycle smoothly
    TIM2->CR1 |= TIM_CR1_ARPE;

    // Load up new config in the registers
    TIM2->EGR |= TIM_EGR_UG;

    // Start the timer
    TIM2->CR1 |= TIM_CR1_CEN;
}

static void PWM_Init_TIM3(void)
{
}

static void PWM_Init_TIM4(void)
{
}

static void PWM_Init_TIM5(void)
{
}

void PWM_Initialize(void)
{
    PWM_Init_TIM2();
    PWM_Init_TIM3();
    PWM_Init_TIM4();
    PWM_Init_TIM5();
}