#ifndef TRINITY_H
#define TRINITY_H

#include "Panel.h"




class Trinity
{
private:
  Vector<Panel*> Panels;

public:
  Trinity(Vector<Panel*> &panels);
  void Tick();
  Panel* GetPanel(uint8_t x, uint8_t y);

  bool Brightness;
  bool Speed;
};

#endif