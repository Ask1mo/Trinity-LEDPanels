#include "ledControl/printToLEDs.h"

/*-------------------------------------------------------------------------------------*/


CRGB leds[NUM_LEDS];

byte redValue;
byte greenValue;
byte blueValue;
/*-------------------------------------------------------------------------------------*/

void startLeds()
{
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
}

void printToLEDs(Leaf *leaf, byte brightness)
{
  /*
  redValue = (leaf->redValue*brightness)/255;
  greenValue = (leaf->greenValue*brightness)/255;
  blueValue = (leaf->blueValue*brightness)/255;
  */
  redValue = (leaf->redValue);
  greenValue = (leaf->greenValue);
  blueValue = (leaf->blueValue);

  for(byte i = 0; i < LEDSPERLEAF; i++)
  {
    leds[((leaf->leafNumber*LEDSPERLEAF)+i)] = CRGB(redValue, greenValue, blueValue);
  }
}