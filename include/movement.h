#ifndef MOVEMENT_H
#define MOVEMENT_H 

#include <Arduino.h>
#include <Servo.h>

extern Servo myServo;
#include <stalling.h>

void ShoulderForward(int motor_runtime, int power);
void ShoulderBackward(int motor_runtime, int power);
void ElbowForward(int motor_runtime, int power);
void ElbowBackward(int motor_runtime, int power);
void HandClose();
void HandOpen();
void Motor1Movement(int direction, int duration);
void Motor2Movement(int direction, int duration);
void Motor3Movement(int direction, int duration);
void Motor4Movement(int direction, int duration);


#endif