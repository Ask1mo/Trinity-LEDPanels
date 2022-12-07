#include "Comms.h"

Comms::Comms(byte pin, uint32_t longPressDuration)
{
    this->pin = pin;
    this->longPressDuration = longPressDuration;

    pinMode(this->pin, INPUT_PULLUP);
}

byte Comms::getCommand()
{
    state = digitalRead(pin);
    myMillis = millis();

    if (state != prevState)
    {
        if(state == LOW) //If button is pressed
        {
            pressStartTime = myMillis;
            prevState = state;
            return BUTTON_RELEASED;
        }
        else// If button is released
        {
            if (myMillis - pressStartTime <= longPressDuration)
            {
                prevState = state;
                lastActionTime = myMillis;
                Serial.println(F("BTN TAP"));
                return BUTTON_TAPPED;
            }
            else
            {
                prevState = state;
                holdStateIsKnown = false;
                return BUTTON_RELEASED;
            }
            
        }
        
    }

    if (state == LOW) // If button is pressed
    {
        if (myMillis - pressStartTime >= longPressDuration)
        {
            if(holdStateIsKnown == false)
            {
                holdStateIsKnown = true;
                lastActionTime = myMillis;
                Serial.println(F("BTN HLD"));
                return BUTTON_HELD;
            }
            else
            {
                lastActionTime = myMillis;
                return BUTTON_RELEASED;
            }
        }
    }

    return BUTTON_RELEASED;
}

unsigned long Comms::getLastTimeDelta()
{
    return (myMillis - lastActionTime);
}