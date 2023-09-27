#include "Diode.h"

Diode::Diode(uint8_t number)
{
  this->number = number;

  this->brightness  = 255;
  this->effect      = new uint8_t();
  this->colour      = new uint8_t();
  *this->effect      = EFFECT_CUSTOM_STATIC;
  *this->colour      = COLOUR_CYCLE;
  this->offset      = 0;
  this->speed       = 1;

  for (uint8_t i = 0; i < AMOUNTOFCOLOURS; i++)
  {
    this->customRGB[i] = new struct ColourRGB;
    this->customRGB[i]->r = 255;
    this->customRGB[i]->g = 63;
    this->customRGB[i]->b = 127;
    //These are some preset empty colours for the custom RGB values.
  }

  this->rgb.r           = 0;
  this->rgb.g           = 0;
  this->rgb.b           = 0;
  this->d               = 0;
  this->c               = 0;
  this->fxProgression   = 0;          //In effect cycling
  this->offsetTimer     = 0;

}


void Diode::tick()
{
  //printDebug();
  
  if (offsetTimer < offset)
  {
    offsetTimer++;
  }
  else
  {
    for (byte i = 0; i < speed; i++)
    {
      if (*colour != COLOUR_CYCLE)
      {
        c = *colour;
      }
      

      bool effectFinished = false;
      switch (*effect)
      {
        case EFFECT_STOCK_STATIC:
        effectFinished = effectApplications.stock_static(&rgb, &d, &fxProgression, c);
        break;

        case EFFECT_STOCK_BLINK:
        effectFinished = effectApplications.stock_blink(&rgb, &d, &fxProgression, c);
        break;

        case EFFECT_STOCK_PLANE:
        effectFinished = effectApplications.stock_plane(&rgb, &d, &fxProgression, c);
        break;

        case EFFECT_STOCK_BREATHING:
        effectFinished = effectApplications.stock_breathing(&rgb, &d, &fxProgression, c);
        break;

        case EFFECT_STOCK_PAUSEDBREATHING:
        effectFinished = effectApplications.stock_pausedbreathing(&rgb, &d, &fxProgression, c);
        break;

        case EFFECT_STOCK_FLASH:
        effectFinished = effectApplications.stock_flash(&rgb, &d, &fxProgression, c);
        break;

        case EFFECT_STOCK_PAUSEDFLASH:
        effectFinished = effectApplications.stock_pausedFlash(&rgb, &d, &fxProgression, c);
        break;

        case EFFECT_STOCK_HEARTBEAT:
        effectFinished = effectApplications.stock_heartbeat(&rgb, &d, &fxProgression, c);
        break;

        case EFFECT_STOCK_APPEAR:
        effectFinished = effectApplications.stock_appear(&rgb, &d, &fxProgression, c);
        break;

        case EFFECT_SPECIAL_RAINBOW:
        effectFinished = effectApplications.special_rainbow(&rgb, &d, &fxProgression);
        break;

        case EFFECT_SPECIAL_FIRE:
        //effectFinished = special_fire();
        break;

        case EFFECT_SPECIAL_SOUND:
        //effectFinished = progressFX_sound();
        break;
      }

      if(*colour == COLOUR_CYCLE && effectFinished)
      {
        c++;
        if(c == AMOUNTOFCOLOURS) c = (COLOUR_BLACK + 1);
      }
    }
  }
}
void Diode::setDataFx(uint8_t brightness, uint8_t effect, uint8_t colour, uint16_t offset, uint8_t speed, bool repeat)
{
  //Serial.println("Setting diode data (In Diode)");
  this->brightness  = brightness;
  *this->effect      = effect;
  *this->colour      = colour;
  this->offset      = offset;
  this->speed       = speed;
  this->repeat      = repeat;

  d = 0;
  c = 0;
  fxProgression = 0;
  offsetTimer = 0;
}
void Diode::setDataCustom(uint8_t customRGBAmount, ColourRGB *customRGB[AMOUNTOFCOLOURS])
{
  this->customRGBAmount = customRGBAmount;
  for (uint8_t i = 0; i < AMOUNTOFCOLOURS; i++)
  {
    this->customRGB[i]->r = customRGB[i]->r;
  }
}
CRGB Diode::getRGB(uint8_t sysBrightness)
{
  uint8_t r = (((this->rgb.r * this->brightness) / 255) * sysBrightness) / 255;
  uint8_t g = (((this->rgb.g * this->brightness) / 255) * sysBrightness) / 255;
  uint8_t b = (((this->rgb.b * this->brightness) / 255) * sysBrightness) / 255;
  return CRGB(r, g, b);
}
void Diode::printDebug()
{
  Serial.print(F("Diode "));
  Serial.println(number);

  Serial.print(F("brightness "));
  Serial.print(brightness);
  Serial.print(F(" | effect "));
  Serial.print(*effect);
  Serial.print(F(" | colour "));
  Serial.print(*colour);
  Serial.print(F(" | offset "));
  Serial.print(offset);
  Serial.print(F(" | speed "));
  Serial.print(speed);

  Serial.print(F(" === r "));
  Serial.print(rgb.r);
  Serial.print(F(" | g "));
  Serial.print(rgb.g);
  Serial.print(F(" | b "));
  Serial.print(rgb.b);
  Serial.print(F(" | d "));
  Serial.print(d);
  Serial.print(F(" | c "));
  Serial.print(c);
  Serial.print(F(" | fxProgression "));
  Serial.print(fxProgression);
  Serial.print(F(" | offsetTimer "));
  Serial.println(offsetTimer);
}

String Diode::convertToTransmission()
{
  String data = "";
  
  data += number;

  data += brightness;
  data += *effect;
  data += *colour;
  data += offset;
  data += speed;
  data += repeat;

  data += rgb.r;
  data += rgb.g;
  data += rgb.b;

  return data;
}