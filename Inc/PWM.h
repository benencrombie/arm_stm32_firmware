/**
 * filename: PWM.h
 * author: Benen Crombie
 *
 * Header for PWMs, timers 2,3,4, and 5
 */

#ifndef PWM_H
#define PWM_H

#include "MotorDriver.h"
#include "main.h"

// These are arbitrarily chosen. Speed of PWMs is adjusted with ARR
#define TIM2_PRESC 127 // 5.25 MHz / (127 + 1) ~ 41,000 Hz
#define TIM3_PRESC 511 // 5.25 MHz / (511 + 1) ~ 10,300 Hz
#define TIM4_PRESC 511 // 5.25 MHz / (511 + 1) ~ 10,300 Hz
#define TIM5_PRESC 511 // 5.25 MHz / (511 + 1) ~ 10,300 Hz

#define MAX_ARR 65535
#define MIN_ARR 19 // this is the fastest a motor should go, 10 kHz / 20 = 500 ticks/second

void PWM_Initialize(void);
void PWM_EnableChannel(e_MotorNum motor_number);
void PWM_DisableChannel(e_MotorNum motor_number);
void PWM_SetArr(e_MotorNum motor_number, uint32_t arr_val);

#endif