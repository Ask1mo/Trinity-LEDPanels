#include "Comms.h"

Comms::Comms()
{
    Serial.println(F("Comms: Starting"));

    readyTransmissionType = TRANSMISSION_IN_NONE;

    buffer_PanelFX          = new struct Transmission_PanelFX;
    buffer_PanelCustomRGB   = new struct Transmission_CustomRGB;
    for (uint8_t i = 0; i < AMOUNTOFCOLOURS; i++) buffer_PanelCustomRGB->customRGB[i]= new struct ColourRGB;
    buffer_DiodeFX          = new struct Transmission_DiodeFX;
    buffer_DiodeCustomRGB   = new struct Transmission_CustomRGB;
    for (uint8_t i = 0; i < AMOUNTOFCOLOURS; i++) buffer_DiodeCustomRGB->customRGB[i]= new struct ColourRGB;
    buffer_Brightness       = 0;
    buffer_SleepTimerData   = new struct Transmission_SleepTimerData;
    buffer_LightSensorData  = new struct Transmission_LightSensorData;

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
    ) return TRANSMISSION_IN_PANELFX;

    if
    (
        transmissionData[0] == 'P' &&
        transmissionData[1] == 'a' &&
        transmissionData[2] == 'n' &&
        transmissionData[3] == 'C' &&
        transmissionData[4] == 'u'
    ) return TRANSMISSION_IN_PANELCUSTOM;

    if
    (
        transmissionData[0] == 'D' &&
        transmissionData[1] == 'i' &&
        transmissionData[2] == 'o' &&
        transmissionData[3] == 'F' &&
        transmissionData[4] == 'x'
    ) return TRANSMISSION_IN_DIODEFX;

    if
    (
        transmissionData[0] == 'D' &&
        transmissionData[1] == 'i' &&
        transmissionData[2] == 'o' &&
        transmissionData[3] == 'C' &&
        transmissionData[4] == 'u'
    ) return TRANSMISSION_IN_DIODECUSTOM;

    if
    (
        transmissionData[0] == 'B' &&
        transmissionData[1] == 'r' &&
        transmissionData[2] == 'g' &&
        transmissionData[3] == 'h' &&
        transmissionData[4] == 't'
    ) return TRANSMISSION_IN_BRIGHTNESS;

    if
    (
        transmissionData[0] == 'S' &&
        transmissionData[1] == 'l' &&
        transmissionData[2] == 'e' &&
        transmissionData[3] == 'e' &&
        transmissionData[4] == 'p'
    ) return TRANSMISSION_IN_SLEEPTIMER;

    if
    (
        transmissionData[0] == 'L' &&
        transmissionData[1] == 'i' &&
        transmissionData[2] == 'g' &&
        transmissionData[3] == 'h' &&
        transmissionData[4] == 't'
    ) return TRANSMISSION_IN_LIGHTSENSOR;

    if
    (
        transmissionData[0] == 'R' &&
        transmissionData[1] == 'e' &&
        transmissionData[2] == 'q' &&
        transmissionData[3] == 'u' &&
        transmissionData[4] == 'e'
    ) return TRANSMISSION_IN_REQUEST;

    return TRANSMISSION_IN_NONE;
}
uint8_t Comms::waitAndRead()
{
    while (!Serial.available()) delay(1);
    return (Serial.read());
}
bool    Comms::doTransmissionEndCheck()
{
    for(uint8_t i = 0; i < IDENTLENGTH; i++)
    {
        transmissionData[i] = waitAndRead();
    }
    
    printBuffer();
    
    if
    (
        transmissionData[0] == 'C' &&
        transmissionData[1] == 'l' &&
        transmissionData[2] == 'e' &&
        transmissionData[3] == 'a' &&
        transmissionData[4] == 'r'
    ) return true;

    return false;
}
void    Comms::printBuffer()
{
    Serial.print(F("Printing buffer: "));
    for(uint8_t i = 0; i < IDENTLENGTH; i++)
    {
        Serial.write(transmissionData[i]);
    }
    Serial.println( );
}

//Public
void                            Comms::tick()
{
    while(Serial.available() > 0 && readyTransmissionType == TRANSMISSION_IN_NONE)
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
            case TRANSMISSION_IN_PANELFX:
            {
                buffer_PanelFX->brightness  = waitAndRead();
                buffer_PanelFX->effect      = waitAndRead();
                buffer_PanelFX->colour      = waitAndRead();
                buffer_PanelFX->offset      = waitAndRead();
                buffer_PanelFX->speed       = waitAndRead();
                buffer_PanelFX->repeat      = waitAndRead();
                buffer_PanelFX->detailed    = waitAndRead();
            }
            break;
            case TRANSMISSION_IN_PANELCUSTOM:
            {
                buffer_PanelCustomRGB->customRGBAmount = waitAndRead();

                for (uint8_t i = 0; i < AMOUNTOFCOLOURS; i++)
                {
                    if (i < buffer_PanelCustomRGB->customRGBAmount)
                    {

                        buffer_PanelCustomRGB->customRGB[i]->r = waitAndRead();
                        buffer_PanelCustomRGB->customRGB[i]->g = waitAndRead();
                        buffer_PanelCustomRGB->customRGB[i]->b = waitAndRead();
                    }
                    else
                    {
                        buffer_PanelCustomRGB->customRGB[i]->r = 0;
                        buffer_PanelCustomRGB->customRGB[i]->g = 0;
                        buffer_PanelCustomRGB->customRGB[i]->b = 0;
                    }
                }
            }
            break;
            case TRANSMISSION_IN_DIODEFX:
            {
                buffer_DiodeFX->number        = waitAndRead();
                buffer_DiodeFX->brightness    = waitAndRead();
                buffer_DiodeFX->effect        = waitAndRead();
                buffer_DiodeFX->colour        = waitAndRead();
                buffer_DiodeFX->offset        = waitAndRead();
                buffer_DiodeFX->speed         = waitAndRead();
                buffer_DiodeFX->repeat        = waitAndRead();
            }
            break;
            case TRANSMISSION_IN_DIODECUSTOM:
            {
                buffer_DiodeCustomRGB->customRGBAmount = waitAndRead();

                for (uint8_t i = 0; i < AMOUNTOFCOLOURS; i++)
                {
                    if (i < buffer_DiodeCustomRGB->customRGBAmount)
                    {

                        buffer_DiodeCustomRGB->customRGB[i]->r = waitAndRead();
                        buffer_DiodeCustomRGB->customRGB[i]->g = waitAndRead();
                        buffer_DiodeCustomRGB->customRGB[i]->b = waitAndRead();
                    }
                    else
                    {
                        buffer_DiodeCustomRGB->customRGB[i]->r = 0;
                        buffer_DiodeCustomRGB->customRGB[i]->g = 0;
                        buffer_DiodeCustomRGB->customRGB[i]->b = 0;
                    }
                }
            }
            break;
            case TRANSMISSION_IN_BRIGHTNESS:
            {
                buffer_Brightness = waitAndRead();
            }
            break;
            case TRANSMISSION_IN_SLEEPTIMER:
            {
                buffer_SleepTimerData->timerID   = waitAndRead();
                buffer_SleepTimerData->hour      = waitAndRead();
                buffer_SleepTimerData->minute    = waitAndRead();
                buffer_SleepTimerData->enabled   = waitAndRead();
            }
            break;
            case TRANSMISSION_IN_LIGHTSENSOR:
            {
                buffer_LightSensorData->offset = waitAndRead();
                buffer_LightSensorData->offset = buffer_LightSensorData->offset << 8;
                buffer_LightSensorData->offset = buffer_LightSensorData->offset | waitAndRead();
                buffer_LightSensorData->enabled = waitAndRead();
            }
            break;
        }

        if(receivedTransmissionType != TRANSMISSION_IN_NONE)
        {
            if (doTransmissionEndCheck())
            {
                readyTransmissionType = receivedTransmissionType;
                Serial.println(F("Transmission completed"));
            }
            else
            {
                Serial.println(F("TRANS ERR"));
            }
        }
        

        if(!Serial.available())
        {            
            delay(1); //Wait a bit in case the transmisison was not actually finished
        }
    }
}
void                            Comms::transmit(uint8_t transmissionType, String data)
{
    switch (transmissionType)
    {
        case TRANSMISSION_OUT_LEDMANAGER:
        {
            Serial.print("TXLED");
        }
        break;
        case TRANSMISSION_OUT_PANEL:
        {
            Serial.print("TXPAN");
        }
        break;
        case TRANSMISSION_OUT_DIODE:
        {
            Serial.print("TXDIO");
        }
        break;
    }

    Serial.print(data);
    Serial.println("Clear");
}
uint8_t                         Comms::getReadyTransmissionType()
{
    if(readyTransmissionType == TRANSMISSION_IN_REQUEST)
    {
        readyTransmissionType = TRANSMISSION_IN_NONE;
        return TRANSMISSION_IN_REQUEST;
    }
    return readyTransmissionType;
}
Transmission_PanelFX            Comms::getTransmission_PanelFX()
{
    readyTransmissionType = TRANSMISSION_IN_NONE;
    return *buffer_PanelFX;
}
Transmission_CustomRGB          Comms::getTransmission_PanelCustomRGB()
{
    readyTransmissionType = TRANSMISSION_IN_NONE;
    return *buffer_PanelCustomRGB;
}
Transmission_DiodeFX            Comms::getTransmission_DiodeFX()
{
    readyTransmissionType = TRANSMISSION_IN_NONE;
    return *buffer_DiodeFX;
}
Transmission_CustomRGB          Comms::getTransmission_DiodeCustomRGB()
{
    readyTransmissionType = TRANSMISSION_IN_NONE;
    return *buffer_DiodeCustomRGB;
}
uint8_t                         Comms::getTransmission_Brightness()
{
    readyTransmissionType = TRANSMISSION_IN_NONE;
    return buffer_Brightness;
}
Transmission_SleepTimerData     Comms::getTransmission_SleepTimerData()
{
    readyTransmissionType = TRANSMISSION_IN_NONE;
    return *buffer_SleepTimerData;
}
Transmission_LightSensorData    Comms::getTransmission_LightSensorData()
{
    readyTransmissionType = TRANSMISSION_IN_NONE;
    return *buffer_LightSensorData;
}