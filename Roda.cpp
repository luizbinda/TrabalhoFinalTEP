#include "Roda.h"

void Roda::iniciarRoda(uint8_t pino_velocidade, uint8_t pino_entrada1, uint8_t pino_entrada2)
{
    this->pino_velocidade = pino_velocidade; //Ligado ao pino de ENABLE do L293D  
    this->pino_entrada1 = pino_entrada1; //Ligado ao pino de INPUT do L293D  
    this-> pino_entrada2 = pino_entrada2; //Ligado ao pino de INPUT do L293D  
        
    pinMode(this->pino_velocidade, OUTPUT);  
    pinMode(this->pino_entrada1, OUTPUT);  
    pinMode(this->pino_entrada2, OUTPUT);

}

void Roda::Velocidade(int velocidade)
{
    velocidade = constrain(velocidade, -100, 100);

    if (velocidade > 0)
    {
        velocidade = map(velocidade, 0, 100, 0, 255);
        analogWrite(pino_velocidade, velocidade);   
        digitalWrite(pino_entrada1, LOW);  
        digitalWrite(pino_entrada2, HIGH);  
    }

    else if (velocidade < 0)
    {  
        velocidade = map(velocidade, 0, -100, 0, 255);
        analogWrite(pino_velocidade, velocidade);   
        digitalWrite(pino_entrada1, HIGH);  
        digitalWrite(pino_entrada2, LOW);  
    }

    else if (velocidade == 0)
    {
        analogWrite(pino_velocidade, velocidade);   
        digitalWrite(pino_entrada1, LOW);  
        digitalWrite(pino_entrada2, LOW); 
    }
        
}


