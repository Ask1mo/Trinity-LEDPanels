/*---=== Setup stuff ===---*/

#define PANELSETUP_DRONE //Select your panel setup here:
//PANELSETUP_ATOS
//PANELSETUP_EVA
//PANELSETUP_LIAM
//PANELSETUP_PRIME
//PANELSETUP_TEST
//PANELSETUP_DRONE
#define PLATFORM_ESP32FIREBEETLE2
//PLATFORM_ARDUINO
//PLATFORM_ESP32FIREBEETLE2
//PLATFORM_ESP32FIREBEETLE2_DEBUG


/*---=== Pin Mapping ===---*/

#ifdef PLATFORM_ARDUINO
    #define PIN_BUTTON      2     //D2
    #define PIN_LEDS        12    //D12
    #define PIN_LIGHTSENSOR A0    //A0
#endif
#ifdef PLATFORM_ESP32FIREBEETLE2
    #define PIN_BUTTON      27    //On board button
    #define PIN_LEDS        2     //D?   //pin 4 for ESP32, 2 for WROOM
    #define PIN_LIGHTSENSOR 15    //D?
    
    #define DRONESENSOR_A 32
    #define DRONESENSOR_B 33
    #define DRONESENSOR_C 25
    #define DRONESENSOR_D 26
    

    /*
    #define DRONESENSOR_A 26
    #define DRONESENSOR_B 25
    #define DRONESENSOR_C 33
    #define DRONESENSOR_D 32
    */

#endif
#ifdef PLATFORM_ESP32FIREBEETLE2_DEBUG
    #define PIN_BUTTON      27    //On board button
    #define PIN_LEDS        5     //On boadr LED
    #define PIN_LIGHTSENSOR 15    //D?
#endif


/* ---=== LED Setup ===---*/

#ifdef PANELSETUP_ATOS
    #define PANELAMOUNT 1
    #define LEDAMOUNT 38
#endif
#ifdef PANELSETUP_EVA
    #define PANELAMOUNT 4
    #define LEDAMOUNT 68
#endif
#ifdef PANELSETUP_LIAM
    #define PANELAMOUNT 10
    #define LEDAMOUNT 170
#endif
#ifdef PANELSETUP_PRIME
    #define PANELAMOUNT 16
    #define LEDAMOUNT 272
#endif
#ifdef PANELSETUP_TEST
    #define PANELAMOUNT 6
    #define LEDAMOUNT 18
#endif
#ifdef PANELSETUP_DRONE
    #define PANELAMOUNT 33
    #define PANELAMOUNT_TOWERONLY 29
    //#define LEDAMOUNT 272
    #define LEDAMOUNT 450
#endif