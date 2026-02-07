#include "LightSensor.h"

LightSensor::LightSensor(uint8_t pin)
{
  

  this->pin = pin;
  pinMode(pin, INPUT_PULLUP);
  enabled = false;
  recommendedBrightness = 99;
  brightnessOffset = 0;

  Serial.println(F("...LightSensor Started"));
}


void LightSensor::tick()
{
  int reading = analogRead(pin)/8; //I should do 16, as this could lead to byte overflow. But as the resistor never reaches 255 otherwise, I decided to "double" the value
  reading += 11;

  if(reading > 254) reading = 254;
  recommendedBrightness = reading;
}
bool LightSensor::getEnabled()
{
  return enabled;
}
void LightSensor::setEnabled(bool enabled)
{
  this->enabled = enabled;
}
uint8_t LightSensor::getBrightnessOffset()
{
  return brightnessOffset;
}
void LightSensor::setBrightnessOffset(int brightnessOffset)
{
  this->brightnessOffset = brightnessOffset;
}
uint8_t LightSensor::getRecommendedBrightness()
{
  return recommendedBrightness;
}