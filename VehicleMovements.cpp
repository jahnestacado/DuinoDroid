
#include "PING.h"
#include "VehicleMovements.h"
#include "ServoReading.h"


const int forwardA = 5;
const int backA = 6;
const int forwardB = 11;
const int backB = 12;
const int HIGH_SPEED_A = 225;
const int HIGH_SPEED_B = 220;
const int TURN_SPEED= 160;
const int LED = 13;
const int minDistance = 38;
PING ping;
boolean firstRun = true;
ServoReading servoReading;

VehicleMovements::VehicleMovements(){
   Serial.begin(9600);
   pinMode(forwardA, OUTPUT);
   pinMode(forwardB, OUTPUT);
   pinMode(backA, OUTPUT);
   pinMode(backB, OUTPUT);
   pinMode(LED, OUTPUT);
   digitalWrite(LED, LOW);
   initSensor();
}



VehicleMovements::~VehicleMovements(){}

 void VehicleMovements::initSensor(){
    stop();
    firstRun = false;
    long distance = ping.getDistance(); // Dummy first call in order to receive actual value the second time
  }

void VehicleMovements::avoidObstacle(){
   stop();
   moveToOptimalDirection();
   toggleLEDPattern(300, 1);
   stop();
   toggleLEDPattern(50, 7);
}
 
void VehicleMovements::moveToOptimalDirection(){
  boolean shouldTurnLeft = servoReading.isLeftClear();
   goBack();
   toggleLEDPattern(130, 2);
   stop();
   toggleLEDPattern(90, 2);
  if(shouldTurnLeft){
     turnLeft();
  }
  else turnRight();

}
  
  
void VehicleMovements:: goFront(){
  moveForward();
  delay(200);
}  
  
void VehicleMovements::moveForward(){
   analogWrite(forwardB, HIGH_SPEED_B);
   analogWrite(forwardA, HIGH_SPEED_A);
   digitalWrite(backA, LOW);
   digitalWrite(backB, LOW);
}  

void VehicleMovements::goBack(){
   digitalWrite(forwardA, LOW);
   digitalWrite(forwardB, LOW);
   analogWrite(backA, HIGH_SPEED_A);
   analogWrite(backB, HIGH_SPEED_B);
}  


void VehicleMovements::turnLeft(){
   digitalWrite(backB, LOW);
   digitalWrite(forwardA, LOW);
   analogWrite(forwardB, TURN_SPEED);
   analogWrite(backA, TURN_SPEED - 5);
}  

void VehicleMovements::turnRight(){
   digitalWrite(forwardB, LOW);
   digitalWrite(backA, LOW);
   analogWrite(forwardA, TURN_SPEED - 5);
   analogWrite(backB, TURN_SPEED);
} 


void VehicleMovements::moveFrontLeft(){
   digitalWrite(forwardB, HIGH_SPEED_B);
   analogWrite(forwardA, 200);
   digitalWrite(backA, LOW);
   analogWrite(backB, LOW);
} 


void VehicleMovements::moveFrontRight(){
   digitalWrite(forwardB, 195);
   analogWrite(forwardA, HIGH_SPEED_A);
   digitalWrite(backA, LOW);
   analogWrite(backB, LOW);
} 

void VehicleMovements::moveBackRight(){
   digitalWrite(forwardB, LOW);
   analogWrite(forwardA, LOW);
   digitalWrite(backA, HIGH_SPEED_A);
   analogWrite(backB, 195);
} 

void VehicleMovements::moveBackLeft(){
   digitalWrite(forwardB, LOW);
   analogWrite(forwardA, LOW);
   digitalWrite(backA, 200);
   analogWrite(backB, HIGH_SPEED_B);
} 

void VehicleMovements::stop(){
   digitalWrite(forwardA, LOW);
   digitalWrite(forwardB, LOW);
   digitalWrite(backA, LOW);
   digitalWrite(backB, LOW);
} 



void VehicleMovements::toggleLEDPattern(int duration, int times){
  for(int i = 0; i <= times -1 ; i++){
    toggleLED();
    delay(duration);
  }
}

void VehicleMovements::toggleLED() {
  int ledState = digitalRead(LED); 
   if (ledState == HIGH) 
     ledState = LOW;
   else 
     ledState = HIGH;
   digitalWrite(LED,ledState);  // make LED ON/OFF same as updated ledState
}


  
  boolean VehicleMovements::hasFoundObstacle(){
    long distance = ping.getDistance();
    Serial.println(distance);
    boolean answer =  distance <= minDistance;
    Serial.println(distance);
    return answer;
  }
  
  void VehicleMovements::beAutonomous(){
     if(!hasFoundObstacle()){
           moveForward();
           delay(400);
           return;
       }
      avoidObstacle();
  }

