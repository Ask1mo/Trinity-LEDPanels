
#include "SleepTimer.h"

SleepTimer::SleepTimer()
{
    Serial.println(F("SleepTimer Starting..."));

    uint8_t     turn            = TURN_NEUTRAL;
    bool        turnOnEnabled   = false;
    bool        turnOnFlag      = false;
    bool        turnOffEnabled  = false;
    bool        turnOffFlag     = false;

    struct tm tm;
    tm.tm_year  = 2023 - 1900; //Year
    tm.tm_mon   = 2; //Month (Do -1 or it will be incorrect)
    tm.tm_mday  = 1; //Day
    tm.tm_hour  = 17;//Hour
    tm.tm_min   = 15; //Minute
    tm.tm_sec   = 10; //Second
    time_t t = mktime(&tm);
    struct timeval now = { .tv_sec = t };
    settimeofday(&now, NULL);

    Serial.println(F("...SleepTimer Started"));
}

void SleepTimer::tick()
{
    struct tm timeinfo;
    getLocalTime(&timeinfo);
    //Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S"); 

    if (turnOnEnabled)
    {
        if(timeinfo.tm_hour == 17 && timeinfo.tm_min == 16)
        {
            if(!turnOnFlag)
            {
                turn = TURN_ON;
                turnOnFlag = true;
            }
            Serial.println(F("ON FLAG HIT!!! --- ON FLAG HIT!!! --- ON FLAG HIT!!!"));
        }
        else
        {
            turnOnFlag = false;
        }
    }

    if (turnOffEnabled)
    {
        if(timeinfo.tm_hour == 17 && timeinfo.tm_min == 15)
        {
            //if(!turnOffFlag)
            //{
                turn = TURN_OFF;
                turnOffFlag = true;
            //}
            Serial.println(F("OFF FLAG HIT!!! --- OFF FLAG HIT!!! --- OFF FLAG HIT!!!"));
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
        Serial.print(F("Returning "));
        Serial.println(turnToSend);
        return turnToSend;
    }
    Serial.print(F("Returning "));
    Serial.println(turn);
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