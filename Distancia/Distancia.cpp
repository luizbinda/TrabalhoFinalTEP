#include "Distancia.h"

Distancia::Distancia(uint8_t pino_servo, uint8_t pino_trigger, uint8_t pino_echo)
{
    this->pino_servo = pino_servo;
    this->pino_echo = pino_echo;
    this->pino_trigger = pino_trigger;       
    pinMode(pino_trigger, OUTPUT);
    pinMode(pino_echo, INPUT);        
}

void Distancia::SetServoAngulo(uint16_t angulo)
{
    Servo myServo;
    myServo.attach(pino_servo); 
    myServo.write(angulo);
}

float Distancia::distanciaAtual(uint8_t angulo)
{
    Servo myServo;
    myServo.attach(pino_servo); 
    myServo.write(angulo);

    long duration, cm;
    digitalWrite(pino_trigger, LOW);
    delayMicroseconds(5);
    digitalWrite(pino_trigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(pino_trigger, LOW);
    
    pinMode(pino_echo, INPUT);
    duration = pulseIn(pino_echo, HIGH);
    
    cm = (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
    
    return cm ;
}