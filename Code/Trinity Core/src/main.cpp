#include "Trinity/Trinity.h"

Trinity *trinity;

void setup()
{
  Serial.begin(9600);

  trinity = new Trinity();
}

void loop()
{
  if(Serial.available())
  {
    delay(1000);
  }
  trinity->tick();
  delay(1);
}


