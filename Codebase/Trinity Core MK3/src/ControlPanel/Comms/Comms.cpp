#include "Comms.h"

Comms::Comms()
{
    Serial.println(F("Comms: Starting"));
    Serial.println(F("Comms: Started"));
}

//Private
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
        transmissionData[1] == 'l' &&
        transmissionData[2] == 'e' &&
        transmissionData[3] == 'e' &&
        transmissionData[4] == 'p'
    ) return TRANSMISSION_SLEEPTIMER;

    if
    (
        transmissionData[0] == 'L' &&
        transmissionData[1] == 'i' &&
        transmissionData[2] == 'g' &&
        transmissionData[3] == 'h' &&
        transmissionData[4] == 't'
    ) return TRANSMISSION_LIGHTSENSOR;

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
Transmission_PanelFX            Comms::receieveTransmission_PanelFX()
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
Transmission_PanelCustom        Comms::receieveTransmission_PanelCustom()
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
Transmission_DiodeFX            Comms::receieveTransmission_DiodeFX()
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
Transmission_DiodeCustom        Comms::receieveTransmission_DiodeCustom()
{

}
uint8_t                         Comms::receieveTransmission_Brightness()
{

}
Transmission_SleepTimerData     Comms::receieveTransmission_SleepTimer()
{

}
Transmission_LightSensorData    Comms::receieveTransmission_LightSensor()
{

}

//Public
void    Comms::tick()
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
                *buffer_PanelFX = receieveTransmission_PanelFX();
            }
            break;
            case TRANSMISSION_PANELCUSTOM:
            {
                *buffer_PanelCustom = receieveTransmission_PanelCustom();
            }
            break;
            case TRANSMISSION_DIODEFX:
            {
                *buffer_DiodeFX = receieveTransmission_DiodeFX();
            }
            break;
            case TRANSMISSION_DIODECUSTOM:
            {
                *buffer_DiodeCustom = receieveTransmission_DiodeCustom();
            }
            break;
            case TRANSMISSION_BRIGHTNESS:
            {
                buffer_Brightness = receieveTransmission_Brightness();
            }
            break;
            case TRANSMISSION_SLEEPTIMER:
            {
                *buffer_SleepTimerData = receieveTransmission_SleepTimer();
            }
            break;
            case TRANSMISSION_LIGHTSENSOR:
            {
                *buffer_LightSensorData = receieveTransmission_LightSensor();
            }
            break;
        }

        if (doTransmissionEndCheck())
        {
            readyTransmissionType = receivedTransmissionType;
        }
        else
        {
            Serial.println("BROKEN TRANSMISISON CAPTURED");
        }
        

        if(!Serial.available())
        {            
            delay(1); //Wait a bit in case the transmisison was not actually finished
        }
    }
}
uint8_t Comms::getReadyTransmissionType()
{
    uint8_t readyTransmissionTypeToSend = readyTransmissionType;
    readyTransmissionType = TRANSMISSION_NONE;
    return readyTransmissionTypeToSend;
}
Transmission_PanelFX            Comms::getTransmission_PanelFX()
{
    return *buffer_PanelFX;
}
Transmission_PanelCustom        Comms::getTransmission_PanelCustom()
{
    return *buffer_PanelCustom;
}
Transmission_DiodeFX            Comms::getTransmission_DiodeFX()
{
    return *buffer_DiodeFX;
}
Transmission_DiodeCustom        Comms::getTransmission_DiodeCustom()
{
    return *buffer_DiodeCustom;
}
uint8_t                         Comms::getTransmission_Brightness()
{
    return buffer_Brightness;
}
Transmission_SleepTimerData     Comms::getTransmission_SleepTimerData()
{
    return *buffer_SleepTimerData;
}
Transmission_LightSensorData    Comms::getTransmission_LightSensorData()
{
    return *buffer_LightSensorData;
}