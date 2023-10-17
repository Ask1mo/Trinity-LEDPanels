#include "main.h"


#ifdef ANIMATIONSET_WESTPOINT
void playAnimation_Reset()
{
  Serial.print(F("playAnimation_Reset"));
  trinity->setSpeed(1);

  int diodeNumbers = 0;
  for (uint16_t i = 0; i < PANELAMOUNT; i++)
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
  Serial.print(F("setAnimation_Westpoint_FullWhite"));
  trinity->setSpeed(1);

  uint16_t offset = 0;
  for (uint16_t i = 0; i < PANELAMOUNT; i++)
  {
    trinity->setPanelVfx(i, (VFXData){EFFECT_STOCK_STATIC, COLOUR_WHITE, (uint16_t)random(0, 10)*15, 1, true});
    for (uint16_t j = 0; j < trinity->getPanelDiodeAmount(i); j++)
    {
      trinity->setPanelDiodeVfx(i, j, (VFXData){EFFECT_STOCK_STATIC, COLOUR_WHITE, 0, 5, true});
      offset++;
    }
  }
}
void setAnimation_Westpoint_Default()
{
  Serial.print(F("setAnimation_Westpoint_Default"));
  trinity->setSpeed(1);

  uint16_t offset = 0;
  for (uint16_t i = 0; i < PANELAMOUNT; i++)
  {
    trinity->setPanelVfx(i, (VFXData){EFFECT_STOCK_DECODE, COLOUR_RED, (uint16_t)random(0, 10)*15, 1, true});
    for (uint16_t j = 0; j < trinity->getPanelDiodeAmount(i); j++)
    {
      trinity->setPanelDiodeVfx(i, j, (VFXData){EFFECT_SPECIAL_RAINBOW, COLOUR_RED, 0, 5, true});
      offset++;
    }
  }
}
void setAnimation_Westpoint_BreathingLines()
{
  Serial.print(F("setAnimation_Westpoint_BREATHINGLINES"));
  trinity->setSpeed(1);

  uint16_t offset = 0;
  for (uint16_t i = 0; i < PANELAMOUNT; i++)
  {
    trinity->setPanelVfx(i, (VFXData){EFFECT_STOCK_DECODE, COLOUR_RED, (uint16_t)random(0, 10)*15, 1, true});
    for (uint16_t j = 0; j < trinity->getPanelDiodeAmount(i); j++)
    {
      trinity->setPanelDiodeVfx(i, j, (VFXData){EFFECT_STOCK_PAUSEDBREATHING, COLOUR_CYCLE, j, 20, true});
    }
  }
}
void setAnimation_Westpoint_FlashingLines()
{
  Serial.print(F("setAnimation_Westpoint_FlashingGLINES"));
  trinity->setSpeed(1);

  uint16_t offset = 0;
  for (uint16_t i = 0; i < PANELAMOUNT; i++)
  {
    trinity->setPanelVfx(i, (VFXData){EFFECT_STOCK_DECODE, COLOUR_RED, (uint16_t)random(0, 10)*15, 1, true});
    for (uint16_t j = 0; j < trinity->getPanelDiodeAmount(i); j++)
    {
      trinity->setPanelDiodeVfx(i, j, (VFXData){EFFECT_STOCK_PAUSEDFLASH, COLOUR_WHITE, j, 10, true});
    }  
  }
}
void setAnimation_Westpoint_Rain()
{
  Serial.print(F("setAnimation_Westpoint_Rain"));
  trinity->setSpeed(1);

  uint16_t offset = 0;
  for (uint16_t i = 0; i < PANELAMOUNT; i++)
  {
    trinity->setPanelVfx(i, (VFXData){EFFECT_STOCK_DECODE, COLOUR_RED, (uint16_t)random(0, 10)*15, 1, true});
    for (uint16_t j = 0; j < trinity->getPanelDiodeAmount(i); j++)
    {
      trinity->setPanelDiodeVfx(i, j, (VFXData){EFFECT_STOCK_PAUSEDFLASH, COLOUR_BLUE, j, (uint16_t)random(0, 10), true});
    }
  }
}
void setAnimation_Westpoint_Matrix()
{
  Serial.print(F("setAnimation_Westpoint_Matrix"));
  trinity->setSpeed(1);

  uint16_t offset = 0;
  for (uint16_t i = 0; i < PANELAMOUNT; i++)
  {
    trinity->setPanelVfx(i, (VFXData){EFFECT_STOCK_DECODE, COLOUR_RED, (uint16_t)random(0, 10)*15, 1, true});
    for (uint16_t j = 0; j < trinity->getPanelDiodeAmount(i); j++)
    {
      trinity->setPanelDiodeVfx(i, j, (VFXData){EFFECT_STOCK_DECODE, COLOUR_GREEN, j, 10, true});
    }
  }
}
void setAnimation_Westpoint_SuperRainbow()
{
  Serial.print(F("setAnimation_Westpoint_SuperRainbow"));
  trinity->setSpeed(3);

  uint16_t offset = 0;
  for (uint16_t i = 0; i < PANELAMOUNT; i++)
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
  Serial.print(F("setAnimation_Westpoint_ADHDRAINBOW"));
  trinity->setSpeed(1);

  uint16_t offset = 0;
  for (uint16_t i = 0; i < PANELAMOUNT; i++)
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
  Serial.print(F("setAnimation_Westpoint_BurningRainbow"));
  trinity->setSpeed(4);

  uint16_t offset = 0;
    for (uint16_t i = 0; i < PANELAMOUNT; i++)
    {
      trinity->setPanelVfx(i, (VFXData){EFFECT_STOCK_DECODE, COLOUR_RED, i*5, 10, true});
      for (uint16_t j = 0; j < trinity->getPanelDiodeAmount(i); j++)
      {
        trinity->setPanelDiodeVfx(i, j, (VFXData){EFFECT_SPECIAL_RAINBOW, COLOUR_RED, j*5, 10, true});
        offset++;
      }
  

      
    }
}
void setAnimation_Westpoint_HeartbeatTower()
{
  Serial.print(F("setAnimation_Westpoint_HeartbeatTower"));
  trinity->setSpeed(5);

  uint16_t offset = 0;
    for (uint16_t i = 0; i < PANELAMOUNT; i++)
    {
      trinity->setPanelVfx(i, (VFXData){EFFECT_STOCK_DECODE, COLOUR_RED, i*4, 1, true});
      for (uint16_t j = 0; j < trinity->getPanelDiodeAmount(i); j++)
      {
        trinity->setPanelDiodeVfx(i, j, (VFXData){EFFECT_STOCK_HEARTBEAT, COLOUR_RED, 0, 1, true});
        offset++;
      }
  

      
    }
}
void setAnimation_Westpoint_Stoplight()
{
  Serial.print(F("setAnimation_Westpoint_Stoplight"));
  trinity->setSpeed(8);

  uint16_t offset = 0;
    for (uint16_t i = 0; i < PANELAMOUNT; i++)
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
  Serial.print(F("setAnimation_Westpoint_Powerrize"));
  trinity->setSpeed(15);

  uint16_t offset = 0;
    for (uint16_t i = 0; i < PANELAMOUNT; i++)
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
  Serial.print(F("setAnimation_Westpoint_Fishbowl"));
  trinity->setSpeed(10);

  uint16_t offset = 0;
  for (uint16_t i = 0; i < PANELAMOUNT; i++)
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

  for (uint8_t i = 0; i < PANELAMOUNT; i++)
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
  Serial.print(F("setAnimation_Westpoint_AppearThing"));
  trinity->setSpeed(20);

  uint16_t offset = 0;

  for (uint8_t i = 0; i < PANELAMOUNT; i++)
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
  Serial.print(F("setAnimation_Westpoint_AppearThing2"));
  trinity->setSpeed(10);

  uint16_t offset = 0;

  for (uint8_t i = 0; i < PANELAMOUNT; i++)
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
  Serial.print(F("setAnimation_Westpoint_AppearThing3"));
  trinity->setSpeed(10);

  uint16_t offset = 0;

  for (uint8_t i = 0; i < PANELAMOUNT; i++)
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
  Serial.print(F("setAnimation_Westpoint_AppearThing4"));
  trinity->setSpeed(4);

  uint16_t offset = 0;

  for (uint8_t i = 0; i < PANELAMOUNT; i++)
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
  Serial.print(F("setAnimation_Westpoint_ColourBlink"));
  trinity->setSpeed(4);

  uint16_t offset = 0;

  for (uint8_t i = 0; i < PANELAMOUNT; i++)
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
  Serial.begin(115200);
  
  trinity = new Trinity(PIN_LEDS, PIN_BUTTON, PIN_LIGHTSENSOR, 60);

  currentShowingEffect = 0;

  Serial.println(F("---===SETUP COMPLETED===---"));
}

void loop()
{
  trinity->tick();

  if(ENABLECYCLING)
  {
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
        Serial.println(F("WARNING: NO ANIMATIONSET SELECTED"));
        break;
      }
    }
  }
}


