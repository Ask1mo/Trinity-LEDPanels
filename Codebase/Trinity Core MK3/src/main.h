#ifndef MAIN_H
#define MAIN_H

#include "Trinity/Trinity.h"

#define NEXTEFFECTTIME 10000
#define ENABLECYCLING true

//#define ANIMATIONSET_STOCK
#define ANIMATIONSET_WESTPOINT

Trinity *trinity;

uint64_t prevMillis;
uint8_t currentShowingEffect;

#endif