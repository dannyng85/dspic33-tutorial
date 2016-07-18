#include "typedef.h"
#include "qei.h"
#include <xc.h>

int qei_Rev1 = 0;
int qei_Rev2 = 0;

void QEIInitialize(int MaxCount){
    // QEI 1
    QEI1CON = 0x0744;
    DFLT1CON = 0x0170;
    MAX1CNT = MaxCount;
    IFS3bits.QEI1IF = 0;
    IEC3bits.QEI1IE = 1;

    // QEI 2
    QEI2CON = 0x0744;
    DFLT2CON = 0x0170;
    MAX2CNT = MaxCount;
    IFS4bits.QEI2IF = 0;
    IEC4bits.QEI2IE = 1;
    
    IPC14bits.QEI1IP = 1;
    IPC18bits.QEI2IP = 1;
}

void _ISR __attribute__((__auto_psv__)) _QEI1Interrupt (void){
    IFS3bits.QEI1IF = 0;
    if(QEI1CONbits.UPDN){
        qei_Rev1++;
    }
    else{
        qei_Rev1--;
    }
}

void _ISR __attribute__((__auto_psv__)) _QEI2Interrupt (void){
    IFS4bits.QEI2IF = 0;
    if(QEI2CONbits.UPDN){
        qei_Rev2++;
    }
    else{
        qei_Rev2--;
    }
}

QEIResult QEIGetChannel(byte Channel){
    QEIResult result;
    if(Channel == 1){
        result.Rev = qei_Rev1; 
        result.Pos = POS1CNT;
    }
    else{
        result.Rev = qei_Rev2; 
        result.Pos = POS2CNT;
    }
    return result;
}