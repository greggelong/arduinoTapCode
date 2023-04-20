// C++ code
//

const int whisker = 7;
const int light = 13;
int taps=0;
int state = 0; // state of the led 1 = on 0 = off

int val =0; // will be used to store the state of the pen

int old_val = 0; // stores the previous state
unsigned long startTime;
unsigned long elapsedTime;
int firstD =0;
int secondD=0;

void setup(){
  
  pinMode(light, OUTPUT);
  pinMode(whisker, INPUT);
  Serial.begin(9600);
}

void loop(){
  // read whisker state
 
  
  val = digitalRead(whisker);  // read input and store it 
  // check if there was a transition
  
  if ((val == HIGH) && (old_val ==LOW)){
    state = 1-state;
    delay(10);
    // increace taps
    taps++;
    // start timer
    startTime = millis();
  }
    
   Serial.println("first digit");
   Serial.println(firstD);
   Serial.println("second digit");
   Serial.println(secondD);
   // get elapsed Time
  elapsedTime = millis()-startTime;
    
    if ( (elapsedTime > 1000) ||( taps >=5)){
    Serial.println("final tap");
    Serial.println(elapsedTime);
    Serial.println(taps);
      
    // set the firt digit to taps
      
      if (firstD == 0){
       firstD = taps;
      }
      else if (secondD == 0){
        secondD = taps;
      }
    // set taps to zero
    // set elapsed Time to zero
    taps =0;
    elapsedTime =0;
    startTime =millis();  
    
    
    
    
  }
      
   old_val = val; // val is now old, so store it
      
  if (state == 1){
    digitalWrite(light, HIGH);
    
   
  } else{
    digitalWrite(light, LOW);
  }
  
  
}