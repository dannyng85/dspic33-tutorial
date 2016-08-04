#include "typedef.h"
#include "pwm.h"
#include <xc.h>

void pwmInit(){
    // Set OC1 to PWM Mode - TMR2
    // Set OC2 to PWM Mode - TMR2
    // Set PR2 - 500 Hz
}

void setPWM(byte channel, float dutyCycle){
    // Calculate Duty cycle
    
    // If channel == 1
    // OC1RS = dutyCycle / 100 * (PR2 + 1)
    
}