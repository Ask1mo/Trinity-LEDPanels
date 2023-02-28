/*
#ifndef SLEEPTIMER_H
#define SLEEPTIMER_H

#define TURN_OFF        0
#define TURN_ON         1
#define TURN_NEUTRAL    2

#include <Arduino.h>
//#include <RTClib.h>

class SleepTimer
{
private:
    RTC_DS3231  *rtc;
    uint8_t     turn;
    DateTime    turnOnTime;
    bool        turnOnEnabled;
    bool        turnOnFlag;
    DateTime    turnOffTime;
    bool        turnOffEnabled;
    bool        turnOffFlag;
    
public:
    SleepTimer();
    void tick();
    uint8_t getTurn();
    void setTurnOnTime(DateTime dateTime);
    void setTurnOnEnabled(bool enabled);
    void setTurnOffTime(DateTime dateTime);
    void setTurnOffEnabled(bool enabled);
};

#endif
*/