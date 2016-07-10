#include"timer.h"
#include<xc.h>

long TimerMsTick;

void TimerInitialize(){
    // Timer
    PR1 = 36850;
    T1CON = 0x8000;
    IFS0bits.T1IF = 0;
    IEC0bits.T1IE = 1;
}

void _ISR __attribute__((__auto_psv__)) _T1Interrupt (void){
    IFS0bits.T1IF = 0;
    TimerMsTick++;
}

long GetTickCount(){
    return TimerMsTick;
}
