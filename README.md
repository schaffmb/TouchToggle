# `TouchToggle` ![exarVersion](https://img.shields.io/badge/Version-0.0.1-green.svg?style=plastic) [![arduino-library-badge](https://www.ardu-badge.com/badge/TouchToggle.svg?)](https://www.ardu-badge.com/TouchToggle)
Library for the Berrett Hill Shop Touch Toggle

Licensing
=========
![GPLv3Logo](https://www.gnu.org/graphics/gplv3-127x51.png)

TouchToggle is an open source project for open source projects. Those wishing to
create closed projects should seek an alternate solution.
TouchToggle is licensed under the terms of the GNU General Public License v3.0
as opposed to the more liberal licensing terms of the
GNU Lesser General Public License (LGPL), MIT, modified BSD, Apache, etc..

GPL licensing information can found here: https://www.gnu.org/licenses/

For full details on the licensing of TouchToggle and its components, see the included licensing file.

## Overview:
=================
TBD


## Library API:
```c++
bool begin(Stream& stream, bool debug, unsigned long threshold=100);

void playNext();
void playPrevious();
void play(uint16_t trackNum);
void stop();
void playFromMP3Folder(uint16_t trackNum);
void playAdvertisement(uint16_t trackNum);
void stopAdvertisement();
void incVolume();
void decVolume();
void volume(uint8_t volume);
void EQSelect(uint8_t setting);
void loop(uint16_t trackNum);
void playbackSource(uint8_t source);
void standbyMode();
void normalMode();
void reset();
void resume();
void pause();
void playFolder(uint8_t folderNum, uint8_t trackNum);
void playLargeFolder(uint8_t folderNum, uint16_t trackNum);
void volumeAdjustSet(uint8_t gain);
void startRepeatPlay();
void stopRepeatPlay();
void repeatFolder(uint16_t folder);
void randomAll();
void startRepeat();
void stopRepeat();
void startDAC();
void stopDAC();
void sleep();
void wakeUp();

bool isPlaying();
int16_t currentVolume();
int16_t currentEQ();
int16_t currentMode();
int16_t currentVersion();
int16_t numUsbTracks();
int16_t numSdTracks();
int16_t numFlashTracks();
int16_t currentUsbTrack();
int16_t currentSdTrack();
int16_t currentFlashTrack();
int16_t numTracksInFolder(uint8_t folder);
int16_t numFolders();

void setTimeout(unsigned long threshold);
void findChecksum(stack& _stack);
void sendData();
void flush();
int16_t query(uint8_t cmd, uint8_t msb=0, uint8_t lsb=0);
bool parseFeedback();

void printStack(stack _stack);
void printError();
