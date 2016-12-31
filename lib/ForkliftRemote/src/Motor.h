#ifndef MOTOR_H
#define MOTOR_H

#include "Arduino.h"

enum motorState
{
   turningLeft,
   turningRight,
   stopped
};

class Motor {
public:
   Motor();
   Motor(int enablePin, int inputPin1, int inputPin2);
   void rotateLeft();
   void rotateRight();
   void stop();

private:
   int _enablePin, _inputPin1, _inputPin2;
   motorState currentState;
};

#endif
