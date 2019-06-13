#include <Ultrasonic.h>

#define pino_trigger 13
#define pino_echo 12

Ultrasonic ultrasonic(pino_trigger, pino_echo);
 
void setup()
{
  Serial.begin(9600);
}
 
void loop()
{
  float cmMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);

  Serial.print("Distancia em cm: ");
  Serial.print(cmMsec);
  delay(100);
}
