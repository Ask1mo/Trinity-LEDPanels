#include "main.h"


#ifdef ANIMATIONSET_WESTPOINT
void playAnimation_Reset()
{
  Serial.println(F("playAnimation_Reset"));
  trinity->setSpeed(1);

  uint16_t diodeNumbers = 0;
  for (uint16_t i = 0; i < trinity->getPanelAmount(); i++)
  {
    trinity->setPanelVfx(i, (VFXData){EFFECT_STOCK_STATIC, COLOUR_BLACK, 0, 1, true});
    for (uint16_t j = 0; j < trinity->getPanelDiodeAmount(i); j++)
    {
      diodeNumbers++;
      trinity->setPanelDiodeVfx(i, j, (VFXData){EFFECT_STOCK_STATIC, COLOUR_VIOLET, diodeNumbers, 1, false});
    }
  }

  trinity->forceTick(diodeNumbers, true, 10);
  delay(1000);
}

void setAnimation_Westpoint_FullWhite()
{
  Serial.println(F("setAnimation_Westpoint_FullWhite"));
  trinity->setSpeed(1);

  uint16_t offset = 0;
  for (uint16_t i = 0; i < trinity->getPanelAmount(); i++)
  {
    trinity->setPanelVfx(i, (VFXData){EFFECT_STOCK_STATIC, COLOUR_WHITE, (uint16_t)(random(0, 10)*15), 1, true});
    for (uint16_t j = 0; j < trinity->getPanelDiodeAmount(i); j++)
    {
      trinity->setPanelDiodeVfx(i, j, (VFXData){EFFECT_STOCK_STATIC, COLOUR_WHITE, 0, 5, true});
      offset++;
    }
  }
}
void setAnimation_Westpoint_Default()
{
  Serial.println(F("setAnimation_Westpoint_Default"));
  trinity->setSpeed(1);

  uint16_t offset = 0;
  for (uint16_t i = 0; i < trinity->getPanelAmount(); i++)
  {
    trinity->setPanelVfx(i, (VFXData){EFFECT_STOCK_DECODE, COLOUR_RED, (uint16_t)(random(0, 10)*15), 1, true});
    for (uint16_t j = 0; j < trinity->getPanelDiodeAmount(i); j++)
    {
      trinity->setPanelDiodeVfx(i, j, (VFXData){EFFECT_SPECIAL_RAINBOW, COLOUR_RED, 0, 5, true});
      offset++;
    }
  }
}
void setAnimation_Westpoint_BreathingLines()
{
  Serial.println(F("setAnimation_Westpoint_BREATHINGLINES"));
  trinity->setSpeed(1);

  for (uint16_t i = 0; i < trinity->getPanelAmount(); i++)
  {
    trinity->setPanelVfx(i, (VFXData){EFFECT_STOCK_DECODE, COLOUR_RED, (uint16_t)(random(0, 10)*15), 1, true});
    for (uint16_t j = 0; j < trinity->getPanelDiodeAmount(i); j++)
    {
      trinity->setPanelDiodeVfx(i, j, (VFXData){EFFECT_STOCK_PAUSEDBREATHING, COLOUR_CYCLE, j, 20, true});
    }
  }
}
void setAnimation_Westpoint_FlashingLines()
{
  Serial.println(F("setAnimation_Westpoint_FlashingGLINES"));
  trinity->setSpeed(1);

  for (uint16_t i = 0; i < trinity->getPanelAmount(); i++)
  {
    trinity->setPanelVfx(i, (VFXData){EFFECT_STOCK_DECODE, COLOUR_RED, (uint16_t)(random(0, 10)*15), 1, true});
    for (uint16_t j = 0; j < trinity->getPanelDiodeAmount(i); j++)
    {
      trinity->setPanelDiodeVfx(i, j, (VFXData){EFFECT_STOCK_PAUSEDFLASH, COLOUR_WHITE, j, 10, true});
    }  
  }
}
void setAnimation_Westpoint_Rain()
{
  Serial.println(F("setAnimation_Westpoint_Rain"));
  trinity->setSpeed(1);

  for (uint16_t i = 0; i < trinity->getPanelAmount(); i++)
  {
    trinity->setPanelVfx(i, (VFXData){EFFECT_STOCK_DECODE, COLOUR_RED, (uint16_t)(random(0, 10)*15), 1, true});
    for (uint16_t j = 0; j < trinity->getPanelDiodeAmount(i); j++)
    {
      trinity->setPanelDiodeVfx(i, j, (VFXData){EFFECT_STOCK_PAUSEDFLASH, COLOUR_BLUE, j, (uint8_t)random(0, 10), true});
    }
  }
}
void setAnimation_Westpoint_Matrix()
{
  Serial.println(F("setAnimation_Westpoint_Matrix"));
  trinity->setSpeed(1);

  for (uint16_t i = 0; i < trinity->getPanelAmount(); i++)
  {
    trinity->setPanelVfx(i, (VFXData){EFFECT_STOCK_DECODE, COLOUR_RED, (uint16_t)(random(0, 10)*15), 1, true});
    for (uint16_t j = 0; j < trinity->getPanelDiodeAmount(i); j++)
    {
      trinity->setPanelDiodeVfx(i, j, (VFXData){EFFECT_STOCK_DECODE, COLOUR_GREEN, j, 10, true});
    }
  }
}
void setAnimation_Westpoint_SuperRainbow()
{
  Serial.println(F("setAnimation_Westpoint_SuperRainbow"));
  trinity->setSpeed(3);

  uint16_t offset = 0;
  for (uint16_t i = 0; i < trinity->getPanelAmount(); i++)
  {
    trinity->setPanelVfx(i, (VFXData){EFFECT_STOCK_DECODE, COLOUR_RED, 0, 1, true});
    for (uint16_t j = 0; j < trinity->getPanelDiodeAmount(i); j++)
    {
      trinity->setPanelDiodeVfx(i, j, (VFXData){EFFECT_SPECIAL_RAINBOW, COLOUR_RED, offset, 10, true});
      offset++;
    }
  }
}
void setAnimation_Westpoint_ADHDRainbow()
{
  Serial.println(F("setAnimation_Westpoint_ADHDRAINBOW"));
  trinity->setSpeed(1);

  uint16_t offset = 0;
  for (uint16_t i = 0; i < trinity->getPanelAmount(); i++)
  {
    for (uint16_t j = 0; j < trinity->getPanelDiodeAmount(i); j++)
    {
      trinity->setPanelDiodeVfx(i, j, (VFXData){EFFECT_SPECIAL_RAINBOW, COLOUR_RED, offset, 100, true});
      offset++;
    }
  }
  trinity->forceTick(500, false, 0);
}
void setAnimation_Westpoint_BurningRainbow()
{
  Serial.println(F("setAnimation_Westpoint_BurningRainbow"));
  trinity->setSpeed(4);

  uint16_t offset = 0;
    for (uint16_t i = 0; i < trinity->getPanelAmount(); i++)
    {
      trinity->setPanelVfx(i, (VFXData){EFFECT_STOCK_DECODE, COLOUR_RED, (uint16_t)(i*5), 10, true});
      for (uint16_t j = 0; j < trinity->getPanelDiodeAmount(i); j++)
      {
        trinity->setPanelDiodeVfx(i, j, (VFXData){EFFECT_SPECIAL_RAINBOW, COLOUR_RED, (uint16_t)(j*5), 10, true});
        offset++;
      }
  

      
    }
}
void setAnimation_Westpoint_HeartbeatTower()
{
  Serial.println(F("setAnimation_Westpoint_HeartbeatTower"));
  trinity->setSpeed(5);

  uint16_t offset = 0;
    for (uint16_t i = 0; i < trinity->getPanelAmount(); i++)
    {
      trinity->setPanelVfx(i, (VFXData){EFFECT_STOCK_DECODE, COLOUR_RED, (uint16_t)(i*4), 1, true});
      for (uint16_t j = 0; j < trinity->getPanelDiodeAmount(i); j++)
      {
        trinity->setPanelDiodeVfx(i, j, (VFXData){EFFECT_STOCK_HEARTBEAT, COLOUR_RED, 0, 1, true});
        offset++;
      }
  

      
    }
}
void setAnimation_Westpoint_Stoplight()
{
  Serial.println(F("setAnimation_Westpoint_Stoplight"));
  trinity->setSpeed(8);

  uint16_t offset = 0;
    for (uint16_t i = 0; i < trinity->getPanelAmount(); i++)
    {
      trinity->setPanelVfx(i, (VFXData){EFFECT_STOCK_DECODE, COLOUR_RED, offset, 1, true});
      for (uint16_t j = 0; j < trinity->getPanelDiodeAmount(i); j++)
      {
        trinity->setPanelDiodeVfx(i, j, (VFXData){EFFECT_STOCK_PAUSEDFLASH, COLOUR_CYCLE, offset, 1, true});
        offset+=3;
      }
  

      
    }
}
void setAnimation_Westpoint_PowerRise()
{
  Serial.println(F("setAnimation_Westpoint_Powerrize"));
  trinity->setSpeed(15);

  uint16_t offset = 0;
    for (uint16_t i = 0; i < trinity->getPanelAmount(); i++)
    {
      trinity->setPanelVfx(i, (VFXData){EFFECT_STOCK_DECODE, COLOUR_RED, offset, 1, true});
      for (uint16_t j = 0; j < trinity->getPanelDiodeAmount(i); j++)
      {
        trinity->setPanelDiodeVfx(i, j, (VFXData){EFFECT_STOCK_PAUSEDFLASH, COLOUR_CYAN, offset, 1, true});
        offset++;
      }
  

      
    }
}
void setAnimation_Westpoint_Fishbowl()
{
  Serial.println(F("setAnimation_Westpoint_Fishbowl"));
  trinity->setSpeed(10);

  uint16_t offset = 0;
  for (uint16_t i = 0; i < trinity->getPanelAmount(); i++)
  {
    trinity->setPanelVfx(i, (VFXData){EFFECT_STOCK_DECODE, COLOUR_RED, offset, 1, true});
    for (uint16_t j = 0; j < trinity->getPanelDiodeAmount(i); j++)
    {
      trinity->setPanelDiodeVfx(i, j, (VFXData){EFFECT_STOCK_PAUSEDFLASH, COLOUR_CYCLE, offset, 1, true});
      offset+=10;
    }
  }
  trinity->forceTick(900, false, 0);
}
void setAnimation_Westpoint_Coils()
{
  Serial.println(F("setAnimation_Westpoint_Coils"));
  trinity->setSpeed(10);

  uint16_t offset = 0;

  for (uint8_t i = 0; i < trinity->getPanelAmount(); i++)
  {
    trinity->setPanelVfx(i, (VFXData){EFFECT_STOCK_DECODE, COLOUR_RED, 0, 1, true});
    for (uint8_t j = 0; j < trinity->getPanelDiodeAmount(i); j++)
    {
      trinity->setPanelDiodeVfx(i, j, VFXData{ EFFECT_STOCK_DECODE, COLOUR_CYCLE, offset, 1, true});
      offset++;
    }
  }
}
void setAnimation_Westpoint_AppearThing()
{
  Serial.println(F("setAnimation_Westpoint_AppearThing"));
  trinity->setSpeed(20);

  uint16_t offset = 0;

  for (uint8_t i = 0; i < trinity->getPanelAmount(); i++)
  {
    trinity->setPanelVfx(i, (VFXData){EFFECT_STOCK_DECODE, COLOUR_RED, (uint16_t)random(0, 100), 1, true});
    for (uint8_t j = 0; j < trinity->getPanelDiodeAmount(i); j++)
    {
      trinity->setPanelDiodeVfx(i, j,VFXData{ EFFECT_STOCK_DECODE, COLOUR_CYCLE, (uint16_t)random(0, 100), 1, true});
      offset++;
    }
  }

}
void setAnimation_Westpoint_AppearThing2()
{
  Serial.println(F("setAnimation_Westpoint_AppearThing2"));
  trinity->setSpeed(10);

  uint16_t offset = 0;

  for (uint8_t i = 0; i < trinity->getPanelAmount(); i++)
  {
    trinity->setPanelVfx(i, (VFXData){EFFECT_STOCK_DECODE, COLOUR_RED, (uint16_t)random(0, 100), 1, true});
    for (uint8_t j = 0; j < trinity->getPanelDiodeAmount(i); j++)
    {
      trinity->setPanelDiodeVfx(i, j,VFXData{ EFFECT_STOCK_STATIC, COLOUR_CYCLE, (uint16_t)random(0, 100), 1, true});
      offset++;
    }
  }

}
void setAnimation_Westpoint_AppearThing3()
{
  Serial.println(F("setAnimation_Westpoint_AppearThing3"));
  trinity->setSpeed(10);

  uint16_t offset = 0;

  for (uint8_t i = 0; i < trinity->getPanelAmount(); i++)
  {
    trinity->setPanelVfx(i, (VFXData){EFFECT_STOCK_DECODE, COLOUR_RED, 0, 1, true});
    for (uint8_t j = 0; j < trinity->getPanelDiodeAmount(i); j++)
    {
      trinity->setPanelDiodeVfx(i, j,VFXData{ EFFECT_STOCK_STATIC, COLOUR_CYCLE, (uint16_t)random(0, 1000), 1, true});
      offset++;
    }
  }
}
void setAnimation_Westpoint_AppearThing4()
{
  Serial.println(F("setAnimation_Westpoint_AppearThing4"));
  trinity->setSpeed(4);

  uint16_t offset = 0;

  for (uint8_t i = 0; i < trinity->getPanelAmount(); i++)
  {
    trinity->setPanelVfx(i, (VFXData){EFFECT_STOCK_DECODE, COLOUR_RED, 0, 1, true});
    for (uint8_t j = 0; j < trinity->getPanelDiodeAmount(i); j++)
    {
      trinity->setPanelDiodeVfx(i, j,VFXData{ EFFECT_STOCK_PAUSEDFLASH, COLOUR_CYCLE, (uint16_t)random(0, 250), 1, true});
      offset++;
    }
  }
}
void setAnimation_Westpoint_ColourBlink()
{
  Serial.println(F("setAnimation_Westpoint_ColourBlink"));
  trinity->setSpeed(4);

  uint16_t offset = 0;

  for (uint8_t i = 0; i < trinity->getPanelAmount(); i++)
  {
    trinity->setPanelVfx(i, (VFXData){EFFECT_STOCK_DECODE, COLOUR_RED, 0, 1, true});
    for (uint8_t j = 0; j < trinity->getPanelDiodeAmount(i); j++)
    {
      trinity->setPanelDiodeVfx(i, j,VFXData{ EFFECT_STOCK_STATIC, COLOUR_CYCLE, i, 1, true});
      offset++;
    }
  }
  trinity->forceTick(64, false, 0);
}
#endif

void setup()
{
  Serial.begin(BAUDRATE);
  
  trinity = new Trinity(PIN_LEDS, PIN_BUTTON, PIN_LIGHTSENSOR, 60);

  #ifdef PANELSETUP_PROTO
  trinity->addPanel(new Panel(0, 0, 0, CLOCK_CLOCKWISE, COMPASS_NORTH, LEDSAMOUNT_TRIANGLE));
  trinity->addPanel(new Panel(1, 1, 0, CLOCK_CLOCKWISE, COMPASS_NORTH, LEDSAMOUNT_TRIANGLE));
  trinity->addPanel(new Panel(2, 2, 0, CLOCK_CLOCKWISE, COMPASS_NORTH, LEDSAMOUNT_TRIANGLE));
  trinity->addPanel(new Panel(3, 3, 0, CLOCK_CLOCKWISE, COMPASS_NORTH, LEDSAMOUNT_TRIANGLE));
  trinity->addPanel(new Panel(4, 4, 0, CLOCK_CLOCKWISE, COMPASS_NORTH, LEDSAMOUNT_TRIANGLE));
  trinity->addPanel(new Panel(5, 5, 0, CLOCK_CLOCKWISE, COMPASS_NORTH, LEDSAMOUNT_TRIANGLE));
  #endif
  #ifdef PANELSETUP_ATOS
  trinity->addPanel(new Panel(0, 0, 0, CLOCK_COUNTERWISE, COMPASS_WEST, 38));
  #endif
  #ifdef PANELSETUP_EVA
  trinity->addPanel(new Panel(0, 0, 0, CLOCK_COUNTERWISE, COMPASS_SOUTH_EAST, LEDSAMOUNT_TRIANGLE));
  trinity->addPanel(new Panel(1, 0, 0, CLOCK_COUNTERWISE, COMPASS_SOUTH,      LEDSAMOUNT_TRIANGLE));
  trinity->addPanel(new Panel(2, 0, 0, CLOCK_COUNTERWISE, COMPASS_SOUTH_WEST, LEDSAMOUNT_TRIANGLE));
  trinity->addPanel(new Panel(3, 0, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH_EAST, LEDSAMOUNT_TRIANGLE));
  #endif
  #ifdef PANELSETUP_LIAM
  trinity->addPanel(new Panel(0, 0, 0, CLOCK_COUNTERWISE, COMPASS_SOUTH_EAST, LEDSAMOUNT_TRIANGLE));
  trinity->addPanel(new Panel(1, 0, 0, CLOCK_COUNTERWISE, COMPASS_SOUTH,      LEDSAMOUNT_TRIANGLE));
  trinity->addPanel(new Panel(2, 0, 0, CLOCK_COUNTERWISE, COMPASS_SOUTH_WEST, LEDSAMOUNT_TRIANGLE));
  trinity->addPanel(new Panel(3, 0, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH_EAST, LEDSAMOUNT_TRIANGLE));
  trinity->addPanel(new Panel(4, 0, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH,      LEDSAMOUNT_TRIANGLE));
  trinity->addPanel(new Panel(5, 0, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH_WEST, LEDSAMOUNT_TRIANGLE));
  trinity->addPanel(new Panel(6, 0, 0, CLOCK_COUNTERWISE, COMPASS_SOUTH_WEST, LEDSAMOUNT_TRIANGLE));
  trinity->addPanel(new Panel(7, 0, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH_EAST, LEDSAMOUNT_TRIANGLE));
  trinity->addPanel(new Panel(8, 0, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH,      LEDSAMOUNT_TRIANGLE));
  trinity->addPanel(new Panel(9, 0, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH_WEST, LEDSAMOUNT_TRIANGLE));
  #endif
  #ifdef PANELSETUP_PRIME
  trinity->addPanel(new Panel( 0, 0, 3, CLOCK_COUNTERWISE, COMPASS_SOUTH_EAST, LEDSAMOUNT_TRIANGLE));
  trinity->addPanel(new Panel( 1, 1, 3, CLOCK_COUNTERWISE, COMPASS_SOUTH,      LEDSAMOUNT_TRIANGLE));
  trinity->addPanel(new Panel( 2, 2, 3, CLOCK_COUNTERWISE, COMPASS_SOUTH_WEST, LEDSAMOUNT_TRIANGLE));
  trinity->addPanel(new Panel( 3, 3, 3, CLOCK_CLOCKWISE,   COMPASS_NORTH_EAST, LEDSAMOUNT_TRIANGLE));
  trinity->addPanel(new Panel( 4, 4, 3, CLOCK_CLOCKWISE,   COMPASS_NORTH,      LEDSAMOUNT_TRIANGLE));
  trinity->addPanel(new Panel( 5, 5, 3, CLOCK_CLOCKWISE,   COMPASS_NORTH_WEST, LEDSAMOUNT_TRIANGLE));
  trinity->addPanel(new Panel( 6, 6, 3, CLOCK_COUNTERWISE, COMPASS_SOUTH_WEST, LEDSAMOUNT_TRIANGLE));
  trinity->addPanel(new Panel( 7, 5, 2, CLOCK_CLOCKWISE,   COMPASS_NORTH_EAST, LEDSAMOUNT_TRIANGLE));
  trinity->addPanel(new Panel( 8, 5, 2, CLOCK_CLOCKWISE,   COMPASS_NORTH,      LEDSAMOUNT_TRIANGLE));
  trinity->addPanel(new Panel( 9, 0, 1, CLOCK_CLOCKWISE,   COMPASS_NORTH_WEST, LEDSAMOUNT_TRIANGLE));
  trinity->addPanel(new Panel(10, 0, 1, CLOCK_CLOCKWISE,   COMPASS_NORTH,      LEDSAMOUNT_TRIANGLE));
  trinity->addPanel(new Panel(11, 0, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH_WEST, LEDSAMOUNT_TRIANGLE));
  trinity->addPanel(new Panel(12, 0, 1, CLOCK_COUNTERWISE, COMPASS_SOUTH_WEST, LEDSAMOUNT_TRIANGLE));
  trinity->addPanel(new Panel(13, 0, 2, CLOCK_CLOCKWISE,   COMPASS_NORTH_EAST, LEDSAMOUNT_TRIANGLE));
  trinity->addPanel(new Panel(14, 0, 2, CLOCK_CLOCKWISE,   COMPASS_NORTH,      LEDSAMOUNT_TRIANGLE));
  trinity->addPanel(new Panel(15, 0, 2, CLOCK_CLOCKWISE,   COMPASS_NORTH_WEST, LEDSAMOUNT_TRIANGLE));
  #endif
  #ifdef PANELSETUP_CHRISTMAS
  for (uint8_t i = 0; i < 10; i++)trinity->addPanel(new Panel(i, i, 0, CLOCK_CLOCKWISE, COMPASS_NORTH, 5));
  #endif
  #ifdef PANELSETUP_WESTPOINT
  //Tower Base
  trinity->addPanel(new Panel( 0, 0, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH,      10));
  trinity->addPanel(new Panel( 1, 0, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH,      11));
  trinity->addPanel(new Panel( 2, 0, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH,      10));
  trinity->addPanel(new Panel( 3, 0, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH,      11));
  trinity->addPanel(new Panel( 4, 0, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH,      10));
  trinity->addPanel(new Panel( 5, 0, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH,      10));
  trinity->addPanel(new Panel( 6, 0, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH,      11));
  trinity->addPanel(new Panel( 7, 0, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH,      10));
  trinity->addPanel(new Panel( 8, 0, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH,      10));
  trinity->addPanel(new Panel( 9, 0, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH,      10));
  trinity->addPanel(new Panel(10, 0, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH,      11));
  trinity->addPanel(new Panel(11, 0, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH,      10));
  trinity->addPanel(new Panel(12, 0, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH,      11));
  trinity->addPanel(new Panel(13, 0, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH,      10));
  trinity->addPanel(new Panel(14, 0, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH,      9 ));
  //Tower Top
  trinity->addPanel(new Panel(15, 0, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH,      10));
  trinity->addPanel(new Panel(16, 0, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH,      11));
  trinity->addPanel(new Panel(17, 0, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH,      10));
  trinity->addPanel(new Panel(18, 0, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH,      10));
  trinity->addPanel(new Panel(19, 0, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH,      10));
  trinity->addPanel(new Panel(20, 0, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH,      10));
  trinity->addPanel(new Panel(21, 0, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH,      11));
  trinity->addPanel(new Panel(22, 0, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH,      10));
  trinity->addPanel(new Panel(23, 0, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH,      10));
  trinity->addPanel(new Panel(24, 0, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH,      11));
  trinity->addPanel(new Panel(25, 0, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH,      10));
  trinity->addPanel(new Panel(26, 0, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH,      11));
  trinity->addPanel(new Panel(27, 0, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH,      10));
  trinity->addPanel(new Panel(28, 0, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH,      12));
  //Rigns
  trinity->addPanel(new Panel(29, 0, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH,      37));
  trinity->addPanel(new Panel(30, 0, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH,      37));
  trinity->addPanel(new Panel(31, 0, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH,      37));
  trinity->addPanel(new Panel(32, 0, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH,      37));
  #endif
  #ifdef PANELSETUP_MINITOWER
  for (uint8_t i = 0; i < 4; i++) trinity->addPanel(new Panel(i, i, 0, CLOCK_CLOCKWISE, COMPASS_NORTH, 10));
  trinity->addPanel(new Panel( 4, 4, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH,      6 ));
  #endif
  #ifdef PANELSETUP_CLOSET
  for (uint8_t i = 0; i < 4; i++) trinity->addPanel(new Panel(i, i, 0, CLOCK_CLOCKWISE, COMPASS_NORTH, 10));
  trinity->addPanel(new Panel( 4, 4, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH,      6 ));
  for (uint8_t i = 0; i < 6; i++) trinity->addPanel(new Panel(i+4, i+4, 0, CLOCK_CLOCKWISE, COMPASS_NORTH, LEDSAMOUNT_TRIANGLE));
  trinity->addPanel(new Panel( 4, 4, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH,      6 ));
  #endif
  #ifdef PANELSETUP_TEST
  trinity->addPanel(new Panel(0 0, 0, CLOCK_COUNTERWISE, COMPASS_SOUTH_EAST, 3));
  trinity->addPanel(new Panel(1 0, 0, CLOCK_COUNTERWISE, COMPASS_SOUTH,      3));
  trinity->addPanel(new Panel(2 0, 0, CLOCK_COUNTERWISE, COMPASS_SOUTH_WEST, 3));
  trinity->addPanel(new Panel(3 0, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH_EAST, 3));
  trinity->addPanel(new Panel(4 0, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH,      3));
  trinity->addPanel(new Panel(5 0, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH_WEST, 3));
  #endif

  trinity->finaliseSetup();

  currentShowingEffect = 0;

  Serial.println(F("---===SETUP COMPLETED===---"));



  for (uint16_t i = 0; i < trinity->getPanelAmount(); i++)
  {
    trinity->setPanelVfx(i, (VFXData){EFFECT_SPECIAL_SYNTH, COLOUR_RED, (uint16_t)(random(0, 10)*100), 1, true});
    for (uint16_t j = 0; j < trinity->getPanelDiodeAmount(i); j++)
    {
      //trinity->setPanelDiodeVfx(i, j, (VFXData){EFFECT_SPECIAL_SYNTH, COLOUR_RED, 0, 5, true});
      //offset++;
    }
  }
  
  /*
  trinity->setSpeed(5);

  trinity->setCustomPaletteColours(0, 0, (ColourRGB){255, 128, 0});
  trinity->setCustomPaletteColours(0, 1, (ColourRGB){255, 0, 255});
  trinity->setCustomPaletteColours(0, 2, (ColourRGB){0, 128, 255});
  trinity->setCustomPaletteAvailableColours(0, 3);

  for (uint16_t i = 0; i < trinity->getPanelAmount(); i++)
  {
    trinity->setPanelVfx(i, (VFXData){EFFECT_CUSTOM_DECODE, 0, 0, 1, true});
    //
    for (uint16_t j = 0; j < trinity->getPanelDiodeAmount(i); j++)
    {
      trinity->setPanelDiodeVfx(i, j, (VFXData){EFFECT_STOCK_STATIC, COLOUR_WHITE, 0, 1, true});
    }
    //
  }
  */



}

void loop()
{

  trinity->tick();

  #if ENABLECYCLING
  uint64_t currentMillis = millis();
  if(currentMillis >= (prevMillis+NEXTEFFECTTIME))
  {
    prevMillis = currentMillis;
    currentShowingEffect++;
    if (currentShowingEffect == 18)
    {
      currentShowingEffect = 0;
    }
    
    #ifdef ANIMATIONSET_WESTPOINT
    playAnimation_Reset();
    #endif

    switch (currentShowingEffect)
    {
      #ifdef ANIMATIONSET_STOCK
      #endif
      #ifdef ANIMATIONSET_WESTPOINT
      case 0:
      setAnimation_Westpoint_Default();
      break;
      case 1:
      setAnimation_Westpoint_BreathingLines();
      break;
      case 2:
      setAnimation_Westpoint_FlashingLines();
      break;
      case 3:
      setAnimation_Westpoint_Rain();
      break;
      case 4:
      setAnimation_Westpoint_Matrix();
      break;
      case 5:
      setAnimation_Westpoint_SuperRainbow();
      break;
      case 6:
      setAnimation_Westpoint_ADHDRainbow();
      break;
      case 7:
      setAnimation_Westpoint_BurningRainbow();
      break;
      case 8:
      setAnimation_Westpoint_HeartbeatTower();
      break;
      case 9:
      setAnimation_Westpoint_Stoplight();
      break;
      case 10:
      setAnimation_Westpoint_PowerRise();
      break;
      case 11:
      setAnimation_Westpoint_Fishbowl();
      break;
      case 12:
      setAnimation_Westpoint_Coils();
      break;
      case 13:
      setAnimation_Westpoint_AppearThing();
      break;
      case 14:
      setAnimation_Westpoint_AppearThing2();
      break;
      case 15:
      setAnimation_Westpoint_AppearThing3();
      break;
      case 16:
      setAnimation_Westpoint_AppearThing4();
      break;
      #endif
      default:
      if(DEBUGLEVEL >= DEBUG_ERRORS) Serial.println(F("ERROR: NO ANIMATIONSET SELECTED"));
      break;
    }
  #endif
}


