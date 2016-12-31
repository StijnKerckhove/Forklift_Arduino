#ifndef FORKLIFTCONTROLLER_H
#define FORKLIFTCONTROLLER_H

#include "Arduino.h"
#include "Motor.h"

class ForkliftController {
public:
   ForkliftController();
   void initializeLiftMotor(int enablePin, int inputPin1, int inputPin2);
   void initializeSteeringMotor(int enablePin, int inputPin1, int inputPin2);
   void initializeMastTiltMotor(int enablePin, int inputPin1, int inputPin2);
   void initializeDriveMotor(int enablePin, int inputPin1, int inputPin2);
   void processCommand(String command);

private:
   Motor _steeringMotor;
   Motor _liftMotor;
   Motor _driveMotor;
   Motor _mastTiltMotor;
};

#endif
