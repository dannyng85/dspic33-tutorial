#ifndef pid
#define pid
    typedef struct PID {
        float Kp;
        float Ki;
        float Kd;
        
        float ErrorP;
        float ErrorI;
        float ErrorD;
        
        float Result;
        
        float CurrentMeasurement;
        float SetPoint;
        
        float dt;
    } PID;
    
    void PID_Execute(PID*);
#endif
