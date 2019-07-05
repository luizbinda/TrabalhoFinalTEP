#include "Distancia.h"

void Distancia::iniciarDistancia()
{
    this->pino_servo = 9;
    this->pino_echo = 10;
    this->pino_trigger = 8;       
    pinMode(pino_trigger, OUTPUT);
    pinMode(pino_echo, INPUT);
    this->myServo = new Servo();
    myServo->attach(pino_servo); 
}

void Distancia::setAngulo(uint8_t angulo)
{
    myServo->write(angulo);
}

float Distancia::distanciaAtual()
{
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
