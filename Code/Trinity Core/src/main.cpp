#include "Trinity/Trinity.h"

#define PANELSETUP_TEST   0
#define PANELSETUP_PRIME  1
#define PANELSETUP_EVA    3
#define PANELSETUP_LIAM   4
#define PANELSETUP_TEST_AMOUNT  6
#define PANELSETUP_PRIME_AMOUNT 16
#define PANELSETUP_EVA_AMOUNT   4
#define PANELSETUP_LIAM_AMOUNT  10

//#define PANELSAMOUNT  6
#define PIN_LEDS      12

Trinity   *trinity;
Panel     **panels;
uint8_t panelsAmount;

bool setupPanels_Test()
{
  panels = (Panel**)malloc(sizeof(Panel*) * PANELSETUP_TEST_AMOUNT);
  //if (PANELSAMOUNT != PANELSETUP_TEST_AMOUNT) return false;
  panels[0] = new Panel( 0, CLOCK_COUNTERWISE, COMPASS_SOUTH_EAST, LEDSAMOUNT_TRIANGLE);
  panels[1] = new Panel( 1, CLOCK_COUNTERWISE, COMPASS_SOUTH,      LEDSAMOUNT_TRIANGLE);
  panels[2] = new Panel( 2, CLOCK_COUNTERWISE, COMPASS_SOUTH_WEST, LEDSAMOUNT_TRIANGLE);
  panels[3] = new Panel( 3, CLOCK_CLOCKWISE,   COMPASS_NORTH_EAST, LEDSAMOUNT_TRIANGLE);
  panels[4] = new Panel( 4, CLOCK_CLOCKWISE,   COMPASS_NORTH,      LEDSAMOUNT_TRIANGLE);
  panels[5] = new Panel( 5, CLOCK_CLOCKWISE,   COMPASS_NORTH_WEST, LEDSAMOUNT_TRIANGLE);
  panelsAmount = 6;
  return true;
}
bool setupPanels(uint8_t stripID)
{
  bool success = true;
  switch (stripID)
  {
    case PANELSETUP_TEST:
    success = setupPanels_Test();
    break;

    case PANELSETUP_PRIME:
    success = setupPanels_Test();
    break;
  }
  if (success == false)
  {
    Serial.println(F("ERROR: panels to define amount does not match PANELSAMOUNT"));
  }
  return success;
}

void setup()
{
  Serial.begin(9600);
  Serial.println(F("Trinity Core - Ask Blommaert"));

  if (setupPanels(PANELSETUP_TEST) == false)
  {
    Serial.println(F("Critical setup error, system forcefully blocked"));
    while(true);
  }
  trinity = new Trinity(panels, panelsAmount, PIN_LEDS);
}

void loop()
{
  trinity->tick();
}


