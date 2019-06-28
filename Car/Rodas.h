#include <Arduino.h>

class Rodas
{
    private:
        uint8_t pino_velocidade; //Ligado ao pino de ENABLE do L293D  
        uint8_t pino_entrada1; //Ligado ao pino de INPUT do L293D  
        uint8_t pino_entrada2; //Ligado ao pino de INPUT do L293D  

        uint8_t pino_velocidade2; //Ligado ao pino de ENABLE do L293D  
        uint8_t pino_entrada3; //Ligado ao pino de INPUT do L293D  
        uint8_t pino_entrada4; //Ligado ao pino de INPUT do L293D  

    public:
        Rodas();
        void VelocidadeEsq(int velocidade);
        void VelocidadeDir(int velocidade);
};
