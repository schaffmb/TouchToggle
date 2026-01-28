//*****************************************************************************
//*
//* EX_TouchToggle.h
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

#ifndef obj_TouchToggle_h
#define obj_TouchToggle_h

#include <Arduino.h>

#define EX_BEGIN        0x0A
#define EX_TOGGLE       0x0F

#define EX_SENSITIVITY  5L

#define EX_NORMAL       1
#define EX_REVERSED     0

//=============================================================================
// EX_TouchToggle class
//-----------------------------------------------------------------------------
class EX_TouchToggle
{
public:
// Constructor
  EX_TouchToggle();
  EX_TouchToggle(void(*function)(uint8_t, uint16_t, uint8_t, uint8_t));

// Implementation
public:
  bool begin(uint8_t status, uint8_t pin);
  void run(void);

// Accessors
public:
  void setHandler(void(*function)(uint8_t, uint16_t, uint8_t, uint8_t))
                              { _onToggle = function; }

  uint16_t getID(void)        { return (toggleID);}
  void setID(uint16_t id)     { toggleID = id;}

  uint8_t getPin(void)        { return (pinSensor);}
  void setPin(uint8_t pin)    { pinSensor = pin;}

  uint8_t getSensor(void)     { return (lastSensor); }
  uint8_t getStatus(void)     { return (lastStatus); }

  // Members
private:
  void(*_onToggle)(uint8_t, uint16_t, uint8_t, uint8_t);

  uint8_t
    pinSensor;

  uint16_t
    toggleID    { 0xFF };

  uint8_t
    lastSensor  { 0 },
    lastStatus  { 0 };

  uint32_t
    lastInquiry { 0 };

};

#endif
