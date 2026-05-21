#include <iostream>
#include <string>
#include <vector>

#include <SoftwareSerial.h>
#include <SparkFun_TB6612.h>
#include <Arduino.h>

using namespace std;

#define motorRileri D1
#define motorRgeri  D2
#define motorRhiz A1


#define motorLileri D3
#define motorLgeri D4
#define motorLhiz A2

void setup() {

  pinMode(motorRileri,OUTPUT);
  pinMode(motorRgeri,OUTPUT);
  pinMode(motorRhiz,OUTPUT);

  pinMode(motorLileri,OUTPUT);
  pinMode(motorLgeri,OUTPUT);
  pinMode(motorLhiz,OUTPUT);

}

class Robot{

    private:
    
        int hiz;
        char yon; 

        void ileri(int hiz);
        void geri(int hiz);
        void sag(int hiz);
        void sol(int hiz);
        void dur();

        void navigateAndMove(int hiz , char yon);

        Robot(int varsayilanHiz,int varsayilanYon){

            hiz = varsayilanHiz;
            yon = varsayilanYon; 

        }

};



void Robot::ileri(int hiz) {

  digitalWrite(motorRileri,1);
  digitalWrite(motorRgeri,0);
  analogWrite(motorRhiz,hiz);

  digitalWrite(motorLileri,1);
  digitalWrite(motorLgeri,0);
  analogWrite(motorLhiz,hiz);

}

void Robot::geri(int hiz){

  digitalWrite(motorRileri,0);
  digitalWrite(motorRgeri,1);
  analogWrite(motorRhiz,hiz);

  digitalWrite(motorLileri,0);
  digitalWrite(motorLgeri,1);
  analogWrite(motorLhiz,hiz);

}

void Robot::sag(int hiz) {

  digitalWrite(motorRileri,0);
  digitalWrite(motorRgeri,0);

  digitalWrite(motorLileri,1);
  digitalWrite(motorLgeri,0);
  analogWrite(motorLhiz,hiz);

}

void Robot::sol(int hiz){

  digitalWrite(motorRileri,1);
  digitalWrite(motorRgeri,0);
  analogWrite(motorRhiz,hiz);

  digitalWrite(motorLileri,0);
  digitalWrite(motorLgeri,0);
}

void Robot::dur(){

  digitalWrite(motorRileri,0);
  digitalWrite(motorRgeri,0);

  digitalWrite(motorLileri,0);
  digitalWrite(motorLgeri,0);

}

void Robot::navigateAndMove(int hiz,char yon){

      switch (yon)
      {
      case 'F':
              ileri(hiz);
              break;

      case 'R':
              sag(hiz);
              break;

      case 'L':
              sol(hiz);
              break;

      case 'B':
              geri(hiz);
              break;


      default:
              dur();
              break;
      }

}

