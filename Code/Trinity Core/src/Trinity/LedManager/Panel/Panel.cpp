#include "Panel.h"

Panel::Panel(uint8_t number, uint8_t compassDir, bool clockDir, uint8_t diodeAmount)
{

  diodes = (Diode**)malloc(sizeof(Diode*) * diodeAmount);
  for (uint8_t i = 0; i < diodeAmount; i++)
  {
    diodes[i] = new Diode(i);
  }

  this->number        = number;
  this->compassDir    = compassDir;
  this->clockDir      = clockDir;
  this->diodeAmount   = diodeAmount;
  this->diodeStart    = 0;  // The coordinate of the first LED

  this->brightness   = 255;
  this->effect       = 0;
  this->colour       = 0;
  this->offset       = 10;
  this->speed        = 1;
  this->rCustom      = 255;
  this->gCustom      = 255;
  this->bCustom      = 255;
  
  this->r                   = 0;
  this->g                   = 0;
  this->b                   = 0;
  this->d                   = 0;
  this->fxProgression       = 0;      // In effect cycling
  this->fxCycleProgression  = 0; // Cycles of the whole effect (But with different colourss)
  this->offsetTimer         = 0;
}

void Panel::tick()
{
  //printDebug();


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
    return CRGB(0);
  }

  return diodes[number]->getRGB();
}
byte Panel::getDiodeAmount()
{
  return diodeAmount;
}
byte Panel::getDiodeStart()
{
  return diodeStart;
}
void Panel::setDiodeStart(byte ledStart)
{
  this->diodeStart = ledStart;
}
void Panel::printDebug()
{
  Serial.println();
  Serial.print(F("Panel "));
  Serial.println(number);

  Serial.print(F("compassDir "));
  Serial.print(compassDir);
  Serial.print(F(" | clockDir "));
  Serial.print(clockDir);
  Serial.print(F(" | diodeAmount "));
  Serial.print(diodeAmount);
  Serial.print(F(" | diodeStart "));
  Serial.println(diodeStart);

  Serial.print(F("brightness "));
  Serial.print(brightness);
  Serial.print(F(" | effect "));
  Serial.print(effect);
  Serial.print(F(" | colour "));
  Serial.print(colour);
  Serial.print(F(" | offset "));
  Serial.print(offset);
  Serial.print(F(" | speed "));
  Serial.print(speed);
  Serial.print(F(" | rCustom "));
  Serial.print(rCustom);
  Serial.print(F(" | gCustom "));
  Serial.print(gCustom);
  Serial.print(F(" | bCustom "));
  Serial.println(bCustom);

  Serial.print(F("r "));
  Serial.print(r);
  Serial.print(F(" | g "));
  Serial.print(g);
  Serial.print(F(" | b "));
  Serial.print(b);
  Serial.print(F(" | d "));
  Serial.print(d);
  Serial.print(F(" | fxProgression "));
  Serial.print(fxProgression);
  Serial.print(F(" | fxCycleProgression "));
  Serial.print(fxCycleProgression);
  Serial.print(F(" | offsetTimer "));
  Serial.println(offsetTimer);
  
}