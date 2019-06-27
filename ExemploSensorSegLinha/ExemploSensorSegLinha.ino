#include <Car.h>
Car c;
uint8_t x = A3;
void setup() {
  Serial.begin(9600);
}

void loop() { 
  if (c.naPista(1) == 0) //SE A LEITURA DO PINO FOR IGUAL A LOW, FAZ
    Serial.println("Branco...");
  else
    Serial.println("Preto...");
  delay(100);

}
