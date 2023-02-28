#include "ledManager.h"

LedManager::LedManager(Panel **panelsArg)
{
  Serial.println(F("LedManager Starting..."));

  brightness  = 100;
  speed       = 1;
  panels        = panelsArg;
  this->panelsAmount  = PANELAMOUNT;

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


void LedManager::tick() 
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
void LedManager::print() 
{
  #ifdef PLATFORM_ESP32FIREBEETLE2_DEBUG
  Serial.print(F("Red = "));
  Serial.println(leds[5].r);

  leds[5].r = leds[5].red;

  Serial.print(F("Red = "));
  Serial.println(leds[5].r);

  leds[5].r = 255;
  
  Serial.print(F("Red = "));
  Serial.println(leds[5].r);





  leds[0].g = leds[0].green;
  leds[0].b = leds[0].blue;
  FastLED.show();
  
  delay(500);
  
  leds[0].r = 255;
  FastLED.show();
  delay(500);
  
  leds[0].g = 255;
  FastLED.show();
  delay(500);
  
  leds[0].b = 255;
  FastLED.show();
  delay(500);
  #endif

  FastLED.show();
  
}
uint8_t LedManager::getBrightness()
{
  return brightness;
}
void LedManager::setBrightness(uint8_t brightness)
{
  this->brightness = brightness;
  this->brightness = 255;
}
void LedManager::setPanelData(uint8_t panelNumber, uint8_t direction, uint8_t brightness, uint8_t effect, uint8_t colour, uint8_t offset, uint8_t speed, bool repeat)
{
  panels[panelNumber]->setDataFx(direction, brightness, effect, colour, offset, speed, repeat);
}
void LedManager::setPanelCustomData(uint8_t panelNumber, uint8_t customRGBAmount, ColourRGB *customRGB[AMOUNTOFCOLOURS])
{
  panels[panelNumber]->setDataCustom(customRGBAmount, customRGB);
}
void LedManager::setEnabled(bool enabled)
{
  this->enabled = enabled;
}