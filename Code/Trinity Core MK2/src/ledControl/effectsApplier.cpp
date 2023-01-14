#include "ledControl/effectsApplier.h"

/*-------------------------------------------------------------------------------------*/

void effectsApplier(Leaf *leaf, byte brightness)
{
  if ((leaf->fxOffset*5) > leaf->timer)leaf->timer++;
  else
  {
    switch (leaf->fxType)
    {
      case 0:
      effect_custom(leaf);
      break;

      case 1:
      effect_static(leaf);
      break;

      case 2:
      effect_blink(leaf); //Single
      break;

      case 3:
      effect_blink(leaf); //Double
      break;
    
      case 4:
      effect_breathing(leaf); //Single
      break;
    
      case 5:
      effect_breathing(leaf); //Double
      break;
    
      case 6:
      effect_flash(leaf); //Single
      break;

      case 7:
      effect_flash(leaf); //Double/Heartbeat
      break;

      case 8:
      effect_sound(leaf); //Sound mode
      break;

      case 10:
      effect_breathing(leaf);
      break;

      case 11:
      effect_breathing(leaf);
      break;



      case 15:
      effect_custom(leaf);
      break;
    }
  }
  printToLEDs(leaf, brightness);
}

void effect_custom(Leaf * leaf)
{
  for (byte i = 0; i < leaf->fxSpeed; i++)
  {
    switch (leaf->fxNumber)
    {
      case 0:
      customFx_off(leaf);
      break;

      case 1:
      customFx_rainbow(leaf);
      break;

      case 2:
      customFx_rainbow(leaf);
      break;

      case 3:
      customFx_strobe(leaf);
      break;

      case 4:
      customFx_fire(leaf);
      break;

      case 5:
      customFx_christmas(leaf);
      break;

      case 6:
      customFx_notBound(leaf);
      break;
      
      case 7:
      customFx_notBound(leaf);
      break;

      case 15:
      {
        customFx_customRGB(leaf);
      }
    }
  }
}
