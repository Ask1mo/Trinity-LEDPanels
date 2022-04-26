#include "globals.h"

/*-------------------------------------------------------------------------------------*/
Globals globals =
{
    /*byte brightness = */15,
    /*byte leafDelay = */5,

    /*byte soundLevel = */0,
    /*byte soundPeak = */0,
    
    /*byte soundMinimum= */255,
    /*byte soundMaximum = */0,
};
/*-------------------------------------------------------------------------------------*/

Globals* getGlobals()
{
    return &globals;
}