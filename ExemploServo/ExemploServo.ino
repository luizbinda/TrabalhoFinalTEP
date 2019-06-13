#include <Servo.h>
Servo myservo;  // create servo object to control a servo

void setup()
{
  // Define que o servo esta ligado a porta 8
  myservo.attach(8);
}

void loop()
{
  // Move o eixo do servo, de acordo com o angulo
  for (int i = 0; i < 180; i++) {
    myservo.write(i);
  }
  delay(500);
  for (int i = 180; i > 0; i--) {
    myservo.write(i);
  }
  delay(500);
}
