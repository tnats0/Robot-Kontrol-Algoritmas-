#include <Arduino.h>
#include <SoftwareSerial.h>
#include <string>


#define rx D7 
#define tx D8

SoftwareSerial robotCom(rx,tx);


void setup(){

    Serial.begin(9600);
    robotCom.begin(9600);

}

void loop(){


    while (robotCom.available()){

        char data = robotCom.read();

        Serial.println(data);
            
    }

}