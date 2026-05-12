#include <Arduino.h>
#include <Servo.h>

/*-----------------------------------MOTOR DRIVER PIN DEFINITIIONS --------------------------------------------------*/
// ELBOW
const byte IN1 = 6; //L  
const byte IN2 = 9;
const byte IN3 = 2; //S
const byte IN4 = 4;


//SHOULDER
const byte IN5 = 10; //S
const byte IN6 = 11;
const byte IN7 = 3; //L
const byte IN8 = 5;

const byte LG_ServoPin = A0; 
const byte RG_ServoPin = A1;   // change accordingly

/*-----------------------------------HAND ANGLES-------------------------------------------------------*/

const byte Servo_L_Pin = 8;
const byte Servo_S_Pin = 7;

const byte endAngle = 110;
const byte startAngle = 180;

byte S_Angle = startAngle;
byte L_Angle = endAngle;


/*-----------------------------------SERVO DEFINITIONS------------------------------------------------*/
Servo Servo_L_Gaurdrail;
Servo Servo_R_Gaurdrail;

Servo Servo_ShortA;
Servo Servo_LongA;


/*------------------------------------- FUNCTION DEFINED----------------------------------------------*/

void GaurdRail_Deploy();
void ShoulderBack(char Arm);
void ElbowBack(char Arm);
void ShoulderUp(char Arm);
void ElbowUp(char Arm);
void ElbowStop(char Arm);
void ShoulderStop(char Arm);
void FirstBlock();
void SecondBlock(); 
void ThirdBlock();


/*----------------------------------------TIMINGS-----------------------------------------------------*/
unsigned long CurrentTime = millis();
bool EventA = false;
bool EventB = false; 


const byte GR_Duration = 200;

unsigned long S_ShoulderBack = 150;
// S_ElbowBack > L_ShoulderBack
unsigned long S_ElbowBack = 100;
unsigned long L_ShoulderBack = 90;

unsigned long S_ShoulderUp = 1500;
unsigned long S_ElbowUp = 1200;
unsigned long L_ElbowDown = 80;

unsigned long L_ShoulderUp = 700;
unsigned long L_ElbowUp = 100;





/*----------------------------------------MAIN------------------------------------------------------*/

void setup(){

    Servo_LongA.write(endAngle);
    Servo_LongA.attach(Servo_L_Pin);
    Servo_ShortA.write(startAngle);
    Servo_ShortA.attach(Servo_S_Pin);
    delay(100);

    for (int p = 2 ; p <= 13; p++) {
        if (p != 9 & p != 4 & p != 2 & p != 3) { // Skip pin 9,4,3,2 (the servos)
            pinMode(p, OUTPUT); 
        }
    }
    

    GaurdRail_Deploy();
    // FirstBlock();
    // SecondBlock();
    // ThirdBlock();

}

void loop(){
}




void GaurdRail_Deploy(){
    Servo_L_Gaurdrail.attach(LG_ServoPin);
    Servo_R_Gaurdrail.attach(RG_ServoPin);

    Servo_L_Gaurdrail.write(90);
    Servo_R_Gaurdrail.write(90);

    Servo_L_Gaurdrail.write(30);
    Servo_R_Gaurdrail.write(150);
    delay(200);

    Servo_L_Gaurdrail.write(90);
    Servo_R_Gaurdrail.write(90);

    Servo_L_Gaurdrail.detach();
    Servo_R_Gaurdrail.detach();
}




void ShoulderBack(char Arm){
    if (Arm == 'S'){
        digitalWrite(IN5,HIGH);
        digitalWrite(IN6,LOW);
        //delay(10);
    }else if (Arm == 'L'){
        digitalWrite(IN7,HIGH);
        digitalWrite(IN8,LOW);
        //delay(10);
    }
}

void ElbowBack(char Arm){
    if (Arm == 'S'){
        digitalWrite(IN3,HIGH);
        digitalWrite(IN4,LOW);
        //delay(10);
    }else if (Arm == 'L'){
        digitalWrite(IN1,HIGH);
        digitalWrite(IN2,LOW);
        //delay(10);
    }
}

void ShoulderUp(char Arm){
    if (Arm == 'S'){
        digitalWrite(IN5,LOW);
        digitalWrite(IN6,HIGH);
    } else if (Arm == 'L'){
        digitalWrite(IN7,LOW);
        digitalWrite(IN8,HIGH);
    }
}

void ElbowUp(char Arm){
    if (Arm == 'S'){
        digitalWrite(IN3,LOW);
        digitalWrite(IN4,HIGH);
    }else if (Arm == 'L'){
        digitalWrite(IN1,LOW);
        digitalWrite(IN2,HIGH);
    }
}

void ElbowStop(char Arm){
    if (Arm == 'S'){
        digitalWrite(IN3,LOW);
        digitalWrite(IN4,LOW);
        //delay(10);
    }else if (Arm == 'L'){
        digitalWrite(IN1,LOW);
        digitalWrite(IN2,LOW);
        //delay(10);
    }
}

void ShoulderStop(char Arm){ 
    if (Arm == 'S'){
        digitalWrite(IN5,LOW);
        digitalWrite(IN6,LOW);
        //delay(10);
    }else if (Arm == 'L'){
        digitalWrite(IN7,LOW);
        digitalWrite(IN8,LOW);
        //delay(10);
    }
}


void FirstBlock(){ 
    /*

    Status: In - Progress


    Overview of sequence in order: 
        1) S shoulder back 
        2) S Elbow + L Shoulder : Back
        3) S Hand close + L Hand Open 

    */


    //Step 1 
    ShoulderBack('S');
    delay(100);
    ShoulderStop('S');

   
    //Step 2
    // S Elbow > L Shoulder
    ElbowBack('S');
    ShoulderBack('L');
    CurrentTime = millis();
    while(true){
        if (millis() > (CurrentTime + S_ElbowBack)){
            ElbowStop('S');
            break; 
        }
        if (millis() > (CurrentTime + L_ShoulderBack)){
            ShoulderStop('L');
        }
    }

    //Step 3 
    //S Hand Closing + L Hand Opening
    while(S_Angle != endAngle){
        S_Angle--;
        L_Angle++;
        Servo_ShortA.write(S_Angle);
        Servo_LongA.write(L_Angle);
        delay(20);
    }
}

void SecondBlock(){
    /*
    
    Overview :
        1) S_Shoulder Up >+ S_Elbow Up 
        2)L Elbow Down 
        3)L Hand close + S Hand Open 
    */

    ShoulderUp('S');
    ElbowUp('S');
    CurrentTime = millis();
    while (true){
        if (millis() > (CurrentTime + S_ShoulderUp)){
            ShoulderStop('S');
            break;          //S_ShoulderUp>
        }
        if(millis() > (CurrentTime + S_ElbowUp)){
            ElbowStop('S');
        }
    }

    ElbowBack('L');
    delay(70);
    ElbowStop('L');



    while(S_Angle != startAngle){
        S_Angle++;
        L_Angle--;
        Servo_ShortA.write(S_Angle);
        Servo_LongA.write(L_Angle);
        delay(20);
    }

}

void ThirdBlock(){
    /*
    Overview : 
        1) S_ShoulderBack + S_ElbowBack
        2) L_ShoulderUp + L_ElbowUp
        3) L Hand Open
    */

    ShoulderBack('S');
    ElbowBack('S');
    CurrentTime = millis(); 
    while(1){ 
        if (millis() > (CurrentTime + (S_ShoulderBack/4) )){
            ShoulderStop('L');
            break;              // Shoulder Delay >
        }
        if (millis() > (CurrentTime + (S_ElbowBack/4
        ) )){
            ElbowStop('L');
        }
    }


    ShoulderUp('L');
    ElbowUp('L');
    CurrentTime = millis();
    while(1){
        if(millis() > (CurrentTime + L_ShoulderUp)){ 
            ShoulderStop('L');
            break;
        }
        if(millis() > (CurrentTime + L_ElbowUp)){
            ElbowStop('L');
        }
    }



    while(L_Angle != startAngle){
        L_Angle--;
        Servo_LongA.write(L_Angle);
        delay(20);
    }
}


