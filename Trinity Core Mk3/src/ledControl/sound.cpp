#include "ledControl/sound.h"

unsigned long soundpeakMillis;
unsigned long soundMinimumMillis;
byte soundInput;
byte soundArray[FLOATINGAVERAGESIZE];

byte soundLevel = 0;
byte soundPeak = 0;
    
byte soundMinimum= 255;
byte soundMaximum = 0;


void soundVisualiser(unsigned long currentMillis)
{  
  /*TAKING SENSOR READINGS*/
  float voltageValue = analogRead(SOUNDPIN) / 1024.0 * VOLTAGE; //Takes a measurement
  soundInput = voltageValue * SOUNDANALOGTODECIBELSNUMBER;
  

  /*GETTING THE SOUND LEVEL*/
  float soundAverage = 0; //Resets the average to 0
  soundArray[(FLOATINGAVERAGESIZE-1)] = soundInput; //Takes the measured sound and puts it in an array in order to get the average
  for (int i = 0; i<(FLOATINGAVERAGESIZE-1); i++) //Moves all the values back one position
  {
    soundAverage = soundAverage + soundArray[i];
    soundArray[i] = soundArray[i+1];
  }
  soundLevel = soundAverage / (FLOATINGAVERAGESIZE-1);//Gets the soundaverage out of the array





  /*DEFINING THE SOUND MINIMUM*/
  if (soundMinimum > soundLevel/* || globals->soundLowest < 30*/)//If the average is lower than the lowest recorded sound level |OR| The lowest sound recorded is quieter than 30 decibels
  {
    soundMinimum--; /*= (byte)soundAverage;*/ //Makes sure the lowest point of the sound stays as low as possible.
  }
  /*
  else if(currentMillis - soundMinimumMillis >= SOUNDMILLISDELAY)//If the average is lower than the lowest recorded sound level |OR| The lowest sound recorded is quieter than 30 decibels
  {
    globals->soundMinimum++;
    soundMinimumMillis = millis;
  }
  */

/*
 if (globals->soundLowest > globals->soundLevel)//If the average is lower than the lowest recorded sound level
 {
   globals->soundLowest = globals->soundLevel; //Makes sure the lowest point of the sound stays as low as possible.
 }
 */

  soundLevel = soundLevel - soundMinimum; //Takes the sound level and removes the low-end of the noise. This way all the sound that's just too quiet will be removed

  if (soundPeak < soundLevel) //If the current sound is louder than sound peak (not the loudest sound ever recorded)
  {
    soundPeak = soundLevel; //The current sound is stored as the sound peak
    soundpeakMillis = currentMillis; //The timer for decreasing the sound peak is reset.
  }

  if (soundPeak > 0 && currentMillis - soundpeakMillis >= SOUNDPEAKDELAY) //After some time the soundpeak starts to decrease.
  {
    soundPeak--;// Decrease the sound peak
  }

  soundMaximum = 0; //Resets the limit for what the loudest sound in the measurements should be (it can be topped by the actual sound level. and then it will just go over it)
  
  /*
  for (byte i = 0; i < LEAVES; i++)
  {
    Leaf *leaf = getLeaf(i);
    if (globals->soundMaximum < leaf->fxOffset)globals->soundMaximum = leaf->fxOffset; //Re-applies the top sound level from the highest one of all leaves.
  }
  */
}