/**
 * filename: MotorDriver.h
 * author: Benen Crombie
 *
 * header for MotorDriver.c
 */

#ifndef MTRDRVR_H
#define MTRDRVR_H

#include "main.h"

// Motor Speed Definitions
// NOTE each stepper motor has 1.8 deg stepping, so 200 steps/rev. Additionally, there are gear
// reductions for each cycloidal gearbox ranging from 19x to ... idk yet lol
// Frequency = F / [(PSC + 1) * (ARR + 1)]

#define LEEWAY_TICKS                                                                               \
    5 // Number of ticks to ensure that the motor reaches approach speed before target

// Motor 0 - 200 steps/rev, 19x gear reduction -> 3800 steps/joint rev
#define M0_APPROACH_ARR 10000
#define M0_RAMP_MS      1000 // milliseconds to fully ramp up or down

// Motor 1 - 200 steps/rev, 19x gear reduction -> 3800 steps/joint rev
#define M1_APPROACH_ARR 10000
#define M1_RAMP_MS      1000 // milliseconds to fully ramp up or down

// Motor 2 - 200 steps/rev, 19x gear reduction -> 3800 steps/joint rev
#define M2_APPROACH_ARR 10000
#define M2_RAMP_MS      1000 // milliseconds to fully ramp up or down

// Motor 3 - 200 steps/rev, 19x gear reduction -> 3800 steps/joint rev
#define M3_APPROACH_ARR 10000
#define M3_RAMP_MS      1000 // milliseconds to fully ramp up or down

// Motor 4 - 200 steps/rev, 19x gear reduction -> 3800 steps/joint rev
#define M4_APPROACH_ARR 10000
#define M4_RAMP_MS      1000 // milliseconds to fully ramp up or down

// Motor 5 - 200 steps/rev, 19x gear reduction -> 3800 steps/joint rev
#define M5_APPROACH_ARR 10000
#define M5_RAMP_MS      1000 // milliseconds to fully ramp up or down

// Enum for like the entire robot actuation system. Dictates all motors stopping, slowing down,
// disabled, etc.
typedef enum
{
    MTRSYS_DISABLED,      // Can't do anything with motors
    MTRSYS_RUNNING,       // Can do everything with motors
    MTRSYS_EMERGENCY_STOP // STOP EVERYTHING NOW, go to disabled after
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
    MTR_NONE,         // No destination state, might be useful in future implementations
    MTR_DISABLED,     // Motor is off, EN low
    MTR_BRAKED,       // EN is on, PWM disabled
    MTR_ACCELERATING, // Motor is accelerating. Counter tracked in struct
    MTR_DECELERATING, // Motor is decelerating. Counter tracked in struct
    MTR_ATSPEED,      // Motor is at target speed
    MTR_APPROACH      // Motor is approaching a target and full stop is controlled by ISR flags
} e_MotorState;

// Enum for motor details. Includes STEP, DIR, EN, etc.
typedef struct
{
    e_MotorNum motor_num;          // motor enum
    uint32_t motor_base_freq;      // base frequency, after PSC but before ARR is applied
    e_MotorState motor_state;      // motor state, enum is above this
    uint16_t motor_target_arr;     // how fast I want the motor to go (f = 1/arr)
    uint32_t motor_curr_arr;       // current arr, for tracking and checking states
    uint16_t motor_target_steps;   // how many steps I command the motor to take
    uint8_t motor_en_pin;          // enable pin
    uint8_t motor_dir_pin;         // direction pin
    GPIO_TypeDef *motor_step_port; // step port
    uint8_t motor_step_pin;        // step pin
    uint16_t motor_approach_arr;   // approach arr
    uint16_t motor_ramp_ms;        // milliseconds to ramp up or down fully
    uint16_t motor_ramp_ticks;     // number of ticks to ramp, calculated with a static function
    uint16_t motor_start_decel;    // the tick number to start decelerating, called on interrupt
    volatile uint8_t *motor_decel_flag; // pointer to deceleration flag
} s_MotorStruct;

// Prototypes
void Motors_StartMotor(uint8_t motor_num, uint32_t arr, uint16_t number_of_steps);
void Motors_DisableAll(void);
void Motors_EnableAll(void);
void Motors_RampDownAll(void);
void Motors_FSM_Initialize(void);
void Motors_FSM_Tick1000Hz(void);
void Motors_TIM2_IRQHandler(void);
void Motors_TIM3_IRQHandler(void);
void Motors_TIM4_IRQHandler(void);
void Motors_TIM5_IRQHandler(void);

#endif
