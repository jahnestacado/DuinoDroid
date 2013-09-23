#ifndef PING_H
#define PING_H
 

#include<Arduino.h>//It is very important to remember this! note that if you are using Arduino 1.0 IDE, change "WProgram.h" to "Arduino.h"
 
class PING {
public:
        PING();
        ~PING();
        long getDistance();
        long microsecondsToCentimeters(long microseconds);
      
};

#endif
