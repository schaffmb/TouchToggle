# `TouchToggle` ![exarVersion](https://img.shields.io/badge/Version-0.0.1-green.svg?style=plastic) [![arduino-library-badge](https://www.ardu-badge.com/badge/TouchToggle.svg?)](https://www.ardu-badge.com/TouchToggle)
Library for the Berrett Hill Shop Touch Toggle

## Licensing:
![GPLv3Logo](https://www.gnu.org/graphics/gplv3-127x51.png)

TouchToggle is an open source project for open source projects. Those wishing to
create closed projects should seek an alternate solution.
TouchToggle is licensed under the terms of the GNU General Public License v3.0
as opposed to the more liberal licensing terms of the
GNU Lesser General Public License (LGPL), MIT, modified BSD, Apache, etc..

GPL licensing information can found here: https://www.gnu.org/licenses/

For full details on the licensing of TouchToggle and its components, see the included licensing file.

## Overview:
TBD


## Library API:
```c++
TouchToggle();
TouchToggle(void(*callback)(uint8_t, uint16_t, uint8_t, uint8_t));

bool begin(uint8_t status, uint8_t pin);
void run();

void setHandler(void(*callback)(uint8_t, uint16_t, uint8_t, uint8_t));

uint16_t getID();
void setID(uint16_t id);

uint8_t getPin();
void setPin(uint8_t pin);

uint8_t getSensor(void);
uint8_t getStatus(void);
