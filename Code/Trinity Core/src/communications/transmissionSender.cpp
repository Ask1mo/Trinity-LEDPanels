#include "communications/transmissionSender.h"

/*-------------------------------------------------------------------------------------*/

//EVEN PARITY

void serialSend_Leaf(Leaf* leaf)
{
  byte alpha = leaf->fxType;
  byte beta = leaf->fxNumber;
  byte charlie = 0;

  charlie = alpha;
  charlie = charlie << 4;
  charlie = charlie | beta;

  /*0*/Serial.write("/");
  /*1*/Serial.write(leaf->leafNumber);
  /*2*/Serial.write("/");
  /*3*/Serial.write(leaf->fxOffset);
  /*4*/Serial.write(leaf->fxSpeed);
  /*5*/Serial.write(charlie);
  /*6*/Serial.write("/");
  /*7*/Serial.write(leaf->redValue);
  /*8*/Serial.write(leaf->greenValue);
  /*9*/Serial.write(leaf->blueValue);
  /*10*/Serial.write("/");
}


