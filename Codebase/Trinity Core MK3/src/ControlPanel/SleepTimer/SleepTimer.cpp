
#include "SleepTimer.h"

SleepTimer::SleepTimer()
{
    Serial.println(F("SleepTimer Starting..."));
    rtc = new RTC_DS3231();
    rtc->begin();

    if (rtc->lostPower())
    {
        Serial.println(F("RTC lost power, let's set the time!"));
        rtc->adjust(DateTime(F(__DATE__), F(__TIME__)));
    }
    Serial.println(F("...SleepTimer Started"));
}

void SleepTimer::tick()
{
    DateTime now = rtc->now();
    if (turnOnEnabled)
    {
        if (turnOnTime.hour() == now.hour() && turnOnTime.minute() == now.minute())
        {
            if(turnOnFlag)
            turn = TURN_ON;
            turnOnFlag = true;
        }
        else
        {
            turnOnFlag = false;
        }
        
    }

    if (turnOffEnabled)
    {
        if (turnOffTime.hour() == now.hour() && turnOffTime.minute() == now.minute())
        {
            if(turnOffFlag)
            turn = TURN_OFF;
            turnOffFlag = true;
        }
        else
        {
            turnOffFlag = false;
        }
        
    }
    
}
uint8_t SleepTimer::getTurn()
{
    if (turn != TURN_NEUTRAL)
    {
        uint8_t turnToSend = turn;
        turn = TURN_NEUTRAL;
        return turnToSend;
    }
    return turn;
}
void SleepTimer::setTurnOnTime(DateTime dateTime)
{
    turnOnTime = dateTime;
}
void SleepTimer::setTurnOnEnabled(bool enabled)
{
    turnOnEnabled = enabled;
}
void SleepTimer::setTurnOffTime(DateTime dateTime)
{
    turnOffTime = dateTime;
}
void SleepTimer::setTurnOffEnabled(bool enabled)
{
    turnOffEnabled = enabled;
}