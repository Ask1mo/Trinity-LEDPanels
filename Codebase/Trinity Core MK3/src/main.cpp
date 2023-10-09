#include "main.h"

void playResetAnimation()
{
  int panelMultiplier = 2;

  trinity->setBrightness(255);
  trinity->setSpeed(1);

  for (uint16_t i = 0; i < PANELAMOUNT; i++)
  {
    trinity->setPanelVfx(i, (VFXData){EFFECT_STOCK_APPEAR, COLOUR_RED, (i*panelMultiplier, 1, true)});
    for (uint16_t j = 0; j < trinity->getPanelDiodeAmount(i); j++)
    {
      trinity->setPanelDiodeVfx(i, j, (VFXData){EFFECT_STOCK_FLASH, COLOUR_VIOLET, j, 1, false});
    }

    
  }


  for (int i = 0; i < (PANELAMOUNT*panelMultiplier*2); i++) //*2 is just to make sure all the diodes in every panel have lit up
  {
    delay(1);
    trinity->manualTick();
    trinity->manualPrint();
  }

  delay(1000);
  
}
void playDroneResetAnimation()
{
  trinity->setBrightness(255);
  trinity->setSpeed(5);

  for (uint16_t i = 0; i < PANELAMOUNT; i++)
  {
    trinity->setPanelVfx(i, (VFXData){EFFECT_STOCK_APPEAR, COLOUR_RED, i, 1, true});
    for (uint16_t j = 0; j < trinity->getPanelDiodeAmount(i); j++)
    {
      trinity->setPanelDiodeVfx(i, j, (VFXData){EFFECT_STOCK_PLANE, COLOUR_WHITE, 0, 1, false});
    }
  }


  for (int i = 0; i < 20; i++)
  {
    trinity->manualTick();
    trinity->manualPrint();
  }
  
}

void setAnimation_FullWhite()
{
  Serial.print(F("setAnimation_FullWhite"));


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
void setAnimation_Default()
{
  Serial.print(F("setAnimation_Default"));


    uint16_t offset = 0;
    for (uint16_t i = 0; i < PANELAMOUNT; i++)
    {
      trinity->setPanelVfx(i, (VFXData){EFFECT_STOCK_APPEAR, COLOUR_RED, (uint16_t)random(0, 10)*15, 1, true});
      for (uint16_t j = 0; j < trinity->getPanelDiodeAmount(i); j++)
      {
        trinity->setPanelDiodeVfx(i, j, (VFXData){EFFECT_SPECIAL_RAINBOW, COLOUR_RED, 0, 5, true});
        offset++;
      }

      
    }
}
void setAnimation_BreathingLines()
{
  Serial.print(F("setAnimation_BREATHINGLINES"));
  uint16_t offset = 0;
    for (uint16_t i = 0; i < PANELAMOUNT; i++)
    {
      trinity->setPanelVfx(i, (VFXData){EFFECT_STOCK_APPEAR, COLOUR_RED, (uint16_t)random(0, 10)*15, 1, true});
      for (uint16_t j = 0; j < trinity->getPanelDiodeAmount(i); j++)
      {
        trinity->setPanelDiodeVfx(i, j, (VFXData){EFFECT_STOCK_PAUSEDBREATHING, COLOUR_CYCLE, j, 20, true});
      }

      
    }
}
void setAnimation_FlashingLines()
{
  Serial.print(F("setAnimation_FlashingGLINES"));
  uint16_t offset = 0;
    for (uint16_t i = 0; i < PANELAMOUNT; i++)
    {
      trinity->setPanelVfx(i, (VFXData){EFFECT_STOCK_APPEAR, COLOUR_RED, (uint16_t)random(0, 10)*15, 1, true});
      for (uint16_t j = 0; j < trinity->getPanelDiodeAmount(i); j++)
      {
        trinity->setPanelDiodeVfx(i, j, (VFXData){EFFECT_STOCK_PAUSEDFLASH, COLOUR_WHITE, j, 10, true});
      }

      
    }
}
void setAnimation_Rain()
{
  Serial.print(F("setAnimation_Rain"));
  uint16_t offset = 0;
    for (uint16_t i = 0; i < PANELAMOUNT; i++)
    {
      trinity->setPanelVfx(i, (VFXData){EFFECT_STOCK_APPEAR, COLOUR_RED, (uint16_t)random(0, 10)*15, 1, true});
      for (uint16_t j = 0; j < trinity->getPanelDiodeAmount(i); j++)
      {
        trinity->setPanelDiodeVfx(i, j, (VFXData){EFFECT_STOCK_PAUSEDFLASH, COLOUR_BLUE, j, (uint16_t)random(0, 10), true});
      }

      
    }
}
void setAnimation_Matrix()
{
  Serial.print(F("setAnimation_Matrix"));
  uint16_t offset = 0;
    for (uint16_t i = 0; i < PANELAMOUNT; i++)
    {
      trinity->setPanelVfx(i, (VFXData){EFFECT_STOCK_APPEAR, COLOUR_RED, (uint16_t)random(0, 10)*15, 1, true});
      for (uint16_t j = 0; j < trinity->getPanelDiodeAmount(i); j++)
      {
        trinity->setPanelDiodeVfx(i, j, (VFXData){EFFECT_STOCK_APPEAR, COLOUR_GREEN, j, 10, true});
      }

      
    }
}
void setAnimation_SuperRainbow()
{
  Serial.print(F("setAnimation_SuperRainbow"));
  trinity->setSpeed(5);
  uint16_t offset = 0;
    for (uint16_t i = 0; i < PANELAMOUNT; i++)
    {
      trinity->setPanelVfx(i, (VFXData){EFFECT_STOCK_APPEAR, COLOUR_RED, 0, 1, true});
      for (uint16_t j = 0; j < trinity->getPanelDiodeAmount(i); j++)
      {
        trinity->setPanelDiodeVfx(i, j, (VFXData){EFFECT_SPECIAL_RAINBOW, COLOUR_RED, offset, 10, true});
        offset++;
      }
  

      
    }
}
void setAnimation_ADHDRainbow()
{
  Serial.print(F("setAnimation_ADHDRAINBOW"));
  //trinity->setSpeed(10);
  uint16_t offset = 0;
    for (uint16_t i = 0; i < PANELAMOUNT; i++)
    {
      trinity->setPanelVfx(i, (VFXData){EFFECT_STOCK_APPEAR, COLOUR_RED, 0, 1, true});
      for (uint16_t j = 0; j < trinity->getPanelDiodeAmount(i); j++)
      {
        trinity->setPanelDiodeVfx(i, j, (VFXData){EFFECT_SPECIAL_RAINBOW, COLOUR_RED, offset, 100, true});
        offset++;
      }
      
    }

    for (int i = 0; i < 500; i++)
  {
    trinity->manualTick();
  }
}
void setAnimation_BurningRainbow()
{
  Serial.print(F("setAnimation_BurningRainbow"));
  trinity->setSpeed(10);

  uint16_t offset = 0;
    for (uint16_t i = 0; i < PANELAMOUNT; i++)
    {
      trinity->setPanelVfx(i, (VFXData){EFFECT_STOCK_APPEAR, COLOUR_RED, i*5, 10, true});
      for (uint16_t j = 0; j < trinity->getPanelDiodeAmount(i); j++)
      {
        trinity->setPanelDiodeVfx(i, j, (VFXData){EFFECT_SPECIAL_RAINBOW, COLOUR_RED, j*5, 10, true});
        offset++;
      }
  

      
    }
}
void setAnimation_LowFPSRainbow()
{
  Serial.print(F("setAnimation_LowFPSRainbow"));
  trinity->setSpeed(100);

  uint16_t offset = 0;
    for (uint16_t i = 0; i < PANELAMOUNT; i++)
    {
      trinity->setPanelVfx(i, (VFXData){EFFECT_STOCK_APPEAR, COLOUR_RED, i*5, 10, true});
      for (uint16_t j = 0; j < trinity->getPanelDiodeAmount(i); j++)
      {
        trinity->setPanelDiodeVfx(i, j, (VFXData){EFFECT_SPECIAL_RAINBOW, COLOUR_RED, j*5, 10, true});
        offset++;
      }
  

      
    }
}
void setAnimation_HeartbeatTower()
{
  Serial.print(F("setAnimation_HeartbeatTower"));
  trinity->setSpeed(10);

  uint16_t offset = 0;
    for (uint16_t i = 0; i < PANELAMOUNT; i++)
    {
      trinity->setPanelVfx(i, (VFXData){EFFECT_STOCK_APPEAR, COLOUR_RED, i*4, 1, true});
      for (uint16_t j = 0; j < trinity->getPanelDiodeAmount(i); j++)
      {
        trinity->setPanelDiodeVfx(i, j, (VFXData){EFFECT_STOCK_HEARTBEAT, COLOUR_RED, 0, 1, true});
        offset++;
      }
  

      
    }
}
void setAnimation_Stoplight()
{
  Serial.print(F("setAnimation_Stoplight"));
  trinity->setSpeed(25);

  uint16_t offset = 0;
    for (uint16_t i = 0; i < PANELAMOUNT; i++)
    {
      trinity->setPanelVfx(i, (VFXData){EFFECT_STOCK_APPEAR, COLOUR_RED, offset, 1, true});
      for (uint16_t j = 0; j < trinity->getPanelDiodeAmount(i); j++)
      {
        trinity->setPanelDiodeVfx(i, j, (VFXData){EFFECT_STOCK_PAUSEDFLASH, COLOUR_CYCLE, offset, 1, true});
        offset+=3;
      }
  

      
    }
}
void setAnimation_PowerRise()
{
  Serial.print(F("setAnimation_Powerrize"));
  trinity->setSpeed(50);

  uint16_t offset = 0;
    for (uint16_t i = 0; i < PANELAMOUNT; i++)
    {
      trinity->setPanelVfx(i, (VFXData){EFFECT_STOCK_APPEAR, COLOUR_RED, offset, 1, true});
      for (uint16_t j = 0; j < trinity->getPanelDiodeAmount(i); j++)
      {
        trinity->setPanelDiodeVfx(i, j, (VFXData){EFFECT_STOCK_PAUSEDFLASH, COLOUR_CYAN, offset, 1, true});
        offset++;
      }
  

      
    }
}
void setAnimation_Fishbowl()
{
  Serial.print(F("setAnimation_Fishbowl"));
  trinity->setSpeed(10);

  uint16_t offset = 0;
    for (uint16_t i = 0; i < PANELAMOUNT; i++)
    {
      trinity->setPanelVfx(i, (VFXData){EFFECT_STOCK_APPEAR, COLOUR_RED, offset, 1, true});
      for (uint16_t j = 0; j < trinity->getPanelDiodeAmount(i); j++)
      {
        trinity->setPanelDiodeVfx(i, j, (VFXData){EFFECT_STOCK_PAUSEDFLASH, COLOUR_CYCLE, offset, 1, true});
        offset+=10;
      }
  

      
    }


  for (int i = 0; i < 900; i++)
  {
    trinity->manualTick();
  }
}
void setAnimation_Coils()
{
  Serial.print(F("setAnimation_Coils"));
  trinity->setSpeed(10);

  uint16_t offset = 0;

  for (uint8_t i = 0; i < PANELAMOUNT; i++)
  {
    trinity->setPanelVfx(i, (VFXData){EFFECT_STOCK_APPEAR, COLOUR_RED, 0, 1, true});
    for (uint8_t j = 0; j < trinity->getPanelDiodeAmount(i); j++)
    {
      trinity->setPanelDiodeVfx(i, i, VFXData{ EFFECT_STOCK_APPEAR, COLOUR_CYCLE, offset, 1, true});
      offset++;
    }
  }
}
void setAnimation_AppearThing()
{
  Serial.print(F("setAnimation_AppearThing"));
  trinity->setSpeed(20);

  uint16_t offset = 0;

  for (uint8_t i = 0; i < PANELAMOUNT; i++)
  {
    trinity->setPanelVfx(i, (VFXData){EFFECT_STOCK_APPEAR, COLOUR_RED, (uint16_t)random(0, 100), 1, true});
    for (uint8_t j = 0; j < trinity->getPanelDiodeAmount(i); j++)
    {
      trinity->setPanelDiodeVfx(i, i, VFXData{ EFFECT_STOCK_APPEAR, COLOUR_CYCLE, (uint16_t)random(0, 100), 1, true});
      offset++;
    }
  }

}
void setAnimation_AppearThing2()
{
  Serial.print(F("setAnimation_AppearThing2"));
  trinity->setSpeed(10);

  uint16_t offset = 0;

  for (uint8_t i = 0; i < PANELAMOUNT; i++)
  {
    trinity->setPanelVfx(i, (VFXData){EFFECT_STOCK_APPEAR, COLOUR_RED, (uint16_t)random(0, 100), 1, true});
    for (uint8_t j = 0; j < trinity->getPanelDiodeAmount(i); j++)
    {
      trinity->setPanelDiodeVfx(i, i, VFXData{ EFFECT_STOCK_STATIC, COLOUR_CYCLE, (uint16_t)random(0, 100), 1, true});
      offset++;
    }
  }

}
void setAnimation_AppearThing3()
{
  Serial.print(F("setAnimation_AppearThing3"));
  trinity->setSpeed(10);

  uint16_t offset = 0;

  for (uint8_t i = 0; i < PANELAMOUNT; i++)
  {
    trinity->setPanelVfx(i, (VFXData){EFFECT_STOCK_APPEAR, COLOUR_RED, 0, 1, true});
    for (uint8_t j = 0; j < trinity->getPanelDiodeAmount(i); j++)
    {
      trinity->setPanelDiodeVfx(i, i, VFXData{ EFFECT_STOCK_STATIC, COLOUR_CYCLE, (uint16_t)random(0, 1000), 1, true});
      offset++;
    }
  }
}
void setAnimation_AppearThing4()
{
  Serial.print(F("setAnimation_AppearThing4"));
  trinity->setSpeed(4);

  uint16_t offset = 0;

  for (uint8_t i = 0; i < PANELAMOUNT; i++)
  {
    trinity->setPanelVfx(i, (VFXData){EFFECT_STOCK_APPEAR, COLOUR_RED, 0, 1, true});
    for (uint8_t j = 0; j < trinity->getPanelDiodeAmount(i); j++)
    {
      trinity->setPanelDiodeVfx(i, i, VFXData{ EFFECT_STOCK_PAUSEDFLASH, COLOUR_CYCLE, (uint16_t)random(0, 250), 1, true});
      offset++;
    }
  }
}
void setAnimation_ColourBlink()
{
  Serial.print(F("setAnimation_ColourBlink"));
  trinity->setSpeed(4);

  uint16_t offset = 0;

  for (uint8_t i = 0; i < PANELAMOUNT; i++)
  {
    trinity->setPanelVfx(i, (VFXData){EFFECT_STOCK_APPEAR, COLOUR_RED, 0, 1, true});
    for (uint8_t j = 0; j < trinity->getPanelDiodeAmount(i); j++)
    {
      trinity->setPanelDiodeVfx(i, i, VFXData{ EFFECT_STOCK_STATIC, COLOUR_CYCLE, i, 1, true});
      offset++;
    }
  }

  for (int i = 0; i < 64; i++)
  {
    trinity->manualTick();
  }
}


void setup()
{
  Serial.begin(115200);
  
  trinity = new Trinity(PIN_LEDS, PIN_BUTTON, PIN_LIGHTSENSOR, 20);

  currentShowingEffect = 0;

  Serial.println(F("---===SETUP COMPLETED===---"));
}

void loop()
{
  trinity->tick();

  //Cycle code?
    uint64_t currentMillis = millis();
    if(currentMillis >= (prevMillis+NEXTEFFECTTIME))
    {
      prevMillis = currentMillis;
      currentShowingEffect++;
      if (currentShowingEffect == 18)
      {
        currentShowingEffect = 0;
      }
      playResetAnimation();
      

      switch (currentShowingEffect)
      {
        case 0:
        setAnimation_Default();
        break;
        case 1:
        setAnimation_BreathingLines();
        break;
        case 2:
        setAnimation_FlashingLines();
        break;
        case 3:
        setAnimation_Rain();
        break;
        case 4:
        setAnimation_Matrix();
        break;
        case 5:
        setAnimation_SuperRainbow();
        break;
        case 6:
        setAnimation_ADHDRainbow();
        break;
        case 7:
        setAnimation_BurningRainbow();
        break;
        case 8:
        setAnimation_LowFPSRainbow();
        break;
        case 9:
        setAnimation_HeartbeatTower();
        break;
        case 10:
        setAnimation_Stoplight();
        break;
        case 11:
        setAnimation_PowerRise();
        break;
        case 12:
        setAnimation_Fishbowl();
        break;
        case 13:
        setAnimation_Coils();
        break;
        case 14:
        setAnimation_AppearThing();
        break;
        case 15:
        setAnimation_AppearThing2();
        break;
        case 16:
        setAnimation_AppearThing3();
        break;
        case 17:
        setAnimation_AppearThing4();
        break;

      }
    }
//End cycle code?
}


