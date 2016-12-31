#include "Motor.h"

Motor::Motor()
{
}


Motor::Motor(int enablePin, int inputPin1, int inputPin2)
{
   _enablePin = enablePin;
   _inputPin1 = inputPin1;
   _inputPin2 = inputPin2;

   currentState = stopped;

   pinMode(_enablePin, OUTPUT);
   pinMode(_inputPin1, OUTPUT);
   pinMode(_inputPin2, OUTPUT);
}


void Motor::rotateLeft()
{
   if (currentState != turningLeft)
   {
      digitalWrite(_enablePin, HIGH);
      digitalWrite(_inputPin1, LOW);
      digitalWrite(_inputPin2, HIGH);
      currentState = turningLeft;
   }
}


void Motor::rotateRight()
{
   if (currentState != turningRight)
   {
      digitalWrite(_enablePin, HIGH);
      digitalWrite(_inputPin1, HIGH);
      digitalWrite(_inputPin2, LOW);
      currentState = turningRight;
   }
}


void Motor::stop()
{
   digitalWrite(_enablePin, LOW);
   digitalWrite(_inputPin1, LOW);
   digitalWrite(_inputPin2, LOW);
   currentState = stopped;
}
