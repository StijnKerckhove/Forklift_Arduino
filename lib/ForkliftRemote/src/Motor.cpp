#include "Motor.h"

//Default constructor
Motor::Motor()
{
}


Motor::Motor(int enablePin, int inputPin1, int inputPin2)
{
   //Sla de meegegeven pinnummers op in het motorobject
   _enablePin = enablePin;
   _inputPin1 = inputPin1;
   _inputPin2 = inputPin2;

   //Verander de status van de motor naar stopped
   currentState = stopped;

   //Configureer de meegegeven pinnen als OUTPUT pinnen
   pinMode(_enablePin, OUTPUT);
   pinMode(_inputPin1, OUTPUT);
   pinMode(_inputPin2, OUTPUT);
}


//Laat de motor links draaien
void Motor::rotateLeft()
{
   //Laat de motor enkel links draaien als deze nog niet links aan het draaien is
   if (currentState != turningLeft)
   {
      digitalWrite(_enablePin, HIGH);
      digitalWrite(_inputPin1, LOW);
      digitalWrite(_inputPin2, HIGH);
      currentState = turningLeft;
   }
}


//Laat de motor rechts draaien
void Motor::rotateRight()
{
   //Laat de motor enkel rechts draaien als deze nog niet rechts aan het draaien is
   if (currentState != turningRight)
   {
      digitalWrite(_enablePin, HIGH);
      digitalWrite(_inputPin1, HIGH);
      digitalWrite(_inputPin2, LOW);
      currentState = turningRight;
   }
}


//Laat de motor stoppen met draaien
void Motor::stop()
{
   digitalWrite(_enablePin, LOW);
   digitalWrite(_inputPin1, LOW);
   digitalWrite(_inputPin2, LOW);
   currentState = stopped;
}
