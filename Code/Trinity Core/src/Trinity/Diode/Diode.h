#ifndef DIODE_H
#define DIODE_H

#include <Arduino.h>
#include <FastLED.h>
#include "Trinity/ColourRGB.h"

#define AMOUNTOFCOLOURS 7 //The amount of preset colours in the system, also functions as the amount of slots for custom colours
#define COLOUR_BLACK    0
#define COLOUR_RED      1
#define COLOUR_YELLOW   2
#define COLOUR_GREEN    3
#define COLOUR_CYAN     4
#define COLOUR_BLUE     5
#define COLOUR_VIOLET   6
#define COLOUR_WHITE    7
#define COLOUR_CYCLE    8

#define EFFECT_STATIC                 0
#define EFFECT_BLINK                  1
#define EFFECT_PLANE                  2
#define EFFECT_BREATHING              3
#define EFFECT_PAUSEDBREATHING        4
#define EFFECT_FLASH                  5
#define EFFECT_HEARTBEAT              6
#define EFFECT_CUSTOM_STATIC          7
#define EFFECT_CUSTOM_BLINK           8
#define EFFECT_CUSTOM_PLANE           9
#define EFFECT_CUSTOM_BREATHING       10
#define EFFECT_CUSTOM_PAUSEDBREATHING 11
#define EFFECT_CUSTOM_FLASH           12
#define EFFECT_CUSTOM_HEARTBEAT       13
#define EFFECT_RAINBOW                14
#define EFFECT_FIRE                   15
#define EFFECT_SOUND                  16









class Diode
{
private:
  uint8_t number;

  uint8_t brightness;
  uint8_t effect;
  uint8_t colour;
  uint8_t offset;
  uint8_t speed;
  
  uint8_t customRGBAmount;
  ColourRGB *customRGB[AMOUNTOFCOLOURS];
  bool repeat;

  uint8_t r;
  uint8_t g;
  uint8_t b;
  uint8_t d;
  uint8_t c;
  uint8_t fxProgression;          //In effect cycling
  uint16_t offsetTimer;
  bool getColourClearance(byte colourToClear, byte colourChannel);
  void progressFX_static();
  void progressFX_blink();
  void progressFX_plane();
  void progressFX_breathing();
  void progressFX_pausedbreathing();
  void progressFX_flash();
  void progressFX_heartbeat();
  void progressFX_custom_static();
  void progressFX_rainbow();
  void progressFX_fire();
  void progressFX_sound();
  void progressFX_custom_fade();

public:
  Diode(uint8_t number);
  void tick();
  CRGB getRGB();
  void printDebug();
};

#endif