#ifndef LEDMANAGER_H
#define LEDMANAGER_H

#include "Panel/Panel.h"
#include "../PinMapping.h"

#define LEDAMOUNT 102

class LedManager
{
private:
  Panel     **panels;
  
  uint8_t   panelsAmount;
  CRGB      leds[LEDAMOUNT];
  bool      brightness;
  bool      speed;
  bool      enabled;

public:
  LedManager(Panel **panelsArg, uint8_t panelsAmount);
  void tick();
  void print();
  uint8_t getBrightness();
  void setBrightness(uint8_t brightness);
  void setPanelData(uint8_t panelNumber, uint8_t direction, uint8_t brightness, uint8_t effect, uint8_t colour, uint8_t offset, uint8_t speed, bool repeat);
  void setPanelCustomData(uint8_t panelNumber, uint8_t customRGBAmount, ColourRGB *customRGB[AMOUNTOFCOLOURS]);
  void setEnabled(bool enabled);
};



#endif