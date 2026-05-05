//Using in-built timers to run the arms. 
#include <Arduino.h>
#include <Servo.h>

const byte IN1 = 5;  
const byte IN2 = 6;
const byte IN3 = 7; 
const byte IN4 = 8;
const byte IN5 = 10; 
const byte IN6 = 11;
const byte IN7 = 12; 
const byte IN8 = 13;

const byte LG_Servo = 3; 
const byte RG_Servo = 2;


const byte endAngle = 115;
const byte startAngle = 180;


Servo Servo_L_Gaurdrail;
Servo Servo_R_Gaurdrail;

Servo Servo_ShortA;
Servo Servo_LongA;

/*------------------------------------- FUNCTION DEFINED----------------------------------------------*/

void GaurdRail_Deploy();
void ShoulderBack(char Arm);
void ElbowBack(char Arm);

/*----------------------------------------TIMINGS-----------------------------------------------------*/
unsigned long CurrentTime = millis();
bool End = false; 

unsigned long S_ShoulderBack = 150;
unsigned long S_ElbowBack = 100;
unsigned long L_ShoulderBack = 90;


void setup(){
    Servo_LongA.write(endAngle);
    Servo_LongA.attach(9);
    Servo_ShortA.write(startAngle);
    Servo_ShortA.attach(4);


    delay(100);

    GaurdRail_Deploy();

}

void loop(){}




void GaurdRail_Deploy(){
    //Currently servos must be roated either side. 
    // Code now allows bidirectional rotation at the same time. 
    Servo_L_Gaurdrail.write(180);
    delay(10);
    Servo_L_Gaurdrail.attach(LG_Servo);

    Servo_R_Gaurdrail.write(40);
    delay(10);
    Servo_R_Gaurdrail.attach(RG_Servo);

    byte LG_Angle = 180; 
    byte RG_Angle = 40; 

    while(LG_Angle != 40 ){ // only one comparison made as both angles will go through same difference
        LG_Angle--;
        RG_Angle++; 
        delay(60); // Longer delay if needed
        Servo_L_Gaurdrail.write(LG_Angle);
        Servo_R_Gaurdrail.write(RG_Angle);
    }
}

void ShoulderBack(char Arm){
    if (Arm == 'S'){
        digitalWrite(IN5,HIGH);
        digitalWrite(IN6,LOW);
        delay(10);
    }else if (Arm == 'L'){
        digitalWrite(IN3,HIGH);
        digitalWrite(IN4,LOW);
        delay(10);
    }
}

void ElbowBack(char Arm){
    if (Arm == 'S'){
        digitalWrite(IN7,HIGH);
        digitalWrite(IN8,LOW);
        delay(10);
    }else if (Arm == 'L'){
        digitalWrite(IN1,HIGH);
        digitalWrite(IN2,LOW);
        delay(10);
    }
}


void FirstBlock(){ 
    //S shoulder back 
    //S Elbow + L Shoulder : Back
    //S Hand close + L Hand Open 
    ShoulderBack('S');
    delay(100);
    CurrentTime = millis();
    while (End == false){
        // Assumes that Long Shoulder delay > Short Elbow delay
        End = true;
        if(millis() < (CurrentTime + S_ElbowBack)){
            End = false;
            ElbowBack('S');
            if(millis()<(CurrentTime + L_ShoulderBack)){
                ShoulderBack('L');
            }
        }

    }
    
    


}
