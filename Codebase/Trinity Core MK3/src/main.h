#ifndef MAIN_H
#define MAIN_H

#include "setup.h"
#include "Trinity/Trinity.h"



#define NEXTEFFECTTIME 20000

Trinity *trinity;

uint64_t prevMillis;
uint8_t currentShowingEffect;
//uint8_t brightnessLevel;

void setupPanels();

void tick();

#endif