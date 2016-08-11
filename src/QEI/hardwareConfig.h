#ifndef hardwareConfig
#define hardwareConfig

    #define LED LATBbits.LATB4
    #define LED_TRIS TRISBbits.TRISB4

    // QEI1
    #define QEI1_A 0
    #define QEI1_B 1
    //#define QEI1_I 24
    // QEI2
    #define QEI2_A 2
    #define QEI2_B 3
    //#define QEI2_I 11

    // Robot variables
    #define wheelCircumference 150.0
    #define encoderMaxCount 2000.0
    #define wheelMaxSpeed 100
#endif
