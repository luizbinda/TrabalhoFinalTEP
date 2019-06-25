#ifndef Distancia_h
#define Distancia_h

#include <Arduino.h>
#include <Servo.h>

class Distancia : public Servo
{
    private:
        uint8_t pino_servo;
        uint8_t pino_trigger;
        uint8_t pino_echo;
        
    public:
        Distancia(uint8_t pino_servo, uint8_t pino_trigger, uint8_t pino_echo);
        float distanciaAtual(uint8_t angulo);
        void SetServoAngulo(uint16_t angulo);
};

#endif