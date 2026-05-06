#include <Servo.h>
#include "movement.h"

// Pins
const int motorIN1 = 5;  
const int motorIN2 = 6; 
const int motorIN3 = 7; 
const int motorIN4 = 8; 

const int motorIN5 = 10;
const int motorIN6 = 11; 
const int motorIN7 = 12;
const int motorIN8 = 13; 

const int servoPin = 9;
const int ServoPin2 = 4;



const byte IN1 = 5;  
const byte IN2 = 6;
const byte IN3 = 7; 
const byte IN4 = 8;
const byte IN5 = 10; 
const byte IN6 = 11;
const byte IN7 = 12; 
const byte IN8 = 13;



void ShoulderBackward(int motor_runtime, int power) { 
    for(int step = 0; step < 3; step++) {
      digitalWrite(motorIN1, HIGH); // Full power ON
      digitalWrite(motorIN2, LOW);
      delay(motor_runtime);
    }
    // Stop motor after loop
    digitalWrite(motorIN1, LOW); 
    delay(10);
}

void ShoulderForward(int motor_runtime, int power) {
    for(int step = 0; step < 3; step++) {
        digitalWrite(motorIN1, LOW);
        digitalWrite(motorIN2, HIGH); // Full power ON
        delay(motor_runtime);
    }
    // Stop motor after loop
    digitalWrite(motorIN2, LOW);
    delay(10);
}

void ElbowForward(int motor_runtime, int power) {
    for(int step = 0; step < 3; step++) {
      digitalWrite(motorIN3, LOW);
      digitalWrite(motorIN4, HIGH); // Full power ON
      delay(motor_runtime);
    }
    // Stop motor after loop
    digitalWrite(motorIN4, LOW);
    delay(10);
}

void ElbowBackward(int motor_runtime, int power) {
    for(int step = 0; step < 3; step++) {
      digitalWrite(motorIN3, HIGH); // Full power ON
      digitalWrite(motorIN4, LOW);
      delay(motor_runtime);
    }
    // Electronic Brake (Both HIGH)
    digitalWrite(motorIN3, HIGH);
    digitalWrite(motorIN4, HIGH);
    delay(10);
}

// --- Shoulder 2 Functions (Using MotorIN5 & MotorIN6) ---

void Shoulder2Backward(int motor_runtime, int power) { 
    for(int step = 0; step < 3; step++) {
      digitalWrite(motorIN5, HIGH); 
      digitalWrite(motorIN6, LOW);
      delay(motor_runtime);
    }
    digitalWrite(motorIN5, LOW); 
    delay(10);
}



void Shoulder2Forward(int motor_runtime, int power) {
    for(int step = 0; step < 3; step++) {
        digitalWrite(motorIN5, LOW);
        digitalWrite(motorIN6, HIGH); 
        delay(motor_runtime);
    }
    digitalWrite(motorIN6, LOW);
    delay(10);
}

// --- Elbow 2 Functions (Using MotorIN7 & MotorIN8) ---

void Elbow2Forward(int motor_runtime, int power) {
    for(int step = 0; step < 3; step++) {
      digitalWrite(motorIN7, LOW);
      digitalWrite(motorIN8, HIGH); 
      delay(motor_runtime);
    }
    digitalWrite(motorIN8, LOW);
    delay(10);
}

void Elbow2Backward(int motor_runtime, int power) {
    for(int step = 0; step < 3; step++) {
      digitalWrite(motorIN7, HIGH); 
      digitalWrite(motorIN8, LOW);
      delay(motor_runtime);
    }
    // Electronic Brake (Both HIGH)
    digitalWrite(motorIN7, HIGH);
    digitalWrite(motorIN8, HIGH);
    delay(10);
}



void HandOpen() {
  // Moving from 90 up to 180
  for(int angle = 90; angle <= 180; angle++) {
      myServo.write(angle);
      delay(30);
    }
}

void HandClose() {
  // Moving from 180 down to 90
  for(int angle = 180; angle >= 90; angle--) {
      myServo.write(angle);
      delay(30);
    }
}

//FUNCTIONS FOR MATS CODE 




void Motor1Movement(int direction, int duration) {
  if (direction == 1) { 
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
  } 
  else if (direction == 2) { 
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
  } 
  else { 
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
  }
  delay(duration);
}

void Motor2Movement(int direction, int duration) {
  if (direction == 1) { 
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  } 
  else if (direction == 2) { 
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  } 
  else { 
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }
  delay(duration);
}

void Motor3Movement(int direction, int duration) {
  if (direction == 1) { 
    digitalWrite(IN5, LOW);
    digitalWrite(IN6, HIGH);
  } 
  else if (direction == 2) { 
    digitalWrite(IN5, HIGH);
    digitalWrite(IN6, LOW);
  } 
  else if (direction == 4){
    digitalWrite(IN5, HIGH);
    digitalWrite(IN6, HIGH);
  }
  else { 
    digitalWrite(IN5, LOW);
    digitalWrite(IN6, LOW);
  }
  delay(duration);
}

void Motor4Movement(int direction, int duration) {
  if (direction == 1) { 
    digitalWrite(IN7, LOW);
    digitalWrite(IN8, HIGH);
  } 
  else if (direction == 2) { 
    digitalWrite(IN7, HIGH);
    digitalWrite(IN8, LOW);
  } 
  else { 
    digitalWrite(IN7, LOW);
    digitalWrite(IN8, LOW);
  }
  delay(duration);
}
