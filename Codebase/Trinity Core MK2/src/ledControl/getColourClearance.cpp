#include "ledControl/getColourClearance.h"

/*-------------------------------------------------------------------------------------*/

bool getColourClearance(byte fxNumber, byte colour)
{
  switch (colour)
  {
    case 0:
    {
      if(fxNumber == 0 || fxNumber == 1 || fxNumber == 2 || fxNumber == 6) return true;
      return false;
    }
    break;

    case 1:
    {
      if(fxNumber == 0 || fxNumber == 2 || fxNumber == 3 || fxNumber == 4) return true;
      return false;
    }
    break;

    case 2:
    {
      if(fxNumber == 0 || fxNumber == 4 || fxNumber == 5 || fxNumber == 6) return true;
      return false;
    }
    break;
  }
  return false;
}