#include "VehicleMovements.h"
#include <Servo.h> 

char incomingByte = '0';
VehicleMovements movements;
boolean isAuto = false;


void setup(){
   Serial.begin(9600); 
   movements.initSensor();

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
    movements.beAutonomous();
  }
  else if(incomingByte == 'E'){
    movements.stop();
  }
  else interpretCommand(incomingByte);
  
 
 
 
 }
 
 void interpretCommand(char command){
   switch(command){
     case '0':  movements.stop();
     break;
     case 'F': movements.moveForward();
     delay(100);
     break;
     case 'B': movements.goBack();
     delay(100);
     break;
      case 'L': movements.turnLeft();
     delay(100);
     break;
      case 'R': movements.turnRight();
     delay(100);
     break;
     case '7': movements.moveFrontLeft();
     delay(100);
     break;
     case '9': movements.moveFrontRight();
     delay(100);
     break;
      case '3': movements.moveBackLeft();
     delay(100);
     break;
      case '4': movements.moveBackRight();
     delay(100);
     break;
     
   }
   
 }
 
