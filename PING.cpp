#include "PING.h"
const int pingTrig = 2;
const int Echo = 3;

PING::PING() {
  // initialize serial communication:
  Serial.begin(9600);
  pinMode(pingTrig, OUTPUT);
}

PING::~PING(){}


long PING::getDistance(){
  // establish variables for duration of the ping, 
  // and the distance result in inches and centimeters:
  long duration, cm;

  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:

  digitalWrite(pingTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(pingTrig, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingTrig, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(Echo, INPUT);
  duration = pulseIn(Echo, HIGH);

  // convert the time into a distance
  cm = microsecondsToCentimeters(duration);
  
  return cm;

}



long PING::microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}
