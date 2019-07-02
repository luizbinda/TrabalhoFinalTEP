#include <Arduino.h>

class Roda
{
    private:
        uint8_t pino_velocidade; //Ligado ao pino de ENABLE do L293D  
        uint8_t pino_entrada1; //Ligado ao pino de INPUT do L293D  
        uint8_t pino_entrada2; //Ligado ao pino de INPUT do L293D  

    public:
        void iniciarRoda(uint8_t pino_velocidade, uint8_t pino_entrada1, uint8_t pino_entrada2);
        void Velocidade(int velocidade);
};
