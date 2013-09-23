#ifndef Autonomous_H
#define Autonomous_H
 

#include<Arduino.h>//It is very important to remember this! note that if you are using Arduino 1.0 IDE, change "WProgram.h" to "Arduino.h"
 
class Autonomous {
public:
        Autonomous();
        ~ Autonomous();
  
        void avoidObstacle();
        void randomMove();
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
      
};

#endif
