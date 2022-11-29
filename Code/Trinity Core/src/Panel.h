#ifndef PANEL_H
#define PANEL_H

#include <Arduino.h>
#include <FastLED.h>
#include <Vector.h>

#define LEDSPERPANEL 17


#define RAINBOW           0
#define SYNTHBOW          1
#define FIRE              2
#define STATIC            3
#define BLINK             4
#define BREATHING         5
#define PAUSEDBREATHING   6
#define FLASH             7
#define HEARTBEAT         8

#define BLACK             0
#define RED               1
#define YELLOW            2
#define GREEN             3
#define TEAL              4
#define BLUE              5
#define VIOLET            6
#define WHITE             7

#define CLOCKWISE         0
#define COUNTERWISE       1

#define NORTH             0
#define NORTH_EAST        1
#define EAST              2
#define SOUTH_EAST        3
#define SOUTH             4
#define SOUTH_WEST        5
#define WEST              6
#define NORTH_WEST        7




class Panel
{
private:
  void FX_rainbow();
  void FX_fire();
  void FX_blink();
  void FX_static();
  void FX_breathing();
  void FX_flash();
  void FX_sound();

  uint8_t fxProgression;    //Sys - How far into a effect are we? (think of rainbow mode: What colour is cycling?)
  uint8_t cycleProgression; //Sys - What fxNumber is currently being cycled? 
  uint32_t timer;             //Sys - The leaf's timer. If this timer reaches fxOfsset, the leaf will activate.

  uint8_t redValue;         //Sys - The R value of this leaf
  uint8_t greenValue;       //Sys - The G value of this leaf
  uint8_t blueValue;        //Sys - The B value of this leaf
  uint8_t dummyValue;       //Sys - A invisible value, used for timings and delays.

  bool allowRed;
  bool allowGreen;
  bool allowBlue;
  bool colourNumber;

  



public:
  Panel(uint8_t panelNumber, uint8_t x, uint8_t y, uint8_t compassRotation, bool flowDirection);
  void Tick();
  bool getColourClearance(byte colourToClear);

  CRGB Leds[LEDSPERPANEL];
  

  uint8_t PanelNumber;
  uint8_t X;
  uint8_t Y;
  uint8_t CompassDirection;
  bool ClockDirection;

  uint8_t Brightness;
  uint8_t Effect;
  uint8_t Colour; 

  uint8_t Offset;
  uint8_t Speed;    

  uint8_t CustomRedValue;
  uint8_t CustomGreenValue;
  uint8_t CustomBlueValue;
};

#endif