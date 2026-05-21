#include <iostream>
#include <string>

#include <Arduino.h>
#include <SoftwareSerial.h>
#include <SparkFun_TB6612.h>

using namespace std;

// -- Class Structure -- //

class Robot{

    private:
    
        int motorRileri;
        int motorRgeri;
        int motorRhiz;

        int motorLileri;
        int motorLgeri;
        int motorLhiz;


        int hiz;
        char yon; 

    public:

        void ileri(int hiz);
        void geri(int hiz);
        void sag(int hiz);
        void sol(int hiz);
        void dur();

        void navigateAndMove(int hiz , char yon);

        Robot(int r1, int r2, int rh, int l1, int l2, int lh){
    
            
            int motorRileri = r1;
            int motorRgeri = r2;
            int motorRhiz = rh;
    
            int motorLileri = l1;
            int motorLgeri = l2;
            int motorLhiz = lh;
    
        }
        



};

// -- Functions -- //

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

// -- Test -- //


int main() {
    
    Robot altayBot = Robot(D1,D2,A1,D4,D5,A2);


    return 0;
}