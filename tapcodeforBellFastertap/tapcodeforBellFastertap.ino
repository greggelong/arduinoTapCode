// C++ code
//
#include <Servo.h>

Servo myservo;
#define servoPin 9

int angle = 0;
// use EF92A 180d analog micro servo. not the EF90D 360d digital servo, as this one keeps spinning during delay()
// https://github.com/greggelong/arduinoTapCode

// the Piezo seems to be messing with the servo so I am taking it out
// translate sentence with python code to save arduino memory
// I am using a bell and a faster tap
// need to wait for servo to move into positon with delay
// this set up seems to work
// need to add the translation from english to tap code
// from code on tinker cad


int s[] = {0, 22, 42, 15, 22, 0, 24, 43, 0, 22, 34, 34, 14}; //
void setup()
{
  myservo.attach(servoPin);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  //pinMode(3,OUTPUT);


}

void loop()
{
  for (int j = 0; j < 13; j++) {
    if (s[j] == 0) {
      // go backward for start of word
      // move servo
      myservo.write(0);
      // light green leg
      digitalWrite(7, HIGH);
      // piezo
      //analogWrite(3,20);

      //myservo.write(0);
      delay(1000);
      digitalWrite(7, LOW);
      //analogWrite(3,0);

    }
    else {
      delay(1000);
      // start tapping out letter in word
      // use math to get the number in 10s place
      int lttr = s[j];
      for (int i = 0; i < floor(lttr / 10); i++) {
        myservo.write(40);
        digitalWrite(8, HIGH);
        delay(600); //delay so servo gets there

        myservo.write(0);
        digitalWrite(8, LOW);
        delay(600);

      }
      // delay between letter half
      // use math to get the number in the 1s place
      delay(2000);

      for (int i = 0; i < lttr % 10; i++) {
        myservo.write(40);
        digitalWrite(8, HIGH);
        delay(600);


        myservo.write(0);

        digitalWrite(8, LOW);
        delay(600);
      }
      // delay between letters
      delay(4000);
    }
  }
}
