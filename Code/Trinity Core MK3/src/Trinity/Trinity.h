#ifndef TRINITY_H
#define TRINITY_H

#include "LedManager/ledManager.h"
#include "ControlPanel/AskButton/AskButton.h"
#include "ControlPanel/LightSensor/LightSensor.h"
#include "ControlPanel/SleepTimer/SleepTimer.h"
//#include "ControlPanel/Comms/Comms.h"
#include "PinMapping.h"

#define PANELSETUP_TEST_AMOUNT  6
#define PANELSETUP_PRIME_AMOUNT 16
#define PANELSETUP_ATOS_AMOUNT  1
#define PANELSETUP_EVA_AMOUNT   4
#define PANELSETUP_LIAM_AMOUNT  10


#define BRIGHTNESSLEVELS 6
#define BRIGHTNESS_0_OFF 0
#define BRIGHTNESS_1_MIN 10
#define BRIGHTNESS_2_DIM 50
#define BRIGHTNESS_3_NOR 100
#define BRIGHTNESS_4_MAX 255
#define BRIGHTNESS_5_AUT 100

#define BUTTON_LONGPRESSDURATION 1000


class Trinity
{
private:
  Panel **panels;
  LedManager    *ledManager;
  AskButton     *button;
  LightSensor   *lightSensor;
  SleepTimer    *sleepTimer;
  //Comms         *comms;

  uint8_t brightnessLevel;
  uint8_t setupPanels_Test();
  uint8_t setupPanels_Atos();

public:
  Trinity();
  void tick();
};



#endif