#ifndef TRANSMISSIONEXECUTOR_H
#define TRANSMISSIONEXECUTOR_H

#include <Arduino.h>
#include <Wire.h>

#include "communications/transmissionReader.h"
#include "communications/transmissionSender.h"
#include "ledControl/resetAndUpdateLEDs.h"

/*-------------------------------------------------------------------------------------*/

void leafTransmissionExecutor(byte transmissionData[]);
void globalsTransmissionExecutor(byte transmissionData[]);
void requestTransmissionExecutor();

#endif