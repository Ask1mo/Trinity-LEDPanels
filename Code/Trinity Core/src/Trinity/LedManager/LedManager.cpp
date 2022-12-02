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
  FastLED.show();
}