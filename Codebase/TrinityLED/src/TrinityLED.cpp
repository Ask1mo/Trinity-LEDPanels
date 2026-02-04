#include "TrinityLED.h"





//Constructor
Trinity::Trinity(uint8_t ledPin, uint8_t framerate, bool diodeControl)
{
  Serial.println(F("Trinity MK4 - Ask Blommaert"));

  if(DEBUGLEVEL >= DEBUG_OPERATIONS)
  {
    Serial.print(F("Creating Trinity at adress "));
    Serial.println((int)this, DEC);
  } 


  sleepTimer      = new SleepTimer();

  
  speed           = 1;
  prevFrameMillis = 0;
  frameTime       = 1000/framerate;
  this->allowDiodeControl = diodeControl;

  Serial.print(F("...Trinity Initialised with frameRate of "));
  Serial.print(framerate);
  Serial.print(F(" and frameTime of "));
  Serial.println(frameTime);

  

  //create custom palettes
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

  /*
    sleepTimer->setTurnOnEnabled(true);
    sleepTimer->setTurnOnTime(10,0);
    sleepTimer->setTurnOffEnabled(true);
    sleepTimer->setTurnOffTime(9,59);
  */

  Serial.println(F("...Trinity Started (NOT READY YET, DONT FORGET TO USE Trinity->begin() after adding your panels!!!)"));

}
void    Trinity::addPanel                                    (Panel *panel)
{
  panels = (Panel**)realloc(panels, sizeof(Panel*) * (panelAmount + 1));
  if (panels == NULL)
  {
    Serial.println(F("ERROR: Could not allocate memory for new panel"));
    return;
  }
  panels[panelAmount] = panel;
  panelAmount++;
  Serial.print(F("New panel added, Amount is now: "));
  Serial.println(panelAmount);
}

void    Trinity::addPanel                                    (uint8_t x, uint8_t y, uint8_t compassDir, bool clockDir, uint16_t diodeAmount)
{
  addPanel(new Panel(panelAmount, x, y, compassDir, clockDir, diodeAmount, allowDiodeControl));
}

void    Trinity::addPanel                                    (uint16_t diodeAmount)
{
  addPanel(new Panel(panelAmount, 0, 0, 0, 0, diodeAmount, allowDiodeControl));
}

void Trinity::begin()
{
  //Count diodes and give them to the panels (tell them where they start)
  int ledAmount = 0;
  for (uint8_t i = 0; i < panelAmount; i++)
  {
    panels[i]->setDiodeStart(ledAmount);
    ledAmount += panels[i]->getDiodeAmount();
  }

  //create static led array
  const int staticLedAmount = ledAmount;
  leds = new CRGB[staticLedAmount];
  if(DEBUGLEVEL >= DEBUG_OPERATIONS)
  {
    Serial.print(F("Allocated  "));
    Serial.print(staticLedAmount);
    Serial.print(F(" LED's at adress "));
    Serial.println((int)leds, DEC);
  }

  if(!leds)
  {
    Serial.println(F("ERROR: Trinity::Trinity() Could not create led array"));
  }

  //start FastLED
  #ifdef PLATFORM_ESP32_FIREBEETLE2_DEBUG
  FastLED.addLeds<NEOPIXEL, PIN_LEDS>(leds, staticLedAmount);
  #endif
  #ifndef PLATFORM_ESP32_FIREBEETLE2_DEBUG
  FastLED.addLeds<WS2812, PIN_LEDS, LEDCOLORDER>(leds, staticLedAmount);
  #endif

  prepareCanvas();

}
//Public
//Standard

void    Trinity::tick                            () 
{

  uint32_t currentMillis = millis();

  //Frame pushing
  tick_leds();


  //Waking up or Shutting down system from sleep timer
  sleepTimer->tick();
  switch (sleepTimer->getTurn())
  {
    case TURN_OFF:
    {
      Serial.println(F("SleepTimer Turning system off"));
      setBrightness(0, true);
    }
    break;

    case TURN_ON:
    {
      Serial.println(F("SleepTimer Turning system on"));
      if(getBrightness() == 0)setBrightness(100, true);
    }
    break;
  }





  //Preset animations cycling
  if(!animationCycling)return;

  if(currentMillis >= (prevMillis_AnimationCycle+durationMillis_animationCycle))
  {
    prevMillis_AnimationCycle = currentMillis;
    nextPresetAnimation(); 
  }
} 
void    Trinity::tick_leds                       ()
{
  uint32_t currentMillis = millis();
  if(currentMillis >= (prevFrameMillis+frameTime))
  {
    prevFrameMillis = currentMillis;

    //Brightness
    if      (brightness < goalBrightness) brightness++;
    else if (brightness > goalBrightness) brightness--;
    
    //FX
    for (uint8_t i = 0; i < speed; i++)
    {
      if(DEBUGLEVEL >=DEBUG_OPERATIONS) Serial.print(F("t"));

      for (uint8_t i = 0; i < panelAmount; i++)
      {
        panels[i]->tick();

        for(uint16_t j = 0; j < panels[i]->getDiodeAmount(); j++)
        {
          leds[panels[i]->getDiodeStart()+j] = panels[i]->getDiodeRGB(j, brightness);
        }
      }
    }
    
    print();
  }
}
void Trinity::forceTick_leds(uint16_t ticks, bool keepPrinting, uint16_t delayTime)
{
  for (uint16_t i = 0; i < ticks; i++)
  {
    if(DEBUGLEVEL >=DEBUG_DAYISRUINED) Serial.print(F("T"));
    tick_leds();

    if (keepPrinting)
    {
      if(DEBUGLEVEL >=DEBUG_DAYISRUINED) Serial.print(("P"));
      //print();

      if(delayTime > 0 )
      {
        delay(delayTime);
      }
    }
  }
}




void    Trinity::print                           () 
{
  if(DEBUGLEVEL >= DEBUG_OPERATIONS) Serial.print(F("p"));
  FastLED.show(); 
}
//Effects
uint8_t Trinity::getBrightness                   ()
{
  return brightness;
}
void    Trinity::setBrightness                   (uint8_t brightness, bool smooth)
{
  if (smooth)
  {
    goalBrightness = brightness;
  }
  else
  {
    this->brightness = brightness;
  }
}
void    Trinity::setSpeed                        (uint8_t speed)
{
  this->speed = speed;
}
//Panel Effects
void    Trinity::setPanelBrightness              (uint8_t panelNumber, uint8_t brightness, bool smooth)
{
  if (panelNumber > panelAmount)
  {
    Serial.print(F("ERROR: Trinity::setPanelBrightness(): Too high panel number requested: "));
    Serial.print(panelNumber);
    Serial.print(F(". Max: "));
    Serial.println(panelAmount);
    return;
  }

  panels[panelNumber]->setBrightness(brightness, smooth);
}
void    Trinity::setPanelVfx                     (uint8_t panelNumber, VFXData vfxData)
{
  //Serial.println("Setting panel data (In ledmanager)");
  panels[panelNumber]->setVfx(vfxData);

  if (CUSTOMEFFECTNUMBER_FIRST <= vfxData.effect && vfxData.effect <= CUSTOMEFFECTNUMBER_LAST) //If it's a custom colour effect: Apply colour palette
  {
    panels[panelNumber]->setDataCustom(customPalette[vfxData.colour]);
  }
}
//Diode Effects
void    Trinity::setPanelDiodeBrightness              (uint8_t panelNumber, uint16_t diodeNumber, uint8_t brightness, bool smooth)
{
  if (panelNumber > panelAmount)
  {
    Serial.print(F("ERROR: Trinity::setPanelDiodeBrightness(): Too high panel number requested: "));
    Serial.print(panelNumber);
    Serial.print(F(". Max: "));
    Serial.println(panelAmount);
    return;
  }

  if (diodeNumber > panels[panelNumber]->getDiodeAmount())
  {
    Serial.print(F("ERROR: Trinity::setPanelDiodeBrightness(): Too high diode number requested: "));
    Serial.print(diodeNumber);
    Serial.print(F(". Max: "));
    Serial.println(panels[panelNumber]->getDiodeAmount());
    return;
  }
  
  panels[panelNumber]->setDiodeBrightness(diodeNumber, brightness, smooth);
}
void    Trinity::setPanelDiodeVfx                (uint8_t panelNumber, uint16_t diodeNumber, VFXData vfxData)
{
  //Serial.println("Setting diode data (In ledmanager)");
  if (panelNumber > getPanelAmount())
  {
    Serial.print(F("Trinity::setPanelDiodeVfx() Too high panel number requested: "));
    Serial.print(panelNumber);
    Serial.print(F(". Max: "));
    Serial.println(getPanelAmount());
  }
  
  panels[panelNumber]->setDiodeVfx(diodeNumber, vfxData);
}
//Technical
uint8_t Trinity::getPanelAmount                  ()
{
  return panelAmount;
}
uint16_t Trinity::getPanelDiodeAmount            (uint8_t panelNumber)
{
  return panels[panelNumber]->getDiodeAmount();
}
//Transmissions
String  Trinity::convertToTansmission            ()
{
  String data = "";
  
  data += (char)brightness;
  data += (char)speed;

  return data;
}
String  Trinity::convertPanelToTransmission      (uint8_t panelNumber)
{
  return panels[panelNumber]->convertToTransmission();
}
String  Trinity::convertPanelDiodeToTransmission (uint8_t panelNumber,uint16_t diodeNumber)
{
  return panels[panelNumber]->convertDiodeToTransmission(diodeNumber);
}

void Trinity::setCustomPaletteColours(uint8_t slot, uint8_t colourRGBNumber, ColourRGB colourRGB)
{
  if (slot >= CUSTOMPALETTEAMOUNT)
  {
    if (DEBUGLEVEL >=  DEBUG_ERRORS)
    {
      Serial.print(F("ERROR: Trinity.setCustomPaletteColours() Slot selected too high: "));
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
      Serial.print(F("ERROR: Trinity.setCustomPaletteColours() Colour number selected too high: "));
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
void Trinity::setCustomPaletteAvailableColours(uint8_t slot, uint8_t avalaibleColours)
{
  customPalette[slot]->customRGBSlots = avalaibleColours;
}



//Preset animations
void Trinity::resetAnim_Wspt_Reset()
{
  Serial.println(F("playAnimation_Reset"));
  setSpeed(1);

  uint16_t diodeNumbers = 0;
  for (uint16_t i = 0; i < getPanelAmount(); i++)
  {
    setPanelVfx(i, (VFXData){EFFECT_STOCK_STATIC, COLOUR_BLACK, 0, 1, true});
    for (uint16_t j = 0; j < getPanelDiodeAmount(i); j++)
    {
      diodeNumbers++;
      //setPanelDiodeVfx(i, j, (VFXData){EFFECT_STOCK_STATIC, COLOUR_VIOLET, diodeNumbers, 1, false});
    }
  }
  Serial.print("Prepped reset fx, frames: ");
  Serial.println(diodeNumbers);
  forceTick_leds(diodeNumbers, false, 0);
  Serial.println("Reset anim complete");
  //delay(1000);
}
void Trinity::playPresetAnim_Wspt_FullWhite()
{
  Serial.println(F("playPresetAnim_Wspt_FullWhite"));
  setSpeed(1);

  uint16_t offset = 0;
  for (uint16_t i = 0; i < getPanelAmount(); i++)
  {
    setPanelVfx(i, (VFXData){EFFECT_STOCK_STATIC, COLOUR_WHITE, (uint16_t)(random(0, 10)*15), 1, true});
    for (uint16_t j = 0; j < getPanelDiodeAmount(i); j++)
    {
      setPanelDiodeVfx(i, j, (VFXData){EFFECT_STOCK_STATIC, COLOUR_WHITE, 0, 5, true});
      offset++;
    }
  }
}
void Trinity::playPresetAnim_Wspt_Default()
{
  Serial.println(F("playPresetAnim_Wspt_Default"));
  setSpeed(1);

  uint16_t offset = 0;
  for (uint16_t i = 0; i < getPanelAmount(); i++)
  {
    setPanelVfx(i, (VFXData){EFFECT_STOCK_DECODE, COLOUR_RED, (uint16_t)(random(0, 10)*15), 1, true});
    for (uint16_t j = 0; j < getPanelDiodeAmount(i); j++)
    {
      setPanelDiodeVfx(i, j, (VFXData){EFFECT_SPECIAL_RAINBOW, COLOUR_RED, 0, 5, true});
      offset++;
    }
  }
}
void Trinity::playPresetAnim_Wspt_BreathingLines()
{
  Serial.println(F("playPresetAnim_Wspt_BREATHINGLINES"));
  setSpeed(1);

  for (uint16_t i = 0; i < getPanelAmount(); i++)
  {
    setPanelVfx(i, (VFXData){EFFECT_STOCK_DECODE, COLOUR_RED, (uint16_t)(random(0, 10)*15), 1, true});
    for (uint16_t j = 0; j < getPanelDiodeAmount(i); j++)
    {
      setPanelDiodeVfx(i, j, (VFXData){EFFECT_STOCK_PAUSEDBREATHING, COLOUR_CYCLE, j, 20, true});
    }
  }
}
void Trinity::playPresetAnim_Wspt_FlashingLines()
{
  Serial.println(F("playPresetAnim_Wspt_FlashingGLINES"));
  setSpeed(1);

  for (uint16_t i = 0; i < getPanelAmount(); i++)
  {
    setPanelVfx(i, (VFXData){EFFECT_STOCK_DECODE, COLOUR_RED, (uint16_t)(random(0, 10)*15), 1, true});
    for (uint16_t j = 0; j < getPanelDiodeAmount(i); j++)
    {
      setPanelDiodeVfx(i, j, (VFXData){EFFECT_STOCK_PAUSEDFLASH, COLOUR_WHITE, j, 10, true});
    }  
  }
}
void Trinity::playPresetAnim_Wspt_Rain()
{
  Serial.println(F("playPresetAnim_Wspt_Rain"));
  setSpeed(1);

  for (uint16_t i = 0; i < getPanelAmount(); i++)
  {
    setPanelVfx(i, (VFXData){EFFECT_STOCK_DECODE, COLOUR_RED, (uint16_t)(random(0, 10)*15), 1, true});
    for (uint16_t j = 0; j < getPanelDiodeAmount(i); j++)
    {
      setPanelDiodeVfx(i, j, (VFXData){EFFECT_STOCK_PAUSEDFLASH, COLOUR_BLUE, j, (uint8_t)random(0, 10), true});
    }
  }
}
void Trinity::playPresetAnim_Wspt_Matrix()
{
  Serial.println(F("playPresetAnim_Wspt_Matrix"));
  setSpeed(1);

  for (uint16_t i = 0; i < getPanelAmount(); i++)
  {
    setPanelVfx(i, (VFXData){EFFECT_STOCK_DECODE, COLOUR_RED, (uint16_t)(random(0, 10)*15), 1, true});
    for (uint16_t j = 0; j < getPanelDiodeAmount(i); j++)
    {
      setPanelDiodeVfx(i, j, (VFXData){EFFECT_STOCK_DECODE, COLOUR_GREEN, j, 10, true});
    }
  }
}
void Trinity::playPresetAnim_Wspt_SuperRainbow()
{
  Serial.println(F("playPresetAnim_Wspt_SuperRainbow"));
  setSpeed(3);

  uint16_t offset = 0;
  for (uint16_t i = 0; i < getPanelAmount(); i++)
  {
    setPanelVfx(i, (VFXData){EFFECT_STOCK_DECODE, COLOUR_RED, 0, 1, true});
    for (uint16_t j = 0; j < getPanelDiodeAmount(i); j++)
    {
      setPanelDiodeVfx(i, j, (VFXData){EFFECT_SPECIAL_RAINBOW, COLOUR_RED, offset, 10, true});
      offset++;
    }
  }
}
void Trinity::playPresetAnim_Wspt_ADHDRainbow()
{
  Serial.println(F("playPresetAnim_Wspt_ADHDRAINBOW"));
  setSpeed(1);

  uint16_t offset = 0;
  for (uint16_t i = 0; i < getPanelAmount(); i++)
  {
    for (uint16_t j = 0; j < getPanelDiodeAmount(i); j++)
    {
      setPanelDiodeVfx(i, j, (VFXData){EFFECT_SPECIAL_RAINBOW, COLOUR_RED, offset, 100, true});
      offset++;
    }
  }
  forceTick_leds(500, false, 0);
}
void Trinity::playPresetAnim_Wspt_BurningRainbow()
{
  Serial.println(F("playPresetAnim_Wspt_BurningRainbow"));
  setSpeed(4);

  uint16_t offset = 0;
    for (uint16_t i = 0; i < getPanelAmount(); i++)
    {
      setPanelVfx(i, (VFXData){EFFECT_STOCK_DECODE, COLOUR_RED, (uint16_t)(i*5), 10, true});
      for (uint16_t j = 0; j < getPanelDiodeAmount(i); j++)
      {
        setPanelDiodeVfx(i, j, (VFXData){EFFECT_SPECIAL_RAINBOW, COLOUR_RED, (uint16_t)(j*5), 10, true});
        offset++;
      }
  

      
    }
}
void Trinity::playPresetAnim_Wspt_HeartbeatTower()
{
  Serial.println(F("playPresetAnim_Wspt_HeartbeatTower"));
  setSpeed(5);

  uint16_t offset = 0;
    for (uint16_t i = 0; i < getPanelAmount(); i++)
    {
      setPanelVfx(i, (VFXData){EFFECT_STOCK_DECODE, COLOUR_RED, (uint16_t)(i*4), 1, true});
      for (uint16_t j = 0; j < getPanelDiodeAmount(i); j++)
      {
        setPanelDiodeVfx(i, j, (VFXData){EFFECT_STOCK_HEARTBEAT, COLOUR_RED, 0, 1, true});
        offset++;
      }
  

      
    }
}
void Trinity::playPresetAnim_Wspt_Stoplight()
{
  Serial.println(F("playPresetAnim_Wspt_Stoplight"));
  setSpeed(8);

  uint16_t offset = 0;
    for (uint16_t i = 0; i < getPanelAmount(); i++)
    {
      setPanelVfx(i, (VFXData){EFFECT_STOCK_DECODE, COLOUR_RED, offset, 1, true});
      for (uint16_t j = 0; j < getPanelDiodeAmount(i); j++)
      {
        setPanelDiodeVfx(i, j, (VFXData){EFFECT_STOCK_PAUSEDFLASH, COLOUR_CYCLE, offset, 1, true});
        offset+=3;
      }
  

      
    }
}
void Trinity::playPresetAnim_Wspt_PowerRise()
{
  Serial.println(F("playPresetAnim_Wspt_Powerrize"));
  setSpeed(15);

  uint16_t offset = 0;
    for (uint16_t i = 0; i < getPanelAmount(); i++)
    {
      setPanelVfx(i, (VFXData){EFFECT_STOCK_DECODE, COLOUR_RED, offset, 1, true});
      for (uint16_t j = 0; j < getPanelDiodeAmount(i); j++)
      {
        setPanelDiodeVfx(i, j, (VFXData){EFFECT_STOCK_PAUSEDFLASH, COLOUR_CYAN, offset, 1, true});
        offset++;
      }
  

      
    }
}
void Trinity::playPresetAnim_Wspt_Fishbowl()
{
  Serial.println(F("playPresetAnim_Wspt_Fishbowl"));
  setSpeed(10);

  uint16_t offset = 0;
  for (uint16_t i = 0; i < getPanelAmount(); i++)
  {
    setPanelVfx(i, (VFXData){EFFECT_STOCK_DECODE, COLOUR_RED, offset, 1, true});
    for (uint16_t j = 0; j < getPanelDiodeAmount(i); j++)
    {
      setPanelDiodeVfx(i, j, (VFXData){EFFECT_STOCK_PAUSEDFLASH, COLOUR_CYCLE, offset, 1, true});
      offset+=10;
    }
  }
  forceTick_leds(900, false, 0);
}
void Trinity::playPresetAnim_Wspt_Coils()
{
  Serial.println(F("playPresetAnim_Wspt_Coils"));
  setSpeed(10);

  uint16_t offset = 0;

  for (uint8_t i = 0; i < getPanelAmount(); i++)
  {
    setPanelVfx(i, (VFXData){EFFECT_STOCK_DECODE, COLOUR_RED, 0, 1, true});
    for (uint8_t j = 0; j < getPanelDiodeAmount(i); j++)
    {
      setPanelDiodeVfx(i, j, VFXData{ EFFECT_STOCK_DECODE, COLOUR_CYCLE, offset, 1, true});
      offset++;
    }
  }
}
void Trinity::playPresetAnim_Wspt_AppearThing()
{
  Serial.println(F("playPresetAnim_Wspt_AppearThing"));
  setSpeed(20);

  uint16_t offset = 0;

  for (uint8_t i = 0; i < getPanelAmount(); i++)
  {
    setPanelVfx(i, (VFXData){EFFECT_STOCK_DECODE, COLOUR_RED, (uint16_t)random(0, 100), 1, true});
    for (uint8_t j = 0; j < getPanelDiodeAmount(i); j++)
    {
      setPanelDiodeVfx(i, j,VFXData{ EFFECT_STOCK_DECODE, COLOUR_CYCLE, (uint16_t)random(0, 100), 1, true});
      offset++;
    }
  }

}
void Trinity::playPresetAnim_Wspt_AppearThing2()
{
  Serial.println(F("playPresetAnim_Wspt_AppearThing2"));
  setSpeed(10);

  uint16_t offset = 0;

  for (uint8_t i = 0; i < getPanelAmount(); i++)
  {
    setPanelVfx(i, (VFXData){EFFECT_STOCK_DECODE, COLOUR_RED, (uint16_t)random(0, 100), 1, true});
    for (uint8_t j = 0; j < getPanelDiodeAmount(i); j++)
    {
      setPanelDiodeVfx(i, j,VFXData{ EFFECT_STOCK_STATIC, COLOUR_CYCLE, (uint16_t)random(0, 100), 1, true});
      offset++;
    }
  }

}
void Trinity::playPresetAnim_Wspt_AppearThing3()
{
  Serial.println(F("playPresetAnim_Wspt_AppearThing3"));
  setSpeed(10);

  uint16_t offset = 0;

  for (uint8_t i = 0; i < getPanelAmount(); i++)
  {
    setPanelVfx(i, (VFXData){EFFECT_STOCK_DECODE, COLOUR_RED, 0, 1, true});
    for (uint8_t j = 0; j < getPanelDiodeAmount(i); j++)
    {
      setPanelDiodeVfx(i, j,VFXData{ EFFECT_STOCK_STATIC, COLOUR_CYCLE, (uint16_t)random(0, 1000), 1, true});
      offset++;
    }
  }
}
void Trinity::playPresetAnim_Wspt_AppearThing4()
{
  Serial.println(F("playPresetAnim_Wspt_AppearThing4"));
  setSpeed(4);

  uint16_t offset = 0;

  for (uint8_t i = 0; i < getPanelAmount(); i++)
  {
    setPanelVfx(i, (VFXData){EFFECT_STOCK_DECODE, COLOUR_RED, 0, 1, true});
    for (uint8_t j = 0; j < getPanelDiodeAmount(i); j++)
    {
      setPanelDiodeVfx(i, j,VFXData{ EFFECT_STOCK_PAUSEDFLASH, COLOUR_CYCLE, (uint16_t)random(0, 250), 1, true});
      offset++;
    }
  }
}
void Trinity::playPresetAnim_Wspt_ColourBlink()
{
  Serial.println(F("playPresetAnim_Wspt_ColourBlink"));
  setSpeed(4);

  uint16_t offset = 0;

  for (uint8_t i = 0; i < getPanelAmount(); i++)
  {
    setPanelVfx(i, (VFXData){EFFECT_STOCK_DECODE, COLOUR_RED, 0, 1, true});
    for (uint8_t j = 0; j < getPanelDiodeAmount(i); j++)
    {
      setPanelDiodeVfx(i, j,VFXData{ EFFECT_STOCK_STATIC, COLOUR_CYCLE, i, 1, true});
      offset++;
    }
  }
  forceTick_leds(64, false, 0);
}
void Trinity::playPresetAnim_Atos_Default()
{
  Serial.println(F("playPresetAnim_Atos_Default"));
  setSpeed(1);

  const int offset = 10;


  setPanelVfx(0, (VFXData){EFFECT_SPECIAL_SYNTH, COLOUR_BLACK, 10, 1, true});
  for (uint8_t i = 0; i < getPanelDiodeAmount(0); i++)
  {
    setPanelDiodeVfx(0, i, (VFXData){EFFECT_SPECIAL_SYNTH, COLOUR_BLACK, i*offset, 1, true});
  }

  setPanelVfx(1, (VFXData){EFFECT_SPECIAL_SYNTH, COLOUR_BLACK, 10, 1, true});
  for (uint8_t i = 0; i < getPanelDiodeAmount(1); i++)
  {
    setPanelDiodeVfx(1, i, (VFXData){EFFECT_SPECIAL_SYNTH, COLOUR_BLACK, i*offset, 1, true});
  }

  setPanelVfx(2, (VFXData){EFFECT_SPECIAL_SYNTH, COLOUR_BLACK, 10, 1, true});
  for (uint8_t i = 0; i < getPanelDiodeAmount(2); i++)
  {
    setPanelDiodeVfx(2, i, (VFXData){EFFECT_SPECIAL_SYNTH, COLOUR_BLACK, i*offset, 1, true});
  }
}

//Sleep timer
void Trinity::setTurnOnEnabled(bool enabled)
{
  sleepTimer->setTurnOnEnabled(enabled);
}
void Trinity::setTurnOnTime(uint8_t hour, uint8_t minute)
{
  sleepTimer->setTurnOnTime(hour, minute);
}
void Trinity::setTurnOffEnabled(bool enabled)
{
  sleepTimer->setTurnOffEnabled(enabled);
}
void Trinity::setTurnOffTime(uint8_t hour, uint8_t minute)
{
  sleepTimer->setTurnOffTime(hour, minute);
}

//Preset animations

void Trinity::setAnimationCyclingDuration(uint32_t duration)
{
  durationMillis_animationCycle = duration;
}
void Trinity::playPresetAnimation(uint8_t animation, bool cycling)
{
  animationCycling = cycling;
  currentlyShowingAnimation = animation;

  switch (animation)
  {
    case 0:  playPresetAnim_Wspt_FullWhite     (); break;
    case 1:  playPresetAnim_Wspt_Default       (); break;
    case 2:  playPresetAnim_Wspt_BreathingLines(); break;
    case 3:  playPresetAnim_Wspt_FlashingLines (); break;
    case 4:  playPresetAnim_Wspt_Rain          (); break;
    case 5:  playPresetAnim_Wspt_Matrix        (); break;
    case 6:  playPresetAnim_Wspt_SuperRainbow  (); break;
    case 7:  playPresetAnim_Wspt_ADHDRainbow   (); break;
    case 8:  playPresetAnim_Wspt_BurningRainbow(); break;
    case 9:  playPresetAnim_Wspt_HeartbeatTower(); break;
    case 10: playPresetAnim_Wspt_Stoplight     (); break;
    case 11: playPresetAnim_Wspt_PowerRise     (); break;
    case 12: playPresetAnim_Wspt_Fishbowl      (); break;
    case 13: playPresetAnim_Wspt_Coils         (); break;
    case 14: playPresetAnim_Wspt_AppearThing   (); break;
    case 15: playPresetAnim_Wspt_AppearThing2  (); break;
    case 16: playPresetAnim_Wspt_AppearThing3  (); break;
    case 17: playPresetAnim_Wspt_AppearThing4  (); break;
    case 18: playPresetAnim_Wspt_ColourBlink   (); break;
    case 19: playPresetAnim_Atos_Default       (); break;
  }

  prevMillis_AnimationCycle = millis();
}

void Trinity::nextPresetAnimation()
{

  static uint8_t currentAnimation = 0;
  currentAnimation++;
  if (currentAnimation > 18) currentAnimation = 0;

  resetAnim_Wspt_Reset();

  playPresetAnimation(currentAnimation, true);
}

void Trinity::prepareCanvas()
{
  Serial.println(F("Prepping canvasWidth and canvasHeight"));
  //Prepare the panel matrix x and y
  for (uint8_t i = 0; i < panelAmount; i++)
  {
    if (panels[i]->getX() > canvasWidth)
    {
      canvasWidth = panels[i]->getX()+1;
      Serial.print(F("New canvasWidth: "));
      Serial.println(canvasWidth);
    }
    if (panels[i]->getY() > canvasHeight)
    {
      canvasHeight = panels[i]->getY()+1;
      Serial.print(F("New canvasHeight: "));
      Serial.println(canvasHeight);
    }
  }
  
  Serial.println(F("Allocating the panel matrix"));
  // Allocate memory for the 2D array
  panelMatrix = new Panel**[canvasWidth];
  for(uint8_t i = 0; i < canvasWidth; ++i)
  {
    panelMatrix[i] = new Panel*[canvasHeight];
  }

  Serial.println(F("Setting all elements to nullptr"));
  // Initialize all elements to nullptr
  for(uint8_t i = 0; i < canvasWidth; ++i)
  {
    for(uint8_t j = 0; j < canvasHeight; ++j)
    {
      panelMatrix[i][j] = nullptr;
    }
  }

  Serial.println(F("Adding all panels to the matrix"));
  //Add all panels to their corresponding spots in the matrix
  for (uint8_t i = 0; i < panelAmount; i++)
  {
    
    Serial.println(F("Panel index out of bounds"));

    Serial.print(F("Adding panel to position "));
    Serial.print(panels[i]->getX());
    Serial.print(F(","));
    Serial.println(panels[i]->getY());
    
    if (panels[i]->getX() >= canvasWidth || panels[i]->getY() >= canvasHeight)
    {
      Serial.print(F("Panel index out of bounds: "));
      Serial.print(panels[i]->getX());
      Serial.print(F(","));
      Serial.print(panels[i]->getY());

      Serial.print(F("Canvas size: "));
      Serial.print(canvasWidth);
      Serial.print(F(","));
      Serial.println(canvasHeight);
    }
    
    panelMatrix[panels[i]->getX()][panels[i]->getY()] = panels[i];
    
  }



  //Print the matrix
  printCanvas();

}


void Trinity::printCanvas()
{
  int canvasSize = 10;



    Serial.println();
    Serial.println("Printing canvas:");

    Serial.print("Columns");    
        for(uint8_t j = 0; j < canvasSize; j++)
        {
            Serial.print(" ");
            if(j<10) Serial.print(" ");
            Serial.print(j);
        }
        Serial.println();


    for (uint8_t i = 0; i < canvasSize; i++)
    {
        Serial.print("Row ");
        Serial.print(i);
        if(i<10) Serial.print(" ");
        Serial.print(" [");


        for (uint8_t j = 0; j < canvasSize; j++)
        {
            if (panelMatrix[j][i] != nullptr)
            {
              if (panelMatrix[j][i]->getNumber() < 10) Serial.print(" ");
                Serial.print(panelMatrix[j][i]->getNumber());
                
            }
            else
            {
                Serial.print("  ");
            }
            Serial.print(" ");
        }
        Serial.println(" ]");        
    }
}