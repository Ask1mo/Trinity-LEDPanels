#ifndef COMMS_H
#define COMMS_H

#include <Arduino.h>
#include "TransmissionTypes.h"

#define IDENTLENGTH 5
#define COMPLETEDBUFFERSIZE

class Comms
{
    private:
    uint8_t                             readyTransmissionType;
    uint8_t                             transmissionData[IDENTLENGTH];
    struct Transmission_PanelFX         *buffer_PanelFX;
    struct Transmission_CustomRGB       *buffer_PanelCustomRGB;
    struct Transmission_DiodeFX         *buffer_DiodeFX;
    struct Transmission_CustomRGB       *buffer_DiodeCustomRGB;
    uint8_t                             buffer_Brightness;
    struct Transmission_SleepTimerData  *buffer_SleepTimerData;
    struct Transmission_LightSensorData *buffer_LightSensorData;
    uint8_t                             decodeTransmissionType();   
    uint8_t                             waitAndRead();
    bool                                doTransmissionEndCheck();
    void                                printBuffer();

    public:
    Comms();
    void                            tick();
    void                            transmit(uint8_t transmissionType, String data);
    uint8_t                         getReadyTransmissionType();
    Transmission_PanelFX            getTransmission_PanelFX();
    Transmission_CustomRGB          getTransmission_PanelCustomRGB();
    Transmission_DiodeFX            getTransmission_DiodeFX();
    Transmission_CustomRGB          getTransmission_DiodeCustomRGB();
    uint8_t                         getTransmission_Brightness();
    Transmission_SleepTimerData     getTransmission_SleepTimerData();
    Transmission_LightSensorData    getTransmission_LightSensorData();
};
#endif