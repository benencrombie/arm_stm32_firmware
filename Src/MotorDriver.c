/**
 * filename: MotorDriver.c
 * author: Benen Crombie
 *
 * Controls motor through fsm. Motors have acceleration, deceleration, and at speed states
Motor speed profiles are controlled at a 1000 Hz (every millisecond) tick. To ensure accurate
position with just the steppers, motor stops (PWM disabling) is monitored on timer interrupts. This
prevents there being a desync between the timer and 1000 Hz ticker.
 */

#include "MotorDriver.h"
#include "GPIO.h"
#include "PWM.h"
#include "USART.h"
#include "main.h"

// Overall motor actuation system state
e_MotorSystemState motor_system_state =
    MTRSYS_RUNNING; // TODO Start at DISABLED, jumping straight to RUNNING for testing purposes

// Motor variables
uint32_t arr_reset_val = MAX_ARR;
uint32_t next_arr_val;
uint32_t tim2_step_counter = 0;
uint32_t tim3_step_counter = 0;
uint32_t tim4_step_counter = 0;
uint32_t tim5_step_counter = 0;
bool tim2_paused = 0; // Not really tim2 being paused, but whatever motor is on that timer at a
                      // given point. Functionality for later, not needed now.
bool tim3_paused = 0;
bool tim4_paused = 0;
bool tim5_paused = 0;

/**
 * Motor structs:
 * Keeps track of motor pins, their state, and other useful information
 */
s_MotorStruct MOTOR0 = {
    .motor_num               = M0,
    .motor_state             = MTR_DISABLED,
    .motor_destination_state = MTR_DISABLED,
    .motor_destination_steps = 0,
    .motor_en_pin            = MTR0_EN_PIN,
    .motor_dir_pin           = MTR0_DIR_PIN,
    .motor_step_port         = MTR0_STEP_PORT,
    .motor_step_pin          = MTR0_STEP_PIN,
    .motor_current_arr       = MAX_ARR,
    .motor_slow_arr          = M0_ARR_SLOWSPEED,
    .motor_mid_arr           = M0_ARR_MIDSPEED,
    .motor_fast_arr          = M0_ARR_FASTSPEED,
    .motor_ramp_accel        = M0_RAMP_ACCEL,
    .motor_ramp_vel          = 0,
    .motor_step_counter      = &tim2_step_counter,
};
s_MotorStruct MOTOR1 = {
    .motor_num               = M1,
    .motor_state             = MTR_DISABLED,
    .motor_destination_state = MTR_DISABLED,
    .motor_destination_steps = 0,
    .motor_en_pin            = MTR1_EN_PIN,
    .motor_dir_pin           = MTR1_DIR_PIN,
    .motor_step_port         = MTR1_STEP_PORT,
    .motor_step_pin          = MTR1_STEP_PIN,
    .motor_current_arr       = MAX_ARR,
    .motor_slow_arr          = M1_ARR_SLOWSPEED,
    .motor_mid_arr           = M1_ARR_MIDSPEED,
    .motor_fast_arr          = M1_ARR_FASTSPEED,
    .motor_ramp_accel        = M1_RAMP_ACCEL,
    .motor_ramp_vel          = 0,
    .motor_step_counter      = &tim3_step_counter,
};
s_MotorStruct MOTOR2 = {
    .motor_num               = M2,
    .motor_state             = MTR_DISABLED,
    .motor_destination_state = MTR_DISABLED,
    .motor_destination_steps = 0,
    .motor_en_pin            = MTR2_EN_PIN,
    .motor_dir_pin           = MTR2_DIR_PIN,
    .motor_step_port         = MTR2_STEP_PORT,
    .motor_step_pin          = MTR2_STEP_PIN,
    .motor_current_arr       = MAX_ARR,
    .motor_slow_arr          = M2_ARR_SLOWSPEED,
    .motor_mid_arr           = M2_ARR_MIDSPEED,
    .motor_fast_arr          = M2_ARR_FASTSPEED,
    .motor_ramp_accel        = M2_RAMP_ACCEL,
    .motor_ramp_vel          = 0,
    .motor_step_counter      = &tim4_step_counter,
};
s_MotorStruct MOTOR3 = {
    .motor_num               = M3,
    .motor_state             = MTR_DISABLED,
    .motor_destination_state = MTR_DISABLED,
    .motor_destination_steps = 0,
    .motor_en_pin            = MTR3_EN_PIN,
    .motor_dir_pin           = MTR3_DIR_PIN,
    .motor_step_port         = MTR3_STEP_PORT,
    .motor_step_pin          = MTR3_STEP_PIN,
    .motor_current_arr       = MAX_ARR,
    .motor_slow_arr          = M3_ARR_SLOWSPEED,
    .motor_mid_arr           = M3_ARR_MIDSPEED,
    .motor_fast_arr          = M3_ARR_FASTSPEED,
    .motor_ramp_accel        = M3_RAMP_ACCEL,
    .motor_ramp_vel          = 0,
    .motor_step_counter      = &tim5_step_counter,
};
s_MotorStruct MOTOR4 = {
    .motor_num               = M4,
    .motor_state             = MTR_DISABLED,
    .motor_destination_state = MTR_DISABLED,
    .motor_destination_steps = 0,
    .motor_en_pin            = MTR4_EN_PIN,
    .motor_dir_pin           = MTR4_DIR_PIN,
    .motor_step_port         = MTR4_STEP_PORT,
    .motor_step_pin          = MTR4_STEP_PIN,
    .motor_current_arr       = MAX_ARR,
    .motor_slow_arr          = M4_ARR_SLOWSPEED,
    .motor_mid_arr           = M4_ARR_MIDSPEED,
    .motor_fast_arr          = M4_ARR_FASTSPEED,
    .motor_ramp_accel        = M4_RAMP_ACCEL,
    .motor_ramp_vel          = 0,
    .motor_step_counter      = &tim2_step_counter,
};
s_MotorStruct MOTOR5 = {
    .motor_num               = M5,
    .motor_state             = MTR_DISABLED,
    .motor_destination_state = MTR_DISABLED,
    .motor_destination_steps = 0,
    .motor_en_pin            = MTR5_EN_PIN,
    .motor_dir_pin           = MTR5_DIR_PIN,
    .motor_step_port         = MTR5_STEP_PORT,
    .motor_step_pin          = MTR5_STEP_PIN,
    .motor_current_arr       = MAX_ARR,
    .motor_slow_arr          = M5_ARR_SLOWSPEED,
    .motor_mid_arr           = M5_ARR_MIDSPEED,
    .motor_fast_arr          = M5_ARR_FASTSPEED,
    .motor_ramp_accel        = M5_RAMP_ACCEL,
    .motor_ramp_vel          = 0,
    .motor_step_counter      = &tim3_step_counter,
};

/**
 * Private Functions
 *
 * These are helper funcitons used in the public API's abstraction. There should not be a need to
 * call any of these outside of this module.
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
    // Change motor state to braked. This just enables the motor, but doesn't turn the PWM on. This
    // will be handled elsewhere
    motor->motor_state = MTR_BRAKED;

    // Set en pin
    GPIO_Set(MTR_EN_PORT, motor->motor_en_pin);
}

/**
 * @brief starts a single motor's pwm
 * @param *motor pointer to the motor struct
 * @param destination_state the destination motor state
 * @param destination_steps how many steps to take upon starting the motor
 * @return void
 */
static void SingleMotor_StartWithDestination(s_MotorStruct *motor, uint8_t destination_state,
                                             uint16_t destination_steps)
{
    // Initialize flag for illegal motor start
    uint8_t f_illegal_motor_start = 0;

    // Check if this pwm is allowed to start. Only restrictions are on motors 0 & 4, then 1 & 5
    // running at the same time bc they're on the same timers.
    switch (motor->motor_num)
    {
        case M0:
        {
            // If motor 4 is running, nuh uh
            if (MOTOR4.motor_state != MTR_BRAKED && MOTOR4.motor_state != MTR_DISABLED)
            {
                // Don't do that
                f_illegal_motor_start = 1;

#ifdef DEBUG_MOTORS
                USART2_SendString("Tried to start motor 0, but motor 4 is running");
#endif
            }
            break;
        }
        case M1:
        {
            // If motor 5 is running, nuh uh
            if (MOTOR5.motor_state != MTR_BRAKED && MOTOR5.motor_state != MTR_DISABLED)
            {
                // Don't do that
                f_illegal_motor_start = 1;

#ifdef DEBUG_MOTORS
                USART2_SendString("Tried to start motor 1, but motor 5 is running");
#endif
            }
            break;
        }
        case M2:
        {
            /* no op. ur good */
            break;
        }
        case M3:
        {
            /* no op. ur good */
            break;
        }
        case M4:
        {
            // If motor 0 is running, nuh uh
            if (MOTOR0.motor_state != MTR_BRAKED && MOTOR4.motor_state != MTR_DISABLED)
            {
                // Don't do that
                f_illegal_motor_start = 1;

#ifdef DEBUG_MOTORS
                USART2_SendString("Tried to start motor 4, but motor 0 is running");
#endif
            }
            break;
        }
        case M5:
        {
            // If motor 1 is running, nuh uh
            if (MOTOR4.motor_state != MTR_BRAKED && MOTOR4.motor_state != MTR_DISABLED)
            {
                // Don't do that
                f_illegal_motor_start = 1;

#ifdef DEBUG_MOTORS
                USART2_SendString("Tried to start motor 5, but motor 1 is running");
#endif
            }
            break;
        }
    }

    // Start accelerating the motor if allowed
    if (!f_illegal_motor_start)
    {
        // Set the current state to accelerating
        motor->motor_state = MTR_ACCELERATING;

        // Set the new destination state
        motor->motor_destination_state = destination_state;

        // Tell the motor how many steps to go
        motor->motor_destination_steps = destination_steps;

        // Enable the PWM channel
        PWM_EnableChannel(motor->motor_num);
    }
}

/**
 * @brief Public wrapper to start up a motor with explicit instructions
 * @param motor_num the motor number
 * @param target_speed the target speedd (e.g., MTR_ATSPEED_SLOW)
 * @param number_of_steps the number of steps to take in this instruction
 * @return void
 */
void Motors_StartMotor(uint8_t motor_num, uint8_t target_speed, uint16_t number_of_steps)
{
    switch (motor_num)
    {
        case M0:
            SingleMotor_StartWithDestination(&MOTOR0, target_speed, number_of_steps);
        case M1:
            SingleMotor_StartWithDestination(&MOTOR0, target_speed, number_of_steps);
        case M2:
            SingleMotor_StartWithDestination(&MOTOR0, target_speed, number_of_steps);
        case M3:
            SingleMotor_StartWithDestination(&MOTOR0, target_speed, number_of_steps);
        case M4:
            SingleMotor_StartWithDestination(&MOTOR0, target_speed, number_of_steps);
    }
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

    // Disable PWM channel. There is no situation to have PWM on but the EN cleared
    PWM_DisableChannel(motor->motor_num);

    // Reset the arr val in struct for tracking
    SingleMotor_SetArr(motor, arr_reset_val);

    // Change motor state to stopped
    motor->motor_state = MTR_DISABLED;
}

/**
 * @brief function to check if any motors on tim2 need to be stopped based on their destination
 * steps
 * @param void
 * @return flag for if motor should be stopped
 */
static bool Motors_CheckToStopTim2(void)
{
    // Check which motor is running
    if (MOTOR0.motor_state != MTR_BRAKED && MOTOR0.motor_state != MTR_DISABLED)
    {
        // Check if the counter has passsed destination steps, return true if it has and unplug it
        if (*(MOTOR0.motor_step_counter) >= MOTOR0.motor_destination_steps)
        {
            // Disable channel
            PWM_DisableChannel(M0);

            // Reset relevant vars
            *(MOTOR0.motor_step_counter) = 0;

            // Change the states
            MOTOR0.motor_state             = MTR_BRAKED;
            MOTOR0.motor_destination_state = MTR_BRAKED;

            return true;
        }
    }
    else if (MOTOR4.motor_state != MTR_BRAKED && MOTOR4.motor_state != MTR_DISABLED)
    {
        if (*(MOTOR4.motor_step_counter) >= MOTOR4.motor_destination_steps)
        {
            // Disable channel
            PWM_DisableChannel(M4);

            // Reset relevant vars
            *(MOTOR4.motor_step_counter) = 0;

            // Change the states
            MOTOR4.motor_state             = MTR_BRAKED;
            MOTOR4.motor_destination_state = MTR_BRAKED;

            return true;
        }
    }
    else
    {
        // Not sure why the interrupt was called. This shouldn't happen
        return false;
    }

    // Fall back to false if no stopping conditions are met
    return false;
}

/**
 * @brief function to check if any motors on tim3 need to be stopped based on their destination
 * steps
 * @param void
 * @return flag for if motor should be stopped
 */
static bool Motors_CheckToStopTim3(void)
{
    // Check which motor is running
    if (MOTOR1.motor_state != MTR_BRAKED && MOTOR1.motor_state != MTR_DISABLED)
    {
        if (*(MOTOR1.motor_step_counter) >= MOTOR1.motor_destination_steps)
        {
            // Disable channel
            PWM_DisableChannel(M1);

            // Reset relevant vars
            *(MOTOR1.motor_step_counter) = 0;

            // Change the states
            MOTOR1.motor_state             = MTR_BRAKED;
            MOTOR1.motor_destination_state = MTR_BRAKED;

            return true;
        }
    }
    else if (MOTOR5.motor_state != MTR_BRAKED && MOTOR5.motor_state != MTR_DISABLED)
    {
        if (*(MOTOR5.motor_step_counter) >= MOTOR5.motor_destination_steps)
        {
            // Disable channel
            PWM_DisableChannel(M5);

            // Reset relevant vars
            *(MOTOR5.motor_step_counter) = 0;

            // Change the states
            MOTOR5.motor_state             = MTR_BRAKED;
            MOTOR5.motor_destination_state = MTR_BRAKED;

            return true;
        }
    }
    else
    {
        // Not sure why the interrupt was called. This shouldn't happen
        return false;
    }

    // Fall back to false if no stopping conditions are met
    return false;
}

/**
 * @brief function to check if any motors on tim4 need to be stopped based on their destination
 * steps
 * @param void
 * @return flag for if motor should be stopped
 */
static bool Motors_CheckToStopTim4(void)
{
    if (MOTOR2.motor_state != MTR_BRAKED && MOTOR2.motor_state != MTR_DISABLED)
    {
        if (*(MOTOR2.motor_step_counter) >= MOTOR2.motor_destination_steps)
        {
            // Disable channel
            PWM_DisableChannel(M2);

            // Reset relevant vars
            *(MOTOR2.motor_step_counter) = 0;

            // Change the states
            MOTOR2.motor_state             = MTR_BRAKED;
            MOTOR2.motor_destination_state = MTR_BRAKED;

            return true;
        }
    }
    else
    {
        // Not sure why the interrupt was called. This shouldn't happen
        return false;
    }

    // Fall back to false if no stopping conditions are met
    return false;
}

/**
 * @brief function to check if any motors on tim5 need to be stopped based on their destination
 * steps
 * @param void
 * @return flag for if motor should be stopped
 */
static bool Motors_CheckToStopTim5(void)
{
    if (MOTOR3.motor_state != MTR_BRAKED && MOTOR3.motor_state != MTR_DISABLED)
    {
        if (*(MOTOR3.motor_step_counter) >= MOTOR3.motor_destination_steps)
        {
            // Disable channel
            PWM_DisableChannel(M3);

            // Reset relevant vars
            *(MOTOR3.motor_step_counter) = 0;

            // Change the states
            MOTOR3.motor_state             = MTR_BRAKED;
            MOTOR3.motor_destination_state = MTR_BRAKED;

            return true;
        }
    }
    else
    {
        // Not sure why the interrupt was called. This shouldn't happen
        return false;
    }

    // Fall back to false if no stopping conditions are met
    return false;
}

/**
 * @brief calculate the next ARR value given the current, target, and steps
 * @param state the motor state (accel or decel expected)
 * @param curr_arr current arr value
 * @param ramp_accel how aggressively to ramp
 * @return the next arr value
 */
static uint32_t Calculate_NextArr(uint8_t state, uint32_t curr_arr, uint32_t ramp_accel)
{
    // NOTE I think my math is fine here. Testing this by just visually taking a look at motor ramp
    // ups and ramp downs.
    //
    // Constant acceleration and deceleration profile:
    // The frequency is proportional to 1/arr. I am aiming to a linear velocity profile, given a
    // constant acceleration, ramp_accel, for that is a characteristic in the motor structs.
    // The challenge here is that I call this function on the timer interrupt so I am able to easily
    // track number of steps for position and that there are no spurious ticks (though this should
    // be avoided with preloading). Therefore, the acceleration profile must account for a non
    // linear updating time. Ideally, the next arr can be implicitly calculated from the current arr
    // and acceleration constant, rather than time.
    //
    // Here's my derivation for a recursive calculation of ARR, probably pretty close to what it
    // should be.
    //
    // TARGET EQUATION) ARR = ARR_prev + Delta(ARR)
    // - ARR_prev will simply be the motor's characteristic, curr_arr.
    // - delta(ARR) should be a function of ARR_prev
    //
    // Eq. 1) Stepper_Frequency = Timer_Frequency / [(1 + ARR) * (1 + PSC)].
    // - PSC is a characteristic of the motor, and therefore is not changed
    // - Timer frequency is dependent on prescaling, and therefore is a motor characteristic and not
    // changed.
    // - Stepper frequency is directly proportional to rotational speed of the motor
    // - I'm just going to drop teh "1" in 1 + ARR since this hardly adds precision, just
    // complicates things
    //
    // Eq. 2) Stepper_Frequency = C * (1 / ARR), where C = Timer_Frequency / PSC.
    // - Simplification of Eq. 1
    //
    // Eq. 4) Stepper_Frequency^2 = Previous_Stepper_Frequency^2 + (2 * RAMP_ACCEL)
    // - Simple kinematic derivation,
    //
    // Eq. 5) (C / ARR)^2 = (C / Previous_ARR)^2 + 2 * RAMP_ACCEL
    // - Substituting equation for stepper frequency back in
    //
    // Next steps are simplifying the equation above and solving for ARR
    // Eq. 5.1) 1 / ARR^2 = (1 / Previous_ARR^2) + (2 * RAMP_ACCEL / C^2)
    // - Divide everything by C^2
    //
    // Eq. 5.2) ARR^2 = 1 / [(1 / Previous_ARR^2) + (2 * RAMP_ACCEL / C^2)]
    // - Isolate ARR^2
    //
    // Eq. 5.3) ARR = 1 / SQRT ( [ (1 / Previous_ARR^2) + (2 * RAMP_ACCEL / C^2) ] )
    // - Solve for ARR, this is what I'll use
    //
    // NOTE about overhead: My stepper motors are ~1.8 degree steps, so realistically the speed
    // shouldn't exceed 20 steps per second. This interrupt isn't super calculation intensive and
    // should be more than OKAY to execute ~20 times per second.

    if (state == MTR_ACCELERATING)
    {
        // ramp_accel is the ticks/second^2, in this case positive
        // using kinematic equation for acceleration,  v = kx

        uint32_t next_arr = curr_arr - 100;

        return next_arr;
    }
    else if (state == MTR_DECELERATING)
    {
        // ramps_accel is the ticks/second^2, in this case negative

        uint32_t next_arr = curr_arr + 100;

        return next_arr;
    }
    else
    {
// Shouldn't happen
#ifdef DEBUG_MOTORS
        USART2_SendString("Calculating next arr for unexpected state (not accel or decel)");
#endif
        return 0;
    }
}

/**
 * Public API
 *
 * These are operations that are accessible from the mainloop/FSM.  Eventually, these will be made
 * accessible by the raspberri pi, and that is why I am developing a payload structure.
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

#ifdef DEBUG_MOTORS
    USART2_SendString("Disabled all motors");
#endif
}

/**
 * @brief Enable all motors, taking them out of freedrive
 * @param void
 * @return void
 */
void Motors_EnableAll(void)
{
    // Set all ENs
    SingleMotor_Enable(&MOTOR0);
    SingleMotor_Enable(&MOTOR1);
    SingleMotor_Enable(&MOTOR2);
    SingleMotor_Enable(&MOTOR3);
    SingleMotor_Enable(&MOTOR4);
    SingleMotor_Enable(&MOTOR5);

    // Transition into a braked state
    motor_system_state = MTRSYS_BRAKED;
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

#ifdef DEBUG_MOTORS
    USART2_SendString("Ramping down all motors");
#endif
}

/**
 * @brief Initialize the motors FSM. Called on startup or after an emergency stop.
 * @param void
 * @return void
 */
void Motors_FSM_Initialize(void)
{
    // Enable all motors. Whether a motor moves or not is dictated by the PWM channel, not this
    Motors_EnableAll();

    // Kick off the fsm by jumping into BRAKED
    motor_system_state =
        MTRSYS_RUNNING; // TODO change to braked to perform initialization tasks when done testing
}

/**
 * FSM Operations
 *
 * The FSM handles all motor operations on a 1ms tick, including setting motor destination states
 * and handling motor state transitions.
 */

/**
 * @brief accelerate a single motor. called within tick function
 * @param *motor pointer to the motor struct
 * @return void
 */
static void SingleMotor_AccelerateOnTick(s_MotorStruct *motor)
{
    // Calculate the next arr
    uint32_t next_arr_val =
        Calculate_NextArr(motor->motor_state, motor->motor_current_arr, motor->motor_ramp_accel);

    // Compare arr to the destination state. Motors can either slow to a stop (BRAKED) or to a
    // slower speed. Eventually I might make just make the destination an arr value from
    // analog/joystick input
    switch (motor->motor_destination_state)
    {
        case MTR_BRAKED:
        {
            // Shouldn't happen
            break;
        }
        case MTR_ATSPEED_SLOW:
        {
            // Check if a motor's arr is at slow/undershot
            if (next_arr_val <= motor->motor_slow_arr)
            {
                // Set the arr to the slow arr
                next_arr_val = motor->motor_slow_arr;
                SingleMotor_SetArr(motor, next_arr_val);

                // Change the motor state to at speed
                motor->motor_state = MTR_ATSPEED_SLOW;

                // Change the current ramp vel
                motor->motor_ramp_vel = 0;
            }
            else
            {
                SingleMotor_SetArr(motor, next_arr_val);
            }
            break;
        }
        case MTR_ATSPEED_MID:
        {
            // Check if a motor's arr is at mid/undershot
            if (next_arr_val <= motor->motor_mid_arr)
            {
                // Set the arr to the mid arr
                next_arr_val = motor->motor_mid_arr;
                SingleMotor_SetArr(motor, next_arr_val);

                // Change the motor state to at speed
                motor->motor_state = MTR_ATSPEED_MID;

                // Change the current ramp vel
                motor->motor_ramp_vel = 0;
            }
            break;
        }
        case MTR_ATSPEED_FAST:
        {
            // Check if a motor's arr is at fast/undershot
            if (next_arr_val <= motor->motor_fast_arr)
            {
                // Set the arr to the fast arr
                next_arr_val = motor->motor_fast_arr;
                SingleMotor_SetArr(motor, next_arr_val);

                // Change the motor state to at speed
                motor->motor_state = MTR_ATSPEED_FAST;

                // Change the current ramp vel
                motor->motor_ramp_vel = 0;
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
 * @brief decelerate a single motor. called within teh tick function
 * @param *motor pointer to the motor struct
 * @return void
 */
static void SingleMotor_DecelerateOnTick(s_MotorStruct *motor)
{
    // Calculate the next arr
    uint32_t next_arr_val =
        Calculate_NextArr(motor->motor_state, motor->motor_current_arr, motor->motor_ramp_accel);

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
                // Disable PWM, keeping EN pin on so the motor is not in freedrive
                PWM_DisableChannel(motor->motor_num);

                // Set arr to max
                SingleMotor_SetArr(motor, arr_reset_val);

                // Change motor state to braked
                motor->motor_state = MTR_BRAKED;

                // Stops should be handled by the interrupt. Since this is the case, this behavior
                // is unexpected so it should be logged. This means that slow downs were anticipated
                // incorrectly.
                // TODO log this in UART
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
    // Honestly idk. Handle anticipation of new destination states?
}

/**
 * @brief private function to update individual motor based on state. this does not handle state
 * changes
 * @param *motor pointer to the motor struct
 * @return void
 */
static void SingleMotor_UpdateOnTick(s_MotorStruct *motor)
{
    // Handle motor's current state
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
 * @brief Main tick of the motor FSM at 1000Hz. Called in main
 * @param void
 * @return void
 */
void Motors_FSM_Tick1000Hz(void)
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

/**
 * ISR functions
 *
 * IRQ handlers for TIM2, TIM3, TIM4, and TIM5. Each clears the flag and increments the tracked
 * step counter
 */

/**
 * @brief Handle the tim2 interrupt
 * @param void
 * @return void
 */
void Motors_TIM2_IRQHandler(void)
{
    // Clear the interrupt flag
    TIM2->SR &= ~TIM_SR_UIF;

    // Stop timer if needed
    bool stop_tim2 = Motors_CheckToStopTim2();

    // Increment the step counter if not paused
    if (!stop_tim2 && !tim2_paused)
    {
        tim2_step_counter++;
    }
}

/**
 * @brief Handle the tim3 interrupt
 * @param void
 * @return void
 */
void Motors_TIM3_IRQHandler(void)
{
    // Clear the interrupt flag
    TIM3->SR &= ~TIM_SR_UIF;

    // Stop timer if needed
    bool stop_tim3 = Motors_CheckToStopTim3();

    // Increment the step counter if not paused
    if (!stop_tim3 && !tim3_paused)
    {
        tim3_step_counter++;
    }
}

/**
 * @brief Handle the tim4 interrupt
 * @param void
 * @return void
 */
void Motors_TIM4_IRQHandler(void)
{
    // Clear the interrupt flag
    TIM4->SR &= ~TIM_SR_UIF;

    // Stop timer if needed
    bool stop_tim4 = Motors_CheckToStopTim4();

    // Increment the step counter if not paused
    if (!stop_tim4 && !tim4_paused)
    {
        tim4_step_counter++;
    }
}

/**
 * @brief Handle the tim5 interrupt
 * @param void
 * @return void
 */
void Motors_TIM5_IRQHandler(void)
{
    // Clear the interrupt flag
    TIM5->SR &= ~TIM_SR_UIF;

    // Stop timer if needed
    bool stop_tim5 = Motors_CheckToStopTim5();

    // Increment the step counter if not paused
    if (!stop_tim5 && !tim5_paused)
    {
        tim5_step_counter++;
    }
}