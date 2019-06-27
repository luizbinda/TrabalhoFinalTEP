#include <Arduino.h>
#include <AFMotor.h>

class Roda : public AF_DCMotor
{
    private:
        uint8_t Velocidade;

    public:
        Roda();
        void Roda::frente(uint8_t Velocidade);
        void Roda::traz(uint8_t Velocidade);  
        
};

