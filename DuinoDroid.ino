#include "Autonomous.h"


char incomingByte = '0';
Autonomous autonomous;
boolean isAuto = false;


void setup(){
   Serial.begin(9600);
 
  
}

void loop(){
 incomingByte = 'E';
  if(Serial.available() > 0){
    incomingByte = Serial.read();
    Serial.println(incomingByte);
  }

  
  
  if(incomingByte == '0'){
    isAuto = false;
  }
  else if(incomingByte == 'A'){
   isAuto = true;
 } 
 else if(incomingByte == 'M') {
    isAuto = false;
  }
  
  

  if(isAuto){
    autonomous.beAutonomous();
  }
  else if(incomingByte == 'E'){
    autonomous.stop();
  }
  else interpretCommand(incomingByte);
  
 
 
 
 }
 
 void interpretCommand(char command){
   switch(command){
     case '0':  autonomous.stop();
     break;
     case 'F': autonomous.moveForward();
     delay(100);
     break;
     case 'B': autonomous.goBack();
     delay(100);
     break;
     
   }
   
 }
 
