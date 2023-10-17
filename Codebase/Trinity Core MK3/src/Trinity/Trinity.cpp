#include "Trinity.h"



//Constructor
Trinity::Trinity(uint8_t ledPin, uint8_t buttonPin, uint8_t ldrPin, uint8_t maxFramerate)
{
  Serial.begin(115200);
  Serial.println(F("Trinity MK3 - Ask Blommaert"));

  setupPanels();
  ledManager      = new LedManager(panels); //Todo: Made LedManager accept const ints
  button          = new AskButton(buttonPin, 100);
  lightSensor     = new LightSensor(ldrPin);
  sleepTimer      = new SleepTimer();
  comms           = new Comms();

  prevFrameMillis = 0;
  frameTime = 1000/maxFramerate;

  Serial.print(F("...Trinity Initialised with frame time of: "));
  Serial.println(frameTime);

  /*
  sleepTimer->setTurnOnEnabled(true);
  sleepTimer->setTurnOnTime(10,0);
  sleepTimer->setTurnOffEnabled(true);
  sleepTimer->setTurnOffTime(9,59);
  */

  Serial.println(F("...Trinity Started"));
  
  /*
  //Basic effect
  for (uint8_t i = 0; i < PANELAMOUNT; i++)
  {
    for (uint8_t j = 0; j < panels[i]->getDiodeAmount(); j++)
    {
      panels[i]->setDiodeVfx(j, VFXData{EFFECT_STOCK_PLANE, COLOUR_RED, 0, 1, true});
    }
  }
  */

  Serial.println(F("...Trinity Setup complete"));
}

//Private
void Trinity::setupPanels()
{
  Serial.println(F("Allocatig..."));
  panels = (Panel**)malloc(sizeof(Panel*) * PANELAMOUNT);
  Serial.println(F("Array allocated..."));

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
  panels[0] = new Panel(0, CLOCK_COUNTERWISE, COMPASS_SOUTH_EAST, LEDSAMOUNT_TRIANGLE);
  panels[1] = new Panel(1, CLOCK_COUNTERWISE, COMPASS_SOUTH,      LEDSAMOUNT_TRIANGLE);
  panels[2] = new Panel(2, CLOCK_COUNTERWISE, COMPASS_SOUTH_WEST, LEDSAMOUNT_TRIANGLE);
  panels[3] = new Panel(3, CLOCK_CLOCKWISE,   COMPASS_NORTH_EAST, LEDSAMOUNT_TRIANGLE);
  panels[4] = new Panel(4, CLOCK_CLOCKWISE,   COMPASS_NORTH,      LEDSAMOUNT_TRIANGLE);
  panels[5] = new Panel(5, CLOCK_CLOCKWISE,   COMPASS_NORTH_WEST, LEDSAMOUNT_TRIANGLE);
  panels[6] = new Panel(6, CLOCK_COUNTERWISE, COMPASS_SOUTH_WEST, LEDSAMOUNT_TRIANGLE);
  panels[7] = new Panel(7, CLOCK_CLOCKWISE,   COMPASS_NORTH_EAST, LEDSAMOUNT_TRIANGLE);
  panels[8] = new Panel(8, CLOCK_CLOCKWISE,   COMPASS_NORTH,      LEDSAMOUNT_TRIANGLE);
  panels[9] = new Panel(9, CLOCK_CLOCKWISE,   COMPASS_NORTH_WEST, LEDSAMOUNT_TRIANGLE);
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
  #ifdef PANELSETUP_TEST
  panels[0] = new Panel(0, CLOCK_COUNTERWISE, COMPASS_SOUTH_EAST, 3);
  panels[1] = new Panel(1, CLOCK_COUNTERWISE, COMPASS_SOUTH,      3);
  panels[2] = new Panel(2, CLOCK_COUNTERWISE, COMPASS_SOUTH_WEST, 3);
  panels[3] = new Panel(3, CLOCK_CLOCKWISE,   COMPASS_NORTH_EAST, 3);
  panels[4] = new Panel(4, CLOCK_CLOCKWISE,   COMPASS_NORTH,      3);
  panels[5] = new Panel(5, CLOCK_CLOCKWISE,   COMPASS_NORTH_WEST, 3);
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
    case TRANSMISSION_IN_PANELFX:
    {
      //Serial.println("Panel transmission retrieved from comms");
      Transmission_PanelFX data = comms->getTransmission_PanelFX();
      //Serial.println("Yom");
      ledManager->setPanelVfx(data.panelNumber, data.vfxData);
      //Serial.println("Done");
    }
    break;
    case TRANSMISSION_IN_PANELCUSTOM:
    {

    }
    break;
    case TRANSMISSION_IN_DIODEFX:
    {
      //Serial.println("Panel transmission retrieved from comms");
      Transmission_DiodeFX data = comms->getTransmission_DiodeFX();
      //Serial.println("Yom");
      ledManager->setPanelDiodeVfx(data.panelNumber, data.diodeNumber, data.vfxData);
      //Serial.println("Done");
    }
    break;
    case TRANSMISSION_IN_DIODECUSTOM:
    {

    }
    break;
    case TRANSMISSION_IN_BRIGHTNESS:
    {
      ledManager->setBrightness(comms->getTransmission_Brightness());
    }
    break;
    case TRANSMISSION_IN_SLEEPTIMER:
    {
      Transmission_SleepTimerData data = comms->getTransmission_SleepTimerData();
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
      Transmission_LightSensorData data = comms->getTransmission_LightSensorData();
      lightSensor->setBrightnessOffset(data.offset);
      lightSensor->setEnabled(data.enabled);
    }
    break;
    case TRANSMISSION_IN_REQUEST:
    {
      comms->transmit(TRANSMISSION_OUT_LEDMANAGER, ledManager->convertToTansmission());

      for (uint8_t i = 0; i < ledManager->getPanelAmount(); i++)
      {
        
        comms->transmit(TRANSMISSION_OUT_PANEL, ledManager->convertPanelToTransmission(i));
        
        for (uint8_t j = 0; j < ledManager->getPanelDiodeAmount(i); j++)
        {
          comms->transmit(TRANSMISSION_OUT_DIODE, ledManager->convertPanelDiodeToTransmission(i,j));
        }
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
  panels[panelNumber]->setVfx(vfxData);
}
uint16_t Trinity::getPanelDiodeAmount(uint8_t panelNumber)
{
  return panels[panelNumber]->getDiodeAmount();
}
void Trinity::setPanelDiodeVfx(uint8_t panelNumber, uint16_t diodeNumber, VFXData vfxData)
{
  if (panelNumber >= sizeof(panels))
  {
    Serial.print(F("Trinity::setPanelDiodeVfx() Too high panel number requested: "));
    Serial.print(panelNumber);
    Serial.print(F(". Max: "));
    Serial.println(panelNumber);
  }
  
  panels[panelNumber]->setDiodeVfx(diodeNumber, vfxData);
}

