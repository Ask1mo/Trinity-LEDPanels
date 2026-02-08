
#ifndef DATATYPES_H
#define DATATYPES_H

#include <Arduino.h>




struct VFXData
{
    uint8_t effect;
    uint8_t colour;
    uint16_t offset;
    uint8_t speed;
    bool repeat;
};

struct ColourRGB
{
  uint8_t r;
  uint8_t g;
  uint8_t b;
};
struct EffectVariables
{
  uint8_t                                   r;
  uint8_t                                   g;
  uint8_t                                   b;
  uint8_t                                   d; //Dummy
  uint8_t                                   c; //Current colour (Can cycle because of COLOUR_COLOURCYCLE)
  uint8_t                                   fxProgression; //Current part of the effect
};
struct CustomPalette 
{
    uint8_t                                   customRGBSlots; //Actually used amount of slots.
  ColourRGB                                 customRGB[AMOUNTOFCOLOURS];
};




struct Transmission_LedManager
{
    uint8_t brightness;
    uint8_t speed;
};
struct Transmission_Panel
{
    uint8_t panelNumber;
    VFXData vfxData;
};
struct Transmission_Diode
{
    uint8_t panelNumber;
    uint16_t diodeNumber;
    VFXData vfxData;
};
struct Transmission_CustomPalette
{
    uint8_t slot;
    ColourRGB *customRGB[AMOUNTOFCOLOURS];
};
struct Transmission_SleepTimer
{
    bool timerID;
    uint8_t hour;
    uint8_t minute;
    bool enabled;
};
struct Transmission_LightSensor
{
    uint16_t offset;
    bool enabled;
};

#endif