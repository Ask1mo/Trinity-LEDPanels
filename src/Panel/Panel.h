#ifndef PANEL_H
#define PANEL_H

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
  //Detailed
  bool                                      detailed = false;
  bool                                      allowDetailed = false;
  Diode                                     **diodes;

  //Orientation
  uint8_t                                   number      = 0;
  uint8_t                                   x           = 0;
  uint8_t                                   y           = 0;
  uint8_t                                   compassDir  = 0;
  bool                                      clockDir    = 0;

  uint16_t                                  diodeAmount = 0; // Amount of leds in this panel
  uint16_t                                  diodeStart  = 0;  // The coordinate of the first LED
  
  uint8_t                                   brightness      = 0;
  uint8_t                                   goalBrightness  = 255;
  uint8_t                                   effect          = EFFECT_DEV_UNBOUND; 
  uint8_t                                   colour  	      = COLOUR_BLACK;
  uint16_t                                  offset          = 0;
  uint8_t                                   speed           = 1;
  bool                                      repeat          = true;

  CustomPalette                             *customPalette;
  EffectVariables                           effectVariables;
  uint16_t                                  offsetTimer     = 0;

public:
  Panel                                     (uint8_t number, uint8_t x, uint8_t y, uint8_t compassDir, bool clockDir, uint16_t diodeAmount, bool allowDetailed);
  //Standard
  void      tick                            ();
  //Effects
  void      setBrightness                   (uint8_t brightness, bool smooth);
  void      setVfx                          (VFXData vfxData);
  void      setDataCustom                   (CustomPalette *customPaletteArg);
  //Diode Effects
  void      setDiodeBrightness              (uint16_t diodeNumber, uint8_t brightness, bool smooth);
  void      setDiodeVfx                     (uint16_t diodeNumber, VFXData vfxData);
  void      setDiodeDataCustom              (uint16_t diodeNumber, CustomPalette *customPalette);
  //Mask Effects
  void      setMaskPercentage               (uint8_t percentage);
  //Technical
  uint8_t   getNumber                       ();
  uint8_t   getX                            ();
  uint8_t   getY                            ();
  CRGB      getDiodeRGB                     (uint16_t diodeNumber, uint8_t brightness);
  uint16_t  getDiodeAmount                  ();
  uint16_t  getDiodeStart                   ();
  void      setDiodeStart                   (uint16_t ledStart);
  void      resetFXProcessingVars           ();
  //Transmissions
  String    convertToTransmission           ();
  String    convertDiodeToTransmission  	  (uint16_t diodeNumber);
  String    converToJson                    ();
  //Debug
  void      printDebug                      ();
};

#endif