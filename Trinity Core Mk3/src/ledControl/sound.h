#ifndef SOUND_H
#define SOUND_H


#include <Arduino.h>


#define FLOATINGAVERAGESIZE 5 //Min 2, Max 33. This is how many values(-1) are used in the floating average code.
#define SOUNDPEAKDELAY 500
#define SOUNDMILLISDELAY 5000

#define SOUNDANALOGTODECIBELSNUMBER 50.0
#define VOLTAGE 3.3
#define SOUNDPIN A0




void soundVisualiser(unsigned long currentMillis);

#endif