#include "AskButton/AskButton.h"
#include "LightSensor/LightSensor.h"
#include "Comms/Comms.h"

Trinity     *trinity;
AskButton   *button;
LightSensor *lightSensor;
Comms       *comms;

void handleComms()
{
  comms->tick();
  switch (comms->getReadyTransmissionType())
  {
    case TRANSMISSION_IN_LEDMANAGER:
    {
      Transmission_LedManager data = comms->getTransmission_LedManager();
      trinity->setBrightness(data.brightness); 
      trinity->setSpeed(data.speed); 
    }
    break;
    case TRANSMISSION_IN_PANEL:
    {
      Transmission_Panel data = comms->getTransmission_Panel();
      trinity->setPanelVfx(data.panelNumber, data.vfxData);
    }
    break;
    case TRANSMISSION_IN_DIODE:
    {
      Transmission_Diode data = comms->getTransmission_Diode();
      trinity->setPanelDiodeVfx(data.panelNumber, data.diodeNumber, data.vfxData);
    }
    break;
    case TRANSMISSION_IN_CUSTOMPALETTES:
    {
      Transmission_CustomPalette data = comms->getTransmission_CustomPalette();
      for (uint8_t i = 0; i < AMOUNTOFCOLOURS; i++)
      {
        trinity->setCustomPaletteColours(data.slot, i, *data.customRGB[i]);
      }
    }
    break;
    
    case TRANSMISSION_IN_SLEEPTIMER:
    {
      Transmission_SleepTimer data = comms->getTransmission_SleepTimer();
      switch (data.timerID)
      {
        case TIMERID_OFFTIMER:
        {
          trinity->setTurnOffTime(data.hour, data.minute);
          trinity->setTurnOffEnabled(data.enabled);
        }
        break;
        case TIMERID_ONTIMER:
        {
          trinity->setTurnOnTime(data.hour, data.minute);
          trinity->setTurnOnEnabled(data.enabled);
        }
        break;
      }
    }
    break;
    case TRANSMISSION_IN_LIGHTSENSOR:
    {
      lightSensor->setBrightnessOffset(comms->getTransmission_LightSensorOffset());
    }
    break;
    case TRANSMISSION_IN_REQUEST:
    {
      comms->transmit(TRANSMISSION_OUT_LEDMANAGER, trinity->convertToTansmission());

      for (uint8_t i = 0; i < trinity->getPanelAmount(); i++)
      {
        
        comms->transmit(TRANSMISSION_OUT_PANEL, trinity->convertPanelToTransmission(i));

        #if ENABLE_DIODECONTROL
        for (uint8_t j = 0; j < trinity->getPanelDiodeAmount(i); j++)
        {
          comms->transmit(TRANSMISSION_OUT_DIODE, trinity->convertPanelDiodeToTransmission(i,j));
        }
        #endif
      }
    }
    break;
    case TRANSMISSION_IN_IDENT:
    {
      comms->transmit(TRANSMISSION_OUT_IDENT, "");
    }
    break;
  }

}
void handleLDR()
{
  if (lightSensor->getEnabled())
  {
    lightSensor->tick();
    if(trinity->getBrightness() != lightSensor->getRecommendedBrightness())
    trinity->setBrightness(lightSensor->getRecommendedBrightness());
  }
}
void handleButton()
{
  switch(button->getCommand())
  {
    case BUTTON_TAPPED: //Brightness cycle
    {
      switch (trinity->getBrightness())
      {
        case BRIGHTNESS_0_OFF:
        {
          trinity->setBrightness(BRIGHTNESS_1_DIM);
          lightSensor->setEnabled(false);
          Serial.println(F("Changing sys brightness to DIM"));
        }
        break;
        case BRIGHTNESS_1_DIM:
        {
          trinity->setBrightness(BRIGHTNESS_2_NOR);
          lightSensor->setEnabled(false);
          Serial.println(F("Changing sys brightness to NORMAL"));
        }
        break;
        case BRIGHTNESS_2_NOR:
        {
          trinity->setBrightness(BRIGHTNESS_3_MAX);
          lightSensor->setEnabled(false);
          Serial.println(F("Changing sys brightness to MAX"));

        }
        break;
        case BRIGHTNESS_3_MAX:
        {
          trinity->setBrightness(BRIGHTNESS_4_AUT);
          lightSensor->setEnabled(true);
          Serial.println(F("Changing sys brightness to Automatic"));
        }
        break;
        default:
        {
          trinity->setBrightness(BRIGHTNESS_0_OFF);
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
}

void setup()
{
  Serial.begin(BAUDRATE);

  button          = new AskButton   (PIN_BUTTON, 100);
  lightSensor     = new LightSensor (PIN_LIGHTSENSOR);
  comms           = new Comms       ();
  trinity         = new Trinity     (PIN_LEDS, 60);

  
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
  #ifdef PANELSETUP_EYEOFTHESTORM
  for (uint8_t i = 0; i < 54; i++) trinity->addPanel(new Panel(i, i, 0, CLOCK_CLOCKWISE, COMPASS_NORTH, 5));
  #endif

  trinity->begin();
  Serial.println(F("---===SETUP COMPLETED===---"));

  trinity->playPresetAnimation(9);
  trinity->setAnimationCyclingDuration(10000);
}

void loop()
{
  trinity->tick();

  //Button press handling
  handleButton();

  //Auto brightness handling
  handleLDR();

  //Communications handling
  handleComms();
}



