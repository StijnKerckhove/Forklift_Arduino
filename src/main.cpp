#include "Arduino.h"
#include "ForkliftRemote.h"

//Maak object aan van de bibliotheek
ForkliftRemote remote;

void setup()
{
   Serial1.begin(115200);
   Serial1.setTimeout(10);

   //Configureer de digitale pinnen waarop de motor is aangesloten
   remote.initializeMastTiltMotor(5, 6, 7);
   remote.initializeLiftMotor(8, 9, 10);
   remote.initializeDriveMotor(11, 12, 13);
   remote.initializeSteeringMotor(2, 3, 4);
}


void loop()
{
   while (Serial1.available() > 0)
   {
      //Lees de data uit die door de Bluetooth module werd ontvangen
      String input = Serial1.readString();

      //Indien de lengte uitgelezen datastring groter is dan 1
      if (input.length() > 1)
      {
         //Zendt het ontvangen commando naar de ForkliftController
         remote.processCommand(input);
      }
   }
}
