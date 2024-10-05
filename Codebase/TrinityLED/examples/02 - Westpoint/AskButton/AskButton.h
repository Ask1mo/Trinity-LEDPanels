#ifndef ASKBUTTON_H
#define ASKBUTTON_H

#include <Arduino.h>

#define BUTTON_RELEASED         0
#define BUTTON_TAPPED           1
#define BUTTON_HELD             2
#define BUTTON_ERROR            3 

class AskButton
{
    private:
    byte pin;
    bool state;
    bool prevState;
    bool holdStateIsKnown;
    unsigned long myMillis;
    unsigned long pressStartTime;
    unsigned long lastActionTime;
    uint32_t longPressDuration;

    public:
    AskButton(byte pin, uint32_t longPressDuration);
    byte getCommand();
    unsigned long getLastTimeDelta();
};



#endif