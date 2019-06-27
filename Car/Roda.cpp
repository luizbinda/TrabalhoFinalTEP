#include "Roda.h"

Roda::Roda()
{
    uint8_t Velocidade = 0;
}

void Roda::frente(uint8_t Velocidade)
{
    AF_DCMotor motor(1);
    motor.setSpeed(Velocidade); 
    motor.run(FORWARD);
}

void Roda::traz(uint8_t Velocidade)
{
    AF_DCMotor motor(1);
    motor.setSpeed(Velocidade); 
    motor.run(BACKWARD);
}