//*****************************************************************************
//*
//* EX_TouchToggle.cpp
//*   Copyright © 2026 Michael Schaff
//*   All rights reserved.
//*
//* Brief:
//*   Arduino interface for the Berrett Hill Shop Touch Toggle turnout
//*   control.
//*
//*   For further information:
//*     https://www.berretthillshop.com/store/products/touch-controls/
//*
//* Notes:
//*   This is free software: you can redistribute it and/or modify it under
//*   the terms of the GNU General Public License as published by the Free
//*   Software Foundation, either version 3 of the License, or (at your
//*   option) any later version.
//*
//*   It is distributed in the hope that it will be useful, but WITHOUT ANY
//*   WARRANTY; without even the implied warranty of MERCHANTABILITY FITNESS
//*   FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
//*   details.
//*
//*   You should have received a copy of the GNU General Public License along
//*   with the product. If not, see <https://www.gnu.org/licenses/>.
//*
//*****************************************************************************

#include "EX_TouchToggle.h"

// Constructor ////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
EX_TouchToggle::EX_TouchToggle()
{
}

// Constructor ////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
EX_TouchToggle::EX_TouchToggle(void(*function)(uint8_t, uint16_t, uint8_t, uint8_t))
{
  _onToggle = function;
}

//*****************************************************************************
//*
//* Brief:
//*   ???.
//*
//* Parameters:
//*   status - Beginning LED status indicator.
//*   pin    - Digital pin for the Touch Toggle sensor.
//*
//* Returns:
//*   true if successful, otherwise false.
//*
//*****************************************************************************
bool EX_TouchToggle::begin(uint8_t status, uint8_t pin)
{
  pinSensor  = pin;
  lastStatus = status;

  // The sensor startup state value does not always match the LED status, so we
  // read the state of the pin at startup.
  //-----------------------------------------------------------------------------
  pinMode(pinSensor, INPUT);
  lastSensor = digitalRead(pinSensor);

  // We can manually change the LED status by holding the pin HIGH (green) or
  // LOW (red), so we set the initial status.
  //-----------------------------------------------------------------------------
  pinMode(pinSensor, OUTPUT);
  digitalWrite(pinSensor, lastStatus);

  lastInquiry = millis();

  if (_onToggle)
    _onToggle(EX_BEGIN, toggleID, lastSensor, lastStatus);

  return (_onToggle ? true : false);
}

//*****************************************************************************
//*
//* Brief:
//*   ???.
//*
//* Parameters:
//*   None.
//*
//* Returns:
//*   None.
//*
//*****************************************************************************
void EX_TouchToggle::run(void)
{
  // To avoid a 'purple' LED, we need to pause between readings before setting
  // the LED status indicator colour. As a result, we check the clock to see how
  // much time has passed since the last sensor inquiry.
  //=============================================================================
  if (millis() - lastInquiry > EX_SENSITIVITY)
    {
    pinMode(pinSensor, INPUT);

    // Compare the current sensor value to the last value.
    if (lastSensor != digitalRead(pinSensor))
      {
      // When they change, toggle the values of both the...
      lastSensor = !lastSensor;   // sensor and...
      lastStatus = !lastStatus;   // LED status.

      // Report the event to our host.
      if (_onToggle)
        _onToggle(EX_TOGGLE, toggleID, lastSensor, lastStatus);
      }

    // Record the time we last checked the sensor.
    lastInquiry = millis();
    }

  // Set the LED status indicator colour. 
  pinMode(pinSensor, OUTPUT);
  digitalWrite(pinSensor, lastStatus);

  return;
}
