#ifndef TRINITY_H
#define TRINITY_H

#include "LedManager/ledManager.h"

#define PANELSETUP_TEST_AMOUNT  6
#define PANELSETUP_PRIME_AMOUNT 16
#define PANELSETUP_EVA_AMOUNT   4
#define PANELSETUP_LIAM_AMOUNT  10

class Trinity
{
private:
  Panel **panels;
  LedManager *ledManager;
  uint8_t setupPanels_Test();

public:
  Trinity();
  void tick();
};



#endif