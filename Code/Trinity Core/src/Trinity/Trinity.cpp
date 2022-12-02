#include "Trinity.h"

Trinity::Trinity()
{
  Serial.println(F("Trinity Starting..."));

  uint8_t panelsAmount = setupPanels_Test();

  Serial.println(F("Panels Initialised, starting"));

  ledManager = new LedManager(panels, panelsAmount);

  Serial.println(F("Setup Finished"));

  Serial.println(F("Trinity Started"));
  Serial.println(F("---===STARTUP COMPLETED===---"));
  Serial.println();
}

uint8_t Trinity::setupPanels_Test()
{
  Serial.println(F("Allocatig..."));

  panels = (Panel**)malloc(sizeof(Panel*) * PANELSETUP_TEST_AMOUNT);

  Serial.println(F("Array allocated..."));
  
  panels[0] = new Panel( 0, CLOCK_COUNTERWISE, COMPASS_SOUTH_EAST, LEDSAMOUNT_TRIANGLE);
  panels[1] = new Panel( 1, CLOCK_COUNTERWISE, COMPASS_SOUTH,      LEDSAMOUNT_TRIANGLE);
  panels[2] = new Panel( 2, CLOCK_COUNTERWISE, COMPASS_SOUTH_WEST, LEDSAMOUNT_TRIANGLE);
  panels[3] = new Panel( 3, CLOCK_CLOCKWISE,   COMPASS_NORTH_EAST, LEDSAMOUNT_TRIANGLE);
  panels[4] = new Panel( 4, CLOCK_CLOCKWISE,   COMPASS_NORTH,      LEDSAMOUNT_TRIANGLE);
  panels[5] = new Panel( 5, CLOCK_CLOCKWISE,   COMPASS_NORTH_WEST, LEDSAMOUNT_TRIANGLE);
  
  Serial.println(F("Allocating complete"));
  
  return PANELSETUP_TEST_AMOUNT;
}

void Trinity::tick()
{
  ledManager->tick();
}