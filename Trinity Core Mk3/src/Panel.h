#ifndef PANEL_H
#define PANEL_H

#include <Arduino.h>
#include <FastLED.h>

#define LEDSPERLEAF 17
#define NUM_LEDS    272 //272for16



#define RAINBOW 0
#define SYNTHBOW 1
#define FIRE 2
#define SOUND 3

#define STATIC 4
#define BLINK 5
#define BREATHING 6
#define PAUSEDBREATHING 7
#define FLASH 8
#define HEARTBEAT 9


#define BLACK 0
#define RED 1
#define Yellow 2
#define Green 3
#define TEAL 4
#define BLUE 5
#define VIOLET 6
#define WHITE 7



class Panel
{
  private:
  uint8_t PanelNumber;
  uint8_t Brightness;

  uint8_t Offset;
  uint8_t Speed;    

  uint8_t Effect;
  uint8_t Colour; 
  
  uint8_t CustomRedValue;
  uint8_t CustomGreenValue;
  uint8_t CustomBlueValue;

  bool allowRed;
  bool allowGreen;
  bool allowBlue;
  bool colourNumber;

  CRGB leds[NUM_LEDS];

  void FX_RAINBOW();

  public:
  Panel(uint8_t number);
  void Write();
  void Tick();

  void FX_rainbow();
  void FX_fire();
  void FX_blink();
  void FX_static();
  void FX_breathing();
  void FX_flash();
  void FX_sound();


  //Colour stuff
  uint8_t redValue;         //Sys - The R value of this leaf
  uint8_t greenValue;       //Sys - The G value of this leaf
  uint8_t blueValue;        //Sys - The B value of this leaf
  uint8_t DummyValue;       //Sys - A invisible value, used for timings and delays.
  
  uint8_t fxProgression;    //Sys - How far into a effect are we? (think of rainbow mode: What colour is cycling?)
  uint8_t cycleProgression; //Sys - What fxNumber is currently being cycled? 
  
  //Delay & time stuff
  uint32_t timer;             //Sys - The leaf's timer. If this timer reaches fxOfsset, the leaf will activate.
}

#endif