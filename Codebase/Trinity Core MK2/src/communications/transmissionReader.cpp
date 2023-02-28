#include "communications/transmissionReader.h"

/*-------------------------------------------------------------------------------------*/
byte transmissionData[MAXTRANSMISSIONLENGTH];
/*-------------------------------------------------------------------------------------*/


void transmissionReader()
{
  while(Serial.available())
  {
    for(byte i = 0; i<MAXTRANSMISSIONLENGTH-1; i++)
    {
      transmissionData[i] = transmissionData[i+1];
    }
    transmissionData[MAXTRANSMISSIONLENGTH-1] = Serial.read();
    transmissionMatcher(transmissionData);
  }
}