#ifndef hardwareConfig
#define hardwareConfig

    #define LED LATCbits.LATC5
    #define LED_TRIS TRISCbits.TRISC5

    // QEI1
    #define QEI1_A 22
    #define QEI1_B 23
    //#define QEI1_I 24
    // QEI2
    #define QEI2_A 25
    #define QEI2_B 10
    //#define QEI2_I 11

    // Robot variables
    #define wheelCircumference 150.0
    #define encoderMaxCount 2000.0
#endif
