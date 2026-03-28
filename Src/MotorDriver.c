/*
filename: MotorDriver.c

Controls motor through fsm. Motors have acceleration, deceleration, and at speed states
*/

#include "MotorDriver.h"
#include "main.h"

// Motor structs
s_MotorStruct MOTOR0 = {
    .motor_num       = M0,
    .motor_en_pin    = MTR0_EN_PIN,
    .motor_dir_pin   = MTR0_DIR_PIN,
    .motor_step_port = MTR0_STEP_PORT,
    .motor_step_pin  = MTR0_STEP_PIN,
};
s_MotorStruct MOTOR1 = {
    .motor_num       = M1,
    .motor_en_pin    = MTR1_EN_PIN,
    .motor_dir_pin   = MTR1_DIR_PIN,
    .motor_step_port = MTR1_STEP_PORT,
    .motor_step_pin  = MTR1_STEP_PIN,
};
s_MotorStruct MOTOR2 = {
    .motor_num       = M2,
    .motor_en_pin    = MTR2_EN_PIN,
    .motor_dir_pin   = MTR2_DIR_PIN,
    .motor_step_port = MTR2_STEP_PORT,
    .motor_step_pin  = MTR2_STEP_PIN,
};
s_MotorStruct MOTOR3 = {
    .motor_num       = M3,
    .motor_en_pin    = MTR3_EN_PIN,
    .motor_dir_pin   = MTR3_DIR_PIN,
    .motor_step_port = MTR3_STEP_PORT,
    .motor_step_pin  = MTR3_STEP_PIN,
};
s_MotorStruct MOTOR4 = {
    .motor_num       = M4,
    .motor_en_pin    = MTR4_EN_PIN,
    .motor_dir_pin   = MTR4_DIR_PIN,
    .motor_step_port = MTR4_STEP_PORT,
    .motor_step_pin  = MTR4_STEP_PIN,
};
s_MotorStruct MOTOR5 = {
    .motor_num       = M5,
    .motor_en_pin    = MTR5_EN_PIN,
    .motor_dir_pin   = MTR5_DIR_PIN,
    .motor_step_port = MTR5_STEP_PORT,
    .motor_step_pin  = MTR5_STEP_PIN,
};