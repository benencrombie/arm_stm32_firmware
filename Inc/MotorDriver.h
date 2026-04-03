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
// reductions for each cycloidal gearbox ranging from 19x to ...
// Frequency = F / [(PSC + 1) * (ARR + 1)]

// Motor 0 - 200 steps/rev, 19x gear reduction -> 3800 steps/joint rev
#define M0_ARR_SLOWSPEED 820 // f = 84M / [(1023 + 1)(~820 + 1)], 100 Hz (0.5 rev/sec)
#define M0_ARR_MIDSPEED  410 // f = 84M / [(1023 + 1)(~410 + 1)], 200 Hz (1.0 rev/sec)
#define M0_ARR_FASTSPEED 275 // f = 84M / [(1023 + 1)(~275 + 1)], 300 Hz (1.5 rev/sec)
#define M0_RAMP_STEPS                                                                              \
    1000 // 1000 ms to ramp up from 0 to full speed. Will use the same rate to ramp to mid or fast
         // speed, so those rampups will just be quicker

// Motor 1 - 200 steps/rev, 19x gear reduction -> 3800 steps/joint rev
#define M1_ARR_SLOWSPEED 820  // f = 84M / [(1023 + 1)(~820 + 1)], 100 Hz (0.5 rev/sec)
#define M1_ARR_MIDSPEED  410  // f = 84M / [(1023 + 1)(~410 + 1)], 200 Hz (1.0 rev/sec)
#define M1_ARR_FASTSPEED 275  // f = 84M / [(1023 + 1)(~275 + 1)], 300 Hz (1.5 rev/sec)
#define M1_RAMP_STEPS    1000 // 1000 ms to ramp up from 0 to full speed

// Motor 2 - 200 steps/rev, 19x gear reduction -> 3800 steps/joint rev
#define M2_ARR_SLOWSPEED 820  // f = 84M / [(1023 + 1)(~820 + 1)], 100 Hz (0.5 rev/sec)
#define M2_ARR_MIDSPEED  410  // f = 84M / [(1023 + 1)(~410 + 1)], 200 Hz (1.0 rev/sec)
#define M2_ARR_FASTSPEED 275  // f = 84M / [(1023 + 1)(~275 + 1)], 300 Hz (1.5 rev/sec)
#define M2_RAMP_STEPS    1000 // 1000 ms to ramp up from 0 to full speed

// Motor 3 - 200 steps/rev, 19x gear reduction -> 3800 steps/joint rev
#define M3_ARR_SLOWSPEED 820  // f = 84M / [(1023 + 1)(~820 + 1)], 100 Hz (0.5 rev/sec)
#define M3_ARR_MIDSPEED  410  // f = 84M / [(1023 + 1)(~410 + 1)], 200 Hz (1.0 rev/sec)
#define M3_ARR_FASTSPEED 275  // f = 84M / [(1023 + 1)(~275 + 1)], 300 Hz (1.5 rev/sec)
#define M3_RAMP_STEPS    1000 // 1000 ms to ramp up from 0 to full speed

// Motor 4 - 200 steps/rev, 19x gear reduction -> 3800 steps/joint rev
#define M4_ARR_SLOWSPEED 820  // f = 84M / [(1023 + 1)(~820 + 1)], 100 Hz (0.5 rev/sec)
#define M4_ARR_MIDSPEED  410  // f = 84M / [(1023 + 1)(~410 + 1)], 200 Hz (1.0 rev/sec)
#define M4_ARR_FASTSPEED 275  // f = 84M / [(1023 + 1)(~275 + 1)], 300 Hz (1.5 rev/sec)
#define M4_RAMP_STEPS    1000 // 1000 ms to ramp up from 0 to full speed

// Motor 5 - 200 steps/rev, 19x gear reduction -> 3800 steps/joint rev
#define M5_ARR_SLOWSPEED 820  // f = 84M / [(1023 + 1)(~820 + 1)], 100 Hz (0.5 rev/sec)
#define M5_ARR_MIDSPEED  410  // f = 84M / [(1023 + 1)(~410 + 1)], 200 Hz (1.0 rev/sec)
#define M5_ARR_FASTSPEED 275  // f = 84M / [(1023 + 1)(~275 + 1)], 300 Hz (1.5 rev/sec)
#define M5_RAMP_STEPS    1000 // 1000 ms to ramp up from 0 to full speed

// Enum for like the entire robot actuation system. Dictates all motors stopping, slowing down,
// disabled, etc.
typedef enum
{
    MTRSYS_DISABLED,      // Can't do anything with motors
    MTRSYS_RAMP_DOWN,     // All motors decelerating, approaching BRAKED state
    MTRSYS_BRAKED,        // All motor ENs are on, but speeds are 0
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
    MTR_DISABLED,     // Motor is off, EN low
    MTR_BRAKED,       // EN is on, PWM disabled
    MTR_ACCELERATING, // Motor is accelerating. Counter tracked in struct
    MTR_DECELERATING, // Motor is decelerating. Counter tracked in struct
    MTR_ATSPEED_SLOW, // Motor is going at slow speed
    MTR_ATSPEED_MID,  // Motor is going at mid speed
    MTR_ATSPEED_FAST  // Motor is going at fast speed
} e_MotorState;

// Enum for motor details. Includes STEP, DIR, EN, etc.
typedef struct
{
    e_MotorNum motor_num;                 // motor enum
    e_MotorState motor_state;             // motor state, enum is above this
    e_MotorState motor_destination_state; // destination state. what speed the motor approaches
    uint16_t motor_destination_steps;     // how many steps I command the motor to take
    uint8_t motor_en_pin;                 // enable pin
    uint8_t motor_dir_pin;                // direction pin
    GPIO_TypeDef *motor_step_port;        // step port
    uint8_t motor_step_pin;               // step pin
    uint32_t motor_current_arr;           // current arr
    uint16_t motor_slow_arr;              // slowest arr
    uint16_t motor_mid_arr;               // mid arr
    uint16_t motor_fast_arr;              // fastest arr
    uint16_t motor_ramp_steps; // number of steps to ramp from 0 to full speed. Right now this is
                               // for all ramps, even if its a step up from slow to mid speed. Fine
                               // for now and I don't want a ton of bloat in this struct, but keep
                               // in mind for future optimizations
    uint32_t *motor_step_counter; // pointer to the steps counter
} s_MotorStruct;

// Prototypes
void Motors_StartMotor(uint8_t motor_num, uint8_t target_speed, uint16_t number_of_steps);
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
