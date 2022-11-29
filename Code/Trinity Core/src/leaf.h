#ifndef LEAF_H
#define LEAF_H

#include <Arduino.h>

#include "globals.h"

/*-------------------------------------------------------------------------------------*/


typedef struct
{
  byte leafNumber;
  //Delay
  byte fxOffset;          //Both - How long it takes before this effect starts. Creates a offset/delay compared to other leafs.
  byte fxSpeed;           //Both - How fast the leaf progresses through it's effects

  //Effect
  byte fxType;   //Both - Type of effect (Breathing, flashing, custom.)
  byte fxNumber; //Both - Number of effect (Red, Yellow, Orange, Teal, Blue, Cycle.)
  
  byte customRedValue;
  byte customGreenValue;
  byte customBlueValue;
 
  //Colour stuff
  byte redValue;         //Sys - The R value of this leaf
  byte greenValue;       //Sys - The G value of this leaf
  byte blueValue;        //Sys - The B value of this leaf
  byte dummyValue;       //Sys - A invisible value, used for timings and delays.
  
  byte fxProgression;    //Sys - How far into a effect are we? (think of rainbow mode: What colour is cycling?)
  byte cycleProgression; //Sys - What fxNumber is currently being cycled? 
  
  //Delay & time stuff
  int timer;             //Sys - The leaf's timer. If this timer reaches fxOfsset, the leaf will activate.
}Leaf;
/*-------------------------------------------------------------------------------------*/

Leaf* getLeaf(byte leafNumber);

#endif