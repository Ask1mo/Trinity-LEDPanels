#include "Trinity.h"

#define LED_PIN 12
#define LEDAMOUNT 200




Trinity::Trinity(Vector<Panel*> &panels)
{
  brightness = 100;
  speed = 1;

  uint8_t ledAmount = 0;
  for (uint8_t i = 0; i < sizeof(panels); i++)
  {
    panels[i]->setDiodeStart(ledAmount);
    ledAmount += panels[i]->getDiodeAmount();
  }
  if (ledAmount != LEDAMOUNT)
  {
    Serial.println(F("LED amount in the system is incorrect"));
  }
  leds = new CRGB[ledAmount];
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, ledAmount);
}


Panel* Trinity::getPanel(uint8_t x, uint8_t y)
{
  for(uint8_t i = 0; i < sizeof(panels); i++)
  {
    if(panels[i]->getX() == x && panels[i]->getY() == y)
    {
      return panels[i];
    }
  }
  return NULL;
}

void Trinity::tick()
{
  for (uint8_t panelNumber = 0; panelNumber < sizeof(panels); panelNumber++)
  {
    panels[panelNumber]->tick();
    for(byte diodeNumber = 0; diodeNumber < panels[panelNumber]->getDiodeAmount(); diodeNumber++)
    {
      leds[panels[panelNumber]->getDiodeStart()+diodeNumber] = panels[panelNumber]->getPanelRGB();
      //leds[panels[panelNumber]->getDiodeStart()+diodeNumber] = panels[panelNumber]->getDiodeRGB(diodeNumber);
    }
  }
  FastLED.show();
}

