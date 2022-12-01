#ifndef TRINITY_H
#define TRINITY_H

#include "Trinity/Panel/Panel.h"

#define LEDAMOUNT 300
#define LED_PIN 12


class Trinity
{
private:
  Panel **panels;
  
  uint8_t   panelsAmount;
  CRGB      leds[LEDAMOUNT];
  bool      brightness;
  bool      speed;

public:
  Trinity(Panel **panelsArg, uint8_t panelsAmount, uint8_t pin);
  void tick();
};



#endif