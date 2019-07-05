#include "SensorLinha.h"

void SensorLinha::iniciarLinha()
{   
    pino_Seg_linha1 = A3;
    pino_Seg_linha2 = A2;
    pinMode(pino_Seg_linha1, INPUT);
    pinMode(pino_Seg_linha2, INPUT);
}

bool SensorLinha::naPista()
{
    if (digitalRead (pino_Seg_linha1) == true && digitalRead (pino_Seg_linha2) == true )
        return true;

    else 
        return false;
}

bool SensorLinha::naPista(int NumSegLinha)
{
    if (NumSegLinha == 2)
        return digitalRead (pino_Seg_linha2);

    else   
        return digitalRead (pino_Seg_linha1);
}
