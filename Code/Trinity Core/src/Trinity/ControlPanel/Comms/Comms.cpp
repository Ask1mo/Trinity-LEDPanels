#include "Comms.h"

Comms::Comms()
{
    
}

uint8_t Comms::decodeTransmissionType()
{
    if
    (
        transmissionData[0] == 'P' &&
        transmissionData[1] == 'a' &&
        transmissionData[2] == 'n' &&
        transmissionData[3] == 'F' &&
        transmissionData[4] == 'x'
    ) return TRANSMISSION_PANELFX;

    if
    (
        transmissionData[0] == 'P' &&
        transmissionData[1] == 'a' &&
        transmissionData[2] == 'n' &&
        transmissionData[3] == 'C' &&
        transmissionData[4] == 'u'
    ) return TRANSMISSION_PANELCUSTOM;

    if
    (
        transmissionData[0] == 'D' &&
        transmissionData[1] == 'i' &&
        transmissionData[2] == 'o' &&
        transmissionData[3] == 'F' &&
        transmissionData[4] == 'x'
    ) return TRANSMISSION_DIODEFX;

    if
    (
        transmissionData[0] == 'D' &&
        transmissionData[1] == 'i' &&
        transmissionData[2] == 'o' &&
        transmissionData[3] == 'C' &&
        transmissionData[4] == 'u'
    ) return TRANSMISSION_DIODECUSTOM;

    if
    (
        transmissionData[0] == 'B' &&
        transmissionData[1] == 'r' &&
        transmissionData[2] == 'g' &&
        transmissionData[3] == 'h' &&
        transmissionData[4] == 't'
    ) return TRANSMISSION_BRIGHTNESS;

    if
    (
        transmissionData[0] == 'S' &&
        transmissionData[1] == 'p' &&
        transmissionData[2] == 'e' &&
        transmissionData[3] == 'e' &&
        transmissionData[4] == 'd'
    ) return TRANSMISSION_SPEED;

    if
    (
        transmissionData[0] == 'S' &&
        transmissionData[1] == 'l' &&
        transmissionData[2] == 'p' &&
        transmissionData[3] == 'E' &&
        transmissionData[4] == 'n'
    ) return TRANSMISSION_SLEEPTIMERENABLED;

    if
    (
        transmissionData[0] == 'S' &&
        transmissionData[1] == 'l' &&
        transmissionData[2] == 'p' &&
        transmissionData[3] == 'T' &&
        transmissionData[4] == 'i'
    ) return TRANSMISSION_SLEEPTIMERTIME;

    if
    (
        transmissionData[0] == 'L' &&
        transmissionData[1] == 'i' &&
        transmissionData[2] == 'g' &&
        transmissionData[3] == 'E' &&
        transmissionData[4] == 'n'
    ) return TRANSMISSION_LIGHTSENSORENABLED;

    if
    (
        transmissionData[0] == 'L' &&
        transmissionData[1] == 'i' &&
        transmissionData[2] == 'g' &&
        transmissionData[3] == 'O' &&
        transmissionData[4] == 'f'
    ) return TRANSMISSION_LIGHTSENSOROFFSET;

    return TRANSMISSION_NONE;
}
uint8_t waitAndRead()
{
    while (!Serial.available()) delay(1);
    return Serial.read();
}
void receieveTransmission_PanelFX()
{
    Transmission_PanelFX panelFX;
    
    panelFX.brightness  = waitAndRead();
    panelFX.effect      = waitAndRead();
    panelFX.colour      = waitAndRead();
    panelFX.offset      = waitAndRead();
    panelFX.speed       = waitAndRead();
    panelFX.repeat      = waitAndRead();
    panelFX.detailed    = waitAndRead();
}
void receieveTransmission_PanelCustom()
{

}
void receieveTransmission_DiodeFX()
{

}
void receieveTransmission_DiodeCustom()
{

}
void receieveTransmission_Brightness()
{

}
void receieveTransmission_Speed()
{

}
void receieveTransmission_SleepTimerEnabled()
{

}
void receieveTransmission_SleepTimerTime()
{

}
void receieveTransmission_LightSensorEnabled()
{

}
void receieveTransmission_LighstSensorOffset()
{

}

void Comms::tick()
{
    while(Serial.available() > 0)
    {
        for(byte i = 0; i < IDENTLENGTH-1; i++)
        {
            transmissionData[i] = transmissionData[i+1];
        }
        transmissionData[IDENTLENGTH-1] = Serial.read();

        uint8_t receivedTransmissionType = decodeTransmissionType();
        Serial.print(F("Transmisison "));
        Serial.println(receivedTransmissionType);

        switch (receivedTransmissionType)
        {
            case TRANSMISSION_PANELFX:
            {
                receieveTransmission_PanelFX();
            }
            break;
            case TRANSMISSION_PANELCUSTOM:
            {
                receieveTransmission_PanelCustom();
            }
            break;
            case TRANSMISSION_DIODEFX:
            {
                receieveTransmission_DiodeFX();
            }
            break;
            case TRANSMISSION_DIODECUSTOM:
            {
                receieveTransmission_DiodeCustom();
            }
            break;
            case TRANSMISSION_BRIGHTNESS:
            {
                receieveTransmission_Brightness();
            }
            break;
            case TRANSMISSION_SPEED:
            {
                receieveTransmission_Speed();
            }
            break;
            case TRANSMISSION_SLEEPTIMERENABLED:
            {
                receieveTransmission_SleepTimerEnabled();
            }
            break;
            case TRANSMISSION_SLEEPTIMERTIME:
            {
                receieveTransmission_SleepTimerTime();
            }
            break;
            case TRANSMISSION_LIGHTSENSORENABLED:
            {
                receieveTransmission_LightSensorEnabled();
            }
            break;
            case TRANSMISSION_LIGHTSENSOROFFSET:
            {
                receieveTransmission_LighstSensorOffset();
            }
            break;
        }

        if(!Serial.available())
        {            
            delay(1); //Wait a bit in case the transmisison was not actually finished
        }
    }
}
