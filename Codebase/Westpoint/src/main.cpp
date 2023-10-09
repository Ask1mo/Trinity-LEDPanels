#include "main.h"

void receiveEvent(int howMany)
{
  Serial.print("!");
  if(Wire.available())
  {
    receivedCode = Wire.read(); // receive message as a character
    Wire.write(receivedCode);
    Serial.print(F("Received: "));
    Serial.println(receivedCode);
    newDataReceived = true;
  }
}

void setDronePercentage(int ringNumber)
{
  switch (ringNumber)
  {
    case 0:
    {
      for (uint16_t i = 0; i < PANELAMOUNT; i++)
      {
        panels[i]->setBrightness(BRIGHTNESS_3_MAX);
      }
    }
    break;

    case 1:
    {
      for (uint16_t i = 0; i < PANELAMOUNT_TOWERONLY; i++)
      {
        if (i > 7)  panels[i]->setBrightness(BRIGHTNESS_0_OFF);
        else        panels[i]->setBrightness(BRIGHTNESS_3_MAX);
      }
    }
    break;

    case 2:
    {
      for (uint16_t i = 0; i < PANELAMOUNT_TOWERONLY; i++)
      {
        if (i > 14) panels[i]->setBrightness(BRIGHTNESS_0_OFF);
        else        panels[i]->setBrightness(BRIGHTNESS_3_MAX);
      }
    }
    break;

    case 3:
    {
      for (uint16_t i = 0; i < PANELAMOUNT_TOWERONLY; i++)
      {
        if (i > 21) panels[i]->setBrightness(BRIGHTNESS_0_OFF);
        else        panels[i]->setBrightness(BRIGHTNESS_3_MAX);
      }
    }
    break;

    case 4:
    {
      for (uint16_t i = 0; i < PANELAMOUNT_TOWERONLY; i++)
      {
        if (i > 28) panels[i]->setBrightness(BRIGHTNESS_0_OFF);
        else        panels[i]->setBrightness(BRIGHTNESS_3_MAX);
      }
    }
    break;
  
  }
  
}

void playResetAnimation()
{
  int panelMultiplier = 2;

  ledManager->setBrightness(255);
  ledManager->setSpeed(1);

  for (uint16_t i = 0; i < PANELAMOUNT; i++)
  {
    panels[i]->setDataFx(EFFECT_STOCK_APPEAR, COLOUR_RED, (i*panelMultiplier), 1, true, false);
    for (uint16_t j = 0; j < panels[i]->getDiodeAmount(); j++)
    {
      panels[i]->setDiodeDataFx(j, BRIGHTNESS_3_MAX, EFFECT_STOCK_FLASH, COLOUR_VIOLET, j, 1, false);
    }

  Serial.print("Editing panel ");
  Serial.println(i);
  }


  for (int i = 0; i < (PANELAMOUNT*panelMultiplier*2); i++) //*2 is just to make sure all the diodes in every panel have lit up
  {
    delay(1);
    ledManager->tick();
    ledManager->print();
  }

  delay(1000);
  
}

void playDroneResetAnimation(uint8_t ringNumber)
{
  ledManager->setBrightness(255);
  ledManager->setSpeed(5);

  for (uint16_t i = 0; i < (PANELAMOUNT_TOWERONLY-1); i++)
  {
    panels[i]->setDataFx(EFFECT_STOCK_APPEAR, COLOUR_RED, i, 1, true, false);
    for (uint16_t j = 0; j < panels[i]->getDiodeAmount(); j++)
    {
      panels[i]->setDiodeDataFx(j, BRIGHTNESS_3_MAX, EFFECT_STOCK_PLANE, COLOUR_WHITE, 0, 1, false);
    }

    Serial.print("Editing panel ");
    Serial.println(i);
  }

  for (uint16_t i = PANELAMOUNT_TOWERONLY; i < PANELAMOUNT; i++)
  {
    panels[i]->setDataFx(EFFECT_STOCK_APPEAR, COLOUR_RED, 0, 1, true, false);

    if (i == (PANELAMOUNT_TOWERONLY+ringNumber-1))
    {
      for (uint16_t j = 0; j < panels[i]->getDiodeAmount(); j++)
      {
        panels[i]->setDiodeDataFx(j, BRIGHTNESS_3_MAX, EFFECT_STOCK_PLANE, COLOUR_WHITE, 0, 1, false);
      }
    }
    else
    {
      for (uint16_t j = 0; j < panels[i]->getDiodeAmount(); j++)
      {
        panels[i]->setDiodeDataFx(j, BRIGHTNESS_3_MAX, EFFECT_STOCK_STATIC, COLOUR_BLACK, 0, 1, false);
      }
    }


    

    Serial.print("Editing Blink Ringpanel ");
    Serial.println(i);
  }


  for (int i = 0; i < 20; i++)
  {
    ledManager->tick();
    ledManager->print();
  }
  
}

void setRingAnimations(uint8_t ringNumber)
{
  for (uint16_t i = PANELAMOUNT_TOWERONLY; i < PANELAMOUNT; i++)
  {
    panels[i]->setDataFx(EFFECT_STOCK_APPEAR, COLOUR_RED, 0, 1, true, false);

    if (i == (PANELAMOUNT_TOWERONLY+ringNumber-1))
    {
      Serial.print("Panel ");
      Serial.print(i);
      Serial.println(" was target!!!");

      for (uint16_t j = 0; j < panels[i]->getDiodeAmount(); j++)
      {
        panels[i]->setDiodeDataFx(j, BRIGHTNESS_3_MAX, EFFECT_SPECIAL_RAINBOW, COLOUR_BLACK, j*5, 5, false);
      }
    }
    else
    {
      Serial.print("Panel ");
      Serial.print(i);
      Serial.println(" was not target");

      for (uint16_t j = 0; j < panels[i]->getDiodeAmount(); j++)
      {
        panels[i]->setDiodeDataFx(j, BRIGHTNESS_3_MAX, EFFECT_SPECIAL_RAINBOW, COLOUR_BLACK, 0, 1, false);
      }
    }


    Serial.print("Editing Rainbow Ringpanel ");
    Serial.println(i);
  }
}

void setAnimation_FullWhite()
{
  


    uint16_t offset = 0;
    for (uint16_t i = 0; i < PANELAMOUNT; i++)
    {
    panels[i]->setDataFx(EFFECT_STOCK_STATIC, COLOUR_WHITE, random(0, 10)*15, 1, true, true);
    for (uint16_t j = 0; j < panels[i]->getDiodeAmount(); j++)
    {
      panels[i]->setDiodeDataFx(j, BRIGHTNESS_3_MAX, EFFECT_STOCK_STATIC, COLOUR_WHITE, 0, 5, true);
      offset++;
    }

    Serial.print("Editing panel ");
    Serial.println(i);
    }
}

void setAnimation_Default()
{
  


    uint16_t offset = 0;
    for (uint16_t i = 0; i < PANELAMOUNT; i++)
    {
    panels[i]->setDataFx(EFFECT_STOCK_APPEAR, COLOUR_RED, random(0, 10)*15, 1, true, true);
    for (uint16_t j = 0; j < panels[i]->getDiodeAmount(); j++)
    {
      panels[i]->setDiodeDataFx(j, BRIGHTNESS_3_MAX, EFFECT_SPECIAL_RAINBOW, COLOUR_RED, 0, 5, true);
      offset++;
    }

    Serial.print("Editing panel ");
    Serial.println(i);
    }
}
void setAnimation_BreathingLines()
{
  uint16_t offset = 0;
    for (uint16_t i = 0; i < PANELAMOUNT; i++)
    {
      panels[i]->setDataFx(EFFECT_STOCK_APPEAR, COLOUR_RED, random(0, 10)*15, 1, true, true);
      for (uint16_t j = 0; j < panels[i]->getDiodeAmount(); j++)
      {
        panels[i]->setDiodeDataFx(j, BRIGHTNESS_3_MAX, EFFECT_STOCK_PAUSEDBREATHING, COLOUR_CYCLE, j, 20, true);
      }

      Serial.print("Editing panel ");
      Serial.println(i);
    }
}
void setAnimation_FlashingLines()
{
  uint16_t offset = 0;
    for (uint16_t i = 0; i < PANELAMOUNT; i++)
    {
      panels[i]->setDataFx(EFFECT_STOCK_APPEAR, COLOUR_RED, random(0, 10)*15, 1, true, true);
      for (uint16_t j = 0; j < panels[i]->getDiodeAmount(); j++)
      {
        panels[i]->setDiodeDataFx(j, BRIGHTNESS_3_MAX, EFFECT_STOCK_PAUSEDFLASH, COLOUR_WHITE, j, 10, true);
      }

      Serial.print("Editing panel ");
      Serial.println(i);
    }
}
void setAnimation_Rain()
{
  uint16_t offset = 0;
    for (uint16_t i = 0; i < PANELAMOUNT; i++)
    {
      panels[i]->setDataFx(EFFECT_STOCK_APPEAR, COLOUR_RED, random(0, 10)*15, 1, true, true);
      for (uint16_t j = 0; j < panels[i]->getDiodeAmount(); j++)
      {
        panels[i]->setDiodeDataFx(j, BRIGHTNESS_3_MAX, EFFECT_STOCK_PAUSEDFLASH, COLOUR_BLUE, j, random(0, 10), true);
      }

      Serial.print("Editing panel ");
      Serial.println(i);
    }
}
void setAnimation_Matrix()
{
  uint16_t offset = 0;
    for (uint16_t i = 0; i < PANELAMOUNT; i++)
    {
      panels[i]->setDataFx(EFFECT_STOCK_APPEAR, COLOUR_RED, random(0, 10)*15, 1, true, true);
      for (uint16_t j = 0; j < panels[i]->getDiodeAmount(); j++)
      {
        panels[i]->setDiodeDataFx(j, BRIGHTNESS_3_MAX, EFFECT_STOCK_APPEAR, COLOUR_GREEN, j, 10, true);
      }

      Serial.print("Editing panel ");
      Serial.println(i);
    }
}
void setAnimation_SuperRainbow()
{
  ledManager->setSpeed(5);
  uint16_t offset = 0;
    for (uint16_t i = 0; i < PANELAMOUNT; i++)
    {
      panels[i]->setDataFx(EFFECT_STOCK_APPEAR, COLOUR_RED, 0, 1, true, true);
      for (uint16_t j = 0; j < panels[i]->getDiodeAmount(); j++)
      {
        panels[i]->setDiodeDataFx(j, BRIGHTNESS_3_MAX, EFFECT_SPECIAL_RAINBOW, COLOUR_RED, offset, 10, true);
        offset++;
      }
  

      Serial.print("Editing panel ");
      Serial.println(i);
    }
}
void setAnimation_ADHDRainbow()
{
  //ledManager->setSpeed(10);
  uint16_t offset = 0;
    for (uint16_t i = 0; i < PANELAMOUNT; i++)
    {
      panels[i]->setDataFx(EFFECT_STOCK_APPEAR, COLOUR_RED, 0, 1, true, true);
      for (uint16_t j = 0; j < panels[i]->getDiodeAmount(); j++)
      {
        panels[i]->setDiodeDataFx(j, BRIGHTNESS_3_MAX, EFFECT_SPECIAL_RAINBOW, COLOUR_RED, offset, 100, true);
        offset++;
      }
      Serial.print("Editing panel ");
      Serial.println(i);
    }

    for (int i = 0; i < 500; i++)
  {
    ledManager->tick();
  }
}
void setAnimation_BurningRainbow()
{
  ledManager->setSpeed(10);

  uint16_t offset = 0;
    for (uint16_t i = 0; i < PANELAMOUNT; i++)
    {
      panels[i]->setDataFx(EFFECT_STOCK_APPEAR, COLOUR_RED, i*5, 10, true, true);
      for (uint16_t j = 0; j < panels[i]->getDiodeAmount(); j++)
      {
        panels[i]->setDiodeDataFx(j, BRIGHTNESS_3_MAX, EFFECT_SPECIAL_RAINBOW, COLOUR_RED, j*5, 10, true);
        offset++;
      }
  

      Serial.print("Editing panel ");
      Serial.println(i);
    }
}
void setAnimation_LowFPSRainbow()
{
  ledManager->setSpeed(100);

  uint16_t offset = 0;
    for (uint16_t i = 0; i < PANELAMOUNT; i++)
    {
      panels[i]->setDataFx(EFFECT_STOCK_APPEAR, COLOUR_RED, i*5, 10, true, true);
      for (uint16_t j = 0; j < panels[i]->getDiodeAmount(); j++)
      {
        panels[i]->setDiodeDataFx(j, BRIGHTNESS_3_MAX, EFFECT_SPECIAL_RAINBOW, COLOUR_RED, j*5, 10, true);
        offset++;
      }
  

      Serial.print("Editing panel ");
      Serial.println(i);
    }
}
void setAnimation_HeartbeatTower()
{
  ledManager->setSpeed(10);

  uint16_t offset = 0;
    for (uint16_t i = 0; i < PANELAMOUNT; i++)
    {
      panels[i]->setDataFx(EFFECT_STOCK_APPEAR, COLOUR_RED, i*4, 1, true, true);
      for (uint16_t j = 0; j < panels[i]->getDiodeAmount(); j++)
      {
        panels[i]->setDiodeDataFx(j, BRIGHTNESS_3_MAX, EFFECT_STOCK_HEARTBEAT, COLOUR_RED, 0, 1, true);
        offset++;
      }
  

      Serial.print("Editing panel ");
      Serial.println(i);
    }
}
void setAnimation_Stoplight()
{
  ledManager->setSpeed(25);

  uint16_t offset = 0;
    for (uint16_t i = 0; i < PANELAMOUNT; i++)
    {
      panels[i]->setDataFx(EFFECT_STOCK_APPEAR, COLOUR_RED, offset, 1, true, true);
      for (uint16_t j = 0; j < panels[i]->getDiodeAmount(); j++)
      {
        panels[i]->setDiodeDataFx(j, BRIGHTNESS_3_MAX, EFFECT_STOCK_PAUSEDFLASH, COLOUR_CYCLE, offset, 1, true);
        offset+=3;
      }
  

      Serial.print("Editing panel ");
      Serial.println(i);
    }
}
void setAnimation_PowerRise()
{
  ledManager->setSpeed(50);

  uint16_t offset = 0;
    for (uint16_t i = 0; i < PANELAMOUNT; i++)
    {
      panels[i]->setDataFx(EFFECT_STOCK_APPEAR, COLOUR_RED, offset, 1, true, true);
      for (uint16_t j = 0; j < panels[i]->getDiodeAmount(); j++)
      {
        panels[i]->setDiodeDataFx(j, BRIGHTNESS_3_MAX, EFFECT_STOCK_PAUSEDFLASH, COLOUR_CYAN, offset, 1, true);
        offset++;
      }
  

      Serial.print("Editing panel ");
      Serial.println(i);
    }
}
void setAnimation_Fishbowl()
{
  ledManager->setSpeed(10);

  uint16_t offset = 0;
    for (uint16_t i = 0; i < PANELAMOUNT; i++)
    {
      panels[i]->setDataFx(EFFECT_STOCK_APPEAR, COLOUR_RED, offset, 1, true, true);
      for (uint16_t j = 0; j < panels[i]->getDiodeAmount(); j++)
      {
        panels[i]->setDiodeDataFx(j, BRIGHTNESS_3_MAX, EFFECT_STOCK_PAUSEDFLASH, COLOUR_CYCLE, offset, 1, true);
        offset+=10;
      }
  

      Serial.print("Editing panel ");
      Serial.println(i);
    }


  for (int i = 0; i < 900; i++)
  {
    ledManager->tick();
  }
}
void setAnimation_Coils()
{
  ledManager->setSpeed(10);

  uint16_t offset = 0;

  for (uint8_t i = 0; i < PANELAMOUNT; i++)
  {
    panels[i]->setDataFx( EFFECT_STOCK_APPEAR, COLOUR_RED, 0, 1, true, true);
    for (uint8_t j = 0; j < panels[i]->getDiodeAmount(); j++)
    {
      panels[i]->setDiodeDataFx(j, 255, EFFECT_STOCK_APPEAR, COLOUR_CYCLE, offset, 1, true);
      offset++;
    }
  }
}
void setAnimation_AppearThing()
{
  ledManager->setSpeed(20);

  uint16_t offset = 0;

  for (uint8_t i = 0; i < PANELAMOUNT; i++)
  {
    panels[i]->setDataFx( EFFECT_STOCK_APPEAR, COLOUR_RED, random(0,100), 1, true, true);
    for (uint8_t j = 0; j < panels[i]->getDiodeAmount(); j++)
    {
      panels[i]->setDiodeDataFx(j, 255, EFFECT_STOCK_APPEAR, COLOUR_CYCLE, random(0,100), 1, true);
      offset++;
    }
  }

}
void setAnimation_AppearThing2()
{
  ledManager->setSpeed(10);

  uint16_t offset = 0;

  for (uint8_t i = 0; i < PANELAMOUNT; i++)
  {
    panels[i]->setDataFx( EFFECT_STOCK_APPEAR, COLOUR_RED, random(0,100), 1, true, true);
    for (uint8_t j = 0; j < panels[i]->getDiodeAmount(); j++)
    {
      panels[i]->setDiodeDataFx(j, 255, EFFECT_STOCK_STATIC, COLOUR_CYCLE, random(0,100), 1, true);
      offset++;
    }
  }

}
void setAnimation_AppearThing3()
{
  ledManager->setSpeed(10);

  uint16_t offset = 0;

  for (uint8_t i = 0; i < PANELAMOUNT; i++)
  {
    panels[i]->setDataFx( EFFECT_STOCK_APPEAR, COLOUR_RED, 0, 1, true, true);
    for (uint8_t j = 0; j < panels[i]->getDiodeAmount(); j++)
    {
      panels[i]->setDiodeDataFx(j, 255, EFFECT_STOCK_STATIC, COLOUR_CYCLE, random(0,1000), 1, true);
      offset++;
    }
  }
}
void setAnimation_AppearThing4()
{
  ledManager->setSpeed(4);

  uint16_t offset = 0;

  for (uint8_t i = 0; i < PANELAMOUNT; i++)
  {
    panels[i]->setDataFx( EFFECT_STOCK_APPEAR, COLOUR_RED, 0, 1, true, true);
    for (uint8_t j = 0; j < panels[i]->getDiodeAmount(); j++)
    {
      panels[i]->setDiodeDataFx(j, 255, EFFECT_STOCK_PAUSEDFLASH, COLOUR_CYCLE, random(0,250), 1, true);
      offset++;
    }
  }
}
void setAnimation_ColourBlink()
{
  ledManager->setSpeed(4);

  uint16_t offset = 0;

  for (uint8_t i = 0; i < PANELAMOUNT; i++)
  {
    panels[i]->setDataFx( EFFECT_STOCK_APPEAR, COLOUR_RED, 0, 1, true, true);
    for (uint8_t j = 0; j < panels[i]->getDiodeAmount(); j++)
    {
      panels[i]->setDiodeDataFx(j, 255, EFFECT_STOCK_STATIC, COLOUR_CYCLE, i, 1, true);
      offset++;
    }
  }

  for (int i = 0; i < 64; i++)
  {
    ledManager->tick();
  }
}

void setupPanels()
{
  Serial.println(F("Allocatig..."));
  panels = (Panel**)malloc(sizeof(Panel*) * PANELAMOUNT);
  Serial.println(F("Array allocated..."));

  #ifdef PANELSETUP_ATOS
  panels[0] = new Panel(0, CLOCK_COUNTERWISE, COMPASS_WEST, LEDAMOUNT);
  #endif
  #ifdef PANELSETUP_EVA
  panels[0] = new Panel(0, CLOCK_COUNTERWISE, COMPASS_SOUTH_EAST, LEDSAMOUNT_TRIANGLE);
  panels[1] = new Panel(1, CLOCK_COUNTERWISE, COMPASS_SOUTH,      LEDSAMOUNT_TRIANGLE);
  panels[2] = new Panel(2, CLOCK_COUNTERWISE, COMPASS_SOUTH_WEST, LEDSAMOUNT_TRIANGLE);
  panels[3] = new Panel(3, CLOCK_CLOCKWISE,   COMPASS_NORTH_EAST, LEDSAMOUNT_TRIANGLE);
  #endif
  #ifdef PANELSETUP_LIAM
  panels[0] = new Panel(0, CLOCK_COUNTERWISE, COMPASS_SOUTH_EAST, LEDSAMOUNT_TRIANGLE);
  panels[1] = new Panel(1, CLOCK_COUNTERWISE, COMPASS_SOUTH,      LEDSAMOUNT_TRIANGLE);
  panels[2] = new Panel(2, CLOCK_COUNTERWISE, COMPASS_SOUTH_WEST, LEDSAMOUNT_TRIANGLE);
  panels[3] = new Panel(3, CLOCK_CLOCKWISE,   COMPASS_NORTH_EAST, LEDSAMOUNT_TRIANGLE);
  panels[4] = new Panel(4, CLOCK_CLOCKWISE,   COMPASS_NORTH,      LEDSAMOUNT_TRIANGLE);
  panels[5] = new Panel(5, CLOCK_CLOCKWISE,   COMPASS_NORTH_WEST, LEDSAMOUNT_TRIANGLE);
  panels[6] = new Panel(6, CLOCK_COUNTERWISE, COMPASS_SOUTH_WEST, LEDSAMOUNT_TRIANGLE);
  panels[7] = new Panel(7, CLOCK_CLOCKWISE,   COMPASS_NORTH_EAST, LEDSAMOUNT_TRIANGLE);
  panels[8] = new Panel(8, CLOCK_CLOCKWISE,   COMPASS_NORTH,      LEDSAMOUNT_TRIANGLE);
  panels[9] = new Panel(9, CLOCK_CLOCKWISE,   COMPASS_NORTH_WEST, LEDSAMOUNT_TRIANGLE);
  #endif
  #ifdef PANELSETUP_PRIME
  panels[ 0] = new Panel( 0, CLOCK_COUNTERWISE, COMPASS_SOUTH_EAST, LEDSAMOUNT_TRIANGLE);
  panels[ 1] = new Panel( 1, CLOCK_COUNTERWISE, COMPASS_SOUTH,      LEDSAMOUNT_TRIANGLE);
  panels[ 2] = new Panel( 2, CLOCK_COUNTERWISE, COMPASS_SOUTH_WEST, LEDSAMOUNT_TRIANGLE);
  panels[ 3] = new Panel( 3, CLOCK_CLOCKWISE,   COMPASS_NORTH_EAST, LEDSAMOUNT_TRIANGLE);
  panels[ 4] = new Panel( 4, CLOCK_CLOCKWISE,   COMPASS_NORTH,      LEDSAMOUNT_TRIANGLE);
  panels[ 5] = new Panel( 5, CLOCK_CLOCKWISE,   COMPASS_NORTH_WEST, LEDSAMOUNT_TRIANGLE);
  panels[ 6] = new Panel( 6, CLOCK_COUNTERWISE, COMPASS_SOUTH_WEST, LEDSAMOUNT_TRIANGLE);
  panels[ 7] = new Panel( 7, CLOCK_CLOCKWISE,   COMPASS_NORTH_EAST, LEDSAMOUNT_TRIANGLE);
  panels[ 8] = new Panel( 8, CLOCK_CLOCKWISE,   COMPASS_NORTH,      LEDSAMOUNT_TRIANGLE);
  panels[ 9] = new Panel( 9, CLOCK_CLOCKWISE,   COMPASS_NORTH_WEST, LEDSAMOUNT_TRIANGLE);
  panels[10] = new Panel(10, CLOCK_CLOCKWISE,   COMPASS_NORTH,      LEDSAMOUNT_TRIANGLE);
  panels[11] = new Panel(11, CLOCK_CLOCKWISE,   COMPASS_NORTH_WEST, LEDSAMOUNT_TRIANGLE);
  panels[12] = new Panel(12, CLOCK_COUNTERWISE, COMPASS_SOUTH_WEST, LEDSAMOUNT_TRIANGLE);
  panels[13] = new Panel(13, CLOCK_CLOCKWISE,   COMPASS_NORTH_EAST, LEDSAMOUNT_TRIANGLE);
  panels[14] = new Panel(14, CLOCK_CLOCKWISE,   COMPASS_NORTH,      LEDSAMOUNT_TRIANGLE);
  panels[15] = new Panel(15, CLOCK_CLOCKWISE,   COMPASS_NORTH_WEST, LEDSAMOUNT_TRIANGLE);
  #endif
  #ifdef PANELSETUP_DRONE
  panels[ 0] = new Panel( 0, CLOCK_CLOCKWISE,   COMPASS_NORTH,      10);
  panels[ 1] = new Panel( 1, CLOCK_CLOCKWISE,   COMPASS_NORTH,      11);

  panels[ 2] = new Panel( 2, CLOCK_CLOCKWISE,   COMPASS_NORTH,      10);
  panels[ 3] = new Panel( 3, CLOCK_CLOCKWISE,   COMPASS_NORTH,      11);
  
  panels[ 4] = new Panel( 4, CLOCK_CLOCKWISE,   COMPASS_NORTH,      10);
  panels[ 5] = new Panel( 5, CLOCK_CLOCKWISE,   COMPASS_NORTH,      10);

  panels[ 6] = new Panel( 6, CLOCK_CLOCKWISE,   COMPASS_NORTH,      11);
  panels[ 7] = new Panel( 7, CLOCK_CLOCKWISE,   COMPASS_NORTH,      10);

  panels[ 8] = new Panel( 8, CLOCK_CLOCKWISE,   COMPASS_NORTH,      10);
  panels[ 9] = new Panel( 9, CLOCK_CLOCKWISE,   COMPASS_NORTH,      10);

  panels[10] = new Panel(10, CLOCK_CLOCKWISE,   COMPASS_NORTH,      11);
  panels[11] = new Panel(11, CLOCK_CLOCKWISE,   COMPASS_NORTH,      10);

  panels[12] = new Panel(12, CLOCK_CLOCKWISE,   COMPASS_NORTH,      11);
  panels[13] = new Panel(13, CLOCK_CLOCKWISE,   COMPASS_NORTH,      10);


  panels[14] = new Panel(14, CLOCK_CLOCKWISE,   COMPASS_NORTH,      9);
  panels[15] = new Panel(15, CLOCK_CLOCKWISE,   COMPASS_NORTH,      10);


  panels[16] = new Panel(16, CLOCK_CLOCKWISE,   COMPASS_NORTH,      11);
  panels[17] = new Panel(17, CLOCK_CLOCKWISE,   COMPASS_NORTH,      10);

  panels[18] = new Panel(18, CLOCK_CLOCKWISE,   COMPASS_NORTH,      10);
  panels[19] = new Panel(19, CLOCK_CLOCKWISE,   COMPASS_NORTH,      10);

  panels[20] = new Panel(20, CLOCK_CLOCKWISE,   COMPASS_NORTH,      10);
  panels[21] = new Panel(21, CLOCK_CLOCKWISE,   COMPASS_NORTH,      11);

  panels[22] = new Panel(22, CLOCK_CLOCKWISE,   COMPASS_NORTH,      10);
  panels[23] = new Panel(23, CLOCK_CLOCKWISE,   COMPASS_NORTH,      10);

  panels[24] = new Panel(24, CLOCK_CLOCKWISE,   COMPASS_NORTH,      11);
  panels[25] = new Panel(25, CLOCK_CLOCKWISE,   COMPASS_NORTH,      10);

  panels[26] = new Panel(26, CLOCK_CLOCKWISE,   COMPASS_NORTH,      11);
  panels[27] = new Panel(27, CLOCK_CLOCKWISE,   COMPASS_NORTH,      10);

  panels[28] = new Panel(28, CLOCK_CLOCKWISE,   COMPASS_NORTH,      12);


  panels[29] = new Panel(29, CLOCK_CLOCKWISE,   COMPASS_NORTH,      38);
  panels[30] = new Panel(30, CLOCK_CLOCKWISE,   COMPASS_NORTH,      37);
  panels[31] = new Panel(31, CLOCK_CLOCKWISE,   COMPASS_NORTH,      38);
  panels[32] = new Panel(32, CLOCK_CLOCKWISE,   COMPASS_NORTH,      37);



  #endif
  #ifdef PANELSETUP_TEST
  panels[0] = new Panel(0, CLOCK_COUNTERWISE, COMPASS_SOUTH_EAST, 3);
  panels[1] = new Panel(1, CLOCK_COUNTERWISE, COMPASS_SOUTH,      3);
  panels[2] = new Panel(2, CLOCK_COUNTERWISE, COMPASS_SOUTH_WEST, 3);
  panels[3] = new Panel(3, CLOCK_CLOCKWISE,   COMPASS_NORTH_EAST, 3);
  panels[4] = new Panel(4, CLOCK_CLOCKWISE,   COMPASS_NORTH,      3);
  panels[5] = new Panel(5, CLOCK_CLOCKWISE,   COMPASS_NORTH_WEST, 3);
  #endif

  Serial.println(F("Allocating complete"));
  return;
}

void setup()
{
  Serial.begin(115200);
  Serial.println(F("Trinity MK3 - Ask Blommaert"));

  Wire.begin(ADDR_WESTPOINT);
  Wire.onReceive(receiveEvent);
  receivedCode = 0;
  responseCode = 0;
  newDataReceived = false;
  wrongDataReceived = false;
  currentShowingEffect = 0;
  celebrate = false;

  setupPanels();
  ledManager      = new LedManager(panels);
  button          = new AskButton(PIN_BUTTON, 250);
  lightSensor     = new LightSensor(PIN_LIGHTSENSOR);
  sleepTimer      = new SleepTimer();
  comms           = new Comms();

  pinMode(DRONESENSOR_A, INPUT);
  pinMode(DRONESENSOR_B, INPUT);
  pinMode(DRONESENSOR_C, INPUT);
  pinMode(DRONESENSOR_D, INPUT);

  enableNavLighting = false;

  Serial.println(F("...Trinity Initialised"));

  ledManager->setBrightness(255);

  Serial.println(F("...Trinity Started"));


  playResetAnimation();

  enableCycleDemoMode = STARTCYCLING;
  if (STARTCYCLING) setAnimation_AppearThing4();
  else setAnimation_Default();
  
  
    

  

  Serial.println(F("---===SETUP COMPLETED===---"));
}

void loop()
{
  uint64_t currentMillis = millis();

    Serial.print(".");

    if (celebrate)
    {
      if(currentMillis >= (prevCelebrateTime+CELEBRATETIME))
      {
        prevCelebrateTime = currentMillis;
        celebrate = false;

        newDataReceived = true;
        receivedCode = CODE_WESTPOINT_DEFAULT;
      }
    }

    if(!enableCycleDemoMode)
    {
      if(currentMillis >= (prevAntiScreensaverTime+SCREENSAVERTIME))
      {
        prevAntiScreensaverTime = currentMillis;
        enableCycleDemoMode = true;
        setDronePercentage(0);
      }
    }
    

    
    if (digitalRead(DRONESENSOR_A))sensorAHits++;
    if (digitalRead(DRONESENSOR_B))sensorBHits++;
    if (digitalRead(DRONESENSOR_C))sensorCHits++;
    if (digitalRead(DRONESENSOR_D))sensorDHits++;
    sensorPolls++;

    //Serial.print(F("Sensors: "));
    //Serial.print(digitalRead(DRONESENSOR_A));
    //Serial.print(digitalRead(DRONESENSOR_B));
    //Serial.print(digitalRead(DRONESENSOR_C));
    //Serial.println(digitalRead(DRONESENSOR_D));

    if(currentMillis >= (prevSensorMillis+SENSORPOLLTIME))
    {
      prevSensorMillis = currentMillis;
      uint16_t requiredSensorHits = sensorPolls * SENSORTRIGGERPERCENTAGE;


      //Serial.println(requiredSensorHits);
      //Serial.println(sensorAHits * 100);
      
      if((sensorAHits*100) > requiredSensorHits)
      {
        Serial.println(F("Sensor A hit"));
        newDataReceived = true;
        receivedCode = CODE_WESTPOINT_PERCENTAGE25;
      }
      if((sensorBHits*100) > requiredSensorHits)
      {
        Serial.println(F("Sensor B hit"));
        newDataReceived = true;
        receivedCode = CODE_WESTPOINT_PERCENTAGE50;
      }
      if((sensorCHits*100) > requiredSensorHits)
      {
        Serial.println(F("Sensor C hit"));
        newDataReceived = true;
        receivedCode = CODE_WESTPOINT_PERCENTAGE75;
      }
      if((sensorDHits*100) > requiredSensorHits)
      {
        Serial.println(F("Sensor D hit"));
        newDataReceived = true;
        receivedCode = CODE_WESTPOINT_FINISH;
      }



      sensorAHits = 0;
      sensorBHits = 0;
      sensorCHits = 0;
      sensorDHits = 0;
      sensorPolls = 0;
    }


   delay(10);
    //Button press handling
    switch(button->getCommand())
    {
      case BUTTON_TAPPED: //Brightness cycle
      {
        if (enableNavLighting)
        {
          enableNavLighting = false;
          for (uint8_t j = 0; j < panels[4]->getDiodeAmount(); j++)
          {
            panels[4]->setDiodeDataFx(j, BRIGHTNESS_2_NOR, EFFECT_SPECIAL_RAINBOW, COLOUR_RED, 0, 5, true);
          }
        }
        else
        {
          enableNavLighting = true;
          for (uint8_t j = 0; j < panels[4]->getDiodeAmount(); j++)
          {
            panels[4]->setDiodeDataFx(j, BRIGHTNESS_3_MAX, EFFECT_STOCK_PLANE, COLOUR_WHITE, j*1, 5, true);
          }
        }
      }
      break;
      case BUTTON_HELD: //Preset cycle
      {
    
        uint8_t goalPanelNumber = random(0, PANELAMOUNT);
        uint8_t goalEffectNumber = random(0, AMOUNTOFEFFECTS);
        uint8_t goalColourNumber = random(0, AMOUNTOFCOLOURS);
        for (uint8_t j = 0; j < panels[goalPanelNumber]->getDiodeAmount(); j++)
        {
          panels[goalPanelNumber]->setDiodeDataFx(j, BRIGHTNESS_2_NOR, goalEffectNumber, goalColourNumber, 0, 5, true);
        }
    
      /*
        for (uint8_t i = 0; i < PANELAMOUNT; i++)
        {
          uint8_t goalEffectNumber = random(0, AMOUNTOFEFFECTS);
          uint8_t goalColourNumber = random(0, AMOUNTOFCOLOURS);

          panels[i]->setDataFx(BRIGHTNESS_2_NOR, EFFECT_STOCK_APPEAR, COLOUR_RED, random(0, 10)*15, 1, true, true);
          for (uint8_t j = 0; j < panels[i]->getDiodeAmount(); j++)
          {
            panels[i]->setDiodeDataFx(j, BRIGHTNESS_2_NOR, goalEffectNumber, goalColourNumber, 0, 5, true);
          }
        }
        */
      }
    }
    
    //Auto brightness handling
    if (lightSensor->getEnabled())
    {
      lightSensor->tick();
      if(ledManager->getBrightness() != lightSensor->getRecommendedBrightness())
      ledManager->setBrightness(lightSensor->getRecommendedBrightness());
    }

    //Waking up / Shutting down system from sleep timer
    sleepTimer->tick();
    switch (sleepTimer->getTurn())
    {
      case TURN_OFF:
      {
        Serial.println(F("SleepTimer Turning system off"));
        ledManager->setBrightness(BRIGHTNESS_0_OFF);
      }
      break;

      case TURN_ON:
      {
        Serial.println(F("SleepTimer Turning system on"));
        if(ledManager->getBrightness() == BRIGHTNESS_0_OFF)ledManager->setBrightness(BRIGHTNESS_2_NOR);
      }
      break;
    }

    //Communications handling
    comms->tick();
    switch (comms->getReadyTransmissionType())
    {
      case TRANSMISSION_IN_PANELFX:
      {
        //Serial.println("Panel transmission retrieved from comms");
        Transmission_PanelFX data = comms->getTransmission_PanelFX();
        //Serial.println("Yom");
        ledManager->setPanelData(data.panelNumber, data.effect, data.colour, data.offset, data.speed, data.repeat, data.detailed);
        //Serial.println("Done");
      }
      break;
      case TRANSMISSION_IN_PANELCUSTOM:
      {

      }
      break;
      case TRANSMISSION_IN_DIODEFX:
      {
        //Serial.println("Panel transmission retrieved from comms");
        Transmission_DiodeFX data = comms->getTransmission_DiodeFX();
        //Serial.println("Yom");
        ledManager->setPanelDiodeData(data.panelNumber, data.diodeNumber, data.brightness, data.effect, data.colour, data.offset, data.speed, data.repeat);
        //Serial.println("Done");
      }
      break;
      case TRANSMISSION_IN_DIODECUSTOM:
      {

      }
      break;
      case TRANSMISSION_IN_BRIGHTNESS:
      {
        ledManager->setBrightness(comms->getTransmission_Brightness());
      }
      break;
      case TRANSMISSION_IN_SLEEPTIMER:
      {
        Transmission_SleepTimerData data = comms->getTransmission_SleepTimerData();
        switch (data.timerID)
        {
          case TIMERID_OFFTIMER:
          {
            sleepTimer->setTurnOffTime(data.hour, data.minute);
            sleepTimer->setTurnOffEnabled(data.enabled);
          }
          break;
          case TIMERID_ONTIMER:
          {
            sleepTimer->setTurnOnTime(data.hour, data.minute);
            sleepTimer->setTurnOnEnabled(data.enabled);
          }
          break;
        }
      }
      break;
      case TRANSMISSION_IN_LIGHTSENSOR:
      {
        Transmission_LightSensorData data = comms->getTransmission_LightSensorData();
        lightSensor->setBrightnessOffset(data.offset);
        lightSensor->setEnabled(data.enabled);
      }
      break;
      case TRANSMISSION_IN_REQUEST:
      {
        comms->transmit(TRANSMISSION_OUT_LEDMANAGER, ledManager->convertToTansmission());

        for (uint8_t i = 0; i < ledManager->getPanelAmount(); i++)
        {
          
          comms->transmit(TRANSMISSION_OUT_PANEL, ledManager->convertPanelToTransmission(i));
          
          for (uint8_t j = 0; j < ledManager->getPanelDiodeAmount(i); j++)
          {
            comms->transmit(TRANSMISSION_OUT_DIODE, ledManager->convertPanelDiodeToTransmission(i,j));
          }
        }
      }
      break;
      case TRANSMISSION_IN_IDENT:
      {
        comms->transmit(TRANSMISSION_OUT_IDENT, "");
      }
      break;
    }


    Serial.print("p");
    ledManager->tick();
    ledManager->print();
//Cycle code?
  if(enableCycleDemoMode)
  {
    
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
  }
//End cycle code?

  if (!newDataReceived) return;

  prevAntiScreensaverTime = currentMillis;
  enableCycleDemoMode = false;
  
  switch (receivedCode)
  {
    case CODE_DEBUG_ACKREQUEST:
    Wire.write(responseCode);
    break;
    
    case CODE_WESTPOINT_TURNOFF:
    Serial.println("Action: Turning westpoint off");
    ledManager->setBrightness(0);
    setDronePercentage(100);
    break;

    case CODE_WESTPOINT_DEFAULT:
    Serial.println("Action: Showing default animation");
    ledManager->setBrightness(255);
    ledManager->setSpeed(1);
    for (uint16_t i = 0; i < PANELAMOUNT; i++)
    {
      panels[i]->setDataFx(EFFECT_STOCK_APPEAR, COLOUR_RED, random(0, 10)*15, 1, true, true);
      for (uint16_t j = 0; j < panels[i]->getDiodeAmount(); j++)
      {
        panels[i]->setDiodeDataFx(j, BRIGHTNESS_3_MAX, EFFECT_SPECIAL_SYNTHBOW, COLOUR_RED, 0, 5, true);
      }

      Serial.print("Editing panel ");
      Serial.println(i);
    }
    setDronePercentage(0);
    setRingAnimations(1);
    break;

    case CODE_WESTPOINT_PERCENTAGE25:
    Serial.println("Action: Showing 25/ animation");
    ledManager->setBrightness(255);
    setDronePercentage(1);
    playDroneResetAnimation(1);
    setAnimation_ColourBlink();
    setRingAnimations(2);
    break;

    case CODE_WESTPOINT_PERCENTAGE50:
    Serial.println("Action: Showing 50/ animation");
    ledManager->setBrightness(255);
    setDronePercentage(2);
    playDroneResetAnimation(2);
    setAnimation_Stoplight();
    setRingAnimations(3);
    break;
    

    case CODE_WESTPOINT_PERCENTAGE75:
    Serial.println("Action: Showing 75/ animation");
    ledManager->setBrightness(255);
    setDronePercentage(3);
    playDroneResetAnimation(3);
    setAnimation_HeartbeatTower();
    setRingAnimations(4);
    
    break;


    
    case CODE_WESTPOINT_FINISH:
    Serial.println("Action: Showing race finished animation");
    //ledManager->setBrightness(100);
    setDronePercentage(4);
    playDroneResetAnimation(4);
    ledManager->setBrightness(255);
    setAnimation_BurningRainbow();
    celebrate = true;
    prevCelebrateTime = currentMillis;
    break;

    case CODE_WESTPOINT_RANDOM:
    Serial.println("Action: Showing random animation");
    ledManager->setBrightness(255);
    setDronePercentage(100);
    break;




    case CODE_WESTPOINT_EFFECT_EYE:
    Serial.println("Action: Showing Eye animation");
    ledManager->setBrightness(255);
    setDronePercentage(100);
    playResetAnimation();
    setAnimation_AppearThing2();
    break;
    case CODE_WESTPOINT_EFFECT_ZAP:
    Serial.println("Action: Showing Zap animation");
    ledManager->setBrightness(255);
    setDronePercentage(100);
    playResetAnimation();
    setAnimation_PowerRise();
    break;
    case CODE_WESTPOINT_EFFECT_HEART:
    Serial.println("Action: Showing Heart animation");
    ledManager->setBrightness(255);
    setDronePercentage(100);
    playResetAnimation();
    setAnimation_HeartbeatTower();
    break;
    case CODE_WESTPOINT_EFFECT_GAY:
    Serial.println("Action: Showing Gay animation");
    ledManager->setBrightness(255);
    setDronePercentage(100);
    playResetAnimation();
    setAnimation_ADHDRainbow();
    break;
    case CODE_WESTPOINT_EFFECT_SOUND:
    Serial.println("Action: Showing Sound animation");
    ledManager->setBrightness(255);
    setDronePercentage(100);
    playResetAnimation();
    setAnimation_Fishbowl();
    break;
    case CODE_WESTPOINT_EFFECT_WIND:
    Serial.println("Action: Showing Wind animation");
    ledManager->setBrightness(255);
    setDronePercentage(100);
    playResetAnimation();
    setAnimation_Rain();
    break;




    default:
    wrongDataReceived = true;
    Serial.print("Warning: Received incorrect transmission. Received:");
    Serial.println(receivedCode);
    break;
  }

  if(wrongDataReceived)
  {
    responseCode = CODE_DEBUG_RECEIVEDWRONGCODE;
  }
  else
  {
    responseCode = receivedCode;
  }

  newDataReceived = false;
}


