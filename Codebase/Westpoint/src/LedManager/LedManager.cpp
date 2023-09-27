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
  dronePercentage = 0;

  uint16_t ledAmount = 0;
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
  for (uint8_t i = 0; i < speed; i++)
  {
    for (uint8_t panelNumber = 0; panelNumber < PANELAMOUNT; panelNumber++)
    {
      panels[panelNumber]->tick();
      for(uint16_t diodeNumber = 0; diodeNumber < panels[panelNumber]->getDiodeAmount(); diodeNumber++)
      {
        leds[panels[panelNumber]->getDiodeStart()+diodeNumber] = panels[panelNumber]->getDiodeRGB(diodeNumber, brightness);
      }
    }
  }
}
void    LedManager::print() 
{
  /*
  for (uint16_t i = 0; i < LEDAMOUNT; i++)
  {
    Serial.print(i);
    Serial.print(" ");
    leds[i] = CRGB(20, 0, 20);
  }

  Serial.println();
  */


  if(dronePercentage == 20)
  {
    for (int i = 100; i < LEDAMOUNT; i++)
    {
      leds[i] = 0;
    }
  }
  else if(dronePercentage == 40)
  {
    for (int i = 200; i < LEDAMOUNT; i++)
    {
      leds[i] = 0;
    }
  }
  else if(dronePercentage == 60)
  {
    for (int i = 300; i < LEDAMOUNT; i++)
    {
      leds[i] = 0;
    }
  }
  else if(dronePercentage == 80)
  {
    for (int i = 400; i < LEDAMOUNT; i++)
    {
      leds[i] = 0;
    }
  }


  FastLED.show(); 
}

void LedManager::setDronePercentage(uint8_t dronePercentage)
{
  this->dronePercentage = dronePercentage;
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
void    LedManager::setPanelData(uint8_t panelNumber, uint8_t brightness, uint8_t effect, uint8_t colour, uint16_t offset, uint8_t speed, bool repeat, bool detailed)
{
  //Serial.println("Setting panel data (In ledmanager)");
  panels[panelNumber]->setDataFx(brightness, effect, colour, offset, speed, repeat, detailed);
}
void    LedManager::setPanelCustomData(uint8_t panelNumber, uint8_t customRGBAmount, ColourRGB *customRGB[AMOUNTOFCOLOURS])
{
  panels[panelNumber]->setDataCustom(customRGBAmount, customRGB);
}
void    LedManager::setPanelDiodeData(uint8_t panelNumber, uint16_t diodeNumber, uint8_t brightness, uint8_t effect, uint8_t colour, uint16_t offset, uint8_t speed, bool repeat)
{
  //Serial.println("Setting diode data (In ledmanager)");
  panels[panelNumber]->setDiodeDataFx(diodeNumber, brightness, effect, colour, offset, speed, repeat);
}
void    LedManager::setEnabled(bool enabled)
{
  this->enabled = enabled;
}
String  LedManager::convertToTansmission()
{
  String data = "";
  
  data += (char)brightness;
  data += (char)speed;
  data += (char)enabled;

  return data;
}
String  LedManager::convertPanelToTransmission(uint8_t panelNumber)
{
  return panels[panelNumber]->convertToTransmission();
}
String  LedManager::convertPanelDiodeToTransmission(uint8_t panelNumber, uint16_t diodeNumber)
{
  return panels[panelNumber]->convertDiodeToTransmission(diodeNumber);
}

void LedManager::setSpeed(uint8_t speed)
{
  this->speed = speed;
}