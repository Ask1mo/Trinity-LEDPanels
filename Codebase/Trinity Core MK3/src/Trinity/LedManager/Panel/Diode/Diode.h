#ifndef DIODE_H
#define DIODE_H

#include <Arduino.h>
#include <FastLED.h>
#include "Trinity/ledManager/effectProcessor/effectProcessor.h"
#include "Trinity/DataTypes.h"
#include "setup.h"












class Diode
{
private:
  uint16_t                                  number;

  uint8_t                                   brightness;
  uint8_t                                   *effect;
  uint8_t                                   *colour;
  uint16_t                                  offset;
  uint8_t                                   speed;
  bool                                      repeat;
  
  uint8_t                                   customRGBAmount;
  ColourRGB                                 *customRGB[AMOUNTOFCOLOURS];
  

  ColourRGB                                 rgb;
  uint8_t                                   d; //Dummy
  uint8_t                                   c; //Current colour (Can cycle because of COLOUR_COLOURCYCLE)
  uint8_t                                   fxProgression; //Current part of the effect
  uint16_t                                  offsetTimer;

public:
  Diode                                     (uint16_t number);
  //Standard
  void      tick                            ();
  //Effects
  void      setBrightness                   (uint8_t brightness);
  void      setVfx                          (VFXData vfxData);
  void      setDataCustom                   (uint8_t customRGBAmount, ColourRGB *customRGB[AMOUNTOFCOLOURS]);
  //Technical
  CRGB      getRGB                          (uint8_t sysBrightness);
  //Transmisisons
  String    convertToTransmission           ();
  //Debug
  void      printDebug                      ();
};

#endif