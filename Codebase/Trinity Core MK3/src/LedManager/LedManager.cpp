#include "ledManager.h"

//Constructor
LedManager::LedManager                              (Panel **panelsArg)
{
  Serial.println(F("LedManager Starting..."));

  panelsAmount  = PANELAMOUNT;
  brightness    = 100;
  speed         = 1;
  enabled       = 1;
  panels        = panelsArg;

  int ledAmount = 0;
  for (uint8_t i = 0; i < PANELAMOUNT; i++)
  {
    panels[i]->setDiodeStart(ledAmount);
    ledAmount += panels[i]->getDiodeAmount();
  }

  #ifdef PLATFORM_ARDUINO
  FastLED.addLeds<WS2812, PIN_LEDS, GRB>(leds, LEDAMOUNT);
  #endif
  #ifdef PLATFORM_ESP32FIREBEETLE2
  FastLED.addLeds<WS2812, PIN_LEDS, GRB>(leds, LEDAMOUNT);
  #endif
  #ifdef PLATFORM_ESP32FIREBEETLE2_DEBUG
  FastLED.addLeds<NEOPIXEL, PIN_LEDS>(leds, LEDAMOUNT);
  #endif

  Serial.println(F("...LedManager Started"));
}

//Public
//Standard
void    LedManager::tick                            () 
{
  for (uint8_t i = 0; i < panelsAmount; i++)
  {
    panels[i]->tick();

    for(uint16_t j = 0; j < panels[i]->getDiodeAmount(); j++)
    {
      leds[panels[i]->getDiodeStart()+j] = panels[i]->getDiodeRGB(j, brightness);
    }
  }
} 
void    LedManager::print                           () 
{
  FastLED.show(); 
}
//Effects
uint8_t LedManager::getBrightness                   ()
{
  return brightness;
}
void    LedManager::setBrightness                   (uint8_t brightness)
{
  this->brightness = brightness;
}
//Panel Effects
void    LedManager::setPanelBrightness              (uint8_t panelNumber, uint8_t brightness)
{
  //Serial.println("Setting panel data (In ledmanager)");
  panels[panelNumber]->setBrightness(brightness);
}
void    LedManager::setPanelVfx                     (uint8_t panelNumber, VFXData vfxData)
{
  //Serial.println("Setting panel data (In ledmanager)");
  panels[panelNumber]->setVfx(vfxData);
}
void    LedManager::setPanelCustomData              (uint8_t panelNumber, uint8_t customRGBAmount, ColourRGB *customRGB[AMOUNTOFCOLOURS])
{
  panels[panelNumber]->setDataCustom(customRGBAmount, customRGB);
}
//Diode Effects
void    setPanelBrightness                          (uint8_t panelNumber, uint8_t diodeNumber, uint8_t brightness)
{
  
}
void    LedManager::setPanelDiodeVfx                (uint8_t panelNumber, uint8_t diodeNumber, VFXData vfxData)
{
  //Serial.println("Setting diode data (In ledmanager)");
  panels[panelNumber]->setDiodeVfx(diodeNumber, vfxData);
}
//Technical
void    LedManager::setEnabled                      (bool enabled)
{
  this->enabled = enabled;
}
uint8_t LedManager::getPanelAmount                  ()
{
  return panelsAmount;
}
uint8_t LedManager::getPanelDiodeAmount             (uint8_t panelNumber)
{
  return panels[panelNumber]->getDiodeAmount();
}
//Transmissions
String  LedManager::convertToTansmission            ()
{
  String data = "";
  
  data += (char)brightness;
  data += (char)speed;
  data += (char)enabled;

  return data;
}
String  LedManager::convertPanelToTransmission      (uint8_t panelNumber)
{
  return panels[panelNumber]->convertToTransmission();
}
String  LedManager::convertPanelDiodeToTransmission (uint8_t panelNumber,uint8_t diodeNumber)
{
  return panels[panelNumber]->convertDiodeToTransmission(diodeNumber);
}