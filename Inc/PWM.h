/*
filename: PWM.h
author: Benen Crombie

Header for PWMs, timers 2,3,4, and 5
*/

#ifndef PWM_H
#define PWM_H

#include "MotorDriver.h"
#include "main.h"

// These are arbitrarily chosen. Speed of PWMs is adjusted with ARR
#define TIM2_PRESC 1023
#define TIM3_PRESC 1023
#define TIM4_PRESC 1023
#define TIM5_PRESC 1023

#define MAX_ARR 65535
#define MIN_ARR                                                                                    \
    1023 // TODO find a good min for the motors. Working with 1.8 degree steps and 19x gear
         // reductions on the mechanical side

void PWM_Initialize(void);
void PWM_EnableChannel(e_MotorNum motor_number);
void PWM_DisableChannel(e_MotorNum motor_number);
void PWM_SetArr(e_MotorNum motor_number, uint32_t arr_val);

#endif