#ifndef MAIN_H
#define MAIN_H

#include "stm32f446xx.h"
#include <stdbool.h>
#include <stdint.h>

// Debug flags dictate what is sent through UART. If you turn everything on you will get... a lot
#define DEBUG_SYS              (1)
#define DEBUG_MOTORS           (0)
#define DEBUG_FSM              (1)
#define DEBUG_FSM_VERBOSE      (1)
#define DEBUG_INTERRUPT_TIMERS (0)
#define DEBUG_COMMS            (1)

// Globally used defines
#define SYSHZ  (84000000) // 84 MHz
#define APB1HZ (5250000)  // Prescaled by 128 for now, artbitratily chosen

// Global vars
extern uint32_t SystemCoreClock; // Current clock freq (adjusted to 84 MHz), making global incase
                                 // its needed as a param

// prototypes
void SystemCoreClockUpdate(void);

/**
 * Test Pins:
 * Used for troubleshooting and to monitor cpu hangs
 */

#define TEST_GPIO_PORT GPIOC
#define TEST_GPIO_PIN  3 // PC3

/**
 * Motor IOs:
 * Each motor has an EN, DIR, and STEP
 */

#define MTR_EN_PORT GPIOC // Just use the same port for all ENs for simplicity
#define MTR0_EN_PIN 0     // PC0
#define MTR1_EN_PIN 1     // PC1
#define MTR2_EN_PIN 2     // PC2
#define MTR3_EN_PIN 13    // PC13
#define MTR4_EN_PIN 14    // PC14
#define MTR5_EN_PIN 15    // PC15

#define MTR_DIR_PORT GPIOB // Just use the same port for all DIRs for simplicity
#define MTR0_DIR_PIN 3     // PB3
#define MTR1_DIR_PIN 4     // PB4
#define MTR2_DIR_PIN 5     // PB5
#define MTR3_DIR_PIN 13    // PB13
#define MTR4_DIR_PIN 14    // PB14
#define MTR5_DIR_PIN 15    // PB15

/**
 * USARTs:
 * One USART is used for debug. On the dev board, PA2 and PA3 are already wired
 * to USB, so just going to use that. Others USARTs will potentially be used if
 * a "brain"/raspberri pi is incorporated
 */

// USART2 is for debug, built in through USB for devboard so this is easy to use
#define USART2_PORT   GPIOA
#define USART2_TX_PIN 2 // PA2, AF7
#define USART2_RX_PIN 3 // PA3, AF7

// USART1 is RESERVED for other stuff. I think it would be sick to have a
// raspberri pi send UART comms to this for processing video/audio
#define USART1_PORT   GPIOA
#define USART1_TX_PIN 9  // PA9, AF7
#define USART1_RX_PIN 10 // PA10, AF7

/**
 * PWMs:
 * I want to use internal timers to dictate motor driving. Going to use A4988
 * drivers which tick on a rising edge, so adjusting the speed of the timer can
 * adjust the speed of the motor without requiring a lot of overhead.
 * TIM2/3/4/5 general purpose timers will be used for these.
 * TIM1/8 are advanced timers. Reserving these for later since I don't think
 * they add much for motor drivers
 *
 * However, the limitation to using timers is that I can't set two motors on the
 * same timer to different speeds at the same time. To work around this, I'm
 * going to use the 4 general purpose timers, with 2 being reused for motor
 * pairs that are unlikely to run at the same time.
 */

// Motor 0, TIM2
#define MTR0_STEP_PORT GPIOA
#define MTR0_STEP_PIN  1 // PA1, AF1, TIM2_CH2
// Motor 1, TIM3
#define MTR1_STEP_PORT GPIOA
#define MTR1_STEP_PIN  6 // PA6, AF2, TIM3_CH1
// Motor 2, TIM4
#define MTR2_STEP_PORT GPIOB
#define MTR2_STEP_PIN  6 // PB6, AF2, TIM4_CH1
// Motor 3, TIM5
#define MTR3_STEP_PORT GPIOA
#define MTR3_STEP_PIN  0 // PA0, AF2, TIM5_CH1
// Motor 4, TIM2 (reused)
#define MTR4_STEP_PORT GPIOA
#define MTR4_STEP_PIN  2 // PA2, AF1, TIM2_CH3
// Motor 5, TIM3 (reused)
#define MTR5_STEP_PORT GPIOA
#define MTR5_STEP_PIN  7 // PA7, AF2, TIM3_CH2

#endif