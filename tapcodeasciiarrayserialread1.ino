// C++ code
//
#include <Servo.h>

Servo myservo;
 #define servoPin 9

int angle =0;
// a-z 97 122 ascii code in decimal
// translate sentence with python code to save arduino memory
int letters[] = {11,12,13,14,15,21,22,23,24,25,13,31,32,33,34,35,41,42,43,44,45,51,52,53,54,55};

void setup()
{
  myservo.attach(servoPin);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(3,OUTPUT);
  Serial.begin(9600);
  
  
}

void loop()
{
  int s=0; // var to hold two digit number that matches letter
  char ch; // var to hold char from serial
  if (Serial.available()>0){
    ch = Serial.read();
    s = letters[ch - 'a']; // ch = a  s will be zero and so on becaue of ascii code in decimal
    Serial.println(s);
    Serial.println(ch);
  }
  
  //When you enter a sentence in to the serial like "greg is good"
  //it will process the whole sentence one character at a time
  // spaces will produce an s that is zero
  // the sentence is held in the 128 byte UART buffer
  // and each byte of teh sentence is removed as read.
    
    if (s==0){
      // go backward for start of word
      // move servo
      myservo.write(60);
      // light green leg
      digitalWrite(7,HIGH);
      // piezo
      tone(3,500);
  	  delay(2000);
      myservo.write(0);
      digitalWrite(7,LOW);
      noTone(3);
      delay(4000);
      
    }
    else{
      // start tapping out letter in word
      // use math to get the number in 10s place
        int lttr = s;
  		for (int i = 0; i<floor(lttr/10);i++){
  		myservo.write(90);
        digitalWrite(8,HIGH);
        // piezo
        tone(3,420);
  		delay(1000);
  		myservo.write(0);
        digitalWrite(8,LOW);
        noTone(3);
  		delay(1000);
 		 }
  		// delay between letter half
        // use math to get the number in the 1s place
  		delay(2000);
  		for (int i =0; i <lttr%10;i++){
  		myservo.write(90);
        digitalWrite(8,HIGH);
        // piezo
        tone(3,420);
  		delay(1000);
  		myservo.write(0);
        digitalWrite(8,LOW);
        noTone(3);
  		delay(1000);
  		}
  		// delay between letters
  		delay(4000);
   		 }
  
}