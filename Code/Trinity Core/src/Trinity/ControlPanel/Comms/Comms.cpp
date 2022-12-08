#include "Comms.h"

Comms::Comms()
{
    
}

uint8_t Comms::decodeTransmissionType()
{
    if
    (// /0/0000/000/
        transmissionData[0] == 'P' &&
        transmissionData[1] == 'a' &&
        transmissionData[2] == 'n' &&
        transmissionData[3] == 'F' &&
        transmissionData[4] == 'x'
    )
    return TRANSMISSION_PANELFX;
}

void Comms::tick()
{
    //delay(1000);
    while(Serial.available())
    {
        Serial.print("!");
        delay(1000);


        for(byte i = 0; i < IDENTLENGTH-1; i++)
        {
            transmissionData[i] = transmissionData[i+1];
        }
        transmissionData[IDENTLENGTH-1] = Serial.read();
        switch (decodeTransmissionType())
        {
            case TRANSMISSION_PANELFX:
            {
                Serial.print(F("Transmisison "));
                Serial.println(TRANSMISSION_PANELFX);
            }
            break;
        }
        


        if(!Serial.available())
        {
            
            delay(1000); //Wait a bit in case the transmisison was not actually finished
        }
    }
}
