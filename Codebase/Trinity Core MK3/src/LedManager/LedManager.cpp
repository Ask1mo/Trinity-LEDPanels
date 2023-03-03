#include "ledManager.h"

//Constructor
LedManager::LedManager(Panel **panelsArg)
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
void    LedManager::tick() 
{
  for (uint8_t panelNumber = 0; panelNumber < panelsAmount; panelNumber++)
  {
    panels[panelNumber]->tick();
    for(byte diodeNumber = 0; diodeNumber < panels[panelNumber]->getDiodeAmount(); diodeNumber++)
    {
      leds[panels[panelNumber]->getDiodeStart()+diodeNumber] = panels[panelNumber]->getDiodeRGB(diodeNumber, brightness);
    }
  }
}
void    LedManager::print() 
{
  FastLED.show(); 
}
uint8_t LedManager::getBrightness()
{
  return brightness;
}
void    LedManager::setBrightness(uint8_t brightness)
{
  this->brightness = brightness;
}
uint8_t LedManager::getPanelAmount()
{
  return panelsAmount;
}
uint8_t LedManager::getPanelDiodeAmount(uint8_t panelNumber)
{
  return panels[panelNumber]->getDiodeAmount();
}
void    LedManager::setPanelData(uint8_t panelNumber, uint8_t direction, uint8_t brightness, uint8_t effect, uint8_t colour, uint8_t offset, uint8_t speed, bool repeat)
{
  panels[panelNumber]->setDataFx(direction, brightness, effect, colour, offset, speed, repeat);
}
void    LedManager::setPanelCustomData(uint8_t panelNumber, uint8_t customRGBAmount, ColourRGB *customRGB[AMOUNTOFCOLOURS])
{
  panels[panelNumber]->setDataCustom(customRGBAmount, customRGB);
}
void    LedManager::setEnabled(bool enabled)
{
  this->enabled = enabled;
}
String  LedManager::convertToTansmission()
{
  String data = "";
  
  data += brightness;
  data += speed;
  data += enabled;

  return data;
}
String  LedManager::convertPanelToTransmission(uint8_t panelNumber)
{
  return panels[panelNumber]->convertToTransmission();
}
String  LedManager::convertPanelDiodeToTransmission(uint8_t panelNumber,uint8_t diodeNumber)
{
  return panels[panelNumber]->convertDiodeToTransmission(diodeNumber);
}