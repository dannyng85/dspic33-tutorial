#include "config.h"
#include "timer.h"
#include "typedef.h"
#include <xc.h>

void initialize(){
    TimerInitialize();
    // Port Initialization
    TRISBbits.TRISB7 = 1;
    TRISBbits.TRISB4 = 0;
}

int main(){
    bool updated = false;
    initialize();
    while(true){
        if(GetTickCount() % 1000 == 0 && !updated){
            updated = true;
            LATBbits.LATB4 ^= 1;
        }
        else if(GetTickCount() % 1000 != 0){
            updated = false;
        }
    }
    return 0;
}