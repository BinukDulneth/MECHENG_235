
#include <Arduino.h>
#include <Servo.h>

/*-----------------------------------MOTOR DRIVER PIN DEFINITIIONS --------------------------------------------------*/
// ELBOW
const byte IN1 = 6; //L  
const byte IN2 = 9;

const byte IN3 = 2; //S
const byte IN4 = 4;


//SHOULDER
const byte IN5 = 11; //S
const byte IN6 = 10;

const byte IN7 = 3; //L
const byte IN8 = 5; 

const byte LG_ServoPin = A0; 
const byte RG_ServoPin = A1;   // change accordingly

/*--------------------------------SWITCH PIN DEFINITIONS--------------------------------------------------------------*/

byte ShortA_Switch = A3; 
byte LongA_Switch = A2;

byte Buzzer = A5;
/*-----------------------------------Servo PINS + HAND ANGLES-------------------------------------------------------*/

const byte Servo_L_Pin = 8;
const byte Servo_S_Pin = 7;

const byte endAngle = 85;
const byte startAngle = 180;

byte S_Angle = startAngle;
byte L_Angle = startAngle;

/*-----------------------------------SERVO DEFINITIONS------------------------------------------------*/
Servo Servo_L_Gaurdrail;
Servo Servo_R_Gaurdrail;

Servo Servo_ShortA;
Servo Servo_LongA;

/*------------------------------------- FUNCTION DEFINED----------------------------------------------*/

void Startup();
void GaurdRail_Deploy();


void DettachServos();

void ShoulderBack(char Arm, byte Power);
void ElbowBack(char Arm);
void ShoulderUp(char Arm);
void ElbowUp(char Arm);
void ElbowStop(char Arm);
void ShoulderStop(char Arm);
void FirstBlock();
void SecondBlock(); 

/*----------------------------------------TIMINGS-----------------------------------------------------*/
bool EventA = false;


const byte GR_Duration = 200;

unsigned int L_ElbowBack = 100;
unsigned int L_ShoulderBack = 70;
unsigned int S_ElbowBack = 110;
unsigned int S_ShoulderBack = 140;


unsigned long S_ElbowUp = 250;
unsigned long L_ElbowUp = 100;

/*-----------------------------------GLOBAL VARIABLES-----------------------------------------------*/

byte powerA;

/*----------------------------------------MAIN------------------------------------------------------*/

void setup(){
    

    for (int p = 2 ; p <= 13; p++) {
        if ( (p != Servo_S_Pin) && (p != Servo_L_Pin) ) { //Skip servo pins
            pinMode(p, OUTPUT); 
        }
    }

    pinMode(Buzzer,OUTPUT);
    pinMode(ShortA_Switch,INPUT_PULLUP);
    pinMode(LongA_Switch,INPUT_PULLUP);
   

    Servo_LongA.write(startAngle);
    Servo_LongA.attach(Servo_L_Pin);
    Servo_ShortA.write(startAngle);
    Servo_ShortA.attach(Servo_S_Pin);
    delay(100);


    digitalWrite(13,LOW);
    //Startup();
    GaurdRail_Deploy();
    FirstBlock();
    SecondBlock();

    //Safety : turning the Motors off to prevent stalling
    DettachServos();
    ShoulderStop('L');
    ShoulderStop('S');
    ElbowStop('L');
    ElbowStop('S');

    digitalWrite(13,HIGH);

}

void loop(){

}


void Startup(){
    for(byte i = 0; i < 3; i++){
        digitalWrite(Buzzer,HIGH);
        delay(500);
        digitalWrite(Buzzer,LOW);
        delay(500);
    }
}


void DettachServos(){
    Servo_LongA.detach();
    Servo_ShortA.detach();
}

void GaurdRail_Deploy(){
    Servo_L_Gaurdrail.attach(LG_ServoPin);
    Servo_R_Gaurdrail.attach(RG_ServoPin);

    Servo_L_Gaurdrail.write(90);
    Servo_R_Gaurdrail.write(90);

    Servo_L_Gaurdrail.write(50);
    Servo_R_Gaurdrail.write(130);
    delay(GR_Duration);

    Servo_L_Gaurdrail.write(90);
    Servo_R_Gaurdrail.write(90);

    Servo_L_Gaurdrail.detach();
    Servo_R_Gaurdrail.detach();

}

void ShoulderBack(char Arm, byte Power){
    if (Arm == 'S'){
        analogWrite(IN5,Power);
        digitalWrite(IN6,LOW);
    }else if (Arm == 'L'){
        analogWrite(IN7,Power);
        digitalWrite(IN8,LOW);
    }
}

void ElbowBack(char Arm){
    if (Arm == 'S'){
        digitalWrite(IN3,HIGH);
        digitalWrite(IN4,LOW);
    }else if (Arm == 'L'){
        digitalWrite(IN1,HIGH);
        digitalWrite(IN2,LOW);
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
    }else if (Arm == 'L'){
        digitalWrite(IN1,LOW);
        digitalWrite(IN2,LOW);
    }
}

void ShoulderStop(char Arm){ 
    if (Arm == 'S'){
        digitalWrite(IN5,LOW);
        digitalWrite(IN6,LOW);
    }else if (Arm == 'L'){
        digitalWrite(IN7,LOW);
        digitalWrite(IN8,LOW);
    }
}

void FirstBlock(){ 
    /*
        Overview  :  
            1) Long Arm Grabs ball 
            2) Short Arm grabs ball 
    */

    ElbowBack('L');
    delay(L_ElbowBack);
    ElbowStop('L');

    delay(100);

    ShoulderBack('L',190);
    delay(L_ShoulderBack);
    ShoulderStop('L');


    delay(200);

    //Closing Of Long Arm's Claw
    while(L_Angle != endAngle){
        L_Angle--;
        Servo_LongA.write(L_Angle);
        delay(10);
    }

    delay(100);

    ElbowBack('S');
    delay(S_ElbowBack);
    ElbowStop('S');

    delay(100);

    ShoulderBack('S',200);
    delay(S_ShoulderBack);
    ShoulderStop('S');

    delay(300);

    //Closing of Short Arm's Claw
    while(S_Angle != endAngle){
        S_Angle--;
        Servo_ShortA.write(S_Angle);
        delay(10);
    }


}

void SecondBlock(){
    /*
        Overview : 
            1) Long Arm delivers the ball 
            2) Short Armrm delivers the ball 

    */

    
    int count = 0; 
    ShoulderUp('L');

    while (digitalRead(LongA_Switch)!=LOW ) {
        count++;
        if (count >= 160){
            break;
        }
        
        delay(5);
    }
    delay(20);
    ShoulderStop('L');


    ElbowUp('L');
    delay(L_ElbowUp);
    ElbowStop('L');

    delay(400);

    //Opening the Long Arm's Claw to release the ball.
    while(L_Angle != startAngle){
        L_Angle++;
        Servo_LongA.write(L_Angle);
        delay(15);
    }

    delay(100);

    ElbowBack('L');
    delay(L_ElbowBack);
    ElbowStop('L');

    delay(100);

    ElbowUp('S');
    delay(S_ElbowUp);
    ElbowStop('S');

    ShoulderUp('S');
    count = 0;
    while (digitalRead(ShortA_Switch)!=LOW) {
        count++;
        if(count >= 160){
            break;
        }
        delay(5);
    }
    delay(20);
    ShoulderStop('S');

    delay(200);
    
    //Opening of Short Arm's Claw to release the ball. 
    while(S_Angle != startAngle){
        S_Angle++;
        Servo_ShortA.write(S_Angle);
        delay(15);
    }


}