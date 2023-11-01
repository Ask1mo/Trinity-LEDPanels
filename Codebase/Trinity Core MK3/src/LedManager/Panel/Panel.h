#ifndef PANEL_H
#define PANEL_H

#include <Arduino.h>
#include "Diode/Diode.h"

#define LEDSAMOUNT_TRIANGLE 17

//These are mostly used for setup, but are also selectable when applying offset stuff.
#define DIR_STRIP           0
#define CLOCK_CLOCKWISE     1
#define CLOCK_COUNTERWISE   2
#define COMPASS_NORTH       3
#define COMPASS_NORTH_EAST  4
#define COMPASS_EAST        5
#define COMPASS_SOUTH_EAST  6
#define COMPASS_SOUTH       7
#define COMPASS_SOUTH_WEST  8
#define COMPASS_WEST        9
#define COMPASS_NORTH_WEST  10

class Panel
{
private:
  Diode **diodes;

  uint8_t number;
  uint8_t compassDir;
  bool    clockDir;
  uint16_t diodeAmount; // Amount of leds in this panel
  uint16_t diodeStart;  // The coordinate of the first LED

  uint8_t brightness;
  uint8_t effect;
  uint8_t colour;
  uint16_t offset;
  uint8_t speed;
  bool repeat;
  bool detailed;

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
  void setBrightness(uint8_t brightness);
  void setDataFx(uint8_t effect, uint8_t colour, uint16_t offset, uint8_t speed, bool repeat, bool detailed);
  void setDataCustom(uint8_t customRGBAmount, ColourRGB *customRGB[AMOUNTOFCOLOURS]);
  void setDiodeDataFx(uint16_t diodeNumber, uint8_t brightness, uint8_t effect, uint8_t colour, uint16_t offset, uint8_t speed, bool repeat);
  void setDiodeDataCustom(uint16_t diodeNumber, uint8_t customRGBAmount, ColourRGB *customRGB[AMOUNTOFCOLOURS]);
  CRGB getPanelRGB();
  CRGB getDiodeRGB(byte number, uint8_t brightness);
  uint8_t getDiodeAmount();
  uint16_t getDiodeStart();
  void setDiodeStart(uint16_t ledStart);
  void printDebug();
  String convertToTransmission();
  String convertDiodeToTransmission(uint16_t diodeNumber);
};


#endif