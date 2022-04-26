#include "Trinity.h"




Trinity::Trinity()
{
  dummy = 73;
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
}

void Trinity::Tick()
{
  FastLED.show();
}
