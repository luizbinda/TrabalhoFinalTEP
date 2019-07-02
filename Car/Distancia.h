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
        Servo *myServo; 
        
    public:
        void iniciarDistancia();
        float distanciaAtual();
        float distanciaAtual(uint8_t angulo);
        void setAngulo(uint8_t angulo);
};

#endif
