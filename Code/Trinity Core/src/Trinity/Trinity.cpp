#include "Trinity/Trinity.h"

#define NUM_LEDS 244

Trinity::Trinity(Panel **panelsArg, uint8_t panelsAmount, uint8_t pin)
{
  Serial.println(F("Trinity Starting..."));

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

  //leds = new CRGB[LEDAMOUNT];
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, LEDAMOUNT);

  Serial.println(F("Trinity Started"));
  Serial.println(F("---===STARTUP COMPLETED===---"));
  Serial.println();
}

void Trinity::tick()
{
  for (uint8_t panelNumber = 0; panelNumber < panelsAmount; panelNumber++)
  {
    panels[panelNumber]->tick();
    //for(byte diodeNumber = 0; diodeNumber < panels[panelNumber]->getDiodeAmount(); diodeNumber++)
    //{
    //  leds[panels[panelNumber]->getDiodeStart()+diodeNumber] = panels[panelNumber]->getDiodeRGB(diodeNumber);
    //}
  }
  //FastLED.show();
}

