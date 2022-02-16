#include "effectsStorage/normalFxList.h"

/*-------------------------------------------------------------------------------------*/
byte colourNumber;
bool allowRed;
bool allowGreen;
bool allowBlue;
/*-------------------------------------------------------------------------------------*/

void effect_static(Leaf *leaf)
{
  for(byte i = 0; i < leaf->fxSpeed; i++)
  {
    if(leaf->cycleProgression == 7) leaf->cycleProgression = 0;
    colourNumber = leaf->fxNumber;
    if(leaf->fxNumber == 7) colourNumber = leaf->cycleProgression;

    allowRed = getColourClearance(colourNumber, 0);
    allowGreen = getColourClearance(colourNumber, 1);
    allowBlue = getColourClearance(colourNumber, 2);

    switch (leaf->fxProgression)
    {
      case 0:
      {
        if(allowRed)leaf->redValue = 255;
        else leaf->redValue = 0;

        if(allowGreen)leaf->greenValue = 255;
        else leaf->greenValue = 0;

        if(allowBlue)leaf->blueValue = 255;
        else leaf->blueValue = 0;

        leaf->dummyValue = 0;

        leaf->fxProgression++;
      }
      break;
      
      case 1:
      {
        leaf->dummyValue++;

        if(leaf->dummyValue == 255) leaf->fxProgression++;
      }
      break;

      default:
      {
        leaf->fxProgression = 0;
        leaf->cycleProgression++;
      }
      break;
    }
  }
}

void effect_blink(Leaf *leaf)
{
  for(byte i = 0; i < leaf->fxSpeed; i++)
  {
    if(leaf->cycleProgression == 7) leaf->cycleProgression = 0;
    colourNumber = leaf->fxNumber;
    if(leaf->fxNumber == 7) colourNumber = leaf->cycleProgression;

    allowRed = getColourClearance(colourNumber, 0);
    allowGreen = getColourClearance(colourNumber, 1);
    allowBlue = getColourClearance(colourNumber, 2);

    switch (leaf->fxProgression)
    {
      case 0:
      {
        if(allowRed)leaf->redValue = 255;
        else leaf->redValue = 0;

        if(allowGreen)leaf->greenValue = 255;
        else leaf->greenValue = 0;

        if(allowBlue)leaf->blueValue = 255;
        else leaf->blueValue = 0;

        leaf->dummyValue = 0;

        leaf->fxProgression++;
      }
      break;
      
      case 1:
      {
        leaf->dummyValue++;

        if(leaf->dummyValue == 20) leaf->fxProgression++;
      }
      break;

      case 2:
      {
        leaf->redValue = 0;
        leaf->greenValue = 0;
        leaf->blueValue = 0;

  	    leaf->fxProgression++;
      }
      break;

      case 3:
      {
        leaf->dummyValue++;

        if(leaf->dummyValue == 40 && leaf->fxType == 3) leaf->fxProgression = leaf->fxProgression + 2;
        if(leaf->dummyValue == 255) leaf->fxProgression++;
      }
      break;




      case 5: //Double effect start
      {
        if(allowRed)leaf->redValue = 255;
        if(allowGreen)leaf->greenValue = 255;
        if(allowBlue)leaf->blueValue = 255;

        leaf->fxProgression++;
      }
      break;

      case 6:
      {
        leaf->dummyValue++;

        if(leaf->dummyValue == 60) leaf->fxProgression++;
      }
      break;

      case 7:
      {
        leaf->redValue = 0;
        leaf->greenValue = 0;
        leaf->blueValue = 0;

  	    leaf->fxProgression++;
      }
      break;

      case 8:
      {
        leaf->dummyValue++;

        if(leaf->dummyValue == 253) leaf->fxProgression++;
      }
      break; //Double effect end




      default:
      {
        leaf->fxProgression = 0;
        leaf->cycleProgression++;
      }
      break;
    }
  }
}

void effect_breathing(Leaf *leaf)
{
  for(byte i = 0; i < leaf->fxSpeed; i++)
  {
    if(leaf->cycleProgression == 7) leaf->cycleProgression = 0;
    colourNumber = leaf->fxNumber;
    if(leaf->fxNumber == 7) colourNumber = leaf->cycleProgression;

    allowRed = getColourClearance(colourNumber, 0);
    allowGreen = getColourClearance(colourNumber, 1);
    allowBlue = getColourClearance(colourNumber, 2);

    switch (leaf->fxProgression)
    {
      case 0:
      {
        if(leaf->fxType == 4 || leaf->fxType == 5)
        {
          leaf->redValue = 0;
          leaf->greenValue = 0;
          leaf->blueValue = 0;
        }
        else
        {
          leaf->redValue = 255;
          leaf->greenValue = 255;
          leaf->blueValue = 255;
        }

        leaf->dummyValue = 0;

        leaf->fxProgression++;
      }
      break;

      case 1:
      {
        if(leaf->fxType == 4 || leaf->fxType == 5)
        {
          if(allowRed)leaf->redValue++;
          if(allowGreen)leaf->greenValue++;
          if(allowBlue)leaf->blueValue++;
        }
        else
        {
          if(!allowRed)leaf->redValue--;
          if(!allowGreen)leaf->greenValue--;
          if(!allowBlue)leaf->blueValue--;
        }

        leaf->dummyValue++;

        if(leaf->dummyValue == 255)leaf->fxProgression++;
      }
      break;

      case 2:
      {
        if(leaf->fxType == 4 || leaf->fxType == 5)
        {
          if(allowRed)leaf->redValue--;
          if(allowGreen)leaf->greenValue--;
          if(allowBlue)leaf->blueValue--;
        }
        else
        {
          if(!allowRed)leaf->redValue++;
          if(!allowGreen)leaf->greenValue++;
          if(!allowBlue)leaf->blueValue++;
        }

        leaf->dummyValue--;

        if(leaf->dummyValue == 0)
        {
          if(leaf->fxType == 5 || leaf->fxType == 11)leaf->fxProgression = leaf->fxProgression + 2;
          else leaf->fxProgression++;
        }
      }
      break;



      case 4: //Begin of double code
      {
        leaf->dummyValue++;

        if(leaf->dummyValue == 255)leaf->fxProgression++;
      }
      break;

      case 5:
      {
        leaf->dummyValue--;

        if(leaf->dummyValue == 1)leaf->fxProgression++;
      }
      break; //End of double code
      




      default:
      {
        leaf->fxProgression = 0;
        leaf->cycleProgression++;
      }
      break;
    }
  }
}

void effect_flash(Leaf *leaf)
{
  for(byte i = 0; i < leaf->fxSpeed; i++)
  {
    if(leaf->cycleProgression == 7) leaf->cycleProgression = 0;
    colourNumber = leaf->fxNumber;
    if(leaf->fxNumber == 7) colourNumber = leaf->cycleProgression;

    allowRed = getColourClearance(colourNumber, 0);
    allowGreen = getColourClearance(colourNumber, 1);
    allowBlue = getColourClearance(colourNumber, 2);

    switch (leaf->fxProgression)
    {
      case 0:
      {
        if(allowRed)leaf->redValue = 255;
        else leaf->redValue = 0;

        if(allowGreen)leaf->greenValue = 255;
        else leaf->greenValue = 0;

        if(allowBlue)leaf->blueValue = 255;
        else leaf->blueValue = 0;

        leaf->dummyValue = 255;

        leaf->fxProgression++;
      }
      break;

      case 1:
      {
        if(allowRed)leaf->redValue = leaf->redValue - 5;
        if(allowGreen)leaf->greenValue = leaf->greenValue - 5;
        if(allowBlue)leaf->blueValue = leaf->blueValue - 5;

        leaf->dummyValue = leaf->dummyValue - 5;

        
        if(leaf->fxType == 7 && leaf->dummyValue == 100)leaf->fxProgression = leaf->fxProgression + 3;
        if(leaf->dummyValue == 0)leaf->fxProgression++;
      }
      break;

      case 2:
      {
        leaf->dummyValue++;
        if (leaf->dummyValue == 255)leaf->fxProgression++;
      }
      break;





      case 4://Start of double code
      {
        if(leaf->fxType == 7)
        {
          if(allowRed)leaf->redValue = 255;
          if(allowGreen)leaf->greenValue = 255;
          if(allowBlue)leaf->blueValue = 255;

          leaf->dummyValue = 255;

          leaf->fxProgression++;
        }
        else
        {
          leaf->fxProgression = 0;
          leaf->cycleProgression++;
        }
      }
      break;

      case 5:
      {
        if(allowRed)leaf->redValue = leaf->redValue - 5;
        if(allowGreen)leaf->greenValue = leaf->greenValue - 5;
        if(allowBlue)leaf->blueValue = leaf->blueValue - 5;

        leaf->dummyValue = leaf->dummyValue - 5;

        if(leaf->dummyValue == 0)leaf->fxProgression++;
      }
      break;

      case 6:
      {
        leaf->dummyValue++;
        if (leaf->dummyValue == 223)leaf->fxProgression++;
      }
      break; //End of double code

      


      




      default:
      {
        leaf->fxProgression = 0;
        leaf->cycleProgression++;
      }
      break;
    }
  }

  
}

void effect_sound(Leaf *leaf)
{
  Globals* globals = getGlobals();
  
  allowRed = getColourClearance(leaf->fxNumber, 0);
  allowGreen = getColourClearance(leaf->fxNumber, 1);
  allowBlue = getColourClearance(leaf->fxNumber, 2);


  leaf->redValue = 0;
  leaf->greenValue = 0;
  leaf->blueValue = 0;

  if(globals->soundLevel > (leaf->fxOffset))
  {
    leaf->redValue = 255;
    if(globals->soundLevel<= globals->soundMaximum)
    {
      if(allowRed)leaf->redValue = 255-globals->soundLevel/globals->soundMaximum*255;
      if(allowGreen)leaf->greenValue = 255-globals->soundLevel/globals->soundMaximum*255;
      if(allowBlue)leaf->blueValue = 255-globals->soundLevel/globals->soundMaximum*255;
    }
    else
    {
      leaf->greenValue = 0;
      leaf->blueValue = 0;
    }

  }
  if(globals->soundPeak >= leaf->fxOffset && globals->soundPeak < leaf->fxOffset+leaf->fxSpeed && leaf->fxSpeed != 1)
  {
    leaf->redValue = 255;
    leaf->greenValue = 255;
    leaf->blueValue = 255;
  }
}