
#include "EX_TouchToggle.h"

// Application definition(s)
///////////////////////////////////////////////////////////////////////////////
#define PIN_NORMAL    1
#define PIN_REVERSED  2

// Forward reference definition(s)
///////////////////////////////////////////////////////////////////////////////
void onEvent(uint8_t, uint16_t, uint8_t, uint8_t);

// Global variable(s)
///////////////////////////////////////////////////////////////////////////////
EX_TouchToggle
  objTouchToggle;

//*****************************************************************************
//*****************************************************************************
void setup()
{
  pinMode(PIN_NORMAL, OUTPUT);
  pinMode(PIN_REVERSED, OUTPUT);

  objTouchToggle.setHandler(onEvent);

  //                             +----------- Beginning state of the Touch Toggle LED indicator.
  //                             |
  //                             |       +--- Digital pin used for Touch Toggle sensor (orange wire).
  //                             |       |
  //                             v       v
  if (!objTouchToggle.begin(EX_REVERSED, 3))
    while (true); // ERROR: EX_TouchToggle object incorrectly instantiated.

  return;
}

//*****************************************************************************
//*****************************************************************************
void loop()
{
  objTouchToggle.run();
  return;
}
//*****************************************************************************
//*
//* Brief:
//*   Event handler for Touch Toggle.
//*
//* Parameters:
//*   None.
//*
//* Returns:
//*   None.
//*
//*****************************************************************************
void onEvent(uint8_t event, uint16_t id, uint8_t sensor, uint8_t status)
{
  uint8_t
    pinKATO = status == EX_NORMAL ? PIN_NORMAL : PIN_REVERSED;

  digitalWrite(pinKATO, HIGH);
  delay(25);
  digitalWrite(pinKATO, LOW);

  return;
}
