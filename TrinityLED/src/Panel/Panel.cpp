#include "Panel.h"

//Constructor
Panel::Panel                                (uint8_t number, uint8_t x, uint8_t y, uint8_t compassDir, bool clockDir, uint16_t diodeAmount, bool allowDetailed)
{
  if(DEBUGLEVEL >= DEBUG_OPERATIONS)
  {
    Serial.print(F("Creating Panel at adress "));
    Serial.println((int)this, DEC);
  }

  this->allowDetailed = allowDetailed;
  detailed = allowDetailed;
  
  this->number        = number;
  this->x             = x;
  this->y             = y;
  this->compassDir    = compassDir;
  this->clockDir      = clockDir;

  this->diodeAmount   = diodeAmount;
  this->diodeStart    = 0;  // The coordinate of the first LED

  this->brightness   = 255;
  this->effect       = EFFECT_DEV_UNBOUND;
  this->colour       = COLOUR_BLACK;
  this->offset       = 0;
  this->speed        = 1;


    this->effectVariables.r                   = 0;
  this->effectVariables.g                   = 0;
  this->effectVariables.b                   = 0;

  if(allowDetailed)
  {
    diodes = (Diode**)malloc(sizeof(Diode*) * diodeAmount);
    for (uint8_t i = 0; i < diodeAmount; i++)
    {
      diodes[i] = new Diode(i, &this->effect);
    }
  }
  
  resetFXProcessingVars();
}

//Public
//Standard
void      Panel::tick                       ()
{
  if(DEBUGLEVEL >= DEBUG_DAYISRUINED)printDebug();

  //Brightness
  if      (brightness < goalBrightness) brightness++;
  else if (brightness > goalBrightness) brightness--;
  
  if (offsetTimer < offset)
  {
    offsetTimer++;
  }
  else
  {
    for (uint8_t i = 0; i < speed; i++)
    {
      if (detailed)
      {
        for (uint8_t i = 0; i < diodeAmount; i++)
        {
          diodes[i]->tick();
        }
        return;
      }

      if (CUSTOMEFFECTNUMBER_FIRST <= effect && effect <= CUSTOMEFFECTNUMBER_LAST) //If it's a custom colour effect
      {
        bool effectFinished = processEffect(effect, &effectVariables, customPalette);

        if(effectFinished)
        {
          effectVariables.c++;
          if(effectVariables.c == customPalette->customRGBSlots) effectVariables.c = 0;
        }
      }
      else //If it's a standard effect
      {
        if (colour != COLOUR_CYCLE)
        {
          effectVariables.c = colour;
        }
        
        bool effectFinished = processEffect(effect, &effectVariables, customPalette);

        if(colour == COLOUR_CYCLE && effectFinished)
        {
          effectVariables.c++;
          if(effectVariables.c == AMOUNTOFCOLOURS) effectVariables.c = (COLOUR_BLACK + 1);
        }
      }
      
      
      
    }
  }
}
//Effects
void      Panel::setBrightness              (uint8_t brightness, bool smooth)
{
  if (smooth)
  {
    goalBrightness = brightness;
  }
  else
  {
    this->brightness = brightness;
  }
}
void      Panel::setVfx                     (VFXData vfxData)
{  
  this->effect      = vfxData.effect;
  this->colour      = vfxData.colour;
  this->offset      = vfxData.offset;
  this->speed       = vfxData.speed;
  this->repeat      = vfxData.repeat;
  this->detailed    = false;
  resetFXProcessingVars();
}
void      Panel::setDataCustom              (CustomPalette *customPaletteArg)
{ 
  customPalette = customPaletteArg; 
  resetFXProcessingVars();
}
//Diode Effects
void      Panel::setDiodeBrightness         (uint16_t diodeNumber, uint8_t brightness, bool smooth)
{
  if (diodeNumber > diodeAmount)
  {
    Serial.print(F("ERROR: Panel.setDiodeBrightness() Too high diode number requested: "));
    Serial.print(diodeNumber);
    Serial.print(F(". Max: "));
    Serial.println(diodeAmount);
    return;
  }

  diodes[diodeNumber]->setBrightness(brightness, smooth);
}
void      Panel::setDiodeVfx                (uint16_t diodeNumber, VFXData vfxData)
{
  if(!allowDetailed)
  {
    Serial.println(F("WARNING: Panel.setDiodeVfx(): Detailed diode control not allowed. Effect applied to panel"));
    setVfx(vfxData);
    return;
  }

  detailed = true;
  if (effect != vfxData.effect) effect = vfxData.effect; //Let panel copy effects intended for diodes. Panels always copy effect.
  
  diodes[diodeNumber]->setVfx(vfxData);

  resetFXProcessingVars();
}
void      Panel::setDiodeDataCustom         (uint16_t diodeNumber, CustomPalette *customPalette)
{
  if(!allowDetailed)
  {
    if(DEBUGLEVEL >= DEBUG_WARNINGS) Serial.println(F("WARNING: Panel.setDiodeDataCustom(): Detailed diode control not allowed. Effect applied to panel"));
    setDataCustom(customPalette);
    return;
  }

  detailed = true;
  diodes[diodeNumber]->setDataCustom(customPalette);


  resetFXProcessingVars();
}
//Mask Effects
void      Panel::setMaskPercentage          (uint8_t percentage)
{
  
}
//Technical
uint8_t   Panel::getNumber                  ()
{
  return number;
}
uint8_t   Panel::getX                       ()
{
  return x;
}
uint8_t   Panel::getY                       ()
{
  return y;
}
CRGB      Panel::getDiodeRGB                (uint16_t diodeNumber, uint8_t sysBrightness) //Todo: Send own RGB if !detailed
{
  if(diodeNumber > diodeAmount)
  {
    Serial.print(F("Panel.getDiodeRGB() Too high diodeNumber requested: "));
    Serial.println(diodeNumber);
    return CRGB(0);
  }

  if (!detailed) //If not detailed send own LED colours
  {
    uint8_t r = (((this->effectVariables.r * this->brightness) / 255) * sysBrightness) / 255;
    uint8_t g = (((this->effectVariables.g * this->brightness) / 255) * sysBrightness) / 255;
    uint8_t b = (((this->effectVariables.b * this->brightness) / 255) * sysBrightness) / 255;
    return CRGB(r, g, b);
  }

  return diodes[diodeNumber]->getRGB(sysBrightness);

  /*
  uint8_t redValue    = (this->r * this->brightness)/255;
  uint8_t greenValue  = (this->g * this->brightness)/255;
  uint8_t blueValue   = (this->b * this->brightness)/255;
  return CRGB(redValue, greenValue, blueValue);
  */
}
uint16_t  Panel::getDiodeAmount             ()
{
  return diodeAmount;
}
uint16_t  Panel::getDiodeStart              ()
{
  return diodeStart;
}
void      Panel::setDiodeStart              (uint16_t ledStart)
{
  this->diodeStart = ledStart;
}
void      Panel::resetFXProcessingVars      ()
{

  this->effectVariables.d                   = 0;
  this->effectVariables.c                   = 0; //Current colour (Can cycle because of COLOUR_COLOURCYCLE)
  this->effectVariables.fxProgression       = 0; // In effect cycling
  this->offsetTimer                         = 0;
}
//Transmissions
String    Panel::convertToTransmission      ()
{
  #ifdef LINKPROGRAM_MK2
  
  String data = "";
  data += "/";
  data += (char)number;
  data += "/";
  data += (char)offset;
  data += (char)speed;
  data += (char)effect;
  data += (char)colour;
  data += "/";
  data += (char)effectVariables.r;
  data += (char)effectVariables.g;
  data += (char)effectVariables.b;
  data += "/";

  return data;
  #endif
  #ifdef LINKPROGRAM_MK3
  String data = "";

  data += (char)number;
  data += (char)compassDir;
  data += (char)clockDir;
  data += (char)diodeAmount; // Amount of leds in this panel

  data += (char)brightness;
  data += (char)effect;
  data += (char)colour;
  data += (char)offset;
  data += (char)speed;
  data += (char)repeat;
  data += (char)detailed;

  data += (char)effectVariables.r;
  data += (char)effectVariables.g;
  data += (char)effectVariables.b;

  return data;
  #endif
}
String    Panel::convertDiodeToTransmission (uint16_t diodeNumber)
{
  return diodes[diodeNumber]->convertToTransmission();
}
String    Panel::converToJson               ()
{
  //Only send: number, brightness, effect, colour, offset, speed, 

  String data = "{";
  data += "\"number\":";
  data += number;
  data += ",";
  data += "\"brightness\":";
  data += brightness;
  data += ",";
  data += "\"effect\":";
  data += effect;
  data += ",";
  data += "\"colour\":";
  data += colour;
  data += ",";
  data += "\"offset\":";
  data += offset;
  data += ",";
  data += "\"speed\":";
  data += speed;
  data += "}";
  return data;
  
}
//Debug
void      Panel::printDebug                 ()
{
  Serial.println();
  Serial.print(F("Panel "));
  Serial.println(number);

  Serial.print(F("compassDir "));
  Serial.print(compassDir);
  Serial.print(F(" | clockDir "));
  Serial.print(clockDir);
  Serial.print(F(" | diodeAmount "));
  Serial.print(diodeAmount);
  Serial.print(F(" | diodeStart "));
  Serial.println(diodeStart);

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
  Serial.print(effectVariables.r);
  Serial.print(F(" | g "));
  Serial.print(effectVariables.g);
  Serial.print(F(" | b "));
  Serial.print(effectVariables.b);
  Serial.print(F(" | d "));
  Serial.print(effectVariables.d);
  Serial.print(F(" | fxProgression "));
  Serial.print(effectVariables.fxProgression);
  Serial.print(F(" | c "));
  Serial.print(effectVariables.c);
  Serial.print(F(" | offsetTimer "));
  Serial.println(offsetTimer);
  
}

