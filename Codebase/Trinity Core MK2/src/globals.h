#ifndef GLOBALS_H
#define GLOBALS_H

#include <Arduino.h>

#define LED_PIN     12

#define MAXTRANSMISSIONLENGTH 11
#define GLOBALSTRANSMISSIONLENGTH 5
#define REQUESTTRANSMISSIONLENGTH 7

#define LEAVES 16
#define LEDSPERLEAF 17
#define NUM_LEDS    272 //272for16

/*-------------------------------------------------------------------------------------*/

typedef struct
{
    byte brightness;
    byte leafDelay;

    byte soundLevel;
    byte soundPeak;
    
    byte soundMinimum;
    byte soundMaximum;
}Globals;


/*-------------------------------------------------------------------------------------*/

Globals* getGlobals();

#endif