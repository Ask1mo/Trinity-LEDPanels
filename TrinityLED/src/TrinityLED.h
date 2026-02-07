#ifndef TRINITYLED_H
#define TRINITYLED_H

#include "Panel/Panel.h"
#include "SleepTimer/SleepTimer.h"

#define PRESETANIMATIONAMOUNT 19
#define PRESETANIMATION_FULLWHITE        0
#define PRESETANIMATION_DEFAULT          1
#define PRESETANIMATION_BREATHINGLINES   2
#define PRESETANIMATION_FLASHINGLINES    3
#define PRESETANIMATION_RAIN             4
#define PRESETANIMATION_MATRIX           5
#define PRESETANIMATION_SUPERRAINBOW     6
#define PRESETANIMATION_ADHDRAINBOW      7
#define PRESETANIMATION_BURNINGRAINBOW   8
#define PRESETANIMATION_HEARTBEATTOWER   9
#define PRESETANIMATION_STOPLIGHT        10
#define PRESETANIMATION_POWERRISE        11
#define PRESETANIMATION_FISHBOWL         12
#define PRESETANIMATION_COILS            13
#define PRESETANIMATION_APPEARTHING      14
#define PRESETANIMATION_APPEARTHING2     15
#define PRESETANIMATION_APPEARTHING3     16
#define PRESETANIMATION_APPEARTHING4     17
#define PRESETANIMATION_COLOURBLINK      18

class Trinity
{
private:
  uint8_t       panelAmount = 0;
  uint8_t       goalBrightness = 255;
  uint8_t       brightness = 0;
  uint8_t       speed = 1;

  uint64_t      prevFrameMillis;
  uint16_t      frameTime;

  bool          animationCycling = false;
  uint8_t       currentlyShowingAnimation = 0;
  uint32_t      prevMillis_AnimationCycle = 0;
  uint32_t      durationMillis_animationCycle = 0;

  Panel         **panels = NULL;
  CRGB          *leds;
  CustomPalette *customPalette[CUSTOMPALETTEAMOUNT];
  SleepTimer    *sleepTimer;

  uint8_t                                 canvasWidth;
  uint8_t                                 canvasHeight;
  Panel                                   ***panelMatrix;

  bool          allowDiodeControl = false;


  void resetAnim_Wspt_Reset();
  void playPresetAnim_Wspt_FullWhite();       //0   
  void playPresetAnim_Wspt_Default();         //1
  void playPresetAnim_Wspt_BreathingLines();  //2
  void playPresetAnim_Wspt_FlashingLines();   //3
  void playPresetAnim_Wspt_Rain();            //4
  void playPresetAnim_Wspt_Matrix();          //5
  void playPresetAnim_Wspt_SuperRainbow();    //6
  void playPresetAnim_Wspt_ADHDRainbow();     //7
  void playPresetAnim_Wspt_BurningRainbow();  //8
  void playPresetAnim_Wspt_HeartbeatTower();  //9
  void playPresetAnim_Wspt_Stoplight();       //10
  void playPresetAnim_Wspt_PowerRise();       //11
  void playPresetAnim_Wspt_Fishbowl();        //12
  void playPresetAnim_Wspt_Coils();           //13
  void playPresetAnim_Wspt_AppearThing();     //14
  void playPresetAnim_Wspt_AppearThing2();    //15
  void playPresetAnim_Wspt_AppearThing3();    //16
  void playPresetAnim_Wspt_AppearThing4();    //17
  void playPresetAnim_Wspt_ColourBlink();     //18
  void playPresetAnim_Atos_Default();       //19
  
  

public:
  Trinity                                 (uint8_t ledPin, uint8_t maxFramerate, bool diodeControl);
  void    addPanel                        (Panel *panel);
  void    addPanel                        (uint8_t x, uint8_t y, uint8_t compassDir, bool clockDir, uint16_t diodeAmount);
  void    addPanel                        (uint16_t diodeAmount);
  void    begin                           ();
  //Standard
  void    tick                            ();
  void    tick_leds                       ();
  void    forceTick_leds                  (uint16_t ticks, bool keepPrinting, uint16_t delayTime);  //Manually force the ledmanager to tick without running any other Trinity code.
  void    print                           ();
  //Effects
  uint8_t getBrightness                   ();
  void    setBrightness                   (uint8_t brightness, bool smooth);
  void    setSpeed                        (uint8_t speed);
  //Panel Effects
  void    setPanelBrightness              (uint8_t panelNumber, uint8_t brightness, bool smooth);
  void    setPanelVfx                     (uint8_t panelNumber, VFXData vfxData);
  //Diode Effects
  void    setPanelDiodeBrightness         (uint8_t panelNumber, uint16_t diodeNumber, uint8_t brightness, bool smooth);
  void    setPanelDiodeVfx                (uint8_t panelNumber, uint16_t diodeNumber, VFXData vfxData);
  //Technical
  uint8_t getPanelAmount                  ();
  uint16_t getPanelDiodeAmount            (uint8_t panelNumber);
  //Transmissions
  String  convertToTansmission            ();
  String  convertPanelToTransmission      (uint8_t panelNumber);
  String  convertPanelDiodeToTransmission (uint8_t panelNumber,uint16_t diodeNumber);
  //Custom Palettes
  void    setCustomPaletteColours         (uint8_t slot, uint8_t colourRGBNumber, ColourRGB colourRGB);
  void    setCustomPaletteAvailableColours(uint8_t slot, uint8_t avalaibleColours);
  //Preset animations
  void    setAnimationCyclingDuration     (uint32_t duration); //0 = off, 0 < will cycle through all animations 
  void    playPresetAnimation             (uint8_t animation, bool cycling);  //Play a preset animation. If cycling duration is set, it will cycle through all animations.
  void    nextPresetAnimation             (); //Manually cycle to the next animation.
  //Sleep timer
  void    setTurnOnTime                   (uint8_t hour, uint8_t minute);
  void    setTurnOnEnabled                (bool enabled);
  void    setTurnOffTime                  (uint8_t hour, uint8_t minute);
  void    setTurnOffEnabled               (bool enabled);



  void prepareCanvas();
  void printCanvas();

};  

#endif