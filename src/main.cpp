#include <Arduino.h>

// Libraries

#include <SoftwareSerial.h>
#include <SparkFun_TB6612.h>

int motorRileri = D1;
#define motorRgeri  D2
#define motorRhiz A1


#define motorLileri D3
#define motorLgeri D4
#define motorLhiz A2




// put function declarations here:

  
void setup() {
  // put your setup code here, to run once:

  pinMode(motorRileri,OUTPUT);
  pinMode(motorRgeri,OUTPUT);
  pinMode(motorRhiz,OUTPUT);

  pinMode(motorLileri,OUTPUT);
  pinMode(motorLgeri,OUTPUT);
  pinMode(motorLhiz,OUTPUT);


}

