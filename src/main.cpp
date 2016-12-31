#include "Arduino.h"
#include "ForkliftRemote.h"

ForkliftRemote remote;

void setup()
{
   Serial1.begin(115200);
   Serial1.setTimeout(10);
   remote.initializeMastTiltMotor(5, 6, 7);
   remote.initializeLiftMotor(8, 9, 10);
   remote.initializeDriveMotor(11, 12, 13);
   remote.initializeSteeringMotor(2, 3, 4);
}


void loop()
{
   while (Serial1.available() > 0)
   {
      String input = Serial1.readString();

      if (input.length() > 1)
      {
         remote.processCommand(input);
      }
   }
}
