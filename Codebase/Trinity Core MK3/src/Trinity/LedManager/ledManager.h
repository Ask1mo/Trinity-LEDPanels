#ifndef LEDMANAGER_H
#define LEDMANAGER_H

#include "Panel/Panel.h"
#include "../src/setup.h"

class LedManager
{
private:
  uint8_t                                 panelsAmount;
  uint8_t                                 brightness;
  bool                                    speed;
  bool                                    enabled;
  Panel                                   **panels;
  CRGB                                    leds[LEDAMOUNT];
  

public:
  LedManager                              (Panel **panelsArg);
  //Standard
  void    tick                            ();
  void    print                           ();
  //Effects
  uint8_t getBrightness                   ();
  void    setBrightness                   (uint8_t brightness);
  void    setSpeed                        (uint8_t speed);
  //Panel Effects
  void    setPanelBrightness              (uint8_t panelNumber, uint8_t brightness);
  void    setPanelVfx                     (uint8_t panelNumber, VFXData vfxData);
  void    setPanelCustomData              (uint8_t panelNumber, uint8_t customRGBAmount, ColourRGB *customRGB[AMOUNTOFCOLOURS]);
  //Diode Effects
  void    setPanelBrightness              (uint8_t panelNumber, uint16_t diodeNumber, uint8_t brightness);
  void    setPanelDiodeVfx                (uint8_t panelNumber, uint16_t diodeNumber, VFXData vfxData);
  void    setPanelCustomData              (uint8_t panelNumber, uint16_t diodeNumber, uint8_t customRGBAmount, ColourRGB *customRGB[AMOUNTOFCOLOURS]);
  //Technical
  void    setEnabled                      (bool enabled);
  uint8_t getPanelAmount                  ();
  uint16_t getPanelDiodeAmount            (uint8_t panelNumber);
  //Transmissions
  String  convertToTansmission            ();
  String  convertPanelToTransmission      (uint8_t panelNumber);
  String  convertPanelDiodeToTransmission (uint8_t panelNumber,uint16_t diodeNumber);

  
};  

#endif