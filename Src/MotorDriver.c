/*
filename: MotorDriver.c

Controls motor through fsm. Motors have acceleration, deceleration, and at speed states
*/

// TODO need to figure out logic for enabling motors/pwms separately. For these motors, when EN is
// on but PWM is not, the joint is in brake mode which is good. If i completely unlatch EN whenever
// a motor isn't moving, it will be in freedrive.

#include "MotorDriver.h"
#include "GPIO.h"
#include "PWM.h"
#include "main.h"

// Overall motor actuation system state
e_MotorSystemState motor_system_state =
    MTRSYS_RUNNING; // TODO Start at DISABLED, jumping straight to RUNNING for testing purposes

/**
 * Motor structs:
 * Keeps track of motor pins, their state, and other useful information
 */
s_MotorStruct MOTOR0 = {
    .motor_num          = M0,
    .motor_state        = MTR_DISABLED,
    .motor_en_pin       = MTR0_EN_PIN,
    .motor_dir_pin      = MTR0_DIR_PIN,
    .motor_step_port    = MTR0_STEP_PORT,
    .motor_step_pin     = MTR0_STEP_PIN,
    .motor_slow_arr     = M0_ARR_SLOWSPEED,
    .motor_mid_arr      = M0_ARR_MIDSPEED,
    .motor_fast_arr     = M0_ARR_FASTSPEED,
    .motor_ramp_ticks   = M0_RAMP_TICKS,
    .motor_ramp_counter = 0,
};
s_MotorStruct MOTOR1 = {
    .motor_num          = M1,
    .motor_state        = MTR_DISABLED,
    .motor_en_pin       = MTR1_EN_PIN,
    .motor_dir_pin      = MTR1_DIR_PIN,
    .motor_step_port    = MTR1_STEP_PORT,
    .motor_step_pin     = MTR1_STEP_PIN,
    .motor_slow_arr     = M1_ARR_SLOWSPEED,
    .motor_mid_arr      = M1_ARR_MIDSPEED,
    .motor_fast_arr     = M1_ARR_FASTSPEED,
    .motor_ramp_ticks   = M1_RAMP_TICKS,
    .motor_ramp_counter = 0,
};
s_MotorStruct MOTOR2 = {
    .motor_num          = M2,
    .motor_state        = MTR_DISABLED,
    .motor_en_pin       = MTR2_EN_PIN,
    .motor_dir_pin      = MTR2_DIR_PIN,
    .motor_step_port    = MTR2_STEP_PORT,
    .motor_step_pin     = MTR2_STEP_PIN,
    .motor_slow_arr     = M2_ARR_SLOWSPEED,
    .motor_mid_arr      = M2_ARR_MIDSPEED,
    .motor_fast_arr     = M2_ARR_FASTSPEED,
    .motor_ramp_ticks   = M2_RAMP_TICKS,
    .motor_ramp_counter = 0,
};
s_MotorStruct MOTOR3 = {
    .motor_num          = M3,
    .motor_state        = MTR_DISABLED,
    .motor_en_pin       = MTR3_EN_PIN,
    .motor_dir_pin      = MTR3_DIR_PIN,
    .motor_step_port    = MTR3_STEP_PORT,
    .motor_step_pin     = MTR3_STEP_PIN,
    .motor_slow_arr     = M3_ARR_SLOWSPEED,
    .motor_mid_arr      = M3_ARR_MIDSPEED,
    .motor_fast_arr     = M3_ARR_FASTSPEED,
    .motor_ramp_ticks   = M3_RAMP_TICKS,
    .motor_ramp_counter = 0,
};
s_MotorStruct MOTOR4 = {
    .motor_num          = M4,
    .motor_state        = MTR_DISABLED,
    .motor_en_pin       = MTR4_EN_PIN,
    .motor_dir_pin      = MTR4_DIR_PIN,
    .motor_step_port    = MTR4_STEP_PORT,
    .motor_step_pin     = MTR4_STEP_PIN,
    .motor_slow_arr     = M4_ARR_SLOWSPEED,
    .motor_mid_arr      = M4_ARR_MIDSPEED,
    .motor_fast_arr     = M4_ARR_FASTSPEED,
    .motor_ramp_ticks   = M4_RAMP_TICKS,
    .motor_ramp_counter = 0,
};
s_MotorStruct MOTOR5 = {
    .motor_num          = M5,
    .motor_state        = MTR_DISABLED,
    .motor_en_pin       = MTR5_EN_PIN,
    .motor_dir_pin      = MTR5_DIR_PIN,
    .motor_step_port    = MTR5_STEP_PORT,
    .motor_step_pin     = MTR5_STEP_PIN,
    .motor_slow_arr     = M5_ARR_SLOWSPEED,
    .motor_mid_arr      = M5_ARR_MIDSPEED,
    .motor_fast_arr     = M5_ARR_FASTSPEED,
    .motor_ramp_ticks   = M5_RAMP_TICKS,
    .motor_ramp_counter = 0,
};

/**
 * @brief wrapper for PWM function. Changes the speed of the motor
 * @param *motor pointer to the motor struct
 * @param arr_val the value for the ARR
 * @return void
 */
static void SingleMotor_SetArr(s_MotorStruct *motor, uint32_t arr_val)
{
    // Call pwm function
    PWM_SetArr(motor->motor_num, arr_val);
}

/**
 * @brief accelerate a single motor. called within tick function
 * @param *motor pointer to the motor struct
 * @return void
 */
static void SingleMotor_AccelerateOnTick(s_MotorStruct *motor)
{
    // Check if we are at speed?

    // TODO calculate the nwe arr to increase speed

    // Increment ramp counter
    motor->motor_ramp_ticks++;
}

/**
 * @brief decelerate a single motor. called within teh tick function
 * @param *motor pointer to the motor struct
 * @return void
 */
static void SingleMotor_DecelerateOnTick(s_MotorStruct *motor)
{
    // Check if a motor is at the end of the ramp down sequence
    if (motor->motor_ramp_ticks == 0)
    {
        // Disable PWM, keeping EN pin on
        PWM_DisableChannel(motor->motor_num);

        // Change motor state to braked
        motor->motor_state = MTR_BRAKED;
    }
    else
    {
        // todo Calculate the new ARR to reduce speed

        // Decrement ramp counter
        motor->motor_ramp_ticks--;
    }
}

/**
 * @brief keep the motor at its current speed
 * @param *motor pointer to the motor sturct
 * @return void
 */
static void SingleMotor_CruiseAtSpeed(s_MotorStruct *motor)
{
    // Just keep cruising i guess
}

/**
 * @brief enable a single motor
 * @param *motor pointer to the motor struct
 * @return void
 */
static void SingleMotor_Enable(s_MotorStruct *motor)
{
    // TODO need to make sure motors 1&4 or 2&5 (whatever the pairing was) aren't enabled at the
    // same time. Figure out what to do here

    // NOTE this just enables the motor, but doesn't turn the PWM on. This will be handled elsewhere

    // Change motor state to accelerating
    motor->motor_state = MTR_ACCELERATING;

    // Set en pin
    GPIO_Set(MTR_EN_PORT, motor->motor_en_pin);
}

/**
 * @brief disable a single motor
 * @param *motor pointer to the motor struct
 * @return void
 */
static void SingleMotor_Disable(s_MotorStruct *motor)
{
    // Clear en pin
    GPIO_Clear(MTR_EN_PORT, motor->motor_en_pin);

    // Disable PWM channel
    PWM_DisableChannel(motor->motor_num);

    // Change motor state to stopped
    motor->motor_state = MTR_DISABLED;

    // Reset motor ramp counter
    motor->motor_ramp_counter = 0;
}

/**
 * @brief start decelerating a motor
 * @param *motor pointer to the motor struct
 * @return void
 */
static void SingleMotor_RampDownOnTick(s_MotorStruct *motor)
{
    // Change motor state to decel
    motor->motor_state = MTR_DECELERATING;
}

/**
 * @brief private function to update individual motor based on state
 * @param *motor pointer to the motor struct
 * @return void
 */
static void SingleMotor_UpdateOnTick(s_MotorStruct *motor)
{
    switch (motor->motor_state)
    {
    case MTR_DISABLED:
    }
}

/**
 * @brief Disable all motors. Emergency stop
 * @param void
 * @return void
 */
void Motors_DisableAll(void)
{
    // Clear all ENs - not putting these in the FSM itself because motors will stay in a DISABLED
    // state, so don't want to repeat this overhead if they're already off
    SingleMotor_Disable(&MOTOR0);
    SingleMotor_Disable(&MOTOR1);
    SingleMotor_Disable(&MOTOR2);
    SingleMotor_Disable(&MOTOR3);
    SingleMotor_Disable(&MOTOR4);
    SingleMotor_Disable(&MOTOR5);

    // Transition into disabled state
    motor_system_state = MTRSYS_DISABLED;
}

/**
 * @brief Ramp down all motors. Soft stop
 * @param void
 * @return void
 */
void Motors_RampDownAll(void)
{
    // Transition into ramp down state
    motor_system_state = MTRSYS_RAMP_DOWN;
}

/**
 * @brief Initialize the motors FSM
 * @param void
 * @return void
 */
void Motors_FSM_Initialize(void)
{
    // Called on startup or after an emergency stop. Not sure what the starting criteria will be
    // just yet.
    motor_system_state = MTRSYS_RUNNING;
}

/**
 * @brief Main tick of the motor FSM. Called in main
 * @param void
 * @return void
 */
void Motors_FSM_Tick(void)
{
    switch (motor_system_state)
    {
    case MTRSYS_DISABLED:
    {
        // Do nothing. Wait for something to transition into the running state
    }

    case MTRSYS_RAMP_DOWN:
    {
        SingleMotor_DecelerateOnTick(&MOTOR0);
        SingleMotor_DecelerateOnTick(&MOTOR1);
        SingleMotor_DecelerateOnTick(&MOTOR2);
        SingleMotor_DecelerateOnTick(&MOTOR3);
        SingleMotor_DecelerateOnTick(&MOTOR4);
        SingleMotor_DecelerateOnTick(&MOTOR5);

        // Check for if all motors are stopped, then enter BRAKED state
        if (0)
        {
            // TODO build out criteria
            motor_system_state = MTRSYS_BRAKED;
        }
    }

    case MTRSYS_BRAKED:
    {
        // Do nothing. Wait for something to transition into the running state
    }

    // State to do stuff with all motors
    case MTRSYS_RUNNING:
    {
        // Check if any state transitions should occur for any motors
        if (0)
        {
            // TODO build out criteria
        }

        // Update all motors with their new states
        SingleMotor_UpdateOnTick(&MOTOR0);
        SingleMotor_UpdateOnTick(&MOTOR1);
        SingleMotor_UpdateOnTick(&MOTOR2);
        SingleMotor_UpdateOnTick(&MOTOR3);
        SingleMotor_UpdateOnTick(&MOTOR4);
        SingleMotor_UpdateOnTick(&MOTOR5);
    }

    // State to emeergency stop (e.g., hard disable)
    case MTRSYS_EMERGENCY_STOP:
        // Stop all motors expeditiously
        Motors_DisableAll();
    }
}

// Motor FSM
