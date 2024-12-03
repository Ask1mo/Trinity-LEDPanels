/*---=== Setting examples ===---*/
//PANELSETUP_PROTO
//PANELSETUP_ATOS
//PANELSETUP_EVA
//PANELSETUP_LIAM
//PANELSETUP_PRIME
//PANELSETUP_CHRISTMAS
//PANELSETUP_WESTPOINT
//PANELSETUP_MINITOWER
//PANELSETUP_CLOSET
//PANELSETUP_TEST

//PLATFORM_ARDUINO
//PLATFORM_ESP32_FIREBEETLE2
//PLATFORM_ESP32_FIREBEETLE2_DEBUG
//PLATFORM_ESP32_WROOMDEVKIT

//LEDTYPE_STANDARD
//LEDTYPE_CHRISTMASSTRING

//LINKPROGRAM_MK2
//LINKPROGRAM_MK3

#define DEBUG_DISABLED              0
#define DEBUG_ERRORS                1
#define DEBUG_WARNINGS              2
#define DEBUG_OPERATIONS            3
#define DEBUG_DAYISRUINED           5
/*---=== Setting examples ===---*/





/*---=== PUT YOUR SETTINGS HERE!!! ===---*/
#define PANELSETUP_SHARKSALES
#define PLATFORM_ESP32_FIREBEETLE2_DEBUG
#define LEDTYPE_STANDARD
#define LINKPROGRAM_MK2

#define DEBUGLEVEL DEBUG_DISABLED
/*---=== PUT YOUR SETTINGS HERE!!! ===---*/





/*---=== Pin Mapping ===---*/
#ifdef PLATFORM_ARDUINO
    #define PIN_BUTTON      2           //D2
    #define PIN_LEDS        12          //D12
    #define PIN_ERRORLED    13          //D13
    #define PIN_LIGHTSENSOR A0          //A0
    #define ENABLE_WEBCONTROL false     //Arduino has no website capabilities
    #define BAUDRATE 9600
    #define CUSTOMPALETTEAMOUNT 5
#endif
#ifdef PLATFORM_ESP32_FIREBEETLE2
    #define PIN_BUTTON      27          //On board button
    #define PIN_LEDS        4           //D?
    #define PIN_ERRORLED    2           //No pinout, only internal on board
    #define PIN_LIGHTSENSOR 15          //D?
    #define ENABLE_WEBCONTROL true      //Controls via website enabled
    #define BAUDRATE 115200
    #define CUSTOMPALETTEAMOUNT 5
#endif
#ifdef PLATFORM_ESP32_FIREBEETLE2_DEBUG
    #define PIN_BUTTON      27          //On board button
    #define PIN_LEDS        5           //On boadr LED
    #define PIN_LIGHTSENSOR 15          //D?
    #define PIN_ERRORLED    2           //No pinout, only internal on board
    #define BAUDRATE 115200
    #define CUSTOMPALETTEAMOUNT 5
#endif
#ifdef PLATFORM_ESP32_WROOMDEVKIT
    #define PIN_BUTTON      27          //On board button
    #define PIN_LEDS        5           //On boadr LED
    #define PIN_LIGHTSENSOR 15          //D?
    #define PIN_ERRORLED    2           //NOT BOUND YET
    #define ENABLE_WEBCONTROL false      //Controls via website enabled
    #define BAUDRATE 115200
    #define CUSTOMPALETTEAMOUNT 5
#endif
/*---=== Pin Mapping ===---*/


/* ---=== Strip Setup ===---*/
#ifdef LEDTYPE_STANDARD
    #define LEDCOLORDER GRB
#endif
#ifdef LEDTYPE_CHRISTMASSTRING
    #define LEDCOLORDER RGB
#endif
/* ---=== Strip Setup ===---*/

