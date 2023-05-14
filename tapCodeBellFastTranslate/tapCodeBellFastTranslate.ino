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

// number code for letters in alpha order and repeat for 13 for k
int letters[] = {11, 12, 13, 14, 15, 21, 22, 23, 24, 25, 13, 31, 32, 33, 34, 35, 41, 42, 43, 44, 45, 51, 52, 53, 54, 55};
// start message
String message = " hello art teacher computer and students work together";
//int s[] = {0, 22, 42, 15, 22, 0, 24, 43, 0, 22, 34, 34, 14}; //
void setup()
{
  myservo.attach(servoPin);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  //pinMode(3,OUTPUT);
  Serial.begin(9600);


}

void loop()
{

  int s = 0; // this is the code number

  // changes the  the message variable
  // when this is inside the for loop the new
  // message will interupt the old message
  // works with less trouble outside but you must
  // be patient and wait for last message to finish
  if (Serial.available() > 0) {
    String m = Serial.readString();
    m.toLowerCase();  // modifies the string does not return a new one
    m.trim();
    message = " " + m; /// put a single space to show start of message
  }

  for (int i = 0; i < message.length(); i++) {
    char ch = message.charAt(i);
    if (ch != ' ') {
      s = letters[ch - 'a']; // ch = a  s will be zero and so on becaue of ascii code in decimal

    } else {
      s = 0;
    }
    Serial.println(ch);
    Serial.println(s);

    // start displaying that char code

    // spaces
    if (s == 0) {
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
    // letters
    else {
      delay(1000);
      // start tapping out letter in word
      // use math to get the number in 10s place
      int lttr = s;
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
