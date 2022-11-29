#ifndef TRANSMISSIONSENDER_H
#define TRANSMISSIONSENDER_H

#include <Arduino.h>
#include <Wire.h>

#include "globals.h"
#include "leaf.h"

/*-------------------------------------------------------------------------------------*/

void serialSend_Leaf(Leaf* leaf);


#endif