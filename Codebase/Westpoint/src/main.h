#ifndef TRINITY_H
#define TRINITY_H

#include <Wire.h>
#include "setup.h"
#include "Shared.h"
#include "LedManager/ledManager.h"
#include "ControlPanel/AskButton/AskButton.h"
#include "ControlPanel/LightSensor/LightSensor.h"
#include "ControlPanel/SleepTimer/SleepTimer.h"
#include "ControlPanel/Comms/Comms.h"

#define BRIGHTNESS_0_OFF 1
#define BRIGHTNESS_1_DIM 10
#define BRIGHTNESS_2_NOR 100
#define BRIGHTNESS_3_MAX 255
#define BRIGHTNESS_4_AUT 99

#define NEXTEFFECTTIME 20000

Panel         **panels;
LedManager    *ledManager;
AskButton     *button;
LightSensor   *lightSensor;
SleepTimer    *sleepTimer;
Comms         *comms;

uint64_t prevMillis;
uint8_t receivedCode;
uint8_t responseCode;
bool newDataReceived;
bool wrongDataReceived;
bool enableNavLighting;
uint8_t currentShowingEffect;


//uint8_t brightnessLevel;
void setupPanels();

void tick();

#endif