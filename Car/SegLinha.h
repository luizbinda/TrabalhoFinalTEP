#include <Arduino.h>

class SegLinha
{
    private:
        uint8_t pino_Seg_linha1;
        uint8_t pino_Seg_linha2;

    public:
        SegLinha();
        bool naPista(uint8_t NumSegLinha);

};

