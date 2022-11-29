#include "Trinity.h"

Trinity* trinity;

Vector<Panel*> setupTeststrip()
{
  Vector<Panel*> panels;
  panels.push_back(new Panel( 0, 0, 0, CLOCK_COUNTERWISE, COMPASS_SOUTH_EAST, LEDSAMOUNT_TRIANGLE));
  panels.push_back(new Panel( 1, 1, 0, CLOCK_COUNTERWISE, COMPASS_SOUTH,      LEDSAMOUNT_TRIANGLE));
  panels.push_back(new Panel( 2, 2, 0, CLOCK_COUNTERWISE, COMPASS_SOUTH_WEST, LEDSAMOUNT_TRIANGLE));
  panels.push_back(new Panel( 3, 3, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH_EAST, LEDSAMOUNT_TRIANGLE));
  panels.push_back(new Panel( 4, 4, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH,      LEDSAMOUNT_TRIANGLE));
  panels.push_back(new Panel( 5, 5, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH_WEST, LEDSAMOUNT_TRIANGLE));
  return panels;
}
Vector<Panel*> setupTrinityPrime()
{
  Vector<Panel*> panels;
  panels.push_back(new Panel( 0, 0, 0, CLOCK_COUNTERWISE, COMPASS_SOUTH_EAST, LEDSAMOUNT_TRIANGLE));
  panels.push_back(new Panel( 1, 1, 0, CLOCK_COUNTERWISE, COMPASS_SOUTH,      LEDSAMOUNT_TRIANGLE));
  panels.push_back(new Panel( 2, 2, 0, CLOCK_COUNTERWISE, COMPASS_SOUTH_WEST, LEDSAMOUNT_TRIANGLE));
  panels.push_back(new Panel( 3, 3, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH_EAST, LEDSAMOUNT_TRIANGLE));
  panels.push_back(new Panel( 4, 4, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH,      LEDSAMOUNT_TRIANGLE));
  panels.push_back(new Panel( 5, 5, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH_WEST, LEDSAMOUNT_TRIANGLE));
  panels.push_back(new Panel( 6, 0, 0, CLOCK_COUNTERWISE, COMPASS_SOUTH_EAST, LEDSAMOUNT_TRIANGLE));
  panels.push_back(new Panel( 7, 1, 0, CLOCK_COUNTERWISE, COMPASS_SOUTH,      LEDSAMOUNT_TRIANGLE));
  panels.push_back(new Panel( 8, 2, 0, CLOCK_COUNTERWISE, COMPASS_SOUTH_WEST, LEDSAMOUNT_TRIANGLE));
  panels.push_back(new Panel( 9, 3, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH_EAST, LEDSAMOUNT_TRIANGLE));
  panels.push_back(new Panel(10, 4, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH,      LEDSAMOUNT_TRIANGLE));
  panels.push_back(new Panel(11, 5, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH_WEST, LEDSAMOUNT_TRIANGLE));
  panels.push_back(new Panel(12, 0, 0, CLOCK_COUNTERWISE, COMPASS_SOUTH_EAST, LEDSAMOUNT_TRIANGLE));
  panels.push_back(new Panel(13, 1, 0, CLOCK_COUNTERWISE, COMPASS_SOUTH,      LEDSAMOUNT_TRIANGLE));
  panels.push_back(new Panel(14, 2, 0, CLOCK_COUNTERWISE, COMPASS_SOUTH_WEST, LEDSAMOUNT_TRIANGLE));
  panels.push_back(new Panel(15, 3, 0, CLOCK_CLOCKWISE,   COMPASS_NORTH_EAST, LEDSAMOUNT_TRIANGLE));

  return panels;
}

void setup()
{
  Serial.begin(9600);
  Serial.println(F("Trinity Core MK3 - Ask Blommaert"));

  Vector<Panel*> panels = setupTeststrip();
  trinity = new Trinity(panels);
}

void loop()
{
  trinity->tick();
}


