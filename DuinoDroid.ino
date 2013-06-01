#include "PING.h"
const int forwardA = 5;
const int backA = 6;
const int forwardB = 9;
const int backB = 10;
const int HIGH_SPEED_A = 225;
const int HIGH_SPEED_B = 220;
const int TURN_SPEED = 200;
const int LED = 13;
boolean firstRun = true;
const int minDistance = 35;
char incomingByte = '0';
PING ping;

void setup(){
   Serial.begin(9600);
   pinMode(forwardA, OUTPUT);
   pinMode(forwardB, OUTPUT);
   pinMode(backA, OUTPUT);
   pinMode(backB, OUTPUT);
   pinMode(LED, OUTPUT);
   digitalWrite(LED, LOW);
  
}

void loop(){
 
  if(firstRun){
    stop();
    firstRun = false;
    long distance = ping.getDistance(); // Dummy first call in order to receive actual value the second time
  }
  
  if(Serial.available() > 0){
    incomingByte = Serial.read();
  }
  
  if(incomingByte == '0'){
    stop();
  }
  
  if(incomingByte == '1'){
      beAutonomous();
  }
  
 
 }
  
void avoidObstacle(){
   goBack();
   toggleLEDPattern(130, 2);
   stop();
   toggleLEDPattern(90, 2);
   randomMove();
   toggleLEDPattern(370, 1);
   stop();
   toggleLEDPattern(50, 7);
}

void randomMove(){
  int randNum = random(0, 200);
  if(randNum <= 100){
     turnLeft();
     return;
  }
  turnRight();
}
  
void moveForward(){
   analogWrite(forwardA, HIGH_SPEED_A);
   analogWrite(forwardB, HIGH_SPEED_B);
   digitalWrite(backA, LOW);
   digitalWrite(backB, LOW);
}  

void goBack(){
   digitalWrite(forwardA, LOW);
   digitalWrite(forwardB, LOW);
   analogWrite(backA, HIGH_SPEED_A);
   analogWrite(backB, HIGH_SPEED_B);
}  


void turnLeft(){
   digitalWrite(forwardA, LOW);
   analogWrite(forwardB, TURN_SPEED);
   analogWrite(backA, TURN_SPEED);
   digitalWrite(backB, LOW);
}  

void turnRight(){
   digitalWrite(forwardA, TURN_SPEED);
   analogWrite(forwardB, LOW);
   analogWrite(backA, LOW);
   digitalWrite(backB, TURN_SPEED);
} 

void stop(){
   digitalWrite(forwardA, LOW);
   digitalWrite(forwardB, LOW);
   digitalWrite(backA, LOW);
   digitalWrite(backB, LOW);
} 

void toggleLEDPattern(int duration, int times){
  for(int i = 0; i <= times -1 ; i++){
    toggleLED();
    delay(duration);
  }
}

void toggleLED() {
  int ledState = digitalRead(LED); 
   if (ledState == HIGH) 
     ledState = LOW;
   else 
     ledState = HIGH;
   digitalWrite(LED,ledState);  // make LED ON/OFF same as updated ledState
}


  
  boolean hasFoundObstacle(){
    long distance = ping.getDistance();
    Serial.println(distance);
    boolean answer =  distance <= minDistance;
    Serial.println(distance);
    return answer;
  }
  
  void beAutonomous(){
     if(!hasFoundObstacle()){
           moveForward();
           delay(400);
           return;
       }
      avoidObstacle();
  }

