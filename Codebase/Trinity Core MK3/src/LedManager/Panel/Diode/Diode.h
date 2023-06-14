#ifndef DIODE_H
#define DIODE_H

#include <Arduino.h>
#include <FastLED.h>
#include "ledManager/effectApplications.h"
#include "DataTypes.h"












class Diode
{
private:
  uint8_t                                   number;

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
  EffectApplications                        effectApplications;

public:
  Diode                                     (uint8_t number);
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