#ifndef DIODE_H
#define DIODE_H

#include <Arduino.h>
#include <FastLED.h>
#include <list>

#define AMOUNTOFCOLOURS 7
#define COLOUR_BLACK             0
#define COLOUR_RED               1
#define COLOUR_YELLOW            2
#define COLOUR_GREEN             3
#define COLOUR_TEAL              4
#define COLOUR_BLUE              5
#define COLOUR_VIOLET            6
#define COLOUR_WHITE             7

#define EFFECT_RAINBOW           0
#define EFFECT_SYNTHBOW          1
#define EFFECT_FIRE              2
#define EFFECT_STATIC            3
#define EFFECT_BLINK             4
#define EFFECT_BREATHING         5
#define EFFECT_PAUSEDBREATHING   6
#define EFFECT_FLASH             7
#define EFFECT_HEARTBEAT         8

class Diode
{
private:
  uint8_t number;

  uint8_t brightness;
  uint8_t effect;
  uint8_t colour;
  uint8_t offset;
  uint8_t speed;
  uint8_t rCustom;
  uint8_t gCustom;
  uint8_t bCustom;

  uint8_t r;
  uint8_t g;
  uint8_t b;
  uint8_t d;
  uint8_t fxProgression;      //In effect cycling
  uint8_t fXCycleProgression; //Cycles of the whole effect (But with different colourss)
  uint16_t offsetTimer;
  bool getColourClearance(byte colourToClear);

public:
  Diode(uint8_t number);
  CRGB getRGB();
  void tick();
};

#endif