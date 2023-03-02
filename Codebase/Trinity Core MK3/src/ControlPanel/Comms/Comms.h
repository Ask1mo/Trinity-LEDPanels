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
#define TRANSMISSION_SLEEPTIMER             6
#define TRANSMISSION_LIGHTSENSOR            7

class Comms
{
    private:
    uint8_t readyTransmissionType;
    int inByte;         // incoming serial byte
    uint8_t transmissionData[IDENTLENGTH];
    struct Transmission_PanelFX         *buffer_PanelFX;
    struct Transmission_PanelCustom     *buffer_PanelCustom;
    struct Transmission_DiodeFX         *buffer_DiodeFX;
    struct Transmission_DiodeCustom     *buffer_DiodeCustom;
    uint8_t                             buffer_Brightness;
    struct Transmission_SleepTimerData  *buffer_SleepTimerData;
    struct Transmission_LightSensorData *buffer_LightSensorData;
    uint8_t decodeTransmissionType();
    uint8_t waitAndRead();
    bool    doTransmissionEndCheck();
    Transmission_PanelFX            receieveTransmission_PanelFX();
    Transmission_PanelCustom        receieveTransmission_PanelCustom();
    Transmission_DiodeFX            receieveTransmission_DiodeFX();
    Transmission_DiodeCustom        receieveTransmission_DiodeCustom();
    uint8_t                         receieveTransmission_Brightness();
    Transmission_SleepTimerData     receieveTransmission_SleepTimer();
    Transmission_LightSensorData    receieveTransmission_LightSensor();

    public:
    Comms();
    void tick();
    uint8_t getReadyTransmissionType();
    Transmission_PanelFX            getTransmission_PanelFX();
    Transmission_PanelCustom        getTransmission_PanelCustom();
    Transmission_DiodeFX            getTransmission_DiodeFX();
    Transmission_DiodeCustom        getTransmission_DiodeCustom();
    uint8_t                         getTransmission_Brightness();
    Transmission_SleepTimerData     getTransmission_SleepTimerData();
    Transmission_LightSensorData    getTransmission_LightSensorData();
};



#endif