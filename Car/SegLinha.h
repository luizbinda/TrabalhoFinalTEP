#include <Arduino.h>

class SegLinha
{
    private:
        uint8_t pino_Seg_linha1;
        uint8_t pino_Seg_linha2;

    public:
        static int linha_esquerda;
        static int linha_direita;
        SegLinha();
        bool naPista();
        bool naPista(int NumSegLinha);

};

