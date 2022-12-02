#include "Diode.h"

Diode::Diode(uint8_t number)
{
  this->number = number;

  this->brightness  = 255;
  this->effect      = EFFECT_CUSTOM_STATIC;
  this->colour      = COLOUR_CYCLE;
  this->offset      = 0;
  this->speed       = 1;

  for (uint8_t i = 0; i < AMOUNTOFCOLOURS; i++)
  {
    this->customRGB[i] = new struct ColourRGB;
    this->customRGB[i]->r = 255;
    this->customRGB[i]->g = 63;
    this->customRGB[i]->b = 127;
    //These are some preset empty colours for the custom RGB values.
  }

  this->r               = 0;
  this->g               = 0;
  this->b               = 0;
  this->d               = 0;
  this->c               = 0;
  this->fxProgression   = 0;          //In effect cycling
  this->offsetTimer     = 0;

}

bool Diode::getColourClearance(byte colourToClear, byte colourChannel)
{
  switch (colourChannel)
  {
  case COLOUR_RED:
  {
    if (colourToClear == COLOUR_BLACK || colourToClear == COLOUR_RED || colourToClear == COLOUR_YELLOW || colourToClear == COLOUR_VIOLET)
      return true;
    return false;
  }
  break;

  case COLOUR_GREEN:
  {
    if (colourToClear == COLOUR_BLACK || colourToClear == COLOUR_YELLOW || colourToClear == COLOUR_GREEN || colourToClear == COLOUR_CYAN)
      return true;
    return false;
  }
  break;

  case COLOUR_BLUE:
  {
    if (colourToClear == COLOUR_BLACK || colourToClear == COLOUR_CYAN || colourToClear == COLOUR_BLUE || colourToClear == COLOUR_VIOLET)
      return true;
    return false;
  }
  break;
  }
  return false;
}
void Diode::progressFX_custom_static()
{
  if (colour != COLOUR_CYCLE) c = colour;

  switch (fxProgression)
  {
  case 0:
  {
    r = customRGB[c]->r;
    g = customRGB[c]->g;
    b = customRGB[c]->b;

    d = 0;

    fxProgression++;
  }
  break;

  case 1:
  {
    d++;

    if (d == 255) fxProgression++;
  }
  break;

  default:
  {
    fxProgression = 0;
    if(colour == COLOUR_CYCLE)
    {
      c++;
      if(c == AMOUNTOFCOLOURS) c = 0;
    }
  }
  break;
  }
}
void Diode::progressFX_rainbow()
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
    if (r == 255)
      fxProgression++;
  }
  break;

  case 2:
  {
    b = b - 1;
    if (b == 0)
    {
      if (effect == 1)
        fxProgression++;
      else
        fxProgression = fxProgression + 3;
    }
  }
  break;

  case 3:
  {
    g++;
    if (g == 255)
      fxProgression++;
  }
  break;

  case 4:
  {
    r = r - 1;
    if (r == 0)
    {
      if (effect == 1)
        fxProgression++;
      else
        fxProgression = fxProgression + 3;
    }
  }
  break;

  case 5:
  {
    b++;
    if (b == 255)
    {
      if (effect == 1)
        fxProgression++;
      else
        fxProgression = fxProgression - 1;
    }
  }
  break;

  case 6:
  {
    if (effect == 1)
    {
      g = g - 1;
      if (g == 0)
        fxProgression++;
    }
    else
      fxProgression++;
  }
  break;

  default:
  {
    fxProgression = 0;
  }
  break;
  }
}
void Diode::progressFX_fire()
{
  if (fxProgression == 0)
  {
    r = 255;
    g = random(0, 200);
    b = 0;
  }
  else if (g < 90)
  {
    g++;
  }
  fxProgression++;

  if (g > 25 && random(0, offset) == 0)
  {
    g = g - 5;
  }

  if (g < 150 && offset > 5)
  {
    if (random(10, offset) > 10)
    {
      g = g + 6;
    }
  }
}
void Diode::progressFX_blink()
{
  if (colour != COLOUR_CYCLE) c = colour;
  bool allowR = getColourClearance(COLOUR_RED,    c);
  bool allowG = getColourClearance(COLOUR_GREEN,  c);
  bool allowB = getColourClearance(COLOUR_BLUE,   c);

  switch (fxProgression)
  {
  case 0:
  {
    if (allowR) r = 255;
    else r = 0;
    if (allowG) g = 255;
    else g = 0;
    if (allowB) b = 255;
    else b = 0;
    d = 0;

    fxProgression++;
  }
  break;

  case 1:
  {
    d++;

    if (d == 20) fxProgression++;
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

    if (d == 255)fxProgression++;
  }
  break;

  default:
  {
    fxProgression = 0;
    if(colour == COLOUR_CYCLE)
    {
      if(c == AMOUNTOFCOLOURS) c = 0;
      c++;
    }
  }
  break;
  }
}
void Diode::progressFX_plane()
{
  if (colour != COLOUR_CYCLE) c = colour;
  bool allowR = getColourClearance(COLOUR_RED,    c);
  bool allowG = getColourClearance(COLOUR_GREEN,  c);
  bool allowB = getColourClearance(COLOUR_BLUE,   c);

  switch (fxProgression)
  {
  case 0:
  {
    if (allowR) r = 255;
    else r = 0;
    if (allowG) g = 255;
    else g = 0;
    if (allowB) b = 255;
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
    if(d == 255)fxProgression++;
  }
  break;

  case 4: // Double effect start
  {
    if(allowR) r = 255;
    if(allowG) g = 255;
    if(allowB) b = 255;

    fxProgression++;
  }
  break;

  case 5:
  {
    d++;

    if(d == 60) fxProgression++;
  }
  break;

  case 6:
  {
    r = 0;
    g = 0;
    b = 0;

    fxProgression++;
  }
  break;

  case 7:
  {
    d++;

    if(d == 255)fxProgression++;
  }
  break;

  default:
  {
    fxProgression = 0;
    if(colour == COLOUR_CYCLE)
    {
      if(c == AMOUNTOFCOLOURS) c = 0;
      c++;
    }
  }
  break;
  }
}
void Diode::progressFX_static()
{
  if (colour != COLOUR_CYCLE) c = colour;
  bool allowR = getColourClearance(COLOUR_RED,    c);
  bool allowG = getColourClearance(COLOUR_GREEN,  c);
  bool allowB = getColourClearance(COLOUR_BLUE,   c);

  switch (fxProgression)
  {
  case 0: // Setup
  {
    if(allowR) r = 255;
    else r = 0;
    if(allowG) g = 255;
    else g = 0;
    if(allowB) b = 255;
    else b = 0;

    d = 0;

    fxProgression++;
  }
  break;

  case 1:
  {
    d++;

    if (d == 255)
    {
      fxProgression++;
    }
  }
  break;

  default:
  {
    fxProgression = 0;
    if(colour == COLOUR_CYCLE)
    {
      if(c == AMOUNTOFCOLOURS) c = 0;
      c++;
    }
  }
  break;
  }
}
void Diode::progressFX_breathing()
{
  if (colour != COLOUR_CYCLE) c = colour;
  bool allowR = getColourClearance(COLOUR_RED,    c);
  bool allowG = getColourClearance(COLOUR_GREEN,  c);
  bool allowB = getColourClearance(COLOUR_BLUE,   c);

  switch (fxProgression)
  {
  case 0:
  {
    if (effect == 4 || effect == 5)
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
    if (effect == 4 || effect == 5)
    {
      if (allowR)
        r++;
      if (allowG)
        g++;
      if (allowB)
        b++;
    }
    else
    {
      if (!allowR)
        r--;
      if (!allowG)
        g--;
      if (!allowB)
        b--;
    }

    d++;

    if (d == 255)
      fxProgression++;
  }
  break;

  case 2:
  {
    if (effect == 4 || effect == 5)
    {
      if (allowR)
        r--;
      if (allowG)
        g--;
      if (allowB)
        b--;
    }
    else
    {
      if (!allowR)
        r++;
      if (!allowG)
        g++;
      if (!allowB)
        b++;
    }

    d--;

    if (d == 0)
    {
      if (effect == 5 || effect == 11)
        fxProgression = fxProgression + 2;
      else
        fxProgression++;
    }
  }
  break;

  case 4: // Begin of double code
  {
    d++;

    if (d == 255)
      fxProgression++;
  }
  break;

  case 5:
  {
    d--;

    if (d == 1)
      fxProgression++;
  }
  break; // End of double code

  default:
  {
    fxProgression = 0;
    if(colour == COLOUR_CYCLE)
    {
      if(c == AMOUNTOFCOLOURS) c = 0;
      c++;
    }
  }
  break;
  }
}
void Diode::progressFX_flash()
{
  if (colour != COLOUR_CYCLE) c = colour;
  bool allowR = getColourClearance(COLOUR_RED,    c);
  bool allowG = getColourClearance(COLOUR_GREEN,  c);
  bool allowB = getColourClearance(COLOUR_BLUE,   c);

  switch (fxProgression)
  {
  case 0:
  {
    if (allowR)
      r = 255;
    else
      r = 0;

    if (allowG)
      g = 255;
    else
      g = 0;

    if (allowB)
      b = 255;
    else
      b = 0;

    d = 255;

    fxProgression++;
  }
  break;

  case 1:
  {
    if (allowR)
      r = r - 5;
    if (allowG)
      g = g - 5;
    if (allowB)
      b = b - 5;

    d = d - 5;

    if (effect == 7 && d == 100)
      fxProgression = fxProgression + 3;
    if (d == 0)
      fxProgression++;
  }
  break;

  case 2:
  {
    d++;
    if (d == 255)
      fxProgression++;
  }
  break;

  default:
  {
    fxProgression = 0;
    if(colour == COLOUR_CYCLE)
    {
      if(c == AMOUNTOFCOLOURS) c = 0;
      c++;
    }
  }
  break;
  }
}
void Diode::progressFX_heartbeat()
{
  if (colour != COLOUR_CYCLE) c = colour;
  bool allowR = getColourClearance(COLOUR_RED,    c);
  bool allowG = getColourClearance(COLOUR_GREEN,  c);
  bool allowB = getColourClearance(COLOUR_BLUE,   c);

  switch (fxProgression)
  {
  case 0:
  {
    if(allowR) r = 255;
    else r = 0;
    if(allowG) g = 255;
    else g = 0;
    if(allowB) b = 255;
    else b = 0;

    d = 255;

    fxProgression++;
  }
  break;

  case 1:
  {
    if(allowR) r -= 5;
    if(allowG) g -= 5;
    if(allowB) b -= 5;

    d -= 5;

    if(d == 100) fxProgression++;
  }
  break;

  case 2:
  {
    d++;
    if(d == 255) fxProgression++;
  }
  break;

  case 3: // Start of double code
  {
    if(allowR) r = 255;
    if(allowG) g = 255;
    if(allowB) b = 255;

    d = 255;

    fxProgression++;
  }
  break;

  case 4:
  {
    if(allowR) r -= 5;
    if(allowG) g -= 5;
    if(allowB) b -= 5;

    d -= 5;

    if (d == 0)
      fxProgression++;
  }
  break;

  case 5:
  {
    d++;
    if (d == 223) fxProgression++;
  }
  break; // End of double code

  default:
  {
    fxProgression = 0;
    if(colour == COLOUR_CYCLE)
    {
      if(c == AMOUNTOFCOLOURS) c = 0;
      c++;
    }
  }
  break;
  }
}
void Diode::progressFX_custom_fade()
{

}

void Diode::tick()
{
  //printDebug();
  if (offsetTimer < offset)
  {
    offsetTimer++;
  }
  else
  {
    for (byte i = 0; i < speed; i++)
    {
      switch (effect)
      {
        case EFFECT_STATIC:
        progressFX_static();
        break;

        case EFFECT_BLINK:
        progressFX_blink();
        break;

        case EFFECT_PLANE:
        progressFX_plane();
        break;

        case EFFECT_BREATHING:
        progressFX_breathing();
        break;

        case EFFECT_PAUSEDBREATHING:
        //progressFX_pausedbreathing();
        break;

        case EFFECT_FLASH:
        progressFX_flash();
        break;

        case EFFECT_HEARTBEAT:
        progressFX_heartbeat();
        break;

        case EFFECT_CUSTOM_STATIC:
        progressFX_custom_static();
        break;

        case EFFECT_RAINBOW:
        progressFX_rainbow();
        break;

        case EFFECT_FIRE:
        progressFX_fire();
        break;

        case EFFECT_SOUND:
        //progressFX_sound();
        break;

        
      }
    }
  }
}
CRGB Diode::getRGB()
{
  uint8_t r = (this->r * this->brightness) / 255;
  uint8_t g = (this->g * this->brightness) / 255;
  uint8_t b = (this->b * this->brightness) / 255;
  return CRGB(r, g, b);
}
void Diode::printDebug()
{
  Serial.print(F("Diode "));
  Serial.println(number);

  Serial.print(F("brightness "));
  Serial.print(brightness);
  Serial.print(F(" | effect "));
  Serial.print(effect);
  Serial.print(F(" | colour "));
  Serial.print(colour);
  Serial.print(F(" | offset "));
  Serial.print(offset);
  Serial.print(F(" | speed "));
  Serial.print(speed);

  Serial.print(F("r "));
  Serial.print(r);
  Serial.print(F(" | g "));
  Serial.print(g);
  Serial.print(F(" | b "));
  Serial.print(b);
  Serial.print(F(" | d "));
  Serial.print(d);
  Serial.print(F(" | c "));
  Serial.print(c);
  Serial.print(F(" | fxProgression "));
  Serial.print(fxProgression);
  Serial.print(F(" | offsetTimer "));
  Serial.println(offsetTimer);
}