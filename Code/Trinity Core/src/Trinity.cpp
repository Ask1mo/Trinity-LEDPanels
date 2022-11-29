#include "Trinity.h"

#define LED_PIN 12
#define LEDSAMOUNT 200




Trinity::Trinity(Vector<Panel*> &panels)
{
  uint8_t totalLEDAmount = sizeof(panels)*sizeof(panels[0]->Leds);
  CRGB leds[totalLEDAmount];

  for (uint8_t i = 0; i < sizeof(panels); i++)
  { 
    for (uint8_t j = 0; j < sizeof(panels[i]->Leds); j++)
    {
      
    }
  }
  

  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, totalLEDAmount);
}


Panel* Trinity::GetPanel(uint8_t x, uint8_t y)
{
  for(uint8_t i = 0; i < sizeof(Panels); i++)
  {
    if(Panels[i]->X == x && Panels[i]->Y == y)
    {
      return Panels[i];
    }
  }
  return NULL;
}

void Trinity::Tick()
{
  for (uint8_t i = 0; i < sizeof(Panels); i++)
  {
    Panels[i]->Tick();
  }
  FastLED.show();
}

