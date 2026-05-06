// #include <Arduino.h>
// #include <Servo.h> 
// #include <movement.h>

// Servo myServo;
// Servo myServo2;

// Servo Servo_L_Gaurdrail;
// Servo Servo_R_Gaurdrail;

// // Pin Definitions


// int startAngle = 180;
// int endAngle = 110;


// void setup() {
//   // Initialize ALL motor pins as OUTPUT
//   for (int p = 2 ; p <= 13; p++) {
//     if (p != 9 & p != 4 & p != 2 & p != 3) { // Skip pin 9 (the servo)
//       pinMode(p, OUTPUT); 
//     }
//   }


//   //GUARDRAIL DEPLOYMENT 

//     Servo_L_Gaurdrail.write(180);
//     delay(10);
//     Servo_L_Gaurdrail.attach(3);

//   Servo_R_Gaurdrail.write(40);
//   delay(10);
//   Servo_R_Gaurdrail.attach(2);

//   byte LG_Angle = 180; 
//   byte RG_Angle = 40;

//   while(LG_Angle != 40 ){ // only one comparison made as both angles will go through same difference
//     LG_Angle--;
//     RG_Angle++; 
//     delay(10); // Longer delay if needed
//     Servo_L_Gaurdrail.write(LG_Angle);
//     Servo_R_Gaurdrail.write(RG_Angle);
// }

//   //ARMSSS


//   // Initialize Servo
//   myServo.write(endAngle);
//   myServo.attach(9);
//   delay(250);
//   myServo2.write(startAngle);
//   myServo2.attach(4);
//   delay(250);

//   // --- Start Sequence ---
  
//   // for (int pos = endAngle; pos <= startAngle; pos++) {
//   //   myServo2.write(pos);
//   //   delay(20);
//   // }

//   Motor3Movement(2, 150);
//   Motor3Movement(3, 0); // Stop
//   delay(250); // S Arm Shoulder Back 

//   Motor4Movement(2, 100);
//   Motor4Movement(3, 0); // Stop
//   delay(250);
//   //S Arm Elbow Back 


//   Motor2Movement(2, 90);
//   Motor2Movement(3, 0); // Stop
//   delay(100); 
//   // L Arm Shoudler back

//   // Sweep up
//   for (int pos = endAngle; pos <= startAngle; pos++) {
//     myServo.write(pos);
//     delay(5);
//   }

//   Motor1Movement(2, 70);
//   Motor1Movement(3, 0); // Stop
//   delay(200);

//   // Sweep down
//   for (int pos = startAngle; pos >= endAngle; pos--) {
//     myServo.write(pos);
//     delay(5);
//   }

//   delay(250);

//   Motor2Movement(1, 500);       // change accordingly
//   Motor2Movement(3, 0); // Stop
//   delay(250);

//   Motor1Movement(1, 40);
//   Motor1Movement(3, 0); // Stop
//   delay(250);

//   // Final sweep
//   for (int pos = endAngle; pos <= startAngle; pos++) {
//     myServo.write(pos);
//     delay(5);
//   }
//   delay(750);

//   Motor2Movement(2, 80);
//   Motor2Movement(3, 0); // Stop
//   delay(250);

//   Motor1Movement(2, 80);
//   Motor1Movement(3, 0); // Stop
//   delay(100);
//    //closing of the small arm
//   for (int pos = startAngle; pos >= endAngle; pos--) {
//     myServo2.write(pos);
//     delay(10);
//   }
//   delay(100);
//   Motor3Movement(1, 1400);
//   Motor3Movement(4, 0); // Stop
//   delay(100);

//   Motor4Movement(1, 500);
//   Motor4Movement(3, 0); // Stop
//   delay(50);

//   Motor3Movement(3,0);
//   delay(100);
  
//   for (int pos = endAngle; pos <= startAngle; pos++) {
//     myServo2.write(pos);
//     delay(10);
//   }
// }

// void loop(){

// }