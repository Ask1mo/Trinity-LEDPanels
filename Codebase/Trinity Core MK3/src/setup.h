//Pin mapping
#define PIN_LEDS        4     //D12
#define PIN_BUTTON      25    //D2
#define PIN_LIGHTSENSOR 26    //D3

#define PIN_EXAMPLE_R   37
#define PIN_EXAMPLE_G   36
#define PIN_EXAMPLE_B   33

//Setup stuff
#define PANELSETUP_TEST //Select your panel setup here:
//PANELSETUP_ATOS
//PANELSETUP_EVA
//PANELSETUP_LIAM
//PANELSETUP_PRIME
//PANELSETUP_TEST
#define PLATFORM_ARDUINO
//PLATFORM_ARDUINO
//PLATFORM_ESP32FIREBEETLE2
//PLATFORM_ESP32FIREBEETLE2_DEBUG



//You probably don't have to touch this stuff below 

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