
#include "Servo.h"
#include "ServoReading.h"
#include "PING.h"
Servo servo; 
PING ping2;
const int servoPin = 10;

ServoReading::ServoReading(){
 }



ServoReading::~ServoReading(){
}



boolean ServoReading::isLeftClear(){
   servo.attach(servoPin);
   long rightDistance = 0;
   long leftDistance = 0;
   servo.write(90);
   delay(200);
   servo.write(40); 
   delay(800);
   rightDistance = ping2.getDistance(); 
   servo.write(90);                  
   delay(800);
   servo.write(135);                
   delay(800);
   leftDistance = ping2.getDistance();
   servo.write(90); 
   delay(800);
   if(rightDistance < leftDistance){
     return true;
   }
     return false;
    

}
  
  

