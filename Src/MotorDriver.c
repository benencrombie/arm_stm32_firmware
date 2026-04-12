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
#include "MathModules.h"
#include "PWM.h"
#include "USART.h"
#include "main.h"

// TODOs
// I'm not 100% sure but the FSM will probably break if you pass a small target steps in, since
// steps are controlled by the interrupt and actual accel/decel is controlled by time. Probably will
// be a headache to build out, so maybe mitigate this in the UART comms (from raspberry pi)

// Prototypes

// Overall motor actuation system state
e_MotorSystemState motor_system_state =
    MTRSYS_RUNNING; // TODO Start at DISABLED, jumping straight to RUNNING for testing purposes

// Timer step counter
volatile uint32_t tim2_step_counter = 0;
volatile uint32_t tim3_step_counter = 0;
volatile uint32_t tim4_step_counter = 0;
volatile uint32_t tim5_step_counter = 0;

// Decelerate flags, tells the FSM when to decel a motor, handled within 1000 Hz tick
volatile uint8_t f_m0_decel = 0;
volatile uint8_t f_m1_decel = 0;
volatile uint8_t f_m2_decel = 0;
volatile uint8_t f_m3_decel = 0;
volatile uint8_t f_m4_decel = 0;
volatile uint8_t f_m5_decel = 0;

/**
 * Motor structs:
 * Keeps track of motor pins, their state, and other useful information
 */
s_MotorStruct MOTOR0 = {
    .motor_num          = M0,
    .motor_base_freq    = (uint32_t)SYSHZ / (uint32_t)TIM2_PRESC,
    .motor_state        = MTR_DISABLED,
    .motor_target_arr   = 0,
    .motor_curr_arr     = 0,
    .motor_target_steps = 0,
    .motor_en_pin       = MTR0_EN_PIN,
    .motor_dir_pin      = MTR0_DIR_PIN,
    .motor_step_port    = MTR0_STEP_PORT,
    .motor_step_pin     = MTR0_STEP_PIN,
    .motor_approach_arr = M0_APPROACH_ARR,
    .motor_ramp_ms      = M0_RAMP_MS,
    .motor_ramp_ticks   = 0,
    .motor_start_decel  = 5000, // Calculated in init, todo change from 5000 to 0
    .motor_decel_flag   = &f_m0_decel,
};
s_MotorStruct MOTOR1 = {
    .motor_num          = M1,
    .motor_base_freq    = (uint32_t)SYSHZ / (uint32_t)TIM3_PRESC,
    .motor_state        = MTR_DISABLED,
    .motor_target_arr   = 0,
    .motor_curr_arr     = 0,
    .motor_target_steps = 0,
    .motor_en_pin       = MTR1_EN_PIN,
    .motor_dir_pin      = MTR1_DIR_PIN,
    .motor_step_port    = MTR1_STEP_PORT,
    .motor_step_pin     = MTR1_STEP_PIN,
    .motor_approach_arr = M1_APPROACH_ARR,
    .motor_ramp_ms      = M1_RAMP_MS,
    .motor_ramp_ticks   = 0,
    .motor_start_decel  = 5000, // Calculated in init
    .motor_decel_flag   = &f_m1_decel,
};
s_MotorStruct MOTOR2 = {
    .motor_num          = M2,
    .motor_base_freq    = (uint32_t)SYSHZ / (uint32_t)TIM4_PRESC,
    .motor_state        = MTR_DISABLED,
    .motor_target_arr   = 0,
    .motor_curr_arr     = 0,
    .motor_target_steps = 0,
    .motor_en_pin       = MTR2_EN_PIN,
    .motor_dir_pin      = MTR2_DIR_PIN,
    .motor_step_port    = MTR2_STEP_PORT,
    .motor_step_pin     = MTR2_STEP_PIN,
    .motor_approach_arr = M2_APPROACH_ARR,
    .motor_ramp_ms      = M2_RAMP_MS,
    .motor_ramp_ticks   = 0,
    .motor_start_decel  = 5000, // Calculated in init
    .motor_decel_flag   = &f_m2_decel,
};
s_MotorStruct MOTOR3 = {
    .motor_num          = M3,
    .motor_base_freq    = (uint32_t)SYSHZ / (uint32_t)TIM5_PRESC,
    .motor_state        = MTR_DISABLED,
    .motor_target_arr   = 0,
    .motor_curr_arr     = 0,
    .motor_target_steps = 0,
    .motor_en_pin       = MTR3_EN_PIN,
    .motor_dir_pin      = MTR3_DIR_PIN,
    .motor_step_port    = MTR3_STEP_PORT,
    .motor_step_pin     = MTR3_STEP_PIN,
    .motor_approach_arr = M3_APPROACH_ARR,
    .motor_ramp_ms      = M3_RAMP_MS,
    .motor_ramp_ticks   = 0,
    .motor_start_decel  = 5000, // Calculated in init
    .motor_decel_flag   = &f_m3_decel,
};
s_MotorStruct MOTOR4 = {
    .motor_num          = M4,
    .motor_base_freq    = (uint32_t)SYSHZ / (uint32_t)TIM2_PRESC,
    .motor_state        = MTR_DISABLED,
    .motor_target_arr   = 0,
    .motor_curr_arr     = 0,
    .motor_target_steps = 0,
    .motor_en_pin       = MTR4_EN_PIN,
    .motor_dir_pin      = MTR4_DIR_PIN,
    .motor_step_port    = MTR4_STEP_PORT,
    .motor_step_pin     = MTR4_STEP_PIN,
    .motor_approach_arr = M4_APPROACH_ARR,
    .motor_ramp_ms      = M4_RAMP_MS,
    .motor_ramp_ticks   = 0,
    .motor_start_decel  = 5000, // Calculated in init
    .motor_decel_flag   = &f_m4_decel,
};
s_MotorStruct MOTOR5 = {
    .motor_num          = M5,
    .motor_base_freq    = (uint32_t)SYSHZ / (uint32_t)TIM3_PRESC,
    .motor_state        = MTR_DISABLED,
    .motor_target_arr   = 0,
    .motor_curr_arr     = 0,
    .motor_target_steps = 0,
    .motor_en_pin       = MTR5_EN_PIN,
    .motor_dir_pin      = MTR5_DIR_PIN,
    .motor_step_port    = MTR5_STEP_PORT,
    .motor_step_pin     = MTR5_STEP_PIN,
    .motor_approach_arr = M5_APPROACH_ARR,
    .motor_ramp_ms      = M5_RAMP_MS,
    .motor_ramp_ticks   = 0,
    .motor_start_decel  = 5000, // Calculated in init
    .motor_decel_flag   = &f_m5_decel,
};

/**
 * Private Functions
 *
 * These are helper funcitons used in the public API's abstraction. There should not be a need to
 * call any of these outside of this module.
 */

/**
 * @brief functino to calculate the tick when the motor should start a time controlled deceleration
 * @param *motor pointer to the motor struct
 * @return void
 */
static void SingleMotor_CalculateDecelDist(s_MotorStruct *motor)
{
    // Trigger the deceleration tick. Frame this as motor_target_steps - steps_to_go
    // Variables we have are base frequency, total steps, target arr, approaching arr, and ramp ms
    // (milliseconds), so we need to see how many ticks are in motor_ramp_ms. There should be some
    // buffer such that the motor reaches approach speed a number of ticks before it should come to
    // a full stop so precise positioning can be controlled from the interrupt. This buffer is
    // called LEEWAY_TICKS

    // This is built for a linear ramp profile, so we can calculate an integral of speed using avg
    // speed = (v0 + vf) / 2 Number of steps is the integral of this with respect to time, so steps
    // = (v0 + vf) / 2 * ramp_ms. Check units between vel. and ms
}

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

    // Update the tracked arr, used in the state transition function
    motor->motor_curr_arr = arr_val;
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
 * @param target_arr the destination motor state
 * @param target_steps how many steps to take upon starting the motor
 * @return void
 */
static void SingleMotor_StartWithTarget(s_MotorStruct *motor, uint32_t target_arr,
                                        uint16_t target_steps)
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
            if (MOTOR0.motor_state != MTR_BRAKED && MOTOR0.motor_state != MTR_DISABLED)
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
            if (MOTOR1.motor_state != MTR_BRAKED && MOTOR1.motor_state != MTR_DISABLED)
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
        motor->motor_target_arr = target_arr;

        // Tell the motor how many steps to go
        motor->motor_target_steps = target_steps;

        // Actually set the arr to the max value (slowest speed)
        SingleMotor_SetArr(motor, MAX_ARR);

        // Enable the PWM channel
        PWM_EnableChannel(motor->motor_num);
    }
    else
    {
        // no op
    }
}

/**
 * @brief Public wrapper to start up a motor with explicit instructions
 * @param motor_num the motor number
 * @param arr the target arr
 * @param number_of_steps the number of steps to take in this instruction
 * @return void
 */
void Motors_StartMotor(uint8_t motor_num, uint32_t arr, uint16_t number_of_steps)
{
    uint32_t motor_arr = arr;

    // Just check the bounds, don't wanna go to fast
    if (arr < MIN_ARR)
    {
        motor_arr = MIN_ARR;
    }

    switch (motor_num)
    {
        case M0:
            SingleMotor_StartWithTarget(&MOTOR0, motor_arr, number_of_steps);
            break;
        case M1:
            SingleMotor_StartWithTarget(&MOTOR1, motor_arr, number_of_steps);
            break;
        case M2:
            SingleMotor_StartWithTarget(&MOTOR2, motor_arr, number_of_steps);
            break;
        case M3:
            SingleMotor_StartWithTarget(&MOTOR3, motor_arr, number_of_steps);
            break;
        case M4:
            SingleMotor_StartWithTarget(&MOTOR4, motor_arr, number_of_steps);
            break;
        case M5:
            SingleMotor_StartWithTarget(&MOTOR5, motor_arr, number_of_steps);
            break;
    }
}

/**
 * @brief disable a single motor.
 * @param *motor pointer to the motor struct
 * @return void
 */
static void SingleMotor_Disable(s_MotorStruct *motor)
{
    // Clear en pin
    GPIO_Clear(MTR_EN_PORT, motor->motor_en_pin);

    // Disable PWM channel. There is no situation to have PWM on but the EN cleared
    PWM_DisableChannel(motor->motor_num);

    // Reset the arr in the register
    SingleMotor_SetArr(motor, MAX_ARR);

    // Change motor state to stopped
    motor->motor_state = MTR_DISABLED;
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

    // Transition into a running state
    motor_system_state = MTRSYS_RUNNING;
}

/**
 * @brief Ramp down all motors. Soft stop
 * @param void
 * @return void
 */
void Motors_RampDownAll(void)
{
    // Set all motor states to decel
    MOTOR0.motor_state = MTR_DECELERATING;
    MOTOR1.motor_state = MTR_DECELERATING;
    MOTOR2.motor_state = MTR_DECELERATING;
    MOTOR3.motor_state = MTR_DECELERATING;
    MOTOR4.motor_state = MTR_DECELERATING;
    MOTOR5.motor_state = MTR_DECELERATING;

    // If decelerating there is not target arr, just go til you are at approaching speed (handled
    // elsewhere)

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
    // Calculate the decel distances for each motor, this is not clean to do when declaring
    // variables TODO TODO TODO
    SingleMotor_CalculateDecelDist(&MOTOR0);
    SingleMotor_CalculateDecelDist(&MOTOR1);
    SingleMotor_CalculateDecelDist(&MOTOR2);
    SingleMotor_CalculateDecelDist(&MOTOR3);
    SingleMotor_CalculateDecelDist(&MOTOR4);
    SingleMotor_CalculateDecelDist(&MOTOR5);

    // Enable all motors. Whether a motor moves or not is dictated by the PWM channel, not this
    Motors_EnableAll();

    // Kick off the fsm by jumping into RUNNING
    motor_system_state = MTRSYS_RUNNING;
}

/**
 * FSM Operations
 *
 * The FSM handles all motor operations on a 1ms tick, including setting motor destination states
 * and handling motor state transitions.
 */

/**
 * @brief function to handle state transtiions, called on motor tick. The physics are handled
 * elsewhere
 * @param *motor pointer to the motor struct
 * @return void
 */
static void SingleMotor_HandleStateTransition(s_MotorStruct *motor)
{
    // TODO TODO TODO really need to get this right or I'll keep confusing myself

    switch (motor->motor_state)
    {
        case MTR_NONE:
        // Wait to do something
        case MTR_DISABLED:
        // Wait to do something
        case MTR_BRAKED:
        // Wait to do something
        case MTR_ACCELERATING:
            // Acceleration is handled only by time, so just need to check ramping
            if (motor->motor_ramp_ticks > motor->motor_ramp_ms)
            {
                // Set the arr to the target speed
                PWM_SetArr(motor->motor_num, motor->motor_target_arr);

                // Set state so the motor is no longer accelerating
                motor->motor_state = MTR_ATSPEED;

                // Ensure that the tick is at max for future deceleration
                motor->motor_ramp_ticks = motor->motor_ramp_ms;
            }

        case MTR_DECELERATING:
            // Transition into an approach state when the ramp down is complete, this will be
            // targeted to be slightly before the motor is at the destination.
            // Checks wrapping, not sure if needed
            if ((motor->motor_ramp_ticks == 0) || (motor->motor_ramp_ticks >= 65000))
            {
                // Set speed to appraoch ARR
                PWM_SetArr(motor->motor_num, motor->motor_approach_arr);

                // Set state to appraoching, where last positions are controlled by the interrupt
                // rather than time
                motor->motor_state = MTR_APPROACH;
            }

        case MTR_ATSPEED:
            // Dereference the motor flag and see if its up
            if (*(motor->motor_decel_flag) == 1)
            {
                // Set the motor state to decelerating
                motor->motor_state = MTR_DECELERATING;

                // Clear the flag
                *(motor->motor_decel_flag) = 0;
            }

        case MTR_APPROACH:
            // Logic for approaching is handled in the interrupt itself for precise precisioning.
            // This is not intensive at the rate at which the timer will tick for approach speed
    }
}

/**
 * @brief accelerate a single motor. called within tick function
 * @param *motor pointer to the motor struct
 * @return void
 */
static void SingleMotor_AccelerateOnTick(s_MotorStruct *motor)
{
    // Calculate the next arr based on what step we are on.
    // Bounds are MAX_ARR (slowest speed) and .motor_target_arr. All motors ramp from slowest speed
    // Linearly interpolate speed (1/ARR) based on current tick
    // Steps range from 0 to .motor_ramp_ms, current step is tracked by .motor_ramp_ticks
    // Therefore, the equation for the next arr value is:
    //
    // Speed = (Current Tick/Total Ticks) * (Max Speed - Min Speed) + Min Speed, or
    //
    // 1 / nax_arr = (.motor_ramp_ticks / .motor_ramp_ms) * ((1/.motor_target_arr) - (1/MAX_ARR)) +
    // (1/MAX_ARR) or, next_arr = 1 / [(.motor_ramp_ticks / .motor_ramp_ms) * ((1/.motor_target_arr)
    // - (1/MAX_ARR)) + (1/MAX_ARR)]
    // Rearranging terms to avoid division to 1, or float division:
    //
    // next_arr = [.motor_target_arr * MAX_ARR * .motor_ramp_ms] / [.motor_ramp_ticks(MAX_ARR -
    // .motor_target_arr) + (.motor_ramp_ms * .motor_target_arr)]

    uint32_t t    = motor->motor_ramp_ticks;
    uint32_t T    = motor->motor_ramp_ms;
    uint32_t At   = motor->motor_target_arr;
    uint32_t Amax = MAX_ARR;

    // Use 64b to avoid overflow
    uint64_t numerator   = (uint64_t)At * Amax * T;
    uint64_t denominator = (uint64_t)t * (Amax - At) + (uint64_t)T * At;

    // Tested, this works
    uint32_t next_arr = numerator / denominator;

    // Clamp the arr to the target here just in case, state transition is handled elsewhere is
    // current = target.
    if (next_arr < motor->motor_target_arr)
    {
        next_arr = motor->motor_target_arr;
    }

    // Set the next arr
    SingleMotor_SetArr(motor, next_arr);

    // Increment ramp rounter
    motor->motor_ramp_ticks++;
}

/**
 * @brief decelerate a single motor. called within teh tick function
 * @param *motor pointer to the motor struct
 * @return void
 */
static void SingleMotor_DecelerateOnTick(s_MotorStruct *motor)
{
    // Calcualte next arr, same equation as acceleration so refer to comments there
    uint32_t t    = motor->motor_ramp_ticks;
    uint32_t T    = motor->motor_ramp_ms;
    uint32_t At   = motor->motor_target_arr;
    uint32_t Amax = MAX_ARR;

    // Use 64b to avoid overflow
    uint64_t numerator   = (uint64_t)At * Amax * T;
    uint64_t denominator = (uint64_t)t * (Amax - At) + (uint64_t)T * At;

    // Tested, this works
    uint32_t next_arr = numerator / denominator;

    // Clamp the arr to the target here just in case, state transition is handled elsewhere is
    // current = target.
    if (next_arr < motor->motor_target_arr)
    {
        next_arr = motor->motor_target_arr;
    }

    // Set the next arr
    SingleMotor_SetArr(motor, next_arr);

    // Decrement ramp counter, will need to ensure that the motor ticks is set to max when decel
    // starts, which should be the case with how acceleration is set up. Ensure this in the
    // transition function.
    motor->motor_ramp_ticks--;
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
        case MTR_NONE:
        {
            // No op for the motor
        }
        case MTR_DISABLED:
        {
            // No op for the motor
            break;
        }
        case MTR_BRAKED:
        {
            // No op for the motor
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
        case MTR_ATSPEED:
        {
            // State transitions handled after
            break;
        }
        case MTR_APPROACH:
        {
            // State transitions handled after
            break;
        }
    }

    // Check for state transitions
    SingleMotor_HandleStateTransition(motor);
}

/**
 * @brief function to update all motors on tick
 * @param void
 * @return void
 */
static void Motors_UpdateAll(void)
{
    // Update all of them
    SingleMotor_UpdateOnTick(&MOTOR0);
    SingleMotor_UpdateOnTick(&MOTOR1);
    SingleMotor_UpdateOnTick(&MOTOR2);
    SingleMotor_UpdateOnTick(&MOTOR3);
    SingleMotor_UpdateOnTick(&MOTOR4);
    SingleMotor_UpdateOnTick(&MOTOR5);
}

/**
 * @brief Main tick of the motor FSM at 1000Hz. Called in main
 * @param void
 * @return void
 */
void Motors_FSM_Tick1000Hz(void)
{
    // Logic here handles the motor system as a whole. When the motor sys is running, individual
    // motor states are handled individually (duh)
    switch (motor_system_state)
    {
        case MTRSYS_DISABLED:
        {
            // Do nothing. Wait for something to transition into the running state
            break;
        }

        // State to do stuff with all motors
        case MTRSYS_RUNNING:
        {
            // Update all motors with their respective states
            Motors_UpdateAll();
            break;
        }

        // State to emeergency stop (e.g., hard disable)
        case MTRSYS_EMERGENCY_STOP:
            // Stop all motors expeditiously
            Motors_DisableAll();

            // Go to disbaled
            motor_system_state = MTRSYS_DISABLED;
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
 * @brief Handle the tim2 interrupt,
 * @param void
 * @return void
 */
void Motors_TIM2_IRQHandler(void)
{
    // Clear the interrupt flag
    TIM2->SR &= ~TIM_SR_UIF;

    // Increment step counter
    tim2_step_counter++;

    // Look if either motor is approaching, then check to stop
    if (MOTOR0.motor_state == MTR_APPROACH)
    {
        // Compare the step to target step
        if (tim2_step_counter >= MOTOR0.motor_target_steps)
        {
            // Stop the motor, don't touch the en pin though
            PWM_DisableChannel(MOTOR0.motor_num);

            // reset the counter
            tim2_step_counter = 0;

            // Make motor braked
            MOTOR0.motor_state = MTR_BRAKED;
        }
    }
    else if (MOTOR0.motor_state == MTR_ATSPEED)
    {
        // Check to raise the decel flag
        if (tim2_step_counter >= MOTOR0.motor_start_decel)
        {
            f_m0_decel = 1;
        }
    }
    else if (MOTOR4.motor_state == MTR_APPROACH)
    {
        // Compare the step to target step
        if (tim2_step_counter >= MOTOR4.motor_target_steps)
        {
            // Stop the motor, don't touch the en pin though
            PWM_DisableChannel(MOTOR4.motor_num);

            // reset the counter
            tim2_step_counter = 0;

            // Make motor braked
            MOTOR4.motor_state = MTR_BRAKED;
        }
    }
    else if (MOTOR4.motor_state == MTR_ATSPEED)
    {
        // Check to raise the decel flag
        if (tim2_step_counter >= MOTOR4.motor_start_decel)
        {
            f_m4_decel = 1;
        }
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

    // Increment step counter
    tim3_step_counter++;

    // Look if either motor is approaching, then check to stop
    if (MOTOR1.motor_state == MTR_APPROACH)
    {
        // Compare the step to target step
        if (tim2_step_counter >= MOTOR1.motor_target_steps)
        {
            // Stop the motor, don't touch the en pin though
            PWM_DisableChannel(MOTOR1.motor_num);

            // reset the counter
            tim2_step_counter = 0;

            // Make motor braked
            MOTOR1.motor_state = MTR_BRAKED;
        }
    }
    else if (MOTOR1.motor_state == MTR_ATSPEED)
    {
        // Check to raise the decel flag
        if (tim2_step_counter >= MOTOR1.motor_start_decel)
        {
            f_m1_decel = 1;
        }
    }
    else if (MOTOR5.motor_state == MTR_APPROACH)
    {
        // Compare the step to target step
        if (tim2_step_counter >= MOTOR5.motor_target_steps)
        {
            // Stop the motor, don't touch the en pin though
            PWM_DisableChannel(MOTOR5.motor_num);

            // reset the counter
            tim2_step_counter = 0;

            // Make motor braked
            MOTOR5.motor_state = MTR_BRAKED;
        }
    }
    else if (MOTOR5.motor_state == MTR_ATSPEED)
    {
        // Check to raise the decel flag
        if (tim2_step_counter >= MOTOR5.motor_start_decel)
        {
            f_m5_decel = 1;
        }
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

    // Increment step counter
    tim4_step_counter++;
    // Look if either motor is approaching, then check to stop
    if (MOTOR2.motor_state == MTR_APPROACH)
    {
        // Compare the step to target step
        if (tim2_step_counter >= MOTOR2.motor_target_steps)
        {
            // Stop the motor, don't touch the en pin though
            PWM_DisableChannel(MOTOR2.motor_num);

            // reset the counter
            tim2_step_counter = 0;

            // Make motor braked
            MOTOR2.motor_state = MTR_BRAKED;
        }
    }
    else if (MOTOR2.motor_state == MTR_ATSPEED)
    {
        // Check to raise the decel flag
        if (tim2_step_counter >= MOTOR2.motor_start_decel)
        {
            f_m2_decel = 1;
        }
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

    // Increment step counter
    tim5_step_counter++;

    // Look if either motor is approaching, then check to stop
    if (MOTOR3.motor_state == MTR_APPROACH)
    {
        // Compare the step to target step
        if (tim2_step_counter >= MOTOR3.motor_target_steps)
        {
            // Stop the motor, don't touch the en pin though
            PWM_DisableChannel(MOTOR3.motor_num);

            // reset the counter
            tim2_step_counter = 0;

            // Make motor braked
            MOTOR3.motor_state = MTR_BRAKED;
        }
    }
    else if (MOTOR3.motor_state == MTR_ATSPEED)
    {
        // Check to raise the decel flag
        if (tim2_step_counter >= MOTOR3.motor_start_decel)
        {
            f_m3_decel = 1;
        }
    }
}