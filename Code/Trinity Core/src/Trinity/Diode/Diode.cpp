#include "Trinity/Diode/Diode.h"

Diode::Diode(uint8_t number)
{
  this->number = number;
}










bool Diode::getColourClearance(byte colourToClear)
{
  switch (colourToClear)
  {
    case COLOUR_RED:
    {
      if(colour == COLOUR_BLACK || colour == COLOUR_RED || colour == COLOUR_YELLOW || colour == COLOUR_VIOLET) return true;
      return false;
    }
    break;

    case COLOUR_GREEN:
    {
      if(colour == COLOUR_BLACK || colour == COLOUR_YELLOW || colour == COLOUR_GREEN || colour == COLOUR_CYAN) return true;
      return false;
    }
    break;

    case COLOUR_BLUE:
    {
      if(colour == COLOUR_BLACK || colour == COLOUR_CYAN || colour == COLOUR_BLUE || colour == COLOUR_VIOLET) return true;
      return false;
    }
    break;
  }
  return false;
}
void Diode::FX_rainbow()
{
  switch (fxProgression)
  {
    case 0:
    {
      r = 0;
      g = 0;
      b = 255;

      fxProgression++;
    }
    break;

    case 1:
    {
      r++;
      if (r == 255)fxProgression++;
    }
    break;

    case 2:
    {
      b = b - 1;
      if (b == 0)
      {
        if(effect == 1)fxProgression++;
        else fxProgression = fxProgression + 3;
      }
    }
    break;

    case 3:
    {
      g++;
      if (g == 255)fxProgression++;
    }
    break;

    case 4:
    {
      r = r - 1;
      if (r == 0)
      {
        if(effect == 1)fxProgression++;
        else fxProgression = fxProgression + 3;
      }
    }
    break;

    case 5:
    {
      b++;
      if (b == 255)
      {
        if(effect == 1)fxProgression++;
        else fxProgression = fxProgression - 1;
      }
    }
    break;

    case 6:
    {
      if(effect == 1)
      {
        g = g - 1;
        if (g == 0)fxProgression++;
      }
      else fxProgression++;
    }
    break;

    default:
    {
      fxProgression = 0;
    }
    break;
  }
}
void Diode::FX_fire()
{
  if(fxProgression == 0)
  {
      r = 255;
      g = random(0, 200);
      b = 0;
  }
  else if (g < 90)g++;
  fxProgression++;

  if(g > 25 && random(0, offset) ==  0)g = g - 5;

  if(g < 150 && offset > 5)if(random(10, offset) > 10)g = g + 6;
}
void Diode::FX_blink()
{
  for(byte i = 0; i < speed; i++)
  {
    if(fxCycleProgression == 7) fxCycleProgression = 0;
    uint8_t colourNumber = effect;
    if(effect == 7) colourNumber = fxCycleProgression;

    bool allowRed = getColourClearance(COLOUR_RED);
    bool allowGreen = getColourClearance(COLOUR_GREEN);
    bool allowBlue = getColourClearance(COLOUR_BLUE);

    switch (fxProgression)
    {
      case 0:
      {
        if(allowRed)r = 255;
        else r = 0;

        if(allowGreen)g = 255;
        else g = 0;

        if(allowBlue)b = 255;
        else b = 0;

        d = 0;

        fxProgression++;
      }
      break;
      
      case 1:
      {
        d++;

        if(d == 20) fxProgression++;
      }
      break;

      case 2:
      {
        r = 0;
        g = 0;
        b = 0;

  	    fxProgression++;
      }
      break;

      case 3:
      {
        d++;

        if(d == 40 && effect == 3) fxProgression = fxProgression + 2;
        if(d == 255) fxProgression++;
      }
      break;




      case 5: //Double effect start
      {
        if(allowRed)r = 255;
        if(allowGreen)g = 255;
        if(allowBlue)b = 255;

        fxProgression++;
      }
      break;

      case 6:
      {
        d++;

        if(d == 60) fxProgression++;
      }
      break;

      case 7:
      {
        r = 0;
        g = 0;
        b = 0;

  	    fxProgression++;
      }
      break;

      case 8:
      {
        d++;

        if(d == 253) fxProgression++;
      }
      break; //Double effect end




      default:
      {
        fxProgression = 0;
        fxCycleProgression++;
      }
      break;
    }
  }
}
void Diode::FX_static()
{
  for(byte i = 0; i < speed; i++)
  {
    if(fxCycleProgression == 7) fxCycleProgression = 0;
    uint8_t colourNumber = effect;
    if(effect == 7) colourNumber = fxCycleProgression;

    bool allowRed = getColourClearance(COLOUR_RED);
    bool allowGreen = getColourClearance(COLOUR_GREEN);
    bool allowBlue = getColourClearance(COLOUR_BLUE);

    switch (fxProgression)
    {
      case 0:
      {
        if(allowRed)r = 255;
        else r = 0;

        if(allowGreen)g = 255;
        else g = 0;

        if(allowBlue)b = 255;
        else b = 0;

        d = 0;

        fxProgression++;
      }
      break;
      
      case 1:
      {
        d++;

        if(d == 255) fxProgression++;
      }
      break;

      default:
      {
        fxProgression = 0;
        fxCycleProgression++;
      }
      break;
    }
  }
}
void Diode::FX_breathing()
{
  for(byte i = 0; i < speed; i++)
  {
    if(fxCycleProgression == 7) fxCycleProgression = 0;
    uint8_t colourNumber = effect;
    if(effect == 7) colourNumber = fxCycleProgression;

    bool allowRed = getColourClearance(COLOUR_RED);
    bool allowGreen = getColourClearance(COLOUR_GREEN);
    bool allowBlue = getColourClearance(COLOUR_BLUE);

    switch (fxProgression)
    {
      case 0:
      {
        if(effect == 4 || effect == 5)
        {
          r = 0;
          g = 0;
          b = 0;
        }
        else
        {
          r = 255;
          g = 255;
          b = 255;
        }

        d = 0;

        fxProgression++;
      }
      break;

      case 1:
      {
        if(effect == 4 || effect == 5)
        {
          if(allowRed)r++;
          if(allowGreen)g++;
          if(allowBlue)b++;
        }
        else
        {
          if(!allowRed)r--;
          if(!allowGreen)g--;
          if(!allowBlue)b--;
        }

        d++;

        if(d == 255)fxProgression++;
      }
      break;

      case 2:
      {
        if(effect == 4 || effect == 5)
        {
          if(allowRed)r--;
          if(allowGreen)g--;
          if(allowBlue)b--;
        }
        else
        {
          if(!allowRed)r++;
          if(!allowGreen)g++;
          if(!allowBlue)b++;
        }

        d--;

        if(d == 0)
        {
          if(effect == 5 || effect == 11)fxProgression = fxProgression + 2;
          else fxProgression++;
        }
      }
      break;



      case 4: //Begin of double code
      {
        d++;

        if(d == 255)fxProgression++;
      }
      break;

      case 5:
      {
        d--;

        if(d == 1)fxProgression++;
      }
      break; //End of double code
      




      default:
      {
        fxProgression = 0;
        fxCycleProgression++;
      }
      break;
    }
  }
}
void Diode::FX_flash()
{
  for(byte i = 0; i < speed; i++)
  {
    if(fxCycleProgression == 7) fxCycleProgression = 0;
    uint8_t colourNumber = effect;
    if(effect == 7) colourNumber = fxCycleProgression;

    bool allowRed = getColourClearance(COLOUR_RED);
    bool allowGreen = getColourClearance(COLOUR_GREEN);
    bool allowBlue = getColourClearance(COLOUR_BLUE);

    switch (fxProgression)
    {
      case 0:
      {
        if(allowRed)r = 255;
        else r = 0;

        if(allowGreen)g = 255;
        else g = 0;

        if(allowBlue)b = 255;
        else b = 0;

        d = 255;

        fxProgression++;
      }
      break;

      case 1:
      {
        if(allowRed)r = r - 5;
        if(allowGreen)g = g - 5;
        if(allowBlue)b = b - 5;

        d = d - 5;

        
        if(effect == 7 && d == 100)fxProgression = fxProgression + 3;
        if(d == 0)fxProgression++;
      }
      break;

      case 2:
      {
        d++;
        if (d == 255)fxProgression++;
      }
      break;





      case 4://Start of double code
      {
        if(effect == 7)
        {
          if(allowRed)r = 255;
          if(allowGreen)g = 255;
          if(allowBlue)b = 255;

          d = 255;

          fxProgression++;
        }
        else
        {
          fxProgression = 0;
          fxCycleProgression++;
        }
      }
      break;

      case 5:
      {
        if(allowRed)r = r - 5;
        if(allowGreen)g = g - 5;
        if(allowBlue)b = b - 5;

        d = d - 5;

        if(d == 0)fxProgression++;
      }
      break;

      case 6:
      {
        d++;
        if (d == 223)fxProgression++;
      }
      break; //End of double code

      


      




      default:
      {
        fxProgression = 0;
        fxCycleProgression++;
      }
      break;
    }
  }

  
}


void Diode::tick()
{
  if (offsetTimer < offset)
  {
    offsetTimer++;
  }
  else
  {
    switch (effect)
    {
    case EFFECT_RAINBOW:
      // FX_rainbow();
      break;

    case EFFECT_SYNTHBOW:
      // FX_rainbow();
      break;

    case EFFECT_FIRE:
      // FX_fire();
      break;

    case EFFECT_STATIC:
      // FX_static();

    case EFFECT_BLINK:
      // FX_blink();
      break;

    case EFFECT_BREATHING:
      // FX_breathing();
      break;

    case EFFECT_PAUSEDBREATHING:
      // FX_breathing();
      break;

    case EFFECT_FLASH:
      // FX_flash();
      break;

    case EFFECT_HEARTBEAT:
      // FX_flash();
      break;
    }
  }
}
CRGB Diode::getRGB()
{
  uint8_t r    = (this->r * this->brightness)/255;
  uint8_t g  = (this->g * this->brightness)/255;
  uint8_t b   = (this->b * this->brightness)/255;
  return CRGB(r, g, b);
}
