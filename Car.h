#ifndef Car_h
#define Car_h

#include <Arduino.h>
#include "Distancia.h"
#include "SegLinha.h"
#include "Angulo.h"
#include "Roda.h"
#include "Cor.h"

class Car : public Angulo
{   
    private:
    public:
        Distancia radar;
        Roda rodaEsq;
        Roda rodaDir;
        SegLinha linha;
        Cor cores;
        void iniciarCar();
};

void Car::iniciarCar(){
    Car::incializarAngulo();
    this->radar.iniciarDistancia();
    this->rodaDir.iniciarRoda(3, 2, 4);
    this->rodaEsq.iniciarRoda(5, 6, 7);
    this->linha.iniciarLinha();
    this->cores.iniciarCor();
}

#endif
