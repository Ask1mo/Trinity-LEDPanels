#include "Trinity/Trinity.h"




Trinity *trinity;



void setup()
{
  Serial.begin(9600);
  Serial.println(F("Trinity Core - Ask Blommaert"));

  trinity = new Trinity();
}

void loop()
{
  trinity->tick();
}


