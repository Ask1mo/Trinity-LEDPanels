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
      trinity->setBrightness(data.brightness, true); 
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
    trinity->setBrightness(lightSensor->getRecommendedBrightness(), true);
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
          trinity->setBrightness(BRIGHTNESS_1_DIM, true);
          lightSensor->setEnabled(false);
          Serial.println(F("Changing sys brightness to DIM"));
        }
        break;
        case BRIGHTNESS_1_DIM:
        {
          trinity->setBrightness(BRIGHTNESS_2_NOR, true);
          lightSensor->setEnabled(false);
          Serial.println(F("Changing sys brightness to NORMAL"));
        }
        break;
        case BRIGHTNESS_2_NOR:
        {
          trinity->setBrightness(BRIGHTNESS_3_MAX, true);
          lightSensor->setEnabled(false);
          Serial.println(F("Changing sys brightness to MAX"));

        }
        break;
        case BRIGHTNESS_3_MAX:
        {
          trinity->setBrightness(BRIGHTNESS_4_AUT, true);
          lightSensor->setEnabled(true);
          Serial.println(F("Changing sys brightness to Automatic"));
        }
        break;
        default:
        {
          trinity->setBrightness(BRIGHTNESS_0_OFF, true);
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

  button          = new AskButton   (PIN_BUTTON, 1000);
  lightSensor     = new LightSensor (PIN_LIGHTSENSOR);
  comms           = new Comms       ();
  trinity         = new Trinity     (PIN_LEDS, 60, true);

  
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
  trinity->addPanel(10);
  trinity->addPanel(11);
  trinity->addPanel(10);
  trinity->addPanel(11);
  trinity->addPanel(10);
  trinity->addPanel(10);
  trinity->addPanel(11);
  trinity->addPanel(10);
  trinity->addPanel(10);
  trinity->addPanel(10);
  trinity->addPanel(11);
  trinity->addPanel(10);
  trinity->addPanel(11);
  trinity->addPanel(10);
  trinity->addPanel(9 );
  //Tower Top
  trinity->addPanel(10);
  trinity->addPanel(11);
  trinity->addPanel(10);
  trinity->addPanel(10);
  trinity->addPanel(10);
  trinity->addPanel(10);
  trinity->addPanel(11);
  trinity->addPanel(10);
  trinity->addPanel(10);
  trinity->addPanel(11);
  trinity->addPanel(10);
  trinity->addPanel(11);
  trinity->addPanel(10);
  trinity->addPanel(12);
  //Rigns
  trinity->addPanel(37);
  trinity->addPanel(37);
  trinity->addPanel(37);
  trinity->addPanel(37);
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
  trinity->addPanel(0, 0, COMPASS_NORTH, CLOCK_CLOCKWISE, 3);
  trinity->addPanel(1, 0, COMPASS_NORTH, CLOCK_CLOCKWISE, 3);
  trinity->addPanel(2, 0, COMPASS_NORTH, CLOCK_CLOCKWISE, 3);
  trinity->addPanel(0, 1, COMPASS_NORTH, CLOCK_CLOCKWISE, 3);
  trinity->addPanel(1, 1, COMPASS_NORTH, CLOCK_CLOCKWISE, 3);
  trinity->addPanel(2, 1, COMPASS_NORTH, CLOCK_CLOCKWISE, 3);
  #endif
  #ifdef PANELSETUP_EYEOFTHESTORM
  for (uint8_t i = 0; i < 54; i++) trinity->addPanel(new Panel(i, i, 0, CLOCK_CLOCKWISE, COMPASS_NORTH, 5));
  #endif
  #ifdef PANELSETUP_SHARKSALES
  trinity->addPanel(3);
  trinity->addPanel(10);
  trinity->addPanel(3);
  trinity->addPanel(10);
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



