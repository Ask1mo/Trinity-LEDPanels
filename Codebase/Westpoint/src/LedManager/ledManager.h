#ifndef LEDMANAGER_H
#define LEDMANAGER_H

#include "Panel/Panel.h"
#include "../setup.h"

class LedManager
{
private:
  uint8_t   panelsAmount;
  uint8_t   brightness;
  uint8_t      speed;
  bool      enabled;
  Panel     **panels;
  CRGB      leds[LEDAMOUNT];
  uint8_t dronePercentage;
  

public:
  LedManager(Panel **panelsArg);
  void tick();
  void print();
  void setDronePercentage(uint8_t dronePercentage);
  uint8_t getBrightness();
  void setBrightness(uint8_t brightness);
  uint8_t getPanelAmount();
  uint8_t getPanelDiodeAmount(uint8_t panelNumber);
  void setPanelData(uint8_t panelNumber, uint8_t brightness, uint8_t effect, uint8_t colour, uint16_t offset, uint8_t speed, bool repeat, bool detailed);
  void setPanelCustomData(uint8_t panelNumber, uint8_t customRGBAmount, ColourRGB *customRGB[AMOUNTOFCOLOURS]);
  void setPanelDiodeData(uint8_t panelNumber, uint16_t diodeNumber, uint8_t brightness, uint8_t effect, uint8_t colour, uint16_t offset, uint8_t speed, bool repeat);
  void setEnabled(bool enabled);
  String convertToTansmission();
  String convertPanelToTransmission(uint8_t panelNumber);
  String convertPanelDiodeToTransmission(uint8_t panelNumber,uint16_t diodeNumber);
  void setSpeed(uint8_t speed);
};



#endif