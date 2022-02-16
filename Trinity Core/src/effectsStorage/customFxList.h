#ifndef CUSTOMFX_H
#define CUSTOMFX_H

#include <Arduino.h>

#include "leaf.h"
#include "ledControl/getColourClearance.h"
#include "globals.h"

/*-------------------------------------------------------------------------------------*/

void customFx_off(Leaf *leaf);

void customFx_rainbow(Leaf *leaf);

void customFx_strobe(Leaf *leaf);

void customFx_fire(Leaf * leaf);

void customFx_customRGB(Leaf *leaf);

void customFx_christmas(Leaf *leaf);

void customFx_notBound(Leaf *leaf);

#endif