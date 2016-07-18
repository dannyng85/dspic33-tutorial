#ifndef qei
#define qei
    
    typedef struct QEIResult {
        int Rev;
        int Pos;
    } QEIResult;
    
    void QEIInitialize(int);
    QEIResult QEIGetChannel(byte);

#endif
