#include "ledControl/resetAndUpdateLEDs.h"

/*-------------------------------------------------------------------------------------*/

void resetAndUpdateLEDs()
{
  for (byte i = 0; i<LEAVES; i++)
  {
    Leaf* leaf = getLeaf(i);
    
    leaf->redValue = 0;
    leaf->greenValue = 0;
    leaf->blueValue = 0;
    leaf->dummyValue = 0;
    
    leaf->fxProgression = 0;
    leaf->cycleProgression = 0;

    leaf->timer = 0;
  }
}