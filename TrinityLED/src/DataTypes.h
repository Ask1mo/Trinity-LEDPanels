
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

#endif