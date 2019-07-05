#include <Arduino.h>

class SensorLinha
{
    private:
        uint8_t pino_Seg_linha1;
        uint8_t pino_Seg_linha2;

    public:
        static const int sensor_esquerda = 1;
        static const int sensor_direita 2;
        void iniciarLinha();
        bool naPista();
        bool naPista(int NumSegLinha);

};

