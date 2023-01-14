
#ifndef TRANSMISSIONTYPES_H
#define TRANSMISSIONTYPES_H

#include <Arduino.h>
#include <RTClib.h>
//#include "./Trinity/LedManager/Panel/Diode/ColourRGB.h"
#include "./Trinity/LedManager/Panel/Diode/Diode.h"

struct Transmission_PanelFX
{
    uint8_t brightness;
    uint8_t effect;
    uint8_t colour;
    uint8_t offset;
    uint8_t speed;
    bool repeat;
    bool detailed;
};
struct Transmission_PanelCustom
{
    uint8_t customRGBAmount;
    ColourRGB *customRGB[AMOUNTOFCOLOURS];
};
struct Transmission_DiodeFX
{
    uint8_t number;

    uint8_t brightness;
    uint8_t effect;
    uint8_t colour;
    uint8_t offset;
    uint8_t speed;
    bool repeat;
};
struct Transmission_DiodeCustom
{
    uint8_t customRGBAmount;
    ColourRGB *customRGB[AMOUNTOFCOLOURS];
};
struct Transmission_SleepTimerEnabled
{
    bool timerID;
    bool enabled;
};
struct Transmission_SleepTimerTime
{
    bool timerID;
    DateTime time;
};

#endif