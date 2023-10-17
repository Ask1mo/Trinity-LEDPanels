#ifndef TRINITY_H
#define TRINITY_H

#include <Wire.h>
#include "setup.h"
#include "Shared.h"
#include "LedManager/ledManager.h"
#include "ControlPanel/AskButton/AskButton.h"
#include "ControlPanel/LightSensor/LightSensor.h"
//#include "ControlPanel/SleepTimer/SleepTimer.h"
#include "ControlPanel/Comms/Comms.h"

#define BRIGHTNESS_0_OFF 1
#define BRIGHTNESS_1_DIM 10
#define BRIGHTNESS_2_NOR 100
#define BRIGHTNESS_3_MAX 255
#define BRIGHTNESS_4_AUT 99

#define ENABLERINGS true
#define STARTCYCLING true

#define SCREENSAVERTIME 180000
#define CELEBRATETIME 10000
#define NEXTEFFECTTIME 30000
#define SENSORPOLLTIME 250
#define SENSORTRIGGERPERCENTAGE 10

Panel         **panels;
LedManager    *ledManager;
AskButton     *button;
LightSensor   *lightSensor;
Comms         *comms;

uint64_t prevMillis;
uint64_t prevSensorMillis;
uint64_t prevCelebrateTime;
uint64_t prevAntiScreensaverTime;
uint16_t sensorAHits;
uint16_t sensorBHits;
uint16_t sensorCHits;
uint16_t sensorDHits;
uint16_t sensorPolls;
uint8_t receivedCode;
uint8_t responseCode;
bool newDataReceived;
bool wrongDataReceived;
bool enableNavLighting;
uint8_t currentShowingEffect;
bool celebrate;
bool enableCycleDemoMode;


//uint8_t brightnessLevel;
void setupPanels();

void tick();

#endif