#include "Trinity.h"



Trinity* trinity;


void setup()
{
  Serial.begin(9600);
  Serial.println(F("Trinity Core MK3 - Ask Blommaert"));

  Vector<Panel*> panels;
  panels.push_back(new Panel( 0, 0, 0, COUNTERWISE, SOUTH_EAST));
  panels.push_back(new Panel( 1, 1, 0, COUNTERWISE, SOUTH));
  panels.push_back(new Panel( 2, 2, 0, COUNTERWISE, SOUTH_WEST));
  panels.push_back(new Panel( 3, 3, 0, CLOCKWISE,   NORTH_EAST));
  panels.push_back(new Panel( 4, 4, 0, CLOCKWISE,   NORTH));
  panels.push_back(new Panel( 5, 5, 0, CLOCKWISE,   NORTH_WEST));

  trinity = new Trinity(panels);
}

void loop()
{
  trinity->Tick();
}


/*
void add_TrinityPrime()
{
  trinity.AddPanel(new Panel( 0, 0, 0, COUNTERWISE, SOUTH_EAST));
  trinity.AddPanel(new Panel( 1, 1, 0, COUNTERWISE, SOUTH));
  trinity.AddPanel(new Panel( 2, 2, 0, COUNTERWISE, SOUTH_WEST));
  trinity.AddPanel(new Panel( 3, 3, 0, CLOCKWISE,   NORTH_EAST));
  trinity.AddPanel(new Panel( 4, 4, 0, CLOCKWISE,   NORTH));
  trinity.AddPanel(new Panel( 5, 5, 0, CLOCKWISE,   NORTH_WEST));
  
}*/