#include "config.h"
#include"timer.h"
#include"typedef.h"
#include <xc.h>

void initialize(){
    OscInitialize();
    TimerInitialize();
    // Port Initialization
    TRISBbits.TRISB7 = 1;
    TRISBbits.TRISB4 = 0;
}

int main(){
    initialize();
    while(true){
        if(GetTickCount() % 1000){
            LATBbits.LATB4 ^= 1;
        }
    }
    return 0;
}