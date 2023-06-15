
#ifndef TRANSMISSIONTYPES_H
#define TRANSMISSIONTYPES_H

#include <Arduino.h>
#include "./LedManager/effectProcessor/effectProcessor.h"
//#include "./LedManager/Panel/Diode/Diode.h"
#include "DataTypes.h"

#define TRANSMISSION_IN_NONE                   0
#define TRANSMISSION_IN_PANELFX                1
#define TRANSMISSION_IN_PANELCUSTOM            2
#define TRANSMISSION_IN_DIODEFX                3
#define TRANSMISSION_IN_DIODECUSTOM            4
#define TRANSMISSION_IN_BRIGHTNESS             5
#define TRANSMISSION_IN_SLEEPTIMER             6
#define TRANSMISSION_IN_LIGHTSENSOR            7
#define TRANSMISSION_IN_REQUEST                8
#define TRANSMISSION_IN_IDENT                  9

#define TRANSMISSION_OUT_NONE       0
#define TRANSMISSION_OUT_LEDMANAGER 1
#define TRANSMISSION_OUT_PANEL      2
#define TRANSMISSION_OUT_DIODE      3
#define TRANSMISSION_OUT_IDENT      4

struct Transmission_PanelFX
{
    uint8_t panelNumber;
    VFXData vfxData;
};
struct Transmission_CustomRGB
{
    uint8_t customRGBAmount;
    ColourRGB *customRGB[AMOUNTOFCOLOURS];
};
struct Transmission_DiodeFX
{
    uint8_t panelNumber;
    uint8_t diodeNumber;
    VFXData vfxData;
};
struct Transmission_SleepTimerData
{
    bool timerID;
    uint8_t hour;
    uint8_t minute;
    bool enabled;
};
struct Transmission_LightSensorData
{
    uint16_t offset;
    bool enabled;
};

#endif