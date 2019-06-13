#include <Servo.h>
Servo myservo; 
void SetServoAngulo(int angulo){
  myservo.write(angulo);
}

void setup()
{
  // Define que o servo esta ligado a porta 8
  myservo.attach(8);
  SetServoAngulo(180);
}

void loop()
{
  
}
