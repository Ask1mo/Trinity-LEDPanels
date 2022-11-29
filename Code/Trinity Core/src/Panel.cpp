#include "Panel.h"

Panel::Panel(uint8_t number, uint8_t x, uint8_t y, uint8_t compassDir, bool clockDir, uint8_t diodeAmount)
{
  this->number = number;
  this->x = x;
  this->y = y;
  this->compassDir = compassDir;
  this->clockDir = clockDir;
  this->diodeAmount = diodeAmount;

  //TODO: GET THE XYZ COORDIATES RIGHT
  for (uint8_t i = 0; i < diodeAmount; i++)
  {
    diodes.push_back(new Diode(i, 0, 0));
  }
}

void Panel::tick()
{
  if (offsetTimer < offset)
  {
    offsetTimer++;
  }
  else
  {
    for (uint8_t i = 0; i < diodeAmount; i++)
    {
      diodes[i]->tick();
    }
  }
}



CRGB Panel::getPanelRGB()
{
  uint8_t redValue    = (this->r * this->brightness)/255;
  uint8_t greenValue  = (this->g * this->brightness)/255;
  uint8_t blueValue   = (this->b * this->brightness)/255;
  
  return CRGB(redValue, greenValue, blueValue);
}
CRGB Panel::getDiodeRGB(byte number)
{
  if(number >= diodeAmount)
  {
    Serial.println(F("Too high diode number requested"));
    return;
  }

  return diodes[number]->getRGB();
}
byte Panel::getDiodeStart()
{
  return diodeStart;
}
void Panel::setDiodeStart(byte ledStart)
{
  this->diodeStart = ledStart;
}
byte Panel::getDiodeAmount()
{
  return diodeAmount;
}
byte Panel::getX()
{
  return x;
}
byte Panel::getY()
{
  return y;
}
