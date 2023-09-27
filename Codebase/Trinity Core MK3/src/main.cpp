#include "main.h"

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
  panels[ 0] = new Panel( 0, 0, 3, CLOCK_COUNTERWISE, COMPASS_SOUTH_EAST, LEDSAMOUNT_TRIANGLE);
  panels[ 1] = new Panel( 1, 1, 3, CLOCK_COUNTERWISE, COMPASS_SOUTH,      LEDSAMOUNT_TRIANGLE);
  panels[ 2] = new Panel( 2, 2, 3, CLOCK_COUNTERWISE, COMPASS_SOUTH_WEST, LEDSAMOUNT_TRIANGLE);
  panels[ 3] = new Panel( 3, 3, 3, CLOCK_CLOCKWISE,   COMPASS_NORTH_EAST, LEDSAMOUNT_TRIANGLE);
  panels[ 4] = new Panel( 4, 4, 3, CLOCK_CLOCKWISE,   COMPASS_NORTH,      LEDSAMOUNT_TRIANGLE);
  panels[ 5] = new Panel( 5, 5, 3, CLOCK_CLOCKWISE,   COMPASS_NORTH_WEST, LEDSAMOUNT_TRIANGLE);
  panels[ 6] = new Panel( 6, 6, 3, CLOCK_COUNTERWISE, COMPASS_SOUTH_WEST, LEDSAMOUNT_TRIANGLE);
  panels[ 7] = new Panel( 7, 5, 2, CLOCK_CLOCKWISE,   COMPASS_NORTH_EAST, LEDSAMOUNT_TRIANGLE);
  panels[ 8] = new Panel( 8, 5, 2, CLOCK_CLOCKWISE,   COMPASS_NORTH,      LEDSAMOUNT_TRIANGLE);
  panels[ 9] = new Panel( 9, 0, 1, CLOCK_CLOCKWISE,   COMPASS_NORTH_WEST, LEDSAMOUNT_TRIANGLE);
  panels[10] = new Panel(10, 0, 1, CLOCK_CLOCKWISE,   COMPASS_NORTH,      LEDSAMOUNT_TRIANGLE);
  panels[11] = new Panel(11, 0, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH_WEST, LEDSAMOUNT_TRIANGLE);
  panels[12] = new Panel(12, 0, 1, CLOCK_COUNTERWISE, COMPASS_SOUTH_WEST, LEDSAMOUNT_TRIANGLE);
  panels[13] = new Panel(13, 0, 2, CLOCK_CLOCKWISE,   COMPASS_NORTH_EAST, LEDSAMOUNT_TRIANGLE);
  panels[14] = new Panel(14, 0, 2, CLOCK_CLOCKWISE,   COMPASS_NORTH,      LEDSAMOUNT_TRIANGLE);
  panels[15] = new Panel(15, 0, 2, CLOCK_CLOCKWISE,   COMPASS_NORTH_WEST, LEDSAMOUNT_TRIANGLE);
  #endif
  #ifdef PANELSETUP_TEST
  panels[0] = new Panel(0, CLOCK_COUNTERWISE, COMPASS_SOUTH_EAST, 3);
  panels[1] = new Panel(1, CLOCK_COUNTERWISE, COMPASS_SOUTH,      3);
  panels[2] = new Panel(2, CLOCK_COUNTERWISE, COMPASS_SOUTH_WEST, 3);
  panels[3] = new Panel(3, CLOCK_CLOCKWISE,   COMPASS_NORTH_EAST, 3);
  panels[4] = new Panel(4, CLOCK_CLOCKWISE,   COMPASS_NORTH,      3);
  panels[5] = new Panel(5, CLOCK_CLOCKWISE,   COMPASS_NORTH_WEST, 3);
  #endif
  #ifdef PANELSETUP_CHRISTMAS
  panels[0] = new Panel(0, 0, 0, CLOCK_CLOCKWISE,   COMPASS_SOUTH_EAST, 10);
  panels[1] = new Panel(1, 0, 0, CLOCK_CLOCKWISE,   COMPASS_SOUTH,      10);
  panels[2] = new Panel(2, 0, 0, CLOCK_CLOCKWISE,   COMPASS_SOUTH_WEST, 10);
  panels[3] = new Panel(3, 0, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH_EAST, 10);
  panels[4] = new Panel(4, 0, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH,      10);
  panels[5] = new Panel(5, 0, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH_WEST, 10);
  panels[6] = new Panel(6, 0, 0, CLOCK_CLOCKWISE,   COMPASS_SOUTH_EAST, 10);
  panels[7] = new Panel(7, 0, 0, CLOCK_CLOCKWISE,   COMPASS_SOUTH,      10);
  panels[8] = new Panel(8, 0, 0, CLOCK_CLOCKWISE,   COMPASS_SOUTH_WEST, 10);
  panels[9] = new Panel(9, 0, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH_EAST, 10);

  #endif

  Serial.println(F("Allocating complete"));
  return;
}

void playResetAnimation()
{
  int panelMultiplier = 2;

  ledManager->setBrightness(255);
  ledManager->setSpeed(1);

  for (uint16_t i = 0; i < PANELAMOUNT; i++)
  {
    VFXData vfxData;
    vfxData.effect = EFFECT_STOCK_APPEAR;
    vfxData.colour = COLOUR_RED;
    vfxData.offset = (i*panelMultiplier);
    vfxData.speed = 1;
    vfxData.repeat = 1;
    panels[i]->setVfx(vfxData);
    for (uint16_t j = 0; j < panels[i]->getDiodeAmount(); j++)
    {
      panels[i]->setDiodeVfx(j, (VFXData){EFFECT_STOCK_FLASH, COLOUR_VIOLET, j, 1, false});
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
void playDroneResetAnimation()
{
  ledManager->setBrightness(255);
  ledManager->setSpeed(5);

  for (uint16_t i = 0; i < PANELAMOUNT; i++)
  {
    panels[i]->setVfx((VFXData){EFFECT_STOCK_APPEAR, COLOUR_RED, i, 1, true});
    for (uint16_t j = 0; j < panels[i]->getDiodeAmount(); j++)
    {
      panels[i]->setDiodeVfx(j, (VFXData){EFFECT_STOCK_PLANE, COLOUR_WHITE, 0, 1, false});
    }

  Serial.print("Editing panel ");
  Serial.println(i);
  }


  for (int i = 0; i < 20; i++)
  {
    ledManager->tick();
    ledManager->print();
  }
  
}

void setAnimation_FullWhite()
{
  


    uint16_t offset = 0;
    for (uint16_t i = 0; i < PANELAMOUNT; i++)
    {
    panels[i]->setVfx((VFXData){EFFECT_STOCK_STATIC, COLOUR_WHITE, (uint8_t)random(0, 10)*15, 1, true});
    for (uint16_t j = 0; j < panels[i]->getDiodeAmount(); j++)
    {
      panels[i]->setDiodeVfx(j, (VFXData){EFFECT_STOCK_STATIC, COLOUR_WHITE, 0, 5, true});
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
    panels[i]->setVfx((VFXData){EFFECT_STOCK_APPEAR, COLOUR_RED, (uint8_t)random(0, 10)*15, 1, true});
    for (uint16_t j = 0; j < panels[i]->getDiodeAmount(); j++)
    {
      panels[i]->setDiodeVfx(j, (VFXData){EFFECT_SPECIAL_RAINBOW, COLOUR_RED, 0, 5, true});
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
      panels[i]->setVfx((VFXData){EFFECT_STOCK_APPEAR, COLOUR_RED, (uint8_t)random(0, 10)*15, 1, true});
      for (uint16_t j = 0; j < panels[i]->getDiodeAmount(); j++)
      {
        panels[i]->setDiodeVfx(j, (VFXData){EFFECT_STOCK_PAUSEDBREATHING, COLOUR_CYCLE, j, 20, true});
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
      panels[i]->setVfx((VFXData){EFFECT_STOCK_APPEAR, COLOUR_RED, (uint8_t)random(0, 10)*15, 1, true});
      for (uint16_t j = 0; j < panels[i]->getDiodeAmount(); j++)
      {
        panels[i]->setDiodeVfx(j, (VFXData){EFFECT_STOCK_PAUSEDFLASH, COLOUR_WHITE, j, 10, true});
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
      panels[i]->setVfx((VFXData){EFFECT_STOCK_APPEAR, COLOUR_RED, (uint8_t)random(0, 10)*15, 1, true});
      for (uint16_t j = 0; j < panels[i]->getDiodeAmount(); j++)
      {
        panels[i]->setDiodeVfx(j, (VFXData){EFFECT_STOCK_PAUSEDFLASH, COLOUR_BLUE, j, (uint8_t)random(0, 10), true});
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
      panels[i]->setVfx((VFXData){EFFECT_STOCK_APPEAR, COLOUR_RED, (uint8_t)random(0, 10)*15, 1, true});
      for (uint16_t j = 0; j < panels[i]->getDiodeAmount(); j++)
      {
        panels[i]->setDiodeVfx(j, (VFXData){EFFECT_STOCK_APPEAR, COLOUR_GREEN, j, 10, true});
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
      panels[i]->setVfx((VFXData){EFFECT_STOCK_APPEAR, COLOUR_RED, 0, 1, true});
      for (uint16_t j = 0; j < panels[i]->getDiodeAmount(); j++)
      {
        panels[i]->setDiodeVfx(j, (VFXData){EFFECT_SPECIAL_RAINBOW, COLOUR_RED, offset, 10, true});
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
      panels[i]->setVfx((VFXData){EFFECT_STOCK_APPEAR, COLOUR_RED, 0, 1, true});
      for (uint16_t j = 0; j < panels[i]->getDiodeAmount(); j++)
      {
        panels[i]->setDiodeVfx(j, (VFXData){EFFECT_SPECIAL_RAINBOW, COLOUR_RED, offset, 100, true});
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
      panels[i]->setVfx((VFXData){EFFECT_STOCK_APPEAR, COLOUR_RED, i*5, 10, true});
      for (uint16_t j = 0; j < panels[i]->getDiodeAmount(); j++)
      {
        panels[i]->setDiodeVfx(j, (VFXData){EFFECT_SPECIAL_RAINBOW, COLOUR_RED, j*5, 10, true});
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
      panels[i]->setVfx((VFXData){EFFECT_STOCK_APPEAR, COLOUR_RED, i*5, 10, true});
      for (uint16_t j = 0; j < panels[i]->getDiodeAmount(); j++)
      {
        panels[i]->setDiodeVfx(j, (VFXData){EFFECT_SPECIAL_RAINBOW, COLOUR_RED, j*5, 10, true});
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
      panels[i]->setVfx((VFXData){EFFECT_STOCK_APPEAR, COLOUR_RED, i*4, 1, true});
      for (uint16_t j = 0; j < panels[i]->getDiodeAmount(); j++)
      {
        panels[i]->setDiodeVfx(j, (VFXData){EFFECT_STOCK_HEARTBEAT, COLOUR_RED, 0, 1, true});
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
      panels[i]->setVfx((VFXData){EFFECT_STOCK_APPEAR, COLOUR_RED, offset, 1, true});
      for (uint16_t j = 0; j < panels[i]->getDiodeAmount(); j++)
      {
        panels[i]->setDiodeVfx(j, (VFXData){EFFECT_STOCK_PAUSEDFLASH, COLOUR_CYCLE, offset, 1, true});
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
      panels[i]->setVfx((VFXData){EFFECT_STOCK_APPEAR, COLOUR_RED, offset, 1, true});
      for (uint16_t j = 0; j < panels[i]->getDiodeAmount(); j++)
      {
        panels[i]->setDiodeVfx(j, (VFXData){EFFECT_STOCK_PAUSEDFLASH, COLOUR_CYAN, offset, 1, true});
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
      panels[i]->setVfx((VFXData){EFFECT_STOCK_APPEAR, COLOUR_RED, offset, 1, true});
      for (uint16_t j = 0; j < panels[i]->getDiodeAmount(); j++)
      {
        panels[i]->setDiodeVfx(j, (VFXData){EFFECT_STOCK_PAUSEDFLASH, COLOUR_CYCLE, offset, 1, true});
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
    panels[i]->setVfx((VFXData){EFFECT_STOCK_APPEAR, COLOUR_RED, 0, 1, true});
    for (uint8_t j = 0; j < panels[i]->getDiodeAmount(); j++)
    {
      panels[i]->setDiodeVfx(i, VFXData{ EFFECT_STOCK_APPEAR, COLOUR_CYCLE, offset, 1, true});
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
    panels[i]->setVfx((VFXData){EFFECT_STOCK_APPEAR, COLOUR_RED, (uint8_t)random(0, 100), 1, true});
    for (uint8_t j = 0; j < panels[i]->getDiodeAmount(); j++)
    {
      panels[i]->setDiodeVfx(i, VFXData{ EFFECT_STOCK_APPEAR, COLOUR_CYCLE, (uint8_t)random(0, 100), 1, true});
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
    panels[i]->setVfx((VFXData){EFFECT_STOCK_APPEAR, COLOUR_RED, (uint8_t)random(0, 100), 1, true});
    for (uint8_t j = 0; j < panels[i]->getDiodeAmount(); j++)
    {
      panels[i]->setDiodeVfx(i, VFXData{ EFFECT_STOCK_STATIC, COLOUR_CYCLE, (uint8_t)random(0, 100), 1, true});
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
    panels[i]->setVfx((VFXData){EFFECT_STOCK_APPEAR, COLOUR_RED, 0, 1, true});
    for (uint8_t j = 0; j < panels[i]->getDiodeAmount(); j++)
    {
      panels[i]->setDiodeVfx(i, VFXData{ EFFECT_STOCK_STATIC, COLOUR_CYCLE, (uint16_t)random(0, 1000), 1, true});
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
    panels[i]->setVfx((VFXData){EFFECT_STOCK_APPEAR, COLOUR_RED, 0, 1, true});
    for (uint8_t j = 0; j < panels[i]->getDiodeAmount(); j++)
    {
      panels[i]->setDiodeVfx(i, VFXData{ EFFECT_STOCK_PAUSEDFLASH, COLOUR_CYCLE, (uint8_t)random(0, 250), 1, true});
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
    panels[i]->setVfx((VFXData){EFFECT_STOCK_APPEAR, COLOUR_RED, 0, 1, true});
    for (uint8_t j = 0; j < panels[i]->getDiodeAmount(); j++)
    {
      panels[i]->setDiodeVfx(i, VFXData{ EFFECT_STOCK_STATIC, COLOUR_CYCLE, i, 1, true});
      offset++;
    }
  }

  for (int i = 0; i < 64; i++)
  {
    ledManager->tick();
  }
}


void setup()
{
  Serial.begin(115200);
  Serial.println(F("Trinity MK3 - Ask Blommaert"));

  setupPanels();
  ledManager      = new LedManager(panels);
  button          = new AskButton(PIN_BUTTON, 1000);
  lightSensor     = new LightSensor(PIN_LIGHTSENSOR);
  sleepTimer      = new SleepTimer();
  comms           = new Comms();

  Serial.println(F("...Trinity Initialised"));

  /*
  ledManager->setBrightness(255);

  sleepTimer->setTurnOnEnabled(true);
  sleepTimer->setTurnOnTime(10,0);
  sleepTimer->setTurnOffEnabled(true);
  sleepTimer->setTurnOffTime(9,59);
  */

  Serial.println(F("...Trinity Started"));


  /*
  //TEMP: Do some editing of the panel data 
  for (uint8_t i = 0; i < PANELAMOUNT; i++)
  {
    ledManager->setPanelData(i, DIR_STRIP, 255, EFFECT_RAINBOW, COLOUR_BLACK, i*5, 3, true);
  }
  */
  

  //Temp
  uint16_t offset = 0;

  for (uint8_t i = 0; i < PANELAMOUNT; i++)
  {
    //panels[i]->setVfx((VFXData){EFFECT_STOCK_APPEAR, COLOUR_RED, 0, 1, true});
    for (uint8_t j = 0; j < panels[i]->getDiodeAmount(); j++)
    {
      /*
      VFXData vfxData = {EFFECT_SPECIAL_RAINBOW, COLOUR_RED, offset, 1, true};
      panels[i]->setDiodeVfx(j, vfxData);
      */

      panels[i]->setDiodeVfx(j, VFXData{EFFECT_SPECIAL_RAINBOW, COLOUR_RED, offset, 1, true});



      offset++;
    }
  }

  Serial.println(F("---===SETUP COMPLETED===---"));
}

void loop()
{
  delay(10);
  
  //Button press handling
  switch(button->getCommand())
  {
    case BUTTON_TAPPED: //Brightness cycle
    {
      switch (ledManager->getBrightness())
      {
        case BRIGHTNESS_0_OFF:
        {
          ledManager->setEnabled(true);
          ledManager->setBrightness(BRIGHTNESS_1_DIM);
          lightSensor->setEnabled(false);
          Serial.println(F("Changing sys brightness to DIM"));
        }
        break;
        case BRIGHTNESS_1_DIM:
        {
          ledManager->setEnabled(true);
          ledManager->setBrightness(BRIGHTNESS_2_NOR);
          lightSensor->setEnabled(false);
          Serial.println(F("Changing sys brightness to NORMAL"));
        }
        break;
        case BRIGHTNESS_2_NOR:
        {
          ledManager->setEnabled(true);
          ledManager->setBrightness(BRIGHTNESS_3_MAX);
          lightSensor->setEnabled(false);
          Serial.println(F("Changing sys brightness to MAX"));

        }
        break;
        case BRIGHTNESS_3_MAX:
        {
          ledManager->setEnabled(true);
          ledManager->setBrightness(BRIGHTNESS_4_AUT);
          lightSensor->setEnabled(true);
          Serial.println(F("Changing sys brightness to Automatic"));
        }
        break;
        default:
        {
          ledManager->setEnabled(true);
          ledManager->setBrightness(BRIGHTNESS_0_OFF);
          lightSensor->setEnabled(false);
          Serial.println(F("Changing sys brightness to OFF"));
        }
        break;
      }
    }
    break;
    case BUTTON_HELD: //Preset cycle
    {
      Serial.println(F("Preset loading not implemented"));
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
      ledManager->setPanelVfx(data.panelNumber, data.vfxData);
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
      ledManager->setPanelDiodeVfx(data.panelNumber, data.diodeNumber, data.vfxData);
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

  ledManager->tick();
  ledManager->print();
}


