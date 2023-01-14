/*
#ifndef COMMS_H
#define COMMS_H

#include <Arduino.h>
#include "TransmissionTypes.h"

#define IDENTLENGTH 5
#define COMPLETEDBUFFERSIZE

#define TRANSMISSION_NONE                   0
#define TRANSMISSION_PANELFX                1
#define TRANSMISSION_PANELCUSTOM            2
#define TRANSMISSION_DIODEFX                3
#define TRANSMISSION_DIODECUSTOM            4
#define TRANSMISSION_BRIGHTNESS             5
#define TRANSMISSION_SPEED                  6
#define TRANSMISSION_SLEEPTIMERENABLED      7
#define TRANSMISSION_SLEEPTIMERTIME         8
#define TRANSMISSION_LIGHTSENSORENABLED     9
#define TRANSMISSION_LIGHTSENSOROFFSET      10

class Comms
{
    private:
    int inByte;         // incoming serial byte
    uint8_t transmissionData[IDENTLENGTH];
    uint8_t decodeTransmissionType();
    uint8_t waitAndRead();
    bool    doTransmissionEndCheck();

    Transmission_PanelFX        receieveTransmission_PanelFX();
    Transmission_PanelCustom    receieveTransmission_PanelCustom();
    void receieveTransmission_DiodeFX();
    void receieveTransmission_DiodeCustom();
    void receieveTransmission_Brightness();
    void receieveTransmission_Speed();
    void receieveTransmission_SleepTimerEnabled();
    void receieveTransmission_SleepTimerTime();
    void receieveTransmission_LightSensorEnabled();
    void receieveTransmission_LighstSensorOffset();

    public:
    Comms();
    void tick();
    uint8_t getReadyTransmissionType();
    void    getTransmission_PanelFX();
    void    getTransmission_PanelCustom();
    void    getTransmission_DiodeFX();
    void    getTransmission_DiodeCustom();
    uint8_t getTransmission_Brightness();
    uint8_t getTransmission_Speed();
    void    getTransmission_SleepTimerEnabled();
    void    getTransmission_SleepTimerTime();
    bool    getTransmission_LightSensorEnabled();
    int     getTransmission_LightSensorOffset();
};



#endif
*/