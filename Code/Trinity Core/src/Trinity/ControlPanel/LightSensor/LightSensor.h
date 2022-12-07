#ifndef LIGHTSENSOR_H
#define LIGHTSENSOR_H

#include <Arduino.h>

class LightSensor
{
private:
  uint8_t pin;
  bool enabled;

  uint8_t brightnessRecommended;
  int brightnessOffset;

public:
  LightSensor(uint8_t pin);
  void tick();
  bool getEnabled();
  void setEnabled(bool enabled);
  bool getBrightnessOffset();
  void setBrightnessOffset(int brightnessOffset);
  uint8_t getInstruction_Brightness();
};



#endif