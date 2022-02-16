#include "communications/transmissionReader.h"
#include "ledcontrol/effectsApplier.h"
#include "ledcontrol/sound.h"

#define READDELAY 1000
bool readerMode = false;
unsigned long currentMillis;
unsigned long leafMillis;
unsigned long readMillis;

void setup()
{
  Serial.begin(9600);
  Serial.println(F("Trinity Core Edition - Ask Blommaert"));
  startLeds();
  pinMode(13, OUTPUT); //Setup the ledpin output
}

void loop()
{
  Globals* globals = getGlobals();
  currentMillis = millis();

  if(Serial.available())
  {
    readerMode = true;
    readMillis = currentMillis;
    globals->soundMinimum = 255;
  }

  if(currentMillis - readMillis >= READDELAY) readerMode = false;


  if (readerMode)
  {
    transmissionReader();
  }
  else if(currentMillis - leafMillis >= globals->leafDelay)
  {
    bool isSoundModeActive = false;
    for(byte i = 0; i < LEAVES; i++)
    {
      Leaf* leaf = getLeaf(i);

      if (leaf->fxType == 8) isSoundModeActive = true;
    }
    if(isSoundModeActive) soundVisualiser(currentMillis);

    for (byte i = 0; i<LEAVES; i++)
    {
      Leaf* leaf = getLeaf(i);
      effectsApplier(leaf, globals->brightness);
    }
    
    FastLED.show();

    leafMillis = currentMillis;
  }
}