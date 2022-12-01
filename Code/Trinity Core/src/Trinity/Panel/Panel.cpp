#include "Trinity/Panel/Panel.h"

Panel::Panel(uint8_t number, uint8_t compassDir, bool clockDir, uint8_t diodeAmount)
{
  this->number        = number;
  this->compassDir    = compassDir;
  this->clockDir      = clockDir;
  this->diodeAmount   = diodeAmount;

  //TODO: GET THE XYZ COORDIATES RIGHT
  for (uint8_t i = 0; i < diodeAmount; i++)
  {
    //diodes.push_back(new Diode(i));
  }
}

void Panel::tick()
{
  printDebug();


  if (offsetTimer < offset)
  {
    offsetTimer++;
  }
  else
  {
    for (uint8_t i = 0; i < diodeAmount; i++)
    {
      //diodes[i]->tick();
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

  //return diodes[number]->getRGB();
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

void Panel::printDebug()
{
  Serial.print(F("Panel "));
  Serial.println(number);

  Serial.print(F("compassDir "));
  Serial.print(compassDir);
  Serial.print(F("| clockDir "));
  Serial.print(clockDir);
  Serial.print(F("| diodeAmount "));
  Serial.print(diodeAmount);
  Serial.print(F("| diodeStart "));
  Serial.println(diodeStart);

  Serial.print(F("brightness "));
  Serial.print(brightness);
  Serial.print(F("| effect "));
  Serial.print(effect);
  Serial.print(F("| colour "));
  Serial.print(colour);
  Serial.print(F("| offset "));
  Serial.print(offset);
  Serial.print(F("| speed "));
  Serial.print(speed);
  Serial.print(F("| rCustom "));
  Serial.print(rCustom);
  Serial.print(F("| gCustom "));
  Serial.print(gCustom);
  Serial.print(F("| bCustom "));
  Serial.println(bCustom);

  Serial.print(F("r "));
  Serial.print(r);
  Serial.print(F("| g "));
  Serial.print(g);
  Serial.print(F("| b "));
  Serial.print(b);
  Serial.print(F("| d "));
  Serial.print(d);
  Serial.print(F("| fxProgression "));
  Serial.print(fxProgression);
  Serial.print(F("| fXCycleProgression "));
  Serial.print(fXCycleProgression);
  Serial.print(F("| offsetTimer "));
  Serial.println(offsetTimer);
}
