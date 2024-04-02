#include "Trinity.h"



//Constructor
Trinity::Trinity(uint8_t ledPin, uint8_t buttonPin, uint8_t ldrPin, uint8_t maxFramerate)
{
  Serial.println(F("Trinity MK3 - Ask Blommaert"));

  if(DEBUGLEVEL >= DEBUG_OPERATIONS)
  {
    Serial.print(F("Creating Trinity at adress "));
    Serial.println((int)this, DEC);
  }

  ledManager        = new LedManager(); //Todo: Made LedManager accept const ints
  button            = new AskButton(buttonPin, 500);
  lightSensor       = new LightSensor(ldrPin);
  sleepTimer        = new SleepTimer();
  comms             = new Comms();

  setupComplete = false;

  

  setBrightnessMode(BRIGHTNESS_3_MAX);
  currentEffect = 0;
  prevFrameMillis = 0;
  frameTime = 1000/maxFramerate;

  Serial.print(F("...Trinity Initialised with frameRate of "));
  Serial.print(maxFramerate);
  Serial.print(F(" and frameTime of "));
  Serial.println(frameTime);

  /*
  sleepTimer->setTurnOnEnabled(true);
  sleepTimer->setTurnOnTime(10,0);
  sleepTimer->setTurnOffEnabled(true);
  sleepTimer->setTurnOffTime(9,59);
  */

  Serial.println(F("...Trinity Started"));


}
void Trinity::addPanel(Panel *panel)
{
  ledManager->addPanel(panel);
}
void Trinity::begin()
{
  ledManager->begin();
  webServerManager  = new WebServerManager(ledManager->getPanelAmount(), ledManager->getCanvasWidth(), ledManager->getCanvasHeight());
  setupComplete = true;
  Serial.println(F("...Trinity Setup Finalised"));

    setAnimation_Atos_0();
    currentEffect = 1;

}
//Private

//Public
void Trinity::tick()
{
  if (!setupComplete)
  {
    if (DEBUGLEVEL >= DEBUG_ERRORS)Serial.println(F("Trinity not setup yet"));
    return;
  }
  
  webServerManager->tick();

  //Frame pushing
  uint64_t currentMillis = millis();
  if(currentMillis >= (prevFrameMillis+frameTime))
  {
    prevFrameMillis = currentMillis;

    
    ledManager->tick();
    ledManager->print();
  }

  //Button press handling
  switch(button->getCommand())
  {
    case BUTTON_HELD: //Brightness cycle
    {
      switch (brightnessMode)
      {
        case BRIGHTNESS_4_AUT:
        {
          setBrightnessMode(BRIGHTNESS_0_OFF);
          lightSensor->setEnabled(false);
          Serial.println(F("Changing sys brightness to OFF"));
        }
        break;
        case BRIGHTNESS_0_OFF:
        { 
          setBrightnessMode(BRIGHTNESS_1_DIM);
          lightSensor->setEnabled(false);
          Serial.println(F("Changing sys brightness to DIM"));
        }
        break;
        case BRIGHTNESS_1_DIM:
        {
          setBrightnessMode(BRIGHTNESS_2_NOR);
          lightSensor->setEnabled(false);
          Serial.println(F("Changing sys brightness to NORMAL"));
        }
        break;
        case BRIGHTNESS_2_NOR:
        {
          setBrightnessMode(BRIGHTNESS_3_MAX);
          lightSensor->setEnabled(false);
          Serial.println(F("Changing sys brightness to MAX"));

        }
        break;
        case BRIGHTNESS_3_MAX:
        {
          setBrightnessMode(BRIGHTNESS_0_OFF);
          lightSensor->setEnabled(false);
          Serial.println(F("Changing sys brightness to OFFtomatic"));
        }
        break;
      }
    }
    break;
    case BUTTON_TAPPED: //Preset cycle
    {
      switch (currentEffect)
      {
        case 0:
        {
          setAnimation_Atos_0();
          currentEffect++;
        }
        break;
        case 1:
        {
          setAnimation_Atos_1();
          currentEffect++;
        }
        break;
        case 2:
        {
          setAnimation_Atos_2();
          currentEffect++;
        }
        break;
        case 3:
        {
          setAnimation_Atos_3();
          currentEffect++;
        }
        break;
        case 4:
        {
          setAnimation_Atos_4();
          currentEffect = 0;
        }
        break;
      }
    }
  }
  
  //Auto brightness handling
  if (lightSensor->getEnabled())
  {
    lightSensor->tick();
    //if(ledManager->getGoalBrightness() != lightSensor->getRecommendedBrightness())
    ledManager->setGoalBrightness(lightSensor->getRecommendedBrightness());
  }

  //Waking up or Shutting down system from sleep timer
  sleepTimer->tick();
  switch (sleepTimer->getTurn())
  {
    case TURN_OFF:
    {
      Serial.println(F("SleepTimer Turning system off"));
      ledManager->setGoalBrightness(BRIGHTNESS_0_OFF);
    }
    break;

    case TURN_ON:
    {
      Serial.println(F("SleepTimer Turning system on"));
      if(ledManager->getGoalBrightness() == BRIGHTNESS_0_OFF)ledManager->setGoalBrightness(BRIGHTNESS_2_NOR);
    }
    break;
  }

  //Communications handling
  comms->tick();
  switch (comms->getReadyTransmissionType())
  {
    case TRANSMISSION_IN_LEDMANAGER:
    {
      Transmission_LedManager data = comms->getTransmission_LedManager();
      ledManager->setGoalBrightness(data.brightness); 
      ledManager->setSpeed(data.speed); 
    }
    break;
    case TRANSMISSION_IN_PANEL:
    {
      Transmission_Panel data = comms->getTransmission_Panel();
      ledManager->setPanelVfx(data.panelNumber, data.vfxData);
    }
    break;
    case TRANSMISSION_IN_DIODE:
    {
      Transmission_Diode data = comms->getTransmission_Diode();
      ledManager->setPanelDiodeVfx(data.panelNumber, data.diodeNumber, data.vfxData);
    }
    break;
    case TRANSMISSION_IN_CUSTOMPALETTES:
    {
      Transmission_CustomPalette data = comms->getTransmission_CustomPalette();
      for (uint8_t i = 0; i < AMOUNTOFCOLOURS; i++)
      {
        ledManager->setCustomPaletteColours(data.slot, i, *data.customRGB[i]);
      }
    }
    break;
    
    case TRANSMISSION_IN_SLEEPTIMER:
    {
      Transmission_SleepTimer data = comms->getTransmission_SleepTimer();
      switch (data.timerID)
      {
        case TIMERID_OFFTIMER:
        {
          sleepTimer->setTurnOffTime(data.hour, data.minute);
          sleepTimer->setTurnOffEnabled(data.enabled);
        }
        break;
        case TIMERID_ONTIMER:
        {
          sleepTimer->setTurnOnTime(data.hour, data.minute);
          sleepTimer->setTurnOnEnabled(data.enabled);
        }
        break;
      }
    }
    break;
    case TRANSMISSION_IN_LIGHTSENSOR:
    {
      lightSensor->setBrightnessOffset(comms->getTransmission_LightSensorOffset());
    }
    break;
    case TRANSMISSION_IN_REQUEST:
    {
      comms->transmit(ledManager->convertToTansmission());
      for (uint8_t i = 0; i < ledManager->getPanelAmount(); i++)
      {
        comms->transmit(ledManager->convertPanelToTransmission(i));
        #if ENABLE_DIODECONTROL
        for (uint8_t j = 0; j < ledManager->getPanelDiodeAmount(i); j++)
        {
          comms->transmit(ledManager->convertPanelDiodeToTransmission(i,j));
        }
        #endif
      }
    }
    break;
    case TRANSMISSION_IN_IDENT:
    {
      comms->transmit("IDENT");
    }
    break;
  }
}
void Trinity::forceTick(uint16_t ticks, bool keepPrinting, uint16_t delayTime)
{
  for (uint16_t i = 0; i < ticks; i++)
  {
    if(DEBUGLEVEL >=DEBUG_DAYISRUINED) Serial.print(F("T"));
    ledManager->tick();

    if (keepPrinting)
    {
      if(DEBUGLEVEL >=DEBUG_DAYISRUINED) Serial.print(("P"));
      ledManager->print();

      if(delayTime > 0 )
      {
        delay(delayTime);
      }
    }
  }
}


void Trinity::setSpeed(uint8_t speed)
{
  ledManager->setSpeed(speed);
}
void Trinity::setBrightnessMode(uint8_t brightnessMode)
{
  this->brightnessMode = brightnessMode;

  switch (brightnessMode)
  {
    case BRIGHTNESS_0_OFF:
    ledManager->setGoalBrightness(BRIGHTNESS_0_OFF_VAL);
    break;
    case BRIGHTNESS_1_DIM:
    ledManager->setGoalBrightness(BRIGHTNESS_1_DIM_VAL);
    break;
    case BRIGHTNESS_2_NOR:
    ledManager->setGoalBrightness(BRIGHTNESS_2_NOR_VAL);
    break;
    case BRIGHTNESS_3_MAX:
    ledManager->setGoalBrightness(BRIGHTNESS_3_MAX_VAL);
    break;
  }
}
void Trinity::setPanelVfx(uint8_t panelNumber, VFXData vfxData)
{
  ledManager->setPanelVfx(panelNumber, vfxData);
}
uint16_t Trinity::getPanelDiodeAmount(uint8_t panelNumber)
{
  return ledManager->getPanelDiodeAmount(panelNumber);
}
void Trinity::setPanelDiodeVfx(uint8_t panelNumber, uint16_t diodeNumber, VFXData vfxData)
{
  ledManager->setPanelDiodeVfx(panelNumber, diodeNumber, vfxData);
}

void Trinity::setCustomPaletteColours(uint8_t slot, uint8_t colourRGBNumber, ColourRGB colourRGB)
{
  ledManager->setCustomPaletteColours(slot, colourRGBNumber, colourRGB);
}
void Trinity::setCustomPaletteAvailableColours(uint8_t slot, uint8_t avalaibleColours)
{
  ledManager->setCustomPaletteAvailableColours(slot, avalaibleColours);
}

uint8_t Trinity::getPanelAmount()
{
  return ledManager->getPanelAmount();
}


//TEMP
void Trinity::setAnimation_Atos_0() //Special Synth
{
  setSpeed(1);

  for (uint16_t i = 0; i < getPanelAmount(); i++)
  {
    setPanelVfx(i, (VFXData){EFFECT_STOCK_STATIC, COLOUR_BLACK, 0, 1, true});
  }
  forceTick(1, true, 0);

  uint8_t multiplier = 10;
  uint8_t diodesAmount;
  uint16_t offset;
  uint8_t speed = 3;


  //Right panel
  diodesAmount = getPanelDiodeAmount(0);
  offset = diodesAmount*multiplier;
  setPanelVfx(0, (VFXData){EFFECT_SPECIAL_SYNTH, COLOUR_BLACK, 100, 1, true});
  for (uint16_t j = 0; j < getPanelDiodeAmount(0); j++)
  {
    if (j < diodesAmount/2) offset -= multiplier;
    else offset += multiplier;
    setPanelDiodeVfx(0, j, (VFXData){EFFECT_SPECIAL_SYNTH, COLOUR_BLACK, offset, speed, true});
  }

  //Middle panel
  diodesAmount = getPanelDiodeAmount(1);
  offset = diodesAmount*multiplier;
  setPanelVfx(1, (VFXData){EFFECT_SPECIAL_SYNTH, COLOUR_BLACK, 0, 1, true});
  for (uint16_t j = 0; j < getPanelDiodeAmount(1); j++)
  {
    if (j < diodesAmount/2) offset -= multiplier;
    else offset += multiplier;
    setPanelDiodeVfx(1, j, (VFXData){EFFECT_SPECIAL_SYNTH, COLOUR_BLACK, offset, speed, true});
  }

  //Left panel
  diodesAmount = getPanelDiodeAmount(2);
  offset = diodesAmount*multiplier;
  setPanelVfx(2, (VFXData){EFFECT_SPECIAL_SYNTH, COLOUR_BLACK, 100, 1, true});
  for (uint16_t j = 0; j < getPanelDiodeAmount(2); j++)
  {
    if (j < diodesAmount/2) offset -= multiplier;
    else offset += multiplier;
    setPanelDiodeVfx(2, j, (VFXData){EFFECT_SPECIAL_SYNTH, COLOUR_BLACK, offset, speed, true});
  }
}

void Trinity::setAnimation_Atos_1() //Super Rainbow
{

  setSpeed(4);

  uint8_t multiplier = 10;
  uint8_t diodesAmount;
  uint16_t offset;
  uint8_t speed = 15;


  //Right panel
  diodesAmount = getPanelDiodeAmount(0);
  offset = diodesAmount*multiplier;
  setPanelVfx(0, (VFXData){EFFECT_SPECIAL_RAINBOW, COLOUR_BLACK, 50, 1, true});
  for (uint16_t j = 0; j < getPanelDiodeAmount(0); j++)
  {
    if (j < diodesAmount/2) offset -= multiplier;
    else offset += multiplier;
    setPanelDiodeVfx(0, j, (VFXData){EFFECT_SPECIAL_RAINBOW, COLOUR_BLACK, offset, speed, true});
  }

  //Middle panel
  diodesAmount = getPanelDiodeAmount(1);
  offset = diodesAmount*multiplier;
  setPanelVfx(1, (VFXData){EFFECT_SPECIAL_RAINBOW, COLOUR_BLACK, 0, 1, true});
  for (uint16_t j = 0; j < getPanelDiodeAmount(1); j++)
  {
    if (j < diodesAmount/2) offset -= multiplier;
    else offset += multiplier;
    setPanelDiodeVfx(1, j, (VFXData){EFFECT_SPECIAL_RAINBOW, COLOUR_BLACK, offset, speed, true});
  }

  //Left panel
  diodesAmount = getPanelDiodeAmount(2);
  offset = diodesAmount*multiplier;
  setPanelVfx(2, (VFXData){EFFECT_SPECIAL_RAINBOW, COLOUR_BLACK, 50, 1, true});
  for (uint16_t j = 0; j < getPanelDiodeAmount(2); j++)
  {
    if (j < diodesAmount/2) offset -= multiplier;
    else offset += multiplier;
    setPanelDiodeVfx(2, j, (VFXData){EFFECT_SPECIAL_RAINBOW, COLOUR_BLACK, offset, speed, true});
  }
}
void Trinity::setAnimation_Atos_2() //Red Decode
{
  setSpeed(10);
  uint8_t multiplier = 10;
  uint8_t diodesAmount;
  uint16_t offset;
  uint8_t speed = 1;


  //Right panel
  diodesAmount = getPanelDiodeAmount(0);
  offset = diodesAmount*multiplier;
  setPanelVfx(0, (VFXData){EFFECT_STOCK_DECODE, COLOUR_RED, 10, 1, true});
  for (uint16_t j = 0; j < getPanelDiodeAmount(0); j++)
  {
    offset -= multiplier;
    setPanelDiodeVfx(0, j, (VFXData){EFFECT_STOCK_DECODE, COLOUR_RED, offset, speed, true});
  }

  //Middle panel
  diodesAmount = getPanelDiodeAmount(1);
  offset = diodesAmount*multiplier;
  setPanelVfx(1, (VFXData){EFFECT_STOCK_DECODE, COLOUR_RED, 0, 1, true});
  for (uint16_t j = 0; j < getPanelDiodeAmount(1); j++)
  {
    if (j < diodesAmount/2) offset -= multiplier;
    else offset += multiplier;
    setPanelDiodeVfx(1, j, (VFXData){EFFECT_STOCK_DECODE, COLOUR_RED, offset, speed, true});
  }

  //Left panel
  diodesAmount = getPanelDiodeAmount(2);
  offset = 0;
  setPanelVfx(2, (VFXData){EFFECT_STOCK_DECODE, COLOUR_RED, 10, 1, true});
  for (uint16_t j = 0; j < getPanelDiodeAmount(2); j++)
  {
    offset += multiplier;
    setPanelDiodeVfx(2, j, (VFXData){EFFECT_STOCK_DECODE, COLOUR_RED, offset, speed, true});
  }
}
void Trinity::setAnimation_Atos_3() //Static Cool
{
  setSpeed(1);

  setPanelVfx(0, (VFXData){EFFECT_STOCK_STATIC, COLOUR_RED,  0, 1, true});
  setPanelVfx(1, (VFXData){EFFECT_STOCK_STATIC, COLOUR_BLUE, 0, 1, true});
  setPanelVfx(2, (VFXData){EFFECT_STOCK_STATIC, COLOUR_RED,  0, 1, true});

}
void Trinity::setAnimation_Atos_4() //Static white
{
  setSpeed(1);

  for (uint16_t i = 0; i < getPanelAmount(); i++)
  {
    setPanelVfx(i, (VFXData){EFFECT_STOCK_STATIC, COLOUR_WHITE, 0, 1, true});
  }
}