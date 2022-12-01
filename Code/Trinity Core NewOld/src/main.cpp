#include "Trinity/Trinity.h"

Trinity* trinity;

void setup()
{
  Serial.begin(9600);
  Serial.println(F("Trinity Core - Ask Blommaert"));

  Vector<Panel*> panels = setupTeststrip();
  trinity = new Trinity(panels);
}

void loop()
{
  trinity->tick();
}


