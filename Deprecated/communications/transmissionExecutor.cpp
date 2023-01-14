#include "communications/transmissionExecutor.h"

void leafTransmissionExecutor(byte transmissionData[])
{
  if (transmissionData[1] < LEAVES && transmissionData[1] >= 0)
  {
    Leaf *leaf = getLeaf(transmissionData[1]);

    leaf->fxOffset = transmissionData[3];
    leaf->fxSpeed = transmissionData[4];

    /*
    leaf->fxType = transmissionData[5];
    leaf->fxNumber = transmissionData[6];
    */

    byte fxTypee = transmissionData[5];
    fxTypee = fxTypee >> 4;
    fxTypee = fxTypee & 0x0F;
    leaf->fxType = fxTypee;

    leaf->fxNumber = transmissionData[5];
    leaf->fxNumber = leaf->fxNumber & 0x0F;

    leaf->customRedValue = transmissionData[7]*2;
    leaf->customGreenValue = transmissionData[8]*2;
    leaf->customBlueValue = transmissionData[9]*2;
 
    resetAndUpdateLEDs();
  }
}

void globalsTransmissionExecutor(byte transmissionData[])
{
  Globals* globals = getGlobals();
  globals->brightness = transmissionData[1]*2;
  globals->leafDelay = transmissionData[3];
}

void requestTransmissionExecutor()
{
  for (byte i = 0; i < LEAVES; i++)
  {
    Leaf *leaf = getLeaf(i);
    serialSend_Leaf(leaf);
  }
}