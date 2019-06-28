#ifndef Car_h
#define Car_h

#include <Arduino.h>
#include "Distancia.h"
#include "SegLinha.h"
#include "Angulo.h"
#include "Rodas.h"

class Car : public Distancia, public SegLinha, public Rodas, public Angulo
{};

#endif
