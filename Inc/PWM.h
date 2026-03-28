/*
filename: PWM.h

Header for PWMs, timers 2,3,4, and 5
*/

// These are arbitrarily chosen. Speed of PWMs is adjusted with ARR
#define TIM2_PRESC 1023
#define TIM3_PRESC 1023
#define TIM4_PRESC 1023
#define TIM5_PRESC 1023

#define MAX_ARR 65535
#define MIN_ARR 0

void PWM_Initialize(void);