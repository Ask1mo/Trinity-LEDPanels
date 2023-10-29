#include "ledManager.h"

//Constructor
LedManager::LedManager                              (Panel **panelsArg)
{
  Serial.println(F("LedManager Starting..."));

  panelsAmount  = PANELAMOUNT;
  brightness    = 255;
  speed         = 1;
  enabled       = 1;
  panels        = panelsArg;

  int ledAmount = 0;
  for (uint8_t i = 0; i < PANELAMOUNT; i++)
  {
    panels[i]->setDiodeStart(ledAmount);
    ledAmount += panels[i]->getDiodeAmount();
  }

  for (uint8_t i = 0; i < CUSTOMPALETTEAMOUNT; i++)
  {
    customPalette[i] = new struct CustomPalette;
    for (uint8_t j = 0; j < AMOUNTOFCOLOURS; j++)
    {
      customPalette[i]->customRGB[j].r = 0;
      customPalette[i]->customRGB[j].g = 0;
      customPalette[i]->customRGB[j].b = 0;
    }
  }
  

  #ifdef PLATFORM_ESP32_FIREBEETLE2_DEBUG
  FastLED.addLeds<NEOPIXEL, PIN_LEDS>(leds, LEDAMOUNT);
  #endif
  #ifndef PLATFORM_ESP32_FIREBEETLE2_DEBUG
  FastLED.addLeds<WS2812, PIN_LEDS, LEDCOLORDER>(leds, LEDAMOUNT);
  #endif

  Serial.println(F("...LedManager Started"));
}

//Public
//Standard
void    LedManager::tick                            () 
{
  for (uint8_t i = 0; i < speed; i++)
  {
    if(DEBUGLEVEL >=DEBUG_OPERATIONS) Serial.print(F("t"));

    for (uint8_t i = 0; i < panelsAmount; i++)
    {
      panels[i]->tick();

      for(uint16_t j = 0; j < panels[i]->getDiodeAmount(); j++)
      {
        leds[panels[i]->getDiodeStart()+j] = panels[i]->getDiodeRGB(j, brightness);
      }
    }
  }
} 
void    LedManager::print                           () 
{
  if(DEBUGLEVEL >= DEBUG_OPERATIONS) Serial.print(F("p"));
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
void    LedManager::setSpeed                        (uint8_t speed)
{
  this->speed = speed;
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

  if (CUSTOMEFFECTNUMBER_FIRST <= vfxData.effect && vfxData.effect <= CUSTOMEFFECTNUMBER_LAST) //If it's a custom colour effect: Apply colour palette
  {
    panels[panelNumber]->setDataCustom(customPalette[vfxData.colour]);
  }
}
//Diode Effects
void    LedManager::setPanelBrightness              (uint8_t panelNumber, uint16_t diodeNumber, uint8_t brightness)
{
  
}
void    LedManager::setPanelDiodeVfx                (uint8_t panelNumber, uint16_t diodeNumber, VFXData vfxData)
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
uint16_t LedManager::getPanelDiodeAmount            (uint8_t panelNumber)
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
String  LedManager::convertPanelDiodeToTransmission (uint8_t panelNumber,uint16_t diodeNumber)
{
  return panels[panelNumber]->convertDiodeToTransmission(diodeNumber);
}

void LedManager::setCustomPaletteColours(uint8_t slot, uint8_t colourRGBNumber, ColourRGB colourRGB)
{
  if (slot >= CUSTOMPALETTEAMOUNT)
  {
    if (DEBUGLEVEL >=  DEBUG_ERRORS)
    {
      Serial.print(F("ERROR: LedManager.setCustomPaletteColours() Slot selected too high: "));
      Serial.print(slot);
      Serial.print(F(" Max:"));
      Serial.println(CUSTOMPALETTEAMOUNT);
      return;
    }
  }

  if (colourRGBNumber >= AMOUNTOFCOLOURS)
  {
    if (DEBUGLEVEL >=  DEBUG_ERRORS)
    {
      Serial.print(F("ERROR: LedManager.setCustomPaletteColours() Colour number selected too high: "));
      Serial.print(slot);
      Serial.print(F(" Max:"));
      Serial.println(AMOUNTOFCOLOURS);
      return;
    }
  }

  
  customPalette[slot]->customRGB[colourRGBNumber].r = colourRGB.r;
  customPalette[slot]->customRGB[colourRGBNumber].g = colourRGB.g;
  customPalette[slot]->customRGB[colourRGBNumber].b = colourRGB.b;
}
void LedManager::setCustomPaletteAvailableColours(uint8_t slot, uint8_t avalaibleColours)
{
  customPalette[slot]->customRGBSlots = avalaibleColours;
}