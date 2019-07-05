#include "Cor.h"

void Cor::iniciarCor()
{
    pinMode(pino_red, OUTPUT);
    pinMode(pino_greem, OUTPUT);
    pinMode(pino_blue, OUTPUT);
    pinMode(pino_leitura, INPUT);
}

void Cor::lerCor() 
{
    digitalWrite(pino_red, HIGH);
    delay(20);
    cor.red = analogRead(pino_leitura);
    digitalWrite(pino_red, LOW);

    digitalWrite(pino_greem, HIGH);
    delay(20);
    cor.greem = analogRead(pino_leitura);
    digitalWrite(pino_greem, LOW);

    digitalWrite(pino_blue, HIGH);
    delay(20);
    cor.blue = analogRead(pino_leitura);
    digitalWrite(pino_blue, LOW);
}