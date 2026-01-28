
#include "EX_TouchToggle.h"

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
  Serial.begin(9600);

  objTouchToggle.setHandler(onEvent);
  objTouchToggle.setID(0x1F);

  //                             +----------- Beginning state of the Touch Toggle LED indicator.
  //                             |
  //                             |       +--- Digital pin used for Touch Toggle sensor (orange wire).
  //                             |       |
  //                             v       v
  if (!objTouchToggle.begin(EX_REVERSED, 8))
    Serial.println("ERROR: EX_TouchToggle object incorrectly instantiated.");

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
  switch (event)
    {
    case EX_BEGIN:
      Serial.println("== Begin ==================================");
      break;

    case EX_TOGGLE:
      Serial.println("== Toggle =================================");
      break;
    }

  Serial.println("ID: " + String(id));
  Serial.println("sensor: " + String(sensor));
  Serial.println("status: " + String(status) + ":" + (status == EX_NORMAL ? "Normal(GREEN)" : "Reversed(RED)"));

  return;
  }
