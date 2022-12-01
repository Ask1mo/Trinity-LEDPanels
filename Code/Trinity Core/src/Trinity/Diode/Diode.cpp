#include "Trinity/Diode/Diode.h"

Diode::Diode(uint8_t number)
{
  this->number = number;
}



void Diode::tick()
{
  if (offsetTimer < offset)
  {
    offsetTimer++;
  }
  else
  {
    switch (effect)
    {
    case EFFECT_RAINBOW:
      // FX_rainbow();
      break;

    case EFFECT_SYNTHBOW:
      // FX_rainbow();
      break;

    case EFFECT_FIRE:
      // FX_fire();
      break;

    case EFFECT_STATIC:
      // FX_static();

    case EFFECT_BLINK:
      // FX_blink();
      break;

    case EFFECT_BREATHING:
      // FX_breathing();
      break;

    case EFFECT_PAUSEDBREATHING:
      // FX_breathing();
      break;

    case EFFECT_FLASH:
      // FX_flash();
      break;

    case EFFECT_HEARTBEAT:
      // FX_flash();
      break;
    }
  }
}


CRGB Diode::getRGB()
{
  uint8_t redValue    = (this->r * this->brightness)/255;
  uint8_t greenValue  = (this->g * this->brightness)/255;
  uint8_t blueValue   = (this->b * this->brightness)/255;
  return CRGB(redValue, greenValue, blueValue);
}
