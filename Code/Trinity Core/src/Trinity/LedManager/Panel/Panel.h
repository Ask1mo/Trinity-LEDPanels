#ifndef PANEL_H
#define PANEL_H

#include <Arduino.h>
#include "Diode/Diode.h"

#define LEDSAMOUNT_TRIANGLE 17

#define CLOCK_CLOCKWISE 0
#define CLOCK_COUNTERWISE 1

#define COMPASS_NORTH 0
#define COMPASS_NORTH_EAST 1
#define COMPASS_EAST 2
#define COMPASS_SOUTH_EAST 3
#define COMPASS_SOUTH 4
#define COMPASS_SOUTH_WEST 5
#define COMPASS_WEST 6
#define COMPASS_NORTH_WEST 7

class Panel
{
private:
  Diode **diodes;

  uint8_t number;
  uint8_t compassDir;
  bool clockDir;
  uint8_t diodeAmount; // Amount of leds in this panel
  uint8_t diodeStart;  // The coordinate of the first LED

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
  uint8_t fxProgression;      // In effect cycling
  uint8_t fxCycleProgression; // Cycles of the whole effect (But with different colourss)
  uint16_t offsetTimer;

public:
  Panel(uint8_t number, uint8_t compassDir, bool clockDir, uint8_t diodeAmount);
  void tick();
  CRGB getPanelRGB();
  CRGB getDiodeRGB(byte number);
  byte getDiodeAmount();
  byte getDiodeStart();
  void setDiodeStart(uint8_t ledStart);
  void printDebug();
};


#endif