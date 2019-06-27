#include "SegLinha.h"

SegLinha::SegLinha()
{
    pino_Seg_linha1 = A3;
    pino_Seg_linha2 = A2;
    pinMode(pino_Seg_linha1, INPUT);
    pinMode(pino_Seg_linha2, INPUT);
}

bool SegLinha::naPista(uint8_t NumSegLinha)
{
    if (NumSegLinha == 2)
        return digitalRead (pino_Seg_linha1);

    else 
        return digitalRead (pino_Seg_linha1);
}