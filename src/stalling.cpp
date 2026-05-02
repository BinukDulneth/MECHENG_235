#include "stalling.h"

const int motorIN1 = 5;  
const int motorIN2 = 6; 
const int motorIN3 = 7; 
const int motorIN4 = 8; 



void ShoulderStall(int motorIN1, int motorIN2){ 
    analogWrite(motorIN1,0);
    analogWrite(motorIN2,0);
    ElbowStall_UP(motorIN3,motorIN4);
}



void ElbowStall_UP(int motorIN3, int motorIN4){
    analogWrite(motorIN3,120);
    analogWrite(motorIN4,0);

}

void ElbowStall_DOWN(int motorIN3, int motorIN4){
    analogWrite(motorIN3,180);
    analogWrite(motorIN4,0);
}