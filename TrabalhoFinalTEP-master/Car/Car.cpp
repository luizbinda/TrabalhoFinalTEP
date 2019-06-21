#include "Car.h"

Car::Car(uint8_t pino_servo,
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
    uint8_t pino_cor_pino4)
{
     this->pino_servo = pino_servo; 
     this->pino_ultrasonic_trigger = pino_ultrasonic_trigger;
     this->pino_ultrasonic_echo = pino_ultrasonic_echo;
     this->pino_Seg_linha1 = pino_Seg_linha1;
     this->pino_seg_linha2 = pino_seg_linha2;
     this->pino_giroscopio_SLC = pino_giroscopio_SLC;
     this->pino_giroscopio_SDA = pino_giroscopio_SDA;
     this->pino_roda1_pino1 = pino_roda1_pino1;
     this->pino_roda1_pino2 = pino_roda1_pino2;
     this->pino_roda1_pinoPWM = pino_roda1_pinoPWM;
     this->pino_roda2_pino1 = pino_roda2_pino1;
     this->pino_roda2_pino2 = pino_roda2_pino2;
     this->pino_roda2_pinoPWM = pino_roda2_pinoPWM;
     this->pino_cor_pino1 = pino_cor_pino1;
     this->pino_cor_pino2 = pino_cor_pino2;
     this->pino_cor_pino3 = pino_cor_pino3;
     this->pino_cor_pino4 = pino_cor_pino4;

}

Car::Car()
{
    pino_servo = 7;
    pino_ultrasonic_trigger = 8;
    pino_ultrasonic_echo = 9;
    pino_Seg_linha1 = A0;
    pino_seg_linha2 = A1; 
    pino_giroscopio_SLC = A4;
    pino_giroscopio_SDA = A5;
    pino_roda1_pino1 = 2;
    pino_roda1_pino2 = 3;
    pino_roda1_pinoPWM = 4;
    pino_roda2_pino1 = 5;
    pino_roda2_pino2 = 6;
    pino_roda2_pinoPWM = 1;
    pino_cor_pino1 = 10;
    pino_cor_pino2 = 11;
    pino_cor_pino3 = 12;
    pino_cor_pino4 = 13;
}