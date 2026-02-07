#ifndef LIGHTSENSOR_H
#define LIGHTSENSOR_H

##include <Arduino.h>
//#include "../../setup.h"

#define BRIGHTNESS_0_OFF 1
#define BRIGHTNESS_1_DIM 10
#define BRIGHTNESS_2_NOR 100
#define BRIGHTNESS_3_MAX 255
#define BRIGHTNESS_4_AUT 99

class LightSensor
{
private:
  uint8_t pin;
  bool enabled;

  uint8_t recommendedBrightness;
  int brightnessOffset;

public:
  LightSensor(uint8_t pin);
  void    tick();
  bool    getEnabled();
  void    setEnabled(bool enabled);
  uint8_t getBrightnessOffset();
  void    setBrightnessOffset(int brightnessOffset);
  uint8_t getRecommendedBrightness();
};



#endif