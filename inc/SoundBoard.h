#ifndef SOUNDBOARD_H_
#define SOUNDBOARD_H_

#include "Config.h"
#include "SoundManager.h"

class SoundBoard
{
public:
    SoundBoard();
private:
    void init();
    void run();
    Config configFile;
    SoundManager audioManager;
};

#endif