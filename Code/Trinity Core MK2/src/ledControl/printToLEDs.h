#ifndef PRINTTOLEDS_H
#define PRINTTOLEDS_H

#include <Arduino.h>
#include <FastLED.h>

#include "leaf.h"
#include "globals.h"

/*-------------------------------------------------------------------------------------*/

void startLeds();

void printToLEDs(Leaf *leaf, byte brightness);

#endif