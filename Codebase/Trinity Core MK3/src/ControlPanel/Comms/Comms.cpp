/*
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
uint8_t Comms::waitAndRead()
{
    while (!Serial.available()) delay(1);
    return Serial.read();
}
bool    Comms::doTransmissionEndCheck()
{
    for(uint8_t i = 0; i < IDENTLENGTH-1; i++)
    {
        transmissionData[i] = transmissionData[i+1];
    }
    transmissionData[IDENTLENGTH-1] = waitAndRead();

    if
    (
        transmissionData[0] == 'C' &&
        transmissionData[1] == 'l' &&
        transmissionData[2] == 'e' &&
        transmissionData[3] == 'a' &&
        transmissionData[4] == 'r'
    ) return TRANSMISSION_PANELFX;
}
Transmission_PanelFX        Comms::receieveTransmission_PanelFX()
{
    Transmission_PanelFX processedData;
    
    processedData.brightness  = waitAndRead();
    processedData.effect      = waitAndRead();
    processedData.colour      = waitAndRead();
    processedData.offset      = waitAndRead();
    processedData.speed       = waitAndRead();
    processedData.repeat      = waitAndRead();
    processedData.detailed    = waitAndRead();

    return processedData;
}
Transmission_PanelCustom    Comms::receieveTransmission_PanelCustom()
{
    Transmission_PanelCustom processedData;
    
    processedData.customRGBAmount  = waitAndRead();

    ColourRGB *processedData_ColourRGB[processedData.customRGBAmount];
    for (uint8_t i = 0; i < processedData.customRGBAmount; i++)
    {
        processedData_ColourRGB[i]->r = waitAndRead();
        processedData_ColourRGB[i]->g = waitAndRead();
        processedData_ColourRGB[i]->b = waitAndRead();
    }

    return processedData;
}
Transmission_DiodeFX        Comms::receieveTransmission_DiodeFX()
{
    Transmission_DiodeFX processedData;

    processedData.number        = waitAndRead();
    processedData.brightness    = waitAndRead();
    processedData.effect        = waitAndRead();
    processedData.colour        = waitAndRead();
    processedData.offset        = waitAndRead();
    processedData.speed         = waitAndRead();
    processedData.repeat        = waitAndRead();

    return processedData;
}
void                        Comms::receieveTransmission_DiodeCustom()
{

}
void Comms::receieveTransmission_Brightness()
{

}
void Comms::receieveTransmission_Speed()
{

}
void Comms::receieveTransmission_SleepTimerEnabled()
{

}
void Comms::receieveTransmission_SleepTimerTime()
{

}
void Comms::receieveTransmission_LightSensorEnabled()
{

}
void Comms::receieveTransmission_LighstSensorOffset()
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
*/