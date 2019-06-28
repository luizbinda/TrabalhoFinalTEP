#include "Rodas.h"

Rodas::Rodas()
{
    pino_velocidade = 3;
    pino_entrada1 = 2;
    pino_entrada2 = 7;
    
    pino_velocidade2 = 6; //Ligado ao pino de ENABLE do L293D  
    pino_entrada3 = 4; //Ligado ao pino de INPUT do L293D  
    pino_entrada4 = 8; //Ligado ao pino de INPUT do L293D  
    
    pinMode(pino_velocidade, OUTPUT);  
    pinMode(pino_entrada1, OUTPUT);  
    pinMode(pino_entrada2, OUTPUT);
    
    pinMode(pino_velocidade2, OUTPUT);  
    pinMode(pino_entrada3, OUTPUT);  
    pinMode(pino_entrada4, OUTPUT);
}

void Rodas::VelocidadeEsq(int velocidade)
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


void Rodas::VelocidadeDir(int velocidade)
{
    velocidade = constrain(velocidade, -100, 100);

    if (velocidade > 0)
    {
        velocidade = map(velocidade, 0, 100, 0, 255);
        analogWrite(pino_velocidade2, velocidade);   
        digitalWrite(pino_entrada3, LOW);  
        digitalWrite(pino_entrada4, HIGH);  
    }

    else if (velocidade < 0)
    {  
        velocidade = map(velocidade, 0, -100, 0, 255);
        analogWrite(pino_velocidade2, velocidade);   
        digitalWrite(pino_entrada3, HIGH);  
        digitalWrite(pino_entrada4, LOW);  
    }

    else if (velocidade == 0)
    {
        analogWrite(pino_velocidade2, velocidade);   
        digitalWrite(pino_entrada3, LOW);  
        digitalWrite(pino_entrada4, LOW); 
    }
        
}