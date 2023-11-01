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

 setupPanels();

  Serial.println(F("...Trinity Started"));
}

//Private
void Trinity::setupPanels()
{
  
  /*
  #ifdef PANELSETUP_PROTO
  panels[0] = new Panel(0, 0, 0, CLOCK_CLOCKWISE, COMPASS_NORTH, LEDSAMOUNT_TRIANGLE);
  panels[1] = new Panel(1, 1, 0, CLOCK_CLOCKWISE, COMPASS_NORTH, LEDSAMOUNT_TRIANGLE);
  panels[2] = new Panel(2, 2, 0, CLOCK_CLOCKWISE, COMPASS_NORTH, LEDSAMOUNT_TRIANGLE);
  panels[3] = new Panel(3, 3, 0, CLOCK_CLOCKWISE, COMPASS_NORTH, LEDSAMOUNT_TRIANGLE);
  panels[4] = new Panel(4, 4, 0, CLOCK_CLOCKWISE, COMPASS_NORTH, LEDSAMOUNT_TRIANGLE);
  panels[5] = new Panel(5, 5, 0, CLOCK_CLOCKWISE, COMPASS_NORTH, LEDSAMOUNT_TRIANGLE);
  #endif
  */
  #ifdef PANELSETUP_PROTO
  ledManager->addPanel(new Panel(0, 0, 0, CLOCK_CLOCKWISE, COMPASS_NORTH, LEDSAMOUNT_TRIANGLE));
  ledManager->addPanel(new Panel(1, 1, 0, CLOCK_CLOCKWISE, COMPASS_NORTH, LEDSAMOUNT_TRIANGLE));
  ledManager->addPanel(new Panel(2, 2, 0, CLOCK_CLOCKWISE, COMPASS_NORTH, LEDSAMOUNT_TRIANGLE));
  ledManager->addPanel(new Panel(3, 3, 0, CLOCK_CLOCKWISE, COMPASS_NORTH, LEDSAMOUNT_TRIANGLE));
  ledManager->addPanel(new Panel(4, 4, 0, CLOCK_CLOCKWISE, COMPASS_NORTH, LEDSAMOUNT_TRIANGLE));
  ledManager->addPanel(new Panel(5, 5, 0, CLOCK_CLOCKWISE, COMPASS_NORTH, LEDSAMOUNT_TRIANGLE));
  #endif
  #ifdef PANELSETUP_ATOS
  panels[0] = new Panel(0, CLOCK_COUNTERWISE, COMPASS_WEST, LEDAMOUNT);
  #endif
  #ifdef PANELSETUP_EVA
  panels[0] = new Panel(0, CLOCK_COUNTERWISE, COMPASS_SOUTH_EAST, LEDSAMOUNT_TRIANGLE);
  panels[1] = new Panel(1, CLOCK_COUNTERWISE, COMPASS_SOUTH,      LEDSAMOUNT_TRIANGLE);
  panels[2] = new Panel(2, CLOCK_COUNTERWISE, COMPASS_SOUTH_WEST, LEDSAMOUNT_TRIANGLE);
  panels[3] = new Panel(3, CLOCK_CLOCKWISE,   COMPASS_NORTH_EAST, LEDSAMOUNT_TRIANGLE);
  #endif
  #ifdef PANELSETUP_LIAM
  panels[0] = new Panel(0, 0, 0, CLOCK_COUNTERWISE, COMPASS_SOUTH_EAST, LEDSAMOUNT_TRIANGLE);
  panels[1] = new Panel(1, 0, 0, CLOCK_COUNTERWISE, COMPASS_SOUTH,      LEDSAMOUNT_TRIANGLE);
  panels[2] = new Panel(2, 0, 0, CLOCK_COUNTERWISE, COMPASS_SOUTH_WEST, LEDSAMOUNT_TRIANGLE);
  panels[3] = new Panel(3, 0, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH_EAST, LEDSAMOUNT_TRIANGLE);
  panels[4] = new Panel(4, 0, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH,      LEDSAMOUNT_TRIANGLE);
  panels[5] = new Panel(5, 0, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH_WEST, LEDSAMOUNT_TRIANGLE);
  panels[6] = new Panel(6, 0, 0, CLOCK_COUNTERWISE, COMPASS_SOUTH_WEST, LEDSAMOUNT_TRIANGLE);
  panels[7] = new Panel(7, 0, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH_EAST, LEDSAMOUNT_TRIANGLE);
  panels[8] = new Panel(8, 0, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH,      LEDSAMOUNT_TRIANGLE);
  panels[9] = new Panel(9, 0, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH_WEST, LEDSAMOUNT_TRIANGLE);
  #endif
  #ifdef PANELSETUP_PRIME
  panels[ 0] = new Panel( 0, 0, 3, CLOCK_COUNTERWISE, COMPASS_SOUTH_EAST, LEDSAMOUNT_TRIANGLE);
  panels[ 1] = new Panel( 1, 1, 3, CLOCK_COUNTERWISE, COMPASS_SOUTH,      LEDSAMOUNT_TRIANGLE);
  panels[ 2] = new Panel( 2, 2, 3, CLOCK_COUNTERWISE, COMPASS_SOUTH_WEST, LEDSAMOUNT_TRIANGLE);
  panels[ 3] = new Panel( 3, 3, 3, CLOCK_CLOCKWISE,   COMPASS_NORTH_EAST, LEDSAMOUNT_TRIANGLE);
  panels[ 4] = new Panel( 4, 4, 3, CLOCK_CLOCKWISE,   COMPASS_NORTH,      LEDSAMOUNT_TRIANGLE);
  panels[ 5] = new Panel( 5, 5, 3, CLOCK_CLOCKWISE,   COMPASS_NORTH_WEST, LEDSAMOUNT_TRIANGLE);
  panels[ 6] = new Panel( 6, 6, 3, CLOCK_COUNTERWISE, COMPASS_SOUTH_WEST, LEDSAMOUNT_TRIANGLE);
  panels[ 7] = new Panel( 7, 5, 2, CLOCK_CLOCKWISE,   COMPASS_NORTH_EAST, LEDSAMOUNT_TRIANGLE);
  panels[ 8] = new Panel( 8, 5, 2, CLOCK_CLOCKWISE,   COMPASS_NORTH,      LEDSAMOUNT_TRIANGLE);
  panels[ 9] = new Panel( 9, 0, 1, CLOCK_CLOCKWISE,   COMPASS_NORTH_WEST, LEDSAMOUNT_TRIANGLE);
  panels[10] = new Panel(10, 0, 1, CLOCK_CLOCKWISE,   COMPASS_NORTH,      LEDSAMOUNT_TRIANGLE);
  panels[11] = new Panel(11, 0, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH_WEST, LEDSAMOUNT_TRIANGLE);
  panels[12] = new Panel(12, 0, 1, CLOCK_COUNTERWISE, COMPASS_SOUTH_WEST, LEDSAMOUNT_TRIANGLE);
  panels[13] = new Panel(13, 0, 2, CLOCK_CLOCKWISE,   COMPASS_NORTH_EAST, LEDSAMOUNT_TRIANGLE);
  panels[14] = new Panel(14, 0, 2, CLOCK_CLOCKWISE,   COMPASS_NORTH,      LEDSAMOUNT_TRIANGLE);
  panels[15] = new Panel(15, 0, 2, CLOCK_CLOCKWISE,   COMPASS_NORTH_WEST, LEDSAMOUNT_TRIANGLE);
  #endif
  #ifdef PANELSETUP_CHRISTMAS
  panels[0] = new Panel(0, 0, 0, CLOCK_CLOCKWISE,   COMPASS_SOUTH_EAST, 5);
  panels[1] = new Panel(1, 0, 0, CLOCK_CLOCKWISE,   COMPASS_SOUTH,      5);
  panels[2] = new Panel(2, 0, 0, CLOCK_CLOCKWISE,   COMPASS_SOUTH_WEST, 5);
  panels[3] = new Panel(3, 0, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH_EAST, 5);
  panels[4] = new Panel(4, 0, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH,      5);
  panels[5] = new Panel(5, 0, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH_WEST, 5);
  panels[6] = new Panel(6, 0, 0, CLOCK_CLOCKWISE,   COMPASS_SOUTH_EAST, 5);
  panels[7] = new Panel(7, 0, 0, CLOCK_CLOCKWISE,   COMPASS_SOUTH,      5);
  panels[8] = new Panel(8, 0, 0, CLOCK_CLOCKWISE,   COMPASS_SOUTH_WEST, 5);
  panels[9] = new Panel(9, 0, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH_EAST, 5);
  #endif
  #ifdef PANELSETUP_WESTPOINT
  //Tower Base
  panels[ 0] = new Panel( 0, CLOCK_CLOCKWISE,   COMPASS_NORTH,      10);
  panels[ 1] = new Panel( 1, CLOCK_CLOCKWISE,   COMPASS_NORTH,      11);
  panels[ 2] = new Panel( 2, CLOCK_CLOCKWISE,   COMPASS_NORTH,      10);
  panels[ 3] = new Panel( 3, CLOCK_CLOCKWISE,   COMPASS_NORTH,      11);
  panels[ 4] = new Panel( 4, CLOCK_CLOCKWISE,   COMPASS_NORTH,      10);
  panels[ 5] = new Panel( 5, CLOCK_CLOCKWISE,   COMPASS_NORTH,      10);
  panels[ 6] = new Panel( 6, CLOCK_CLOCKWISE,   COMPASS_NORTH,      11);
  panels[ 7] = new Panel( 7, CLOCK_CLOCKWISE,   COMPASS_NORTH,      10);
  panels[ 8] = new Panel( 8, CLOCK_CLOCKWISE,   COMPASS_NORTH,      10);
  panels[ 9] = new Panel( 9, CLOCK_CLOCKWISE,   COMPASS_NORTH,      10);
  panels[10] = new Panel(10, CLOCK_CLOCKWISE,   COMPASS_NORTH,      11);
  panels[11] = new Panel(11, CLOCK_CLOCKWISE,   COMPASS_NORTH,      10);
  panels[12] = new Panel(12, CLOCK_CLOCKWISE,   COMPASS_NORTH,      11);
  panels[13] = new Panel(13, CLOCK_CLOCKWISE,   COMPASS_NORTH,      10);
  panels[14] = new Panel(14, CLOCK_CLOCKWISE,   COMPASS_NORTH,      9);
  //Tower Top
  panels[15] = new Panel(15, CLOCK_CLOCKWISE,   COMPASS_NORTH,      10);
  panels[16] = new Panel(16, CLOCK_CLOCKWISE,   COMPASS_NORTH,      11);
  panels[17] = new Panel(17, CLOCK_CLOCKWISE,   COMPASS_NORTH,      10);
  panels[18] = new Panel(18, CLOCK_CLOCKWISE,   COMPASS_NORTH,      10);
  panels[19] = new Panel(19, CLOCK_CLOCKWISE,   COMPASS_NORTH,      10);
  panels[20] = new Panel(20, CLOCK_CLOCKWISE,   COMPASS_NORTH,      10);
  panels[21] = new Panel(21, CLOCK_CLOCKWISE,   COMPASS_NORTH,      11);
  panels[22] = new Panel(22, CLOCK_CLOCKWISE,   COMPASS_NORTH,      10);
  panels[23] = new Panel(23, CLOCK_CLOCKWISE,   COMPASS_NORTH,      10);
  panels[24] = new Panel(24, CLOCK_CLOCKWISE,   COMPASS_NORTH,      11);
  panels[25] = new Panel(25, CLOCK_CLOCKWISE,   COMPASS_NORTH,      10);
  panels[26] = new Panel(26, CLOCK_CLOCKWISE,   COMPASS_NORTH,      11);
  panels[27] = new Panel(27, CLOCK_CLOCKWISE,   COMPASS_NORTH,      10);
  panels[28] = new Panel(28, CLOCK_CLOCKWISE,   COMPASS_NORTH,      12);
  //Rigns
  panels[29] = new Panel(29, CLOCK_CLOCKWISE,   COMPASS_NORTH,      37);
  panels[30] = new Panel(30, CLOCK_CLOCKWISE,   COMPASS_NORTH,      37);
  panels[31] = new Panel(31, CLOCK_CLOCKWISE,   COMPASS_NORTH,      37);
  panels[32] = new Panel(32, CLOCK_CLOCKWISE,   COMPASS_NORTH,      37);
  #endif
  #ifdef PANELSETUP_MINITOWER
  panels[ 0] = new Panel( 0, 0, 0, CLOCK_COUNTERWISE, COMPASS_SOUTH_EAST, 10);
  panels[ 1] = new Panel( 1, 0, 0, CLOCK_COUNTERWISE, COMPASS_SOUTH,      10);
  panels[ 2] = new Panel( 2, 0, 0, CLOCK_COUNTERWISE, COMPASS_SOUTH_WEST, 10);
  panels[ 3] = new Panel( 3, 0, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH_EAST, 10);
  panels[ 4] = new Panel( 4, 0, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH,      6);
  #endif
  #ifdef PANELSETUP_TEST
  panels[0] = new Panel(0, CLOCK_COUNTERWISE, COMPASS_SOUTH_EAST, 3);
  panels[1] = new Panel(1, CLOCK_COUNTERWISE, COMPASS_SOUTH,      3);
  panels[2] = new Panel(2, CLOCK_COUNTERWISE, COMPASS_SOUTH_WEST, 3);
  panels[3] = new Panel(3, CLOCK_CLOCKWISE,   COMPASS_NORTH_EAST, 3);
  panels[4] = new Panel(4, CLOCK_CLOCKWISE,   COMPASS_NORTH,      3);
  panels[5] = new Panel(5, CLOCK_CLOCKWISE,   COMPASS_NORTH_WEST, 3);
  #endif

  Serial.println(F("Allocating complete"));
  return;
}

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