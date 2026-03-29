/*
filename: MotorDriver.c

Controls motor through fsm. Motors have acceleration, deceleration, and at speed states
*/

#include "MotorDriver.h"
#include "PWM.h"
#include "main.h"

// Overall motor actuation system state
e_MotorSystemState motor_system_state =
    RUNNING; // TODO Start at DISABLED, jumping straight to RUNNING for testing purposes

/**
 * Motor structs:
 * Keeps track of motor pins, their state, and other useful information
 */
s_MotorStruct MOTOR0 = {
    .motor_num          = M0,
    .motor_state        = STOPPED,
    .motor_en_pin       = MTR0_EN_PIN,
    .motor_dir_pin      = MTR0_DIR_PIN,
    .motor_step_port    = MTR0_STEP_PORT,
    .motor_step_pin     = MTR0_STEP_PIN,
    .motor_ramp_counter = 0,
};
s_MotorStruct MOTOR1 = {
    .motor_num          = M1,
    .motor_state        = STOPPED,
    .motor_en_pin       = MTR1_EN_PIN,
    .motor_dir_pin      = MTR1_DIR_PIN,
    .motor_step_port    = MTR1_STEP_PORT,
    .motor_step_pin     = MTR1_STEP_PIN,
    .motor_ramp_counter = 0,
};
s_MotorStruct MOTOR2 = {
    .motor_num          = M2,
    .motor_state        = STOPPED,
    .motor_en_pin       = MTR2_EN_PIN,
    .motor_dir_pin      = MTR2_DIR_PIN,
    .motor_step_port    = MTR2_STEP_PORT,
    .motor_step_pin     = MTR2_STEP_PIN,
    .motor_ramp_counter = 0,
};
s_MotorStruct MOTOR3 = {
    .motor_num          = M3,
    .motor_state        = STOPPED,
    .motor_en_pin       = MTR3_EN_PIN,
    .motor_dir_pin      = MTR3_DIR_PIN,
    .motor_step_port    = MTR3_STEP_PORT,
    .motor_step_pin     = MTR3_STEP_PIN,
    .motor_ramp_counter = 0,
};
s_MotorStruct MOTOR4 = {
    .motor_num          = M4,
    .motor_state        = STOPPED,
    .motor_en_pin       = MTR4_EN_PIN,
    .motor_dir_pin      = MTR4_DIR_PIN,
    .motor_step_port    = MTR4_STEP_PORT,
    .motor_step_pin     = MTR4_STEP_PIN,
    .motor_ramp_counter = 0,
};
s_MotorStruct MOTOR5 = {
    .motor_num          = M5,
    .motor_state        = STOPPED,
    .motor_en_pin       = MTR5_EN_PIN,
    .motor_dir_pin      = MTR5_DIR_PIN,
    .motor_step_port    = MTR5_STEP_PORT,
    .motor_step_pin     = MTR5_STEP_PIN,
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
    // Call whatever I called it in PWM module.
}

/**
 * @brief accelerate a single motor. called within tick function
 * @param *motor pointer to the motor struct
 * @return void
 */
static void SingleMotor_AccelerateOnTick(s_MotorStruct *motor)
{
    // Increase speed then increment the ramp counter
}

/**
 * @brief decelerate a single motor. called within teh tick function
 * @param *motor pointer to the motor struct
 * @return void
 */
static void SingleMotor_DecelerateOnTick(s_MotorStruct *motor)
{
    // Decrease speed the decrement the ramp counter
}

/**
 * @brief private function to update individual motor based on state
 * @param *motor pointer to the motor struct
 * @return void
 */
static void Tick_UpdateMotor(s_MotorStruct *motor)
{
    // do stuff, call stuff using the pointer like &motor.motor_num...
}

/**
 * @brief Disable all motors. Emergency stop
 * @param void
 * @return void
 */
void Motors_DisableAll(void)
{
    // Clear all ENs
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
    motor_system_state = RUNNING;
}

/**
 * @brief Main tick of the motor FSM. Called in main
 * @param void
 * @return void
 */
void Motors_FSM_Tick(void)
{
    // rename this, but call tick_updatemotor on all motors?
    // I think this is a good approach..., cant think of a reason why this is more inefficient than
    // something else
}

// Motor FSM
