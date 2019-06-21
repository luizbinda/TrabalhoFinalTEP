#include <Servo.h>
#include <Arduino.h>

class Distancia : public Servo
{
    private:
        uint8_t pino_servo;
        uint8_t pino_trigger;
        uint8_t pino_echo;
        
    public:
        float distanciaAtual(uint8_t angulo);
        float distanciaAtual();
        void SetServoAngulo(uint16_t angulo);
};

