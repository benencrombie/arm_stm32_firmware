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

uint32_t arr_reset_val = MAX_ARR;
uint32_t next_arr_val;

/**
 * Motor structs:
 * Keeps track of motor pins, their state, and other useful information
 */
s_MotorStruct MOTOR0 = {
    .motor_num               = M0,
    .motor_state             = MTR_DISABLED,
    .motor_destination_state = MTR_DISABLED,
    .motor_en_pin            = MTR0_EN_PIN,
    .motor_dir_pin           = MTR0_DIR_PIN,
    .motor_step_port         = MTR0_STEP_PORT,
    .motor_step_pin          = MTR0_STEP_PIN,
    .motor_current_arr       = MAX_ARR,
    .motor_slow_arr          = M0_ARR_SLOWSPEED,
    .motor_mid_arr           = M0_ARR_MIDSPEED,
    .motor_fast_arr          = M0_ARR_FASTSPEED,
    .motor_ramp_ticks        = M0_RAMP_TICKS,
    .motor_ramp_counter      = 0,
};
s_MotorStruct MOTOR1 = {
    .motor_num               = M1,
    .motor_state             = MTR_DISABLED,
    .motor_destination_state = MTR_DISABLED,
    .motor_en_pin            = MTR1_EN_PIN,
    .motor_dir_pin           = MTR1_DIR_PIN,
    .motor_step_port         = MTR1_STEP_PORT,
    .motor_step_pin          = MTR1_STEP_PIN,
    .motor_current_arr       = MAX_ARR,
    .motor_slow_arr          = M1_ARR_SLOWSPEED,
    .motor_mid_arr           = M1_ARR_MIDSPEED,
    .motor_fast_arr          = M1_ARR_FASTSPEED,
    .motor_ramp_ticks        = M1_RAMP_TICKS,
    .motor_ramp_counter      = 0,
};
s_MotorStruct MOTOR2 = {
    .motor_num               = M2,
    .motor_state             = MTR_DISABLED,
    .motor_destination_state = MTR_DISABLED,
    .motor_en_pin            = MTR2_EN_PIN,
    .motor_dir_pin           = MTR2_DIR_PIN,
    .motor_step_port         = MTR2_STEP_PORT,
    .motor_step_pin          = MTR2_STEP_PIN,
    .motor_current_arr       = MAX_ARR,
    .motor_slow_arr          = M2_ARR_SLOWSPEED,
    .motor_mid_arr           = M2_ARR_MIDSPEED,
    .motor_fast_arr          = M2_ARR_FASTSPEED,
    .motor_ramp_ticks        = M2_RAMP_TICKS,
    .motor_ramp_counter      = 0,
};
s_MotorStruct MOTOR3 = {
    .motor_num               = M3,
    .motor_state             = MTR_DISABLED,
    .motor_destination_state = MTR_DISABLED,
    .motor_en_pin            = MTR3_EN_PIN,
    .motor_dir_pin           = MTR3_DIR_PIN,
    .motor_step_port         = MTR3_STEP_PORT,
    .motor_step_pin          = MTR3_STEP_PIN,
    .motor_current_arr       = MAX_ARR,
    .motor_slow_arr          = M3_ARR_SLOWSPEED,
    .motor_mid_arr           = M3_ARR_MIDSPEED,
    .motor_fast_arr          = M3_ARR_FASTSPEED,
    .motor_ramp_ticks        = M3_RAMP_TICKS,
    .motor_ramp_counter      = 0,
};
s_MotorStruct MOTOR4 = {
    .motor_num               = M4,
    .motor_state             = MTR_DISABLED,
    .motor_destination_state = MTR_DISABLED,
    .motor_en_pin            = MTR4_EN_PIN,
    .motor_dir_pin           = MTR4_DIR_PIN,
    .motor_step_port         = MTR4_STEP_PORT,
    .motor_step_pin          = MTR4_STEP_PIN,
    .motor_current_arr       = MAX_ARR,
    .motor_slow_arr          = M4_ARR_SLOWSPEED,
    .motor_mid_arr           = M4_ARR_MIDSPEED,
    .motor_fast_arr          = M4_ARR_FASTSPEED,
    .motor_ramp_ticks        = M4_RAMP_TICKS,
    .motor_ramp_counter      = 0,
};
s_MotorStruct MOTOR5 = {
    .motor_num               = M5,
    .motor_state             = MTR_DISABLED,
    .motor_destination_state = MTR_DISABLED,
    .motor_en_pin            = MTR5_EN_PIN,
    .motor_dir_pin           = MTR5_DIR_PIN,
    .motor_step_port         = MTR5_STEP_PORT,
    .motor_step_pin          = MTR5_STEP_PIN,
    .motor_current_arr       = MAX_ARR,
    .motor_slow_arr          = M5_ARR_SLOWSPEED,
    .motor_mid_arr           = M5_ARR_MIDSPEED,
    .motor_fast_arr          = M5_ARR_FASTSPEED,
    .motor_ramp_ticks        = M5_RAMP_TICKS,
    .motor_ramp_counter      = 0,
};

/**
 * Private Functions
 *
 *
 *
 *
 */

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

    // Update tracking in struct
    motor->motor_current_arr = arr_val;
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

    // Change motor state to braked. This just enables the motor, but doesn't turn the PWM on. This
    // will be handled elsewhere
    motor->motor_state = MTR_BRAKED;

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

    // Reset the arr val in struct for tracking
    SingleMotor_SetArr(motor, arr_reset_val);

    // Change motor state to stopped
    motor->motor_state = MTR_DISABLED;

    // Reset motor ramp counter
    motor->motor_ramp_counter = 0;
}

/**
 * Public API
 *
 *
 *
 *
 *
 */

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
    // Set all motor's destination states to braked
    MOTOR0.motor_destination_state = MTR_BRAKED;
    MOTOR1.motor_destination_state = MTR_BRAKED;
    MOTOR2.motor_destination_state = MTR_BRAKED;
    MOTOR3.motor_destination_state = MTR_BRAKED;
    MOTOR4.motor_destination_state = MTR_BRAKED;
    MOTOR5.motor_destination_state = MTR_BRAKED;

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
    // Called on startup or after an emergency stop.

    ///////////////////////////
    // TODO remove from init once I make a trigger for spinning up motors
    PWM_EnableChannel(M0);
    PWM_EnableChannel(M1);
    PWM_EnableChannel(M2);
    PWM_EnableChannel(M3);
    PWM_EnableChannel(M4);
    PWM_EnableChannel(M5);

    MOTOR0.motor_destination_state = MTR_ATSPEED_FAST;
    MOTOR1.motor_destination_state = MTR_ATSPEED_FAST;
    MOTOR2.motor_destination_state = MTR_ATSPEED_FAST;
    MOTOR3.motor_destination_state = MTR_ATSPEED_FAST;
    MOTOR4.motor_destination_state = MTR_ATSPEED_FAST;
    MOTOR5.motor_destination_state = MTR_ATSPEED_FAST;
    ///////////////////////////

    // Kick off the fsm by jumping into BRAKED
    motor_system_state = MTRSYS_RUNNING; // TODO change to braked when done testing
}

void Motors_SendPositionCommand(void)
{
    // TODO build out a payload to tell a motor to rotate X degrees. This is going to be sick dude
}

/**
 * FSM Operations
 *
 *
 *
 *
 */

/**
 * @brief accelerate a single motor. called within tick function
 * @param *motor pointer to the motor struct
 * @return void
 */
static void SingleMotor_AccelerateOnTick(s_MotorStruct *motor)
{
    // Calculate the new ARR to increase speed TODO
    next_arr_val = 999;

    // Check lower bound
    if (next_arr_val < MIN_ARR)
    {
        next_arr_val = MIN_ARR;
    }

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
    // Calculate the new arr to reduce speed TODO
    next_arr_val = 999;

    // Compare arr to the destination state. Motors can either slow to a stop (BRAKED) or to a
    // slower speed. Eventually I might make just make the destination an arr value from
    // analog/joystick input
    switch (motor->motor_destination_state)
    {
        case MTR_BRAKED:
        {
            // Check if the new arr is bottomed out
            if (next_arr_val >= arr_reset_val)
            {
                // Disable PWM, keeping EN pin on
                PWM_DisableChannel(motor->motor_num);

                // Set arr to max
                SingleMotor_SetArr(motor, arr_reset_val);

                // Change motor state to braked
                motor->motor_state = MTR_BRAKED;
            }
            else
            {
                SingleMotor_SetArr(motor, next_arr_val);
            }
            break;
        }
        case MTR_ATSPEED_SLOW:
        {
            // Check if a motor's arr is at slow/overshot
            if (next_arr_val >= motor->motor_slow_arr)
            {
                // Set the arr to the slow arr
                next_arr_val = motor->motor_slow_arr;
                SingleMotor_SetArr(motor, next_arr_val);

                // Change the motor state to at speed
                motor->motor_state = MTR_ATSPEED_SLOW;
            }
            else
            {
                SingleMotor_SetArr(motor, next_arr_val);
            }
            break;
        }
        case MTR_ATSPEED_MID:
        {
            // Check if a motor's arr is at mid/overshot
            if (next_arr_val >= motor->motor_mid_arr)
            {
                // Set the arr to the mid arr
                next_arr_val = motor->motor_mid_arr;
                SingleMotor_SetArr(motor, next_arr_val);

                // Change the motor state to at speed
                motor->motor_state = MTR_ATSPEED_MID;
            }
            break;
        }
        case MTR_ATSPEED_FAST:
        {
            // Check if a motor's arr is at fast/overshot
            if (next_arr_val >= motor->motor_fast_arr)
            {
                // Set the arr to the fast arr
                next_arr_val = motor->motor_fast_arr;
                SingleMotor_SetArr(motor, next_arr_val);

                // Change the motor state to at speed
                motor->motor_state = MTR_ATSPEED_FAST;
            }
            break;
        }
        default:
        {
            // Invalid destination state. Shouldn't happen
            break;
        }
    }
}

/**
 * @brief keep the motor at its current speed and check if it's approaching target
 * @param *motor pointer to the motor sturct
 * @return void
 */
static void SingleMotor_CruiseOnTick(s_MotorStruct *motor)
{
    // TODO use position params or something else to determine when we need to start
    // decelerating.
}

/**
 * @brief private function to update individual motor based on state. this does not handle state
 * changes
 * @param *motor pointer to the motor struct
 * @return void
 */
static void SingleMotor_UpdateOnTick(s_MotorStruct *motor)
{
    // check if accelerating or decelerating...
    // Then, within those, check current arr to what the arr should be
    // Then, transition into a state if applicable
    switch (motor->motor_state)
    {
        case MTR_DISABLED:
        {
            /* no op? */
            break;
        }
        case MTR_BRAKED:
        {
            /* no op? */
            break;
        }
        case MTR_ACCELERATING:
        {
            SingleMotor_AccelerateOnTick(motor);
            break;
        }
        case MTR_DECELERATING:
        {
            SingleMotor_DecelerateOnTick(motor);
            break;
        }
        case MTR_ATSPEED_SLOW:
        {
            SingleMotor_CruiseOnTick(motor);
            break;
        }
        case MTR_ATSPEED_MID:
        {
            SingleMotor_CruiseOnTick(motor);
            break;
        }
        case MTR_ATSPEED_FAST:
        {
            SingleMotor_CruiseOnTick(motor);
            break;
        }
    }
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
            break;
        }

        case MTRSYS_RAMP_DOWN:
        {
            // Decelerate all motors
            SingleMotor_DecelerateOnTick(&MOTOR0);
            SingleMotor_DecelerateOnTick(&MOTOR1);
            SingleMotor_DecelerateOnTick(&MOTOR2);
            SingleMotor_DecelerateOnTick(&MOTOR3);
            SingleMotor_DecelerateOnTick(&MOTOR4);
            SingleMotor_DecelerateOnTick(&MOTOR5);

            // Check for if all motors are stopped, then enter BRAKED system state
            if (MOTOR0.motor_state == MTR_BRAKED && MOTOR1.motor_state == MTR_BRAKED &&
                MOTOR2.motor_state == MTR_BRAKED && MOTOR3.motor_state == MTR_BRAKED &&
                MOTOR4.motor_state == MTR_BRAKED && MOTOR5.motor_state == MTR_BRAKED)
            {
                // TODO build out criteria
                motor_system_state = MTRSYS_BRAKED;
            }

            break;
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

            // Update all motors with their respective states
            SingleMotor_UpdateOnTick(&MOTOR0);
            SingleMotor_UpdateOnTick(&MOTOR1);
            SingleMotor_UpdateOnTick(&MOTOR2);
            SingleMotor_UpdateOnTick(&MOTOR3);
            SingleMotor_UpdateOnTick(&MOTOR4);
            SingleMotor_UpdateOnTick(&MOTOR5);
            break;
        }

        // State to emeergency stop (e.g., hard disable)
        case MTRSYS_EMERGENCY_STOP:
            // Stop all motors expeditiously
            Motors_DisableAll();
            break;
    }
}