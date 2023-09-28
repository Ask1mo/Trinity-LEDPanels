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
  Diode                                     **diodes;

  uint8_t                                   number;

  uint8_t                                   x;
  uint8_t                                   y;
  uint8_t                                   compassDir;
  bool                                      clockDir;

  uint16_t                                  diodeAmount; // Amount of leds in this panel
  uint16_t                                  diodeStart;  // The coordinate of the first LED
  uint8_t                                   brightness;

  uint8_t                                   effect;
  uint8_t                                   colour;
  uint16_t                                  offset;
  uint8_t                                   speed;
  bool                                      repeat;
  
  bool                                      detailed;
  uint8_t                                   rCustom;
  uint8_t                                   gCustom;
  uint8_t                                   bCustom;
  uint8_t                                   r;
  uint8_t                                   g;
  uint8_t                                   b;
  uint8_t                                   d;
  uint8_t                                   fxProgression;      // In effect cycling
  uint8_t                                   fxCycleProgression; // Cycles of the whole effect (But with different colourss)
  uint16_t                                  offsetTimer;

public:
  Panel                                     (uint8_t number, uint8_t x, uint8_t y, uint8_t compassDir, bool clockDir, uint16_t diodeAmount);
  //Standard
  void      tick                            ();
  //Effects
  void      setBrightness                   (uint8_t brightness);
  void      setVfx                          (VFXData vfxData);
  void      setDataCustom                   (uint8_t customRGBAmount, ColourRGB *customRGB[AMOUNTOFCOLOURS]);
  //Diode Effects
  void      setDiodeBrightness              (uint16_t diodeNumber, uint8_t brightness);
  void      setDiodeVfx                     (uint16_t diodeNumber, VFXData vfxData);
  void      setDiodeDataCustom              (uint16_t diodeNumber, uint8_t customRGBAmount, ColourRGB *customRGB[AMOUNTOFCOLOURS]);
  //Mask Effects
  void      setMaskPercentage               (uint8_t percentage);
  //Technical
  uint8_t   getPanelNumber                  ();
  uint8_t   getX                            ();
  uint8_t   getY                            ();
  CRGB      getDiodeRGB                     (uint8_t number, uint8_t brightness);
  uint16_t  getDiodeAmount                  ();
  uint16_t  getDiodeStart                   ();
  void      setDiodeStart                   (uint16_t ledStart);
  //Transmissions
  String    convertToTransmission           ();
  String    convertDiodeToTransmission  	  (uint16_t diodeNumber);
  //Debug
  void      printDebug                      ();
};

#endif