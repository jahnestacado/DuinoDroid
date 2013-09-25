#ifndef VehicleMovements_H
#define VehicleMovements_H
 

#include<Arduino.h>//It is very important to remember this! note that if you are using Arduino 1.0 IDE, change "WProgram.h" to "Arduino.h"
#include <Servo.h> 
class VehicleMovements {
public:
        VehicleMovements();
        ~ VehicleMovements();
  
        void avoidObstacle();
        void moveToOptimalDirection();
        void moveForward();
        void goBack();
        void turnLeft();
        void turnRight();
        void stop();
        void toggleLEDPattern(int duration, int times);
        void toggleLED();
        boolean hasFoundObstacle();
        void beAutonomous();
        void initSensor();
        void goFront();
        void moveFrontLeft();
        void moveFrontRight();
        void moveBackLeft();
        void moveBackRight();
      
      
};

#endif
