#include "communications/transmissionMatcher.h"

/*-------------------------------------------------------------------------------------*/
byte requestTransmissionOffset = MAXTRANSMISSIONLENGTH-REQUESTTRANSMISSIONLENGTH;
byte globalsTransmissionOffset = MAXTRANSMISSIONLENGTH-GLOBALSTRANSMISSIONLENGTH;
/*-------------------------------------------------------------------------------------*/

void transmissionMatcher(byte transmissionData[])
{
  if(// /0/0000/000/
  transmissionData[0] == '/' &&
  transmissionData[2] == '/' &&
  transmissionData[6] == '/' &&
  transmissionData[10] == '/')
  {
    leafTransmissionExecutor(transmissionData);
  }

  if(// #0#0#
  transmissionData[0+globalsTransmissionOffset] == '#' &&
  transmissionData[2+globalsTransmissionOffset] == '#' &&
  transmissionData[4+globalsTransmissionOffset] == '#')
  {
    for (byte i = 0; i<globalsTransmissionOffset; i++)
    {
      for(byte j = 0; j<MAXTRANSMISSIONLENGTH-1; j++)
      {
        transmissionData[j] = transmissionData[j+1];
      }
      transmissionData[MAXTRANSMISSIONLENGTH-1] = 0;
    }
    globalsTransmissionExecutor(transmissionData);
  }

  if(// Request
  transmissionData[0+requestTransmissionOffset] == 'R' &&
  transmissionData[1+requestTransmissionOffset] == 'e' &&
  transmissionData[2+requestTransmissionOffset] == 'q' &&
  transmissionData[3+requestTransmissionOffset] == 'u' &&
  transmissionData[4+requestTransmissionOffset] == 'e' &&
  transmissionData[5+requestTransmissionOffset] == 's' &&
  transmissionData[6+requestTransmissionOffset] == 't')
  {
    for (byte i = 0; i<requestTransmissionOffset; i++)
    {
      for(byte j = 0; j<MAXTRANSMISSIONLENGTH-1; j++)
      {
        transmissionData[j] = transmissionData[j+1];
      }
      transmissionData[MAXTRANSMISSIONLENGTH-1] = 0;
    }
    requestTransmissionExecutor();
  } 
}