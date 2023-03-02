
#ifndef TRANSMISSIONTYPES_H
#define TRANSMISSIONTYPES_H

#include <Arduino.h>
#include "./LedManager/Panel/Diode/ColourRGB.h"
#include "./LedManager/Panel/Diode/Diode.h"

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