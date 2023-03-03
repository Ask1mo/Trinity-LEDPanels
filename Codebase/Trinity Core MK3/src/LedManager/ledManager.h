#ifndef LEDMANAGER_H
#define LEDMANAGER_H

#include "Panel/Panel.h"
#include "../setup.h"

class LedManager
{
private:
  uint8_t   panelsAmount;
  uint8_t   brightness;
  bool      speed;
  bool      enabled;
  Panel     **panels;
  CRGB      leds[LEDAMOUNT];
  

public:
  LedManager(Panel **panelsArg);
  void tick();
  void print();
  uint8_t getBrightness();
  void setBrightness(uint8_t brightness);
  uint8_t getPanelAmount();
  uint8_t getPanelDiodeAmount(uint8_t panelNumber);
  void setPanelData(uint8_t panelNumber, uint8_t direction, uint8_t brightness, uint8_t effect, uint8_t colour, uint8_t offset, uint8_t speed, bool repeat);
  void setPanelCustomData(uint8_t panelNumber, uint8_t customRGBAmount, ColourRGB *customRGB[AMOUNTOFCOLOURS]);
  void setEnabled(bool enabled);
  String convertToTansmission();
  String convertPanelToTransmission(uint8_t panelNumber);
  String convertPanelDiodeToTransmission(uint8_t panelNumber,uint8_t diodeNumber);
};



#endif