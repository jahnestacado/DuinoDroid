#ifndef ServoReading_H
#define ServoReading_H
 

#include<Arduino.h>//It is very important to remember this! note that if you are using Arduino 1.0 IDE, change "WProgram.h" to "Arduino.h"
 
class ServoReading {
public:
        ServoReading();
        ~ServoReading();
        boolean isLeftClear();
       
};

#endif
