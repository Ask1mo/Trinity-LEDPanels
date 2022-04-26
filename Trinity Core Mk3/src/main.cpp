#include "Trinity.h"

Trinity trinity = Trinity();

#define LED_PIN     12
#define MAXTRANSMISSIONLENGTH 11
#define GLOBALSTRANSMISSIONLENGTH 5
#define REQUESTTRANSMISSIONLENGTH 7
#define LEAVES 16

byte brightness = 15;
byte leafDelay = 5;



#define READDELAY 1000
bool readerMode = false;
unsigned long currentMillis;
unsigned long leafMillis;
unsigned long readMillis;

void setup()
{
  Serial.begin(9600);
  Serial.println(F("Trinity Core - Ask Blommaert"));
}

void loop()
{
  currentMillis = millis();

  if(Serial.available())
  {
    readerMode = true;
    readMillis = currentMillis;
  }

  if(currentMillis - readMillis >= READDELAY) readerMode = false;


  if (readerMode)
  {
    //transmissionReader();
  }
  else if(currentMillis - leafMillis >= leafDelay)
  {
    bool isSoundModeActive = false;
    for(byte i = 0; i < LEAVES; i++)
    {
      //Leaf* leaf = getLeaf(i);

      //if (leaf->fxType == 8) isSoundModeActive = true;
    }
    //if(isSoundModeActive) soundVisualiser(currentMillis);

    for (byte i = 0; i<LEAVES; i++)
    {
      //Leaf* leaf = getLeaf(i);
      //effectsApplier(leaf, brightness);
    }
    
    

    leafMillis = currentMillis;
  }
}