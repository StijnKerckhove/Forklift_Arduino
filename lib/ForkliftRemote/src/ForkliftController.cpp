#include "ForkliftController.h"


//Default constructor
ForkliftController::ForkliftController()
{
}


//Configureer de motor die de heftruck laat heffen en zakken
void ForkliftController::initializeLiftMotor(int enablePin, int inputPin1, int inputPin2)
{
   //Maak een nieuw Motor object aan met de correcte pinnummers
   _liftMotor = Motor(enablePin, inputPin1, inputPin2);
}


//Configureer de motor die de heftruck links of rechts laat sturen
void ForkliftController::initializeSteeringMotor(int enablePin, int inputPin1, int inputPin2)
{
  //Maak een nieuw Motor object aan met de correcte pinnummers
   _steeringMotor = Motor(enablePin, inputPin1, inputPin2);
}

//Configureer de motor die de heftruck vooruit en achteruit laat rijden
void ForkliftController::initializeDriveMotor(int enablePin, int inputPin1, int inputPin2)
{
  //Maak een nieuw Motor object aan met de correcte pinnummers
   _driveMotor = Motor(enablePin, inputPin1, inputPin2);
}

//Configureer de motor die de mast van de heftruck vooruit of achteruit laat bewegen
void ForkliftController::initializeMastTiltMotor(int enablePin, int inputPin1, int inputPin2)
{
  //Maak een nieuw Motor object aan met de correcte pinnummers
   _mastTiltMotor = Motor(enablePin, inputPin1, inputPin2);
}

//Verwerk het ontvangen commando
void ForkliftController::processCommand(String command)
{
   if (command.equals("steerstop"))
   {
      _steeringMotor.stop();
   }
   else if (command.equals("steerleft"))
   {
      _steeringMotor.rotateRight();
   }
   else if (command.equals("steerright"))
   {
      _steeringMotor.rotateLeft();
   }
   if (command.equals("tiltstop"))
   {
      _mastTiltMotor.stop();
   }
   else if (command.equals("tiltforward"))
   {
      _mastTiltMotor.rotateRight();
   }
   else if (command.equals("tiltbackward"))
   {
      _mastTiltMotor.rotateLeft();
   }
   else if (command.equals("drivestop"))
   {
      _driveMotor.stop();
   }
   else if (command.equals("driveforward"))
   {
      _driveMotor.rotateLeft();
   }
   else if (command.equals("drivebackward"))
   {
      _driveMotor.rotateRight();
   }
   else if (command.equals("liftstop"))
   {
      _liftMotor.stop();
   }
   else if (command.equals("liftup"))
   {
      _liftMotor.rotateLeft();
   }
   else if (command.equals("liftdown"))
   {
      _liftMotor.rotateRight();
   }
}
