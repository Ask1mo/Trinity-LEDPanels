#include "Trinity.h"

Trinity::Trinity()
{
  Serial.println(F("Trinity Starting..."));

  uint8_t panelsAmount = setupPanels_Test();

  Serial.println(F("Panels Initialised, starting"));

  ledManager    = new LedManager(panels, panelsAmount);
  button        = new AskButton(PIN_BUTTON, BUTTON_LONGPRESSDURATION);
  lightSensor   = new LightSensor(PIN_LIGHTSENSOR);
  sleepTimer    = new SleepTimer();
  comms         = new Comms();

  Serial.println(F("Setup Finished"));

  Serial.println(F("...Trinity Started"));
  Serial.println(F("---===STARTUP COMPLETED===---"));
  Serial.println();

  //TEMP: Do some editing of the panel data 
  for (uint8_t i = 0; i < panelsAmount; i++)
  {
    ledManager->setPanelData(i, DIR_STRIP, 255, EFFECT_RAINBOW, COLOUR_BLACK, i*5, 3, true);
  }
}

uint8_t Trinity::setupPanels_Test()
{
  Serial.println(F("Allocatig..."));

  panels = (Panel**)malloc(sizeof(Panel*) * PANELSETUP_TEST_AMOUNT);

  Serial.println(F("Array allocated..."));
  
  panels[0] = new Panel( 0, CLOCK_COUNTERWISE, COMPASS_SOUTH_EAST, LEDSAMOUNT_TRIANGLE);
  panels[1] = new Panel( 1, CLOCK_COUNTERWISE, COMPASS_SOUTH,      LEDSAMOUNT_TRIANGLE);
  panels[2] = new Panel( 2, CLOCK_COUNTERWISE, COMPASS_SOUTH_WEST, LEDSAMOUNT_TRIANGLE);
  panels[3] = new Panel( 3, CLOCK_CLOCKWISE,   COMPASS_NORTH_EAST, LEDSAMOUNT_TRIANGLE);
  panels[4] = new Panel( 4, CLOCK_CLOCKWISE,   COMPASS_NORTH,      LEDSAMOUNT_TRIANGLE);
  panels[5] = new Panel( 5, CLOCK_CLOCKWISE,   COMPASS_NORTH_WEST, LEDSAMOUNT_TRIANGLE);
  
  Serial.println(F("Allocating complete"));
  
  return PANELSETUP_TEST_AMOUNT;
}

void Trinity::tick()
{
  /*
  //Button press handling: Tap (Brightness cycle)
  if(button->getCommand() == BUTTON_TAPPED)
  {
    brightnessLevel++;
    if(brightnessLevel == BRIGHTNESSLEVELS)
    {
      brightnessLevel = 0;
    }

    switch (brightnessLevel)
    {
      case 0:
      {
        ledManager->setEnabled(false);
        ledManager->setBrightness(BRIGHTNESS_0_OFF);
        lightSensor->setEnabled(false);
      }
      break;
      case 1:
      {
        ledManager->setEnabled(true);
        ledManager->setBrightness(BRIGHTNESS_1_MIN);
        lightSensor->setEnabled(false);
      }
      break;
      case 2:
      {
        ledManager->setEnabled(true);
        ledManager->setBrightness(BRIGHTNESS_2_DIM);
        lightSensor->setEnabled(false);
      }
      break;
      case 3:
      {
        ledManager->setEnabled(true);
        ledManager->setBrightness(BRIGHTNESS_3_NOR);
        lightSensor->setEnabled(false);
      }
      break;
      case 4:
      {
        ledManager->setEnabled(true);
        ledManager->setBrightness(BRIGHTNESS_4_MAX);
        lightSensor->setEnabled(false);
      }
      break;
      case 5:
      {
        ledManager->setEnabled(true);
        ledManager->setBrightness(BRIGHTNESS_5_AUT);
        lightSensor->setEnabled(true);
      }
      break;
    }


    ledManager->setBrightness(255);
  }

  //Button press handling: Long (Preset cycle)
  if(button->getCommand() == BUTTON_HELD)
  {
    Serial.println(F("Preset loading not implemented"));
  }

  //Auto brightness handling
  if (lightSensor->getEnabled())
  {
    lightSensor->tick();
    ledManager->setBrightness(lightSensor->getInstruction_Brightness());
  }

  //Waking up / Shutting down system from sleep timer
  sleepTimer->tick();
  switch (sleepTimer->getTurn())
  {
    case TURN_OFF:
    ledManager->setEnabled(false);
    break;

    case TURN_ON:
    ledManager->setEnabled(true);
    if(ledManager->getBrightness() == BRIGHTNESS_0_OFF)
    {
      ledManager->setBrightness(BRIGHTNESS_3_NOR);
    }
    break;
  }
*/
  comms->tick();

  ledManager->tick();
  ledManager->print();
  
}