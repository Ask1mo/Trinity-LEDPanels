#include "ledManager.h"

LedManager::LedManager(Panel **panelsArg, uint8_t panelsAmount)
{
  Serial.println(F("LedManager Starting..."));

  brightness  = 100;
  speed       = 1;

  panels        = panelsArg;

  this->panelsAmount  = panelsAmount;

  int ledAmount = 0;
  for (uint8_t i = 0; i < panelsAmount; i++)
  {
    panels[i]->setDiodeStart(ledAmount);
    ledAmount += panels[i]->getDiodeAmount();
  }

  FastLED.addLeds<WS2812, PIN_LEDS, GRB>(leds, LEDAMOUNT);

  Serial.println(F("...LedManager Started"));
}


void LedManager::tick() 
{
  for (uint8_t panelNumber = 0; panelNumber < panelsAmount; panelNumber++)
  {
    panels[panelNumber]->tick();
    for(byte diodeNumber = 0; diodeNumber < panels[panelNumber]->getDiodeAmount(); diodeNumber++)
    {
      leds[panels[panelNumber]->getDiodeStart()+diodeNumber] = panels[panelNumber]->getDiodeRGB(diodeNumber);
    }
  }
}
void LedManager::print() 
{
  FastLED.show();
}
uint8_t LedManager::getBrightness()
{
  return brightness;
}
void LedManager::setBrightness(uint8_t brightness)
{
  this->brightness = brightness;
}
void LedManager::setPanelData(uint8_t panelNumber, uint8_t direction, uint8_t brightness, uint8_t effect, uint8_t colour, uint8_t offset, uint8_t speed, bool repeat)
{
  panels[panelNumber]->setData(direction, brightness, effect, colour, offset, speed, repeat);
}
void LedManager::setPanelCustomData(uint8_t panelNumber, uint8_t customRGBAmount, ColourRGB *customRGB[AMOUNTOFCOLOURS])
{
  panels[panelNumber]->setCustomData(customRGBAmount, customRGB);
}
void LedManager::setEnabled(bool enabled)
{
  this->enabled = enabled;
}