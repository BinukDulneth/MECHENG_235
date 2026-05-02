#include <Arduino.h>
#include <Servo.h> 
#include <movement.h>
// /*
// --------------------------------------------------- POTENTIOMETER CODE ARM ----------------------------------------------------------------
// */


// // void loop(){
  
// //   float DesiredAngle = 20.0; 

// //   float potVal = analogRead(PotPin);
// //   float ReadAngle = floor((potVal/670.0)*90);
// //   Serial.print(potVal);
// //   Serial.print("      ");
// //   Serial.println(ReadAngle);
// //   float Diff; 
// //   int power;
// //   int factor = 40;
// //   while (DesiredAngle != ReadAngle){
// //     if(ReadAngle < DesiredAngle){
// //       Diff = DesiredAngle - ReadAngle; 
// //       power = Diff*factor;
// //       if (Diff*factor > 255){
// //         power = 255 ;
// //       }
// //       analogWrite(motorIN3,power);
// //       analogWrite(motorIN4,0);
// //       delay(5);
// //     } else if(ReadAngle > DesiredAngle){
// //       power = Diff*factor;
// //       Diff = ReadAngle - DesiredAngle;
// //       if (Diff*factor > 255){
// //         power = 255;
// //       } 
// //       analogWrite(motorIN3,0);
// //       analogWrite(motorIN4,power);
// //       delay(5);
// //     }

// //     potVal = analogRead(PotPin);
// //     ReadAngle = floor((potVal/670.0)*90);
// //     Serial.print(potVal);
// //     Serial.print("      ");
// //     Serial.println(ReadAngle);
// //   }


// //   delay(10);
// //   digitalWrite(13,HIGH);
// // }


// /*
// NOTES: 
//   - 20/04/2026 
//       Power to the motors to correct itself is given by multiplying the difference between the desired angle and the angle of the motor but maxed out at 255. 
//       Motor would go past the desired angle and recorrect itself. 
//       Not ideal movement. 

  
// */

// /*



// MATTS CODES

Servo myServo;
Servo myServo2;

Servo myServo3;
Servo myServo4;

// Pin Definitions


int startAngle = 180;
int endAngle = 115;


void setup() {
  // Initialize ALL motor pins as OUTPUT
  for (int p = 2 ; p <= 13; p++) {
    if (p != 9 & p != 4 & p != 2 & p != 3) { // Skip pin 9 (the servo)
      pinMode(p, OUTPUT); 
    }
  }


  //GUARDRAIL DEPLOYMENT 
  delay(3000);
  myServo3.write(180);
  delay(100);
  myServo3.attach(3);
  delay(500);
  myServo4.write(40);
  delay(100);
  myServo4.attach(2);
  delay(500);

  for(int angle = 180; angle >= 30; angle--){
    myServo3.write(angle);
    delay(40);
  }

  for(int angle = 40; angle <=180; angle++){
    myServo4.write(angle);
    delay(40);
  }

  delay(500);

  //ARMSSS


  // Initialize Servo
  myServo.write(endAngle);
  myServo.attach(9);
  delay(1000);
  myServo2.write(startAngle);
  myServo2.attach(4);
  delay(1000);

  // --- Start Sequence ---
  
  // for (int pos = endAngle; pos <= startAngle; pos++) {
  //   myServo2.write(pos);
  //   delay(20);
  // }

  Motor3Movement(2, 150);
  Motor3Movement(3, 0); // Stop
  delay(2000);

  Motor4Movement(2, 100);
  Motor4Movement(3, 0); // Stop
  delay(2000);

  Motor2Movement(2, 90);
  Motor2Movement(3, 0); // Stop
  delay(500);

  // Sweep up
  for (int pos = endAngle; pos <= startAngle; pos++) {
    myServo.write(pos);
    delay(20);
  }

  delay(1000);

  Motor1Movement(2, 70);
  Motor1Movement(3, 0); // Stop
  delay(1000);

  // Sweep down
  for (int pos = startAngle; pos >= endAngle; pos--) {
    myServo.write(pos);
    delay(20);
  }

  delay(1000);

  Motor2Movement(1, 500);       // change accordingly
  Motor2Movement(3, 0); // Stop
  delay(500);

  Motor1Movement(1, 40);
  Motor1Movement(3, 0); // Stop
  delay(1000);

  // Final sweep
  for (int pos = endAngle; pos <= startAngle; pos++) {
    myServo.write(pos);
    delay(20);
  }
  delay(1000);

  Motor2Movement(2, 80);
  Motor2Movement(3, 0); // Stop
  delay(500);

  Motor1Movement(2, 80);
  Motor1Movement(3, 0); // Stop
  delay(1000);

   //closing of the small arm
   for (int pos = startAngle; pos >= endAngle; pos--) {
    myServo2.write(pos);
    delay(20);
  }

  Motor3Movement(1, 500);
  Motor3Movement(3, 0); // Stop
  delay(200);

  Motor4Movement(1, 200);
  Motor4Movement(3, 0); // Stop
  delay(1000);

  
  for (int pos = endAngle; pos <= startAngle; pos++) {
    myServo2.write(pos);
    delay(20);
  }
}



//HELLOOOOOOO