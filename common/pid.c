#include "typedef.h"
#include "pid.h"

void PID_Execute(PID *element){
    float error = element->SetPoint - element->CurrentMeasurement;
    element->ErrorI = element->ErrorP + element->dt * error;
    element->ErrorD = (error-element->ErrorP) / element->dt;
    element->ErrorP = error;
    element->Result = element->ErrorP * element->Kp +
            element->ErrorI * element->Ki +
            element->ErrorD * element->Kd;
}

