#include "effectsStorage/customFxList.h"





/*-------------------------------------------------------------------------------------*/



void customFx_off(Leaf *leaf)
{
  leaf->redValue = 0;
  leaf->greenValue = 0;
  leaf->blueValue = 0;
}

void customFx_rainbow(Leaf *leaf)
{
  switch (leaf->fxProgression)
  {
    case 0:
    {
      leaf->redValue = 0;
      leaf->greenValue = 0;
      leaf->blueValue = 255;

      leaf->fxProgression++;
    }
    break;

    case 1:
    {
      leaf->redValue++;
      if (leaf->redValue == 255)leaf->fxProgression++;
    }
    break;

    case 2:
    {
      leaf->blueValue = leaf->blueValue - 1;
      if (leaf->blueValue == 0)
      {
        if(leaf->fxNumber == 1)leaf->fxProgression++;
        else leaf->fxProgression = leaf->fxProgression + 3;
      }
    }
    break;

    case 3:
    {
      leaf->greenValue++;
      if (leaf->greenValue == 255)leaf->fxProgression++;
    }
    break;

    case 4:
    {
      leaf->redValue = leaf->redValue - 1;
      if (leaf->redValue == 0)
      {
        if(leaf->fxNumber == 1)leaf->fxProgression++;
        else leaf->fxProgression = leaf->fxProgression + 3;
      }
    }
    break;

    case 5:
    {
      leaf->blueValue++;
      if (leaf->blueValue == 255)
      {
        if(leaf->fxNumber == 1)leaf->fxProgression++;
        else leaf->fxProgression = leaf->fxProgression - 1;
      }
    }
    break;

    case 6:
    {
      if(leaf->fxNumber == 1)
      {
        leaf->greenValue = leaf->greenValue - 1;
        if (leaf->greenValue == 0)leaf->fxProgression++;
      }
      else leaf->fxProgression++;
    }
    break;

    default:
    {
      leaf->fxProgression = 0;
    }
    break;
  }
}

void customFx_strobe(Leaf *leaf)
{
  switch (leaf->fxProgression)
  {
    case 0:
    {
      leaf->fxProgression++;
      leaf->redValue = 255;
      leaf->greenValue = 255;
      leaf->blueValue = 255;
      leaf->dummyValue = 0;
    }
    break;

    case 1:
    {
      leaf->dummyValue++;
      if (leaf->dummyValue == 10)leaf->fxProgression++;
    }
    break;

    case 2:
    {
      leaf->redValue = 0;
      leaf->greenValue = 0;
      leaf->blueValue = 0;
      leaf->dummyValue = leaf->dummyValue - 1;
      if (leaf->dummyValue == 0)leaf->fxProgression++;
    }
    break;

    default:
    {
      leaf->fxProgression = 0;
    }
    break;
  }
}

void customFx_fire(Leaf * leaf)
{
  if(leaf->fxProgression == 0)
  {
      leaf->redValue = 255;
      leaf->greenValue = random(0, 200);
      leaf->blueValue = 0;
  }
  else if (leaf->greenValue < 90)leaf->greenValue++;
  leaf->fxProgression++;

  if(leaf->greenValue > 25 && random(0, leaf->fxOffset) ==  0)leaf->greenValue = leaf->greenValue - 5;

  if(leaf->greenValue < 150 && leaf->fxOffset > 5)if(random(10, leaf->fxOffset) > 10)leaf->greenValue = leaf->greenValue + 6;
}

void customFx_christmas(Leaf *leaf)
{
  Globals* globals = getGlobals();
  for(byte i = 0; i < leaf->fxSpeed; i++)
  {
    switch (leaf->fxProgression)
    {
      case 0:
      {
        leaf->redValue = 50;
        leaf->greenValue = 50;
        leaf->blueValue = 255;
        leaf->dummyValue = 0;

        leaf->fxProgression++;
      }
      break;
      
      case 1:
      {
        leaf->dummyValue++;

        if(leaf->dummyValue == 5) leaf->fxProgression++;
      }
      break;

      case 2:
      {
        leaf->redValue = 255;
        leaf->greenValue = 255;
        leaf->blueValue = 50;

  	    leaf->fxProgression++;
      }
      break;

      case 3:
      {
        leaf->dummyValue++;

        if(leaf->dummyValue == 255) leaf->fxProgression = 0;
      }
      break;
    }
  }
}

void customFx_customRGB(Leaf *leaf)
{
  leaf->redValue = leaf->customRedValue;
  leaf->greenValue = leaf->customGreenValue;
  leaf->blueValue = leaf->customBlueValue;
}

void customFx_notBound(Leaf *leaf)
{
  switch (leaf->fxProgression)
  {
    case 0:
    {
      leaf->fxProgression++;
      leaf->redValue = 255;
      leaf->greenValue = 0;
      leaf->blueValue = 0;
      leaf->dummyValue = 0;
    }
    break;

    case 1:
    {
      leaf->dummyValue++;
      if (leaf->dummyValue == 50)leaf->fxProgression++;
    }
    break;

    case 2:
    {
      leaf->redValue = 255;
      leaf->greenValue = 75;
      leaf->blueValue = 0;
      leaf->dummyValue = leaf->dummyValue - 1;
      if (leaf->dummyValue == 0)leaf->fxProgression++;
    }
    break;

    default:
    {
      leaf->fxProgression = 0;
    }
    break;
  }
}