// C++ code
//
#include <Servo.h>

Servo myservo;
 #define servoPin 9

int angle =0;
int g = 22;// g
void setup()
{
  myservo.attach(servoPin);
}

void loop()
{
  
  for (int i = 0; i<floor(g/10);i++){
  myservo.write(180);
  delay(1000);
  myservo.write(0);
  delay(1000);
  }
  // delay between word half
  delay(2000);
  for (int i =0; i <g%10;i++){
  myservo.write(180);
  delay(1000);
  myservo.write(0);
  delay(1000);
  }
  // delay between letters
  delay(3000);
}