#include "typedef.h"
#include "pwm.h"
#include <xc.h>

void pwmInit(){
    // Initialize Output Compare Module
    OC1RS = 0; 
    OC2RS = 0; 
    OC1CON = 0x0006;
    OC2CON = 0x0006;
    // Initialize and enable Timer2
    PR2 = 7370;
    T2CON = 0x8000;
}

void setPWM(byte channel, float dutyCycle){
    // Calculate Duty cycle
    switch(channel){
        case 1:
            OC1RS = dutyCycle / 100 * (PR2 + 1);
            break;
        case 2:
            OC2RS = dutyCycle / 100 * (PR2 + 1);
            break;
    }
}