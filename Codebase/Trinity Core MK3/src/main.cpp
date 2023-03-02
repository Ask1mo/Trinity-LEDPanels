#include "main.h"

void setupPanels()
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
  panels[ 0] = new Panel( 0, CLOCK_COUNTERWISE, COMPASS_SOUTH_EAST, LEDSAMOUNT_TRIANGLE);
  panels[ 1] = new Panel( 1, CLOCK_COUNTERWISE, COMPASS_SOUTH,      LEDSAMOUNT_TRIANGLE);
  panels[ 2] = new Panel( 2, CLOCK_COUNTERWISE, COMPASS_SOUTH_WEST, LEDSAMOUNT_TRIANGLE);
  panels[ 3] = new Panel( 3, CLOCK_CLOCKWISE,   COMPASS_NORTH_EAST, LEDSAMOUNT_TRIANGLE);
  panels[ 4] = new Panel( 4, CLOCK_CLOCKWISE,   COMPASS_NORTH,      LEDSAMOUNT_TRIANGLE);
  panels[ 5] = new Panel( 5, CLOCK_CLOCKWISE,   COMPASS_NORTH_WEST, LEDSAMOUNT_TRIANGLE);
  panels[ 6] = new Panel( 6, CLOCK_COUNTERWISE, COMPASS_SOUTH_WEST, LEDSAMOUNT_TRIANGLE);
  panels[ 7] = new Panel( 7, CLOCK_CLOCKWISE,   COMPASS_NORTH_EAST, LEDSAMOUNT_TRIANGLE);
  panels[ 8] = new Panel( 8, CLOCK_CLOCKWISE,   COMPASS_NORTH,      LEDSAMOUNT_TRIANGLE);
  panels[ 9] = new Panel( 9, CLOCK_CLOCKWISE,   COMPASS_NORTH_WEST, LEDSAMOUNT_TRIANGLE);
  panels[10] = new Panel(10, CLOCK_CLOCKWISE,   COMPASS_NORTH,      LEDSAMOUNT_TRIANGLE);
  panels[11] = new Panel(11, CLOCK_CLOCKWISE,   COMPASS_NORTH_WEST, LEDSAMOUNT_TRIANGLE);
  panels[12] = new Panel(12, CLOCK_COUNTERWISE, COMPASS_SOUTH_WEST, LEDSAMOUNT_TRIANGLE);
  panels[13] = new Panel(13, CLOCK_CLOCKWISE,   COMPASS_NORTH_EAST, LEDSAMOUNT_TRIANGLE);
  panels[14] = new Panel(14, CLOCK_CLOCKWISE,   COMPASS_NORTH,      LEDSAMOUNT_TRIANGLE);
  panels[15] = new Panel(15, CLOCK_CLOCKWISE,   COMPASS_NORTH_WEST, LEDSAMOUNT_TRIANGLE);
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

void setup()
{
  Serial.begin(9600);
  Serial.println(F("Trinity MK3 - Ask Blommaert"));

  setupPanels();
  ledManager      = new LedManager(panels);
  button          = new AskButton(PIN_BUTTON, 1000);
  lightSensor     = new LightSensor(PIN_LIGHTSENSOR);
  sleepTimer      = new SleepTimer();
  //comms           = new Comms();

  Serial.println(F("...Trinity Initialised"));

  ledManager->setBrightness(255);

  Serial.println(F("...Trinity Started"));


  /*
  //TEMP: Do some editing of the panel data 
  for (uint8_t i = 0; i < PANELAMOUNT; i++)
  {
    ledManager->setPanelData(i, DIR_STRIP, 255, EFFECT_RAINBOW, COLOUR_BLACK, i*5, 3, true);
  }
  */
  

  //Temp
  for (uint8_t i = 0; i < PANELAMOUNT; i++)
  {
    for (uint8_t j = 0; j < panels[i]->getDiodeAmount(); j++)
    {
      panels[i]->setDiodeDataFx(j, DIR_STRIP, 255, EFFECT_RAINBOW, COLOUR_BLACK, i*j*5, 1, true);
    }
  }

  sleepTimer->setTurnOnEnabled(true);
  sleepTimer->setTurnOnTime(10,0);

  sleepTimer->setTurnOffEnabled(true);
  sleepTimer->setTurnOffTime(9,59);

  Serial.println(F("---===SETUP COMPLETED===---"));
}
void loop()
{
  delay(10);

  sleepTimer->printTime();
  
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

  //Waking up / Shutting down system from sleep timer
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

  //comms->tick();

  ledManager->tick();
  ledManager->print();
}


