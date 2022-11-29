#ifndef FXLIST_H
#define FXLIST_H

#include <Arduino.h>

#include "leaf.h"
#include "globals.h"
#include "ledControl/getColourClearance.h"

/*-------------------------------------------------------------------------------------*/

void effect_static(Leaf *leaf);

void effect_blink(Leaf *leaf);

void effect_breathing(Leaf *leaf);

void effect_flash(Leaf *leaf);

void effect_sound(Leaf *leaf);

#endif