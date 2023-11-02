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

  ledManager      = new LedManager(); //Todo: Made LedManager accept const ints
  button          = new AskButton(buttonPin, 100);
  lightSensor     = new LightSensor(ldrPin);
  sleepTimer      = new SleepTimer();
  comms           = new Comms();

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
void Trinity::finaliseSetup()
{
  ledManager->finaliseSetup();
  Serial.println(F("...Trinity Setup Finalised"));
}
//Private

//Public
void Trinity::tick()
{
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
    case BUTTON_TAPPED: //Brightness cycle
    {
      switch (ledManager->getBrightness())
      {
        case BRIGHTNESS_0_OFF:
        {
          ledManager->setEnabled(true);
          ledManager->setBrightness(BRIGHTNESS_1_DIM);
          lightSensor->setEnabled(false);
          Serial.println(F("Changing sys brightness to DIM"));
        }
        break;
        case BRIGHTNESS_1_DIM:
        {
          ledManager->setEnabled(true);
          ledManager->setBrightness(BRIGHTNESS_2_NOR);
          lightSensor->setEnabled(false);
          Serial.println(F("Changing sys brightness to NORMAL"));
        }
        break;
        case BRIGHTNESS_2_NOR:
        {
          ledManager->setEnabled(true);
          ledManager->setBrightness(BRIGHTNESS_3_MAX);
          lightSensor->setEnabled(false);
          Serial.println(F("Changing sys brightness to MAX"));

        }
        break;
        case BRIGHTNESS_3_MAX:
        {
          ledManager->setEnabled(true);
          ledManager->setBrightness(BRIGHTNESS_4_AUT);
          lightSensor->setEnabled(true);
          Serial.println(F("Changing sys brightness to Automatic"));
        }
        break;
        default:
        {
          ledManager->setEnabled(true);
          ledManager->setBrightness(BRIGHTNESS_0_OFF);
          lightSensor->setEnabled(false);
          Serial.println(F("Changing sys brightness to OFF"));
        }
        break;
      }
    }
    break;
    case BUTTON_HELD: //Preset cycle
    {
      Serial.println(F("Preset loading not implemented"));
    }
  }
  
  //Auto brightness handling
  if (lightSensor->getEnabled())
  {
    lightSensor->tick();
    if(ledManager->getBrightness() != lightSensor->getRecommendedBrightness())
    ledManager->setBrightness(lightSensor->getRecommendedBrightness());
  }

  //Waking up or Shutting down system from sleep timer
  sleepTimer->tick();
  switch (sleepTimer->getTurn())
  {
    case TURN_OFF:
    {
      Serial.println(F("SleepTimer Turning system off"));
      ledManager->setBrightness(BRIGHTNESS_0_OFF);
    }
    break;

    case TURN_ON:
    {
      Serial.println(F("SleepTimer Turning system on"));
      if(ledManager->getBrightness() == BRIGHTNESS_0_OFF)ledManager->setBrightness(BRIGHTNESS_2_NOR);
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
      ledManager->setBrightness(data.brightness); 
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
      comms->transmit(TRANSMISSION_OUT_LEDMANAGER, ledManager->convertToTansmission());

      for (uint8_t i = 0; i < ledManager->getPanelAmount(); i++)
      {
        
        comms->transmit(TRANSMISSION_OUT_PANEL, ledManager->convertPanelToTransmission(i));

        #if ENABLE_DIODECONTROL
        for (uint8_t j = 0; j < ledManager->getPanelDiodeAmount(i); j++)
        {
          comms->transmit(TRANSMISSION_OUT_DIODE, ledManager->convertPanelDiodeToTransmission(i,j));
        }
        #endif
      }
    }
    break;
    case TRANSMISSION_IN_IDENT:
    {
      comms->transmit(TRANSMISSION_OUT_IDENT, "");
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
void Trinity::setBrightness(uint8_t brightness)
{
  ledManager->setBrightness(brightness);
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
  if (panelNumber > ledManager->getPanelAmount())
  {
    Serial.print(F("Trinity::setPanelDiodeVfx() Too high panel number requested: "));
    Serial.print(panelNumber);
    Serial.print(F(". Max: "));
    Serial.println(ledManager->getPanelAmount());
  }
  
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