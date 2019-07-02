#include <Arduino.h>

class Cor
{
    private:
        uint8_t pino_red = 13;
        uint8_t pino_greem = 12;
        uint8_t pino_blue = 11;
        uint8_t pino_leitura = A0;
        struct Cores
        {
            int red;
            int greem;
            int blue;
        };

    public:
        Cores cor;
        void iniciarCor();
        void lerCor();
};




