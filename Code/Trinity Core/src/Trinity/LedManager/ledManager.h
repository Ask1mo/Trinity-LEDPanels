#ifndef LEDMANAGER_H
#define LEDMANAGER_H

#include "Panel/Panel.h"

#define PIN_LEDS      12
#define LEDAMOUNT 300


class LedManager
{
private:
  Panel     **panels;
  
  uint8_t   panelsAmount;
  CRGB      leds[LEDAMOUNT];
  bool      brightness;
  bool      speed;

public:
  LedManager(Panel **panelsArg, uint8_t panelsAmount);
  void tick();
};



#endif