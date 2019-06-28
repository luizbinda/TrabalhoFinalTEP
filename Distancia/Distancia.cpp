#include "Distancia.h"

Distancia::Distancia(uint8_t pino_servo, uint8_t pino_trigger, uint8_t pino_echo)
{
    this->pino_servo = pino_servo;
    this->pino_echo = pino_echo;
    this->pino_trigger = pino_trigger;       
    pinMode(pino_trigger, OUTPUT);
    pinMode(pino_echo, INPUT); 
    Servo *myServo = new Servo();
    myServo->attach(pino_servo); 

       
}

void Distancia::SetServoAngulo(uint16_t angulo)
{
    myServo->write(angulo);
}

float Distancia::distanciaAtual(uint8_t angulo)
{
    myServo->write(angulo);

    long duration, cm;
    digitalWrite(pino_trigger, LOW);
    delayMicroseconds(5);
    digitalWrite(pino_trigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(pino_trigger, LOW);
    
    pinMode(pino_echo, INPUT);
    duration = pulseIn(pino_echo, HIGH);
    
    cm = (duration/2) / 29.1;
    
    return cm ;
}
