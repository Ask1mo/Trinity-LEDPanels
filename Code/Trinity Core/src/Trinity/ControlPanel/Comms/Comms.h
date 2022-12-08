#ifndef COMMS_H
#define COMMS_H

#include <Arduino.h>

#define TRANSMISSION_PANELFX                1
#define TRANSMISSION_PANELCUSTOM            2
#define TRANSMISSION_DIODEFX                3
#define TRANSMISSION_DIODECUSTOM            4
#define TRANSMISSION_BRIGHTNESS             5
#define TRANSMISSION_SPEED                  6
#define TRANSMISSION_SLEEPTIMERENABLE       7
#define TRANSMISSION_SLEEPTIMERTIME         8
#define TRANSMISSION_LIGHTSENSORENABLE      9
#define TRANSMISSION_LIGHTSENSOROVERRIDE    10

class Comms
{
    private:
    byte            pin;
    bool            state;
    bool            prevState;
    bool            holdStateIsKnown;
    unsigned long   myMillis;
    unsigned long   pressStartTime;
    unsigned long   lastActionTime;
    uint32_t        longPressDuration;

    public:
    Comms();
    uint8_t getReadyTransmission();
    void getTransmission_PanelFX();
    void getTransmission_PanelCustom();
    void getTransmission_DiodeFX();
    void getTransmission_DiodeCustom();
    uint8_t getTransmission_Brightness();
    uint8_t getTransmission_Speed();
    void getTransmission_SleepTimerEnabled();
    void getTransmission_SleepTimerTime();
    bool getTransmission_LightSensorEnabled();
    int getTransmission_LightSensorOverride();
};



#endif