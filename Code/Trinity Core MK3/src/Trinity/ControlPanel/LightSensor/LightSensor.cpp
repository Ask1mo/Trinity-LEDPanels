#include "LightSensor.h"

LightSensor::LightSensor(uint8_t pin)
{
  Serial.println(F("LightSensor Starting..."));

  this->pin = pin;
  pinMode(pin, INPUT);

  Serial.println(F("...LightSensor Started"));
}


void LightSensor::tick()
{
  int pinState = digitalRead(pin);
}
bool LightSensor::getEnabled()
{
  return enabled;
}
void LightSensor::setEnabled(bool enabled)
{
  this->enabled = enabled;
}
bool LightSensor::getBrightnessOffset()
{
  return brightnessOffset;
}
void LightSensor::setBrightnessOffset(int brightnessOffset)
{
  this->brightnessOffset = brightnessOffset;
}
uint8_t LightSensor::getInstruction_Brightness()
{

}