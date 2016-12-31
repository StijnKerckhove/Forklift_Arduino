#include "ForkliftController.h"

ForkliftController::ForkliftController()
{
}


void ForkliftController::initializeLiftMotor(int enablePin, int inputPin1, int inputPin2)
{
   _liftMotor = Motor(enablePin, inputPin1, inputPin2);
}


void ForkliftController::initializeSteeringMotor(int enablePin, int inputPin1, int inputPin2)
{
   _steeringMotor = Motor(enablePin, inputPin1, inputPin2);
}


void ForkliftController::initializeDriveMotor(int enablePin, int inputPin1, int inputPin2)
{
   _driveMotor = Motor(enablePin, inputPin1, inputPin2);
}


void ForkliftController::initializeMastTiltMotor(int enablePin, int inputPin1, int inputPin2)
{
   _mastTiltMotor = Motor(enablePin, inputPin1, inputPin2);
}


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
