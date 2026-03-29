/*
filename: MotorDriver.h

header for MotorDriver.c
*/

#ifndef MTRDRVR_H
#define MTRDRVR_H

#include "main.h"

// Enum for like the entire robot actuation system. Dictates all motors stopping, slowing down,
// disabled, etc.
typedef enum
{
    DISABLED,      // Can't do anything with motors
    RUNNING,       // Can do everything with motors
    RAMPDOWN,      // Start decelerating all motors from wherever they're at
    EMERGENCY_STOP // STOP EVERYTHING NOW, go to disabled after
} e_MotorSystemState;

// Enum for motor selection. This will be used for switch cases on motor ops.
// Having this might be redundant but couldn't figure out a clean way to do motor selection
typedef enum
{
    M0 = 0,
    M1,
    M2,
    M3,
    M4,
    M5
} e_MotorNum;

// Enum for motor states, assigned to each motor
typedef enum
{
    STOPPED,      // Motor is not moving
    ACCELERATING, // Motor is accelerating. Counter tracked in struct
    DECELERATING, // Motor is decelerating. Counter tracked in struct
    ATSPEED_SLOW, // Motor is going at slow speed
    ATSPEED_MID,  // Motor is going at mid speed
    ATSPEED_FAST  // Motor is going at fast speed
} e_MotorState;

// Enum for motor details. Includes STEP, DIR, EN, etc.
typedef struct
{
    e_MotorNum motor_num;          // motor enum
    e_MotorState motor_state;      // motor state, enum is above this
    uint8_t motor_en_pin;          // enable pin
    uint8_t motor_dir_pin;         // direction pin
    GPIO_TypeDef *motor_step_port; // step port
    uint8_t motor_step_pin;        // step pin
    uint8_t motor_ramp_counter;    // ramp counter, proportional to speed (kinda)
} s_MotorStruct;

// Motor Speed Definitions

// Prototypes
void Motors_DisableAll(void);
void Motors_FSM_Tick(void);

#endif
