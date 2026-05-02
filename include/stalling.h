#ifndef stalling_h
#define stalling_h

#include <Arduino.h>

void ShoulderStall(int motorIN1, int motorIN2);

void ElbowStall_UP(int motorIN3, int motorIN4);

void ElbowStall_DOWN(int motorIN3, int motorIN4);

#endif