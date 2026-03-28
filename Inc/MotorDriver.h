/*
filename: MotorDriver.h

header for MotorDriver.c
*/

#ifndef MTRDRVR_H
#define MTRDRVR_H

#include "main.h"

// Enum for motor selection. This will be used for switch cases on motor ops
typedef enum
{
    M0 = 0,
    M1,
    M2,
    M3,
    M4,
    M5
} e_MotorNum;

// Enum for motor details. Includes STEP, DIR, EN, etc.
typedef struct
{
    e_MotorNum motor_num;          // motor enum
    uint8_t motor_en_pin;          // enable pin
    uint8_t motor_dir_pin;         // direction pin
    GPIO_TypeDef *motor_step_port; // step port
    uint8_t motor_step_pin;        // step pin
} s_MotorStruct;

#endif
