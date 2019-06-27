#ifndef Car_h
#define Car_h

#include <Arduino.h>
#include "Distancia.h"
#include "SegLinha.h"

class Car : public Distancia, public SegLinha
{
    private:
        uint8_t pino_servo;
        uint8_t pino_ultrasonic_trigger;
        uint8_t pino_ultrasonic_echo;
        uint8_t pino_Seg_linha1;
        uint8_t pino_seg_linha2;
        uint8_t pino_giroscopio_SLC;
        uint8_t pino_giroscopio_SDA;
        uint8_t pino1_roda1;
        uint8_t pino2_roda1;
        uint8_t pinoPWM_roda1;
        uint8_t pino1_roda2;
        uint8_t pino2_roda2;
        uint8_t pinoPWM_roda2;
        uint8_t pino_cor_pino1;
        uint8_t pino_cor_pino2;
        uint8_t pino_cor_pino3;
        uint8_t pino_cor_pino4;

        
        
    public:
        Car(uint8_t pino_servo,
            uint8_t pino_ultrasonic_trigger,
            uint8_t pino_ultrasonic_echo,
            uint8_t pino_Seg_linha1,
            uint8_t pino_seg_linha2,
            uint8_t pino_giroscopio_SLC,
            uint8_t pino_giroscopio_SDA,
            uint8_t pino_roda1_pino1,
            uint8_t pino_roda1_pino2,
            uint8_t pino_roda1_pinoPWM,
            uint8_t pino_roda2_pino1,
            uint8_t pino_roda2_pino2,
            uint8_t pino_roda2_pinoPWM,
            uint8_t pino_cor_pino1,
            uint8_t pino_cor_pino2,
            uint8_t pino_cor_pino3,
            uint8_t pino_cor_pino4);
        
        Car();
};

#endif
