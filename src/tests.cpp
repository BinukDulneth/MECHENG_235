// #include <Arduino.h>
// #include <Servo.h>


// /*-----------------------------------MOTOR DRIVER PIN DEFINITIIONS --------------------------------------------------*/
// // ELBOW
// const byte IN1 = 6; //L  
// const byte IN2 = 9;

// const byte IN3 = 2; //S
// const byte IN4 = 4;


// //SHOULDER
// const byte IN5 = 10; //S
// const byte IN6 = 11;

// const byte IN7 = 3; //L
// const byte IN8 = 5; 

// const byte LG_ServoPin = A0; 
// const byte RG_ServoPin = A1;   // change accordingly

// /*--------------------------------SWITCH PIN DEFINITIONS--------------------------------------------------------------*/

// byte ShortA_Switch = A2; 
// byte LongA_Switch = A3;
// byte RedLED = A4;
// //byte GreenLED = A5;
// byte Buzzer = A5;
// /*-----------------------------------Servo PINS + HAND ANGLES-------------------------------------------------------*/

// const byte Servo_L_Pin = 8;
// const byte Servo_S_Pin = 7;

// const byte endAngle = 110;
// const byte startAngle = 180;

// byte S_Angle = startAngle;
// byte L_Angle = endAngle;

// /*-----------------------------------SERVO DEFINITIONS------------------------------------------------*/
// Servo Servo_L_Gaurdrail;
// Servo Servo_R_Gaurdrail;

// Servo Servo_ShortA;
// Servo Servo_LongA;

// /*------------------------------------- FUNCTION DEFINED----------------------------------------------*/

// void Startup();
// void GaurdRail_Deploy();

// void AttachServos();
// void DettachServos();

// void ShoulderBack(char Arm, byte Power);
// void ElbowBack(char Arm);
// void ShoulderUp(char Arm);
// void ElbowUp(char Arm);
// void ElbowStop(char Arm);
// void ShoulderStop(char Arm);
// void FirstBlock();
// void SecondBlock(); 
// void ThirdBlock();

// /*----------------------------------------TIMINGS-----------------------------------------------------*/
// unsigned long CurrentTime = millis();
// bool EventA = false;
// bool EventB = false; 


// const byte GR_Duration = 200;

// unsigned long S_ShoulderBack = 120;
// // S_ElbowBack > L_ShoulderBack
// unsigned long S_ElbowBack = 100;
// unsigned long L_ShoulderBack = 85;

// unsigned long S_ShoulderUp = 600;
// unsigned long S_ElbowUp = 500;
// unsigned long L_ElbowDown = 100;

// unsigned long L_ShoulderUp = 700;
// unsigned long L_ElbowUp = 200;

// /*-----------------------------------GLOBAL VARIABLES-----------------------------------------------*/

// byte powerA;

// /*----------------------------------------MAIN------------------------------------------------------*/

// void setup(){
    

//     for (int p = 2 ; p <= 13; p++) {
//         if ( (p != Servo_S_Pin) && (p != Servo_L_Pin) ) { //Skip servo pins
//             pinMode(p, OUTPUT); 
//         }
//     }

//     Serial.begin(9600);
//     Serial.println("Restarted");

//     pinMode(Buzzer,OUTPUT);
//     pinMode(RedLED,OUTPUT);
//     pinMode(ShortA_Switch,INPUT_PULLUP);
//     pinMode(LongA_Switch,INPUT_PULLUP);
   

//     Servo_LongA.write(endAngle);
//     Servo_LongA.attach(Servo_L_Pin);
//     Servo_ShortA.write(startAngle);
//     Servo_ShortA.attach(Servo_S_Pin);
//     delay(100);


//     GaurdRail_Deploy();
//     FirstBlock();
//     SecondBlock();
//     ThirdBlock();
    
//     DettachServos();
//     ShoulderStop('L');
//     ShoulderStop('S');

//     ElbowStop('L');
//     ElbowStop('S');

//     digitalWrite(13,HIGH);



// }

// void loop(){
//     //digitalWrite(4,HIGH);
// }


// void Startup(){
//     for(byte i = 0; i < 3; i++){
//         digitalWrite(Buzzer,HIGH);
//         delay(500);
//         digitalWrite(Buzzer,LOW);
//         delay(500);
//     }
// }


// void DettachServos(){
//     Servo_LongA.detach();
//     Servo_ShortA.detach();
// }

// void GaurdRail_Deploy(){
//     Servo_L_Gaurdrail.attach(LG_ServoPin);
//     Servo_R_Gaurdrail.attach(RG_ServoPin);

//     Servo_L_Gaurdrail.write(90);
//     Servo_R_Gaurdrail.write(90);

//     Servo_L_Gaurdrail.write(50);
//     Servo_R_Gaurdrail.write(130);
//     delay(300);

//     Servo_L_Gaurdrail.write(90);
//     Servo_R_Gaurdrail.write(90);

//     Servo_L_Gaurdrail.detach();
//     Servo_R_Gaurdrail.detach();

// }

// void ShoulderBack(char Arm, byte Power){
//     if (Arm == 'S'){
//         analogWrite(IN5,Power);
//         digitalWrite(IN6,LOW);
//         //delay(10);
//     }else if (Arm == 'L'){
//         analogWrite(IN7,Power);
//         digitalWrite(IN8,LOW);
//         //delay(10);
//     }
// }

// void ElbowBack(char Arm){
//     if (Arm == 'S'){
//         digitalWrite(IN3,HIGH);
//         digitalWrite(IN4,LOW);
//         //delay(10);
//     }else if (Arm == 'L'){
//         digitalWrite(IN1,HIGH);
//         digitalWrite(IN2,LOW);
//         //delay(10);
//     }
// }

// void ShoulderUp(char Arm){
//     if (Arm == 'S'){
//         digitalWrite(IN5,LOW);
//         digitalWrite(IN6,HIGH);
//     } else if (Arm == 'L'){
//         digitalWrite(IN7,LOW);
//         digitalWrite(IN8,HIGH);
//     }
// }

// void ElbowUp(char Arm){
//     if (Arm == 'S'){
//         digitalWrite(IN3,LOW);
//         digitalWrite(IN4,HIGH);
//     }else if (Arm == 'L'){
//         digitalWrite(IN1,LOW);
//         digitalWrite(IN2,HIGH);
//     }
// }

// void ElbowStop(char Arm){
//     if (Arm == 'S'){
//         digitalWrite(IN3,LOW);
//         digitalWrite(IN4,LOW);
//         //delay(10);
//     }else if (Arm == 'L'){
//         digitalWrite(IN1,LOW);
//         digitalWrite(IN2,LOW);
//         //delay(10);
//     }
// }

// void ShoulderStop(char Arm){ 
//     if (Arm == 'S'){
//         digitalWrite(IN5,LOW);
//         digitalWrite(IN6,LOW);
//         //delay(10);
//     }else if (Arm == 'L'){
//         digitalWrite(IN7,LOW);
//         digitalWrite(IN8,LOW);
//         //delay(10);
//     }
// }

// void FirstBlock(){ 
//     /*

//     Status: In - Progress


//     Overview of sequence in order: 
//         1) S shoulder back 
//         2) S Elbow + L Shoulder : Back
//         3) S Hand close + L Hand Open 

//     */


//     //Step 1 
//     powerA= 255;
//     ShoulderBack('S',powerA);
//     CurrentTime = millis();
//     while(millis() < (CurrentTime + 100)){      // Delay : 100 ms 
//         ShoulderBack('S',(powerA - 5));
//     }
//     ShoulderStop('S');
//     delay(20);

//     //Step 2
//     // S Elbow > L Shoulder
//     powerA= 255;
//     ElbowBack('S');
//     ShoulderBack('L',powerA);
//     CurrentTime = millis();
//     while(true){

//         if (powerA != 0) {
//             ShoulderBack('L', (powerA - 10) );
//         }

//         if (millis() > (CurrentTime + S_ElbowBack)){
//             ElbowStop('S');
//             break; 
//         }

//         if (millis() > (CurrentTime + L_ShoulderBack)){
//             ShoulderStop('L');
//             powerA = 0;
//         }
     
//     }
//     delay(20);

//     //Step 3 
//     //S Hand Closing + L Hand Opening
//     while(S_Angle != endAngle){
//         S_Angle--;
//         L_Angle++;
//         Servo_ShortA.write(S_Angle);
//         Servo_LongA.write(L_Angle);
//         delay(30);
//     }
//     delay(100);

// }

// void SecondBlock(){
//     /*
    
//     Overview :
//         1) S_Shoulder Up >+ S_Elbow Up 
//         2) L Elbow Down 
//         3) L Hand close + S Hand Open 
//     */
   
   
//     ShoulderUp('S');
//     ElbowUp('S');
//     CurrentTime = millis();
//     while (true){
//         if(millis() > (CurrentTime + S_ElbowUp)){
//             ElbowStop('S');
//         }
//         if (millis() > (CurrentTime + S_ShoulderUp)){                              //digitalRead(ShortA_Switch) == LOW
//             ShoulderStop('S');
//             break;          //S_ShoulderUp>
//         }
//     }

    


//     ElbowBack('L'); //uses HIGH as their is Pin conflicts 
//     delay(L_ElbowDown);
//     ElbowStop('L');


//     while(S_Angle != startAngle){
//         S_Angle++;
//         L_Angle--;
//         Servo_ShortA.write(S_Angle);
//         Servo_LongA.write(L_Angle);
//         delay(30);
//     }
//     delay(100);

// }

// void ThirdBlock(){
//     /*
//     Overview : 
//         1) S_ShoulderBack + S_ElbowBack
//         2) L_ShoulderUp + L_ElbowUp
//         3) L Hand Open
//     */

//     powerA = 255;
//     ShoulderBack('S',powerA);
//     ElbowBack('S');
//     CurrentTime = millis(); 
//     while(true){ 
//         ShoulderBack('S',(powerA - 10));
//         if (millis() > (CurrentTime + (S_ShoulderBack) )){
//             ShoulderStop('S');
//             break;              // Shoulder Delay >
//         }
//         if (millis() > (CurrentTime + (S_ElbowBack) )){
//             ElbowStop('S');
//         }
//     }

   

//     ShoulderUp('L'); // HIGH/LOW logic cause of Conflict 
//     ElbowUp('L');
//     CurrentTime = millis();
//     while(true){
//         if(millis() > (CurrentTime + L_ElbowUp)){
//             ElbowStop('L');
//         }
//         if(millis() > (CurrentTime + L_ShoulderUp)){                                                   //digitalRead(LongA_Switch) == LOW
//             ShoulderStop('L');
//             break;
//         }
//     }

//     while(L_Angle != startAngle){
//         L_Angle--;
//         Servo_LongA.write(L_Angle);
//         delay(10);
//     }

// }


