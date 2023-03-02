
#ifndef SLEEPTIMER_H
#define SLEEPTIMER_H

#include <Arduino.h>

#define TURN_OFF        0
#define TURN_ON         1
#define TURN_NEUTRAL    2

class SleepTimer
{
private:
    //RTC_DS3231  *rtc;
    uint8_t     turn;
    struct tm   *turnOnTime;
    bool        turnOnEnabled;
    bool        turnOnFlag;
    struct tm   *turnOffTime;
    bool        turnOffEnabled;
    bool        turnOffFlag;
    struct tm   *time;
    
public:
    SleepTimer();
    void tick();
    void setTime(uint16_t year, uint8_t month, uint8_t day,   uint8_t hour, uint8_t minute);
    void printTime();
    uint8_t getTurn();
    void setTurnOnTime(uint8_t hour, uint8_t minute);
    void setTurnOnEnabled(bool enabled);
    void setTurnOffTime(uint8_t hour, uint8_t minute);
    void setTurnOffEnabled(bool enabled);
};

#endif



#include "time.h"
