#include "config.h"
#include "timer.h"
#include "typedef.h"
#include "qei.h"
#include "hardwareConfig.h"
#include "pid.h"
#include "pwm.h"
#include <xc.h>

#define IOUnlock asm volatile ("MOV #OSCCON, w1\n""MOV #0x46, w2\n""MOV #0x57, w3\n""MOV.b w2, [w1]\n""MOV.b w3, [w1]\n""BCLR OSCCON,#6")
#define IOLock asm volatile ("MOV #OSCCON, w1\n""MOV #0x46, w2\n""MOV #0x57, w3\n""MOV.b w2, [w1]\n""MOV.b w3, [w1]\n""BSET OSCCON, #6" )

void initialize() {
    TimerInitialize();
    QEIInitialize(encoderMaxCount);
    // Port Initialization
    LED_TRIS = 0;

    // Set all pin to digital
    AD1PCFGL = 0x01FF;

    IOUnlock;
    // Encoder Setting

    RPINR14bits.QEA1R = QEI1_A;
    RPINR14bits.QEB1R = QEI1_B;
    //RPINR15bits.INDX1R = QEI1_I;

    RPINR16bits.QEA2R = QEI2_A;
    RPINR16bits.QEB2R = QEI2_B;
    //RPINR17bits.INDX2R = QEI2_I;

    // PWM Setting

    RPOR4bits.RP8R = 0b10010;
    RPOR4bits.RP9R = 0b10011;

    IOLock;
}

int main() {
    bool updated = false;
    int dt = 100;
    QEIResult encoderLeft, encoderRight;
    float distanceLeft = 0;
    float distanceRight = 0;
    float pwmLeft = 0, pwmRight = 0;
    PID pLeft, pRight;
    pLeft.Kp = 1;
    pLeft.Ki = 0;
    pLeft.Kd = 0;
    pLeft.dt = 0.1;
    pRight.Kp = 1;
    pRight.Ki = 0;
    pRight.Kd = 0;
    pRight.dt = 0.1;
    initialize();
    
    pRight.SetPoint = 0.05;
    pLeft.SetPoint = 0.05;
    while (true) {
        if (GetTickCount() % dt == 0 && !updated) {
            updated = true;
            encoderLeft = QEIGetChannel(1);
            encoderRight = QEIGetChannel(1);
            float distanceLeftCurrent = encoderLeft.Rev * wheelCircumference + encoderLeft.Pos / encoderMaxCount * wheelCircumference;
            float distanceRightCurrent = encoderRight.Rev * wheelCircumference + encoderRight.Pos / encoderMaxCount * wheelCircumference;
            float vLeft = (distanceLeftCurrent - distanceLeft) / dt;
            float vRight = (distanceRightCurrent - distanceRight) / dt;
            
            pLeft.CurrentMeasurement = vLeft;
            pRight.CurrentMeasurement = vRight;
            
            PID_Execute(&pLeft);
            PID_Execute(&pRight);
            float gain = 10;
            pwmLeft += gain * (pLeft.Result > 100 ? 100 : pLeft.Result < -100 ? -100 : pLeft.Result);
            pwmRight += gain * (pRight.Result > 100 ? 100 : pRight.Result < -100 ? -100 : pRight.Result); 
            
            if(pwmLeft > 0){
                // Set Dir Pin
            }
            else if(pwmLeft < 0){
                // Set Dir Pin
            }
            if(pwmRight > 0){
                // Set Dir Pin
            }
            else if(pwmRight < 0){
                // Set Dir Pin
            }
            setPWM(1, pwmLeft);
            setPWM(2, pwmRight);
            
            distanceLeft = distanceLeftCurrent;
            distanceRight = distanceRightCurrent;
            LED ^= 1;
        } else if (GetTickCount() % 20 != 0) {
            updated = false;
        }

        /* 
        if(GetTickCount() % 1000 == 0 ){
            LATBbits.LATB4 ^= 1;
        }
         */
    }
    return 0;
}