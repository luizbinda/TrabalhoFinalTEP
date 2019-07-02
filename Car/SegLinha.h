#include <Arduino.h>

class SegLinha
{
    private:
        uint8_t pino_Seg_linha1;
        uint8_t pino_Seg_linha2;

    public:
        static int linha_esquerda;
        static int linha_direita;
        void iniciarLinha();
        bool naPista();
        bool naPista(int NumSegLinha);

};

