// C++ code
//
#include <Servo.h>

Servo myservo;
 #define servoPin 9

int angle =0;
// translate sentence with python code to save arduino memory
int s[] = {0,22,42,15,22,0,24,43,0,22,34,34,14};// 
void setup()
{
  myservo.attach(servoPin);
}

void loop()
{
  for (int j = 0; j<13;j++){
    if (s[j]==0){
      // go backward for start of word
      myservo.write(180);
  	  delay(1000);
      myservo.write(0);
      delay(4000);
      
    }
    else{
      // start tapping out letter in word
      // use math to get the number in 10s place
        int lttr = s[j];
  		for (int i = 0; i<floor(lttr/10);i++){
  		myservo.write(90);
  		delay(1000);
  		myservo.write(0);
  		delay(1000);
 		 }
  		// delay between word half
        // use math to get the number in the 1s place
  		delay(2000);
  		for (int i =0; i <lttr%10;i++){
  		myservo.write(90);
  		delay(1000);
  		myservo.write(0);
  		delay(1000);
  		}
  		// delay between letters
  		delay(4000);
   		 }
  }
}