/*
filename: MotorDriver.h

header for MotorDriver.c
*/

// Enum for motor selection. This will be used for switch cases on motor ops
typedef enum
{
    MOTOR0 = 0,
    MOTOR1,
    MOTOR2,
    MOTOR3,
    MOTOR4,
    MOTOR5
} e_MotorNum;

// Enum for motor details. Includes STEP, DIR, EN, etc.
typedef struct
{

} s_MotorStruct;
