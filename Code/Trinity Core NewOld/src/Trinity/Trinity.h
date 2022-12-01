#ifndef TRINITY_H
#define TRINITY_H

#include "Trinity/Panel/Panel.h"



class Trinity
{
private:
  Vector<Panel*> panels;
  CRGB *leds;
  bool brightness;
  bool speed;

public:
  Trinity(Vector<Panel*> panels);
  void tick();
  Panel* getPanel(uint8_t x, uint8_t y);

  
};

#endif