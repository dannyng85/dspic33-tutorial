#include <xc.h>
#include "config.h"

int main(){
    TRISBbits.TRISB7 = 1;
    TRISBbits.TRISB4 = 0;
    while(1){
        if(PORTBbits.RB7){
            LATBbits.LATB4 = 1;   
        }
        else{
            LATBbits.LATB4 = 0;
        }
    }
    return 0;
}