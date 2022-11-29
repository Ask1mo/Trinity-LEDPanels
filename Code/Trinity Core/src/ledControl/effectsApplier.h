#ifndef EFFECTSAPPLIER_H
#define EFFECTSAPPLIER_H

#include <Arduino.h>

#include "leaf.h"
#include "effectsStorage/customFxList.h"
#include "effectsStorage/normalFxList.h"
#include "ledControl/printToLEDs.h"

/*-------------------------------------------------------------------------------------*/

void effectsApplier(Leaf *leaf, byte brightness);
void effect_custom(Leaf * leaf);

#endif