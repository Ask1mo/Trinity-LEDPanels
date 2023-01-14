#include "Trinity/Trinity.h"

Trinity *trinity;

void setup()
{
  Serial.begin(9600);

  trinity = new Trinity();
}

void loop()
{
  trinity->tick();
  delay(1);
}


